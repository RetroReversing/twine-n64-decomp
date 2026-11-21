s32 workerLockAcquire();
s32 workerLockRelease();
extern s32 D_800F7954;
extern char D_800F7958[];
extern char D_800F795C[];
extern char D_800F7960[];
typedef struct { s32 w[2]; } __repair_words2;
s32 insertOrCountEntry(u16 arg0, s32 arg1) {
int __repair_literal;
    s32 temp_v0, temp_v1, var_a0, var_a3, var_t1, var_v0, var_v1;
    u32 temp_a1;
    void *var_a2, *var_t0;
    workerLockAcquire();
    var_a0 = D_800F7954;
    var_t1 = 0;
__repair_literal = 0;
    if (var_a0 > __repair_literal) {
        temp_a1 = arg0 & 0xFFFF;
        var_v1 = 0;
loop_2:
        if ((u16)*(u16 *)(D_800F795C + var_v1) < temp_a1) {
            var_t1 += 1;
            var_v1 += 8;
            if (var_t1 < var_a0) goto loop_2;
        }
        var_a0 = var_t1 * 8;
        if (var_t1 < D_800F7954) {
            if (*(u16 *)(D_800F795C + var_a0) != temp_a1) {
                var_a3 = D_800F7954 - 1;
                if (D_800F7954 < 0x800) {
                    temp_v1 = var_a3 * 8;
                    if (var_a3 >= var_t1) {
                        var_t0 = temp_v1 + D_800F7960;
                        var_a2 = temp_v1 + (D_800F7960 - 8);
                        do {
                            *((__repair_words2 *)var_t0) = *((__repair_words2 *)var_a2);
                            var_t0 -= 8;
                            var_a3 -= 1;
                            var_a2 -= 8;
                        } while (var_a3 >= var_t1);
                    }
                    var_v0 = D_800F7954 + 1;
                    goto block_15;
                }
                goto block_14;
            }
            *(u16 *)(D_800F795C + 2 + var_a0) = *(u16 *)(D_800F795C + 2 + var_a0) + 1;
            goto block_14;
        }
        goto block_13;
    }
block_13:
    var_v1 = D_800F7954;
    if (var_v1 < 0x800) {
        var_v0 = var_v1 + 1;
        goto block_15;
    }
block_14:
    workerLockRelease();
    return 0;
block_15:
    D_800F7954 = var_v0;
    temp_v0 = var_t1 * 8;
    *(u16 *)(D_800F795C + temp_v0) = arg0;
    *(s32 *)(D_800F7958 + temp_v0) = arg1;
    *(u16 *)(D_800F795C + 2 + temp_v0) = 1;
    workerLockRelease();
    return 1;
}
