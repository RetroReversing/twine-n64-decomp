extern u8 gTrackMarkerDone[], D_80100BE0[], gTrackMarkerPosTable[], gTrackMarkerRotTable[];
extern u8 gTrackMarkerActiveMask, gSceneFlagsB;
extern s8 D_80103EB0;
extern u32 gTrackMarkerCount;
extern void *sBonusObjectTable, *D_80109690, *gProbeObjectList;
extern s32 func_800658C0(void *);
extern void actorInitFromSpawn(void *, void *, void *);
extern void func_80001D80(s32), func_80048794(s32, void *), func_8003C710(void *);
extern void func_8004844C(void *, f32, f32, f32, f32, f32, f32);
extern void func_80047F50(void *, void *), updateSplinePosition(void *, void *);
extern void func_80084048(void *, s32, u8 *);
#define F(base,type,off) (*(type *)((u8 *)(base)+(off)))
void func_80076838(void *actor) {
    u8 *params = F(actor,u8 *,0x6C);
    u8 *obj;
    u8 *pos, *rot;
    u32 index;
    s32 flags;
    void **scene;
    u8 *active;
    switch (F(actor,s16,0x7A)) {
    case 0:
        if (!gTrackMarkerDone[params[0]]) return;
        if (!D_80103EB0) {
            flags = F(actor,s32,0x60) | 1;
            goto finish;
        }
        obj = sBonusObjectTable;
        D_80103EB0 = 0;
        if (!func_800658C0(obj)) return;
        pos = obj + 0x24;
        rot = obj + 0x3C;
        for (index = 0; index < gTrackMarkerCount; index++) {
            if (D_80100BE0[index] == params[0]) {
                pos = gTrackMarkerPosTable + index * 12;
                rot = gTrackMarkerRotTable + index * 12;
                break;
            }
        }
        actorInitFromSpawn(obj,pos,rot);
        func_80001D80(1);
        F(actor,s16,0x7A)=1;
        break;
    case 1:
        func_80048794(2,gProbeObjectList);
        scene = &D_80109690;
        func_8003C710(*scene);
        func_8004844C(*scene,160.0f,120.0f,320.0f,180.0f,0.0f,0.0f);
        func_80047F50(actor,*scene);
        F(D_80109690,s32,0x100) |= 16;
        active = &gTrackMarkerActiveMask;
        *active = (*active | 4) & 0xFE;
        gSceneFlagsB &= 0xFE;
        F(params,s16,0x12)=-1;
        F(params,f32,8)=0.01f;
        func_80047F50(actor,*scene);
        F(actor,s16,0x7A)=2;
        break;
    case 2:
        F(actor,s32,0x58)|=1;
        F(params,f32,8)+=F(params,f32,12);
        updateSplinePosition(actor,params+4);
        func_80047F50(actor,D_80109690);
        if (!gTrackMarkerDone[params[0]] || F(params,s16,0x12)>=F(params,s16,0x10)-4)
            F(actor,s16,0x7A)=3;
        break;
    case 3:
        scene = &D_80109690;
        active = &gTrackMarkerActiveMask;
        gTrackMarkerDone[params[1]]=1;
        *active |= 1;
        gSceneFlagsB |= 1;
        func_80084048(*scene,14,active);
        *scene=0;
        func_80001D80(0);
        D_80103EB0=1;
        flags = F(actor,s32,0x60) | 1;
finish:
        F(actor,s32,0x60)=flags;
        break;
    }
}
