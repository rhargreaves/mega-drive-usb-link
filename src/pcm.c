#include <pcm.h>
#include <genesis.h>

void pcm_stream(void)
{
    YM2612_writeReg(0, 0x27, 1 << 6); // Ch 3 Special Mode
    YM2612_writeReg(0, 0x28, 0);      // All channels off
    YM2612_writeReg(0, 0x28, 1);
    YM2612_writeReg(0, 0x28, 2);
    YM2612_writeReg(0, 0x28, 4);
    YM2612_writeReg(0, 0x28, 5);
    YM2612_writeReg(0, 0x28, 6);
    YM2612_writeReg(0, 0x90, 0); // Proprietary
    YM2612_writeReg(0, 0x94, 0);
    YM2612_writeReg(0, 0x98, 0);
    YM2612_writeReg(0, 0x9C, 0);
    YM2612_enableDAC();
    SYS_disableInts();
    for(;;) 
    {
        while(!ssf_usb_rd_ready()){ }
        u8 data = ssf_usb_read();
        YM2612_writeReg(0, 0x2A, data);
    }
}