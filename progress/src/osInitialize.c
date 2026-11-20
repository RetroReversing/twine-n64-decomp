typedef struct { u32 words[4]; } ExceptionPreamble;
#define MMIO32(address) (*(volatile u32 *)(address))

extern void bzero(void *, s32);
extern void func_800A0220(void *, s32);
extern void func_800A8050(void *, s32);
extern u32 func_800A91E0(void);
extern u32 func_800A9200(void);
extern void func_800A9220(u32);
extern void func_800A9230(u32);
extern void func_800A9240(u32);
extern s32 func_800A9350(u32, u32 *);
extern s32 func_800A93A0(u32, u32);
extern void func_800A95C0(void);
extern void func_800A9620(void);
extern u64 func_800ABE20(u64, u64);
extern void func_800A71C0(void);
extern ExceptionPreamble D_80000000;
extern s32 D_80000300, D_8000030C;
extern u8 D_8000031C[];
extern u64 D_800D1070;
extern s32 D_800D1078, D_80112F8C;
extern u8 D_80100C0C, D_80100C0D, D_80100C0E, D_80100C0F, D_80100C10;
extern u8 D_80109B24, D_80109B25, D_80109B26, D_80109B27, D_80109B28;

void osInitialize(void)
{
    u32 pif;
    u32 dom1Latency, dom1Pulse, dom1Page, dom1Release;
    u32 dom2Latency, dom2Pulse, dom2Page, dom2Release;
    s32 clock;

    D_80112F8C = 1;
    func_800A9230(func_800A9200() | 0x20000000);
    func_800A9220(0x01000800);
    func_800A9240(0x04900000);
    while (func_800A9350(0x1FC007FC, &pif) != 0) {}
    while (func_800A93A0(0x1FC007FC, pif | 8) != 0) {}

    *(ExceptionPreamble *)0x80000000 = *(const ExceptionPreamble *)func_800A71C0;
    *(ExceptionPreamble *)0x80000080 = *(const ExceptionPreamble *)func_800A71C0;
    *(ExceptionPreamble *)0x80000100 = *(const ExceptionPreamble *)func_800A71C0;
    *(ExceptionPreamble *)0x80000180 = *(const ExceptionPreamble *)func_800A71C0;
    func_800A0220((void *)0x80000000, 0x190);
    func_800A8050((void *)0x80000000, 0x190);

    dom1Latency = MMIO32(0xA4600014);
    dom1Pulse = MMIO32(0xA4600018);
    dom1Page = MMIO32(0xA460001C);
    dom1Release = MMIO32(0xA4600020);
    dom2Latency = MMIO32(0xA4600024);
    dom2Pulse = MMIO32(0xA4600028);
    dom2Page = MMIO32(0xA460002C);
    dom2Release = MMIO32(0xA4600030);
    D_80109B24 = 7;
    D_80100C0C = 7;
    D_80109B25 = dom1Latency;
    D_80109B28 = dom1Pulse;
    D_80109B26 = dom1Page;
    D_80109B27 = dom1Release;
    D_80100C0D = dom2Latency;
    D_80100C10 = dom2Pulse;
    D_80100C0E = dom2Page;
    D_80100C0F = dom2Release;
    func_800A9620();
    func_800A95C0();

    D_800D1070 = func_800ABE20(D_800D1070 * 3, 4);
    if (D_8000030C == 0) {
        bzero(D_8000031C, 0x40);
    }
    if (D_80000300 == 0) {
        D_800D1078 = 0x02F5B2D2;
    } else if (D_80000300 == 2) {
        D_800D1078 = 0x02E6025C;
    } else {
        D_800D1078 = 0x02E6D354;
    }
    if (func_800A91E0() & 0x1000) {
        for (;;) {}
    }
    MMIO32(0xA4500008) = 1;
    MMIO32(0xA4500010) = 0x3FFF;
    MMIO32(0xA4500014) = 0xF;
}
