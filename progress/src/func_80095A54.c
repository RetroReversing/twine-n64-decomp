extern u8 gWorkerThreadActive;
extern s32 D_80103098;
s32 func_80095A54(void) {
    if (gWorkerThreadActive != 0) return (s32)&D_80103098;
    return 0;
}
