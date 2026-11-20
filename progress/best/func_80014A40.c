s32 func_800458C0(void *, s32 *, f32 *, f32 *);
extern volatile s32 D_800D2528[3];
void func_80014A40(void *arg0, void *arg1) {
    f32 sp20[3]; s32 sp10[3]; f32 sp38[3]; f32 sp44[3]; f32 sp2C[3];
    volatile s32 *p = D_800D2528;
    sp10[0] = p[0]; sp10[1] = p[1]; sp10[2] = p[2];
    sp20[0] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 0)) / (*(f32 *)((char *)arg1 + 0x68));
    sp20[1] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 8)) / (*(f32 *)((char *)arg1 + 0x6C));
    sp20[2] = 1.0f;
    sp2C[0] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 4)) / (*(f32 *)((char *)arg1 + 0x68));
    sp2C[1] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 8)) / (*(f32 *)((char *)arg1 + 0x6C));
    sp2C[2] = 1.0f;
    sp38[0] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 0)) / (*(f32 *)((char *)arg1 + 0x68));
    sp38[1] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 0xC)) / (*(f32 *)((char *)arg1 + 0x6C));
    sp38[2] = 1.0f;
    sp44[0] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 4)) / (*(f32 *)((char *)arg1 + 0x68));
    sp44[1] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 0xC)) / (*(f32 *)((char *)arg1 + 0x6C));
    sp44[2] = 1.0f;
    func_800458C0((*(void **)((char *)arg0 + 0x20)) + 0x10, sp10, sp20, sp2C);
    func_800458C0((*(void **)((char *)arg0 + 0x20)) + 0x20, sp10, sp38, sp44);
    func_800458C0((*(void **)((char *)arg0 + 0x20)) + 0x30, sp10, sp20, sp38);
    func_800458C0((*(void **)((char *)arg0 + 0x20)) + 0x40, sp10, sp2C, sp44);
}
