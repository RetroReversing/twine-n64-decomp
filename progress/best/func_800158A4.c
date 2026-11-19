extern u16 D_800B35B0;
s32 func_8004E6E4(void *, void *, f32 *, f32 *, f32 *, f32, s32, s32, s32);
s32 func_8004F990(void *, f32 *, f32 *, s32, f32 *, s32, s32, s32);
f32 func_80045540(f32 *, f32 *);
f32 func_80045764(f32 *, f32 *, void *);
void *func_80047B44(void *, f32 *, f32 *, f32 *);
extern void *func_8004D910;

s32 func_800158A4(void *arg0, void *arg1, void *arg2, void *arg3, s32 *arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    f32 sp28[3];
    f32 sp38[3];
    f32 sp48[3];
    f32 sp58[3];
    f32 sp68[3];
    f32 sp78[3];
    f32 fs0;
    s32 result;
    void *s1;
    void *a2;
    s32 s0;

    a2 = arg2;
    s1 = arg2;
    s0 = 0;
    D_800B35B0 += 1;
    sp48[0] = ((f32 *)arg0)[0];
    sp48[1] = ((f32 *)arg0)[1];
    sp48[2] = ((f32 *)arg0)[2];
    sp58[0] = ((f32 *)arg1)[0];
    sp58[1] = ((f32 *)arg1)[1];
    sp58[2] = ((f32 *)arg1)[2];
    sp38[0] = 0.0f;
    if (s1 == NULL) {
        ((f32 *)arg3)[0] = ((f32 *)arg0)[0];
        ((f32 *)arg3)[1] = ((f32 *)arg0)[1];
        ((f32 *)arg3)[2] = ((f32 *)arg0)[2];
        return 0;
    }
    return 0;
}
