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

s32 objectSetAnimFrame();
s32 randomU32Next();
extern f64 D_800D4258;
extern u8 gTrackDoneFlags[];

void func_80061EC0(void *arg0) {
    f64 var_ft0;
    s16 temp_v1;
    s32 temp_v0;
    u32 temp_a2;
    u32 temp_a2_2;
    void *temp_s1;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (*(gTrackDoneFlags + M2C_FIELD(temp_s1, u8 *, 4)) == M2C_FIELD(temp_s1, u8 *, 5)) {
            *(gTrackDoneFlags + M2C_FIELD(temp_s1, u8 *, 6)) = 1;
            temp_a2 = M2C_FIELD(temp_s1, u32 *, 0);
            objectSetAnimFrame(arg0, ((temp_a2 >> 4) & 0xFFFF) + 1, temp_a2 >> 0x14);
            M2C_FIELD(arg0, s16 *, 0x7A) = 1;
            M2C_FIELD(arg0, u16 *, 0x7C) = 0U;
            return;
        }
        return;
    case 1:
        M2C_FIELD(arg0, u16 *, 0x7C) += 1;
        temp_v0 = randomU32Next() & 0xFF;
        var_ft0 = (f64) temp_v0;
        if (temp_v0 < 0) {
            var_ft0 += D_800D4258;
        }
        M2C_FIELD(arg0, f32 *, 0x54) = (f32) ((((f32) var_ft0 - 128.0f) * 0.00015625f) + 1.0f);
        M2C_FIELD(arg0, u8 *, 0x82) = (u8) ((u32) (M2C_FIELD(arg0, u8 *, 0x82) + (randomU32Next() & 0xFF)) >> 1);
        if ((s16) M2C_FIELD(arg0, u16 *, 0x7C) >= 0xA8D) {
            temp_a2_2 = M2C_FIELD(temp_s1, u32 *, 0);
            objectSetAnimFrame(arg0, (temp_a2_2 >> 4) & 0xFFFF, temp_a2_2 >> 0x14);
            *(gTrackDoneFlags + M2C_FIELD(temp_s1, u8 *, 6)) = 0;
            M2C_FIELD(arg0, s16 *, 0x7A) = 2;
        }
        break;
    case 2:
        break;
    }
}
