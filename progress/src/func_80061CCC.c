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

s32 func_80017EC0(void *, f32, f32);
s32 objectSetAnimFrame();
s32 randomIntBelow();
s32 func_80061BE4();
extern u8 gTrackMarkerDone[];

void func_80061CCC(void *arg0) {
    f32 var_fv0;
    u8 temp_v0;
    u8 temp_v0_2;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v0 = M2C_FIELD(temp_s0, u8 *, 4);
    if ((temp_v0 != 0) && (*(gTrackMarkerDone + temp_v0) != M2C_FIELD(temp_s0, u8 *, 5))) {
        goto mismatch;
    }
block_4:
    var_fv0 = 10.0f;
    if (M2C_FIELD(temp_s0, s8 *, 8) != 0) {
        var_fv0 = 200.0f;
    }
    func_80017EC0(arg0, 2.0f, var_fv0);
    temp_v0_2 = M2C_FIELD(temp_s0, u8 *, 6) + 1;
    M2C_FIELD(temp_s0, u8 *, 6) = temp_v0_2;
    if ((u8) M2C_FIELD(temp_s0, u8 *, 7) < (u32) (temp_v0_2 & 0xFF)) {
        M2C_FIELD(temp_s0, u8 *, 6) = 0U;
    }
    objectSetAnimFrame(arg0, M2C_FIELD(temp_s0, u8 *, 6), (u32) M2C_FIELD(temp_s0, u32 *, 0) >> 0x14);
    M2C_FIELD(arg0, s8 *, 0x7E) = 5;
    if ((M2C_FIELD(arg0, s32 *, 0x60) & 0x7000) && (M2C_FIELD(temp_s0, s8 *, 8) != 0) && (randomIntBelow(0x1E) == 0)) {
        func_80061BE4(arg0);
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
        return;
    }
    goto block_12;
mismatch:
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
block_12:
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
}

