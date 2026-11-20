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
extern void func_8003E6EC(s32, OverlayObject *, s32);
extern void func_80044670(OverlayObject *, s32, s32);
extern s32 *D_800CA31C;
extern u8 D_801002A0;
extern u32 D_8011F140[][2];
extern u8 D_8011F168[];
extern OverlayObject *D_8011F270[];
extern s32 D_8011F280[], D_8011F290[];
extern OverlayPosition D_8011F298[];

OverlayObject *func_8011C16C(OverlayPosition *position, void *orientation, u16 index)
{
    u8 *state = &D_801002A0;

    if ((u32)(*state - 2) < 2U) {
        OverlayObject *object = func_80016410(0, position, orientation);
        if (object != NULL) {
            func_80044670(object, 6, 0xF4);
            D_8011F298[index] = *position;
            object->kind = 0x45;
            object->index = index;
            object->scale = 1.0f;
            D_8011F270[index] = object;
            D_8011F168[index] = 1;
            D_8011F280[index] = 0;
            func_8002B000(D_8011F140[index], 0x1E);
            func_8000A270(D_8011F290[index]);
            D_8011F290[index] = 0;
            object->flags &= ~0x200;
            if (*state == 3) {
                D_8011F298[index].y += 0.76f;
            }
            func_8003E6EC(*D_800CA31C, object, 1);
            if (index == 0) {
                object->color[2] = 0xB4;
            } else {
                object->color[0] = 0xB4;
            }
            object->color[1] = 0xB4;
            return object;
        }
    }
    return NULL;
}
