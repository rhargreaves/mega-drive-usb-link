#include <genesis.h>
#include <foo.h>

int main(void)
{
    while (TRUE)
    {
        int c = add(1, 2);
        VDP_showFPS(FALSE);
        VDP_waitVSync();
    }
}
