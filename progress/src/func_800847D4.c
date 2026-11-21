typedef struct { u8 pad0[0x14]; s32 flags; } Sub847D4;
typedef struct { u8 pad0[0x24]; u8 pos[0x44]; Sub847D4 *sub; } Obj847D4;

void playDistanceSound(u16, f32, s32);
s32 randomIntBelow(s32);
f32 findNearestTrackMarker(void *, s32 *);
extern u16 D_800CE63C[];
extern u16 D_800CE640[];
extern s32 gGameMode;

void func_800847D4(s32 arg0, Obj847D4 *arg1) {
    s32 sp10;
    f32 vol;
    u16 id;

    vol = findNearestTrackMarker(arg1->pos, &sp10);
    switch (gGameMode) {
    case 2:
        id = 0x176;
        if (!(arg1->sub->flags & 0x200000)) {
            goto rnd;
        }
        goto play;
    case 20:
    case 34:
        id = 0x139;
        if (!(arg1->sub->flags & 0x200000)) {
            id = D_800CE63C[randomIntBelow(2)];
        }
        goto play;
    case 28:
        if (arg1->sub->flags & 0x200000) {
            id = 0x176;
        } else {
            id = D_800CE640[randomIntBelow(2)];
        }
        goto play;
    case 29:
        id = 0x176;
        if (!(arg1->sub->flags & 0x200000)) {
        rnd:
            id = D_800CE640[randomIntBelow(2)];
        }
    play:
        playDistanceSound(id, vol, 0xFF);
        break;
    }
}
