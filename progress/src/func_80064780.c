/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80002EF0(void *);                      /* extern */
s32 func_800645A4(u32);                             /* extern */
s32 updateSwayMotion(void *);                      /* extern */
s32 func_80070870(void *);                      /* extern */

void func_80064780(void *arg0) {
    u32 var_s1;
    
    void *temp_s2;
    void *temp_v0;
    void *var_s0;
    void *var_v1;

    temp_s2 = (*(void **)((char *)(arg0) + 0x6C));
    var_s1 = 0;
    var_v1 = temp_s2;
    do {
        (*(s16 *)((char *)(var_v1) + 0x1BC)) = 0;
        var_s1 += 1;
        var_v1 += 2;
    } while (var_s1 < 0x20U);
    var_s1 = 0;
    var_s0 = temp_s2;
    __repair_rows: {
        (*(s8 *)((char *)(var_s0) + 0x1FC)) = 0;
        (*(s8 *)((char *)(var_s0) + 0x1FF)) = 0;
        (*(s8 *)((char *)(var_s0) + 0x1FD)) = 0;
        (*(s8 *)((char *)(var_s0) + 0x1FE)) = 0;
        (*(f32 *)((char *)(var_s0) + 0x200)) = (f32) (func_800645A4(var_s1) & 0xFF);
        var_s0 += 8;
        var_s1 += 1;
    }
if (0x21U > var_s1) goto __repair_rows;
    (*(s8 *)((char *)(temp_s2) + 0x1FC)) = 1;
    (*(s8 *)((char *)(temp_s2) + 0x32C)) = 0;
    (*(s8 *)((char *)(temp_s2) + 0x324)) = 0;
    temp_v0 = (*(void **)((char *)(arg0) + 0x68));
    (*(s8 *)((char *)(temp_v0) + 0xE)) = 0;
    (*(s8 *)((char *)(temp_v0) + 0x10)) = 0;
    (*(s8 *)((char *)(temp_v0) + 0xF)) = 0;
    func_80070870(arg0);
    (*(s16 *)((char *)((*(void **)((char *)(temp_s2) + 0xA8))) + 0x7A)) = 0;
    updateSwayMotion(arg0);
    func_80002EF0((*(void **)((char *)(temp_s2) + 0xA8)));
}
