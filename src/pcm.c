#include <pcm.h>
#include <genesis.h>

static void pcm_writeDAC(u8 sample);

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
        pcm_writeDAC(ssf_usb_read());
    }
}

static void pcm_writeDAC(u8 sample)
{
    vs8 *pb;
    pb = (s8*) YM2612_BASEPORT;
    while (*pb < 0);
    pb[0] = 0x2A;
    while (*pb < 0);
    pb[1] = sample;
}