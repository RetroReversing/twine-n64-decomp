/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80002EF0(void *);                      /* extern */
s32 func_800645A4(u32);                             /* extern */
s32 updateSwayMotion(void *);                      /* extern */
s32 func_80070870(void *);                      /* extern */

/* Clears an actor's motion state tables and flags, then re-initialises sway motion. */ void resetActorMotionState(void *actor) {
    u32 i;
    
    void *state;
    void *sub;
    void *rowPtr;
    void *clearPtr;

    state = (*(void **)((char *)(actor) + 0x6C));
    i = 0;
    clearPtr = state;
    do {
        (*(s16 *)((char *)(clearPtr) + 0x1BC)) = 0;
        i += 1;
        clearPtr += 2;
    } while (i < 0x20U);
    i = 0;
    rowPtr = state;
    __repair_rows: {
        (*(s8 *)((char *)(rowPtr) + 0x1FC)) = 0;
        (*(s8 *)((char *)(rowPtr) + 0x1FF)) = 0;
        (*(s8 *)((char *)(rowPtr) + 0x1FD)) = 0;
        (*(s8 *)((char *)(rowPtr) + 0x1FE)) = 0;
        (*(f32 *)((char *)(rowPtr) + 0x200)) = (f32) (func_800645A4(i) & 0xFF);
        rowPtr += 8;
        i += 1;
    }
if (0x21U > i) goto __repair_rows;
    (*(s8 *)((char *)(state) + 0x1FC)) = 1;
    (*(s8 *)((char *)(state) + 0x32C)) = 0;
    (*(s8 *)((char *)(state) + 0x324)) = 0;
    sub = (*(void **)((char *)(actor) + 0x68));
    (*(s8 *)((char *)(sub) + 0xE)) = 0;
    (*(s8 *)((char *)(sub) + 0x10)) = 0;
    (*(s8 *)((char *)(sub) + 0xF)) = 0;
    func_80070870(actor);
    (*(s16 *)((char *)((*(void **)((char *)(state) + 0xA8))) + 0x7A)) = 0;
    updateSwayMotion(actor);
    func_80002EF0((*(void **)((char *)(state) + 0xA8)));
}
