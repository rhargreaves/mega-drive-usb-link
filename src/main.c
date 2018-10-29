#include <genesis.h>
#include <reader.h>
#include <ssf.h>

static void vsync(void);

static u16 frame = 0;

int main(void)
{
    ssf_init();
    SYS_setVIntCallback(vsync);
    while (TRUE)
    {
        VDP_showFPS(FALSE);
        reader_tick();
        VDP_waitVSync();
    }
}

static void vsync(void) 
{
    u16 byteCount = reader_count();
    char buffer[32];
    sprintf(buffer, "Byte: %lu    ", byteCount);
    VDP_drawText(buffer, 1, 3);
    u16 framesPerSecond = SYS_isNTSC() ? 60 : 50;
    if(frame == framesPerSecond)
    {
        char buffer[32];
        sprintf(buffer, "Bytes/sec: %lu    ", byteCount);
        VDP_drawText(buffer, 1, 4);
        reader_resetCount();
        frame = 0;
    }
    frame++;
}
