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

extern void func_8000A270(s32);
extern OverlayObject *func_80016410(s32, OverlayPosition *, void *);
extern void func_8002B000(void *, s32);
extern void actorLinkToSurface(s32, OverlayObject *, s32);
extern void func_80044670(OverlayObject *, s32, s32);
extern s32 *gProbeObjectList;
extern u8 gSceneType;
extern u32 D_8011F140[][2];
extern u8 D_8011F168[];
extern OverlayObject *D_8011F270[];
extern s32 D_8011F280[], D_8011F290[];
extern OverlayPosition D_8011F298[];

OverlayObject *func_8011C16C(register OverlayPosition *position, void *orientation, u32 index)
{
    register u8 *state = &gSceneType;

    if ((u32)(*state - 2) < 2U) {
        OverlayObject *object = func_80016410(0, position, orientation);
        if (object != NULL) {
            register u32 idx = (u16)index;
            register void *timer;
            do { func_80044670(object, 6, 0xF4); } while (0);
            D_8011F298[idx] = *position;
            timer = D_8011F140[idx];
            object->kind = 0x45;
            object->index = index;
            object->scale = 1.0f;
            D_8011F270[idx] = object;
            D_8011F168[idx] = 1;
            D_8011F280[idx] = 0;
            func_8002B000(timer, 0x1E);
            func_8000A270(D_8011F290[idx]);
            D_8011F290[idx] = 0;
            object->flags &= ~0x200;
            if (*state == 3) {
                D_8011F298[idx].y += 0.76f;
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



