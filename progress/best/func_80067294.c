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

s32 func_80070CA4();
extern char D_800C469C[];
extern s32 D_80102ED8;

void func_80067294(void *arg0, s32 arg1) {
    s8 temp_v1;
    s8 var_a2;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    var_a2 = 0x18;
    if (D_80102ED8 != 0) {
        var_a2 = 0x21;
    }
    temp_v1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE);
    switch (temp_v1) {
    case 4:
    case 5:
    case 18:
    case 19:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = var_a2;
        func_80070CA4(arg0, arg1, var_a2);
        return;
    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        if (!(*(D_800C469C + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8)) & 0x8000)) {
            do {
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 0xE) -= 1;
            } while (!(*(D_800C469C + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8)) & 0x8000));
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = var_a2;
        func_80070CA4((s8) M2C_FIELD(arg0, void **, 0x68), var_a2);
        M2C_FIELD(M2C_FIELD(temp_s0, void **, 0xA8), s16 *, 0x7A) = 0xA;
        /* fallthrough */
    default:
        return;
    }
}
