#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
extern M2C_UNK D_80107EDC; extern M2C_UNK D_80107EE0; extern M2C_UNK D_80107EE8;
u32 func_8008EF18(s32 arg0) {
 s32 index=arg0&0xff; s32 scaled=(index*5)<<3; u32 result;
    u32 __repair_result_2;
 result=*((u8*)((s8*)&D_80107EE8+scaled));
 if(result==4) goto __shared_return_0;
 result=*((u32*)((s8*)&D_80107EE0+scaled));
 if(result==0) __shared_return_0:
    return 0;
 __repair_result_2=*((u32*)((s8*)&D_80107EDC+scaled));
 return __repair_result_2>>31;
}
