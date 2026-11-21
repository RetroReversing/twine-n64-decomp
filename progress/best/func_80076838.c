extern void actorInitFromSpawn(void *, void *, void *);
extern void func_80001D80(s32);
extern void func_8003C710(void *);
extern void func_80047F50(void *, void *);
extern void func_80048794(s32, s32);
extern s32 func_800658C0(void *);
extern void func_80084048(void *, s32, u8 *);
extern void updateSplinePosition(void *, void *);
extern void func_8004844C(void *, f32, f32, f32, f32, f32, f32);
extern u8 D_80100BE0[], gTrackMarkerDone[];
extern s8 D_80103EB0;
extern void *D_80109690, *sBonusObjectTable;
extern s32 gProbeObjectList;
extern u8 gSceneFlagsB, gTrackMarkerActiveMask;
extern volatile u32 gTrackMarkerCount;
extern f32 gTrackMarkerPosTable[][3], gTrackMarkerRotTable[][3];

#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
void func_80076838(void *obj) {
    s16 stage = F(obj,s16,0x7A);
    register void *base;
    void *cursor = F(obj,void *,0x6C);
    void *pos, *rot;
    volatile u32 scratch[2];
    u8 *mask;
    s32 flags;
    u32 i, count;
    u8 first, scene, active;
    u32 offset;

    switch (stage) {
    case 0:
        if (!gTrackMarkerDone[F(cursor,u8,0)]) return;
        if (D_80103EB0) goto load_bonus;
        F(obj,s32,0x60) |= 1;
        return;
found:
        offset = i * 12;
        pos = (u8 *)gTrackMarkerPosTable + offset;
        rot = (u8 *)gTrackMarkerRotTable + offset;
        goto init_bonus;
load_bonus:
        base = sBonusObjectTable;
        D_80103EB0 = 0;
        if (!func_800658C0(base)) return;
        pos = (u8 *)base + 0x24;
        count = gTrackMarkerCount;
        rot = (u8 *)base + 0x3C;
        i = 0;
        if (count != 0) {
            first = F(cursor,u8,0);
again:
            if (D_80100BE0[i] == first) goto found;
            if (++i < count) goto again;
        }
init_bonus:
        actorInitFromSpawn(base,pos,rot);
        func_80001D80(1);
        F(obj,s16,0x7A) = 1;
        return;
    case 1:
        func_80048794(2,gProbeObjectList);
        base = &D_80109690;
        func_8003C710(*(void **)base);
        func_8004844C(*(void **)base,160.0f,120.0f,320.0f,180.0f,0.0f,0.0f);
        func_80047F50(obj,*(void **)base);
        F(D_80109690,s32,0x100) |= 0x10;
        mask = &gTrackMarkerActiveMask;
        active = *mask;
        scene = gSceneFlagsB;
        active = (active | 4) & 0xFE;
        scene &= 0xFE;
        *mask = active;
        gSceneFlagsB = scene;
        F(cursor,s16,0x12) = -1;
        F(cursor,f32,8) = 0.01f;
        func_80047F50(obj,*(void **)base);
        F(obj,s16,0x7A) = 2;
        return;
    case 2:
        F(obj,s32,0x58) |= 1;
        F(cursor,f32,8) += F(cursor,f32,0xC);
        updateSplinePosition(obj,(u8 *)cursor+4);
        func_80047F50(obj,D_80109690);
        if (!gTrackMarkerDone[F(cursor,u8,0)] || F(cursor,s16,0x12) >= F(cursor,s16,0x10)-4) {
            F(obj,s16,0x7A) = 3;
        }
        return;
    case 3:
        first = F(cursor,u8,1);
        base = &D_80109690;
        mask = &gTrackMarkerActiveMask;
        gTrackMarkerDone[first] = 1;
        active = *mask;
        scene = gSceneFlagsB;
        pos = *(void **)base;
        active |= 1;
        scene |= 1;
        *mask = active;
        gSceneFlagsB = scene;
        func_80084048(pos,14,mask);
        *(void **)base = 0;
        func_80001D80(0);
        flags = F(obj,s32,0x60);
        D_80103EB0 = 1;
        flags |= 1;
store_flags:
        F(obj,s32,0x60) = flags;
    }
}
