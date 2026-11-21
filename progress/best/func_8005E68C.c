void *spawnEffectObject(s32, void *, s32);
s32 func_80017490(void *arg0, u16, u16, u16);
s32 func_8001751C(s32, u8, void *, s32);
s32 actorLinkToSurface(s32, void *, s32);
s32 objectSetAnimFrame(void *, s32, int);
extern s16 D_800C4478;
extern s16 D_800C447A;
extern s16 D_800C4706;
extern s16 D_800C4708;
extern s32 *gProbeObjectList;

typedef struct { unsigned char pad_0[12]; int field_C; int field_10; int field_14; unsigned char pad_18[4]; float field_1C; unsigned char pad_20[4]; unsigned short field_24; unsigned short field_26; unsigned short field_28; unsigned short field_2A; unsigned char pad_2C[1]; signed char field_2D; signed char field_2E; signed char field_2F; short field_30; } __repair_record_temp_s0;
void *func_8005E68C(void *arg0, s32 arg1, u16 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, s32 arg10, u16 arg11, s32 arg12, u8 arg13) {
    u16 sp1E;
    unsigned int flags;
    void *temp_s0;
    register u16 sp16;
    s32 off;
    u16 sp26;
    register void *temp_v0;
    u16 a11;

    flags = arg10;
    a11 = arg11;
    sp16 = arg2;
    sp26 = arg6;
    sp1E = arg4;
    func_8001751C(arg12, arg13, arg0, arg1);
    if ((func_80017490(arg0, arg7, arg8, arg9) << 24) != 0) {
        temp_v0 = (void *) spawnEffectObject(0x34, arg0, arg1);
        if (temp_v0 != NULL) {
            temp_s0 = *(void **)((u8 *)temp_v0 + 0x6C);
            *(s16 *)((u8 *)temp_v0 + 0x78) = 0x24;
            *(s16 *)((u8 *)temp_v0 + 0x7A) = 0;
            { struct V { s32 x,y,z; }; *(struct V *)temp_s0 = *(struct V *)arg0; }
            ((__repair_record_temp_s0*)temp_s0)->field_C = 0;
            ((__repair_record_temp_s0*)temp_s0)->field_10 = 0;
            ((__repair_record_temp_s0*)temp_s0)->field_14 = 0;
            ((__repair_record_temp_s0*)temp_s0)->field_24 = a11;
            ((__repair_record_temp_s0*)temp_s0)->field_2F = 1;
            if (flags & 2) {
                ((__repair_record_temp_s0*)temp_s0)->field_2D = 1;
            } else {
                ((__repair_record_temp_s0*)temp_s0)->field_2D = 0;
            }
            if (flags & 1) {
                switch (arg4) {
                case 0:
                    off = arg5 * 0xE8;
                    objectSetAnimFrame(temp_v0, *(s16 *)((u8 *)&D_800C4706 + off), *(s16 *)((u8 *)&D_800C4708 + off));
                    break;
                case 1:
                    off = arg5 * 0x10;
                    objectSetAnimFrame(temp_v0, *(s16 *)((u8 *)&D_800C4478 + off), *(s16 *)((u8 *)&D_800C447A + off));
                    break;
                case 2:
                    objectSetAnimFrame(temp_v0, sp16, arg3 & 0xFFFF);
                    break;
                }
            } else {
                objectSetAnimFrame(temp_v0, sp16, arg3 & 0xFFFF);
            }
            ((__repair_record_temp_s0*)temp_s0)->field_26 = arg4;
            ((__repair_record_temp_s0*)temp_s0)->field_28 = arg5;
            ((__repair_record_temp_s0*)temp_s0)->field_2A = sp26;
            ((__repair_record_temp_s0*)temp_s0)->field_30 = 0;
            actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
            *(s32 *)((u8 *)temp_v0 + 0x5C) = *(s32 *)((u8 *)temp_v0 + 0x5C) | 0x400;
            *(f32 *)((u8 *)temp_v0 + 0x54) = 0.015625f;
            ((__repair_record_temp_s0*)temp_s0)->field_1C = *(f32 *)((u8 *)temp_v0 + 0x28) - 1.0f;
            if ((((u32) (arg5 - 0x18) < 2U) | (arg5 == 0x17)) != 0) {
                ((__repair_record_temp_s0*)temp_s0)->field_2E = 1;
            } else {
                ((__repair_record_temp_s0*)temp_s0)->field_2E = 0;
            }
            *(s16 *)((u8 *)temp_v0 + 0x7A) = 2;
        }
        return temp_v0;
    }
    return NULL;
}
