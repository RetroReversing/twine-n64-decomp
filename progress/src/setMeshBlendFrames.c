void loadMeshFrame(s32, s32, s32, s32);
void func_80005F5C(void *);
extern s32 gDefaultMeshFrame;

typedef struct { s32 flags; u8 pad4[0x3C]; s32 a40; s32 a44; u8 pad48[0x36]; s16 h7E; s16 h80; } Sub600C;

/* Loads the two mesh frames for an animated entity, records the current frames, then recomputes the mesh position delta. */ void setMeshBlendFrames(void *entity, s32 frameA, s32 frameB, s32 frameC) {
    u8 *anim = *(u8 **)((u8 *)entity + 0x68);
    Sub600C *state = (Sub600C *)(anim + 0x14);

    if (state->flags & 0x4000) {
        *(s16 *)(anim + 0x90) = frameB;
    } else {
        *(s16 *)(anim + 0x90) = gDefaultMeshFrame;
    }
    state->h7E = frameA;
    state->h80 = frameB;
    loadMeshFrame(state->a40, frameA, frameB, state->flags & 1);
    loadMeshFrame(state->a44, frameA, frameC, state->flags & 1);
    func_80005F5C(entity);
}
