s32 func_800109CC(void);
s32 func_80010A2C(void);
u16 func_80010B60(u32);
u16 func_800115C0(void);
s32 func_80011800(u16, void *, s16, s32, s32, s32, s32, s32);
s32 func_80012F50(void);
extern u16 D_800BFC32;
extern u16 D_800E0768[4];
extern u8 D_800E076A[16];
extern u8 D_800E076B[16];
extern u8 D_800E0790[];
extern s16 D_800E0938, D_800E093A, D_800E093C, D_800E093E;
extern s16 D_80103022[4];
extern s32 D_801032A8;
extern s16 D_801083D4[4];
extern u8 D_80108F75;
extern s16 D_80109BA4[4], D_80109DC8[4];
extern s8 D_8010A3C5, D_8010A3C6, D_8010A3C7, D_8010A3C8;
u16 func_80012C70(void) {
    u8 *__base_D_800E0790;
    s32 state = -1;
    D_8010A3C5 = 0; D_8010A3C6 = 0; D_8010A3C7 = 0; D_8010A3C8 = 0;
    D_800E093E = 0;
    D_800E093A = 0;
    D_800E093C = -1;
    D_800E093E = 0;
    D_800E0938 = -1;
    func_80011800(0xD, 0, 0, 0, 0, 0, 0, 0);
    func_800109CC();
    D_800E093A = 0;
    for (;;) {
        s32 i = D_800E093A;
        D_80103022[i] = 0;
        D_80109BA4[i] = 0;
        D_801083D4[i] = 0;
        D_80109DC8[i] = 0;
        if (D_800E076B[i * 4] == 0 &&
            (D_80108F75 >> i) != 0 &&
            ((D_800E0768[i * 2] & 0x1F07) != 5 || (D_80103022[i] = 1, (D_800E076A[i * 4] & 1) != 0))) {
            switch ((u32)(func_800115C0())) {
            case 0xA4:
                if (state != 0 && D_800E093A == 0) {
                    state = 0;
                    D_80109BA4[0] = 1;
                    if (func_80012F50() == 0 && func_80010A2C() != 0) D_800BFC32 = 0x30;
                }
                break;
            case 0xA5:
                __base_D_800E0790 = D_800E0790;
                func_80011800(0xC, __base_D_800E0790 + D_800E093A * 0x68, D_800E093A, 0, 0, 0, 0, 0);
                func_800109CC();
                break;
            case 0x20:
                if (D_800E093A == 0) return func_80010B60(D_801032A8);
                break;
            case 0x12:
                if (D_800E093A == 0) return 0x12;
                break;
            case 166:
                break;
            }
        }
        D_800E093A++;
        if (D_800E093A >= 4) {
            if (state == 0) D_800E093A = 0;
            else state = -1;
            if (state < 0) D_800BFC32 = 0x10;
            return D_800BFC32;
        }
    }
}
