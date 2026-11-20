extern s16 D_800E093A;
extern u8 D_800E0790[];
extern u8 D_800E079C[];
extern u32 D_800E0940[];
extern s16 D_800BFC32;
extern s32 D_801032A8;
extern u8 D_80102D60;
extern s16 D_80109DC8[];
extern s32 func_80011800(s32, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_800109CC(void);
extern s32 func_80010B60(s32);

typedef struct { u32 v; } __attribute__((packed)) UW;
#define ENT(i) ((i) * 104 + D_800E0790)
#define CP32(d, s) __builtin_memcpy((d), (s), 32)

s32 func_80010C00(void)
{
    s32 idx;
    u8 *base = D_800E0790;
    
    s32 st;
    s32 a1;
    u8 flag;

    idx = D_800E093A;
    func_80011800(7, ENT(idx), idx, 0, 0, 0, 0, 0);
    func_800109CC();
    if (D_800E093A != 0) return 0;
    switch (D_800BFC32) {
    case 0x20: goto cec;
    case 0x21:
    case 0x25:
    case 0x62: goto d38;
    case 1:
    case 3:
    case 4: goto fb4;
    default: goto d110e4;
    }

cec:
    {
    s32 mode = D_801032A8;
    if (mode == 0xB || mode == 2) goto d18;
    if (mode != 0) goto l11374;
d18:
    func_80011800(0xC, ENT(0), 0, 0, 0, 0, 0, 0);
    goto after_c;
    }
d38:
    {
    s32 mode = D_801032A8;
    if (mode == 0xA || mode == 2) goto d64;
    if (mode != 0) goto l11374;
d64:
    idx = D_800E093A;
    func_80011800(0xC, ENT(idx), idx, 0, 0, 0, 0, 0);
    }
after_c:
    if (func_800109CC() == 0) goto l11434;
    idx = D_800E093A;
    func_80011800(0xE, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (func_800109CC() == 0) goto l113d8;
    {
        u8 *payload = D_800E0790 + 12;
        u32 *backup = D_800E0940;
        s32 copyIdx = D_800E093A;
        CP32(backup, payload + copyIdx * 104);
        idx = *(volatile s16 *)&D_800E093A;
        func_80011800(7, ENT(idx), idx, 0, 0, 0, 0, 0);
        if (func_800109CC() != 0) goto fa4;
        idx = D_800E093A;
        D_80102D60 = 0;
        CP32(backup, payload + idx * 104);
    }
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
    idx = D_800E093A;
    func_80011800(0xC, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (func_800109CC() == 0) goto l11434;
    idx = D_800E093A;
    func_80011800(7, ENT(idx), idx, 0, 0, 0, 0, 0);
    func_800109CC();
    a1 = D_801032A8;
    if (a1 == 0 || a1 == 0xB || a1 == 0xA) goto l114cc;
    goto d110e4;

d110e4:
    if (D_801032A8 != 0) goto l11374;
    st = D_800BFC32;
    if (st == 0x10 || st == 0x63 || st == 0xF) {
        idx = D_800E093A;
        D_80102D60 = 0;
        CP32(D_800E0940, D_800E079C + idx * 104);
        D_800BFC32 = 0;
        return 0;
    }
    a1 = 0;
    do {
        u8 *payload = D_800E079C + D_800E093A * 104;
        if (((u8 *)D_800E0940)[(u16)a1] == payload[(u16)a1]) goto equal;
        flag = D_80102D60;
        CP32(D_800E0940, payload);
        if (flag != 0) {
            D_80102D60 = 0;
            D_800BFC32 = 0;
        } else {
            D_800BFC32 = 0x12;
        }
        return (u16)D_800BFC32;
equal:
        a1++;
    } while ((u16)a1 < 0x20);

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
    {
        s32 entryIndex = D_800E093A;
        D_800BFC32 = 0x10;
        D_80109DC8[entryIndex] = 1;
        return 0x10;
    }
l11464:
    idx = D_800E093A;
    func_80011800(7, ENT(idx), idx, 0, 0, 0, 0, 0);
    func_800109CC();
    a1 = D_801032A8;
    if (a1 == 0 || a1 == 0xB || a1 == 0xA) goto l114cc;
    goto l1159c;
l114cc:
    {
        s32 entryIndex = D_800E093A;
        u8 *payloadBase = base + 12;
        D_80102D60 = 0;
        CP32(D_800E0940, entryIndex * 104 + payloadBase);
        D_800BFC32 = 0x12;
        return 0x12;
    }
l11594:
    a1 = *(volatile s32 *)&D_801032A8;
l1159c:
    return (u16)func_80010B60(a1);
}
