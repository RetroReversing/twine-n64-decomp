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

extern Actor862BC *func_80016410(s32, s32, s32);
extern f64 D_800D63E8;

Actor862BC *func_800862BC(s32 arg0, ActorInit862BC *arg1) {
    Actor862BC *actor;
    ActorData862BC *data;
    s16 type;
    u16 limit;
    actor = func_80016410(0x1C, arg0, 0);
    if (actor != NULL) {
        type = arg1->type;
        data = actor->data;
        switch (type) {
            case 0: actor->type = 0xE; break;
            case 1: actor->type = 0xF; break;
            case 2: actor->type = 0x57; break;
        }
        data->field18 = 0;
        data->field14 = arg1->field0C;
        data->field16 = arg1->field0E;
        data->field17 = arg1->field10;
        data->lower = arg1->field14;
        data->upper = arg1->field12;
        limit = arg1->field16;
        data->state = -1;
        data->field19 = limit;
        if (arg1->field1A == 0) {
            data->field1A = 1;
        } else {
            data->field1A = 0;
        }
        {
            f32 distance = 1000.0f;
            data->first = distance;
            data->second = distance;
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
