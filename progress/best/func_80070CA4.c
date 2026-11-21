#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern s32 func_80063D38(s32, s16);
extern s32 func_80084338(s32, s32);
extern s32 requestSound(s32);
typedef struct { u16 flags; u8 pad[230]; } EnemyDef70;
extern EnemyDef70 sEnemyDefTable[];

void func_80070CA4(void *arg0) {
    u32 scratch[2];
    s32 wrap;
    s16 temp_v1;
    s8 temp_a1;
    s8 temp_a1_2;
    s8 temp_v0_2;
    s8 temp_v0_3;
    s8 temp_v1_2;
    void *temp_a0;
    void *temp_a2;
    void *temp_s2;
    void *temp_s4;
    void *temp_v0;
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
            func_80084338(0x118, (s32)((u8 *)arg0 + 0x24));
        } else {
            requestSound(0x118);
        }
        temp_v0 = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(temp_v0, u8 *, 0x10) = (u8) M2C_FIELD(temp_v0, u8 *, 0xE);
        temp_a0 = M2C_FIELD(arg0, void **, 0x68);
        temp_v1_2 = M2C_FIELD(temp_a0, s8 *, 0xF);
        if (temp_v1_2 >= 0x27) {
            M2C_FIELD(temp_a0, s8 *, 0xF) = (s8) M2C_FIELD(temp_s4, u16 *, 0x134);
            return;
        }
        goto lookup;
restore:
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = temp_a1;
        return;
lookup:
        if (!(sEnemyDefTable[temp_v1_2].flags & 0x8000)) {
            do {
                temp_v1_3 = M2C_FIELD(arg0, void **, 0x68);
                temp_v0_2 = (u8) M2C_FIELD(temp_v1_3, s8 *, 0xF) - 1;
                M2C_FIELD(temp_v1_3, s8 *, 0xF) = temp_v0_2;
                if (temp_v0_2 < 0) {
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = 0x26;
                }
            } while (!(sEnemyDefTable[M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF)].flags & 0x8000));
        }
        wrap = 0x26;
loop_13:
        temp_v1_4 = M2C_FIELD(arg0, void **, 0x68);
        temp_v0_3 = (u8) M2C_FIELD(temp_v1_4, s8 *, 0xF) - 1;
        M2C_FIELD(temp_v1_4, s8 *, 0xF) = temp_v0_3;
        if (temp_v0_3 < 0) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = wrap;
        }
        temp_a2 = M2C_FIELD(arg0, void **, 0x68);
        temp_a1 = M2C_FIELD(temp_a2, s8 *, 0xF);
        if (!(sEnemyDefTable[temp_a1].flags & 0x8000)) {
            goto loop_13;
        }
        {
        s32 saved = temp_a1;
        M2C_FIELD(temp_a2, s8 *, 0xF) = (s8) (temp_a1 + M2C_FIELD((temp_s4 + (temp_a1 * 8)), u8 *, 0x1FE));
        temp_a1 = saved;
        }
        temp_s2 = temp_s4 + (temp_a1 * 8);
        if (M2C_FIELD(temp_s2, u8 *, 0x1FC) != 0) {
            temp_a1_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF);
            if (temp_a1_2 == 0 || ((u32)func_80063D38((s32)temp_s4, temp_a1_2) << 24))
                return;
            if (M2C_FIELD(temp_s2, u8 *, 0x1FE) && ((u32)func_80063D38((s32)temp_s4, temp_a1) << 24)) {
                M2C_FIELD(temp_s2, u8 *, 0x1FE) = 0;
                goto restore;
            }
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xF) = temp_a1;
        goto loop_13;
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
