/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 approxDistance(void *, void *);                 /* extern */
s32 func_800179E8(void *, void **, s32, u8); /* extern */
s32 func_80073108(void *, void *, f32);     /* extern */
s32 func_800851E0(void *);                      /* extern */
s32 startSubdivision(s32, void **, void *, s32, f32, f32, s32, s32); /* extern */
s32 updateNearbyEntries(f32, void *, void *);   /* extern */
extern s32 gBorderSkipActive;

typedef struct { s32 w[3]; } __repair_words3;
void func_80054FEC(void *arg0, f32 arg1, f32 arg2, void *arg3, void *arg4, s32 arg5, s32 arg6) {
    f32 temp_fv0;
    f32 var_fv0;
    s32 temp_v1;
    void **var_s3;
    void *temp_a2;
    
    void *temp_s0;
    void *var_s1;
    void *var_s6;

    var_s3 = (*(void ***)((char *)(arg3) + 0x20));
    if (var_s3 != NULL) {
        var_s1 = (*(void **)((char *)(var_s3) + 0));
        var_s6 = (*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58));
        if (arg0 != NULL) {
            func_800179E8(arg4, var_s3, 0x10000, (*(u8 *)((char *)(arg0) + 0x5E)));
        }
        updateNearbyEntries(arg2 * 4.0f, arg3, arg4);
loop_4:
        if (var_s1 != NULL) {
            do {
                temp_v1 = (*(s32 *)((char *)(var_s1) + 0x60)) | 0x10000;
                (*(s32 *)((char *)(var_s1) + 0x60)) = temp_v1;
                if ((*(u16 *)((char *)(var_s1) + 0x78)) == 0x4B) {
                    (*(s32 *)((char *)(var_s1) + 0x60)) = (s32) (temp_v1 | 1);
                }
                if ((*(s32 *)((char *)(var_s1) + 0x58)) & 0x400) {
                    temp_fv0 = approxDistance(arg4, var_s1 + 0x24);
                    if (temp_fv0 < arg2) {
                        f32 falloff;
                        temp_fv0 /= arg2;
                        falloff = 1.0f - temp_fv0;
                        if ((u32) ((*(u16 *)((char *)(var_s1) + 0x78)) - 2) < 2U) {
                            temp_a2 = (*(void **)((char *)(var_s1) + 0x6C));
                            if (gBorderSkipActive == 0) {
                                var_fv0 = arg1 * 0.25f;
                            } else {
                                var_fv0 = arg1;
                            }
                            (*(s32 *)((char *)(var_s1) + 0x60)) = arg5;
                            (*(s32 *)((char *)(temp_a2) + 0x18C)) = (s32) (((*(s32 *)((char *)(temp_a2) + 0x18C)) & 0xFFFF0FFF) | 0x7000);
                            (*(__repair_words3 *)((char *)(temp_a2) + 0x1A0)) = *(__repair_words3 *) ((s8 *) arg4 + 0x0);
                            (*(f32 *)((char *)(temp_a2) + 0x1B0)) = (f32) ((*(f32 *)((char *)(temp_a2) + 0x1B0)) + (falloff * var_fv0));
                            (*(s32 *)((char *)(temp_a2) + 0x1B4)) = 0;
                            (*(s32 *)((char *)(temp_a2) + 0x1B8)) = arg6;
                            if (arg0 != NULL) {
                                (*(s32 *)((char *)(temp_a2) + 0x1B4)) = (s32) (*(u8 *)((char *)(arg0) + 1));
                            }
                            if ((u32) ((*(u16 *)((char *)(arg3) + 0x78)) - 6) < 2U) {
                                (*(s32 *)((char *)(temp_a2) + 4)) = (s32) (*(s32 *)((char *)((*(void **)((char *)(arg3) + 0x6C))) + 0x24));
                            }
                        }
                        if (((*(u16 *)((char *)(var_s1) + 0x78)) == 1) && ((*(s16 *)((char *)(var_s1) + 0x7A)) != 0x27)) {
                            temp_a2 = (*(void **)((char *)(var_s1) + 0x6C));
                            (*(s32 *)((char *)(var_s1) + 0x60)) = arg5;
                            (*(s32 *)((char *)(temp_a2) + 0x88)) = (s32) (((*(s32 *)((char *)(temp_a2) + 0x88)) & 0xFFE1FFFF) | 0xE0000);
                            (*(__repair_words3 *)((char *)(temp_a2) + 0x50)) = *(__repair_words3 *) ((s8 *) arg4 + 0x0);
                            (*(s32 *)((char *)(temp_a2) + 0x64)) = 0;
                            (*(s32 *)((char *)(temp_a2) + 0x68)) = arg6;
                            (*(f32 *)((char *)(temp_a2) + 0x60)) = (f32) ((*(f32 *)((char *)(temp_a2) + 0x60)) + arg1);
                            if (arg0 != NULL) {
                                (*(s32 *)((char *)(temp_a2) + 0x64)) = (s32) (*(u8 *)((char *)(arg0) + 1));
                            }
                        }
                        if ((*(s32 *)((char *)(var_s1) + 0x5C)) & 2) {
                            (*(s32 *)((char *)(var_s1) + 0x60)) = (s32) ((*(s32 *)((char *)(var_s1) + 0x60)) | 1);
                            if ((*(s32 *)((char *)(var_s1) + 0x70)) != 0) {
                                temp_s0 = var_s1 + 0x24;
                                func_80073108(temp_s0, arg4, 5.0f);
                                startSubdivision((*(s32 *)((char *)(var_s1) + 0x70)), var_s3, temp_s0, (*(s32 *)((char *)(var_s1) + 0x3C)), (*(f32 *)((char *)(var_s1) + 0x40)), (*(f32 *)((char *)(var_s1) + 0x44)), 1, 1);
                                func_800851E0(arg4);
                            }
                        }
                    }
                }
                var_s1 = (*(void **)((char *)(var_s1) + 0));
            } while (var_s1 != NULL);
        }
        if (var_s6 != NULL) {
            var_s3 = (*(void ***)((char *)(var_s6) + 8));
            var_s6 = (*(void **)((char *)(var_s6) + 0));
            var_s1 = *var_s3;
            goto loop_4;
        }
    }
}
