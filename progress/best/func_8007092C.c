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
s32 func_80063D38();
s32 func_80084338();
extern char D_800C469C[];
extern char D_800C469E[];

void func_8007092C(void *arg0, s8 arg1) {
    s16 temp_v1;
    s32 var_s6;
    s8 temp_a1;
    s8 temp_a1_2;
    u8 temp_v0;
    void *temp_a2;
    void *temp_s2;
    void *temp_s4;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;

    temp_s4 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v1 = M2C_FIELD(M2C_FIELD(temp_s4, void **, 0xA8), s16 *, 0x7A);
    var_s6 = 0;
    switch (temp_v1) {
    default:
    case 0:
    case 2:
    case 4:
    case 8:
        if (M2C_FIELD(arg0, u16 *, 0x78) == 3) {
            func_80084338(0x118, arg0 + 0x24);
        } else {
            func_8000A894(0x118);
        }
        temp_v1_2 = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(temp_v1_2, u8 *, 0x10) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0xE);
        temp_v1_3 = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(temp_v1_3, u8 *, 0xF) = (u8) M2C_FIELD(temp_v1_3, u8 *, 0xE);
        temp_v1_4 = M2C_FIELD(arg0, void **, 0x68);
        if ((s8) M2C_FIELD(temp_v1_4, u8 *, 0xF) >= 0x27) {
            M2C_FIELD(temp_v1_4, u8 *, 0xF) = (u8) M2C_FIELD(temp_s4, u16 *, 0x134);
            return;
        }
loop_8:
        temp_v1_5 = M2C_FIELD(arg0, void **, 0x68);
        temp_v0 = M2C_FIELD(temp_v1_5, u8 *, 0xF) + 1;
        M2C_FIELD(temp_v1_5, u8 *, 0xF) = temp_v0;
        if ((s8) temp_v0 >= 0x27) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 0xF) = 0U;
        }
        temp_a2 = M2C_FIELD(arg0, void **, 0x68);
        temp_a1 = (s8) M2C_FIELD(temp_a2, u8 *, 0xF);
        if (!(*(u16 *)(D_800C469C + (temp_a1 * 0xE8)) & 0x8000)) {
            goto loop_8;
        }
        M2C_FIELD(temp_a2, u8 *, 0xF) = (u8) (temp_a1 + M2C_FIELD((temp_s4 + (temp_a1 * 8)), u8 *, 0x1FE));
        temp_s2 = temp_s4 + (temp_a1 * 8);
        if (M2C_FIELD(temp_s2, u8 *, 0x1FC) == 0) {
            goto loop_8;
        }
        if ((arg1 != 0) && (*(u16 *)(D_800C469E + ((s8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 0xF) * 0xE8)) == 0x21)) {
            goto loop_8;
        }
        temp_a1_2 = (s8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 0xF);
        if (temp_a1_2 == 0) {
            if (var_s6 == 0) {
                var_s6 = 1;
                if (arg1 != 0) {
                    goto loop_8;
                }
            }
        } else if ((func_80063D38(temp_s4, temp_a1_2, temp_a2) << 0x18) == 0) {
            if ((M2C_FIELD(temp_s2, u8 *, 0x1FE) != 0) && ((func_80063D38(temp_s4, temp_a1) << 0x18) != 0)) {
                M2C_FIELD(temp_s2, u8 *, 0x1FE) = 0U;
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), u8 *, 0xF) = (u8) temp_a1;
            } else {
                goto loop_8;
            }
        }
    case 1:
    case 3:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
        return;
    }
}
