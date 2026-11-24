typedef struct { u8 pad[0x58]; u32 flags; } Record36B38;
extern Record36B38 *gVisibleObjects[];
extern u8 gVisibleObjectTotal;
extern s32 gObjectDrawMask;
void actorDrawLit(Record36B38 *, s32, s32, s32);
/* Sets flag 4 on every visible object and draws it lit. */ void drawVisibleObjectsLit(s32 lightArg) {
    u32 i;
    for (i = 0; i < gVisibleObjectTotal; i++) {
        Record36B38 *obj = gVisibleObjects[i];
        obj->flags |= 4;
        actorDrawLit(obj, lightArg, gObjectDrawMask, 0);
    }
}
