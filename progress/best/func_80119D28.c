/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 func_80045E34(void *, void *);                  /* extern */
extern void *D_8010A500;

void func_80119D28(void *arg0) {
    unsigned var_s2;
    f32 temp_fv1;
    void *temp_v0;
    void *temp_a1;
    void **var_s1;
    register u16 temp_v1;
    void *temp_a0;

    var_s1 = &D_8010A500;
    var_s2 = 0;
    (*(u16 *)((char *)((unsigned short)arg0) + 0x7C)) = (u16) ((*(u16 *)((char *)(arg0) + 0x7C)) + 1);
    do {
        temp_a0 = *var_s1;
        if (temp_a0 != NULL) {
            register temp_v1 = (*(u16 *)((char *)(temp_a0) + 0x7A));
            if (((u32) (temp_v1 - 2) >= 2U) && ((s16) temp_v1 != 6) && ((*(s32 *)((char *)(temp_a0) + 0x20)) == (*(s32 *)((char *)(arg0) + 0x20)))) {
                temp_v0 = (*(void **)((char *)(*var_s1) + 0x6C));
                temp_fv1 = func_80045E34(temp_a0 + 0x24, arg0 + 0x24);
                if ((u32)temp_v0 != NULL) {
                    temp_a1 = (*(void **)((char *)(temp_v0) + 0xB4));
                    if ((temp_a1 != NULL) && (temp_fv1 < (*(f32 *)((char *)(arg0) + 0x54))) && ((s16) (*(u16 *)((char *)(arg0) + 0x7C)) == (((*(u16 *)((char *)(arg0) + 0x7C)) / 150) * 0x96))) {
                        (*(u16 *)((char *)(temp_a1) + 0xC)) = (u16) ((*(u16 *)((char *)(temp_a1) + 0xC)) + 1);
                    }
                }
            }
        }/*__repair_loop_weight*/do {
        ++var_s2;} while (0);
        var_s1 += 4;
    } while (4U > var_s2);
}
