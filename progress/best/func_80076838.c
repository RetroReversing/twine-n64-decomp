#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
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
extern void *D_80109690;
extern void *sBonusObjectTable;
extern s32 gProbeObjectList;
extern u8 gSceneFlagsB;
extern u8 gTrackMarkerActiveMask;
extern volatile u32 gTrackMarkerCount;
extern f32 gTrackMarkerPosTable[][3];
extern f32 gTrackMarkerRotTable[][3];
void func_80076838(void *obj)
{
  s16 stage = *((s16 *) (((u8 *) obj) + 0x7A));
  void *base;
  void *cursor = *((void **) (((u8 *) obj) + 0x6C));
  void *pos;
  void *rot;
  volatile u32 scratch[2];
  u8 *mask;
  register u32 flags;
  u32 i;
  u32 count;
  int first;
  u8 scene;
  u8 active;
  register unsigned offset;
  switch (stage)
  {
 do { case 0: if (!gTrackMarkerDone[*((u8 *) (((u8 *) cursor) + 0))]) { return; } if (D_80103EB0) { goto load_bonus; } *((s32 *) (((u8 *) obj) + 0x60)) |= 1; return; found: offset = ((s32) i) * 12; pos = ((u8 *) gTrackMarkerPosTable) + offset; rot = ((u8 *) gTrackMarkerRotTable) + offset; goto init_bonus; load_bonus: base = sBonusObjectTable; D_80103EB0 = 0; if (!func_800658C0(base)) { return; } pos = ((u8 *) base) + 0x24; count = gTrackMarkerCount; rot = ((u8 *) base) + 0x3C; i = 0; if (count != 0) { first = *((u8 *) (((u8 *) cursor) + 0)); again: if (D_80100BE0[i] == first) { goto found; } if ((++i) < count) { goto again; } } init_bonus: actorInitFromSpawn(base, pos, rot); func_80001D80(1); *((s16 *) (((u8 *) obj) + 0x7A)) = 1; return; case 1: func_80048794(2, gProbeObjectList); func_8003C710(*((void **) base)); base = &D_80109690; func_8004844C(*((void **) base), 160.0f, 120.0f, 320.0f, 180.0f, 0.0f, 0.0f); func_80047F50(obj, *((void **) base)); *((s32 *) (((u8 *) D_80109690) + 0x100)) |= 0x10; mask = &gTrackMarkerActiveMask; active = *mask; scene = gSceneFlagsB; active = (active | 4) & 0xFE; scene &= 0xFE; *mask = (u32) active; gSceneFlagsB = scene; *((s16 *) (((u8 *) cursor) + 0x12)) = -1; *((f32 *) (((u8 *) cursor) + 8)) = 0.01f; func_80047F50(obj, *((void **) base)); *((s16 *) (((u8 *) obj) + 0x7A)) = 2; return; case 2: *((s32 *) (((u8 *) obj) + 0x58)) |= 1; *((f32 *) (((u8 *) cursor) + 8)) += *((f32 *) (((u8 *) cursor) + 0xC)); updateSplinePosition(obj, ((u8 *) cursor) + 4); func_80047F50(obj, D_80109690); if ((!gTrackMarkerDone[*((u8 *) (((u8 *) cursor) + 0))]) || ((*((s16 *) (((u8 *) cursor) + 0x12))) >= ((*((s16 *) (((u8 *) cursor) + 0x10))) - 4))) { *((s16 *) (((u8 *) obj) + 0x7A)) = 3; } return; } while (0);
    case 3:
      first = *((u8 *) (((u8 *) cursor) + 1));
      mask = &gTrackMarkerActiveMask;
      gTrackMarkerDone[first] = 1;
      active = *mask;
      scene = gSceneFlagsB;
      base = &D_80109690;
      pos = *((void **) base);
      active |= 1;
      scene |= 1;
      *mask = active;
      gSceneFlagsB = scene;
      func_80084048(pos, 14, mask);
      *((void **) base) = 0;
      flags = *((s32 *) (((u8 *) obj) + 0x60));
      func_80001D80(0);
      D_80103EB0 = 1;
      flags |= 1;
      store_flags:
    *((s32 *) (((u8 *) obj) + 0x60)) = flags;


  }

}
