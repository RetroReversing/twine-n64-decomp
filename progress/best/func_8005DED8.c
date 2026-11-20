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

s32 markObjectsNearPos(s32, s32, s32, s32, f32, s32);
s32 func_80044670();
f32 approxDistance();
s32 func_80059658();
s32 func_80084338();
extern u8 D_80102EE8;
extern u8 gTrackDoneFlags[];
extern s32 D_8010A500;

void func_8005DED8(void *arg0) {
short __repair_constant = 0xFF;

    s16 temp_v1_2;
    short var_v0;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v1_3;
    u16 temp_v1_4;
    u16 temp_v1_5;
    u8 temp_v1;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    if (M2C_FIELD(temp_s1, u16 *, 0x3A) == 1) {
        temp_v1 = *(gTrackDoneFlags + M2C_FIELD(temp_s1, u16 *, 0x34));
        if (temp_v1 < 2U) {
            func_80044670(arg0, M2C_FIELD(temp_s1, u16 *, 0x3C) + temp_v1, M2C_FIELD(temp_s1, u16 *, 0x3E));
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x60) & 0x100000) {
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
    }
    if ((D_80102EE8 == 0) && (D_8010A500 != 0) && (M2C_FIELD(temp_s1, s32 *, 0x4C) & 0x80) && (M2C_FIELD(arg0, s32 *, 0x58) & 4) && (approxDistance(arg0, arg0 + 0x24, D_8010A500 + 0x24) < 4.0f)) {
        var_v0 = 0xFF;
        if (M2C_FIELD(temp_s1, s32 *, 0x2C) & 0x08000802) {
            temp_v0 = M2C_FIELD(temp_s1, u16 *, 0x42) + 1;
            M2C_FIELD(temp_s1, u16 *, 0x42) = temp_v0;
            if (!(temp_v0 & 0x10)) {
                var_v0 = 0xBF;
                goto block_14;
            }
            M2C_FIELD(arg0, u8 *, 0x7F) = 0xFF;
            M2C_FIELD(arg0, u8 *, 0x80) = 0xFF;
            M2C_FIELD(arg0, u8 *, 0x81) = 0xFF;
        } else {
block_14:
            M2C_FIELD(arg0, s8 *, 0x81) = var_v0;
            M2C_FIELD(arg0, s8 *, 0x80) = var_v0;
            M2C_FIELD(arg0, s8 *, 0x7F) = var_v0;
        }
    }
    temp_v1_2 = M2C_FIELD(arg0, s16 *, 0x7A);
    switch (temp_v1_2) {
    case 0:
        if ((M2C_FIELD(arg0, s32 *, 0x60) & M2C_FIELD(temp_s1, s32 *, 0x2C)) && ((temp_v0_2 = M2C_FIELD(temp_s1, u16 *, 0x36), (temp_v0_2 == 0)) || (*(gTrackDoneFlags + temp_v0_2) == M2C_FIELD(temp_s1, u16 *, 0x38)))) {
            temp_v1_3 = M2C_FIELD(temp_s1, u16 *, 0x34);
            if (temp_v1_3 != 0) {
                *(gTrackDoneFlags + temp_v1_3) = *(gTrackDoneFlags + temp_v1_3) ^ 1;
            }
            temp_a0 = M2C_FIELD(temp_s1, u16 *, 0x40);
            if (temp_a0 != 0) {
                func_80084338(temp_a0, arg0 + 0x24);
            }
            M2C_FIELD(arg0, s16 *, 0x7A) = 1;
        }
        break;
    case 1:
        if (!(M2C_FIELD(arg0, s32 *, 0x60) & M2C_FIELD(temp_s1, s32 *, 0x2C))) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 2;
        }
        break;
    case 2:
        if (M2C_FIELD(temp_s1, s32 *, 4) != 0) {
            markObjectsNearPos(M2C_FIELD(arg0, s32 *, 0x20), 0, 0x01000000, arg0 + 0x24, M2C_FIELD(M2C_FIELD(arg0, void **, 0x70), f32 *, 0x14) + 1.0f, 0);
            if ((func_80059658(arg0, 1) << 0x18) != 0) {
                M2C_FIELD(temp_s1, f32 *, 8) = 1.0f;
                M2C_FIELD(arg0, s16 *, 0x7A) = 3;
            }
        } else {
            M2C_FIELD(arg0, s16 *, 0x7A) = 3;
        }
        break;
    case 3:
        if ((M2C_FIELD(arg0, s32 *, 0x60) & M2C_FIELD(temp_s1, s32 *, 0x2C)) && ((temp_v0_3 = M2C_FIELD(temp_s1, u16 *, 0x36), (temp_v0_3 == 0)) || (*(gTrackDoneFlags + temp_v0_3) == M2C_FIELD(temp_s1, u16 *, 0x38)))) {
            temp_v1_4 = M2C_FIELD(arg0, u16 *, 0x78);
            if ((temp_v1_4 != 0x12)) {
                if ((temp_v1_4 != 0x60)) {
                    if (M2C_FIELD(temp_s1, u16 *, 0x34) != 0) {
                        M2C_FIELD(arg0, s16 *, 0x7A) = 4;
                    }
                    temp_v1_5 = M2C_FIELD(temp_s1, u16 *, 0x34);
                    *(gTrackDoneFlags + temp_v1_5) = *(gTrackDoneFlags + temp_v1_5) ^ 1;
                    temp_a0_2 = M2C_FIELD(temp_s1, u16 *, 0x40);
                    if (temp_a0_2 != 0) {
                        func_80084338(temp_a0_2, arg0 + 0x24);
                    }
                }
            }
        }
        break;
    case 4:
        if (!(M2C_FIELD(arg0, s32 *, 0x60) & M2C_FIELD(temp_s1, s32 *, 0x2C))) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 5;
        }
        break;
    case 5:
        if (M2C_FIELD(temp_s1, s32 *, 4) != 0) {
            markObjectsNearPos(M2C_FIELD(arg0, s32 *, 0x20), 0, 0x01000000, arg0 + 0x24, M2C_FIELD(M2C_FIELD(arg0, void **, 0x70), f32 *, 0x14) + 1.0f, 0);
            if ((func_80059658(arg0, -1) << 0x18) != 0) {
                M2C_FIELD(temp_s1, f32 *, 8) = 1.0f;
                goto block_45;
            }
        } else {
block_45:
            M2C_FIELD(arg0, s16 *, 0x7A) = 0;
        }
        break;
    }
    M2C_FIELD(arg0, s32 *, 0x60) &= 1;
}
