#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
typedef struct { s32 x, y, z; } __V3;
void *func_800166A0();
void func_800169EC(void *, void *);
M2C_UNK func_80044710(void *, M2C_UNK, M2C_UNK);
f32 approximate_hypot2(f32, f32);
f32 func_80082A70(f32, f32);
M2C_UNK func_80085160(s32);
void func_800556DC(void *arg0, s32 *arg1, const f32 *arg2, s32 arg3) {
    volatile f32 sp10;
    volatile f32 sp14;
    volatile f32 sp18;
    void *temp_v0;
    temp_v0 = func_800166A0();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x1C) = arg3;
        *(__V3 *)((s8 *)temp_v0 + 0x20) = *(__V3 *)arg1;
        func_80044710(temp_v0, 4, 0x1B);
        sp10 = M2C_FIELD(arg2, const f32 *, 0);
        sp14 = M2C_FIELD(arg2, const f32 *, 4);
        sp18 = M2C_FIELD(arg2, const f32 *, 8);
        M2C_FIELD(temp_v0, f32 *, 0x2C) = (f32) -(func_80082A70(sp14, approximate_hypot2(arg2[0], arg2[2])) * 651.8986f);
        M2C_FIELD(temp_v0, f32 *, 0x30) = func_80082A70(sp10, sp18) * 651.8986f;
        M2C_FIELD(temp_v0, s32 *, 0x34) = 0;
        func_800169EC(temp_v0, arg0);
        func_80085160(arg1);
    }
}
