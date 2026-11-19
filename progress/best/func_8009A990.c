s32 func_80095638(s32, s32);
void func_800968A4(u8, u8, u8);
s32 func_80099CA8(void *, void *);
extern u8 D_801007D9[];
extern u8 D_80100C7C[];

s32 func_8009A990(void *arg0, void *arg1) {
    u8 *p = arg1;
    u8 *obj = arg0;
    u32 s0;
    u32 s1;
    s32 v;
    register s32 a0;
    register s32 s4;
    s32 a1;
    s32 word;
    s32 v1_2;
    s32 res;

    if (p[6] == 0) {
        unsigned long w = *(u32 *)p;
        s1 = w >> 8;
        s0 = w >> 24;
        if (s0 < (s1 & 0xFF)) {
            u32 tmp = s1;
            s1 = s0;
            s0 = tmp;
        }
        a0 = arg0;
        a1 = (s32)arg1;
    } else {
        u16 t = *(u16 *)(obj + 0x50);
        s16 d;
        register s16 e;
        a1 = t; a1 += p[0];
        d = t - p[2];
        a0 = p[2];
        if (d >= 0) {
            s1 = 0x7F;
            if (d < 0x80) {
                s1 = d;
            }
        } else {
            s1 = 0;
        }
        e = (s16)a1;
        if (e >= 0) {
            s0 = 0x7F;
            if (0x80 > e) {
                s0 = e;
            }
        } else {
            s0 = 0;
        }
    }
    if (p[7] != 0) {
s32 __repair_branch_v_0;

        __repair_branch_v_0 = func_80095638(a0, a1) & 0xFFFF;
        a0 = (u32)__repair_branch_v_0 / 201;
        s4 = (s8)(__repair_branch_v_0 - a0 * 201 - 100);
    } else {
        s4 = p[1];
    }
    v = func_80095638((u8)a0, (s16)a1) & 0xFFFF;
    v1_2 = s1 & 0xFF;
    v = v % ((s32)((s0 & 0xFF) - (v1_2)) + 1);
    *(s32 *)(p + 4) = 0;
    word = ((s4 & 0xFF) << 16) | ((((s1 & 0xFF) + v) << 8) | 0x19);
    *(s32 *)p = word;
    v1_2 = *(s32 *)(obj + 0x60);
    *(s16 *)(obj + 0x50) = p[2] & 0x7F;
    *(s8 *)(obj + 0xC0) = (s8)*(u16 *)p;
    res = 0;
    if (v1_2 != -1) {
        u8 b4a = obj[0x4A];
        if (b4a != 0xFF) {
            register u8 b4b = obj[0x4B];
            u8 x;
            register s32 y;
            if (b4b == 0xFF) {
                x = D_80100C7C[(u8)v1_2];
                y = (u8)v1_2;
            } else {
                x = D_801007D9[b4b * 0x10 + b4a];
                y = (u8)v1_2;
            }
            res = (x == (unsigned)y);
        }
    }
    if (res) {
        func_800968A4(obj[0x4A], obj[0x4B], obj[0x51]);
    }
    *(s32 *)p = 4;
    func_80099CA8(obj, p);
    return 0;
}
