typedef struct { s32 x, y, z; } __V3;
void *func_800166A0();
void func_800169EC(void *, void *);
s32 func_80044710(void *, s32, s32);
f32 approximate_hypot2(f32, f32);
f32 approximateAtan2(f32, f32);
void func_800556DC(void *arg0, s32 *arg1, const f32 *arg2, s32 arg3) {
    volatile f32 sp14;
    volatile f32 sp10;
    volatile f32 sp18;
    void *temp_v0;
    temp_v0 = func_800166A0();
    if (temp_v0 != NULL) {
        (*(s32 *)((char *)(temp_v0) + 0x1C)) = arg3;
        *(__V3 *)((s8 *)temp_v0 + 0x20) = *(__V3 *)arg1;
        func_80044710(temp_v0, 4, 0x1B);
        sp10 = (*(const f32 *)((char *)(arg2) + 0));
        sp14 = (*(const f32 *)((char *)(arg2) + 4));
        sp18 = (*(const f32 *)((char *)(arg2) + 8));
        (*(f32 *)((char *)(temp_v0) + 0x2C)) = (f32) -(approximateAtan2(sp14, approximate_hypot2(arg2[0], arg2[2])) * 651.8986f);
        (*(f32 *)((char *)(temp_v0) + 0x30)) = approximateAtan2(sp10, sp18) * 651.8986f;
        (*(s32 *)((char *)(temp_v0) + 0x34)) = 0;
        func_800169EC(temp_v0, arg0);
        func_80085160(arg1);
    }
}
