s32 actorLinkToSurface();
s32 clearProbeState();
void func_800015AC();
s32 func_80001D80();
s32 func_8000237C();
s32 func_80002BD0();
void *func_800164F8();
s32 func_8002B9CC();
s32 func_80063C7C();
s32 func_800643EC();
void *func_80064444();
s32 func_800644CC();
void *func_8006452C();
s32 func_80064630();
s32 func_800649E4();
s32 func_800671E0();
s32 func_80067AE8();
s32 func_8007080C();
s32 func_80077C00();
s8 func_80081828();
s32 func_8011ACAC();
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
extern Row D_800C471C[];
extern char D_800C471E[];
extern f32 D_800C7C98;
extern f32 D_800C7C9C;
extern s8 D_800E19F4;
extern unsigned char D_801001A0[];
extern char D_801001A3[];
extern void *D_80102CD0[];
extern s8 D_80103EB0;
extern u8 D_80112F6D;
extern s32 gBorderSkipActive;
extern s32 gGameMode;
extern s32 *gProbeObjectList;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo;
extern void *sBonusObjectTable[];
extern u8 sDifficultyLevel;
extern void *sTrackMarkerTable[];
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
void *func_80064A18(s16 arg0, void *arg1, void *arg2, void *arg3)
{
  Obj *obj;
  void *rec;
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

  if (gBorderSkipActive == 0 && F(arg3, u16, 0x40) != sDifficultyLevel)
    return NULL;
  obj = func_800164F8(0x5AC, arg1, 0);
  D_800E19F4 = 0;
  sBonusObjectTable[(s16) arg0] = obj;
  if (obj != NULL)
  {
    rec = obj->f6C_p;
    func_80077C00(obj);
    id = arg0 & 0xFF;
    F(rec, s32, 0x1B0) = 0;
    F(rec, u8, 0x182) = arg0;
    F(rec, s8, 0x183) = func_80081828(id);
    D_80102CD0[(s16) arg0] = rec;
    F(rec, s32, 0x104) = 0;
    F(rec, s32, 0x108) = 0;
    F(rec, s32, 0x10C) = 0;
    F(rec, s32, 0x110) = 0;
    F(rec, s32, 0x114) = 0;
    F(rec, s32, 0x118) = 0;
    F(rec, s32, 0xC0) = 0;
    D_80103EB0 = 1;
    F(rec, s8, 0x198) = 0;
    F(rec, s8, 0x197) = 0;
    F(rec, s32, 0x1C) = 0;
    F(rec, s32, 0x20) = 0;
    F(rec, s32, 0x24) = 0;
    F(rec, s32, 0x28) = 0;
    F(rec, f32, 0x9C) = 3.1415927f;
    if (gBorderSkipActive != 0)
      initSaveMenuSlot(rec, id);
    else
      F(rec, s32, 0xB4) = 0;
    F(rec, s32, 0xCC) = 0;
    F(rec, s32, 4) = 0;
    F(rec, s32, 0xA8) = func_800671E0(obj, (s16) arg0);
    F(rec, s32, 0x6C) = 0;
    F(rec, s32, 0x70) = 0;
    F(rec, s32, 0x74) = 0;
    F(rec, s32, 0x78) = 0;
    F(rec, s32, 0xC) = -1;
    F(rec, s32, 8) = -1;
    F(rec, s16, 0x176) = 0;
    F(rec, s16, 0x178) = 0;
    F(rec, s16, 0x17A) = 0;
    F(rec, s8, 0x19A) = 0;
    F(rec, void *, 0xAC) = func_80064444(obj, (s16) arg0);
    F(rec, void *, 0xB0) = func_8006452C(obj, (s16) arg0);
    F(F(rec, void *, 0xAC), void *, 0x18) = obj;
    F(F(rec, void *, 0xB0), void *, 0x18) = obj;
    F(rec, s32, 0xC4) = func_800644CC(obj);
    F(rec, s32, 0xBC) = 0;
    obj->f78_s16 = 2;
    obj->f3C_s32 = 0;
    obj->f40_f32 = F(arg2, f32, 4);
    obj->f44_s32 = 0;
    actorLinkToSurface(*gProbeObjectList, obj, 0);
    F(rec, s8, 0x184) = 0;
    F(rec, s8, 0x185) = 0;
    F(rec, s32, 0x410) = 0;
    F(rec, s32, 0x414) = 0;
    i = 0;
    do
    {
      F(rec, s32, 0x3D4 + i * 4) = 0;
      i++;
    }
    while (i < 4);
    i = 0;
    do
    {
      F(rec, s32, 0x3E4 + i * 4) = 0;
      i++;
    }
    while (i < 6);
    F(rec, s32, 0x3FC) = 0;
    F(rec, s32, 0x400) = 0;
    F(rec, s16, 0x520) = 0x706;
    D_800C7D54[0].marker = (s8) F(rec, u8, 0x182);
    D_800C7D54[1].marker = (s8) F(rec, u8, 0x182);
    F(rec, void *, 0x404) = spawnTextNode(&D_800C7D54[0]);
    F(rec, void *, 0x408) = spawnTextNode(&D_800C7D54[1]);
    F(rec, void *, 0x478) = spawnTextNode(&D_800C7D54[0]);
    F(rec, void *, 0x47C) = spawnTextNode(&D_800C7D54[0]);
    if (gBorderSkipActive != 0)
    {
      x0 = 0x18;
      y0 = 0x12;
      dy = 3;
      F(rec, void *, 0x480) = spawnTextNode(&D_800C7D54[1]);
      F(F(rec, void *, 0x478), u16, 0x26) >>= 1;
      F(F(rec, void *, 0x478), u8, 0x29) >>= 1;
      F(F(rec, void *, 0x480), s16, 0x26) = 0x1A;
      F(F(rec, void *, 0x47C), u16, 0x26) >>= 1;
      F(F(rec, void *, 0x47C), u8, 0x29) >>= 1;
      F(F(rec, void *, 0x404), u16, 0x26) >>= 1;
      F(F(rec, void *, 0x404), u8, 0x29) >>= 1;
      F(F(rec, void *, 0x408), u16, 0x26) >>= 1;
      F(F(rec, void *, 0x408), u8, 0x29) >>= 1;
      F(F(rec, void *, 0x480), s16, 0x20) = x0;
      F(F(rec, void *, 0x480), s16, 0x22) = y0;
    }
    else
    {
      x0 = 0x24;
      y0 = 0x15;
      dy = 6;
      m = spawnTrackMarker((s8) F(rec, u8, 0x182));
      initObjectFromBankEntry(m, 0x2B, 0x1B);
F(m, s16, 0x20) = 0x14;
F(m, s16, 0x22) = 0x13;
F(m, u16, 0x1E) = F(m, u16, 0x1E) | 2;
w = F(m, s32, 0x28); w &= ~0xFC; w |= 0x10; F(m, s32, 0x28) = w;
F(m, s32, 0x10) = 0xFF0000C8;
F(rec, void *, 0x484) = m;
      m = spawnTrackMarker((s8) F(rec, u8, 0x182));
      initObjectFromBankEntry(m, 0x2C, 0x1B);
      F(m, s16, 0x20) = 0x55;
      F(m, u16, 0x1E) |= 2;
      w2 = F(m, s32, 0x28); w2 &= ~0xFC; w2 |= 0x1C; F(m, s32, 0x28) = w2;
      F(m, s16, 0x22) = 0x13;
      F(m, s32, 0x10) = 0xFFC8;
      F(rec, void *, 0x488) = m;
      F(rec, void *, 0x480) = spawnTrackMarker((s8) F(rec, u8, 0x182));
      initObjectFromBankEntry(F(rec, void *, 0x480), 0xC, 0x2A);
      F(F(rec, void *, 0x480), u16, 0x1E) |= 2;
      F(F(rec, void *, 0x480), s16, 0x20) = 0x16;
      F(F(rec, void *, 0x480), s16, 0x22) = 0x13;
    }
    yy = y0 + 1;
    F(F(rec, void *, 0x478), s16, 0x20) = x0 + 1;
    F(F(rec, void *, 0x478), s16, 0x22) = yy;
    F(F(rec, void *, 0x47C), s16, 0x20) = x0 + 1;
    F(F(rec, void *, 0x47C), s16, 0x22) = dy + yy;
    ydy = 0x114 - x0;
    F(F(rec, void *, 0x404), s16, 0x20) = ydy + 1;
    F(F(rec, void *, 0x404), s16, 0x22) = yy;
    F(F(rec, void *, 0x408), s16, 0x20) = ydy;
    F(F(rec, void *, 0x408), s16, 0x22) = y0;
    F(rec, void *, 0x40C) = spawnTrackMarker((s8) F(rec, u8, 0x182));
    initObjectFromBankEntry(F(rec, void *, 0x40C), 0x30, 0x1B);
    F(F(rec, void *, 0x40C), u16, 0x1E) |= 2;
    F(F(rec, void *, 0x40C), s16, 0x20) = 0xE0;
    F(F(rec, void *, 0x40C), s16, 0x22) = 0x11;
    F(F(rec, void *, 0x40C), s32, 0x28) = (F(F(rec, void *, 0x40C), s32, 0x28) & ~0xFC) | 0x1C;
    F(F(rec, void *, 0x40C), s32, 0x10) = 0xFFFF00;
    F(F(rec, void *, 0x478), s32, 0x28) = (F(F(rec, void *, 0x478), s32, 0x28) & ~0xFC) | 0x10;
    F(F(rec, void *, 0x480), s32, 0x28) = (F(F(rec, void *, 0x480), s32, 0x28) & ~0xFC) | 0x10;
    F(F(rec, void *, 0x47C), s32, 0x28) = (F(F(rec, void *, 0x47C), s32, 0x28) & ~0xFC) | 0x10;
    F(F(rec, void *, 0x478), s32, 0x10) = 0xAA00FF;
    F(F(rec, void *, 0x480), s32, 0x10) = 0xC8;
    F(F(rec, void *, 0x47C), s32, 0x10) = 0xAAFF;
    F(F(rec, void *, 0x404), s32, 0x10) = 0xAAAA00;
    F(F(rec, void *, 0x408), s32, 0x10) = 0;
    func_8007080C(rec);
    func_800649E4(obj);
    ex = (s16) arg0;
    tab = sTrackMarkerTable;
    tbl = &tab[ex];
    F(*tbl, f32, 0x4C) = 1.0f;
    ent = *tbl;
    fa = F(arg1, f32, 0);
    F(ent, f32, 0x10) = fa;
    F(ent, f32, 0x28) = fa;
    ent = *tbl;
    fa = F(arg1, f32, 4);
    F(ent, f32, 0x14) = fa;
    F(ent, f32, 0x2C) = fa;
    ent = *tbl;
    fa = F(arg1, f32, 8);
    F(ent, f32, 0x18) = fa;
    F(ent, f32, 0x30) = fa;
    F(*tbl, f32, 0x38) = F(arg2, f32, 4);
    F(*tbl, s32, 0xF4) = 0;
    F(*tbl, void *, 0x138) = obj;
    F(*tbl, s32, 0x130) = 0;
    func_80001D80(0);
    if (gBorderSkipActive != 0)
    {
      k = (u16) arg0;
      t = func_8002B9CC(inline_fn2(k));
      a3 = *(D_801001A3 + ((getSaveSlotIndex(k) & 0xFFFF) * 0x18));
      a1 = t;
      func_8000237C(obj, a1, 1, a3);
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
      func_8000237C(obj, a1, 1, 0);
    }
    func_80002BD0(obj, 0x159);
    F(rec, s8, 0x18F) = 0;
    func_80064630(obj);
    func_800015AC(obj, 0);
    func_800643EC(obj);
    a1x = F(obj->f68_p, s16, 0xA2);
    if (a1x != 0)
      clearProbeState(obj, a1x);
    func_80067AE8(obj);
    ctl = obj->f68_p;
    bb = F(ctl, u8, 0xE);
    F(ctl, u8, 0xF) = bb;
    F(ctl, u8, 0x10) = bb;
    if (gBorderSkipActive == 0)
    {
      o0 = F(arg3, u16, 0x2C);
      v = F(arg3, u16, 0x2E);
      t1 = F(arg3, u16, 0x30);
      t2 = F(arg3, u16, 0x32);
      one = 1;
      ((RecA *) rec)->slot[o0].f0 = one;
      *(u16 *) ((char *) rec + (D_800C471C[o0].f0 << 1) + 0x1BC) = v;
      ((RecA *) rec)->slot[(s16) func_80063C7C((s16) o0)].f3 = *(D_800C471E + o0 * 0xE8);
      ((RecA *) rec)->slot[t1].f0 = one;
      *(u16 *) ((char *) rec + (D_800C471C[t1].f0 << 1) + 0x1BC) = t2;
      ((RecA *) rec)->slot[(s16) func_80063C7C((s16) t1)].f3 = *(D_800C471E + t1 * 0xE8);
      if (((gGameMode == 0x26) | (gGameMode == 1)) != 0)
        F(rec, s8, 0x21E) = one;
      if (gGameMode != 0x19)
      {
        F(rec, s8, 0x304) = one;
        F(rec, s8, 0x30C) = one;
        F(rec, s8, 0x314) = one;
        F(rec, s8, 0x31C) = one;
        F(rec, s8, 0x307) = 0x64;
        F(rec, s8, 0x317) = 0x64;
        cv = 0xC;
        if (gGameMode != 2)
          cv = (-(gGameMode == 0x26)) & 0xC;
        F(rec, s8, 0x30F) = cv;
      }
      setActionSlot(rec, F(arg3, u8, 0x35), 1, 1);
      setActionSlot(rec, F(arg3, u8, 0x37), 1, 1);
      setActionSlot(rec, F(arg3, u8, 0x39), 1, 1);
      setActionSlot(rec, F(arg3, u8, 0x3B), 1, 1);
      setActionSlot(rec, F(arg3, u8, 0x3F), 1, 1);
      if (D_80112F6D != 0)
      {
        k = 0;
        do
        {
          setActionSlot(rec, k & 0xFF, 1, 0);
          k += 1;
        }
        while (k < 0x1EU);
      }
    }
    switch ((s16) arg0)
    {
      case 0:
        obj->f5C_s32 = 0x2000;
        F(rec, s32, 0) = 0x7D000;
        break;
      case 1:
        obj->f5C_s32 = 0x4000;
        F(rec, s32, 0) = 0x7B000;
        break;
      case 2:
        obj->f5C_s32 = 0x8000;
        F(rec, s32, 0) = 0x77000;
        break;
      case 3:
        obj->f5C_s32 = 0x10000;
        F(rec, s32, 0) = 0x6F000;
        break;
    }
    obj->f58_s32 |= 0x2400;
    ex2 = (s16) arg0;
    tab2 = sTrackMarkerTable;
    tbl2 = &tab2[ex2];
    obj->f5C_s32 |= 0x600;
    F(*tbl2, s32, 0x100) &= ~7;
    F(*tbl2, s32, 0x100) |= 1;
    obj->f7F_u8 = 0xFF;
    obj->f80_u8 = 0xFF;
    obj->f81_u8 = 0xFF;
    obj->f82_u8 = 0xFF;
    obj->f7E_s8 = 1;
    F(rec, s32, 0x60) = 0;
    F(rec, s32, 0x64) = 0;
    if (gBorderSkipActive != 0)
    {
      if (ex2 < gSaveSlotCount)
        obj->f74_f32 = (f32) (*(D_801001A0 + ((getSaveSlotIndex((u16) arg0) & 0xFFFF) * 0x18)));
      else
        obj->f74_f32 = (f32) ((*(D_800BF688 + (inline_fn2((u16) arg0) * 0xC))) * 5);
    }
    else
      obj->f74_f32 = 100.0f;
F(rec, s8, 0x199) = 0;
F(rec, f32, 0x68) = obj->f74_f32;
F(rec, s8, 0x18C) = 0;
F(rec, u8, 0x18D) = 0x80;
    if (gBorderSkipActive != 0)
      func_8011ACAC(obj, rec, arg0 & 0xFF);
    F(rec, s8, 0x17E) = 3;
    F(obj->f68_p, f32, 8) = obj->f28_f32 - 2.0f;
  }
  if (gBorderSkipActive != 0)
  {
    D_800C7C98 = 10.0f;
    D_800C7C9C = 16.0f;
  }
  else
  {
    switch (sDifficultyLevel)
    {
      case 0:
      default:
        D_800C7C98 = 12.0f;
        D_800C7C9C = 18.0f;
        break;
      case 1:
        D_800C7C98 = 8.0f;
        D_800C7C9C = 14.0f;
        break;
      case 2:
        D_800C7C98 = 0;
        D_800C7C9C = 0;
        break;
    }
  }
  return obj;
}
