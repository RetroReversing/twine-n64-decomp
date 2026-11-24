/* identical to func_8003F210 in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
typedef struct { s32 unk0; s32 unk4; } R8;
typedef struct { s16 unk0; s16 pad2; s32 pad4; R8 *unk8; s32 unkC; } V;
extern s32 osTvType;
extern u8 viContextBuffer[];
extern s16 D_800D10F2;
extern s32 D_800D10F4;
extern s16 D_800D1122;
extern s32 D_800D1124;
extern V *vi_active_ctx_table;
extern u8 *gViPendingContext;
extern V *gViCurrentContext;
extern u8 D_800D11B0[];
extern u8 D_800D1200[];
extern u8 D_800D1160[];
extern s32 vi_apply_context(void);
extern void bzero(void *, s32);

/* Zeroes the VI context buffer, picks the per-TV-type context table, and resets the VI controller. */ void initViManagerContexts(void) {
    bzero(viContextBuffer, 0x60);
    gViPendingContext = viContextBuffer;
    gViCurrentContext = (V *)(viContextBuffer + 0x30);
    D_800D1122 = 1;
    D_800D10F2 = 1;
    D_800D1124 = 0x80000000;
    D_800D10F4 = 0x80000000;
    if (osTvType == 0) {
        vi_active_ctx_table = (V *)D_800D11B0;
    } else if (osTvType == 2) {
        vi_active_ctx_table = (V *)D_800D1200;
    } else {
        vi_active_ctx_table = (V *)D_800D1160;
    }
    gViCurrentContext->unk0 = 0x20;
    gViCurrentContext->unkC = gViCurrentContext->unk8->unk4;
    while (*(volatile u32 *)0xA4400010 >= 0xB) {}
    *(volatile u32 *)0xA4400000 = 0;
    vi_apply_context();
}
