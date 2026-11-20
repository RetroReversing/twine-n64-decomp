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

s32 func_80015F74(void *);
void *func_80016410(M2C_UNK, s32, M2C_UNK, M2C_UNK);
M2C_UNK actorLinkToSurface(s32, void *, M2C_UNK);
M2C_UNK func_80044670(void *, M2C_UNK, M2C_UNK);
M2C_UNK func_800643C8(void *);
extern s32 *gProbeObjectList;
extern u8 gSceneType;
extern u8 D_8011ECF0[];
extern M2C_UNK D_8011ED08;
extern M2C_UNK D_8011F160;
extern M2C_UNK D_8011F278;
extern M2C_UNK D_8011F288;
extern M2C_UNK D_8011F290;
extern M2C_UNK D_8011F2B0;

/* Spawns a scene actor for a slot (scene types 2-3), sets its flags and animation, links it to the probe surface list and records it in the slot tables. */
void *spawnSlotActor(s32 modelId, M2C_UNK unusedArg, u16 slot) {
    u8 *sceneTypePtr;
    M2C_UNK animId;
    s32 slotCopy;
    s32 slotCopy2;
    s32 slotCopy3;
    s32 slotOffset;
    void *actor;

    sceneTypePtr = &gSceneType;
    if ((u32) ((*sceneTypePtr) - 2) < 2U) {
        actor = func_80016410(0, modelId, unusedArg, unusedArg);
        slotCopy = slot;
        if (actor != NULL) {
            slotOffset = slotCopy;
            *(&D_8011F160 + slotOffset) = actor + 0x24;
            *(&D_8011F278 + slotOffset) = 0;
            *(&D_8011F290 + slotOffset) = 0;
            M2C_FIELD(actor, u16 *, 0x78) = 0x42;
            M2C_FIELD(actor, u16 *, 0x7A) = slot;
            M2C_FIELD(actor, f32 *, 0x54) = 1.0f;
            M2C_FIELD(actor, s32 *, 0x5C) = (s32) (M2C_FIELD(actor, s32 *, 0x5C) & ~0x200);
            M2C_FIELD(actor, s32 *, 0x58) = (s32) (M2C_FIELD(actor, s32 *, 0x58) | 1);
            if ((*sceneTypePtr) == 2) {
                *(&D_8011ED08 + slotCopy * 0x9) = 0xC;
                if (slotCopy == 0) {
                    animId = 7;
                
                func_80044670(actor, animId, 0xF4);} else {
                    animId = 8;
                
                func_80044670(actor, animId, 0xF4);}
            } else {
                *(&D_8011ED08 + slotCopy * 0x9) = 0x14;
                func_80044670(actor, 1, 0xF4);
                {
                    u8 intensity = 0xB4;
                    if (slotCopy != 0) goto alternate;
                    M2C_FIELD(actor, u8 *, 0x81) = intensity;
                    goto common;
                alternate:
                    M2C_FIELD(actor, u8 *, 0x7F) = intensity;
                common:
                    M2C_FIELD(actor, volatile u8 *, 0x80) = intensity;
                }
                M2C_FIELD(actor, f32 *, 0x28) = (f32) (M2C_FIELD(actor, volatile f32 *, 0x28) + 0.76f);
                M2C_FIELD(actor, f32 *, 0x34) = (f32) (M2C_FIELD(actor, volatile f32 *, 0x34) + 0.76f);
            }
            actorLinkToSurface(*gProbeObjectList, actor, 1);
            func_800643C8(actor);
            slotCopy2 = slot;
            slotCopy3 = slotCopy2;
            *(&D_8011F288 + slotCopy3) = func_80015F74((slotCopy2 * 0x24) + D_8011ECF0);
            *(&D_8011F2B0 + slotCopy3) = actor;
            return actor;
        }
    }
    return NULL;
}
