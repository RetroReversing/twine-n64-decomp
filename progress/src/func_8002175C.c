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

s32 func_80016718();
extern u16 gMenuMode;
extern void *D_800B7CE8;
extern void *gMenuState;

void func_8002175C(void) {
    s32 temp_v0;
    void *temp_v1;

    if (D_800B7CE8 != NULL) {
        if (M2C_FIELD(gMenuState, u8 *, 0x30) != 0xFF) {
            func_80016718(D_800B7CE8);
            temp_v1 = D_800B7CE8;
            temp_v0 = M2C_FIELD(temp_v1, s32 *, 0x60);
            D_800B7CE8 = NULL;
            M2C_FIELD(temp_v1, s32 *, 0x60) = (s32) (temp_v0 | 1);
            return;
        }
        M2C_FIELD(D_800B7CE8, u8 *, 0x82) = 0xFF;
        if (gMenuMode == 1) {
            M2C_FIELD(D_800B7CE8, f32 *, 0x40) += 34.133335f;
        }
    }
}
