extern s32 getSaveSlotIndex(s32);
extern f32 approxDistance(void *, void *);
extern s32 func_8007A9CC(void *, void *, f32 *, f32);
extern s32 func_800158A4(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_801182B0(void *, void *);
extern u32 gSaveSlotInfo[];
extern s8 D_801001A1[];
extern u8 gSceneType;
extern s32 gSaveTotalSlots;
extern void *D_80102CD0[4];
extern void *D_8010A410;
extern void *gBonusObjects[4];
extern u16 D_800BF688[];
extern s32 D_8011ECB0[];
extern void *sProbeFlags[];
extern s16 D_8011F100[];
extern u8 sProbeActive[];
extern u8 D_8011F169;

typedef struct { u8 pad[0xB4]; void *field_b4; } ObjSub;
typedef struct { u8 pad[0x6C]; void *field6c; } ObjMain;
typedef struct { u8 pad[0x74]; f32 dist; u8 pad2[0]; } ObjCandidate;

void *func_801183F4(ObjMain *arg0, s32 arg1) {
    register ObjSub *sub;
    s32 idx, row, kind, flags, n, i;
    s32 minframe, best1, best2;
    ObjCandidate *candidate;
    void *p, *best, *fallback, *selected;
    f32 limit1=65536.0f, limit2=65536.0f, scale, tmp;
    s32 state, pass, count, entry, v, j;
    volatile s32 __frame_pad[2];
    volatile s8 __saved_arg1 = (s8)arg1;

    sub = (ObjSub *)arg0->field6c;
    idx = getSaveSlotIndex((s32)(s8)*(u8 *)((u8 *)sub + 0x182)) & 0xffff;
    row = gSaveSlotInfo[idx * 6];
    kind = D_800BF688[row * 6] & 3;
    flags = D_8011ECB0[kind];
    idx = getSaveSlotIndex((s32)(s8)*(u8 *)((u8 *)sub + 0x182)) & 0xffff;
    row = gSaveSlotInfo[idx * 6];
    n = ((u8 *)D_800BF688)[row * 12 + 3];
    best = 0; fallback = 0; selected = 0; best1=0x270f;
    if (n & 2) {
        count=gSaveTotalSlots; i=0;
        while(i<count) {
            p=((void **)0x80102CD0)[i];
            v=*(u16 *)((u8 *)*(void **)((u8 *)p+0xb4)+0xc);
            if(v<best1) best1=v;
            i++;
        }
    }
    if(best1<=0) best1=1;
    i=0;
    for(entry=0;entry<4;entry++) {
        if(!(candidate = gBonusObjects[entry]) || candidate==(ObjCandidate *)arg0 || candidate->dist<=0.0f) continue;
        p=*(void **)((u8 *)candidate+0x6c);
        if(*(u16 *)((u8 *)candidate+0x78)==0x4d || *(u16 *)((u8 *)candidate+0x78)==0x61) continue;
        v=*(u8 *)((u8 *)sub->field_b4+0x12);
        if(v!=2 && v==*(u8 *)((u8 *)*(void **)((u8 *)p+0xb4)+0x12)) continue;
        tmp=approxDistance((u8 *)arg0+0x24,(u8 *)candidate+0x24);
        scale=*(f32 *)((u8 *)flags);
        tmp=tmp*scale;
        state=*(u8 *)((u8 *)sub->field_b4+0x12);
        if(gSceneType>=2 && gSceneType<=3) {
            if(sProbeFlags[state] == gBonusObjects[entry]) tmp*=0.33333334f;
        }
        if((unsigned)n&4) tmp=tmp*0.01f*(*(f32 *)((u8 *)gBonusObjects[entry]+0x74));
        if(n&2) {
            v=*(u16 *)((u8 *)*(void **)((u8 *)D_80102CD0[entry]+0xb4)+0xc);
            if(v<=0) v=1;
            tmp=tmp/((f32)v/(f32)best1);
        }
        if(n&8 && entry==D_8011F100[*(s8 *)((u8 *)sub+0x182)]) tmp*=0.25f;
        if(tmp<limit1) { limit1=tmp; fallback=gBonusObjects[entry]; }
        if(tmp<100.0f) {
            if(tmp<6.0f) goto scan_select;
            if(!(n&1)) {
                v=func_8007A9CC(arg0,(u8 *)candidate+0x24,&scale,1137.7778f);
                if(v) goto scan_select;
                continue;
            }
scan_select:
            v=*(s8 *)((u8 *)sub+0x182);
            v=((s32 *)0x80110000)[(v*4)/4-0x19de];
            j=func_800158A4((u8 *)v+0x10,(u8 *)candidate+0x24,*(void **)((u8 *)arg0+0x20),0,0,0x20000,0,1,0);
            if(j == 0) continue;
            if(tmp<limit2) { limit2=tmp; best=candidate; }
        }
    }
    if (!(best)) {
        if(fallback) return fallback;
        return selected;
    }
    return best;
}
