#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
s16 absS32(s16); extern f32 D_800C4728;
/* Computes a scaled value from the actor's table entry, converts it, and stores it clamped to 0x100 in the actor state. */ void updateActorSpeedValue(void *actor) {
    s32 scaled; s16 converted; void *state;
    state = M2C_FIELD(actor, void **, 0x6C);
    scaled = (s32) (*(f32 *)((s8 *)&D_800C4728 + (M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xE) * 0xE8)) * 2133.3335f);
    M2C_FIELD(state, s16 *, 0x17C) = (s16) scaled;
    converted = absS32((s16) scaled);
    M2C_FIELD(state, s16 *, 0x17C) = converted;
    if (converted >= 0x101) M2C_FIELD(state, s16 *, 0x17C) = 0x100;
}
