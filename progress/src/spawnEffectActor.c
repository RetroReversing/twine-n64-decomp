typedef struct {
    char pad00[0xC];
    u16 field0C, field0E, field10;
    s16 field12, field14;
    u16 field16;
    s16 type, field1A;
} ActorInit862BC;

typedef struct {
    s32 state;
    f32 first, second, lower, upper;
    u16 field14;
    u8 field16, field17, field18, field19, field1A;
} ActorData862BC;

typedef struct {
    char pad00[0x6C];
    ActorData862BC *data;
    char pad70[8];
    s16 type;
} Actor862BC;

extern Actor862BC *spawnEffectObject(s32, s32, s32);
extern f64 D_800D63E8;

/* Spawns an effect actor (type 0x1C) from an init record, picks its sub-type and seeds its range and lifetime fields. */ Actor862BC *spawnEffectActor(s32 objectParam, ActorInit862BC *init) {
    Actor862BC *actor;
    ActorData862BC *data;
    s16 type;
    u16 lifetime;
    actor = spawnEffectObject(0x1C, objectParam, 0);
    if (actor != NULL) {
        type = init->type;
        data = actor->data;
        switch (type) {
            case 0: actor->type = 0xE; break;
            case 1: actor->type = 0xF; break;
            case 2: actor->type = 0x57; break;
        }
        data->field18 = 0;
        data->field14 = init->field0C;
        data->field16 = init->field0E;
        data->field17 = init->field10;
        data->lower = init->field14;
        data->upper = init->field12;
        lifetime = init->field16;
        data->state = -1;
        data->field19 = lifetime;
        if (init->field1A == 0) {
            data->field1A = 1;
        } else {
            data->field1A = 0;
        }
        {
            f32 farDistance = 1000.0f;
            data->first = farDistance;
            data->second = farDistance;
        }
        if (data->field19 == 0) {
            data->field19 = 0xFF;
        }
        if (data->lower == data->upper) {
            data->upper = data->lower + D_800D63E8;
            if (data->upper == 0.0f) {
                data->upper = 10.0f;
            }
        }
        return actor;
    }
    return NULL;
}
