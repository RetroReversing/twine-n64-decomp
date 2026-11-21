s32 workerLockAcquire();
s32 workerLockRelease();
extern s32 D_800FD560;
extern char D_800FD564[];
extern char D_800FD566[];
extern char D_800FD568[];

s32 registerWorkerEntry(s32 arg0, void *arg1, s16 arg2) {
    s16 temp_s1;
    s16 temp_s2;
    u16 var_a2;
    s32 var_a0;
s32 __repair_phase_temp_a2;
    s32 temp_v0;
    s32 var_v1; volatile s32 reserved[4];
    s32 var_v1_2;
s32 __repair_phase_var_v1_2;
    void *var_s0;

    var_a2 = arg2;
    var_s0 = arg1;
    var_a0 = arg0;
    temp_v0 = D_800FD560;
    var_v1 = 0;
    var_v1_2 = var_a0;
    temp_s2 = var_a2;
    if (temp_v0 > 0) {
        u32 masked_id = var_v1_2 & 0xFFFF;
        var_a0 = 0;
        for (;;) {
            if (*(u16 *)(D_800FD564 + var_a0) != masked_id) {
                var_v1 += 1;
                var_a0 += 8;
                if (var_v1 < temp_v0) continue;
            }
            break;
        }
    }
    if (var_v1 == D_800FD560) {
        if (var_v1 < 0x80) {
            s32 entry_offset;
            workerLockAcquire(var_a0);
            __repair_phase_temp_a2 = temp_s2 & 0xFFFF;
            entry_offset = D_800FD560 * 8;
            *(u16 *)(D_800FD564 + (unsigned)entry_offset) = var_v1_2;
            *(u16 *)(D_800FD566 + entry_offset) = temp_s2;
            *(void **)(D_800FD568 + entry_offset) = var_s0;
            __repair_phase_var_v1_2 = 0;
            if (__repair_phase_temp_a2 > 0) {
                do {
                    (*(s8 *)((char *)(var_s0) + 9)) = 0x1F;
                    __repair_phase_var_v1_2 += 1;
                    var_s0 += 0xC;
                } while (__repair_phase_var_v1_2 < __repair_phase_temp_a2);
            }
            D_800FD560 += 1;
            workerLockRelease();
            return 1;
        }
    }
    return 0;
}
