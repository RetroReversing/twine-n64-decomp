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

extern u16 D_800BFC32;
extern char D_800E0768[];
extern u8 D_800E077C[];
extern s16 D_800E093A;
extern char D_80103022[];
extern u8 D_80108F75;

u16 func_80012BCC(void) {
int __repair_literal;

    s16 *temp_a0;
    s16 temp_v0;

    D_800E093A = 0;
    do {
        temp_a0 = (D_800E093A * 2) + D_80103022;
        *temp_a0 = 0;
__repair_literal = 4;

        if ((*(D_800E077C + (D_800E093A * 6)) == 0) && (((s32) D_80108F75 >> D_800E093A) != 0) && ((*(u16 *)(D_800E0768 + (D_800E093A * __repair_literal)) & 0x1F07) == 5)) {
            *temp_a0 = 1;
        }
        temp_v0 = (u16) D_800E093A + 1;
        D_800E093A = temp_v0;
    } while (temp_v0 < 4);
    return D_800BFC32;
}
