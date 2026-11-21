typedef struct { u8 pad[4]; u16 id; u16 busy; u8 pad8[0x14]; s32 o1C; s32 o20; s32 o24; } Bank;
s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_8008F520();
extern u8 gWorkerActive;
extern s16 sSceneGroupStackCount;
extern u8 sSceneGroupStack[];

s32 func_800930F4(s32 id, s32 arg1, s32 arg2, s32 arg3) {
    s32 sub;
    s32 i;
    s32 off;
    Bank *b;
    u8 *e;
    u8 *p1;
    u8 *p2;
    s32 v;
    s32 r;

    if (gWorkerActive != 0) {
        i = 0;
        if (i < sSceneGroupStackCount) {
        id &= 0xFFFF;
        do {
            b = *(Bank **)((i << 2) + sSceneGroupStack);
            if (b->id == id) {
                if (b->busy != 0) {
                    return -1;
                }
                e = (u8 *)b + (b->o24 + 8);
                p2 = (u8 *)b + (b->o1C + 8);
                p1 = (u8 *)b + (b->o20 + 8);
                while ((v = *(u16 *)e) != 0xFFFF) {
                    if (v == (arg1 & 0xFFFF)) {
                        func_8008C0D4(v);
                        r = func_8008F520(p2, p1, e, arg2, arg3);
                        func_8008C11C();
                        return r;
                    }
                    e += 0x84;
                }
                return -1;
                break;
            }
            i++;
        } while (i < sSceneGroupStackCount);
        }
    }
    return -1;
}
