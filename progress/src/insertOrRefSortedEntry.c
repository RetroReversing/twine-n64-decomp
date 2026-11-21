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

void workerLockAcquire(void);
void workerLockRelease(void);
extern volatile s32 D_800F3950;
extern char D_800F3954[];
extern char D_800F3958[];
extern char D_800F395C[];

s32 insertOrRefSortedEntry(u16 arg0, s32 arg1) {
    struct { s32 value; u16 key; u16 refs; } previous;
    s32 __repair_store_0;
    s32 __repair_store_1;
    s32 temp_a0;
    s32 count;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a3;
    s32 var_t1;
    s32 var_v0;
    s32 var_v1;
    u32 temp_a1;
    void *var_a2;
    void *var_t0;

    workerLockAcquire();
    temp_a0 = D_800F3950;
    var_t1 = 0;
    if (temp_a0 > 0) {
        temp_a1 = arg0 & 0xFFFF;
        var_v1 = 0;
loop_2:
        if ((u16) *(u16 *)(D_800F3958 + var_v1) < temp_a1) {
            var_t1 += 1;
            var_v1 += 8;
            if (var_t1 < temp_a0) {
                goto loop_2;
            }
        }
        temp_s0 = var_t1 * 8;
        if (var_t1 < (count = D_800F3950)) {
            if (*(u16 *)(D_800F3958 + temp_s0) != temp_a1) {
                var_a3 = count - 1;
                if (count < 0x800) {
                    temp_v1 = var_a3 * 8;
                    if (var_a3 >= var_t1) {
                        var_t0 = temp_v1 + D_800F395C;
                        var_a2 = temp_v1 + (D_800F395C - 8);
                        do {
                            typedef struct { s32 value, keyRefs; } EntryWords;
                            *(EntryWords *)var_t0 = *(EntryWords *)var_a2;
                            var_t0 -= 8;
                            var_a3 -= 1;
                            var_a2 -= 8;
                        } while (var_a3 >= var_t1);
                    }
                    var_v0 = D_800F3950 + 1;
                    goto block_15;
                }
                goto block_14;
            }
            workerLockRelease();
            *(u16 *)(D_800F3958 + 2 + temp_s0) = *(u16 *)(D_800F3958 + 2 + temp_s0) + 1;
            return 0;
        }
        goto check_capacity;
    }
    count = D_800F3950;
check_capacity:
    if (count < 0x800) {
        var_v0 = count + 1;
        goto block_15;
    }
block_14:
    workerLockRelease();
    return 0;
block_15:
    D_800F3950 = var_v0;
    temp_v0 = var_t1 * 8;
    *(u16 *)(D_800F3958 + temp_v0) = arg0;
    *(s32 *)(D_800F3954 + temp_v0) = arg1;
    *(u16 *)(D_800F3958 + 2 + temp_v0) = 1;
    workerLockRelease();
    return 1;
}
