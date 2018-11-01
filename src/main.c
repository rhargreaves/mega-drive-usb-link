#include <genesis.h>
#include <pcm.h>
#include <ping.h>
#include <reader.h>
#include <ssf.h>

static void vsync(void);
static void printRate(u16 byteCount);
static void printCount(u16 count);

static u16 frame = 0;
static u16 framesPerSecond;

#define MODE_PING 0
#define MODE_RATE_TEST 1
#define MODE_PCM 2

static u16 default_mode = MODE_PCM;

int main(void)
{
    framesPerSecond = SYS_isNTSC() ? 60 : 50;
    ssf_init();
    switch (default_mode) {
    case MODE_PING:
        ping_ping();
        break;
    case MODE_RATE_TEST:
        SYS_setVIntCallback(vsync);
        reader_read();
        break;
    case MODE_PCM:
        pcm_stream();
        break;
    }
}

static void vsync(void)
{
    VDP_showFPS(FALSE);
    u16 byteCount = reader_count();
    printCount(byteCount);
    if (frame == framesPerSecond) {
        printRate(byteCount);
        reader_resetCount();
        frame = 0;
    }
    frame++;
}

static void printCount(u16 count)
{
    char buffer[32];
    sprintf(buffer, "Byte: %lu    ", count);
    VDP_drawText(buffer, 1, 3);
}

static void printRate(u16 byteCount)
{
    char buffer[32];
    sprintf(buffer, "Bytes/sec: %lu    ", byteCount);
    VDP_drawText(buffer, 1, 4);
}