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

s32 func_8000A894();
s32 func_80065BC4();
s32 func_80084338();
extern char D_800C4486[];

void func_80070B40(void *arg0) {
    s32 var_a0_2;
    s32 temp_v1;
    s16 var_a0;
    s32 var_a1;
    s8 temp_v0;
    s32 var_a0_3;
    void *temp_s1;
    void *temp_v0_2;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v1 = M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xA8), s16 *, 0x7A);
    var_a0 = 1;
    switch (temp_v1) {
    case 1:
    case 3:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
        break;
    default:
    case 0:
    case 2:
    case 4:
    case 8:
        temp_v1_2 = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(temp_v1_2, u8 *, 0x10) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0xE);
        temp_v1_3 = M2C_FIELD(arg0, void **, 0x68);
        if (M2C_FIELD(temp_v1_3, s8 *, 0xF) < 0x28) {
            M2C_FIELD(temp_s1, s16 *, 0x134) = (s16) (s8) M2C_FIELD(temp_v1_3, u8 *, 0xE);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = 0x27;
        }
        for (;;) {
            temp_v1_4 = M2C_FIELD(arg0, void **, 0x68);
            temp_v0 = (u8) M2C_FIELD(temp_v1_4, s8 *, 0xF) + 1;
            M2C_FIELD(temp_v1_4, s8 *, 0xF) = temp_v0;
            if (temp_v0 >= 0x37) {
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = 0x28;
                var_a0_2 = 0xEC;
                if (var_a0 != 0) {
                    var_a0 = 0;
                    goto block_10;
                }
                temp_v0_2 = M2C_FIELD(arg0, void **, 0x68);
                M2C_FIELD(temp_v0_2, s8 *, 0xF) = (s8) M2C_FIELD(temp_v0_2, u8 *, 0xE);
                {
                    func_8000A894(var_a0_2);break;}
            }
block_10:
            if (M2C_FIELD((temp_s1 + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) * 8)), u8 *, 0x1FC) != 0) {
                var_a0_2 = 0x118;
                if (M2C_FIELD(arg0, u16 *, 0x78) == 3) {
                    func_80084338(0x118, arg0 + 0x24);
                } else {
block_12:
                    func_8000A894(var_a0_2);
                }
            } else {
                continue;
            }
            break;
        }
        func_80065BC4(arg0);
        M2C_FIELD(temp_s1, u16 *, 0x174) = 0U;
        var_a0_3 = 0;
        var_a1 = 0;
        do {
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) == *(s16 *)(D_800C4486 + var_a1)) {
                M2C_FIELD(temp_s1, u16 *, 0x174) = var_a0_3;
            }
            var_a0_3 += 1;
            var_a1 += 0x10;
        } while (var_a0_3 < 0x1EU);
        break;
    }
}
