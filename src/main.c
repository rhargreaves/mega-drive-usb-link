#include <genesis.h>
#include <foo.c>

int main(void)
{
    while (TRUE)
    {
        bar();
        VDP_showFPS(FALSE);
        VDP_waitVSync();
    }
}
