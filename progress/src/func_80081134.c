/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80016410();
s32 func_80017490();
s32 actorLinkToSurface();
s32 func_80045CF8();
extern s32 *D_800CA31C;

void *func_80081134(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, u8 arg13, s32 arg14) {
    void *var_s0;
    void *temp_v0;
    register s32 *list;
    register u8 color;

    var_s0 = NULL;
    if ((func_80017490(arg5, (s32)arg6, arg7) << 0x18) != 0) {
        var_s0 = func_80016410(0x1C, arg0, (u32)arg1);
        if ((color = 0x64, var_s0) != NULL) {
            temp_v0 = (*(void **)((char *)(var_s0) + 0x6C));
            (*(s16 *)((char *)(var_s0) + 0x78)) = 0x2B;
            (*(s8 *)((char *)(temp_v0) + 0x15)) = 0;
            (*(s8 *)((char *)(temp_v0) + 0x17)) = color;
            (*(s8 *)((char *)(temp_v0) + 0x18)) = color;
            (*(s8 *)((char *)(temp_v0) + 0x19)) = color;
            (*(s8 *)((char *)(temp_v0) + 0x14)) = (s8) arg10;
            (*(u8 *)((char *)(temp_v0) + 0x16)) = (unsigned)arg13;
            (*(s8 *)((char *)(temp_v0) + 0x1A)) = (s8) arg14;
            list = D_800CA31C;
            (*(s32 *)((char *)(temp_v0) + 0)) = 0;
            (*(s32 *)((char *)(temp_v0) + 4)) = 0;
            (*(s16 *)((char *)(temp_v0) + 0xE)) = (s16) arg4;
            (*(u16 *)((char *)(temp_v0) + 8)) = (arg8 & 0xFFFF);
            (*(u16 *)((char *)(temp_v0) + 0xA)) = (arg9 & 0xFFFF);
            (*(s16 *)((char *)(temp_v0) + 0xC)) = (s16) (unsigned)arg11;
            (*(s16 *)((char *)(temp_v0) + 0x12)) = (s16) arg12;
            (*(s16 *)((char *)(temp_v0) + 0x10)) = 0;
            actorLinkToSurface(*list, var_s0, 1);
            (*(s16 *)((char *)(var_s0) + 0x7A)) = 0;
            (*(s16 *)((char *)(var_s0) + 0x7C)) = (s16) (func_80045CF8(0x78) + 1);
        }
    }
    return var_s0;
}
