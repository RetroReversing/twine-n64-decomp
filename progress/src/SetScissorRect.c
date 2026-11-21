#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
extern void *sDisplayListCursor;
void SetScissorRect(s32 arg0,s32 arg1,s32 arg2,s32 arg3){s32 x0,y0,x1,y1;void *p;arg0&=0xFFFF;arg1&=0xFFFF;p=sDisplayListCursor;x0=((s32)((f32)arg0*4.0f)&0xFFF)<<12;y0=((s32)((f32)arg1*4.0f)&0xFFF)|0xED000000;x1=((s32)((f32)(arg0+ (arg2 & 0xFFFF))*4.0f)&0xFFF)<<12;y1=(s32)((f32)(arg1+ (arg3 & 0xFFFF))*4.0f)&0xFFF;sDisplayListCursor=p+8;M2C_FIELD(p,s32 *,0)=x0|y0;M2C_FIELD(p,s32 *,4)=x1|y1;}
