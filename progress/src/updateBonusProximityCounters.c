/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 approxDistance(void *, void *);                  /* extern */
extern void *gBonusObjects;

/* Advances the actor's timer and bumps counters of nearby bonus objects on 150-tick steps. */ void updateBonusProximityCounters(void *actor) {
    f32 distance;
    s32 bonusState;
    void **slot;
    u32 slotIndex;
    void *bonus;
    void *counter;
    void *bonusData;

    slotIndex = 0;
    (*(u16 *)((char *)(actor) + 0x7C)) = (u16) ((*(u16 *)((char *)(actor) + 0x7C)) + 1);
    do {
        slot = &gBonusObjects + slotIndex;
        bonus = *slot;
        if (bonus != NULL) {
            bonusState = (*(u16 *)((char *)(bonus) + 0x7A));
            if (((u32) (bonusState - 2) >= 2U) && ((s16) bonusState != 6) && ((*(s32 *)((char *)(bonus) + 0x20)) == (*(s32 *)((char *)(actor) + 0x20)))) {
                distance = approxDistance(bonus + 0x24, actor + 0x24);
                bonusData = (*(void **)((char *)(*slot) + 0x6C));
                if (bonusData != NULL) {
                    counter = (*(void **)((char *)(bonusData) + 0xB4));
                    if ((counter != NULL) && (distance < (*(f32 *)((char *)(actor) + 0x54))) && ((s16) (*(u16 *)((char *)(actor) + 0x7C)) == (((u32)*(s16 *)((char *)actor + 0x7C) / 150U) * 150U))) {
                        (*(u16 *)((char *)(counter) + 0xC)) = (u16) ((*(u16 *)((char *)(counter) + 0xC)) + 1);
                    }
                }
            }
        }
        slotIndex += 1;
    } while (slotIndex < 4U);
}

