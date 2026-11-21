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

M2C_UNK buildRotationMatrixCopy(s16 *, s32);                  /* extern */
M2C_UNK buildRotationMatrixS16Copy(s16 *);                       /* extern */

/* Converts the object's float rotation (fields 0x30-0x38) to s16 angles; arg1 applies it directly and arg2 applies the negated angles with the given count */
void applyObjectRotation(void *object, s32 applyPositive, s32 applyNegative) {
    s16 angles[3];

    if (applyPositive != 0) {
        angles[0] = (s16) (s32) (M2C_FIELD(object, f32 *, 0x30) * 651.8986f);
        angles[1] = (s16) (s32) (M2C_FIELD(object, f32 *, 0x34) * 651.8986f);
        angles[2] = (s16) (s32) (M2C_FIELD(object, f32 *, 0x38) * 651.8986f);
        buildRotationMatrixS16Copy(angles);
    }
    if (applyNegative != 0) {
        angles[0] = (s16) (s32) -(M2C_FIELD(object, f32 *, 0x30) * 651.8986f);
        angles[1] = (s16) (s32) -(M2C_FIELD(object, f32 *, 0x34) * 651.8986f);
        angles[2] = (s16) (s32) -(M2C_FIELD(object, f32 *, 0x38) * 651.8986f);
        buildRotationMatrixCopy(angles, applyNegative);
    }
}
