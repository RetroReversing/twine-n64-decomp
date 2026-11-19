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

s32 func_800158A4();
s32 func_800312F4();
s32 func_80045CF8();
void *func_80079CB4();
extern u8 D_80109A60[];
extern void *D_8010A500;
static inline short __repair_spill_normalize(int x){x=(unsigned int)x<<16;x=(int)x>>16;return x;}


void func_80081268(void *arg0) {
    s32 sp40;
    s32 var_a0;
    s16 temp_v0;
    s32 temp_v1;
    u16 temp_v0_6;
    u8 temp_v0_3;
    void *temp_s0;
    void *temp_s2;
    void *temp_v0_2;
    void *temp_v0_4;
    void *temp_v0_5;

    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v0 = M2C_FIELD(temp_s0, s16 *, 0x10);
    if (temp_v0 > 0) {
        M2C_FIELD(temp_s0, s16 *, 0x10) = (s16) (temp_v0 - 1);
        return;
    }
    temp_v0_2 = M2C_FIELD(temp_s0, void **, 0);
    if ((temp_v0_2 != NULL) && (M2C_FIELD(temp_v0_2, u16 *, 0x78) == 1)) {
        M2C_FIELD(temp_s0, s16 *, 0x10) = (s16) (func_80045CF8(0x1C2) + 0x1C2);
        M2C_FIELD(arg0, s16 *, 0x7A) = 1;
        return;
    }
    temp_v0_3 = M2C_FIELD(temp_s0, u8 *, 0x16);
    if (((temp_v0_3 == 0) || (*(D_80109A60 + temp_v0_3) == 1)) && (temp_v1 = M2C_FIELD(arg0, s32 *, 0x60), ((temp_v1 & 0x1000) == 0)) && (temp_s2 = arg0 + 0x24, ((__repair_spill_normalize(temp_v1) & 0x6000) != 0))) {
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
        if ((func_800158A4(temp_s2, *M2C_FIELD(D_8010A500, s32 **, 0x68) + 0xA8, M2C_FIELD(arg0, s32 *, 0x20), &sp40, 0, 0, 0, 1, 0) << 0x18) != 0) {
            M2C_FIELD(temp_s0, s16 *, 0x10) = (s16) (func_80045CF8(0x96) + 0x96);
            return;
        }
        temp_v0_4 = func_80079CB4(temp_s2, arg0 + 0x3C, M2C_FIELD(temp_s0, s32 *, 4), M2C_FIELD(temp_s0, u8 *, 0x15), (s32) M2C_FIELD(temp_s0, u16 *, 0xE), (s32) M2C_FIELD(temp_s0, u8 *, 0x17), (s32) M2C_FIELD(temp_s0, u8 *, 0x18), (s32) M2C_FIELD(temp_s0, u8 *, 0x19), (s32) M2C_FIELD(temp_s0, u16 *, 8), (s32) M2C_FIELD(temp_s0, u16 *, 0xA), (s32) M2C_FIELD(temp_s0, u8 *, 0x14), (s32) M2C_FIELD(temp_s0, u16 *, 0xC), (s32) M2C_FIELD(temp_s0, u16 *, 0x12), (s32) M2C_FIELD(temp_s0, u8 *, 0x16), (s32) M2C_FIELD(temp_s0, u8 *, 0x1A), 1);
        if (temp_v0_4 != NULL) {
            temp_v0_5 = M2C_FIELD(temp_v0_4, void **, 0x6C);
            M2C_FIELD(temp_v0_5, s32 *, 0x88) |= 0x10000000;
        }
        temp_v0_6 = M2C_FIELD(temp_s0, u16 *, 8);
        M2C_FIELD(temp_s0, void **, 0) = temp_v0_4;
        switch (temp_v0_6) {
        case 29:
        case 30:
            var_a0 = 2;
            goto block_17;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
            break;
        case 28:
            var_a0 = 1;
block_17:
            if (func_800312F4(var_a0, 0) == 1) {
                M2C_FIELD(arg0, s32 *, 0x60) |= 1;
            }
            break;
        }
    }
}
