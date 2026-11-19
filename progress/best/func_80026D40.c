/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80016314(s32);                         /* extern */
s32 func_80026A5C(void *, s32);                 /* extern */
extern void *D_80109BB0;

void func_80026D40(void *arg0, s32 arg1) {
    s32 (*temp_v0_2)();
    s16 var_s1;
    s32 (*temp_v0_3)(void *);
    s32 temp_v1_2;
    s16 temp_v1;
    unsigned int var_s1_2;
    s32 temp_a0;
    s32 var_v1;
    void *temp_s2;
    
    void *temp_s0;
    void *temp_v0;
    void *var_a0;

    var_a0 = arg0;
    temp_v0 = (*(void **)((char *)(D_80109BB0) + 0x10));
    temp_s2 = var_a0;
    var_s1 = 0;
    if (temp_v0 != NULL) {
        temp_v0_2 = (*(s32 (**)())((char *)(temp_v0) + 0xC));
        if (temp_v0_2 != NULL) {
            temp_v0_2();
        }
        var_a0 = D_80109BB0;
        if ((*(u8 *)((char *)((*(void **)((char *)(var_a0) + 0x10))) + 5)) != 0) {
            do {
                temp_s0 = (*(s32 *)((char *)((*(void **)((char *)(var_a0) + 0x10))) + 0)) + (var_s1 * 0x28);
                temp_a0 = (*(s32 *)((char *)(temp_s0) + 8));
                if (temp_a0) {
                    func_80016314(temp_a0);
                    (*(s32 *)((char *)(temp_s0) + 8)) = 0;
                }
                var_a0 = D_80109BB0;
                temp_v1 = var_s1 + 1;
                var_s1 = temp_v1;
            } while (temp_v1 < (s32) (*(u8 *)((char *)((*(void **)((char *)(var_a0) + 0x10))) + 5)));
        }
    }
    (*(void **)((char *)(D_80109BB0) + 0x10)) = temp_s2;
    if (temp_s2 != NULL) {
        temp_v0_3 = (*(s32 (**)(void *))((char *)(temp_s2) + 8));
        if (temp_v0_3 != NULL) {
            temp_v0_3(var_a0);
        }
        var_s1_2 = 0;
        if ((*(u8 *)((char *)(temp_s2) + 5)) != 0) {
            var_v1 = 0 << 0x10;
            __repair_rows: {
                temp_s0 = (*(s32 *)((char *)(temp_s2) + 0)) + ((var_v1 >> 0x10) * 0x28);
                temp_v1_2 = var_s1_2 + 1;
                var_s1_2 = temp_v1_2;
                (*(s32 *)((char *)(temp_s0) + 8)) = func_80026A5C(temp_s0, arg1);
                var_v1 = var_s1_2 << 0x10;
            }
if (temp_v1_2 < (s32) (*(u8 *)((char *)(temp_s2) + 5))) goto __repair_rows;
        }
    }
}
