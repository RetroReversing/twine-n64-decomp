extern void *gBorderSkipFlag;
extern u8 D_801002A2;
extern u8 D_800C469C[];
extern u8 D_800C447C[];
void func_80070664(void *a, s32 b, s32 c, s32 d);
s32 func_80063C7C(s32 a, s32 b);
void func_8007089C(void *a, s32 b, s32 c);

void func_8011ACAC(void *a0, u8 *a1) {
    u16 s0 = 0;
    u16 s2 = 0;
    u8 *s1;
    u8 *p;
    s32 ret;
    u32 v;
    void (*fn)(void *);

    if (gBorderSkipFlag == NULL) {
        return;
    }
    switch (D_801002A2) {
    case 0:
        s0 = 4;
        break;
    case 1:
        s0 = 5;
        func_80070664(a1, 0x15, 1, -1);
        break;
    case 2:
        s0 = 6;
        s2 = 0x1A;
        break;
    case 3:
        s0 = 0xF;
        s2 = 0x1A;
        break;
    case 4:
        s0 = 4;
        break;
    case 5:
        s0 = 0x16;
        break;
    case 6:
        s0 = 0x18;
        s2 = 0x1A;
        break;
    case 7:
        s0 = 1;
        break;
    case 8:
        s0 = 0x14;
        break;
    case 9:
        s0 = 5;
        s2 = 0x1A;
        break;
    }
    s1 = D_800C469C + s0 * 232;
    p = a1 + (*(u16 *)(s1 + 2) << 3);
    p[0x1FE] = s0 - *(u16 *)(s1 + 2);
    p[0x1FC] = 1;
    ret = func_80063C7C(s0, s0 - *(u16 *)(s1 + 2));
    p = a1 + ((s16)ret * 8);
    p[0x1FF] = s1[0x82];
    if (D_801002A2 != 3) {
        *(u16 *)(a1 + (s1[0x80] << 1) + 0x1BC) = s1[0x82] << 1;
    }
    if (s2 != 0) {
        fn = *(void (**)(void *))(D_800C447C + (s2 << 4));
        if (fn != NULL) {
            fn(a0);
        }
    }
    func_8007089C(a0, 0, s0);
}
