extern u8 gWorkerActive;
extern s32 D_80103098;
s32 func_80095A54(void) {
    if (gWorkerActive != 0) return (s32)&D_80103098;
    return 0;
}
