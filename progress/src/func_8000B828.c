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

s32 func_8000B580();
s32 func_8000B79C();
s32 func_8009D090();
s32 osCreateThread();
s32 osStartThread();
extern char D_800B2598[];
extern char D_80107CE8[];
extern s16 gExpansionPakPresent;
extern char D_80108798[];
extern char D_80115040[];
extern char D_80117330[];
extern s32 gfxSyncThreadEntry;
extern s32 rspTaskThread;

s32 func_8000B828(s32 arg0) {
    s32 var_a1;

    var_a1 = 0x4B000;
    if (gExpansionPakPresent != 0) {
        var_a1 = 0xAA000;
    }
    func_8000B580(arg0, var_a1);
    func_8000B79C();
    func_8009D090(D_800B2598);
    osCreateThread(D_80107CE8, 8, &gfxSyncThreadEntry, 0, D_80117330, 0x75);
    osStartThread(D_80107CE8);
    osCreateThread(D_80108798, 7, &rspTaskThread, 0, D_80115040, 0x7A);
    osStartThread(D_80108798);
    return 0;
}
