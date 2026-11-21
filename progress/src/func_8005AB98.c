typedef struct {
    f32 x, y, z;
    u8 mode;
} SpawnParams;

typedef struct {
    u8 pad0[0x14];
    f32 scale;
    u8 pad18[0x2D];
    u8 type;
} SpawnOwner;

typedef struct {
    u8 pad0[0x5C];
    u32 flags;
    u8 pad60[4];
    f32 scale;
    u8 pad68[4];
    SpawnParams *params;
    SpawnOwner *owner;
    u8 pad74[4];
    s16 kind;
    u8 pad7A[4];
    u8 type;
} SpawnObject;

extern SpawnObject *spawnEffectObject(s32 kind, s32 arg, SpawnParams *position);
extern void actorLinkToSurface(s32 arg, SpawnObject *object, s32 mode);
extern s32 *gProbeObjectList;

SpawnObject *func_8005AB98(s32 arg0, SpawnParams *position, SpawnOwner *owner,
                          u8 axes, s32 arg4, u8 mode)
{
    SpawnObject *object = spawnEffectObject(0x10, arg0, position);
    if (object != NULL) {
        SpawnParams *params = object->params;
        object->kind = 0xC;
        params->mode = mode;
        if (axes & 1) {
            params->x = position->x;
        } else {
            params->x = 0.0f;
        }
        if (axes & 2) {
            params->y = position->y;
        } else {
            params->y = 0.0f;
        }
        if (axes & 4) {
            params->z = position->z;
        } else {
            params->z = 0.0f;
        }
        if (owner != NULL) {
            object->owner = owner;
            object->type = owner->type;
            object->scale = owner->scale;
        }
        object->flags |= 0x600;
        actorLinkToSurface(*gProbeObjectList, object, 0);
    }
    return object;
}
