static __inline__ s32 __repair_inline(s32 a) { return a; }
extern u8 D_80109A60[];
void func_80031A84(void *arg0);
s32 func_800179E8(void *a, s32 b, s32 c, s32 d);
s32 func_800624A8(void *a, void *b, s32 c, s32 d);
s32 func_80084338(s32 a, void *b);

void func_80031C70(void *arg0) {
    s32 flags;
    u8 *s2;
    s16 st;
    s16 t;
    s16 u;

    flags = __repair_inline(*(s32 *)((u8 *)arg0 + 0x60));
    s2 = *(u8 **)((u8 *)arg0 + 0x6C);
    if (flags & 2) {
        *(s32 *)((u8 *)arg0 + 0x60) = flags & ~2;
        func_800624A8(arg0, (u8 *)arg0 + 0x24, 0x3DCCCCCD, 1);
        func_800179E8((u8 *)arg0 + 0x24, *(s32 *)((u8 *)arg0 + 0x20), 0x10000, 2);
        *(s32 *)((u8 *)arg0 + 0x60) |= 1;
        if (s2[4] != 0 && s2[5] == D_80109A60[s2[4]] && s2[6] != 0) {
            D_80109A60[s2[6]] = 1;
        }
    }
    if (s2[4] == 0 || s2[5] == D_80109A60[s2[4]]) {
        st = *(s16 *)((u8 *)arg0 + 0x7A);
        switch (st) {
        case 0:
            if (*(u16 *)s2 == 0) {
                *(f32 *)((u8 *)arg0 + 0x40) += 9.0f;
            }
        case 1:
            if (*(u16 *)s2 == 0) {
                s2[2]--;
            }
            if (s2[2] == 0) {
                t = *(s16 *)((u8 *)arg0 + 0x7A) + 1;
                *(s16 *)((u8 *)arg0 + 0x7A) = t;
                if (t == 1) {
                    s2[2] = 0xA;
                    func_80084338(0x10F, (u8 *)arg0 + 0x24);
                } else {
                    s2[2] = 0x50;
                }
            }
            func_80031A84(arg0);
            break;
        case 2:
            if (*(u16 *)s2 == 0) {
                *(f32 *)((u8 *)arg0 + 0x40) += -9.0f;
            }
        case 3:
            if (*(u16 *)s2 == 0) {
                s2[2]--;
            }
            if (s2[2] == 0) {
                s2[2] = 0;
                t = (*(s16 *)((u8 *)arg0 + 0x7A) + 1) & 3;
                *(s16 *)((u8 *)arg0 + 0x7A) = t;
                if (t == 3) {
                    s2[2] = 0xA;
                    func_80084338(0x10F, (u8 *)arg0 + 0x24);
                } else {
                    s2[2] = 0x50;
                }
            }
            func_80031A84(arg0);
            break;
        }
        u = *(s16 *)((u8 *)arg0 + 0x7C);
        if (u > 0) {
            if (*(u16 *)((u8 *)arg0 + 0x78) == 0x1B) {{ s16 __repair_value; __repair_value = u + 1; u = __repair_value; }
                *(s16 *)((u8 *)arg0 + 0x7C) = u;
                if (u >= 0x385) {
                    *(s16 *)((u8 *)arg0 + 0x7C) = 0;
                }
            }
            if (s2[3] != 0) {
                D_80109A60[s2[3]] = 1;
            }
            return;
        }
    }
    if (s2[3] != 0) {
        D_80109A60[s2[3]] = 0;
    }
}
