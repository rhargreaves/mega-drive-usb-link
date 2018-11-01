#include <genesis.h>
#include <pcm.h>

static void pcm_writeDAC(u8 sample);

void pcm_stream(void)
{
    YM2612_writeReg(0, 0x28, 0); // All channels off
    YM2612_writeReg(0, 0x28, 1);
    YM2612_writeReg(0, 0x28, 2);
    YM2612_writeReg(0, 0x28, 4);
    YM2612_writeReg(0, 0x28, 5);
    YM2612_writeReg(0, 0x28, 6);
    YM2612_writeReg(0, 0x90, 0);
    YM2612_writeReg(0, 0x94, 0);
    YM2612_writeReg(0, 0x98, 0);
    YM2612_writeReg(0, 0x9C, 0);
    YM2612_enableDAC();
    SYS_disableInts();
    for (;;) {
        while (!ssf_usb_rd_ready())
            ;
        pcm_writeDAC(ssf_usb_read());
    }
}

static void pcm_writeDAC(u8 sample)
{
    vs8* pb;
    pb = (s8*)YM2612_BASEPORT;
    __asm__ volatile("nop"); // Wait for YM2612 to be ready...
    __asm__ volatile("nop"); // 2
    __asm__ volatile("nop"); // 3
    __asm__ volatile("nop"); // 4
    __asm__ volatile("nop"); // 5
    __asm__ volatile("nop"); // 6
    __asm__ volatile("nop"); // 7
    __asm__ volatile("nop"); // 8
    __asm__ volatile("nop"); // 9
    __asm__ volatile("nop"); // 10
    __asm__ volatile("nop"); // 11
    __asm__ volatile("nop"); // 12
    __asm__ volatile("nop"); // 13
    __asm__ volatile("nop"); // 14
    __asm__ volatile("nop"); // 15
    __asm__ volatile("nop"); // 16
    __asm__ volatile("nop"); // 17 - Sweet spot for 32,000 Hz!
    pb[0] = 0x2A;
    pb[1] = sample;
}
