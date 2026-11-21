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

s32 func_8008C7B0();
extern s32 sKeyTableCount;
extern s32 sortedEntryCount;
extern s32 gCountedEntryCount;
extern s32 D_800F8158;
extern s32 D_800F8D5C;
extern char D_800F8D60[];
extern char D_800F8D62[];
extern s32 D_800FD560;

void func_80098644(void) {
    s32 var_v1;

    var_v1 = 0;
    sKeyTableCount = 0;
    sortedEntryCount = 0;
    gCountedEntryCount = 0;
    D_800F8158 = 0;
    D_800FD560 = 0;
    D_800F8D5C = 0;
    do {
        *(s16 *)(D_800F8D60 + var_v1) = 0;
        *(s16 *)(D_800F8D62 + var_v1) = 0;
        var_v1 += 4;
    } while (var_v1 < 0x800);
    func_8008C7B0();
}
