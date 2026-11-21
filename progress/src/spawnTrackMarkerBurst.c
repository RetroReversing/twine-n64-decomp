#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
void func_80045DB4(f32 *, f32, f32);
M2C_UNK spawnConfiguredEffect(s32, f32 *, void *, f32 *, f32, f32, s32, s32, s32, s32, s32);
typedef struct { u32 x,y,z; } VBits;
void spawnTrackMarkerBurst(void *arg0) {
    VBits sp30; f32 sp40[3]; register f32 zero;
    sp30 = *(VBits *)((s8 *)arg0 + 0x24);
    func_80045DB4((f32 *)&sp30, 1.0f, 0.5f);
    zero = 0.0f;
    sp40[2] = zero; sp40[1] = zero; sp40[0] = zero;
    func_80045DB4(sp40, 0.02f, 0.01f);
    spawnConfiguredEffect(M2C_FIELD(arg0,s32 *,0x20), (f32 *)&sp30, (s8 *)arg0+0x3C, sp40, 0.1f, 1.034f, 0x1B,0xFB,0x54,0xFF,0x80808002);
}
