#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif
f32 __cosf(f32); f32 sinApprox(f32);
/* Fills a 4x3 float matrix with a rotation about the Y axis by angle (rest zero, Y scale 1). */ void buildRotationYMatrix(void *matrix, f32 angle) {
 f32 c, sn, neg, z;
 c=__cosf(angle); sn=sinApprox(angle); neg=-sn; z=0.0f;
 M2C_FIELD(matrix,f32*,0x28)=c; M2C_FIELD(matrix,f32*,0)=c; M2C_FIELD(matrix,f32*,0x20)=sn; M2C_FIELD(matrix,f32*,8)=neg;
 M2C_FIELD(matrix,f32*,0x2C)=z; M2C_FIELD(matrix,f32*,0x24)=z; M2C_FIELD(matrix,f32*,0x1C)=z; M2C_FIELD(matrix,f32*,0x18)=z; M2C_FIELD(matrix,f32*,0x10)=z; M2C_FIELD(matrix,f32*,0xC)=z; M2C_FIELD(matrix,f32*,4)=z;
 M2C_FIELD(matrix,f32*,0x14)=1.0f;
}
