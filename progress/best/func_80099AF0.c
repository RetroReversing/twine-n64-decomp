extern char D_801007D9[];
extern u8 D_80100C7C[];
s32 func_80099AF0(void *arg0) {
    char *base;
    s32 temp_v1;
    u8 temp_a1;
    u8 temp_v0;
    s32 var_v0;
    register u8 var_v1;
    temp_v1 = *(s32 *)((char *)arg0 + 0x60);
    if (temp_v1 != -1) {
        temp_a1 = *(u8 *)((char *)arg0 + 0x4A);
        if (temp_a1 != 0xFF) {
            temp_v0 = *(u8 *)((char *)arg0 + 0x4B);
            if (temp_v0 == 0xFF) {
                var_v1 = temp_v1 & 0xFF;
                var_v0 = D_80100C7C[var_v1];
            } else {
                base = D_801007D9;
                var_v0 = temp_v1 & 0xFF;
                var_v1 = *((base + temp_v1 * 0x10) + temp_a1);
            }
            if (var_v1 == var_v0) return 1;
            goto done;
        }
        return 0;
    }
done:
    return 0;
}
