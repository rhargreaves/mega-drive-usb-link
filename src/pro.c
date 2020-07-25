#include <genesis.h>
#include <pro.h>

static u16 _count = 0;

void pro_read(void)
{
    // u8 data;
    // for (;;) {
    //     if (ssf_usb_rd_ready()) {
    //         data = ssf_usb_read();
    //         _count++;
    //     }
    // }
}

u16 pro_count(void)
{
    return _count;
}

void pro_resetCount(void)
{
    _count = 0;
}
