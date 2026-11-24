/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 requestSound();
u32 randomIntBelow();
s32 resolveEnemyDefLink();
s32 setActionSlot();
s32 spawnCaptionMessage();
s32 playSoundAtPos();
s32 *lookupDataEntry();
s32 startBonusSceneActor();
s32 relinkTrackMarkerSlot();
s32 sprintf();
extern char D_800C447C[];
extern char D_800C4484[];
extern char sEnemyDefTable[];
extern char D_800C46A1[];
extern char sEnemyDefLinkSlot[];
extern char gStatMaxTable[];
extern u8 gSceneType;
extern s32 gTrackMarkerSerial;
extern char gTrackMarkerParents[];
extern void *sBonusObjectTable;

extern char D_800D41E0[];
/* Applies a collected bonus object to an actor: kind 0 teaches/upgrades an enemy ability, 1 grants an action, 2 raises a stat. Returns 1 if applied. */ s32 applyBonusObjectEffect(void *actor, s32 *bonusObject) {
int __repair_literal;

    char sp30[124];
    s32 (*temp_v0_10)(void *);
    s32 *formatName;
    s32 enemyOffset;
    s32 *temp_s0_3;
    s32 markerLinked;
    s16 temp_v0_5;
    s16 temp_v0_8;
    s16 temp_v0_9;
    s32 bonusSlotChoice;
    
    s32 temp_v1;
    s32 statGain;
    s32 result;
    s8 temp_a1_2;
    u16 temp_a0;
    u16 temp_a0_3;
    s32 effectKind;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v1_3;
    u16 soundId;
    u16 soundIdEnemy;
    u32 var_a0;
    u32 filledMask;
    u32 statIndex;
    u32 temp_v1_6;
    void **var_v1;
    void *temp_a0_2;
    void *temp_a0_4;
    void *temp_a1;
    void *actorData;
    void *objectData;
    void *enemyDef;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_7;
    void *temp_v1_2;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_7;

    actorData = M2C_FIELD(actor, void **, 0x6C);
    objectData = M2C_FIELD(bonusObject, void **, 0x6C);
    if (gSceneType == 8) {
        bonusSlotChoice = randomIntBelow(0x1E) / 10;
        filledMask = 0;
        markerLinked = 0;
        var_a0 = 0;
        var_v1 = &sBonusObjectTable;
        do {
            temp_v0 = *var_v1;
            if (temp_v0 != NULL) {
                temp_v0_2 = M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x6C), void **, 0xB4);
                if (temp_v0_2 != NULL) {
                    filledMask |= M2C_FIELD(temp_v0_2, u8 *, 0x10);
                }
            }
            var_v1 += 1;
        } while (++var_a0 < 4U);
        if ((filledMask ^ 1) & 1 & (bonusSlotChoice == 0)) {
            relinkTrackMarkerSlot(actorData, 1);
            markerLinked = 1;
        }
        if (((filledMask >> 1) ^ 1) & 1 & (bonusSlotChoice == 1)) {
            relinkTrackMarkerSlot(actorData, 2);
            markerLinked = 1;
        }
        if (((filledMask >> 2) ^ 1) & 1 & (bonusSlotChoice == 2)) {
            relinkTrackMarkerSlot(actorData, 4);
            markerLinked = 1;
        }
        result = markerLinked;
        if (result != 0) {
            result = 1;
            if (M2C_FIELD(M2C_FIELD(actorData, void **, 0xB4), u8 *, 0x10) == 7) {
                startBonusSceneActor(actorData);
                return 1;
            }
            /* Duplicate return node #67. Try simplifying control flow for better match */
            return result;
        }
        goto block_15;
    }
block_15:
    effectKind = M2C_FIELD(objectData, u16 *, 0x3C);
    switch (effectKind) {
    case 2:
                temp_a0 = M2C_FIELD(objectData, u16 *, 0x3E);
                temp_v1 = temp_a0 & 0xFFFF;
                result = 0;
__repair_literal = 2;

                if (M2C_FIELD((actorData + (temp_v1 * __repair_literal)), s16 *, 0x1BC) < *(s16 *)(gStatMaxTable + (temp_v1 * 4))) {
                    formatName = lookupDataEntry(temp_a0 | 0x9000);
                    sprintf(&sp30, D_800D41E0, formatName, lookupDataEntry(0x16A));
                    gTrackMarkerSerial += 1;
                    spawnCaptionMessage(0, *(s32 *)(gTrackMarkerParents + (M2C_FIELD(actorData, s8 *, 0x182) * 4)), &sp30, -1, -1, 1, 0, 0, 0, 0, 0);
                    temp_v0_3 = M2C_FIELD(objectData, u16 *, 0x3E);
                    switch (temp_v0_3) {
                    case 3:
                        statGain = 0x18;
                        break;
                    case 1:
                    case 2:
                    case 4:
                        statGain = 0x5A;
                        break;
                    case 5:
                        statGain = 0x64;
                        break;
                    case 6:
                        statGain = 0x3C;
                        break;
                    case 7:
                        statGain = 0x20;
                        break;
                    case 9:
                        statGain = 6;
                        break;
                    case 11:
                        statGain = 8;
                        break;
                    case 12:
                    case 13:
                        statGain = 0x14;
                        break;
                    default:
                        statGain = 0;
                        break;
                    }
                    temp_v1_2 = actorData + (M2C_FIELD(objectData, u16 *, 0x3E) * 2);
                    M2C_FIELD(temp_v1_2, u16 *, 0x1BC) += statGain;
                    temp_v0_4 = M2C_FIELD(objectData, u16 *, 0x3E);
                    temp_a0_2 = actorData + (temp_v0_4 * 2);
                    temp_v0_5 = *(s16 *)(gStatMaxTable + (temp_v0_4 * 4));
                    if (temp_v0_5 < M2C_FIELD(temp_a0_2, s16 *, 0x1BC)) {
                        M2C_FIELD(temp_a0_2, s16 *, 0x1BC) = temp_v0_5;
                    }
                    soundId = 0xD8;
                    if (M2C_FIELD(actor, u16 *, 0x78) != 3) {
                        goto block_65;
                    }
                    goto block_63;
                }
        return 0;
    case 0:
        temp_v1_3 = M2C_FIELD(objectData, u16 *, 0x3E);
        enemyOffset = temp_v1_3 * 0xE8;
        enemyDef = enemyOffset + sEnemyDefTable;
        statIndex = M2C_FIELD(enemyDef, u8 *, 0x80);
        if ((u8) *(u8 *)((u32)actorData + (temp_v1_3 << 3) + 0x1FC) < (u8) *(D_800C46A1 + enemyOffset)) {
            gTrackMarkerSerial += 1;
            spawnCaptionMessage(0, *(s32 *)(gTrackMarkerParents + (M2C_FIELD(actorData, s8 *, 0x182) * 4)), lookupDataEntry(M2C_FIELD(objectData, u16 *, 0x3E) | 0x6000), -1, -1, 1, 0, 0, 0, 0, 0);
            temp_v1_4 = actorData + (M2C_FIELD(objectData, u16 *, 0x3E) * 8);
            M2C_FIELD(temp_v1_4, u8 *, 0x1FC) += 1;
            soundIdEnemy = 0xD9;
            if (M2C_FIELD(actor, u16 *, 0x78) == 3) {
                goto block_43;
            } else {
                requestSound(0xD9U);
            }
            goto block_45;
        }
        result = 0;
        if (*(s16 *)((u32)actorData + (statIndex << 1) + 0x1BC) < *(s16 *)(gStatMaxTable + (statIndex * 4))) {
            temp_s0_3 = lookupDataEntry(statIndex | 0x9000);
            sprintf(&sp30, D_800D41E0, temp_s0_3, lookupDataEntry(0x16A));
            gTrackMarkerSerial += 1;
            spawnCaptionMessage(0, *(s32 *)(gTrackMarkerParents + (M2C_FIELD(actorData, s8 *, 0x182) * 4)), &sp30, -1, -1, 1, 0, 0, 0, 0, 0);
            soundIdEnemy = 0xD8;
            if (M2C_FIELD(actor, u16 *, 0x78) == 3) {
block_43:
                playSoundAtPos(soundIdEnemy, actor + 0x24);
            } else {
                ((void (*)(u32))requestSound)(0xD8U);
            }
block_45:
            if (M2C_FIELD((actorData + ((s32) (resolveEnemyDefLink((s16) M2C_FIELD(objectData, u16 *, 0x3E)) << 0x10) >> 0xD)), s8 *, 0x1FF) == 0) {
                M2C_FIELD((actorData + ((s32) (resolveEnemyDefLink((s16) M2C_FIELD(objectData, u16 *, 0x3E)) << 0x10) >> 0xD)), u8 *, 0x1FF) = (u8) M2C_FIELD(enemyDef, u8 *, 0x82);
                temp_v1_5 = actorData + (statIndex * 2);
                M2C_FIELD(temp_v1_5, u16 *, 0x1BC) += M2C_FIELD(enemyDef, u8 *, 0x82);
            } else {
                temp_v0_7 = actorData + (statIndex * 2);
                M2C_FIELD(temp_v0_7, u16 *, 0x1BC) += (M2C_FIELD(enemyDef, u8 *, 0x82) * 2);
            }
            temp_a1 = actorData + (statIndex * 2);
            temp_v0_8 = *(s16 *)(gStatMaxTable + (statIndex * 4));
            if (temp_v0_8 < M2C_FIELD(temp_a1, s16 *, 0x1BC)) {
                M2C_FIELD(temp_a1, s16 *, 0x1BC) = temp_v0_8;
            }
            temp_a1_2 = M2C_FIELD(enemyDef, s8 *, 4);
            result = 1;
            if (temp_a1_2 != 0) {
                u8 tableByte;
                temp_a0_3 = M2C_FIELD(objectData, u16 *, 0x3E);
                tableByte = *(u8 *)(sEnemyDefLinkSlot + ((temp_a0_3 + temp_a1_2) * 0xE8));
                if (tableByte != M2C_FIELD(enemyDef, u8 *, 0x80)) {
                    u8 quantity = 2;
                    temp_v1_6 = tableByte;
                    if (M2C_FIELD((actorData + ((s32) (resolveEnemyDefLink((s16) (temp_a0_3 + temp_a1_2)) << 0x10) >> 0xD)), s8 *, 0x1FF) == 0) {
                        M2C_FIELD((actorData + ((s32) (resolveEnemyDefLink((s16) (M2C_FIELD(objectData, u16 *, 0x3E) + (s8) (u8) M2C_FIELD(enemyDef, s8 *, 4))) << 0x10) >> 0xD)), s8 *, 0x1FF) = quantity;
                    } else {
                        temp_v1_7 = actorData + (temp_v1_6 * 2);
                        M2C_FIELD(temp_v1_7, u16 *, 0x1BC) += quantity;
                    }
                    temp_a0_4 = actorData + (temp_v1_6 * 2);
                    temp_v0_9 = *(s16 *)(gStatMaxTable + (temp_v1_6 * 4));
                    if (temp_v0_9 < M2C_FIELD(temp_a0_4, s16 *, 0x1BC)) {
                        M2C_FIELD(temp_a0_4, s16 *, 0x1BC) = temp_v0_9;
                        goto block_66;
                    }
                    return 1;
                }
                goto block_66;
            }
            /* Duplicate return node #67. Try simplifying control flow for better match */
            return result;
        }
        /* Duplicate return node #67. Try simplifying control flow for better match */
        return result;
    case 1:
    temp_v0_10 = *(s32 (**)(void *))(D_800C447C + (M2C_FIELD(objectData, u16 *, 0x3E) * 0x10));
    if (temp_v0_10 != NULL) {
        temp_v0_10(actor);
    }
    setActionSlot(actorData, M2C_FIELD(objectData, u8 *, 0x3F), M2C_FIELD(objectData, u8 *, 0x3D), 0);
    gTrackMarkerSerial += 1;
    spawnCaptionMessage(0, *(s32 *)(gTrackMarkerParents + (M2C_FIELD(actorData, s8 *, 0x182) * 4)), lookupDataEntry(M2C_FIELD(objectData, u16 *, 0x3E) | 0x7000), -1, -1, (s32) effectKind, 0, 0, 0, 0, 0);
    if (M2C_FIELD(actor, u16 *, 0x78) == 3) {
        soundId = *(u16 *)(D_800C4484 + (M2C_FIELD(objectData, u16 *, 0x3E) * 0x10));
block_63:
        playSoundAtPos(soundId, actor + 0x24);
        return 1;
    }
    soundId = *(u16 *)(D_800C4484 + (M2C_FIELD(objectData, u16 *, 0x3E) * 0x10));
block_65:
    requestSound(soundId);
        break;
    default:
        break;
    }
block_66:
    result = 1;
    return result;
}



