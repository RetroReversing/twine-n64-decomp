/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 fillRandomCodeString();
s32 func_8002FBE4();
extern u16 sMenuAnimFlags;
extern u16 sMenuAnimPhase;
extern char sMenuAnimSlots[];
extern u8 gPendingMenuCommand;

/* Per-frame menu animation: advances the frame counter, toggles the phase flag at frame 0x38, refreshes slots on phase 5, and wraps a rotating angle. */ void updateMenuAnimation(void *anim) {
    f32 angle;
    u16 frame;
    s32 slot;
    void *angleObj;
    void *owner;
    void *angleObj2;
    s32 i;

    owner = (*(void **)((char *)(anim) + 0x34));
    if (((*(u8 *)((char *)(owner) + 0x13)) != 0) && (!gPendingMenuCommand) && (sMenuAnimFlags & 1)) {
        func_8002FBE4(owner, anim + 0x40, anim + 0x42);
    }
    frame = (*(u16 *)((char *)(anim) + 0x40)) + 1;
    (*(u16 *)((char *)(anim) + 0x40)) = frame;
    if ((u32) (frame & 0xFFFF) >= 0x38U) {
        (*(u16 *)((char *)(anim) + 0x42)) = (u16) ((*(u16 *)((char *)(anim) + 0x42)) == 0);
        (*(u16 *)((char *)(anim) + 0x40)) = 0U;
    }
    if ((sMenuAnimPhase & 0xFFFF) == 5) {
        i = 0;
        slot = 0 & 0xFFFF;
        do {
            slot = i & 0xFFFF;
            fillRandomCodeString((slot * 0xC) + sMenuAnimSlots, 0xB);
            ++i;
        } while ((u32) (i & 0xFFFF) < 9U);
        sMenuAnimPhase = 0;
    } else {
        ++sMenuAnimPhase;
    }
    angleObj = (*(void **)((char *)(anim) + 0x30));
    if (angleObj != NULL) {
        (*(f32 *)((char *)(angleObj) + 0x40)) += 2.0f;
        angleObj2 = (*(void **)((char *)(anim) + 0x30));
        angle = (*(f32 *)((char *)(angleObj2) + 0x40));
        if (angle > 4095.0f) {
            (*(f32 *)((char *)(angleObj2) + 0x40)) = (f32) (angle - 4095.0f);
        }
    }
}
