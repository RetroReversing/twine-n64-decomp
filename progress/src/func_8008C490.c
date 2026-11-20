/* adapted from similar verified C in func_8008C644 in TWINE (matched), with its names changed by decompdecomp */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif
extern s32 D_800E41DC;
void func_8008C490(s32 arg0) {
    M2C_FIELD(((arg0 * 0x68) + D_800E41DC), s8 *, 1) = 0;
}
