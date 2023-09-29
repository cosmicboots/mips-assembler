# MIPS Assembler

## Compiling

The code is targeted for C++11 and can be compiled using `make`:

```shell
$ make
```

## Running

To run the assembler:

```shell
$ ./build/main examples/MA/addArray.asm
```

The hex will be printed to `stdout`.

## Testing

All the example tests have been copied to `examples/MA/`. I was not able to get
the included Perl script working; however, I've included a Bash script that
will run the tests:

```shell
$ ./tests.sh
```

This script is also slightly more advanced than the Perl script, as it checks
for zero output on bad input tests.

All tests should be passing:

```
 |=== Checking: [examples/MA/addArray.asm] ===|
 |=== Checking: [examples/MA/arrayCopy.asm] ===|
 |=== Checking: [examples/MA/branch1.asm] ===|
 |=== Checking: [examples/MA/branch2.asm] ===|
 |=== Checking: [examples/MA/daddiu.asm] ===|
 |=== Checking: [examples/MA/decrement.asm] ===|
 |=== Checking: [examples/MA/dump.asm] ===|
 |=== Checking: [examples/MA/factorial.asm] ===|
 |=== Checking: [examples/MA/fibo.asm] ===|
 |=== Checking: [examples/MA/fiboLoop.asm] ===|
 |=== Checking: [examples/MA/iterate.asm] ===|
 |=== Checking: [examples/MA/iterate2.asm] ===|
 |=== Checking: [examples/MA/loadsDaddiStores.asm] ===|
 |=== Checking: [examples/MA/loadsDaddiuStores.asm] ===|
 |=== Checking: [examples/MA/loadsDaddsStores.asm] ===|
 |=== Checking: [examples/MA/loadsDsubsStores.asm] ===|
 |=== Checking: [examples/MA/loadsFPAddsStores.asm] ===|
 |=== Checking: [examples/MA/loadsFPDivsStores.asm] ===|
 |=== Checking: [examples/MA/loadsFPMultsStores.asm] ===|
 |=== Checking: [examples/MA/loadsStores1.asm] ===|
 |=== Checking: [examples/MA/loadsStores2.asm] ===|
 |=== Checking: [examples/MA/loop10times.asm] ===|
 |=== Checking: [examples/MA/matrixMult.asm] ===|
 |=== Checking: [examples/MA/multiply.asm] ===|
 |=== Checking: [examples/MA/negbranch.asm] ===|
 |=== Checking: [examples/MA/powers.asm] ===|
 |=== Checking: [examples/MA/vectorDiv.asm] ===|
 |=== Checking: [examples/MA/vectorSub.asm] ===|
 === 28/28 Tests passed ===
```
