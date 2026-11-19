/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 func_800461D4(s32, s32);                        /* extern */
s32 func_80117740(s32 *, void *);               /* extern */
s32 func_8011775C(void *);                      /* extern */
extern void *D_8011F068;
extern u32 D_8011F06C;
extern s32 D_8011F070;
extern void *D_8011F074;
extern s32 D_8011F0C8;

typedef struct { int field_0; int field_4; int field_8; float field_C; } __repair_record_var_v1;
void func_80117784(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    s32 __repair_store_0;
    s32 __repair_store_1;
    u32 var_s2;
    f32 temp_fv0;
    register f32 var_fv1;
    register int var_s6;
    s32 temp_v0_3;
    s32 __repair_store_2;
    
    void *temp_v0;
    
    
    void *temp_v1;
    void *temp_v1_2;
    register void *temp_v1_3;
    void *var_a0;
    void *var_a1;
    register void *var_s0;
    void *var_s1;
    void *var_v0;
    void *var_v1;

    var_s2 = 0;
    var_s6 = 0;
    var_s1 = NULL;
    if ((*(s32 *)&D_8011F06C) != 0) {
        var_v1 = D_8011F068;
        __repair_rows: {
            ((__repair_record_var_v1*)var_v1)->field_0 = 0;
            ((__repair_record_var_v1*)var_v1)->field_4 = 0;
            ((__repair_record_var_v1*)var_v1)->field_8 = 0;
            ((__repair_record_var_v1*)var_v1)->field_C = -1.0f;
            var_s2 += 1;
            var_v1 += 0x58;
        }
if (var_s2 < (u32) D_8011F06C) goto __repair_rows;
    }
    if ((int)arg0 == arg1) {
        temp_v0 = (arg0 * 0x58) + D_8011F068;
        __repair_store_0 = (s32) (*(s32 *)((char *)((*(void **)((char *)(temp_v0) + 0x10))) + 0));
        __repair_store_1 = (s32) (*(s32 *)((char *)((*(void **)((char *)(temp_v0) + 0x10))) + 4));
        __repair_store_2 = (s32) (*(s32 *)((char *)((*(void **)((char *)(temp_v0) + 0x10))) + 8));
        (*(s32 *)((char *)(arg2) + 0)) = __repair_store_0;
        (*(s32 *)((char *)(arg2) + 4)) = __repair_store_1;
        (*(s32 *)((char *)(arg2) + 8)) = __repair_store_2;
        (*(s32 *)((char *)(arg3) + 0)) = (s32) (*(s32 *)((char *)((*(void **)((char *)(temp_v0) + 0x10))) + 0));
        (*(s32 *)((char *)(arg3) + 4)) = (s32) (*(s32 *)((char *)((*(void **)((char *)(temp_v0) + 0x10))) + 4));
        (*(s32 *)((char *)(arg3) + 8)) = (s32) (*(s32 *)((char *)((*(void **)((char *)(temp_v0) + 0x10))) + 8));
        return;
    }
    D_8011F0C8 = 1;
    D_8011F070 = 0;
    temp_v1 = D_8011F068 + (arg0 * 0x58);
    D_8011F074 = temp_v1;
    (*(s32 *)((char *)(temp_v1) + 0xC)) = 0;
    if (0 == 0) {
        for (;;) {
            var_v0 = D_8011F074;
            var_fv1 = 999999.0f;
            var_s1 = NULL;
            if (var_v0 != NULL) {
                do {
                    temp_fv0 = (*(f32 *)((char *)(var_v0) + 0xC));
                    if (var_fv1 > temp_fv0) {
                        var_s1 = var_v0;
                        var_fv1 = temp_fv0;
                    }
                    var_v0 = (*(void **)((char *)(var_v0) + 4));
                } while (var_v0 != NULL);
            }
            if (var_s1 == NULL) {
                break;
            }
            var_s2 = 0;
            if (var_s1 == (D_8011F068 + (arg1 * 0x58))) {
                var_s6 = 1;
            } else {
                var_s0 = var_s1;
                do {
                    temp_v0 = (*(void **)((char *)(var_s0) + 0x14));
                    var_s2 += 1;
                    if ((temp_v0 != NULL) && ((*(f32 *)((char *)(temp_v0) + 0xC)) == -1.0f)) {
                        (*(f32 *)((char *)((*(void **)((char *)(var_s0) + 0x14))) + 0xC)) = (f32) (s32) ((*(f32 *)((char *)(var_s1) + 0xC)) + func_800461D4((*(s32 *)((char *)(var_s1) + 0x10)), (*(s32 *)((char *)(temp_v0) + 0x10))));
                        (*(void **)((char *)((*(void **)((char *)(var_s0) + 0x14))) + 8)) = var_s1;
                        func_80117740(&D_8011F070, (*(void **)((char *)(var_s0) + 0x14)));
                        *(s32 *)0x8011F0C8 = D_8011F0C8 + 1;
                    }
                    var_s0 += 4;
                } while (0x10U > var_s2);
                func_8011775C(var_s1);
                D_8011F0C8--;
            }
            if (var_s6 != 0) {
                goto block_22;
            }
        }
        temp_v1_2 = (*(void **)((char *)((temp_v0_3 + D_8011F068)) + 0x10));
        temp_v0_3 = arg0 * 0x58;
        (*(s32 *)((char *)(arg2) + 0)) = (s32) (*(s32 *)((char *)(temp_v1_2) + 0));
        (*(s32 *)((char *)(arg2) + 4)) = (s32) (*(s32 *)((char *)(temp_v1_2) + 4));
        (*(s32 *)((char *)(arg2) + 8)) = (s32) (*(s32 *)((char *)(temp_v1_2) + 8));
        temp_v0 = (*(void **)((char *)((temp_v0_3 + D_8011F068)) + 0x10));
        (*(s32 *)((char *)(arg3) + 0)) = (s32) (*(s32 *)((char *)(temp_v0) + 0));
        (*(s32 *)((char *)(arg3) + 4)) = (s32) (*(s32 *)((char *)(temp_v0) + 4));
        (*(s32 *)((char *)(arg3) + 8)) = (s32) (*(s32 *)((char *)(temp_v0) + 8));
        return;
    }
block_22:
    var_a1 = (*(void **)((char *)(var_s1) + 0x10));
    temp_v1_3 = D_8011F068 + (arg0 * 0x58);
    var_a0 = var_a1;
    if (var_s1 != temp_v1_3) {
        do {
            var_s1 = (*(void **)((char *)(var_s1) + 8));
            var_a1 = var_a0;
            var_a0 = (*(void **)((char *)(var_s1) + 0x10));
        } while (var_s1 != temp_v1_3);
    }
    (*(s32 *)((char *)(arg2) + 0)) = (s32) (*(s32 *)((char *)(var_a0) + 0));
    (*(s32 *)((char *)(arg2) + 4)) = (s32) (*(s32 *)((char *)(var_a0) + 4));
    (*(s32 *)((char *)(arg2) + 8)) = (s32) (*(s32 *)((char *)(var_a0) + 8));
    (*(s32 *)((char *)(arg3) + 0)) = (s32) (*(s32 *)((char *)(var_a1) + 0));
    (*(s32 *)((char *)(arg3) + 4)) = (s32) (*(s32 *)((char *)(var_a1) + 4));
    (*(s32 *)((char *)(arg3) + 8)) = (s32) (*(s32 *)((char *)(var_a1) + 8));
}
