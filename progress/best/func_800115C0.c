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

typedef struct {
    u8 bytes[32];
} SaveResponse;

extern SaveResponse D_800E0940;
extern SaveResponse D_800E079C;
s32 func_800109CC();
s32 func_80010C00();
s32 func_80011800();
s32 memset();
extern u16 D_800BFC32;
extern char D_800E0790[];
extern s16 D_800E093A;
extern char D_800E096C[];
extern char D_800E0970[];
extern s32 D_801032A8;
extern s16 D_80109DC8[];

u16 func_800115C0(void) {
    s32 temp_v1;
    u16 var_v0;

    temp_v1 = func_80010C00() & 0xFFFF;
    switch (temp_v1) {                              /* irregular */
    case 0x0:
        /* fallthrough */
    case 0x62:
        func_80011800(3, (D_800E093A * 0x68) + D_800E0790, D_800E096C, D_800E0970, 0, 0, 0, 0);
        if (func_800109CC() == 0) {
            if (D_800E093A == 0) {
                D_800E0940 = D_800E079C;
            }
            return 0xA4;
        }
        if (D_800E093A == 0) {
            memset(&D_800E0940, 0, 0x20);
        }
        func_80011800(0xC, (D_800E093A * 0x68) + D_800E0790, (s32 *) D_800E093A, NULL, 0, 0, 0, 0);
        if (func_800109CC() == 0) {
            D_80109DC8[D_800E093A] = 1;
            return 0xA5U;
        }
        func_80011800(0xE, (D_800E093A * 0x68) + D_800E0790, (s32 *) D_800E093A, NULL, 0, 0, 0, 0);
        if (func_800109CC() == 0) {
            return 0x63U;
        }
        var_v0 = 0x62;
        if (D_801032A8 != 0xB) {
            var_v0 = 0x10;
        }
        return var_v0;
    default:
        return D_800BFC32;
    }
}

