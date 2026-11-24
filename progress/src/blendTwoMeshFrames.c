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

s32 loadMeshFrame();
s32 lerpAnimPose(s32, void *, void *, f32);

/* Loads two mesh frames and writes their interpolated pose, weighted by blend, to outPose. */ void blendTwoMeshFrames(s32 outPose, s32 mesh, s32 frameA, s32 frameB, f32 blend, s32 flags) {
    u8 sp10[0x628];
    u8 sp638[0x628];

    loadMeshFrame(sp10, mesh, frameA, flags);
    __repair_rows: { loadMeshFrame(sp638, mesh, frameB, flags); }
if (0) goto __repair_rows;
    lerpAnimPose(outPose, sp10, sp638, blend);
}
