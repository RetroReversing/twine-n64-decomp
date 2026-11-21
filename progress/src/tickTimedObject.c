typedef struct {
    u8 pad0[8];
    s32 nodeChain;
    u8 pad1[0x50];
    s32 flags;
    s32 stateFlags;
    f32 radius;
    u8 pad2[8];
    void *animSource;
    f32 timer;
} TimedObject;

s32 objectSetAnimFrame(void *, s32, u32);
s32 freeNodeChain(s32);
s32 func_80054FEC(s32, f32, f32, void *, s32, s32, s32);
s32 func_800624A8(void *, s32, f32, s32);

/* Counts down a timed object's timer by dt; when it expires, frees its node chain, resets its animation and sets the expired flag. */
void tickTimedObject(TimedObject *obj, s32 arg1, f32 dt, s32 arg3) {
    f32 temp_fv0;
    u32 temp_a2;

    if (obj->flags & 0x300000) {
        temp_fv0 = obj->timer - dt;
        obj->timer = temp_fv0;
        if (temp_fv0 < 0.0f) {
            freeNodeChain(obj->nodeChain);
            if (obj->flags & 0x100000) {
                obj->stateFlags = (s32) (obj->stateFlags | 1);
            } else {
                temp_a2 = ((u32 *)obj->animSource)[0xC];
                objectSetAnimFrame(obj, ((temp_a2 >> 4) & 0xFFFF) + 1, temp_a2 >> 0x14);
            }
            obj->flags = (s32) ((obj->flags & 0xFFCFFFFF) | 0x200);
            func_800624A8(obj, arg1, 0.5f, 1);
            func_80054FEC(0, 250.0f, (2.0f * obj->radius) + 4.0f, obj, arg1, 0x20, arg3);
        }
    }
}
