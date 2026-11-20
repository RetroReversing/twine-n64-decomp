extern s32 func_80079CB4(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void *D_800B2710;
void func_8000CCE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *obj;
    u32 kind, match;
    obj = *(char **)((u8 *)D_800B2710 + arg0 * 0xD4 + 0x68);
    kind = *(u8 *)(*(char * volatile *)(obj + 0x68) + 0xB1);
    func_80079CB4(obj + 0x24, obj + 0x3C, 0, 0, 0, 0x64, 0x64, 0x64, arg1, 0,
        *(u8 *)(*(char * volatile *)(obj + 0x68) + 0xB1), arg2, (0 - ((kind ^ 0x33) < 1)) & 3, 0, arg3, 0);
}
