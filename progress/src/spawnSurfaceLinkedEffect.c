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
extern s32 *gDefaultOrderObj;

/* Spawns an effect object at position, copying the position axes selected by axisMask, takes scale and type from ownerObj when given, and links it to the probe surface. */
SpawnObject *spawnSurfaceLinkedEffect(s32 spawnArg, SpawnParams *position, SpawnOwner *ownerObj,
                          u8 axisMask, s32 arg4, u8 spawnMode)
{
    SpawnObject *object = spawnEffectObject(0x10, spawnArg, position);
    if (object != NULL) {
        SpawnParams *params = object->params;
        object->kind = 0xC;
        params->mode = spawnMode;
        if (axisMask & 1) {
            params->x = position->x;
        } else {
            params->x = 0.0f;
        }
        if (axisMask & 2) {
            params->y = position->y;
        } else {
            params->y = 0.0f;
        }
        if (axisMask & 4) {
            params->z = position->z;
        } else {
            params->z = 0.0f;
        }
        if (ownerObj != NULL) {
            object->owner = ownerObj;
            object->type = ownerObj->type;
            object->scale = ownerObj->scale;
        }
        object->flags |= 0x600;
        actorLinkToSurface(*gDefaultOrderObj, object, 0);
    }
    return object;
}
