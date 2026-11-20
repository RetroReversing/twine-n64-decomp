extern s32 D_800E41DC;
extern u16 D_800E41E4;
extern u16 D_800E4216;
extern s32 D_800E4218;
extern u16 *D_800E421C;
extern s32 D_800E422C;
extern void *D_800E4230;
extern s32 D_800E4234;
extern s32 D_8010D378;
extern s32 D_8010D42C;
void func_8008A52C(u8 *, s32, s32);

void func_8008AECC(s32 arg0, s32 arg1) {
char *__repair_addr;

    u8 *p;
    u16 *q;
    u16 i;
    s32 s1;
    s32 s2;
    s32 t;
    s32 a0v;
    s32 a1v;
    volatile s64 reserve;

    s1 = arg0;
    a1v = arg1;
    s1 = 0;
    i = 0;
    s2 = 0;
    if (D_800E41E4 != 0) {
        do {
            p = (u8 *)(D_800E41DC + i * 0x68);
            if (p[0x61] != 0) {
                p[0x61] = 0;
                s2 |= 1 << ((u8 *)(D_800E41DC + i * 0x68))[0x60];
            }
            p = (u8 *)(D_800E41DC + i * 0x68);
            if (*p != 0) {
                func_8008A52C(p, (u16)a1v, s1 & 0xFF);
                s1 += 1;
            }
            ++i;
        } while (i < D_800E41E4);
    }
    q = (u16 *)(D_800E4218 + *D_800E421C * 0xA10);
    if (*q == 0) {
        *(s16 *)((u8 *)q + 0x3C) = 0;
        q = (u16 *)(D_800E4218 + *D_800E421C * 0xA10);
    } else {
        q = (u16 *)((u8 *)q + (*q - 1) * 0x50);
    }
    *(s32 *)((u8 *)q + 0x54) = arg0;
    *(s32 *)(D_800E4218 + *D_800E421C * 0xA10 + 8) = D_800E422C;
    *(s32 *)(D_800E4218 + *D_800E421C * 0xA10 + 4) = s2;
    *(void **)(D_800E4218 + *D_800E421C * 0xA10 + 0xC) = D_800E4230;
    if (D_800E4230 != NULL) {
        *(s16 *)(D_800E4218 + *D_800E421C * 0xA10 + 2) = (s16)(D_800E4234 / 192);
        t = *(s32 *)((u8 *)D_800E4230 + 4);
        D_800E4234 += 0xC0;
        if (D_800E4234 == t) {
            D_800E4234 = 0;
        }
    }
    *D_800E421C += 1;
    if (*D_800E421C < D_800E4216) {
        D_8010D378 = (D_800E4218 + *D_800E421C * 0xA10 + 0x10) & ~0xF;
        D_8010D42C = D_800E4218 + *D_800E421C * 0xA10 + 0x10;
        *(u16 *)(D_800E4218 + *D_800E421C * 0xA10) = 0;
    }
}

