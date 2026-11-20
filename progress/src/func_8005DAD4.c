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

s32 func_80044670();
s32 func_80084338();
extern char gTrackDoneFlags[];

void func_8005DAD4(void *arg0) {
    s16 temp_v1_2;
    u16 temp_a0;
    u16 temp_v0;
    u16 temp_v1_3;
    u16 temp_v1_4;
    u8 temp_v1;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    if (M2C_FIELD(temp_s0, u16 *, 0x3A) == 1) {
        temp_v1 = *(gTrackDoneFlags + M2C_FIELD(temp_s0, u16 *, 0x34));
        if (temp_v1 < 2U) {
            func_80044670(arg0, M2C_FIELD(temp_s0, u16 *, 0x3C) + temp_v1, M2C_FIELD(temp_s0, u16 *, 0x3E));
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x60) & 0x100000) {
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
    }
    temp_v1_2 = M2C_FIELD(arg0, s16 *, 0x7A);
    switch (temp_v1_2) {                            /* irregular */
    case 0:
        if (M2C_FIELD(arg0, s32 *, 0x60) & M2C_FIELD(temp_s0, s32 *, 0x2C)) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 1;
            temp_v1_3 = M2C_FIELD(temp_s0, u16 *, 0x34);
            if (temp_v1_3 != 0) {
                *(gTrackDoneFlags + temp_v1_3) = 2;
            }
        }
        break;
    case 1:
        temp_v1_4 = M2C_FIELD(temp_s0, u16 *, 0x34);
        if (temp_v1_4 != 0) {
            *(gTrackDoneFlags + temp_v1_4) = 1;
        }
        temp_a0 = M2C_FIELD(temp_s0, u16 *, 0x36);
        if (temp_a0 != 0) {
            func_80084338(temp_a0, arg0 + 0x24);
        }
        M2C_FIELD(arg0, s16 *, 0x7A) = 2;
        break;
    case 2:
        temp_v0 = M2C_FIELD(temp_s0, u16 *, 0x34);
        if (temp_v0 != 0) {
            *(gTrackDoneFlags + temp_v0) = 0;
        }
        if (!(M2C_FIELD(arg0, s32 *, 0x60) & M2C_FIELD(temp_s0, s32 *, 0x2C))) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 0;
        }
        break;
    }
    M2C_FIELD(arg0, s32 *, 0x60) &= 1;
}
