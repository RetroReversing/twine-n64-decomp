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
s32 randomIntBelow();
extern char gTrackDoneFlags[];

void func_8005AE38(void *arg0) {
    s16 temp_v1;
    u32 temp_a2;
    u32 temp_a2_2;
    u32 temp_a2_3;
    u32 temp_a2_4;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v1_2;
    u8 temp_v1_3;
    void *temp_s0;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (randomIntBelow(0x78) == 0) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 2;
        }
        if (randomIntBelow(0x3C) == 0) {
            temp_v0 = M2C_FIELD(temp_s0, u8 *, 4);
            if (temp_v0 != 0) {
                *(gTrackDoneFlags + temp_v0) = 0;
            }
            temp_a2 = M2C_FIELD(temp_s0, u32 *, 0);
            func_80044670(arg0, ((temp_a2 >> 4) & 0xFFFF) + 1, temp_a2 >> 0x14);
            M2C_FIELD(arg0, s16 *, 0x7A) = 1;
        }
        return;
    case 1:
        if (randomIntBelow(7) == 0) {
            temp_v1_2 = M2C_FIELD(temp_s0, u8 *, 4);
            if (temp_v1_2 != 0) {
                *(gTrackDoneFlags + temp_v1_2) = 1;
            }
            temp_a2_2 = M2C_FIELD(temp_s0, u32 *, 0);
            func_80044670(arg0, (temp_a2_2 >> 4) & 0xFFFF, temp_a2_2 >> 0x14);
            M2C_FIELD(arg0, s16 *, 0x7A) = 0;
            return;
        }
        break;
    case 2:
        if (randomIntBelow(7) != 0) {
            temp_v0_2 = M2C_FIELD(temp_s0, u8 *, 4);
            if (temp_v0_2 != 0) {
                *(gTrackDoneFlags + temp_v0_2) = 0;
            }
            temp_a2_3 = M2C_FIELD(temp_s0, u32 *, 0);
            func_80044670(arg0, ((temp_a2_3 >> 4) & 0xFFFF) + 1, temp_a2_3 >> 0x14);
            M2C_FIELD(arg0, s16 *, 0x7A) = 3;
        }
        if (randomIntBelow(5) == 0) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 0;
            return;
        }
        return;
    case 3:
        temp_v1_3 = M2C_FIELD(temp_s0, u8 *, 4);
        if (temp_v1_3 != 0) {
            *(gTrackDoneFlags + temp_v1_3) = 1;
        }
        temp_a2_4 = M2C_FIELD(temp_s0, u32 *, 0);
        func_80044670(arg0, (temp_a2_4 >> 4) & 0xFFFF, temp_a2_4 >> 0x14);
        M2C_FIELD(arg0, s16 *, 0x7A) = 2;
        return;
    }
}
