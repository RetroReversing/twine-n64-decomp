extern s32 piDomainShadow[];
extern s32 D_A0000000;
/* Writes one word to a PI device address. First waits for any pending PI DMA to finish, then
   reprograms the domain timing registers if the handle's cached values differ from the new ones. */
s32 piWriteDomainWord(u8 *handle, s32 devAddr, s32 *data) {
    u8 *shadow;
    u8 *domainShadow;
    s32 domain;
    if (*(vu32 *)0xA4600010 & 3) {
        do {
        } while (*(vu32 *)0xA4600010 & 3);
    }
    domain = handle[9];
    shadow = (u8 *)(unsigned long)piDomainShadow[domain];
    if (shadow[4] != handle[4]) {
        domainShadow = shadow;
        if (domain == 0) {
            if (domainShadow[5] != handle[5]) *(vu32 *)0xA4600014 = handle[5];
            if (domainShadow[6] != handle[6]) *(vu32 *)0xA460001C = handle[6];
            if (domainShadow[7] != handle[7]) *(vu32 *)0xA4600020 = handle[7];
            if (domainShadow[8] != handle[8]) *(vu32 *)0xA4600018 = handle[8];
        } else {
            if (domainShadow[5] != handle[5]) *(vu32 *)0xA4600024 = handle[5];
            if (domainShadow[6] != handle[6]) *(vu32 *)0xA460002C = handle[6];
            if (domainShadow[7] != handle[7]) *(vu32 *)0xA4600030 = handle[7];
            if (domainShadow[8] != handle[8]) *(vu32 *)0xA4600028 = handle[8];
        }
        domainShadow[4] = handle[4];
        domainShadow[5] = handle[5];
        domainShadow[6] = handle[6];
        domainShadow[7] = handle[7];
        domainShadow[8] = handle[8];
    }
    *(s32 *)(unsigned long)(*(u32 *)(handle + 0xC) | (u32)devAddr | 0xA0000000U) = (s32)data;
    return 0;
}
