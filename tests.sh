#!/bin/bash

tests=($(find examples/MA/ -type f -name '*.hex'))

total=0
good=0

for test in "${tests[@]}"
do
    src="$(dirname $test)/$(basename "$test" ".hex").asm"
    echo " |=== Checking: [$src] ===|"
    difft --exit-code <(./build/main "$src" | awk '{print $1}') <(awk '{print $1}' "$test")
    if [[ $? -ne 0 ]]
    then
        exit 1
    else
        good=$(($good + 1))
    fi
    total=$(($total + 1))
done

echo "$good/$total Tests passed"
