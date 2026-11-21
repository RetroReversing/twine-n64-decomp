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

s32 requestSound();
s32 func_80063D38();
s32 func_80084338();
typedef struct {
    u16 flags;
    u8 data[0xE6];
} EnemyDefinition;
extern EnemyDefinition sEnemyDefTable[];

void func_80070CA4(void *arg0) {
    volatile u32 framePad[2];

int __repair_constant;

    s16 temp_v1;
    s8 temp_a1;
    s8 temp_a1_2;
    s8 temp_v0_2;
    s32 temp_v0_3;
    s8 temp_v1_2;
    void *temp_a0;
    void *temp_a2;
    
    void *temp_s4;
    
    void *temp_v1_3;
    void *temp_v1_4;

    temp_s4 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v1 = M2C_FIELD(M2C_FIELD(temp_s4, void **, 0xA8), s16 *, 0x7A);
    switch (temp_v1) {
    default:
    case 0:
    case 1:
    case 2:
    case 4:
    case 8:
        if (M2C_FIELD(arg0, u16 *, 0x78) == 3) {
            func_80084338(0x118, (u8 *)arg0 + 0x24);
        } else {
            requestSound(0x118);
        }
        temp_a0 = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(temp_a0, u8 *, 0x10) = M2C_FIELD(temp_a0, u8 *, 0xE);
        temp_a0 = M2C_FIELD(arg0, void **, 0x68);
        temp_v1_2 = M2C_FIELD(temp_a0, s8 *, 0xF);
        if (temp_v1_2 >= 0x27) {
            M2C_FIELD(temp_a0, s8 *, 0xF) = (s8) M2C_FIELD(temp_s4, u16 *, 0x134);
            return;
restore_and_exit:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = temp_a1;
            return;
        }
        __repair_constant = 0x26;
        if (!(sEnemyDefTable[temp_v1_2].flags & 0x8000)) {
            do {
                temp_v1_3 = M2C_FIELD(arg0, void **, 0x68);
                temp_v0_2 = (u8) M2C_FIELD(temp_v1_3, s8 *, 0xF) - 1;
                M2C_FIELD(temp_v1_3, s8 *, 0xF) = temp_v0_2;
                if (temp_v0_2 < 0) {
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = __repair_constant;
                }
            } while (!(sEnemyDefTable[M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF)].flags & 0x8000));
        }
loop_13:
        temp_v1_4 = M2C_FIELD(arg0, void **, 0x68);
        temp_v0_3 = (u8) M2C_FIELD(temp_v1_4, s8 *, 0xF) - 1;
        M2C_FIELD(temp_v1_4, s8 *, 0xF) = temp_v0_3;
        if ((s8)temp_v0_3 < 0) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = __repair_constant;
        }
        temp_a2 = M2C_FIELD(arg0, void **, 0x68);
        temp_a1 = M2C_FIELD(temp_a2, s8 *, 0xF);
        if (!(sEnemyDefTable[temp_a1].flags & 0x8000)) {
            goto loop_13;
        }
        M2C_FIELD(temp_a2, s8 *, 0xF) = (s8) (temp_a1 + M2C_FIELD((temp_s4 + (temp_a1 * 8)), u8 *, 0x1FE));
        temp_a0 = temp_s4 + (temp_a1 * 8);
        if (M2C_FIELD(temp_a0, u8 *, 0x1FC) == 0) {
block_23:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = temp_a1;
            goto loop_13;
        }
        temp_a1_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF);
        if ((temp_a1_2 != 0) && ((func_80063D38(temp_s4, temp_a1_2) << 0x18) == 0)) {
            if (M2C_FIELD(temp_a0, u8 *, 0x1FE) != 0) {
                if ((func_80063D38(temp_s4, temp_a1) << 0x18) != 0) {
                    M2C_FIELD(temp_a0, u8 *, 0x1FE) = 0U;
                    goto restore_and_exit;
                }
                goto block_23;
            }
            goto block_23;
        }
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

