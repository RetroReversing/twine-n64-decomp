static __inline__ int __repair_inline(s32 a, s32 b) { return a > b; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800A0170(void *, s32);                 /* extern */
extern void *D_800E4254;
extern void *D_800E4258;
extern s32 D_800E425C;
extern s32 D_800E4260;
extern void *D_800E4264;
extern void *(*D_8010017C)(s32, s32);

typedef struct { unsigned char pad[4]; int value; } __repair_field_4;
void func_80089E64(s32 arg0) {
    s32 temp_s1;
    s32 temp_s3;
    s32 var_a1;
    
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_a3;
    void *var_v1;

    var_a1 = arg0 & 0xFFFF;{ s32 __repair_value; __repair_value = var_a1 * 0x600; temp_s1 = __repair_value; }
    __repair_phase_storage.pointer = D_8010017C(temp_s1, 0);
    D_800E4254 = __repair_phase_storage.pointer;
    func_800A0170(__repair_phase_storage.pointer, temp_s1);
    temp_v0_2 = D_8010017C(var_a1 * 0x18, 0);
    __repair_phase_storage.value = 1;
    D_800E4258 = temp_v0_2;
    D_800E425C = 0;
    D_800E4260 = 0;
    D_800E4264 = temp_v0_2;
    ((__repair_field_4 *)temp_v0_2)->value = 0;
    (*(void **)((char *)(temp_v0_2) + 0x14)) = (void *) D_800E4254;
    if (__repair_inline(var_a1, 1)) {
        var_a3 = D_800E4254 + 0x600;
        var_a1 = 0;
        var_v1 = temp_v0_2 + 0x18;
        __repair_rows: {
            (*(void **)((char *)(var_v1) + 0x14)) = var_a3;
            var_a3 += 0x600;
            temp_v0_3 = temp_v0_2 + var_a1;
            (*(void **)((char *)(var_v1) + -0x18)) = var_v1;
            ((__repair_field_4 *)var_v1)->value = temp_v0_3;
            var_a1 += 0x18;
            var_v1 += 0x18;
            __repair_phase_storage.value += 1;
        }
if (__repair_phase_storage.value < (arg0 & 0xFFFF)) goto __repair_rows;
    }
    (*(s32 *)((char *)(((__repair_phase_storage.value * 0x18) + D_800E4258)) + -0x18)) = 0;
}
