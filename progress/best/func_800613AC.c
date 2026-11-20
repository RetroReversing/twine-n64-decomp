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
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
void *func_80016410();
void func_80016990();
extern u8 D_800B2022;
extern u8 D_800B2272;
typedef struct { s32 w[3]; } __repair_words3;
void func_800613AC(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    void *temp_a2;
    void *temp_v0;
    temp_v0 = func_80016410(arg0, 0x48, 0);
    if (temp_v0 != NULL) {
        temp_a2 = M2C_FIELD(temp_v0, void **, 0x6C);
        M2C_FIELD(temp_a2, s32 *, 0x18) = 0;
        M2C_FIELD(temp_a2, s32 *, 0x1C) = (s32) ((((M2C_FIELD(temp_a2, s32 *, 0x1C) & 0xFFF0000F) | 0x190) & 0x19F) | 0x0FB00000);
        M2C_FIELD(temp_v0, s16 *, 0x78) = arg3;
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
        if (arg2 != NULL) M2C_FIELD(temp_a2, __repair_words3 *, 0) = *(__repair_words3 *)((s8 *)arg2);
        M2C_FIELD(temp_a2, s32 *, 0xC) = 0x12C;
        M2C_FIELD(temp_a2, s16 *, 0x40) = 0x42;
        M2C_FIELD(temp_a2, u8 *, 0x45) = 0xFF;
        M2C_FIELD(temp_a2, s8 *, 0x44) = 0;
        M2C_FIELD(temp_a2, s8 *, 0x42) = 0;
        M2C_FIELD(temp_a2, s8 *, 0x43) = 0;
        M2C_FIELD(temp_a2, s8 *, 0x46) = 1;
        M2C_FIELD(temp_a2, f32 *, 0x38) = (f32) D_800B2022;
        arg1 = D_800B2272;
        M2C_FIELD(temp_a2, s32 *, 0x2C) = -1;
        M2C_FIELD(temp_a2, f32 *, 0x30) = 1000.0f;
        M2C_FIELD(temp_a2, f32 *, 0x34) = 1000.0f;
        M2C_FIELD(temp_a2, f32 *, 0x3C) = (f32) arg1;
        func_80016990(temp_v0, (void *) M2C_FIELD(arg0, void **, 0x20));
    }
}
