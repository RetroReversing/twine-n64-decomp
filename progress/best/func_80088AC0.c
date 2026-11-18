/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 func_8009D284();
extern u8 D_800CEEC0;
extern u8 D_800CEEC1;
extern s32 D_800E3F14;
extern s32 D_800E3F18;
extern s32 *D_800E3F1C;
extern s32 D_800E3F20;
extern s32 (*D_80100178)(s32);
extern s32 *(*D_8010017C)(s32, s32);
extern s32 (*D_80100180)(s32 *);

s32 func_80088AC0(s32 arg0, s32 arg1) {
    s32 *temp_v0_2;
    s32 *temp_v0_3;
    s32 temp_v0;

    if (D_800CEEC0 != 0) {
        if ((D_800E3F1C != NULL) && (D_800CEEC1 != 0)) {
            D_80100180(D_800E3F1C);
        }
        if ((arg0 & 0xF0000000) != 0x80000000) {
            temp_v0 = D_80100178(arg0);
            D_800E3F14 = temp_v0;
            D_800E3F18 = temp_v0;
            temp_v0_2 = D_8010017C(4, 0);
            if (temp_v0_2 != NULL) {
                func_8009D284(temp_v0_2, D_800E3F14, 4);
                D_800E3F20 = *temp_v0_2;
                D_80100180(temp_v0_2);
                temp_v0_3 = D_8010017C(D_800E3F20 * 4, 0);
                D_800E3F1C = temp_v0_3;
                if (temp_v0_3 != NULL) {
                    func_8009D284(temp_v0_3, D_800E3F14 + 4, D_800E3F20 * 4);
                    D_800CEEC1 = 1;
                    return 1;
                }
            }
            goto block_9;
        }
        D_800E3F14 = arg0;
        D_800E3F18 = D_80100178(arg1);
        D_800E3F1C = arg0 + 4;
        D_800CEEC1 = 0;
        D_800E3F20 = *(s32 *)arg0;
        return 1;
    }
block_9:
    return 0;
}
