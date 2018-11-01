#include <genesis.h>
#include <ping.h>
#include <ssf.h>

void ping_ping(void)
{
    u8 data;
    for (;;) {
        if (ssf_usb_rd_ready()) {
            data = ssf_usb_read();
            if (data == '0') {
                VDP_drawText("Ping!", 1, 1);
                ping_pong();
            }
        }
    }
}

void ping_pong(void)
{
    while (!ssf_usb_wr_ready())
        ;
    VDP_drawText("Pong!", 1, 2);
    ssf_usb_write('1');
}