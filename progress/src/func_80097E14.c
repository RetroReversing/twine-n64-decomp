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

s32 workerLockAcquire();
s32 workerLockRelease();
extern char D_800FD55C[];
extern s32 sWorkerEntryCount;
extern char sWorkerEntryIds[];

typedef struct { s32 w[2]; } __repair_words2;
s32 func_80097E14(s32 arg0) {
    volatile u64 unused;
    s32 temp_v1;
    s32 scanCount;
    s32 var_a0;
    s32 var_a2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v1;
    void *var_a3;
    void *var_t0;

    scanCount = sWorkerEntryCount;
    var_a0 = arg0;
    var_s0 = 0;
    if (scanCount > 0) {
        var_a0 &= 0xFFFF;
        var_v1 = 0;
        for (;;) {
            if (*(u16 *)(sWorkerEntryIds + var_v1) != var_a0) {
                var_s0 += 1;
                var_v1 += 8;
                if (var_s0 < scanCount) {
                    continue;
                }
            }
            break;
        }
    }
    if (var_s0 != sWorkerEntryCount) {
        workerLockAcquire();
        var_a2 = var_s0 + 1;
        temp_v1 = var_a2 * 8;
        if (var_a2 < sWorkerEntryCount) {
            var_t0 = temp_v1 + D_800FD55C;
            var_a3 = temp_v1 + (D_800FD55C + 8);
            do {
                M2C_FIELD(var_t0, __repair_words2 *, 0x0) = *(__repair_words2 *) ((s8 *) var_a3 + 0x0);
                var_t0 += 8;
                var_a2 += 1;
                var_a3 += 8;
            } while (var_a2 < sWorkerEntryCount);
        }
        sWorkerEntryCount -= 1;
        workerLockRelease();
        return 1;
    }
    return 0;
}
