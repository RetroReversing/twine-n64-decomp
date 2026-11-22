typedef struct { s32 x, y, z; } EffectVec;
extern void func_80076340(void *, s32, f32);
extern void func_80087380(void *);
extern void effectSetAnimFrame(void *, s32, s32);
extern void *spawnEffectObject(s32, s32, s32);
extern u8 D_800B21CF, D_800B241F;
#define FIELD(type, ptr, off) (*(type *)((ptr) + (off)))
void *func_80087580(EffectVec *pos, EffectVec *rot, char *params, char *path, s32 id)
{
    char *obj = spawnEffectObject(0x4C, 0, 0);
    char *state;
    s16 childType;
    char *child;
    unsigned i;
    if (obj != NULL) {
        state = FIELD(char *, obj, 0x6C);
        FIELD(u8, state, 0x44) = FIELD(u16, params, 0x2C);
        FIELD(u8, state, 0x45) = FIELD(u16, params, 0x2E);
        FIELD(u8, state, 0x46) = FIELD(u16, params, 0x30);
        FIELD(u8, state, 0x47) = FIELD(u16, params, 0x32);
        FIELD(u8, state, 0x48) = FIELD(u16, params, 0x34);
        FIELD(u8, state, 0x49) = FIELD(u16, params, 0x36);
        FIELD(u8, state, 0x4A) = FIELD(u16, params, 0x38);
        FIELD(char *, state, 0x1C) = path;
        FIELD(u8, state, 0x4B) = FIELD(u16, params, 0x40);
        if (path != NULL) {
            FIELD(s16, state, 0x28) = id;
            FIELD(s16, state, 0x2A) = 0;
            FIELD(s32, state, 0x20) = 0;
            FIELD(f32, state, 0x24) = 0.01f;
            func_80076340(state + 0x1C, 1, 2.1f);
            FIELD(EffectVec, obj, 0x30) = FIELD(EffectVec, FIELD(char *, state, 0x1C), 0);
            FIELD(EffectVec, obj, 0x24) = FIELD(EffectVec, obj, 0x30);
            FIELD(EffectVec, obj, 0x48) = FIELD(EffectVec, FIELD(char *, state, 0x1C), 0xC);
        } else {
            FIELD(EffectVec, obj, 0x30) = *pos;
            FIELD(EffectVec, obj, 0x24) = FIELD(EffectVec, obj, 0x30);
            FIELD(EffectVec, obj, 0x48) = *rot;
        }
        FIELD(EffectVec, obj, 0x3C) = FIELD(EffectVec, obj, 0x48);
        FIELD(s16, obj, 0x78) = 0x3B;
        FIELD(s16, obj, 0x7A) = 0;
        FIELD(s16, obj, 0x7C) = 0;
        effectSetAnimFrame(obj, FIELD(u16, params, 0), *FIELD(s16 *, params, 0x28));
        i = 0;
        childType = 0x30;
        FIELD(s32, obj, 0x5C) |= 0x600;
        FIELD(s32, obj, 0x58) |= 0x20000;
        path = state;
        do {
            child = spawnEffectObject(0, 0, 0);
            FIELD(char *, path, 0x2C) = child;
            if (child != NULL) {
                FIELD(char *, child, 0x18) = obj;
                FIELD(s16, child, 0x78) = childType;
                FIELD(s32, child, 0x5C) |= 0x600;
                effectSetAnimFrame(child, 3, *FIELD(s16 *, params, 0x28));
            }
            i++;
            path += 4;
        } while (i < 6);
        func_80087380(obj);
        FIELD(s16, state, 0x14) = 0x1EF;
        FIELD(u8, state, 0x19) = 0xFF;
        FIELD(u8, state, 0x18) = 0;
        FIELD(u8, state, 0x16) = 0;
        FIELD(u8, state, 0x17) = 0;
        FIELD(u8, state, 0x1A) = 1;
        FIELD(f32, state, 0xC) = D_800B21CF;
        FIELD(f32, state, 0x10) = D_800B241F;
        FIELD(s32, state, 0) = -1;
        FIELD(f32, state, 4) = 1000.0f;
        FIELD(f32, state, 8) = 1000.0f;
    }
    return obj;
}
