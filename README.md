# Sega Mega Drive USB Link [![CircleCI](https://circleci.com/gh/rhargreaves/mega-drive-usb-link.svg?style=svg)](https://circleci.com/gh/rhargreaves/mega-drive-usb-link)
Fun and profit sending bits over USB to the Mega EverDrive X7 cart

## Getting Started

This program has many options as defined by the code in [src/main.c](src/main.c). The activate "mode" can be changed by modifying the source and re-compiling the ROM:

```c
#define MODE_PING 0
#define MODE_RATE_TEST 1
#define MODE_PCM 2

static u16 default_mode = MODE_PING;
```

`PING` is a method of calculating round-trip latency from a PC to a Mega Drive by having the PC send a character to the Mega Drive, which upon receipt will immediately respond with a character back. The [many_ping](many_ping) script can be used to find the average time to send & receive ping requests & responses.

`RATE_TEST` is a method of calculating throughput in bytes per second, by simply counting bytes received over the USB. Piping `/dev/zero` into the USB serial device works well!

`PCM` allows you to stream PCM audio through the USB serial interface direct to the DAC of the YM2612 FM chip. For example:

```sh
$ ffmpeg -re -y -i input.mp3 -ar 26000 -acodec pcm_u8 -f u8 -ac 1 - > /dev/cu.usbserial-A105J2JO
```

The `-re` argument ensures that the PCM audio is sent to the Mega Drive at playback rate (there's no software buffering or rate control). A sample rate of 26000 Hz seems to work fine with the program as-is.

### Results

The following metrics were calculated using the tooling described above:

* Maximum throughput/rate = **50,000 bytes/sec**.
* Mean latency = **~2.1 ms**.

## Compiling ROM

Docker:

```sh
./docker-make all
```

Linux (requires `cmake`):

```sh
make all
```

## Running Unit Tests

Unit tests built with `cmocka` and are compiled to x86. Mega Drive interfaces are mocked out.

Docker:

```sh
./docker-make test
```

Linux:

```sh
make test
```


## References

* [extended_ssf-v2](http://krikzz.com/pub/support/mega-everdrive/x3x5x7/dev/extended_ssf-v2.txt)
