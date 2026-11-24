#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
void addRandomJitterVec3(f32 *, f32, f32);
M2C_UNK spawnConfiguredEffect(s32, f32 *, void *, f32 *, f32, f32, s32, s32, s32, s32, s32);
typedef struct { u32 x,y,z; } VBits;
/* Spawns a burst effect at a track marker's position with a small random jitter on position and velocity. */ void spawnTrackMarkerBurst(void *marker) {
    VBits position; f32 velocity[3]; register f32 zero;
    position = *(VBits *)((s8 *)marker + 0x24);
    addRandomJitterVec3((f32 *)&position, 1.0f, 0.5f);
    zero = 0.0f;
    velocity[2] = zero; velocity[1] = zero; velocity[0] = zero;
    addRandomJitterVec3(velocity, 0.02f, 0.01f);
    spawnConfiguredEffect(M2C_FIELD(marker,s32 *,0x20), (f32 *)&position, (s8 *)marker+0x3C, velocity, 0.1f, 1.034f, 0x1B,0xFB,0x54,0xFF,0x80808002);
}
