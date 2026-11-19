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

s32 func_800A0170();
s32 osPiStartDma();
s32 osRecvMesg();
s32 osYieldThread();
extern char D_80113028[];

void func_8000B900(s32 arg0, s32 arg1, u32 arg2) {
    u8 sp20[0x18];
    s32 var_s2;
    s32 var_s3;
    s32 var_v0;
    u32 var_s0;
    u32 var_s1;

    var_s2 = arg0;
    var_s3 = arg1;
    var_s1 = arg2;
    func_800A0170(arg0, var_s1);
    var_v0 = var_s1 < 0x1001U;
    if (var_s1 != 0) {
        do {
            var_s0 = var_s1;
            if (var_v0 == 0) {
                var_s0 = 0x1000;
            }
            osPiStartDma(sp20, 0, 0, var_s3, var_s2, var_s0, D_80113028);
            var_s3 += var_s0;
            var_s2 += var_s0;
            var_s1 -= var_s0;
            osRecvMesg(D_80113028, 0, 1);
            osYieldThread();
            var_v0 = var_s1 < 0x1001U;
        } while (var_s1 != 0);
    }
}
