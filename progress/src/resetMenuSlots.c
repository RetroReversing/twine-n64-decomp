typedef struct { s16 a; s16 b; s16 c; s16 d; } Src8;
typedef struct { s32 x; s32 y; u8 pad[0x98]; } Dst160;
void initMenuSlot(s32, s16);
void resetSlotState(s32);
extern s16 D_800E1A80[];
extern Src8 D_8010D434[];
extern Dst160 D_80115108[];

void resetMenuSlots(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        initMenuSlot((u16)i, 0);
        resetSlotState(i);
        D_80115108[i].x = D_8010D434[i].a;
        D_80115108[i].y = D_8010D434[i].b;
        D_800E1A80[i] = 0;
    }
}
