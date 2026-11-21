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

s32 func_8004478C();
f32 Vec3_DistanceSq();
s32 randomIntBelow();
s32 func_800462C4(void *, f32, f32, f32);
void *spawnConfiguredEffect(s32, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);
f32 sinAngle(f32);
f32 cosAngle(f32);
s32 rotateVec3ByMat3();
extern char sEnemyDefTable[];
extern u8 gPauseFlag;
extern s32 gBorderSkipActive;
extern char gTrackMarkers[];

typedef struct { f32 x, y, z; } Vec3;
/* Per-frame update of an actor's aim/target state: computes its aim direction from the axis table, places the aim point, and spawns or updates the aim effect. */ void UpdateActorTargetEffect(void *actor, void *target_pos) {
s32 __repair_operand;

    f32 rot_mtx[3][3];
    f32 pad_unused[2];
    f32 angles[3];
    f32 aim_pos[3];
    f32 aim_delta[3];
    f32 cos_pitch;
    f32 sin_yaw;
    f32 m02;
    f32 cos_yaw;
    f32 cos_pitch_b;
    f32 dist;
    f32 dy;
    f32 dx;
    f32 dz;
    s32 axis_idx;
    void **axis_entry;
    void *actor_data;
    void *actor_data_b;
    void *actor_def;
    void *vtx_ptr;
    void *effect;

    actor_data = M2C_FIELD(actor, void **, 0x6C);
    axis_idx = M2C_FIELD(actor_data, s8 *, 0x182);
    actor_def = (M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xE) * 0xE8) + sEnemyDefTable;
    if ((gBorderSkipActive == 0) || (gPauseFlag != 0)) {
        if (M2C_FIELD(actor_def, u8 *, 0x9E) != 0xFF) {
            M2C_FIELD(M2C_FIELD(M2C_FIELD(actor_data, void **, 0xA8), void **, 0x68), s32 *, 0x78) = func_8004478C(M2C_FIELD(actor_def, s16 *, 0x48), M2C_FIELD(actor_def, s16 *, 0x40));
        }
        M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s32 *, 0x74) = func_8004478C(M2C_FIELD(actor_def, s16 *, 0x4A), M2C_FIELD(actor_def, s16 *, 0x40));
        if (((M2C_FIELD(actor_def, s32 *, 0x60) & 0xC00) != 0) & (target_pos != NULL)) {
            axis_entry = (axis_idx * 4) + gTrackMarkers;
            actor_data_b = M2C_FIELD(actor_data, void **, 0xA8);
            angles[0] = -(M2C_FIELD(*axis_entry, f32 *, 0x34) * 651.8986f);
            angles[1] = M2C_FIELD(*axis_entry, f32 *, 0x38) * 651.8986f;
            rot_mtx[0][0] = cosAngle(angles[1]);
            cos_pitch = sinAngle(angles[0]);
            rot_mtx[0][1] = -cos_pitch * sinAngle(angles[1]);
            sin_yaw = sinAngle(angles[1]);
            m02 = sin_yaw * cosAngle(angles[0]);
            rot_mtx[1][0] = 0.0f;
            rot_mtx[0][2] = m02;
            rot_mtx[1][1] = cosAngle(angles[0]);
            rot_mtx[1][2] = sinAngle(angles[0]);
            rot_mtx[2][0] = -sinAngle(angles[1]);
            cos_yaw = cosAngle(angles[1]);
            rot_mtx[2][1] = -(cos_yaw * sinAngle(angles[0]));
            cos_pitch_b = cosAngle(angles[0]);
            rot_mtx[2][2] = cos_pitch_b * cosAngle(angles[1]);
            __repair_operand = M2C_FIELD(M2C_FIELD(actor_data_b, void **, 0x68), s32 *, 4);
            vtx_ptr = (M2C_FIELD(actor_def, u16 *, 0x90) * 0xC) + __repair_operand;
            *(Vec3 *) aim_pos = *(Vec3 *) vtx_ptr;
            aim_pos[1] = -aim_pos[1];
            aim_pos[0] = -aim_pos[0];
            rotateVec3ByMat3(rot_mtx, aim_pos);
            aim_pos[0] += M2C_FIELD(*axis_entry, f32 *, 0x10);
            aim_pos[1] += M2C_FIELD(*axis_entry, f32 *, 0x14);
            aim_pos[2] += M2C_FIELD(*axis_entry, f32 *, 0x18);
            effect = NULL;
            dist = Vec3_DistanceSq(aim_pos, target_pos);
            if (M2C_FIELD(actor_def, s32 *, 0x60) & 0x800) {
                effect = spawnConfiguredEffect(M2C_FIELD(actor, s32 *, 0x20), aim_pos, 0, 0, 1.0f, 1.0f, 0x16, 0x1B, 0x22, 0x8020, 0x80808021);
                M2C_FIELD(effect, s32 *, 0x58) |= 0x100000;
            }
            if (M2C_FIELD(actor_def, s32 *, 0x60) & 0x400) {
                effect = spawnConfiguredEffect(M2C_FIELD(actor, s32 *, 0x20), aim_pos, 0, 0, 1.0f, 1.0f, randomIntBelow(4) + 0x17, 0x1B, 0x22, 0x8080, 0x80808081);
                M2C_FIELD(effect, s32 *, 0x58) |= 0x100000;
            }
            if (effect != NULL) {
                M2C_FIELD(effect, f32 *, 0x54) = dist;
                M2C_FIELD(effect, s32 *, 0x58) |= 0x8000;
                dx = aim_pos[0] - M2C_FIELD(target_pos, f32 *, 0);
                aim_delta[0] = dx;
                dy = aim_pos[1] - M2C_FIELD(target_pos, f32 *, 4);
                aim_delta[1] = dy;
                dz = aim_pos[2] - M2C_FIELD(target_pos, f32 *, 8);
                aim_delta[2] = dz;
                func_800462C4(effect + 0x3C, dx, dy, dz);
                M2C_FIELD(effect, s32 *, 0x44) = 0;
                M2C_FIELD(effect, f32 *, 0x3C) = (f32) -M2C_FIELD(effect, f32 *, 0x3C);
            }
        }
    }
}
