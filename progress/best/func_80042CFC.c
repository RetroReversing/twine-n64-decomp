extern s32 D_54D910;
extern s32 D_800C0784[];
extern u8 D_800CA338[];
extern s32 func_80083E24(void);
extern s32 func_80083E90(s32, s32);
extern s32 func_8000B9B8(void *, s32, s32);
void func_80042CFC(s32 arg0, s32 arg1) {
    s32 *fp;
    s32 v;
    s32 a;
    s32 frame[0x40];
    func_80083E24();
    fp = (s32 *)D_800C0784[arg1];
    v = *fp;
    if (D_800CA338[0]) { }
    a = func_80083E90(fp[1] * 68, 0x2D);
    func_8000B9B8((void *)(D_54D910 + v), a, fp[1] * 68);
}
