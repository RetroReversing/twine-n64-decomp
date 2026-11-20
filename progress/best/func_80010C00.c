extern s16 D_800E093A;
extern u8 D_800E0790[];
extern u32 D_800E0940[];
extern s16 D_800BFC32;
extern s32 D_801032A8;
extern u8 D_80102D60;
extern s16 D_80109DC8[];
extern s32 func_80011800(s32, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_800109CC(void);
extern s32 func_80010B60(s32);

typedef struct { u32 v; } __attribute__((packed)) UW;
#define ENT(i) (base + (i) * 104)
#define CP32(d, s) __builtin_memcpy((d), (s), 32)

s32 func_80010C00(void)
{
    s16 idx;
    u8 *base = D_800E0790;
    
    s32 st;
    s32 a1;
    u8 flag;

    idx = D_800E093A;
    func_80011800(7, ENT(idx), idx, 0, 0, 0, 0, 0);
    func_800109CC();
    if (D_800E093A != 0) return 0;
    if (D_800BFC32 == 0x20) goto cec;
    if (D_800BFC32 < 0x21) {
        if (D_800BFC32 == 1) goto fb4;
        if (D_800BFC32 <= 0) goto d110e4;
        if (D_800BFC32 < 5) {
            if (D_800BFC32 < 3) goto d110e4;
            goto fb4;
        }
        goto d110e4;
    }
    if (D_800BFC32 == 0x25) goto d38;
    if (D_800BFC32 >= 0x26) goto cec;
    if (D_800BFC32 == 0x21) goto d38;
    if (D_800BFC32 == 0x62) goto d38;
    goto d110e4;

cec:
    a1 = D_801032A8;
    if (a1 == 0xB || a1 == 2) goto d18;
    if (a1 != 0) goto l11374;
d18:
    func_80011800(0xC, ENT(0), 0, 0, 0, 0, 0, 0);
    goto after_c;
d38:
    a1 = D_801032A8;
    if (a1 == 0xA || a1 == 2) goto d64;
    if (a1 != 0) goto l11374;
d64:
    idx = D_800E093A;
    func_80011800(0xC, ENT(idx), idx, 0, 0, 0, 0, 0);
after_c:
    if (func_800109CC() == 0) goto l11434;
    idx = D_800E093A;
    func_80011800(0xE, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (func_800109CC() == 0) goto l113d8;
    CP32(D_800E0940, ENT(idx) + 12);
    func_80011800(7, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (func_800109CC() != 0) goto fa4;
    CP32(D_800E0940, ENT(idx) + 12);
    D_80102D60 = 0;
fa4:
    D_800BFC32 = 0x12;
    return 0x12;

fb4:
    a1 = D_801032A8;
    if (a1 == 0xB) { D_800BFC32 = 0x62; return 0x62; }
    if (a1 != 2) goto d110e4;
    idx = D_800E093A;
    func_80011800(0xE, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (func_800109CC() == 0) goto l113d8;
    func_80011800(0xC, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (func_800109CC() == 0) goto l11434;
    func_80011800(7, ENT(idx), idx, 0, 0, 0, 0, 0);
    func_800109CC();
    a1 = D_801032A8;
    if (a1 == 0 || a1 == 0xB || a1 == 0xA) goto l114cc;
    goto d110e4;

d110e4:
    a1 = D_801032A8;
    if (a1 != 0) goto l11374;
    st = D_800BFC32;
    if (st == 0x10 || st == 0x63 || st == 0xF) goto l11120;
    for (a1 = 0; (u16)a1 < 0x20; a1++) {
        idx = D_800E093A;
        if (((u8 *)D_800E0940)[(u16)a1] != (ENT(idx) + 12)[(u16)a1]) {
            flag = D_80102D60;
            CP32(D_800E0940, ENT(idx) + 12);
            if (flag != 0) {
                D_80102D60 = 0;
                D_800BFC32 = 0;
            } else {
                D_800BFC32 = 0x12;
            }
            return (u16)D_800BFC32;
        }
    }
    goto l11374;

l11120:
    idx = D_800E093A;
    D_80102D60 = 0;
    CP32(D_800E0940, ENT(idx) + 12);
    D_800BFC32 = 0;
    return 0;

l11374:
    a1 = D_801032A8;
    if (a1 != 2) goto l11594;
    idx = D_800E093A;
    func_80011800(0xE, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (func_800109CC() != 0) goto l113ec;
l113d8:
    D_800BFC32 = 0x63;
    return 0x63;
l113ec:
    idx = D_800E093A;
    func_80011800(0xC, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (func_800109CC() != 0) goto l11464;
l11434:
    idx = D_800E093A;
    D_800BFC32 = 0x10;
    D_80109DC8[idx] = 1;
    return 0x10;
l11464:
    idx = D_800E093A;
    func_80011800(7, ENT(idx), idx, 0, 0, 0, 0, 0);
    func_800109CC();
    a1 = D_801032A8;
    if (a1 == 0 || a1 == 0xB || a1 == 0xA) goto l114cc;
    goto l1159c;
l114cc:
    idx = D_800E093A;
    D_80102D60 = 0;
    CP32(D_800E0940, ENT(idx) + 12);
    D_800BFC32 = 0x12;
    return 0x12;
l11594:
    a1 = D_801032A8;
l1159c:
    return (u16)func_80010B60(a1);
}
