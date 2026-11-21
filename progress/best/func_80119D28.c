/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 approxDistance(void *, void *);                  /* extern */
extern void *gBonusSceneHandle;

void func_80119D28(void *arg0) {
    f32 temp_fv1;
    s32 temp_v1;
    void **var_s1;
    u32 var_s2;
    void *temp_a0;
    void *temp_a1;
    void *temp_v0;

    var_s2 = 0;
    var_s1 = &gBonusSceneHandle;
    (*(u16 *)((char *)(arg0) + 0x7C)) = (u16) ((*(u16 *)((char *)(arg0) + 0x7C)) + 1);
    do {
        temp_a0 = *var_s1;
        if (temp_a0 != NULL) {
            temp_v1 = (*(u16 *)((char *)(temp_a0) + 0x7A));
            if (((u32) (temp_v1 - 2) >= 2U) && ((s16) temp_v1 != 6) && ((*(s32 *)((char *)(temp_a0) + 0x20)) == (*(s32 *)((char *)(arg0) + 0x20)))) {
                temp_fv1 = approxDistance(temp_a0 + 0x24, arg0 + 0x24);
                temp_v0 = (*(void **)((char *)(*var_s1) + 0x6C));
                if (temp_v0 != NULL) {
                    temp_a1 = (*(void **)((char *)(temp_v0) + 0xB4));
                    if ((temp_a1 != NULL) && (temp_fv1 < (*(f32 *)((char *)(arg0) + 0x54))) && ((s16) (*(u16 *)((char *)(arg0) + 0x7C)) == (((u32)*(s16 *)((char *)arg0 + 0x7C) / 150U) * 150U))) {
                        (*(u16 *)((char *)(temp_a1) + 0xC)) = (u16) ((*(u16 *)((char *)(temp_a1) + 0xC)) + 1);
                    }
                }
            }
        }
        var_s2 += 1;
        var_s1 += 1;
    } while (var_s2 < 4U);
}
