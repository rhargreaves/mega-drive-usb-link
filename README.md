# Mega Drive USB Link
Proving that you can send bits over USB to the Everdrive cart

## Getting Started

### Compiling ROM

Docker:

```sh
./docker-make
```

Linux (requires `cmake`):

```sh
make
```

### Running Unit Tests

Unit tests built with `cmocka` and are compiled to x86. Mega Drive interfaces are mocked out.

Docker:

```sh
./docker-make-tests
```

Linux:

```sh
cd tests
make
```

## References

* [extended_ssf-v2](http://krikzz.com/pub/support/mega-everdrive/x3x5x7/dev/extended_ssf-v2.txt)
