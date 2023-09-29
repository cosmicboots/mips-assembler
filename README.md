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
