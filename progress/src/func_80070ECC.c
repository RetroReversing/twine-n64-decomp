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
s16 strlen(s8 *, M2C_UNK, s32, s32);
typedef struct { unsigned char pad_0[16]; int field_10; unsigned char pad_14[8]; short field_1C; unsigned short field_1E; short field_20; short field_22; unsigned char pad_24[4]; int field_28; } __repair_record_arg0;
void func_80070ECC(void *arg0, s8 *arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5) {
    __repair_record_arg0 *obj = (__repair_record_arg0 *)arg0;
    s32 flags = obj->field_28;
    obj->field_20 = arg2;
    obj->field_22 = arg3;
    flags &= -0xFD;
    flags |= 0x10;
    obj->field_28 = flags;
    obj->field_10 = arg5;
    obj->field_1E = (u16)(obj->field_1E | arg4);
    *arg1 = 0;
    M2C_FIELD(arg0, s8 **, 0x18) = arg1;
    obj->field_1C = strlen(arg1, -0xFD, arg5, arg4);
}
