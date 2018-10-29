#include <reader.h>
#include <genesis.h>
#include <ssf.h>

static u16 count;

void reader_tick(void) 
{
    count = 0;
    u8 data;
    while(ssf_usb_rd_ready())
    {
        data = ssf_usb_read();
        count++;
    }
}

u16 reader_count(void)
{
    return count;
}