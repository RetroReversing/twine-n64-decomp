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

s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_800A0170();
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osYieldThread();
extern s8 D_800FDBB0;
extern char D_800FDBB4[];
extern char D_800FDBB8[];
extern char D_800FDBBC[];
extern char D_800FDBE8[];
extern char D_800FDC00[];
extern s32 *D_8011772C;
extern s32 func_8009D100;

void func_8009D284(s32 arg0, s32 arg1, s32 arg2) {
    func_8008C0D4();
    if (D_8011772C == NULL) {
        osCreateMesgQueue(D_800FDBE8, D_800FDC00, 1);
        D_800FDBB0 = 0;
        D_8011772C = &func_8009D100;
    }
    if ((u8) D_800FDBB0 < 4U) {
        *(D_800FDBB4 + (D_800FDBB0 * 0xC)) = arg0;
        *(D_800FDBB8 + (D_800FDBB0 * 0xC)) = arg1;
        *(D_800FDBBC + (D_800FDBB0 * 0xC)) = (arg2 + 0xF) & ~0xF;
        D_800FDBB0 += 1;
        func_800A0170(arg0, arg2);
        func_8008C11C();
        osRecvMesg(D_800FDBE8, 0, 1);
        osYieldThread();
        return;
    }
    func_8008C11C();
}
