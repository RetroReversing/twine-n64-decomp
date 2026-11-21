#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
M2C_UNK func_8000CBE0(void *, void *);
extern void *gObjectRecords;
extern s8 gTransitionPhase;
extern void *D_80109CB4;
extern void *sBonusObjectTable;
void func_8000DB28(void) {
 if ((M2C_FIELD(gObjectRecords,s16 *,0x10)==7) && D_80109CB4 != 0 &&
 (M2C_FIELD(M2C_FIELD(D_80109CB4,void **,0x6C),u8 *,0x4A)==0x13) &&
 (M2C_FIELD(D_80109CB4,f32 *,0x2C)>M2C_FIELD(M2C_FIELD(gObjectRecords,void **,0x3B8),f32 *,0x2C))) {
 M2C_FIELD(sBonusObjectTable,f32 *,0x74)=-1.0f;
 func_8000CBE0(D_80109CB4,gObjectRecords);
 gTransitionPhase=2;
 }
}
