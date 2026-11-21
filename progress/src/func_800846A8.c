typedef struct { u8 pad0[0x14]; s32 flags; } Sub846A8;
typedef struct { u8 pad0[0x24]; u8 pos[0x44]; Sub846A8 *sub; } Obj846A8;

void func_8000A8B4(u16, f32, s32);
u32 randomIntBelow(s32);
f32 findNearestTrackMarker(s32, s16 *);
extern u16 D_800CE634[];
extern u16 D_800CE638[];
extern u32 gGameMode;

void func_800846A8(s32 arg0, Obj846A8 *arg1) {
    s16 sp10;
    f32 vol;
    u16 id;

    vol = findNearestTrackMarker((s32)arg1->pos, &sp10);
    switch (gGameMode) {
    case 2:
        id = 0x179;
        if (!(arg1->sub->flags & 0x200000)) {
            goto rnd;
        }
        goto play;
    case 34:
        id = 0x13E;
        if (!(arg1->sub->flags & 0x200000)) {
            id = D_800CE634[randomIntBelow(2)];
        }
        goto play;
    case 28:
        if (arg1->sub->flags & 0x200000) {
            id = 0x179;
        } else {
            id = D_800CE638[randomIntBelow(2)];
        }
        goto play;
    case 29:
        id = 0x179;
        if (!(arg1->sub->flags & 0x200000)) {
        rnd:
            id = D_800CE638[randomIntBelow(2)];
        }
    play:
        func_8000A8B4(id, vol, 0xFF);
        break;
    }
}
