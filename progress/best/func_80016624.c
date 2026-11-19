/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800165E0();

void func_80016624(void *arg0, s32 *arg1, s32 arg2) {
    s32 *temp_v0_2;
    s32 *temp_v0;
    
    s32 *var_v1;

    temp_v0 = (*(s32 **)((char *)(arg1) + 4));
    var_v1 = temp_v0;
    if (temp_v0 != NULL) {
loop_1:
        if (temp_v0 != arg0) {
            temp_v0 = (*(s32 **)((char *)(temp_v0) + 4));
            var_v1 = temp_v0;
            if (temp_v0 != NULL) {
                goto loop_1;
            }
        } else if (var_v1 != arg0) {
            (*(s32 **)((char *)(var_v1) + 4)) = (s32 *) (*(s32 **)((char *)(arg0) + 4));
            temp_v0 = (*(s32 **)((char *)(arg0) + 4));
            if (temp_v0 != NULL) {
                *temp_v0 = var_v1;
            }
        } else {
            (*(s32 **)((char *)(arg1) + 4)) = (s32 *) (*(s32 **)((char *)(arg0) + 4));
            temp_v0_2 = (*(s32 **)((char *)(arg0) + 4));
            if (temp_v0_2 != NULL) {
                *temp_v0_2 = arg1;
            }
        }
    }
    func_800165E0(arg0, arg2);
}
