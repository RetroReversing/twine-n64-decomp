/* machine draft (m2c) for gcc-2.7.2-kmc -G8 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_800104B8();
s16 func_80010958();
s32 func_800109CC();
s32 func_80010B60();
s32 func_80011800();
s32 func_8001233C();
extern s16 D_800BFC32;
extern char D_800E0790[];
extern s16 D_800E093A;
extern s32 *D_800E0960;
extern s32 *D_800E0964;
extern s32 D_800E0978;
extern char D_80103030[];
extern s32 D_80103042;
extern s32 D_801032A8;
extern char D_80107B68[];
extern char D_8010840C[];
extern char D_80108410[];
extern char D_80108416[];
extern char D_8010A3C5[];
extern s32 D_80115308;

s32 func_80012428(void) {
    s32 temp_a1;

    D_800BFC32 = 0;
    func_800104B8(&D_80115308, D_80103030, 0x10);
    func_800104B8(&D_80103042, D_8010A3C5, 4);
    if ((*(u16 *)(D_80107B68 + (D_800E0978 * 0x18)) == 0) || (temp_a1 = D_800E0978 << 5, func_80011800(6, (D_800E093A * 0x68) + D_800E0790, *(u16 *)(D_80108410 + temp_a1), *(s32 *)(D_8010840C + temp_a1), temp_a1 + D_80108416, temp_a1 + (D_80108416 - 4), NULL, NULL), (func_800109CC() == 0))) {
        func_80011800(0xA, (D_800E093A * 0x68) + D_800E0790, 0x3639U, 0x4E4F3745, &D_80115308, &D_80103042, D_800E0960, &D_800E0978);
        if (func_800109CC() == 0) {
            *D_800E0964 = func_80010958((s8 *) D_800E0964 + 2, D_800E0960 - 2);
            func_80011800(9, (D_800E093A * 0x68) + D_800E0790, (u16) D_800E0978, 1, NULL, D_800E0960, D_800E0964, NULL);
            if (func_800109CC() == 0) {
                func_80011800(0xB, (D_800E093A * 0x68) + D_800E0790, 0x3639U, 0x4E4F3745, &D_80115308, &D_80103042, &D_800E0978, NULL);
                if (func_800109CC() == 0) {
                    return func_8001233C() & 0xFFFF;
                }
            }
        }
    }
    return func_80010B60(D_801032A8) & 0xFFFF;
}
