s32 actorLinkToSurface();
s32 clearProbeState();
void setActorAssetIndex();
s32 setRotationInterpolationMode();
s32 allocActorAnimData();
s32 setActorCommandState();
void *createEffectObject();
s32 getItemTableByte();
s32 resolveEnemyDefLink();
s32 setEffectPairAnimFrames();
void *spawnFlaggedEffectAtValue();
s32 spawnFlaggedEffect();
void *spawnTimedEffectObject();
s32 initEnemyStatusEntries();
s32 clearActorStateBlock();
s32 spawnFlaggedEffectObject();
s32 applyEnemyDefAnimation();
s32 clearActorGateState();
s32 snapObjectToFloor();
s8 findNthUsedSaveSlot();
s32 initOptionCursorActorSlot();
s32 getSaveSlotIndex();
s32 initObjectFromBankEntry();
s32 initSaveMenuSlot();
s32 setActionSlot();
void *spawnTextNode();
void *spawnTrackMarker();
extern u8 D_800BF688[];
typedef struct {
  u8 f0, f1, f2;
  u8 pad[0xE5];
} Row;
extern Row sEnemyDefLinkSlot[];
extern char D_800C471E[];
extern f32 D_800C7C98;
extern f32 kRayRangeMultiplier;
extern s8 gSpecialTriggerHit;
extern unsigned char D_801001A0[];
extern char D_801001A3[];
extern void *gSaveSlots[];
extern s8 gBonusSequenceReady;
extern u8 D_80112F6D;
extern s32 gBorderSkipActive;
extern s32 gGameMode;
extern s32 *gDefaultOrderObj;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo;
extern void *sBonusObjectTable[];
extern u8 sDifficultyLevel;
extern void *gTrackMarkerParents[];
typedef struct {
  u32 x, y, style;
  u16 size;
  u8 mode, pad;
  u32 settings;
  u16 id;
  s32 index, bank;
  s16 marker;
} Tpl;
extern Tpl D_800C7D54[];
#define F(p, T, off) (*(T *)((char *)(p) + (off)))
inline static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}
inline static s32 inline_fn2(unsigned short arg0)
{
  return *((s32 *) (((u8 *) (&gSaveSlotInfo)) + ((getSaveSlotIndex(arg0) & 0xFFFF) * 0x18)));
}

typedef struct Slot { s8 f0, f1, f2; u8 f3; f32 f4; } Slot;
typedef struct RecA {
  u8 pad[0x1BC];
  u16 h1BC[0x20];
  Slot slot[0x3B];
} RecA;
typedef struct Obj {
  u8 pad0[0x28];
  f32 f28_f32;
  u8 pad2C[0x10];
  s32 f3C_s32;
  f32 f40_f32;
  s32 f44_s32;
  u8 pad48[0x10];
  s32 f58_s32;
  s32 f5C_s32;
  u8 pad60[0x8];
  void *f68_p;
  void *f6C_p;
  u8 pad70[0x4];
  f32 f74_f32;
  s16 f78_s16;
  u8 pad7A[0x4];
  s8 f7E_s8;
  u8 f7F_u8;
  u8 f80_u8;
  u8 f81_u8;
  u8 f82_u8;
  u8 pad83[0x1];
} Obj;
/* Creates and initialises a fighter actor for a player slot (state record, HUD text nodes, markers, move slots, physics defaults) and sets difficulty-dependent ray ranges. */ void *spawnFighterActor(s16 arg0, void *spawnPos, void *spawnParams, void *setupEntry)
{
  Obj *fighterObj;
  void *fighterState;
  s32 idx;
  s16 i;
  s32 x0, y0, dy, ydy, yy;
  s32 slot;
  s32 one;
  void *m;
  s32 a1;
  s32 t;
  void **tab2;
  s32 ex2;
  void **tab;
  s32 ex;
  s32 w2;
  s32 w;
  s32 cv;
  s32 a1x;
  u8 bb;
  u8 a3;
  s32 id;
  void *c;
  void *ctl;
  void *ent;
  void **tbl;
  void **tbl2;
  s32 v;
  u32 k;
  u32 t1, t2;
  s32 sl0, sl1, o0, o1;
  f32 fa, fb;

  if (gBorderSkipActive == 0 && F(setupEntry, u16, 0x40) != sDifficultyLevel)
    return NULL;
  fighterObj = createEffectObject(0x5AC, spawnPos, 0);
  gSpecialTriggerHit = 0;
  sBonusObjectTable[(s16) arg0] = fighterObj;
  if (fighterObj != NULL)
  {
    fighterState = fighterObj->f6C_p;
    snapObjectToFloor(fighterObj);
    id = arg0 & 0xFF;
    F(fighterState, s32, 0x1B0) = 0;
    F(fighterState, u8, 0x182) = arg0;
    F(fighterState, s8, 0x183) = findNthUsedSaveSlot(id);
    gSaveSlots[(s16) arg0] = fighterState;
    F(fighterState, s32, 0x104) = 0;
    F(fighterState, s32, 0x108) = 0;
    F(fighterState, s32, 0x10C) = 0;
    F(fighterState, s32, 0x110) = 0;
    F(fighterState, s32, 0x114) = 0;
    F(fighterState, s32, 0x118) = 0;
    F(fighterState, s32, 0xC0) = 0;
    gBonusSequenceReady = 1;
    F(fighterState, s8, 0x198) = 0;
    F(fighterState, s8, 0x197) = 0;
    F(fighterState, s32, 0x1C) = 0;
    F(fighterState, s32, 0x20) = 0;
    F(fighterState, s32, 0x24) = 0;
    F(fighterState, s32, 0x28) = 0;
    F(fighterState, f32, 0x9C) = 3.1415927f;
    if (gBorderSkipActive != 0)
      initSaveMenuSlot(fighterState, id);
    else
      F(fighterState, s32, 0xB4) = 0;
    F(fighterState, s32, 0xCC) = 0;
    F(fighterState, s32, 4) = 0;
    F(fighterState, s32, 0xA8) = spawnFlaggedEffectObject(fighterObj, (s16) arg0);
    F(fighterState, s32, 0x6C) = 0;
    F(fighterState, s32, 0x70) = 0;
    F(fighterState, s32, 0x74) = 0;
    F(fighterState, s32, 0x78) = 0;
    F(fighterState, s32, 0xC) = -1;
    F(fighterState, s32, 8) = -1;
    F(fighterState, s16, 0x176) = 0;
    F(fighterState, s16, 0x178) = 0;
    F(fighterState, s16, 0x17A) = 0;
    F(fighterState, s8, 0x19A) = 0;
    F(fighterState, void *, 0xAC) = spawnFlaggedEffectAtValue(fighterObj, (s16) arg0);
    F(fighterState, void *, 0xB0) = spawnTimedEffectObject(fighterObj, (s16) arg0);
    F(F(fighterState, void *, 0xAC), void *, 0x18) = fighterObj;
    F(F(fighterState, void *, 0xB0), void *, 0x18) = fighterObj;
    F(fighterState, s32, 0xC4) = spawnFlaggedEffect(fighterObj);
    F(fighterState, s32, 0xBC) = 0;
    fighterObj->f78_s16 = 2;
    fighterObj->f3C_s32 = 0;
    fighterObj->f40_f32 = F(spawnParams, f32, 4);
    fighterObj->f44_s32 = 0;
    actorLinkToSurface(*gDefaultOrderObj, fighterObj, 0);
    F(fighterState, s8, 0x184) = 0;
    F(fighterState, s8, 0x185) = 0;
    F(fighterState, s32, 0x410) = 0;
    F(fighterState, s32, 0x414) = 0;
    i = 0;
    do
    {
      F(fighterState, s32, 0x3D4 + i * 4) = 0;
      i++;
    }
    while (i < 4);
    i = 0;
    do
    {
      F(fighterState, s32, 0x3E4 + i * 4) = 0;
      i++;
    }
    while (i < 6);
    F(fighterState, s32, 0x3FC) = 0;
    F(fighterState, s32, 0x400) = 0;
    F(fighterState, s16, 0x520) = 0x706;
    D_800C7D54[0].marker = (s8) F(fighterState, u8, 0x182);
    D_800C7D54[1].marker = (s8) F(fighterState, u8, 0x182);
    F(fighterState, void *, 0x404) = spawnTextNode(&D_800C7D54[0]);
    F(fighterState, void *, 0x408) = spawnTextNode(&D_800C7D54[1]);
    F(fighterState, void *, 0x478) = spawnTextNode(&D_800C7D54[0]);
    F(fighterState, void *, 0x47C) = spawnTextNode(&D_800C7D54[0]);
    if (gBorderSkipActive != 0)
    {
      x0 = 0x18;
      y0 = 0x12;
      dy = 3;
      F(fighterState, void *, 0x480) = spawnTextNode(&D_800C7D54[1]);
      F(F(fighterState, void *, 0x478), u16, 0x26) >>= 1;
      F(F(fighterState, void *, 0x478), u8, 0x29) >>= 1;
      F(F(fighterState, void *, 0x480), s16, 0x26) = 0x1A;
      F(F(fighterState, void *, 0x47C), u16, 0x26) >>= 1;
      F(F(fighterState, void *, 0x47C), u8, 0x29) >>= 1;
      F(F(fighterState, void *, 0x404), u16, 0x26) >>= 1;
      F(F(fighterState, void *, 0x404), u8, 0x29) >>= 1;
      F(F(fighterState, void *, 0x408), u16, 0x26) >>= 1;
      F(F(fighterState, void *, 0x408), u8, 0x29) >>= 1;
      F(F(fighterState, void *, 0x480), s16, 0x20) = x0;
      F(F(fighterState, void *, 0x480), s16, 0x22) = y0;
    }
    else
    {
      x0 = 0x24;
      y0 = 0x15;
      dy = 6;
      m = spawnTrackMarker((s8) F(fighterState, u8, 0x182));
      initObjectFromBankEntry(m, 0x2B, 0x1B);
F(m, s16, 0x20) = 0x14;
F(m, s16, 0x22) = 0x13;
F(m, u16, 0x1E) = F(m, u16, 0x1E) | 2;
w = F(m, s32, 0x28); w &= ~0xFC; w |= 0x10; F(m, s32, 0x28) = w;
F(m, s32, 0x10) = 0xFF0000C8;
F(fighterState, void *, 0x484) = m;
      m = spawnTrackMarker((s8) F(fighterState, u8, 0x182));
      initObjectFromBankEntry(m, 0x2C, 0x1B);
      F(m, s16, 0x20) = 0x55;
      F(m, u16, 0x1E) |= 2;
      w2 = F(m, s32, 0x28); w2 &= ~0xFC; w2 |= 0x1C; F(m, s32, 0x28) = w2;
      F(m, s16, 0x22) = 0x13;
      F(m, s32, 0x10) = 0xFFC8;
      F(fighterState, void *, 0x488) = m;
      F(fighterState, void *, 0x480) = spawnTrackMarker((s8) F(fighterState, u8, 0x182));
      initObjectFromBankEntry(F(fighterState, void *, 0x480), 0xC, 0x2A);
      F(F(fighterState, void *, 0x480), u16, 0x1E) |= 2;
      F(F(fighterState, void *, 0x480), s16, 0x20) = 0x16;
      F(F(fighterState, void *, 0x480), s16, 0x22) = 0x13;
    }
    yy = y0 + 1;
    F(F(fighterState, void *, 0x478), s16, 0x20) = x0 + 1;
    F(F(fighterState, void *, 0x478), s16, 0x22) = yy;
    F(F(fighterState, void *, 0x47C), s16, 0x20) = x0 + 1;
    F(F(fighterState, void *, 0x47C), s16, 0x22) = dy + yy;
    ydy = 0x114 - x0;
    F(F(fighterState, void *, 0x404), s16, 0x20) = ydy + 1;
    F(F(fighterState, void *, 0x404), s16, 0x22) = yy;
    F(F(fighterState, void *, 0x408), s16, 0x20) = ydy;
    F(F(fighterState, void *, 0x408), s16, 0x22) = y0;
    F(fighterState, void *, 0x40C) = spawnTrackMarker((s8) F(fighterState, u8, 0x182));
    initObjectFromBankEntry(F(fighterState, void *, 0x40C), 0x30, 0x1B);
    F(F(fighterState, void *, 0x40C), u16, 0x1E) |= 2;
    F(F(fighterState, void *, 0x40C), s16, 0x20) = 0xE0;
    F(F(fighterState, void *, 0x40C), s16, 0x22) = 0x11;
    F(F(fighterState, void *, 0x40C), s32, 0x28) = (F(F(fighterState, void *, 0x40C), s32, 0x28) & ~0xFC) | 0x1C;
    F(F(fighterState, void *, 0x40C), s32, 0x10) = 0xFFFF00;
    F(F(fighterState, void *, 0x478), s32, 0x28) = (F(F(fighterState, void *, 0x478), s32, 0x28) & ~0xFC) | 0x10;
    F(F(fighterState, void *, 0x480), s32, 0x28) = (F(F(fighterState, void *, 0x480), s32, 0x28) & ~0xFC) | 0x10;
    F(F(fighterState, void *, 0x47C), s32, 0x28) = (F(F(fighterState, void *, 0x47C), s32, 0x28) & ~0xFC) | 0x10;
    F(F(fighterState, void *, 0x478), s32, 0x10) = 0xAA00FF;
    F(F(fighterState, void *, 0x480), s32, 0x10) = 0xC8;
    F(F(fighterState, void *, 0x47C), s32, 0x10) = 0xAAFF;
    F(F(fighterState, void *, 0x404), s32, 0x10) = 0xAAAA00;
    F(F(fighterState, void *, 0x408), s32, 0x10) = 0;
    clearActorGateState(fighterState);
    clearActorStateBlock(fighterObj);
    ex = (s16) arg0;
    tab = gTrackMarkerParents;
    tbl = &tab[ex];
    F(*tbl, f32, 0x4C) = 1.0f;
    ent = *tbl;
    fa = F(spawnPos, f32, 0);
    F(ent, f32, 0x10) = fa;
    F(ent, f32, 0x28) = fa;
    ent = *tbl;
    fa = F(spawnPos, f32, 4);
    F(ent, f32, 0x14) = fa;
    F(ent, f32, 0x2C) = fa;
    ent = *tbl;
    fa = F(spawnPos, f32, 8);
    F(ent, f32, 0x18) = fa;
    F(ent, f32, 0x30) = fa;
    F(*tbl, f32, 0x38) = F(spawnParams, f32, 4);
    F(*tbl, s32, 0xF4) = 0;
    F(*tbl, void *, 0x138) = fighterObj;
    F(*tbl, s32, 0x130) = 0;
    setRotationInterpolationMode(0);
    if (gBorderSkipActive != 0)
    {
      k = (u16) arg0;
      t = getItemTableByte(inline_fn2(k));
      a3 = *(D_801001A3 + ((getSaveSlotIndex(k) & 0xFFFF) * 0x18));
      a1 = t;
      allocActorAnimData(fighterObj, a1, 1, a3);
    }
    else
    {
      switch (gGameMode)
      {
        default:
          a1 = 0x11;
          break;
        case 25:
          a1 = 0x10;
          break;
        case 1:
        case 38:
          a1 = 0xC;
          break;
        case 11:
          a1 = 0xE;
          break;
        case 18:
        case 28:
        case 29:
        case 33:
          a1 = 0xB;
          break;
      }
      allocActorAnimData(fighterObj, a1, 1, 0);
    }
    setActorCommandState(fighterObj, 0x159);
    F(fighterState, s8, 0x18F) = 0;
    initEnemyStatusEntries(fighterObj);
    setActorAssetIndex(fighterObj, 0);
    setEffectPairAnimFrames(fighterObj);
    a1x = F(fighterObj->f68_p, s16, 0xA2);
    if (a1x != 0)
      clearProbeState(fighterObj, a1x);
    applyEnemyDefAnimation(fighterObj);
    ctl = fighterObj->f68_p;
    bb = F(ctl, u8, 0xE);
    F(ctl, u8, 0xF) = bb;
    F(ctl, u8, 0x10) = bb;
    if (gBorderSkipActive == 0)
    {
      o0 = F(setupEntry, u16, 0x2C);
      v = F(setupEntry, u16, 0x2E);
      t1 = F(setupEntry, u16, 0x30);
      t2 = F(setupEntry, u16, 0x32);
      one = 1;
      ((RecA *) fighterState)->slot[o0].f0 = one;
      *(u16 *) ((char *) fighterState + (sEnemyDefLinkSlot[o0].f0 << 1) + 0x1BC) = v;
      ((RecA *) fighterState)->slot[(s16) resolveEnemyDefLink((s16) o0)].f3 = *(D_800C471E + o0 * 0xE8);
      ((RecA *) fighterState)->slot[t1].f0 = one;
      *(u16 *) ((char *) fighterState + (sEnemyDefLinkSlot[t1].f0 << 1) + 0x1BC) = t2;
      ((RecA *) fighterState)->slot[(s16) resolveEnemyDefLink((s16) t1)].f3 = *(D_800C471E + t1 * 0xE8);
      if (((gGameMode == 0x26) | (gGameMode == 1)) != 0)
        F(fighterState, s8, 0x21E) = one;
      if (gGameMode != 0x19)
      {
        F(fighterState, s8, 0x304) = one;
        F(fighterState, s8, 0x30C) = one;
        F(fighterState, s8, 0x314) = one;
        F(fighterState, s8, 0x31C) = one;
        F(fighterState, s8, 0x307) = 0x64;
        F(fighterState, s8, 0x317) = 0x64;
        cv = 0xC;
        if (gGameMode != 2)
          cv = (-(gGameMode == 0x26)) & 0xC;
        F(fighterState, s8, 0x30F) = cv;
      }
      setActionSlot(fighterState, F(setupEntry, u8, 0x35), 1, 1);
      setActionSlot(fighterState, F(setupEntry, u8, 0x37), 1, 1);
      setActionSlot(fighterState, F(setupEntry, u8, 0x39), 1, 1);
      setActionSlot(fighterState, F(setupEntry, u8, 0x3B), 1, 1);
      setActionSlot(fighterState, F(setupEntry, u8, 0x3F), 1, 1);
      if (D_80112F6D != 0)
      {
        k = 0;
        do
        {
          setActionSlot(fighterState, k & 0xFF, 1, 0);
          k += 1;
        }
        while (k < 0x1EU);
      }
    }
    switch ((s16) arg0)
    {
      case 0:
        fighterObj->f5C_s32 = 0x2000;
        F(fighterState, s32, 0) = 0x7D000;
        break;
      case 1:
        fighterObj->f5C_s32 = 0x4000;
        F(fighterState, s32, 0) = 0x7B000;
        break;
      case 2:
        fighterObj->f5C_s32 = 0x8000;
        F(fighterState, s32, 0) = 0x77000;
        break;
      case 3:
        fighterObj->f5C_s32 = 0x10000;
        F(fighterState, s32, 0) = 0x6F000;
        break;
    }
    fighterObj->f58_s32 |= 0x2400;
    ex2 = (s16) arg0;
    tab2 = gTrackMarkerParents;
    tbl2 = &tab2[ex2];
    fighterObj->f5C_s32 |= 0x600;
    F(*tbl2, s32, 0x100) &= ~7;
    F(*tbl2, s32, 0x100) |= 1;
    fighterObj->f7F_u8 = 0xFF;
    fighterObj->f80_u8 = 0xFF;
    fighterObj->f81_u8 = 0xFF;
    fighterObj->f82_u8 = 0xFF;
    fighterObj->f7E_s8 = 1;
    F(fighterState, s32, 0x60) = 0;
    F(fighterState, s32, 0x64) = 0;
    if (gBorderSkipActive != 0)
    {
      if (ex2 < gSaveSlotCount)
        fighterObj->f74_f32 = (f32) (*(D_801001A0 + ((getSaveSlotIndex((u16) arg0) & 0xFFFF) * 0x18)));
      else
        fighterObj->f74_f32 = (f32) ((*(D_800BF688 + (inline_fn2((u16) arg0) * 0xC))) * 5);
    }
    else
      fighterObj->f74_f32 = 100.0f;
F(fighterState, s8, 0x199) = 0;
F(fighterState, f32, 0x68) = fighterObj->f74_f32;
F(fighterState, s8, 0x18C) = 0;
F(fighterState, u8, 0x18D) = 0x80;
    if (gBorderSkipActive != 0)
      initOptionCursorActorSlot(fighterObj, fighterState, arg0 & 0xFF);
    F(fighterState, s8, 0x17E) = 3;
    F(fighterObj->f68_p, f32, 8) = fighterObj->f28_f32 - 2.0f;
  }
  if (gBorderSkipActive != 0)
  {
    D_800C7C98 = 10.0f;
    kRayRangeMultiplier = 16.0f;
  }
  else
  {
    switch (sDifficultyLevel)
    {
      case 0:
      default:
        D_800C7C98 = 12.0f;
        kRayRangeMultiplier = 18.0f;
        break;
      case 1:
        D_800C7C98 = 8.0f;
        kRayRangeMultiplier = 14.0f;
        break;
      case 2:
        D_800C7C98 = 0;
        kRayRangeMultiplier = 0;
        break;
    }
  }
  return fighterObj;
}
