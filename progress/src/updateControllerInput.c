typedef struct { s16 a; s16 b; s16 c; s16 d; } Src8;
typedef struct { s32 x; s32 y; s32 dx; s32 dy; s32 e; s32 f; s32 g; s32 h; u8 pad[0x80]; } Dst160;
extern Dst160 D_80115108[];
s32 pollControllersAndRunSaveCommand();
s32 updateInputBindingStates(s32 *, u8, int, void *);
s32 absS32(s32);
s32 signOf(s32);
s32 updateDemoPlayback();
s32 memset(s32 *, s32, s32);
extern s32 D_800C9D70;
extern s32 D_800C9DF8;
extern s32 D_800C9E80;
extern s32 D_800C9F08;
extern s32 D_800C9F90;
extern s32 D_800C9FC8;
extern s32 D_800CA068;
extern s32 D_800CA108;
extern s32 D_800CA1A8;
extern s32 D_800CA248;
extern s32 D_800CA278;
extern u8 gDemoRecordingActive;
extern s32 D_800E1A80;
extern u8 D_801002AE;
extern u16 D_801002BA;
extern s32 gBorderSkipFlag;
extern s32 D_8010A500;
extern s32 gDemoButtons;
extern Src8 gDemoSticks[];
extern s32 D_80112E98[];
extern s32 D_80112E9C;
extern s32 D_80112EA0;
extern s32 D_80112EAC;
extern s32 D_80112EB0;
extern s32 D_80115091;
extern char gInputBindingTables;
/* Per-frame input update: polls controllers, handles demo record/playback, applies stick deadzone and deltas, and updates input bindings per player. */
void updateControllerInput(void)
{
  s32 port;
  s32 axis;
  s32 deadzoneMask;
  s32 r;
  s32 u;
  s16 playerCount;
  s32 sp24, sp2C;
  s32 var_t8;
  s32 temp_a2;
  s32 temp_a3;
  s32 temp_t0;
  s32 temp_t1;
  s32 temp_t2;
  s32 var_a0;
  s32 var_a1;
  s32 var_v0_3;
  s32 var_s2_2;
  s32 padIndex;
  s32 var_s0_5;
  s32 controlScheme;
  void *player;
  void *bindings;
  s32 temp_s0_5;
  s32 var_a1_2;
  s32 temp_s0_6;
  unsigned temp_s0_8;
  unsigned short temp_s0_7;
  void *var_a0_2;
  pollControllersAndRunSaveCommand();
  if (gDemoRecordingActive == 1) {
    func_80087A80();
  }
  if (gDemoRecordingActive == 2) {
    updateDemoPlayback();
  }
  for (port = 0; port < 4; port++) {
    axis = gDemoSticks[port].a;
    if (axis >= 0) { axis -= 4; deadzoneMask = ~axis >> 31; } else { axis += 4; deadzoneMask = -(axis < 1); }
    axis &= deadzoneMask; axis = (axis << 16) / 76;
    if (axis < -0x10000) axis = -0x10000; else if (axis > 0x10000) axis = 0x10000;
    D_80115108[port].dx = axis - D_80115108[port].x;
    D_80115108[port].x = axis;
    axis = gDemoSticks[port].a;
    { s32 w = signOf(axis & -(absS32(axis) >= 0x21));
    if (w != D_80115108[port].g) { D_80115108[port].g = w; D_80115108[port].e = w; } else { D_80115108[port].e = 0; } }
    axis = gDemoSticks[port].b;
    if (axis >= 0) { axis -= 4; deadzoneMask = ~axis >> 31; } else { axis += 4; deadzoneMask = -(axis < 1); }
    axis &= deadzoneMask; axis = (axis << 16) / 76;
    if (axis < -0x10000) axis = -0x10000; else if (axis > 0x10000) axis = 0x10000;
    D_80115108[port].dy = axis - D_80115108[port].y;
    D_80115108[port].y = axis;
    axis = gDemoSticks[port].b;
    { s32 w = signOf(axis & -(absS32(axis) >= 0x21));
    if (w != D_80115108[port].h) { D_80115108[port].h = w; D_80115108[port].f = w; } else { D_80115108[port].f = 0; } }
  }
  if (gBorderSkipFlag == 0) { playerCount = 4; } else { playerCount = D_801002BA; }
  {
    s32 playerIdx;
    for (playerIdx = 0; playerIdx < (s16)playerCount; playerIdx++)
    {
      s32 p8 = playerIdx * 8;
      memset(D_80112E98, 0, 0x24);
      player = ((void **) &D_8010A500)[playerIdx];
      controlScheme = *(((u8 *) (&D_80115091)) + (playerIdx * 0xA0));
      var_a1 = 1;
      if (player != NULL)
      {
        padIndex = *((s8 *) (((char *) (*((void **) (((char *) player) + 0x6C)))) + 0x183));
        var_s2_2 = *((u16 *) (((u8 *) (&gDemoButtons)) + (padIndex * 8)));
        var_a0 = ((s16 *) (&D_800E1A80))[padIndex];
        temp_a2 = var_s2_2 & 0x2000;
        temp_a3 = var_s2_2 & 0x4000;
        temp_t2 = -(temp_a3 != 0);
        temp_t0 = var_s2_2 & 0x8000;
        temp_t1 = -(temp_t0 != 0);
        var_v0_3 = var_a0 & 7;
        do
        {
          switch (var_v0_3)
          {
            default:
              if (temp_a2 != 0) { var_a0 = 1; }
              else if (temp_a3 != 0) { var_a0 = 2; }
              else if (temp_t0 != 0) { var_a0 = 3; }
              else { var_a1 = 0; }
              break;
            case 1:
              if (temp_a2 != 0) {
                D_80112E98[1] = 1;
                var_a1 = 0;
                if (temp_a3 != 0) { D_80112E98[2] = 1; }
              } else { var_a0 = 0; }
              break;
            case 2:
              if (temp_a3 != 0) {
                if (temp_a2 != 0) { D_80112E98[5] = 1; var_a0 = 4; }
                else if (temp_t0 != 0) { D_80112E98[6] = 1; var_a0 = 5; }
                else { var_a1 = 0; }
              } else {
                if (!(var_a0 & 8)) { D_80112E98[2] = 1; }
                var_a0 = 0;
              }
              break;
            case 3:
              if (temp_t0 != 0) {
                if (temp_a2 != 0) { D_80112E98[3] = 1; var_a0 = 6; }
                else if (temp_a3 != 0) { D_80112E98[7] = 1; var_a0 = 7; }
                else { var_a1 = 0; }
              } else {
                if (!(var_a0 & 8)) { D_80112E98[4] = 1; }
                var_a0 = 0;
              }
              break;
            case 4:
              if (temp_a2 != 0) { var_a1 = 0; } else { var_a0 = temp_t2 & 0xA; }
              break;
            case 5:
              if (temp_t0 != 0) { var_a1 = 0; } else { var_a0 = temp_t2 & 0xA; }
              break;
            case 6:
              if (temp_a2 != 0) { var_a1 = 0; } else { var_a0 = temp_t1 & 0xB; }
              break;
            case 7:
              if (temp_a3 != 0) { var_a1 = 0; } else { var_a0 = temp_t1 & 0xB; }
              break;
          }
          var_v0_3 = var_a0 & 7;
        }
        while (var_a1 != 0);
        ((s16 *) (&D_800E1A80))[padIndex] = var_a0;
      }
      else
      {
        padIndex = playerIdx;
        var_s2_2 = *((u16 *) (((u8 *) (&gDemoButtons)) + p8));
      }
      bindings = (playerIdx * 0xA0) + (&gInputBindingTables);
      updateInputBindingStates(&D_800CA278, (u8)padIndex, var_s2_2, bindings);
      if ((player != NULL) && (D_801002AE == 0))
      {
        switch (controlScheme)
        {
          case 0:
            updateInputBindingStates(&D_800C9D70, (u8)padIndex, var_s2_2, bindings);
            updateInputBindingStates(&D_800C9F90, (u8)padIndex, var_s2_2, bindings);
            break;
          case 1:
            updateInputBindingStates(&D_800C9DF8, (u8)padIndex, var_s2_2, bindings);
            updateInputBindingStates(&D_800C9F90, (u8)padIndex, var_s2_2, bindings);
            break;
          case 2:
            updateInputBindingStates(&D_800C9FC8, (u8)padIndex, var_s2_2, bindings);
            updateInputBindingStates(&D_800CA248, (u8)padIndex, var_s2_2, bindings);
            break;
          case 3:
            updateInputBindingStates(&D_800CA068, (u8)padIndex, var_s2_2, bindings);
            updateInputBindingStates(&D_800CA248, (u8)padIndex, var_s2_2, bindings);
            break;
          case 4:
            updateInputBindingStates(&D_800C9E80, (u8)padIndex, var_s2_2, bindings);
            updateInputBindingStates(&D_800C9F90, (u8)padIndex, var_s2_2, bindings);
            break;
          case 5:
            updateInputBindingStates(&D_800C9F08, (u8)padIndex, var_s2_2, bindings);
            updateInputBindingStates(&D_800C9F90, (u8)padIndex, var_s2_2, bindings);
            break;
          case 6:
            updateInputBindingStates(&D_800CA108, (u8)padIndex, var_s2_2, bindings);
            updateInputBindingStates(&D_800CA248, (u8)padIndex, var_s2_2, bindings);
            break;
          default:
            updateInputBindingStates(&D_800CA1A8, (u8)padIndex, var_s2_2, bindings);
            updateInputBindingStates(&D_800CA248, (u8)padIndex, var_s2_2, bindings);
            break;
        }
      }
    }
  }
}
