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
s32 randomIntBelow();
void *func_80079CB4();
extern u8 gTrackMarkerDone[];
extern void *gBonusObjects;


/* Counts down the actor's respawn timer; when it expires and the spawn check passes, creates a child actor and flags the spawn. */ void actorUpdateSpawnTimer(void *actor) {
    f32 hitPos[3];
    s32 spawnArg;
    s16 timer;
    s32 actorFlags;
    u16 spawnType;
    u8 flagIndex;
    void *subRec;
    void *posVec;
    void *parentActor;
    void *spawnedActor;
    void *spawnedSubRec;

    subRec = M2C_FIELD(actor, void **, 0x6C);
    timer = M2C_FIELD(subRec, s16 *, 0x10);
    if (timer > 0) {
        M2C_FIELD(subRec, s16 *, 0x10) = (s16) (timer - 1);
        return;
    }
    parentActor = M2C_FIELD(subRec, void **, 0);
    if ((parentActor != NULL) && (M2C_FIELD(parentActor, u16 *, 0x78) == 1)) {
        M2C_FIELD(subRec, s16 *, 0x10) = (s16) (randomIntBelow(0x1C2) + 0x1C2);
        M2C_FIELD(actor, s16 *, 0x7A) = 1;
        return;
    }
    flagIndex = M2C_FIELD(subRec, u8 *, 0x16);
    if (((flagIndex == 0) || (*(gTrackMarkerDone + flagIndex) == 1)) && (actorFlags = M2C_FIELD(actor, s32 *, 0x60), ((actorFlags & 0x1000) == 0)) && (posVec = actor + 0x24, ((actorFlags & 0x6000) != 0))) {
        M2C_FIELD(actor, s32 *, 0x60) = 0;
        if ((func_800158A4(posVec, *M2C_FIELD(gBonusObjects, s32 **, 0x68) + 0xA8, M2C_FIELD(actor, s32 *, 0x20), hitPos, 0, 0, 0, 1, 0) << 0x18) != 0) {
            M2C_FIELD(subRec, s16 *, 0x10) = (s16) (randomIntBelow(0x96) + 0x96);
            return;
        }
        spawnedActor = func_80079CB4(posVec, actor + 0x3C, M2C_FIELD(subRec, s32 *, 4), M2C_FIELD(subRec, u8 *, 0x15), (s32) M2C_FIELD(subRec, u16 *, 0xE), (s32) M2C_FIELD(subRec, u8 *, 0x17), (s32) M2C_FIELD(subRec, u8 *, 0x18), (s32) M2C_FIELD(subRec, u8 *, 0x19), (s32) M2C_FIELD(subRec, u16 *, 8), (s32) M2C_FIELD(subRec, u16 *, 0xA), (s32) M2C_FIELD(subRec, u8 *, 0x14), (s32) M2C_FIELD(subRec, u16 *, 0xC), (s32) M2C_FIELD(subRec, u16 *, 0x12), (s32) M2C_FIELD(subRec, u8 *, 0x16), (s32) M2C_FIELD(subRec, u8 *, 0x1A), 1);
        if (spawnedActor != NULL) {
            spawnedSubRec = M2C_FIELD(spawnedActor, void **, 0x6C);
            M2C_FIELD(spawnedSubRec, s32 *, 0x88) |= 0x10000000;
        }
        spawnType = M2C_FIELD(subRec, u16 *, 8);
        M2C_FIELD(subRec, void **, 0) = spawnedActor;
        switch (spawnType) {
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
            spawnArg = 1;
            goto block_17;
        case 29:
        case 30:
            spawnArg = 2;
block_17:
            if (func_800312F4(spawnArg, 0) == 1) {
                M2C_FIELD(actor, s32 *, 0x60) |= 1;
            }
            break;
        }
    }
}

