typedef struct { u8 pad[0x58]; u32 flags; } Record36B38;
extern Record36B38 *gVisibleObjects[];
extern u8 gVisibleObjectTotal;
extern s32 gObjectDrawMask;
void actorDrawLit(Record36B38 *, s32, s32, s32);
void func_80036B38(s32 arg0) {
    u32 i;
    for (i = 0; i < gVisibleObjectTotal; i++) {
        Record36B38 *p = gVisibleObjects[i];
        p->flags |= 4;
        actorDrawLit(p, arg0, gObjectDrawMask, 0);
    }
}
