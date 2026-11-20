extern s32 func_80022DBC(s32);
extern f32 func_80045E34(void *, void *);
extern s32 func_8007A9CC(void *, void *, void *, u32);
extern s32 func_800158A4(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_801182B0(void *, void *);
extern u32 D_8010019C[];
extern u8 D_801001A1[];
extern u8 D_801002A0;
extern s32 D_801002B4;
extern void *D_80102CD0[4];
extern void *D_8010A410;
extern void *D_8010A500[4];
extern u16 D_800BF688[];
extern s32 D_8011ECB0[];
extern s32 D_8011F280[];
extern s16 D_8011F100[];
extern u8 D_8011F168[];
extern u8 D_8011F169;

typedef struct { u8 pad[0xB4]; void *field_b4; } ObjSub;
typedef struct { u8 pad[0x68]; void *field68; } ObjMain;
typedef struct { u8 pad[0x74]; f32 dist; u8 pad2[0]; } ObjCandidate;

void *func_801183F4(ObjMain *arg0, s32 arg1) {
    ObjSub *sub;
    s32 idx, row, kind, flags, n, i;
    s32 minframe, best1, best2;
    ObjCandidate *candidate;
    void *p, *best, *fallback, *selected;
    f32 limit1, limit2, scale, tmp;
    s32 state, pass, count, entry, v, j;
    volatile s32 __frame_pad[2];

    sub = (ObjSub *)arg0->field68;
    idx = func_80022DBC((s32)(s8)*(u8 *)((u8 *)sub + 0x182)) & 0xffff;
    row = D_8010019C[idx * 6];
    kind = D_800BF688[row * 6] & 3;
    flags = D_8011ECB0[kind];
    idx = func_80022DBC((s32)(s8)*(u8 *)((u8 *)sub + 0x182)) & 0xffff;
    row = D_8010019C[idx * 6];
    n = D_800BF688[row * 6 + 3];
    best = 0; fallback = 0; selected = 0; best1=0x270f;
    if (n & 2) {
        count=D_801002B4; i=0;
        while(i<count) {
            p=((void **)0x80102CD0)[i];
            v=*(s32 *)((u8 *)p+0xb4);
            v=*(s16 *)((u8 *)v+0xc);
            if(v<best1) best1=v;
            i++;
        }
    }
    if(best1<=0) best1=1;
    i=0;
    for(entry=0;entry<4;entry++) {
        candidate=D_8010A500[entry];
        if(!candidate || candidate==(ObjCandidate *)arg0 || candidate->dist<=0.0f) continue;
        p=*(void **)((u8 *)candidate+0x6c);
        if(*(u16 *)((u8 *)candidate+0x78)==0x4d || *(u16 *)((u8 *)candidate+0x78)==0x61) continue;
        v=*(u8 *)((u8 *)sub->field_b4+0x12);
        if(v==2) func_80045E34(arg0,(u8 *)candidate+0x24);
        else if(v==*(u8 *)((u8 *)*(void **)((u8 *)p+0x6c)+0x12)) func_80045E34(arg0,(u8 *)candidate+0x24);
        scale=*(f32 *)((u8 *)flags);
        tmp=candidate->dist*scale;
        state=*(u8 *)((u8 *)sub->field_b4+0x12);
        if(D_801002A0>=2 && D_801002A0<=3) {
            if(D_8011F280[state] == D_8010A500[entry]) tmp*=0.33333334f;
        }
        if(n&4) tmp=tmp*0.01f*(*(f32 *)((u8 *)D_8010A500[entry]+0x74));
        if(n&2) {
            v=*(s16 *)((u8 *)((void **)D_80102CD0)[entry]+0xc);
            if(v<=0) v=1;
            tmp=tmp/((f32)v/(f32)best1);
        }
        if(n&8 && i==D_8011F100[*(s8 *)((u8 *)sub+0x182)]) tmp*=0.25f;
        if(tmp<0.0f) { best1=*(s32 *)D_8010A500[entry]; fallback=best1; }
        if(tmp<100.0f) {
            if(tmp<6.0f) goto scan_select;
            if(!(n&1)) {
                v=func_8007A9CC(arg0,(u8 *)candidate+0x24,&scale,0x448E38E4);
                if(v) goto scan_select;
                continue;
            }
scan_select:
            v=*(s8 *)((u8 *)sub+0x182);
            v=((s32 *)0x80110000)[(v*4)/4-0x19de];
            j=func_800158A4((u8 *)v+0x10,(u8 *)candidate+0x24,*(void **)((u8 *)arg0+0x20),0,0,0x20000,0,1,0);
            if(!j) continue;
            if(tmp<0.0f) continue;
            best=candidate;
            selected=candidate;
        }
    }
    if (!(best)) {
        if(fallback) return fallback;
        return selected;
    }
    return best;
}
