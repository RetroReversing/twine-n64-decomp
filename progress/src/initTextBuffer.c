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
/* Attaches an empty string buffer to a text object, setting its position, flags and length. */ void initTextBuffer(void *textObj, s8 *buffer, s16 x, s16 y, s32 flagBits, s32 userData) {
    __repair_record_arg0 *obj = (__repair_record_arg0 *)textObj;
    s32 flags = obj->field_28;
    obj->field_20 = x;
    obj->field_22 = y;
    flags &= -0xFD;
    flags |= 0x10;
    obj->field_28 = flags;
    obj->field_10 = userData;
    obj->field_1E = (u16)(obj->field_1E | flagBits);
    *buffer = 0;
    M2C_FIELD(textObj, s8 **, 0x18) = buffer;
    obj->field_1C = strlen(buffer, -0xFD, userData, flagBits);
}
