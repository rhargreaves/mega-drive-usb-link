#include <genesis.h>
#include <reader.h>

int main(void)
{
    while (TRUE)
    {
        VDP_showFPS(FALSE);
        reader_tick();
        VDP_waitVSync();
    }
}
