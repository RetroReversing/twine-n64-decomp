#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
s16 func_800828D8(s16); extern f32 D_800C4728;
void func_800016F4(void *arg0) {
    s32 temp_fv1; s16 temp_v0; void *temp_s0;
    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    temp_fv1 = (s32) (*(f32 *)((s8 *)&D_800C4728 + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8)) * 2133.3335f);
    M2C_FIELD(temp_s0, s16 *, 0x17C) = (s16) temp_fv1;
    temp_v0 = func_800828D8((s16) temp_fv1);
    M2C_FIELD(temp_s0, s16 *, 0x17C) = temp_v0;
    if (temp_v0 >= 0x101) M2C_FIELD(temp_s0, s16 *, 0x17C) = 0x100;
}
