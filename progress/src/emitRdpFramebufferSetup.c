typedef s32 M2C_UNK;
s32 osVirtualToPhysical(s32);
extern s32 gFramebuffers[];
extern s16 gScreenHeight;
extern s16 D_8010A4B0;
extern s32 D_8010A4E8;
extern s32 gFogColorOverrideEnabled[];
extern s16 gScreenWidth;
extern void *D_80115328;

typedef struct { int field_0; int field_4; int field_8; int field_C; int field_10; int field_14; int field_18; int field_1C; } __repair_record_temp_s0;
/* Appends RDP display list commands that set the color framebuffer and scissor to the full screen. */ void emitRdpFramebufferSetup(void) {
    s32 maxX;
    s32 maxY;
    s32 colorImageSize;
    void *temp_a1;
    void *temp_s0;
    s32 framebufferPhys;

    temp_s0 = D_80115328;
    D_80115328 = temp_s0 + 8;
    ((__repair_record_temp_s0*)temp_s0)->field_0 = 0xE7000000;
    D_80115328 = temp_s0 + 0x10;
    ((__repair_record_temp_s0*)temp_s0)->field_C = 0x300000;
    ((__repair_record_temp_s0*)temp_s0)->field_8 = 0xE3000A01;
    D_80115328 = temp_s0 + 0x18;
    ((__repair_record_temp_s0*)temp_s0)->field_4 = 0;
    ((__repair_record_temp_s0*)temp_s0)->field_10 = 0xE200001C;
    ((__repair_record_temp_s0*)temp_s0)->field_14 = 0x0F0A4000;
    maxX = gScreenWidth - 1;
    maxY = gScreenHeight - 1;
    colorImageSize = 2;
    if (gFogColorOverrideEnabled[0] != 0) {
        colorImageSize = (-(D_8010A4E8 == 0) & 3) | 2;
    }
    ((__repair_record_temp_s0*)temp_s0)->field_18 = 0xFF000000 | (colorImageSize << 0x13) | (maxX & 0xFFF);
    D_80115328 = temp_s0 + 0x20;
    framebufferPhys = osVirtualToPhysical(gFramebuffers[D_8010A4B0]);
    temp_a1 = D_80115328;
    ((__repair_record_temp_s0*)temp_s0)->field_1C = framebufferPhys;
    D_80115328 = temp_a1 + 8;
    *(s32 *)((char *)temp_a1 + 0) = 0xF7000000;
    D_80115328 = temp_a1 + 0x10;
    *(s32 *)((char *)temp_a1 + 4) = 0;
    *(s32 *)((char *)temp_a1 + 8) = 0xF6000000 | (maxX & 0x3FF) << 0xE | (maxY & 0x3FF) * 4;
    *(s32 *)((char *)temp_a1 + 0xC) = 0;
}
