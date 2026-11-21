extern s32 gPiDomainCache[];
extern s32 D_A0000000;
/* Waits for PI DMA idle, syncs the device's PI domain timing, then reads a word from cart space at dev->address | offset. */ s32 piReadDomainWord(u8 *dev, s32 offset, s32 *outWord) {
    u8 *cfg;
    u8 *cached;
    s32 domain;
    s32 *var_v0;

    if (*(vu32 *)0xA4600010 & 3) {
        do {
        } while (*(vu32 *)0xA4600010 & 3);
    }
    domain = dev[9];
    cached = (u8 *)gPiDomainCache[domain];
    if (cached[4] != dev[4]) {
        cfg = cached;
        if (domain == 0) {
            if (cfg[5] != dev[5]) {
                *(vu32 *)0xA4600014 = dev[5];
            }
            if (cfg[6] != dev[6]) {
                *(vu32 *)0xA460001C = dev[6];
            }
            if (cfg[7] != dev[7]) {
                *(vu32 *)0xA4600020 = dev[7];
            }
            if (cfg[8] != dev[8]) {
                *(vu32 *)0xA4600018 = dev[8];
            }
        } else {
            if (cfg[5] != dev[5]) {
                *(vu32 *)0xA4600024 = dev[5];
            }
            if (cfg[6] != dev[6]) {
                *(vu32 *)0xA460002C = dev[6];
            }
            if (cfg[7] != dev[7]) {
                *(vu32 *)0xA4600030 = dev[7];
            }
            if (cfg[8] != dev[8]) {
                *(vu32 *)0xA4600028 = dev[8];
            }
        }
        cfg[4] = dev[4];
        cfg[5] = dev[5];
        cfg[6] = dev[6];
        cfg[7] = dev[7];
        cfg[8] = dev[8];
    }
    *outWord = *(s32 *)((*(s32 *)(dev + 0xC) | offset | 0xA0000000));
    return 0;
}
