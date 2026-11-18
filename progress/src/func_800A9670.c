/* identical to func_8003F210 in PENNY RACERS (matched), with its names changed by decompdecomp */
typedef struct { s32 unk0; s32 unk4; } R8;
typedef struct { s16 unk0; s16 pad2; s32 pad4; R8 *unk8; s32 unkC; } V;
extern s32 D_80000300;
extern u8 D_800D10F0[];
extern s16 D_800D10F2;
extern s32 D_800D10F4;
extern s16 D_800D1122;
extern s32 D_800D1124;
extern V *D_800D1128;
extern u8 *D_800D1150;
extern V *D_800D1154;
extern u8 D_800D11B0[];
extern u8 D_800D1200[];
extern u8 D_800D1160[];
extern s32 vi_apply_context(void);
extern void bzero(void *, s32);

void func_800A9670(void) {
    bzero(D_800D10F0, 0x60);
    D_800D1150 = D_800D10F0;
    D_800D1154 = (V *)(D_800D10F0 + 0x30);
    D_800D1122 = 1;
    D_800D10F2 = 1;
    D_800D1124 = 0x80000000;
    D_800D10F4 = 0x80000000;
    if (D_80000300 == 0) {
        D_800D1128 = (V *)D_800D11B0;
    } else if (D_80000300 == 2) {
        D_800D1128 = (V *)D_800D1200;
    } else {
        D_800D1128 = (V *)D_800D1160;
    }
    D_800D1154->unk0 = 0x20;
    D_800D1154->unkC = D_800D1154->unk8->unk4;
    while (*(volatile u32 *)0xA4400010 >= 0xB) {}
    *(volatile u32 *)0xA4400000 = 0;
    vi_apply_context();
}
