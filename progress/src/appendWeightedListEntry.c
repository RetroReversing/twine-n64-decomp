/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

/* Appends a 12-byte entry (value, flag, weight) to a bounded list, accumulates its running offset, and recomputes the list's normalized rate (capped at 1.0). Returns the next entry slot, or NULL if full. */ void *appendWeightedListEntry(void *list, s32 value, s8 flag, s8 weight) {
    f32 rate;
    s16 totalWeight;
    s32 byteOffset;
    u8 i;
    s32 var_v1;
    u8 index;
    u8 temp_v0;
    u8 temp_v1;
    void *temp_a2;
    void *var_a1_2;

    if (list != NULL) {
        temp_v1 = M2C_FIELD(list, u8 *, 0x19);
        index = temp_v1;
        if (index < (u8) M2C_FIELD(list, u8 *, 0x1A)) {
            void *base = M2C_FIELD(list, void **, 0);
            M2C_FIELD(list, u8 *, 0x19) = (u8) (temp_v1 + 1);
            byteOffset = ((index << 1) + index) << 2;
            *(s32 *)(byteOffset + (u32)base) = value;
            M2C_FIELD((byteOffset + M2C_FIELD(list, u32 *, 0)), s8 *, 8) = flag;
            M2C_FIELD((byteOffset + M2C_FIELD(list, u32 *, 0)), u16 *, 4) = (u16) M2C_FIELD(list, u16 *, 0x16);
            {
                u32 entries = M2C_FIELD(list, u32 *, 0);
                temp_a2 = (void *)(byteOffset + entries);
                var_a1_2 = (void *)entries;
            }
            if (index != 0) {
                var_a1_2 = (s8 *)var_a1_2 + (index - 1) * 0xC;
            }
            M2C_FIELD(temp_a2, s16 *, 6) = (s16) (M2C_FIELD(var_a1_2, u16 *, 6) + M2C_FIELD(list, u8 *, 0x21));
            M2C_FIELD((byteOffset + M2C_FIELD(list, u32 *, 0)), s8 *, 9) = weight;
            temp_v0 = M2C_FIELD(list, u8 *, 0x19);
            i = 0;
            totalWeight = 0;
            if (temp_v0 != 0) {
                do {
                    totalWeight += M2C_FIELD((i * 0xC + M2C_FIELD(list, u32 *, 0)), u8 *, 9);
                    i++;
                } while (i < temp_v0);
            }
            rate = (1.0f / (f32) totalWeight) * (f32) M2C_FIELD(list, u8 *, 0x1B);
            M2C_FIELD(list, f32 *, 0xC) = rate;
            if (rate > 1.0f) {
                M2C_FIELD(list, f32 *, 0xC) = 1.0f;
            }
            return (void *)(M2C_FIELD(list, u32 *, 0) + ((i & 0xFF) * 0xC));
        }
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return NULL;
    }
    return NULL;
}

