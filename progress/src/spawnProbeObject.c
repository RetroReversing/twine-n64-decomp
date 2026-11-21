typedef struct { f32 x, y, z; } OverlayPosition;

typedef struct {
    u8 pad0[0x54];
    f32 scale;
    u8 pad58[4];
    u32 flags;
    u8 pad60[0x18];
    s16 kind;
    u16 index;
    u8 pad7C[3];
    u8 color[3];
} OverlayObject;

extern void listUnlinkFree(s32);
extern OverlayObject *spawnEffectObject(s32, OverlayPosition *, void *);
extern void func_8002B000(void *, s32);
extern void actorLinkToSurface(s32, OverlayObject *, s32);
extern void objectSetAnimFrame(OverlayObject *, s32, s32);
extern s32 *gProbeObjectList;
extern u8 gSceneType;
extern u32 sProbeTimers[][2];
extern u8 sProbeActive[];
extern OverlayObject *sProbeObjects[];
extern s32 sProbeFlags[], sProbeHandles[];
extern OverlayPosition sProbePositions[];

/* Spawns a probe object for slot 'slot' in scene types 2 and 3, records its position and state, and returns it (or NULL). */
OverlayObject *spawnProbeObject(register OverlayPosition *position, void *orientation, u32 slot)
{
    register u8 *sceneType = &gSceneType;

    if ((u32)(*sceneType - 2) < 2U) {
        OverlayObject *probe = spawnEffectObject(0, position, orientation);
        if (probe != NULL) {
            register u32 slotIndex = (u16)slot;
            register void *timerRec;
            do { objectSetAnimFrame(probe, 6, 0xF4); } while (0);
            sProbePositions[slotIndex] = *position;
            timerRec = sProbeTimers[slotIndex];
            probe->kind = 0x45;
            probe->index = slot;
            probe->scale = 1.0f;
            sProbeObjects[slotIndex] = probe;
            sProbeActive[slotIndex] = 1;
            sProbeFlags[slotIndex] = 0;
            func_8002B000(timerRec, 0x1E);
            listUnlinkFree(sProbeHandles[slotIndex]);
            sProbeHandles[slotIndex] = 0;
            probe->flags &= ~0x200;
            if (*sceneType == 3) {
                sProbePositions[slotIndex].y += 0.76f;
            }
            actorLinkToSurface(*gProbeObjectList, probe, 1);
            {
                register s32 colorValue = 0xB4;
                if (slotIndex == 0) {
                    probe->color[2] = colorValue;
                } else {
                    probe->color[0] = colorValue;
                }
                probe->color[1] = colorValue;
            }
            return probe;
        }
    }
    return NULL;
}
