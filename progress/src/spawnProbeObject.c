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
extern u32 D_8011F140[][2];
extern u8 D_8011F168[];
extern OverlayObject *sProbeObjects[];
extern s32 D_8011F280[], D_8011F290[];
extern OverlayPosition sProbePositions[];

OverlayObject *spawnProbeObject(register OverlayPosition *position, void *orientation, u32 index)
{
    register u8 *state = &gSceneType;

    if ((u32)(*state - 2) < 2U) {
        OverlayObject *object = spawnEffectObject(0, position, orientation);
        if (object != NULL) {
            register u32 idx = (u16)index;
            register void *timer;
            do { objectSetAnimFrame(object, 6, 0xF4); } while (0);
            sProbePositions[idx] = *position;
            timer = D_8011F140[idx];
            object->kind = 0x45;
            object->index = index;
            object->scale = 1.0f;
            sProbeObjects[idx] = object;
            D_8011F168[idx] = 1;
            D_8011F280[idx] = 0;
            func_8002B000(timer, 0x1E);
            listUnlinkFree(D_8011F290[idx]);
            D_8011F290[idx] = 0;
            object->flags &= ~0x200;
            if (*state == 3) {
                sProbePositions[idx].y += 0.76f;
            }
            actorLinkToSurface(*gProbeObjectList, object, 1);
            {
                register s32 color = 0xB4;
                if (idx == 0) {
                    object->color[2] = color;
                } else {
                    object->color[0] = color;
                }
                object->color[1] = color;
            }
            return object;
        }
    }
    return NULL;
}



