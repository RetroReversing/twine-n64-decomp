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
short func_800671E0();
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
extern unsigned char D_800C471C[];
extern char D_800C471E[];
extern f32 D_800C7C98;
extern f32 D_800C7C9C;
extern s16 D_800C7D74;
extern s16 D_800C7D98;
extern s8 D_800E19F4;
extern unsigned char D_801001A0[];
extern char D_801001A3[];
extern char D_80102CD0[];
extern s8 D_80103EB0;
extern u8 D_80112F6D;
extern s32 gBorderSkipActive;
extern s32 gGameMode;
extern s32 *gProbeObjectList;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo;
extern s32 sBonusObjectTable;
extern u8 sDifficultyLevel;
extern void *sTrackMarkerTable[];
inline static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

typedef struct 
{
  f32 v;
} Field_f32;
typedef struct 
{
  s16 v;
} Field_s16;
typedef struct 
{
  s32 v;
} Field_s32;
typedef struct 
{
  s8 v;
} Field_s8;
typedef struct 
{
  u8 v;
} Field_u8;
inline static s32 inline_fn2(unsigned short arg0)
{
  return *((s32 *) (((u8 *) (&gSaveSlotInfo)) + ((getSaveSlotIndex(arg0) & 0xFFFF) * 0x18)));
}

inline static int inline_fn23(s32 arg0)
{
  return ((arg0 + 1) - 1) < 2;
}

void *func_80064A18(s16 arg0, void *arg1_in, void *arg2, void *arg3)
{
  void *arg1;
  volatile s32 padding[2];
  void *sp14;
  f32 var_fv0;
  f32 var_fv1;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  register s16 *temp_s0_2;
  s16 *temp_s1_2;
  s16 temp_a1;
  s16 temp_a1_2;
  s16 temp_v0;
  s16 temp_v1_10;
  s32 temp_v0_2;
  s16 temp_v1_11;
  s16 var_s2;
  s16 var_v1;
  int var_v1_2;
  s32 temp_s0;
  s32 __repair_phase_temp_s0;
  s32 temp_s0_4;
  s32 temp_s0_5;
  s32 temp_s0_6;
  s32 temp_s1;
  s32 temp_v1_19;
  s32 var_a1;
  unsigned short var_s1;
  s32 var_s5;
  register s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_5;
  s32 var_v1_4;
  s8 var_v1_3;
  u16 temp_a0;
  unsigned int temp_s1_3;
  u16 temp_s2;
  u32 var_s0;
  u8 temp_v1_18;
  u8 var_a3;
  void **temp_a0_2;
  void **temp_v1_17;
  void *temp_a1_3;
  void *temp_s3;
  void *temp_s4;
  void *temp_v0_10;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v0_7;
  void *temp_v0_8;
  void *temp_v0_9;
  void *temp_v1;
  void *temp_v1_12;
  void *temp_v1_13;
  void *temp_v1_14;
  void *temp_v1_15;
  void *temp_v1_16;
  void *temp_v1_20;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4;
  void *temp_v1_5;
  void *temp_v1_6;
  void *temp_v1_7;
  void *temp_v1_8;
  void *temp_v1_9;
  void *var_v0;
  arg1 = arg1_in;
  sp14 = arg2;
  if ((gBorderSkipActive == 0) && ((*((u16 *) (((char *) arg3) + 0x40))) != sDifficultyLevel))
  {
    goto rejected;
  }
  if (1)
  {
    do
    {
      temp_s4 = func_800164F8(0x5AC, arg1, 0); temp_s0 = ((s32) (arg0 << 0x10)) >> 0xE; D_800E19F4 = 0;
      *((void **) (((char *) (&sBonusObjectTable)) + temp_s0)) = temp_s4;
    }
    while (0);
    if (temp_s4 != NULL)
    {
      temp_s3 = *((void **) (((char *) temp_s4) + 0x6C));
      func_80077C00(temp_s4);
      temp_s1 = arg0 & 0xFF;
      *((s32 *) (((char *) temp_s3) + 0x1B0)) = 0;
      *((u8 *) (((char *) temp_s3) + 0x182)) = arg0;
      *((s8 *) (((char *) temp_s3) + 0x183)) = func_80081828(temp_s1);
      *((s32 *) (D_80102CD0 + temp_s0)) = temp_s3;
      *((s32 *) (((char *) temp_s3) + 0x104)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x108)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x10C)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x110)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x114)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x118)) = 0;
      *((s32 *) (((char *) temp_s3) + 0xC0)) = 0;
      D_80103EB0 = 1;
      *((s8 *) (((char *) temp_s3) + 0x198)) = 0;
      *((s8 *) (((char *) temp_s3) + 0x197)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x1C)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x20)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x24)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x28)) = 0;
      *((f32 *) (((char *) temp_s3) + 0x9C)) = 3.1415927f;
      if (gBorderSkipActive != 0)
      {
        initSaveMenuSlot(temp_s3, temp_s1);
      }
      else
      {
        *((s32 *) (((char *) temp_s3) + 0xB4)) = 0;
      }
      *((s32 *) (((char *) temp_s3) + 0xCC)) = 0;
      *((s32 *) (((char *) temp_s3) + 4)) = 0;
      *((s32 *) (((char *) temp_s3) + 0xA8)) = func_800671E0(temp_s4, (s16) arg0);
      *((s32 *) (((char *) temp_s3) + 0x6C)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x70)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x74)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x78)) = 0;
      *((s32 *) (((char *) temp_s3) + 0xC)) = -1;
      *((s32 *) (((char *) temp_s3) + 8)) = -1;
      *((s16 *) (((char *) temp_s3) + 0x176)) = 0;
      *((s16 *) (((char *) temp_s3) + 0x178)) = 0;
      *((s16 *) (((char *) temp_s3) + 0x17A)) = 0;
      *((s8 *) (((char *) temp_s3) + 0x19A)) = 0;
      *((void **) (((char *) temp_s3) + 0xAC)) = func_80064444(temp_s4, (s16) arg0);
      *((void **) (((char *) temp_s3) + 0xB0)) = func_8006452C(temp_s4, (s16) arg0);
      *((void **) (((char *) (*((void **) (((char *) temp_s3) + 0xAC)))) + 0x18)) = temp_s4;
      *((void **) (((char *) (*((void **) (((char *) temp_s3) + 0xB0)))) + 0x18)) = temp_s4;
      *((s32 *) (((char *) temp_s3) + 0xC4)) = func_800644CC(temp_s4);
      *((s32 *) (((char *) temp_s3) + 0xBC)) = 0;
      ((Field_s16 *) (((char *) temp_s4) + 0x78))->v = 2;
      ((Field_s32 *) (((char *) temp_s4) + 0x3C))->v = 0;
      ((Field_s32 *) (((char *) temp_s4) + 0x44))->v = 0;
      ((Field_f32 *) (((char *) temp_s4) + 0x40))->v = (f32) (*((f32 *) (((char *) sp14) + 4)));
      actorLinkToSurface(*gProbeObjectList, temp_s4, 0);
      var_v1 = 0;
      *((s8 *) (((char *) temp_s3) + 0x184)) = 0;
      *((s8 *) (((char *) temp_s3) + 0x185)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x410)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x414)) = 0;
      do
      {
        *((s32 *) (((char *) ((((var_v1 << 15) << 1) >> 0xE) + temp_s3)) + 0x3D4)) = 0;
        do
        {
          if (1)
          {
            do
            {
              do
              {
                temp_v0 = var_v1 + 1;
              }
              while (0);
            }
            while (0);
          }
        }
        while (0);
        var_v1 = temp_v0;
      }
      while ((temp_v0 + 1) <= 4);
      var_v1_2 = 0;
      do
      {
        *((s32 *) (((char *) (((var_v1_2 << 0x10) >> 0xE) + temp_s3)) + 0x3E4)) = 0;
        temp_v0_2 = var_v1_2 + 1;
        var_v1_2 = temp_v0_2;
      }
      while (((temp_v0_2 + 1) - 1) < 6);
      *((s32 *) (((char *) temp_s3) + 0x3FC)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x400)) = 0;
      *((s16 *) (((char *) temp_s3) + 0x520)) = 0x706;
      temp_s1_2 = &D_800C7D74;
      *((volatile s16 *) temp_s1_2) = (s16) ((s8) (*((u8 *) (((char *) temp_s3) + 0x182))));
      D_800C7D98 = (s16) ((s8) (*((u8 *) (((char *) temp_s3) + 0x182))));
      temp_s0_2 = (s16 *) (((char *) temp_s1_2) + 4);
      *((void **) (((char *) temp_s3) + 0x404)) = spawnTextNode(temp_s1_2);
      *((void **) (((char *) temp_s3) + 0x408)) = spawnTextNode(temp_s0_2);
      *((void **) (((char *) temp_s3) + 0x478)) = spawnTextNode(temp_s1_2);
      *((void **) (((char *) temp_s3) + 0x47C)) = spawnTextNode(temp_s1_2);
      if (gBorderSkipActive != 0)
      {
        temp_v1 = *((void **) (((char *) temp_s3) + 0x478));
        *((void **) (((char *) temp_s3) + 0x480)) = spawnTextNode(temp_s0_2);
        *((u16 *) (((char *) temp_v1) + 0x26)) = (u16) (((u16) (*((u16 *) (((char *) temp_v1) + 0x26)))) >> 1);
        temp_v1_2 = *((void **) (((char *) temp_s3) + 0x478));
        *((u8 *) (((char *) temp_v1_2) + 0x29)) = (u8) (((u8) (*((u8 *) (((char *) temp_v1_2) + 0x29)))) >> 1);
        *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x480)))) + 0x26)) = 0x1A;
        temp_v1_3 = *((void **) (((char *) temp_s3) + 0x47C));
        *((u16 *) (((char *) temp_v1_3) + 0x26)) = (u16) (((u16) (*((u16 *) (((char *) temp_v1_3) + 0x26)))) >> 1);
        temp_v1_4 = *((void **) (((char *) temp_s3) + 0x47C));
        *((u8 *) (((char *) temp_v1_4) + 0x29)) = (u8) (((u8) (*((u8 *) (((char *) temp_v1_4) + 0x29)))) >> 1);
        temp_v1_5 = *((void **) (((char *) temp_s3) + 0x404));
        *((u16 *) (((char *) temp_v1_5) + 0x26)) = (u16) (((u16) (*((u16 *) (((char *) temp_v1_5) + 0x26)))) >> 1);
        temp_v1_6 = *((void **) (((char *) temp_s3) + 0x404));
        *((u8 *) (((char *) temp_v1_6) + 0x29)) = (u8) (((u8) (*((u8 *) (((char *) temp_v1_6) + 0x29)))) >> 1);
        temp_v1_7 = *((void **) (((char *) temp_s3) + 0x408));
        *((u16 *) (((char *) temp_v1_7) + 0x26)) = (u16) (((u16) (*((u16 *) (((char *) temp_v1_7) + 0x26)))) >> 1);
        temp_v1_8 = *((void **) (((char *) temp_s3) + 0x408));
        *((u8 *) (((char *) temp_v1_8) + 0x29)) = (u8) (((u8) (*((u8 *) (((char *) temp_v1_8) + 0x29)))) >> 1);
        var_s1 = 0x18;
        *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x480)))) + 0x20)) = 0x18;
        var_s5 = 3;
        var_s2 = 0x12;
        *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x480)))) + 0x22)) = 0x12;
      }
      else
      {
        temp_v0_3 = spawnTrackMarker((s8) (*((u8 *) (((char *) temp_s3) + 0x182))));
        initObjectFromBankEntry(temp_v0_3, 0x2B, 0x1B);
        *((s16 *) (((char *) temp_v0_3) + 0x20)) = 0x14;
        do
        {
          *((s16 *) (((char *) temp_v0_3) + 0x22)) = 0x13;
          *((s32 *) (((char *) temp_v0_3) + 0x10)) = 0xFF0000C8;
          *((u16 *) (((char *) temp_v0_3) + 0x1E)) |= 2;
          *((s32 *) (((char *) temp_v0_3) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v0_3) + 0x28))) & (~0xFC)) | 0x10);
          *((void **) (((char *) temp_s3) + 0x484)) = temp_v0_3; temp_v0_4 = spawnTrackMarker((s8) (*((u8 *) (((char *) temp_s3) + 0x182))));
          initObjectFromBankEntry(temp_v0_4, 0x2C, 0x1B);
          *((s16 *) (((char *) temp_v0_4) + 0x20)) = 0x55;
          *((s32 *) (((char *) temp_v0_4) + 0x10)) = 0xFFC8;
          *((s16 *) (((char *) temp_v0_4) + 0x22)) = 0x13;
          *((s32 *) (((char *) temp_v0_4) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v0_4) + 0x28))) & (~0xFC)) | 0x1C);
          *((u16 *) (((char *) temp_v0_4) + 0x1E)) |= 2;
          *((void **) (((char *) temp_s3) + 0x488)) = temp_v0_4; temp_v0_5 = spawnTrackMarker((s8) (*((u8 *) (((char *) temp_s3) + 0x182))));
          *((void **) (((char *) temp_s3) + 0x480)) = temp_v0_5;
          initObjectFromBankEntry(temp_v0_5, 0xC, 0x2A);
          *((u16 *) (inline_fn(*((void **) (((char *) temp_s3) + 0x480))) + 0x1E)) |= 2; var_s1 = 0x24;
          *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x480)))) + 0x20)) = 0x16; var_s2 = 0x15; var_s5 = 6;
          *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x480)))) + 0x22)) = 0x13;
        }
        while (0);
      }
      ;
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x478)))) + 0x20)) = var_s1 + 1;
      __repair_phase_temp_s0 = (s16) (var_s2 + 1);
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x478)))) + 0x22)) = (s16) (var_s2 + 1);
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x47C)))) + 0x20)) = var_s1 + 1;
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x47C)))) + 0x22)) = (s16) (var_s5 + ((s16) (var_s2 + 1)));
      temp_v1_11 = 0x114 - var_s1;
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x404)))) + 0x20)) = (s16) (temp_v1_11 + 1);
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x404)))) + 0x22)) = (s16) (var_s2 + 1);
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x408)))) + 0x20)) = temp_v1_11;
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x408)))) + 0x22)) = var_s2;
      temp_v0_6 = spawnTrackMarker((s8) (*((u8 *) (((char *) temp_s3) + 0x182))), __repair_phase_temp_s0);
      *((void **) (((char *) temp_s3) + 0x40C)) = temp_v0_6;
      initObjectFromBankEntry(temp_v0_6, 0x30, 0x1B);
      temp_v1_12 = *((void **) (((char *) temp_s3) + 0x40C));
      *((u16 *) (((char *) temp_v1_12) + 0x1E)) |= 2;
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x40C)))) + 0x20)) = 0xE0;
      *((s16 *) (((char *) (*((void **) (((char *) temp_s3) + 0x40C)))) + 0x22)) = 0x11;
      temp_v1_13 = *((void **) (((char *) temp_s3) + 0x40C));
      *((s32 *) (((char *) temp_v1_13) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_13) + 0x28))) & (~0xFC)) | 0x1C);
      *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x40C)))) + 0x10)) = 0xFFFF00;
      temp_v1_14 = *((void **) (((char *) temp_s3) + 0x478));
      *((s32 *) (((char *) temp_v1_14) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_14) + 0x28))) & (~0xFC)) | 0x10);
      temp_v1_15 = *((void **) (((char *) temp_s3) + 0x480));
      *((s32 *) (((char *) temp_v1_15) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_15) + 0x28))) & (~0xFC)) | 0x10);
      temp_v1_16 = *((void **) (((char *) temp_s3) + 0x47C));
      *((s32 *) (((char *) temp_v1_16) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_16) + 0x28))) & (~0xFC)) | 0x10);
      *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x478)))) + 0x10)) = 0xAA00FF;
      *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x480)))) + 0x10)) = 0xC8;
      *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x47C)))) + 0x10)) = 0xAAFF;
      *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x404)))) + 0x10)) = 0xAAAA00;
      *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x408)))) + 0x10)) = 0;
      func_8007080C(temp_s3);
      func_800649E4(temp_s4);
      temp_v1_17 = &sTrackMarkerTable[arg0];
      *((f32 *) (((char *) (*temp_v1_17)) + 0x4C)) = 1.0f;
      temp_v0_7 = *temp_v1_17;
      temp_fv0 = *((f32 *) (((char *) arg1) + 0));
      *((f32 *) (((char *) temp_v0_7) + 0x10)) = temp_fv0;
      *((f32 *) (((char *) temp_v0_7) + 0x28)) = temp_fv0;
      temp_v0_8 = *temp_v1_17;
      temp_fv0_2 = *((f32 *) (((char *) arg1) + 4));
      *((f32 *) (((char *) temp_v0_8) + 0x14)) = temp_fv0_2;
      *((f32 *) (((char *) temp_v0_8) + 0x2C)) = temp_fv0_2;
      temp_v0_9 = *temp_v1_17;
      temp_fv0_3 = *((f32 *) (((char *) arg1) + 8));
      *((f32 *) (((char *) temp_v0_9) + 0x18)) = temp_fv0_3;
      *((f32 *) (((char *) temp_v0_9) + 0x30)) = temp_fv0_3;
      *((f32 *) (((char *) (*temp_v1_17)) + 0x38)) = (f32) (*((f32 *) (((char *) sp14) + 4)));
      *((s32 *) (((char *) (*temp_v1_17)) + 0xF4)) = 0;
      *((void **) (((char *) (*temp_v1_17)) + 0x138)) = temp_s4;
      *((s32 *) (((char *) (*temp_v1_17)) + 0x130)) = 0;
      func_80001D80(0);
      var_s1 = arg0 & 0xFFFF;
      if (gBorderSkipActive != 0)
      {
        temp_s0_4 = func_8002B9CC(inline_fn2(var_s1));
        var_a3 = *(D_801001A3 + ((getSaveSlotIndex(var_s1) & 0xFFFF) * 0x18));
        var_a1 = temp_s0_4;
      }
      else
      {
        switch (gGameMode)
        {
          default:
            var_a1 = 0x11;
            break;

          case 25:
            var_a1 = 0x10;
            break;

          case 1:

          case 38:
            var_a1 = 0xC;
            break;

          case 11:
            var_a1 = 0xE;
            break;

          case 18:

          case 28:

          case 29:

          case 33:
            var_a1 = 0xB;
            break;

        }

        var_a3 = 0;
      }
      func_8000237C(temp_s4, var_a1, 1, var_a3);
      func_80002BD0(temp_s4, 0x159);
      *((s8 *) (((char *) temp_s3) + 0x18F)) = 0;
      func_80064630(temp_s4);
      func_800015AC(temp_s4, 0);
      func_800643EC(temp_s4);
      temp_a1_2 = *((s16 *) (((char *) (*((void **) (((char *) temp_s4) + 0x68)))) + 0xA2));
      if (temp_a1_2 != 0)
      {
        clearProbeState(temp_s4, temp_a1_2);
      }
      func_80067AE8(temp_s4);
      temp_v0_10 = *((void **) (((char *) temp_s4) + 0x68));
      temp_v1_18 = *((u8 *) (((char *) temp_v0_10) + 0xE));
      *((u8 *) (((char *) temp_v0_10) + 0xF)) = temp_v1_18;
      *((u8 *) (((char *) temp_v0_10) + 0x10)) = temp_v1_18;
      if (gBorderSkipActive == 0)
      {
        temp_a0 = *((u16 *) (((char *) arg3) + 0x2C));
        temp_s1_3 = *((u16 *) (((char *) arg3) + 0x30));
        temp_s2 = *((u16 *) (((char *) arg3) + 0x32));
        temp_s0_5 = temp_a0 * 0xE8;
        *((s8 *) (((char *) (temp_s3 + (temp_a0 * 8))) + 0x1FC)) = 1;
        *((u16 *) (((char *) (temp_s3 + ((*(D_800C471C + temp_s0_5)) * 2))) + 0x1BC)) = (u16) (*((u16 *) (((char *) arg3) + 0x2E)));
        *((u8 *) (((char *) (temp_s3 + (((s32) (func_80063C7C((s16) temp_a0) << 0x10)) >> 0xD))) + 0x1FF)) = (u8) (*(D_800C471E + temp_s0_5));
        temp_s0_6 = temp_s1_3 * 0xE8;
        *((s8 *) (((char *) (temp_s3 + (temp_s1_3 * 8))) + 0x1FC)) = 1;
        *((u16 *) (((char *) (temp_s3 + ((*(D_800C471C + temp_s0_6)) * 2))) + 0x1BC)) = temp_s2;
        *((u8 *) (((char *) (temp_s3 + (((s32) (func_80063C7C((s16) temp_s1_3) << 0x10)) >> 0xD))) + 0x1FF)) = (u8) (*(D_800C471E + temp_s0_6));
        if (((gGameMode == 0x26) | (gGameMode == 1)) != 0)
        {
          *((s8 *) (((char *) temp_s3) + 0x21E)) = 1;
        }
        if (gGameMode != 0x19)
        {
          *((s8 *) (((char *) temp_s3) + 0x304)) = 1;
          *((s8 *) (((char *) temp_s3) + 0x30C)) = 1;
          *((s8 *) (((char *) temp_s3) + 0x314)) = 1;
          *((s8 *) (((char *) temp_s3) + 0x31C)) = 1;
          *((s8 *) (((char *) temp_s3) + 0x307)) = 0x64;
          *((s8 *) (((char *) temp_s3) + 0x317)) = 0x64;
          var_v1_3 = 0xC;
          if (gGameMode != 2)
          {
            var_v1_3 = (-(gGameMode == 0x26)) & 0xC;
          }
          *((s8 *) (((char *) temp_s3) + 0x30F)) = var_v1_3;
        }
        setActionSlot(temp_s3, *((u8 *) (((char *) arg3) + 0x35)), 1, 1);
        setActionSlot(temp_s3, *((u8 *) (((char *) arg3) + 0x37)), 1, 1);
        setActionSlot(temp_s3, *((u8 *) (((char *) arg3) + 0x39)), 1, 1);
        setActionSlot(temp_s3, *((u8 *) (((char *) arg3) + 0x3B)), 1, 1);
        setActionSlot(temp_s3, *((u8 *) (((char *) arg3) + 0x3F)), 1, 1);
        if (D_80112F6D != 0)
        {
          var_s0 = 0;
          do
          {
            setActionSlot(temp_s3, var_s0 & 0xFF, 1, 0);
            var_s0 += 1;
          }
          while (var_s0 < 0x1EU);
        }
      }
      var_v0_4 = arg0 << 0x10;
      temp_v1_19 = var_v0_4 >> 0x10;
      switch (temp_v1_19)
      {
        case 0:
          var_v1_4 = 0x7D000;
          var_v0_5 = 0x2000;
          ((Field_s32 *) (((char *) temp_s4) + 0x5C))->v = var_v0_5;
          *((s32 *) (((char *) temp_s3) + 0)) = var_v1_4;
          break;

        case 1:
          var_v1_4 = 0x7B000;
          var_v0_5 = 0x4000;
          ((Field_s32 *) (((char *) temp_s4) + 0x5C))->v = var_v0_5;
          *((s32 *) (((char *) temp_s3) + 0)) = 0x7B000;
          break;

        case 2:
          var_v1_4 = 0x77000;
          var_v0_5 = 0x8000;
          ((Field_s32 *) (((char *) temp_s4) + 0x5C))->v = var_v0_5;
          *((s32 *) (((char *) temp_s3) + 0)) = var_v1_4;
          break;

        case 3:
          var_v1_4 = 0x6F000;
          var_v0_5 = 0x10000;
          ((Field_s32 *) (((char *) temp_s4) + 0x5C))->v = var_v0_5;
          *((s32 *) (((char *) temp_s3) + 0)) = var_v1_4;
          break;

      }

      ((Field_s32 *) (((char *) temp_s4) + 0x58))->v |= 0x2400;
      temp_a0_2 = &sTrackMarkerTable[arg0];
      ((Field_s32 *) (((char *) temp_s4) + 0x5C))->v |= 0x600;
      temp_a1_3 = *temp_a0_2;
      *((s32 *) (((char *) temp_a1_3) + 0x100)) &= ~7;
      temp_v1_20 = *temp_a0_2;
      *((s32 *) (((char *) temp_v1_20) + 0x100)) |= 1;
      ((Field_u8 *) (((char *) temp_s4) + 0x7F))->v = 0xFF;
      ((Field_u8 *) (((char *) temp_s4) + 0x80))->v = 0xFF;
      ((Field_u8 *) (((char *) temp_s4) + 0x81))->v = 0xFF;
      ((Field_u8 *) (((char *) temp_s4) + 0x82))->v = 0xFF;
      ((Field_s8 *) (((char *) temp_s4) + 0x7E))->v = 1;
      *((s32 *) (((char *) temp_s3) + 0x60)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x64)) = 0;
      if (gBorderSkipActive != 0)
      {
        if (((s16) arg0) < gSaveSlotCount)
        {
          ((Field_f32 *) (((char *) temp_s4) + 0x74))->v = (f32) (*(D_801001A0 + ((getSaveSlotIndex(arg0 & 0xFFFF) & 0xFFFF) * 0x18)));
        }
        else
        {
          ((Field_f32 *) (((char *) temp_s4) + 0x74))->v = (f32) ((*(D_800BF688 + (inline_fn2(arg0 & 0xFFFF) * 0xC))) * 5);
        }
      }
      else
      {
        ((Field_f32 *) (((char *) temp_s4) + 0x74))->v = 100.0f;
      }
      *((s8 *) (((char *) temp_s3) + 0x199)) = 0;
      *((s8 *) (((char *) temp_s3) + 0x18C)) = 0;
      *((u8 *) (((char *) temp_s3) + 0x18D)) = 0x80;
      *((f32 *) (((char *) temp_s3) + 0x68)) = (f32) ((Field_f32 *) (((char *) temp_s4) + 0x74))->v;
      if (gBorderSkipActive != 0)
      {
        func_8011ACAC(temp_s4, temp_s3, arg0 & 0xFF);
      }
      *((s8 *) (((char *) temp_s3) + 0x17E)) = 3;
      *((f32 *) (((char *) (*((void **) (((char *) temp_s4) + 0x68)))) + 8)) = (f32) (((Field_f32 *) (((char *) temp_s4) + 0x28))->v - 2.0f);
    }
    if (gBorderSkipActive != 0)
    {
      var_fv0 = 10.0f;
      var_fv1 = 16.0f;
      D_800C7C98 = var_fv0;
      D_800C7C9C = var_fv1;
      return temp_s4;
    }
    if (sDifficultyLevel != 1)
    {
      do
      {
        if (inline_fn23((s32) sDifficultyLevel) || ((var_v0 = temp_s4, sDifficultyLevel != 2)))
        {
          var_fv0 = 12.0f; var_fv1 = 18.0f; D_800C7C98 = var_fv0;
          D_800C7C9C = var_fv1;
          return temp_s4;
        }
        if (__repair_phase_temp_s0)
        {
          D_800C7C98 = 0;
          D_800C7C9C = 0;
          return var_v0;
        }
        else
        {
          D_800C7C98 = 0;
          D_800C7C9C = 0;
          return var_v0;
        }
      }
      while (0);
    }
    var_fv0 = 8.0f;
    var_fv1 = 14.0f;
    D_800C7C98 = var_fv0;
    D_800C7C9C = var_fv1;
    return temp_s4;
  }
  rejected:
  return NULL;

}

