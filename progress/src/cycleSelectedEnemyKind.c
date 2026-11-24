#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern s32 isEnemyDefAvailable(s32, s16);
extern s32 playSoundAtPos(s32, s32);
extern s32 requestSound(s32);
typedef struct { u16 flags; u8 pad[230]; } EnemyDef70;
extern EnemyDef70 sEnemyDefTable[];

/* Plays a click sound, then steps the actor's current enemy-kind index backwards through sEnemyDefTable to the previous enabled (flag 0x8000) entry, applying per-entry adjustments. */ void cycleSelectedEnemyKind(void *actor) {
int __repair_literal;

    u32 scratch[2];
    s32 lastIndex;
    s16 temp_v1;
    s8 kindIndex;
s8 __repair_result_temp_a1;
    s8 temp_a1_2;
    s8 temp_v0_2;
    s8 temp_v0_3;
    s8 temp_v1_2;
    void *temp_a0;
    void *temp_a2;
    void *entry;
    void *owner;
    void *temp_v0;
    void *temp_v1_3;
    void *temp_v1_4;

    owner = M2C_FIELD(actor, void **, 0x6C);
    temp_v1 = M2C_FIELD(M2C_FIELD(owner, void **, 0xA8), s16 *, 0x7A);
    switch (temp_v1) {
    default:
    case 0:
    case 1:
    case 2:
    case 4:
    case 8:
        if (M2C_FIELD(actor, u16 *, 0x78) == 3) {
            playSoundAtPos(0x118, (s32)((u8 *)actor + 0x24));
        } else {
            requestSound(0x118);
        }
        temp_v0 = M2C_FIELD(actor, void **, 0x68);
        M2C_FIELD(temp_v0, u8 *, 0x10) = (u8) M2C_FIELD(temp_v0, u8 *, 0xE);
        temp_a0 = M2C_FIELD(actor, void **, 0x68);
        temp_v1_2 = M2C_FIELD(temp_a0, s8 *, 0xF);
        if (temp_v1_2 >= 0x27) {
            M2C_FIELD(temp_a0, s8 *, 0xF) = (s8) M2C_FIELD(owner, u16 *, 0x134);
            return;
        }
        goto lookup;
restore:
        M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF) = kindIndex;
        return;
lookup:
        if (!(sEnemyDefTable[temp_v1_2].flags & 0x8000)) {
            do {
                temp_v1_3 = M2C_FIELD(actor, void **, 0x68);
                temp_v0_2 = (u8) M2C_FIELD(temp_v1_3, s8 *, 0xF) - 1;
                M2C_FIELD(temp_v1_3, s8 *, 0xF) = temp_v0_2;
                if (temp_v0_2 < 0) {
                    M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF) = 0x26;
                }
            } while (!(sEnemyDefTable[M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF)].flags & 0x8000));
        }
        lastIndex = 0x26;
        for (;;) {
            temp_v1_4 = M2C_FIELD(actor, void **, 0x68);
            temp_v0_3 = (u8) M2C_FIELD(temp_v1_4, s8 *, 0xF) - 1;
            M2C_FIELD(temp_v1_4, s8 *, 0xF) = temp_v0_3;
            if (temp_v0_3 < 0) {
                M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF) = lastIndex;
            }
            temp_a2 = M2C_FIELD(actor, void **, 0x68);
            __repair_result_temp_a1 = M2C_FIELD(temp_a2, s8 *, 0xF);
            if (!(sEnemyDefTable[__repair_result_temp_a1].flags & 0x8000)) {
                continue;
            }
            {
            s32 saved = __repair_result_temp_a1;
__repair_literal = 8;

            M2C_FIELD(temp_a2, s8 *, 0xF) = (s8) (__repair_result_temp_a1 + M2C_FIELD((owner + (__repair_result_temp_a1 * __repair_literal)), u8 *, 0x1FE));
            kindIndex = saved;
            }
            entry = owner + (kindIndex * 8);
            if (M2C_FIELD(entry, u8 *, 0x1FC) != 0) {
                temp_a1_2 = M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF);
                if (temp_a1_2 == 0 || ((u32)isEnemyDefAvailable((s32)owner, temp_a1_2) << 24))
                    return;
                if (M2C_FIELD(entry, u8 *, 0x1FE) && ((u32)isEnemyDefAvailable((s32)owner, kindIndex) << 24)) {
                    M2C_FIELD(entry, u8 *, 0x1FE) = 0;
                    goto restore;
                }
            }
            M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF) = kindIndex;
            continue;
            break;
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
