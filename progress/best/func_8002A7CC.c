/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_8002A7CC(void *arg0, s32 arg1, s8 arg2, s8 arg3) {
    s16 var_a2;
    f32 temp_fv0;
    register s32 temp_t1;
    
    unsigned long var_v1;
    u32 temp_t0;
    u8 temp_v0;
    u8 temp_v1;
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *var_a1_2;

    if (arg0 != NULL) {
        temp_v1 = (*(u8 *)((char *)(arg0) + 0x19));
        temp_t0 = temp_v1 & 0xFF;
        if (temp_t0 < (u8) (*(u8 *)((char *)(arg0) + 0x1A))) {
            (*(u8 *)((char *)(arg0) + 0x19)) = (u8) (temp_v1 + 1);
            temp_t1 = temp_t0 * 0xC;
            *(s32 *)(temp_t1 + (*(void **)((char *)(arg0) + 0))) = arg1;
            (*(s8 *)((char *)((temp_t1 + (*(void **)((char *)(arg0) + 0)))) + 8)) = arg2;
            (*(u16 *)((char *)((temp_t1 + (*(void **)((char *)(arg0) + 0)))) + 4)) = (u16) (*(u16 *)((char *)(arg0) + 0x16));
            var_a1_2 = (*(void **)((char *)(arg0) + 0));
            __repair_phase_storage.pointer = (void *) ((temp_t1) + (s32) var_a1_2);
            if (temp_t0) {
                var_a1_2 += (temp_t0 - 1) * 0xC;
            }
            (*(s16 *)((char *)(__repair_phase_storage.pointer) + 6)) = (s16) ((*(u16 *)((char *)(var_a1_2) + 6)) + (*(u8 *)((char *)(arg0) + 0x21)));
            (*(s8 *)((char *)((temp_t1 + (*(void **)((char *)(arg0) + 0)))) + 9)) = arg3;
            temp_v0 = (*(u8 *)((char *)(arg0) + 0x19));
            __repair_phase_storage.value = 0;
            var_a2 = 0;
            if (temp_v0) {
                var_v1 = 0 & 0xFF;
                do {
                    var_v1 = __repair_phase_storage.value & 0xFF;
                    var_a2 += (*(u8 *)((char *)(((var_v1 * 0xC) + (*(void **)((char *)(arg0) + 0)))) + 9));
                    __repair_phase_storage.value += 1;
                } while ((u32) ((temp_t1 = __repair_phase_storage.value) & 0xFF) < temp_v0);
            }
            temp_fv0 = (1.0f / (f32) var_a2) * (f32) (*(u8 *)((char *)(arg0) + 0x1B));
            (*(f32 *)((char *)(arg0) + 0xC)) = temp_fv0;
            if (temp_fv0 > 1.0f) {
                (*(f32 *)((char *)(arg0) + 0xC)) = 1.0f;
            }
            return (*(void **)((char *)(arg0) + 0)) + ((__repair_phase_storage.value & 0xFF) * 0xC);
        }
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return NULL;
    }
    return NULL;
}
