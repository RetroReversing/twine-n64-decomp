/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

extern s32 D_801002E0;
extern char D_80100BE0[];
extern char D_80108608[];
extern char D_8010860C[];
extern char D_80108610[];
extern char D_80110B28[];
extern char D_80110B2C[];
extern char D_80110B30[];

void func_80064264(void *arg0, void *arg1, s8 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = D_801002E0 * 0xC;
    *(D_80110B28 + temp_v0) = M2C_FIELD(arg0, s32 *, 0);
    *(D_80110B2C + temp_v0) = M2C_FIELD(arg0, s32 *, 4);
    *(D_80110B30 + temp_v0) = M2C_FIELD(arg0, s32 *, 8);
    temp_v0_2 = D_801002E0 * 0xC;
    *(D_80108608 + temp_v0_2) = M2C_FIELD(arg1, s32 *, 0);
    *(D_8010860C + temp_v0_2) = M2C_FIELD(arg1, s32 *, 4);
    *(D_80108610 + temp_v0_2) = M2C_FIELD(arg1, s32 *, 8);
    *(D_80100BE0 + D_801002E0) = arg2;
    D_801002E0 += 1;
}
