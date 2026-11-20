/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void func_800846A0(void);
extern s16 D_800C9BA8;

void func_80077B58(void *arg0) {
    s32 temp_a1;
    void *temp_s0;

    temp_s0 = (*(void **)((char *)(arg0) + 0x6C));
    temp_a1 = (*(s32 *)((char *)(temp_s0) + 0x88));
    if (((((*(s32 *)((char *)(temp_s0) + 0x88))) & 0x60000000) == 0x20000000) && ((temp_a1 & 0x01E00000) == 0x200000) && ((*(f32 *)((char *)(arg0) + 0x74)) > 0.0f)) {
        if (D_800C9BA8 == 0) {
            func_800846A0();
            D_800C9BA8 = 0xF;
        }
        (*(s32 *)((char *)(temp_s0) + 0x88)) &= 0xBFFFFFFF;
        (*(s32 *)((char *)(temp_s0) + 0x88)) &= 0xDFFFFFFF;
    }
}
