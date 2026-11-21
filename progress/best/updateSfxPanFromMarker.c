s32 angleDelta12(s32, s32);
s32 func_8000AA64(void *, s32, s32 *);
void func_8009C9F8(s32, s32);
void func_8009CA5C(s32, s32);
void func_8009CAC0(s32, s32);
extern s32 sDistanceSoundsActive;
extern u8 gOptionChoice;

void updateSfxPanFromMarker(s32 arg0, void *arg1, s32 arg2, f32 arg3) {
    s32 sp10;
    s32 pan;
    s32 a1;
    s32 dist;
    u32 val;
    f32 t;
    u8 *flag;

    if (sDistanceSoundsActive != 0) if (arg0 != -1) {
        func_8000AA64(arg1, arg2, &sp10);
        pan = angleDelta12(sp10, (s32)(*(f32 *)((u8 *)arg1 + 0x38) * 651.8986f)) * 127 / 2048;
        a1 = pan;
        if (pan >= 64) pan = 127 - pan;
        if (pan < -63) pan = -127 - pan;
        pan += 64;
        if (a1 > 0) dist = a1; else dist = -a1;
        flag = &gOptionChoice;
        if (*flag != 0) {
            func_8009CAC0(arg0, pan & 0xFF);
            if (*flag >= 2) {
                func_8009C9F8(arg0, dist & 0xFF);
                goto pitch;
            }
        } else {
            func_8009CAC0(arg0, 0x40);
        }
        func_8009C9F8(arg0, 0);
pitch:
        if (arg3 > 16.0f) arg3 = 16.0f;
        t = arg3 * 512.0f + 8192.0f;
        val = (u32)t;
        func_8009CA5C(arg0, val & 0xFFFF);
    }
}
