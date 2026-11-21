extern void actorLinkToSurface(s32, void *, s32);
extern s32 func_80017490(u16, u16, u16);
extern void func_8001751C(s32, u8, void *, s32);
extern void effectSetAnimFrame(void *, u16, s16);
extern void *spawnEffectObject(s32, void *, s32);
extern s16 D_800C4478;
extern s16 D_800C447A;
extern s16 D_800C4706;
extern s16 D_800C4708;
extern s32 *gProbeObjectList;

void *func_8005E68C(void *arg0, s32 arg1, u16 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, s32 arg10, u16 arg11, s32 arg12, u8 arg13) {
    u8 *obj;
    u8 *s0;
    s32 off;
    s16 a1, a2;

    func_8001751C(arg12, arg13, arg0, arg1);
    if ((func_80017490(arg7, arg8, arg9) << 24) != 0) {
        obj = spawnEffectObject(0x34, arg0, arg1);
        if (obj != NULL) {
            s0 = *(u8 **)(obj + 0x6C);
            *(s16 *)(obj + 0x78) = 0x24;
            *(s16 *)(obj + 0x7A) = 0;
            *(s32 *)(s0 + 0) = *(s32 *)((u8 *)arg0 + 0);
            *(s32 *)(s0 + 4) = *(s32 *)((u8 *)arg0 + 4);
            *(s32 *)(s0 + 8) = *(s32 *)((u8 *)arg0 + 8);
            *(s32 *)(s0 + 0xC) = 0;
            *(s32 *)(s0 + 0x10) = 0;
            *(s32 *)(s0 + 0x14) = 0;
            *(u16 *)(s0 + 0x24) = arg11;
            *(s8 *)(s0 + 0x2F) = 1;
            if (arg10 & 2) {
                *(s8 *)(s0 + 0x2D) = 1;
            } else {
                *(s8 *)(s0 + 0x2D) = 0;
            }
            if (arg10 & 1) {
                switch (arg4) {
                case 0:
                    off = arg5 * 0xE8;
                    a1 = *(s16 *)((u8 *)&D_800C4706 + off);
                    a2 = *(s16 *)((u8 *)&D_800C4708 + off);
                    goto call;
                case 1:
                    off = arg5 * 0x10;
                    a1 = *(s16 *)((u8 *)&D_800C4478 + off);
                    a2 = *(s16 *)((u8 *)&D_800C447A + off);
                    goto call;
                case 2:
                    goto dflt;
                }
            } else {
dflt:
                a1 = arg2;
                a2 = arg3 & 0xFFFF;
call:
                effectSetAnimFrame(obj, a1, a2);
            }
            *(u16 *)(s0 + 0x26) = arg4;
            *(u16 *)(s0 + 0x28) = arg5;
            *(u16 *)(s0 + 0x2A) = arg6;
            *(s16 *)(s0 + 0x30) = 0;
            actorLinkToSurface(*gProbeObjectList, obj, 1);
            *(s32 *)(obj + 0x5C) |= 0x400;
            *(f32 *)(obj + 0x54) = 0.015625f;
            *(f32 *)(s0 + 0x1C) = *(f32 *)(obj + 0x28) - 1.0f;
            if (((u32)(arg5 - 0x18) < 2U) | (arg5 == 0x17)) {
                *(s8 *)(s0 + 0x2E) = 1;
            } else {
                *(s8 *)(s0 + 0x2E) = 0;
            }
            *(s16 *)(obj + 0x7A) = 2;
        }
        return obj;
    }
    return NULL;
}
