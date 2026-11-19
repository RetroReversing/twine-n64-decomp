/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800055CC();
s32 func_80005F5C();
extern s32 D_800D9418;

void func_8000600C(void *arg0, s32 arg1, s16 arg2, s32 arg3) {
    void *temp_v1;
    void *temp_s0;

    temp_v1 = (*(void **)((char *)(arg0) + 0x68));
    temp_s0 = (char *)(temp_v1); temp_s0 += (s32)(0x14);
    if ((*(s32 *)((char *)(temp_v1) + 0x14)) & 0x4000) {
        (*(s16 *)((char *)(temp_v1) + 0x90)) = arg2;
    } else {
        (*(s16 *)((char *)(temp_v1) + 0x90)) = (s16) D_800D9418;
    }
    (*(s16 *)((char *)(temp_s0) + 0x7E)) = arg1;
    (*(s16 *)((char *)(temp_s0) + 0x80)) = arg2;
    func_800055CC((*(s32 *)((char *)(temp_s0) + 0x44)), arg1, arg3, (*(s32 *)((char *)(temp_v1) + 0x14)) & 1);
    func_800055CC((*(s32 *)((char *)(temp_s0) + 0x40)), arg1, (*(s32 *)((char *)(temp_v1) + 0x14)) & 1);
    func_80005F5C(arg0);
}
