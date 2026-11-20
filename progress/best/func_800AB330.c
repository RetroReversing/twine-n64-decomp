#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
M2C_UNK func_800AB030(f64, M2C_UNK *, f64 *); extern f64 D_800D6FE0,D_800D6FE8,D_800D6FF0,D_800D6FF8;
f64 func_800AB330(f64 arg0) { M2C_UNK sp10; f64 sp18; f64 ratio=arg0/D_800D6FE0; f64 bias; f64 r; s32 n; bias=D_800D6FE8; if(arg0>=0.0) bias=D_800D6FF0; n=(s32)(ratio+bias); do { func_800AB030(arg0-((f64)n*D_800D6FF8),&sp10,&sp18); } while (0); r=sp18; if(n&1) r=-r; return r; }
