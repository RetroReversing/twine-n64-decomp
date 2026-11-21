typedef struct { u8 id; u8 next; u8 pad[2]; u8 spl[4]; f32 t; f32 dt; s16 len; s16 pos; } Cursor;
typedef struct { u8 pad[0x58]; s32 f58; u8 p2[4]; s32 f60; u8 p3[8]; Cursor *cur; u8 p4[0xA]; s16 stage; } Obj;
extern void actorInitFromSpawn(void *, void *, void *);
extern void func_80001D80(s32);
extern void func_8003C710(void *);
extern void func_80047F50(void *, void *);
extern void func_80048794(s32, s32);
extern s32 func_800658C0(void *);
extern void func_80084048(void *, s32, u8 *);
extern void updateSplinePosition(void *, void *);
extern void func_8004844C(void *, f32, f32, f32, f32, f32, f32);
extern u8 D_80100BE0[];
extern u8 gTrackMarkerDone[];
extern s8 D_80103EB0;
extern u8 *D_80109690;
extern void *sBonusObjectTable;
extern s32 gProbeObjectList;
extern u8 gSceneFlagsB;
extern u8 gTrackMarkerActiveMask;
extern u32 gTrackMarkerCount;
extern f32 gTrackMarkerPosTable[][3];
extern f32 gTrackMarkerRotTable[][3];
void func_80076838(Obj *obj)
{
    Cursor *cur = obj->cur;
    void *base;
    void *g1;
    void *g3;
    void *pos;
    void *rot;
    u32 i;
    u8 *m;
    u8 a;
    u8 b;
    u8 *m1;
    u8 a1;
    u8 b1;

    switch (obj->stage) {
    case 0:
        if (!gTrackMarkerDone[cur->id]) {
            break;
        }
        if (D_80103EB0 == 0) {
            obj->f60 |= 1;
            break;
        }
        base = sBonusObjectTable;
        D_80103EB0 = 0;
        if (!func_800658C0(base)) {
            break;
        }
        pos = (u8 *)base + 0x24;
        rot = (u8 *)base + 0x3C;
        for (i = 0; i < gTrackMarkerCount; i++) {
            if (D_80100BE0[i] == cur->id) {
                pos = gTrackMarkerPosTable[i];
                rot = gTrackMarkerRotTable[i];
                break;
            }
        }
        actorInitFromSpawn(base, pos, rot);
        func_80001D80(1);
        obj->stage = 1;
        break;
    case 1:
        func_80048794(2, gProbeObjectList);
        g1 = &D_80109690;
        func_8003C710(*(u8 **)g1);
        func_8004844C(*(u8 **)g1, 160.0f, 120.0f, 320.0f, 180.0f, 0.0f, 0.0f);
        func_80047F50(obj, *(u8 **)g1);
        *(s32 *)(D_80109690 + 0x100) |= 0x10;
        m1 = &gTrackMarkerActiveMask;
        b1 = gSceneFlagsB;
        a1 = (*m1 | 4) & ~1;
        b1 &= ~1;
        *m1 = a1;
        gSceneFlagsB = b1;
        *(s16 *)((u8 *)cur + 0x12) = -1;
        *(f32 *)((u8 *)cur + 8) = 0.01f;
        func_80047F50(obj, *(u8 **)g1);
        obj->stage = 2;
        break;
    case 2:
        obj->f58 |= 1;
        cur->t += cur->dt;
        updateSplinePosition(obj, cur->spl);
        func_80047F50(obj, D_80109690);
        if (!gTrackMarkerDone[cur->id] || cur->pos >= cur->len - 4) {
            obj->stage = 3;
        }
        break;
    case 3:
        g3 = &D_80109690;
        gTrackMarkerDone[cur->next] = 1;
        m = &gTrackMarkerActiveMask;
        *m |= 1;
        gSceneFlagsB |= 1;
        func_80084048(*(u8 **)g3, 14, m);
        *(u8 **)g3 = 0;
        func_80001D80(0);
        D_80103EB0 = 1;
        obj->f60 |= 1;
        break;
    }
}
