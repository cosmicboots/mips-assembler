#!/bin/bash

tests=($(find examples/MA/ -type f -name '*.hex'))

make

if [[ $1 ]]
then
    src="$(dirname $1)/$(basename "$1" ".hex").asm"
    #difft <(./build/main "$src" | awk '{print $1}') <(awk '{print $1}' "$1")
    diff <(./build/main "$src" | awk '{print $1}') <(awk '{print $1}' "$1")
    ./build/main "$src"
else
    total=0
    good=0
    for test in "${tests[@]}"
    do
        src="$(dirname $test)/$(basename "$test" ".hex").asm"
        echo " |=== Checking: [$src] ===|"
        #difft --exit-code <(./build/main "$src" 2>/dev/null | awk '{print $1}') <(awk '{print $1}' "$test")
        diff <(./build/main "$src" 2>/dev/null | awk '{print $1}') <(awk '{print $1}' "$test")
        if [[ $? -eq 0 ]]
        then
            good=$(($good + 1))
        fi
        total=$(($total + 1))
    done
    echo " === $good/$total Tests passed ==="
    echo
fi

