#include <genesis.h>
#include <reader.h>
#include <ssf.h>

static u16 _count = 0;

void reader_read(void)
{
    u8 data;
    for (;;) {
        if (ssf_usb_rd_ready()) {
            data = ssf_usb_read();
            _count++;
        }
    }
}

u16 reader_count(void)
{
    return _count;
}

void reader_resetCount(void)
{
    _count = 0;
}
