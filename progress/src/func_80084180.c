void func_80084180(s32 *arg0, s32 *arg1, s32 arg2) {
    char *var_a0;
    char *var_a1;
    s32 temp_v0;
    s32 var_a2;
    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    if (var_a2 != 0) {
        do {
            temp_v0 = *(s32 *)var_a1;
            var_a1 += 4;
            var_a2 -= 4;
            *(s32 *)var_a0 = temp_v0;
            var_a0 += 4;
        } while (var_a2 != 0);
    }
}
