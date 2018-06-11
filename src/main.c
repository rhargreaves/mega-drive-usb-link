#include <genesis.h>

int main(void)
{
    while (TRUE)
    {
        VDP_showFPS(FALSE);
        VDP_waitVSync();
    }
}
