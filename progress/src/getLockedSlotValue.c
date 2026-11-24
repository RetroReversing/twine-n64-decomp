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
extern char gLockedSlotTable[];
/* Returns the s16 entry of gLockedSlotTable for the slot index (low 4 bits). */ s16 getLockedSlotValue(s32 slot) { return *(s16 *)(gLockedSlotTable + ((slot & 0xF) * 2)); }
