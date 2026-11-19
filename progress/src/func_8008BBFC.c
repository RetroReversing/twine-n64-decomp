void func_8008B824(s32 *, u16, u16, s32);
void func_8008C08C(void);
s32 osAiSetFrequency(s32);
extern s32 D_800E41D4;

s32 func_8008BBFC(s32 *arg0, u16 arg1, u16 arg2, s32 arg3) {
    s32 v;

    func_8008C08C();
    v = osAiSetFrequency(*arg0);
    D_800E41D4 = v;
    *arg0 = v;
    if (arg3 & 0x10000) {
        v = 2;
    } else if (arg3 & 0x20000) {
        v = 3;
    } else if (arg3 & 0x40000) {
        v = 4;
    } else if (arg3 & 0x80000) {
        v = 0;
    } else {
        v = 1;
    }
    func_8008B824(arg0, arg1, arg2, v);
    return 0;
}
