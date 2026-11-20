extern u8 *D_800E41DC;
extern u16 D_800E41E4;
extern u16 D_800E4216;
extern u8 *D_800E4218;
extern u16 *D_800E421C;
extern s32 D_800E422C;
extern u8 *D_800E4230;
extern s32 D_800E4234;
extern u8 *D_8010D378;
extern u8 *D_8010D42C;

void func_8008A52C(u8 *, s32, s32);

void func_8008AECC(s32 arg0, u16 arg1) {
    s32 s1;
    s32 s2;
    u16 i;
    u8 *ent;
    u8 *cur;
    u8 *p;
    u16 k;
    u16 v;
    s32 t;
    s32 off;
    volatile s64 pad;

    s1 = 0;
    i = 0;
    s2 = 0;
    if (D_800E41E4 != 0) {
        do {
            off = (i * 13) << 3;
            ent = (u8 *)(off + (u32)D_800E41DC);
            if (ent[0x61] != 0) {
                ent[0x61] = 0;
                s2 |= 1 << ((u8 *)(off + (u32)D_800E41DC))[0x60];
            }
            if (((u8 *)(off + (u32)D_800E41DC))[0] != 0) {
                func_8008A52C(D_800E41DC + off, arg1 & 0xFFFF, s1 & 0xFF);
                s1 += 1;
            }
            i += 1;
        } while (i < D_800E41E4);
    }
    cur = (u8 *)((*D_800E421C * 0xA10) + (u32)D_800E4218);
    k = *(u16 *)cur;
    if (k == 0) {
        *(s16 *)(cur + 0x3C) = 0;
        p = D_800E4218 + (*D_800E421C * 0xA10);
    } else {
        p = cur + (k - 1) * 0x50;
    }
    *(s32 *)(p + 0x54) = arg0;
    cur = D_800E4218 + (*D_800E421C * 0xA10);
    *(s32 *)(D_800E4218 + (*D_800E421C * 0xA10) + 8) = D_800E422C;
    *(s32 *)(D_800E4218 + (*D_800E421C * 0xA10) + 4) = s2;
    *(u8 **)(D_800E4218 + (*D_800E421C * 0xA10) + 0xC) = D_800E4230;
    if (D_800E4230 != NULL) {
        *(s16 *)(D_800E4218 + (*D_800E421C * 0xA10) + 2) = D_800E4234 / 192;
        t = D_800E4234 + 0xC0;
        D_800E4234 = t;
        if (t == *(s32 *)(D_800E4230 + 4)) {
            D_800E4234 = 0;
        }
    }
    *D_800E421C += 1;
    v = *D_800E421C;
    if (v < D_800E4216) {
        D_8010D378 = (u8 *)((u32)(D_800E4218 + *D_800E421C * 0xA10 + 0x10) & ~0xF);
        D_8010D42C = D_800E4218 + *D_800E421C * 0xA10 + 0x10;
        *(u16 *)(D_800E4218 + *D_800E421C * 0xA10) = 0;
    }
}
