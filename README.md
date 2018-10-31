# Mega Drive USB Link [![CircleCI](https://circleci.com/gh/rhargreaves/mega-drive-usb-link.svg?style=svg)](https://circleci.com/gh/rhargreaves/mega-drive-usb-link)
Proving that you can send bits over USB to the Everdrive cart

## Getting Started

### Compiling ROM

Docker:

```sh
./docker-make all
```

Linux (requires `cmake`):

```sh
make all
```

### Running Unit Tests

Unit tests built with `cmocka` and are compiled to x86. Mega Drive interfaces are mocked out.

Docker:

```sh
./docker-make test
```

Linux:

```sh
make test
```

## Results

The maximum speed reached using the Everdrive has been found to be roughly 50,000 bytes per second.

## References

* [extended_ssf-v2](http://krikzz.com/pub/support/mega-everdrive/x3x5x7/dev/extended_ssf-v2.txt)
