extern void romDmaRead(void *, void *, s32);
extern s32 D_00437E38;
extern s16 D_800D9428;
extern s16 D_800D942A;
extern s16 D_800D942C[6];
extern u8 D_800D9438[192];
extern u8 D_F8D70;

void *func_8000182C(s32 arg0) {

    s16 *var_v1;
    s16 *table_base = D_800D942C;
    u8 *cache_base = D_800D9438;
    s32 temp_a1;
    s32 var_s1;
    
    register void *temp_s0;

    var_s1 = D_800D942A;
    temp_a1 = var_s1;
    var_v1 = table_base + var_s1;
do {
    if (*var_v1 == arg0) {
        D_800D942A = var_s1;
        return (void *)((var_s1 << 5) + (u32)cache_base);
    }
    var_s1 -= 1;
    var_v1 -= 1;
    if (var_s1 < 0) {
        var_v1 = table_base + 5;
        var_s1 = 5;
    }
    } while (var_s1 != temp_a1);
    {
            void *src;
            var_s1 = D_800D9428;
            var_s1 -= 1;
            if (var_s1 < 0) {
                var_s1 = 5;
            }
            temp_s0 = D_800D9438 + (var_s1 << 5);
            src = (void *)((arg0 << 5) + ((u32)&D_F8D70 + (u32)&D_00437E38));
            D_800D9428 = var_s1;
            romDmaRead(temp_s0, src, 0x20);
            D_800D942C[var_s1] = arg0;
            D_800D942A = var_s1;
            return temp_s0;
    }
}
