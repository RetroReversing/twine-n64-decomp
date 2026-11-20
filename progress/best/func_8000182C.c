extern void func_8000B900(void *, void *, s32);
extern s32 D_00437E38;
extern s16 D_800D9428;
extern s16 D_800D942A;
extern s16 D_800D942C[6];
extern u8 D_800D9438[192];
extern u8 D_F8D70;

void *func_8000182C(s32 arg0) {
int __repair_constant = 5;

    s16 *var_v1;
    s16 *table_base = D_800D942C;
    u8 *cache_base = D_800D9438;
    s32 temp_a1;
    s32 var_s1;
    
    register void *temp_s0;

    var_s1 = D_800D942A;
    temp_a1 = var_s1;
    var_v1 = table_base + var_s1;
loop_1:
    if (*var_v1 != arg0) {
        var_s1 -= 1;
        var_v1 -= 1;
        if (0 > var_s1) {
            var_s1 = 5;
            var_v1 = &D_800D942C[5];
        }
        if (var_s1 == temp_a1) {
            var_s1 = D_800D9428 - 1;
            if (var_s1 < 0) {
                var_s1 = 5;
            }
            D_800D9428 = var_s1;
            temp_s0 = cache_base + (var_s1 << 5);
            func_8000B900(temp_s0, &D_F8D70 + (u32)&D_00437E38 + (arg0 << 5), 0x20);
            D_800D942C[var_s1] = arg0;
            D_800D942A = var_s1;
            return temp_s0;
        }
        goto loop_1;
    }
    D_800D942A = var_s1;
    return cache_base + (var_s1 << 5);
}
