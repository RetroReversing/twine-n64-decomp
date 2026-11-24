#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif
/* Comparator: difference of the u16 keys at offset 4 of two scene groups. */ s32 compareSceneGroupKey(void *a, void *b) {
    return M2C_FIELD(a, u16 *, 4) - M2C_FIELD(b, u16 *, 4);
}
