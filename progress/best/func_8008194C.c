static __inline__ u8 __repair_inline(u8 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern char D_80115094[];

s32 func_8008194C(s32 arg0, s32 arg1) {
char *__repair_addr;

    unsigned long temp_v1;
    unsigned int temp_a2;
    
    s32 var_v0_2;
    u8 temp_v1_2;
    u8 temp_v1_3;
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *temp_t0;

    temp_a2 = arg0 * 0xA0;
    temp_t0 = temp_a2 + D_80115094;
    __repair_phase_storage.pointer = (arg1 * 2) + temp_t0;
    temp_v1_2 = (*(u8 *)((char *)(__repair_phase_storage.pointer) + 1));
    if (temp_v1_2) {
        register temp_v1 = *((temp_v1_2 * 4) + (D_80115094 + 0x70) + temp_a2);
        if (!((*(u8 *)((char *)(__repair_phase_storage.pointer) + 0)) & 0x40)) {do{
            var_v0_2 = arg1 * 2;}while(0);
            if (temp_v1 > 0) {
                return temp_v1;
            }
            goto block_6;
        }
        __repair_phase_storage.value = (short)temp_v1;
        if (temp_v1 >= 0) {
            goto block_5;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return __repair_phase_storage.value;
    }
block_5:
    var_v0_2 = arg1 * 2;
__repair_addr = (char *)(var_v0_2 + temp_t0);

block_6:
    temp_v1_3 = __repair_inline(*(s32 *)(__repair_addr));
    if (!(temp_v1_3 & 4)) {
        return 0;
    }
    __repair_phase_storage.value = (((temp_v1_3 & 0x20) != 0) * -0x10000) | 0x10000;
    return __repair_phase_storage.value;
}
