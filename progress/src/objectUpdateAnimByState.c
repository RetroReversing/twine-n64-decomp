#define OBJ_FIELD(p, t, o) (*(t *)((u8 *)(p) + (o)))
void objectSetAnimFrame(void *obj, s32 animSet, s32 frame);

/* Picks the animation frame and the speed/offset fields of an object from its state and its parent's type. */
void objectUpdateAnimByState(void *obj) {
    void *parent;
    void *target;
    s32 mode;

    if (obj == NULL) {
        return;
    }
    parent = OBJ_FIELD(obj, void *, 0x6c);
    if (parent == NULL) {
        return;
    }
    if (OBJ_FIELD(obj, u16, 0x78) == 0x55) {
        switch (OBJ_FIELD(parent, u16, 0x3c)) {
        case 0:
            objectSetAnimFrame(obj, 2, 0x149);
            break;
        case 2:
            objectSetAnimFrame(obj, 0, 0x149);
            break;
        default:
            objectSetAnimFrame(obj, 1, 0x149);
        }
        OBJ_FIELD(obj, f32, 0x54) = 0.015625f;
        target = OBJ_FIELD(obj, void *, 0x70);
        OBJ_FIELD(obj, f32, 0x28) = OBJ_FIELD(parent, f32, 0x34) - OBJ_FIELD(target, f32, 0x20);
    } else {
        mode = OBJ_FIELD(obj, s16, 0x7a);
        OBJ_FIELD(obj, f32, 0x54) = 1.0f;
        switch (mode) {
        case 0:
        case 4:
            OBJ_FIELD(obj, f32, 0x28) = OBJ_FIELD(parent, f32, 8);
        case 1:
            switch (OBJ_FIELD(parent, u16, 0x3c)) {
            case 0:
                objectSetAnimFrame(obj, 7, 0x141);
                break;
            case 2:
                objectSetAnimFrame(obj, 3, 0x141);
                break;
            default:
                objectSetAnimFrame(obj, 5, 0x141);
            }
            break;
        case 2:
            switch (OBJ_FIELD(parent, u16, 0x3c)) {
            case 0:
                objectSetAnimFrame(obj, 8, 0x141);
                break;
            case 2:
                objectSetAnimFrame(obj, 4, 0x141);
                break;
            default:
                objectSetAnimFrame(obj, 6, 0x141);
            }
            break;
        default:
            switch (OBJ_FIELD(parent, u16, 0x3c)) {
            case 0:
                objectSetAnimFrame(obj, 2, 0x149);
                break;
            case 2:
                objectSetAnimFrame(obj, 0, 0x149);
                break;
            default:
                objectSetAnimFrame(obj, 1, 0x149);
            }
            OBJ_FIELD(obj, f32, 0x54) = 0.015625f;
            target = OBJ_FIELD(obj, void *, 0x70);
            if (target) {
                OBJ_FIELD(obj, f32, 0x28) = OBJ_FIELD(parent, f32, 0x34) - OBJ_FIELD(target, f32, 0x20);
            } else {
                OBJ_FIELD(obj, f32, 0x28) = OBJ_FIELD(parent, f32, 0x34);
            }
        }
    }
}
