extern void *gBorderSkipActive;
extern u8 sOptionCursorIndex;
extern u8 sEnemyDefTable[];
extern u8 D_800C447C[];
void setActionSlot(void *a, s32 b, s32 c, s32 d);
s32 resolveEnemyDefLink(s32 a, s32 b);
void requestEnemyDefChange(void *a, s32 b, s32 c);

/* Picks an enemy definition by the option cursor index, fills the actor's slot data from it, runs an optional hook, then notifies the owner. */ void initOptionCursorActorSlot(void *owner, u8 *actor) {
    s32 s0 = 0;
    u16 s2 = 0;
    u8 *s1;
    u8 *p;
    s32 ret;
    u32 v;
    void (*fn)(void *);

    if (gBorderSkipActive == NULL) {
        return;
    }
    switch (sOptionCursorIndex) {
    case 0:
        s0 = 4;
        break;
    case 1:
        s0 = 5;
        setActionSlot(actor, 0x15, 1, -1);
        break;
    case 2:
        s0 = 6;
        s2 = 0x1A;
        break;
    case 3:
        s0 = 0xF;
        s2 = 0x1A;
        break;
    case 4:
        s0 = 4;
        break;
    case 5:
        s0 = 0x16;
        break;
    case 6:
        s0 = 0x18;
        s2 = 0x1A;
        break;
    case 7:
        s0 = 1;
        break;
    case 8:
        s0 = 0x14;
        break;
    case 9:
        s0 = 5;
        s2 = 0x1A;
        break;
    }
    s1 = sEnemyDefTable + (u16)s0 * 232;
    {
        s32 first = *(u16 *)(s1 + 2);
        s32 id = s0;
        s32 one = 1;
        ret = first << 3; ret = (unsigned int)actor - (0U - (unsigned int)ret); p = (u8 *)(unsigned int)ret;
        first = s0 - first;
        p[0x1FC] = one;
        p[0x1FE] = first;
        ret = resolveEnemyDefLink(id, first);
    }
    ret = (s16)ret * 8;
    ((u8 *)((u32)actor + ret))[0x1FF] = s1[0x82];
    if (sOptionCursorIndex != 3) {
        *(u16 *)(actor + (s1[0x80] << 1) + 0x1BC) = s1[0x82] << 1;
    }
    if (s2 != 0) {
        fn = *(void (**)(void *))(D_800C447C + (s2 << 4));
        if (fn != NULL) {
            fn(owner);
        }
    }
    requestEnemyDefChange(owner, 0, s0);
}

