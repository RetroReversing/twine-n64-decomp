s32 func_80010590(s32);
s32 stop_controller_rumble(s32);
s32 func_80010690(s32);
s32 func_800107BC(s32);
s32 osContGetQuery(s32 *);
s32 osContGetReadData(u16 *);
s32 osContStartQuery(s32 *);
s32 osContStartReadData(s32 *);
s32 osEepromLongRead(s32 *, u8, s32, s32);
s32 osEepromLongWrite(s32 *, u8, s32, s32);
s32 osGbpakInit(s32 *, void *, s16);
s32 osMotorInit(s32 *, s32, s32);
s32 osPfsAllocateFile(s32, u16, s32, s32, s32, s32, s32);
s32 osPfsDeleteFile(s32, u16, s32, s32, s32);
s32 osPfsFileState(s32, s32, s32);
s32 osPfsFindFile(s32, u16, s32, s32, s32, s32);
s32 osPfsFreeBlocks(s32, s32);
s32 osPfsInitPak(s32 *, s32, s32);
s32 osPfsNumFiles(s32, s32, s32);
s32 osPfsReadWriteFile(s32, s32, u8, s32, s32, s32);
s32 osPfsRepairId(s32);
s32 osRecvMesg(s32 *, s32, s32);
extern u8 D_800CEEB0;
extern s32 D_800E0768;
extern u16 D_800E0778;
extern u8 D_800E077A[];
extern s8 D_800E077B;
extern u8 D_800E077C[];
extern u8 gSaveSlotTable[];
extern u16 D_800E0930;
extern s16 gSaveSlot;
extern u16 D_800E097E;
extern u8 D_800E098E[];
extern s32 D_800E0996;
extern s32 D_800E099E;
extern s32 D_800E09A6;
extern u16 D_800E09AE;
extern s32 D_800E09B8;
extern u8 D_800E09BB;
extern s32 D_800E09BC;
extern u16 D_800E09BE;
extern s32 D_800E09C0;
extern u8 D_800E09C3;
extern s32 D_800E09C4;
extern s32 D_800E09C8;
extern s32 D_800E09CC;
extern s32 D_800E09D0;
extern u16 gSaveCmdPending;
extern s32 gSaveCmdResult;
extern u16 gSaveSlotValid;
extern u16 D_8010A3A0[];
extern s32 D_8010D298;
extern u16 D_8010D430;
extern s32 D_8010D432;
extern s16 D_8010D434;
extern s16 D_8010D436;
typedef struct { u16 b; u8 x; u8 y; u8 e; u8 p; } PadT;
typedef struct { u16 a; u16 b; s16 x; s16 y; } OutT;
inline static s16 *inline_fn(long arg0)
{
  return (&D_8010D434) + arg0;
}

inline static int inline_fn2(u16 arg0, int arg1)
{
  return arg0 & arg1;
}

void func_80011950(void)
{
  u16 *var_s7;
  register unsigned var_s1;
  s32 __repair_phase_var_s1;
  long var_s4;
  register s32 var_s5;
  u16 *temp_a0_3;
  u16 *temp_a0_4;
  u16 *temp_s0;
  register u16 *temp_v1;
  u16 *var_s2;
  u16 *var_s6;
  u16 temp_a0;
  u16 temp_a0_2;
  u16 temp_v0;
  u16 temp_v0_2;
  u16 temp_v0_3;
  s32 temp_v1_2;
  if (D_800E09AE)
  {
    osRecvMesg(&D_8010D298, 0, 1);
    osContGetReadData(&D_800E0778);
    var_s5 = 0;
    var_s7 = D_8010A3A0;
    var_s6 = &D_8010D430;
    var_s4 = 0;
    var_s2 = &D_800E0778;
    __repair_phase_var_s1 = 0;
    var_s1 = 0;
    do
    {
      if (((*(D_800E077C + __repair_phase_var_s1)) != 4) || (D_800CEEB0 == 2))
      {
        ((OutT *) (((s8 *) (&D_8010D430)) + var_s4))->x = (s16) ((s8) (((PadT *) (((u8 *) (&D_800E0778)) + __repair_phase_var_s1))->x));
        ((OutT *) (((s8 *) (&D_8010D430)) + var_s4))->y = (s16) ((s8) (((PadT *) (((u8 *) (&D_800E0778)) + __repair_phase_var_s1))->y));
        if ((*((u16 *) (((s8 *) (&D_800E0930)) + var_s1))) != 0)
        {
          if ((*((s16 *) (((s8 *) (&D_8010D434)) + var_s4))) < (-0x1E))
          {
            *var_s2 |= 0x200;
          }
          if ((*((s16 *) (((s8 *) (&D_8010D434)) + var_s4))) >= 0x1F)
          {
            *var_s2 |= 0x100;
          }
          if ((*((s16 *) (((s8 *) (&D_8010D436)) + var_s4))) < (-0x1F))
          {
            *var_s2 |= 0x400;
          }
          if ((*((s16 *) (((s8 *) (&D_8010D436)) + var_s4))) >= 0x20)
          {
            *var_s2 |= 0x800;
          }
        }
        temp_a0 = *var_s2;
        if (inline_fn2(temp_a0, 0x300) == 0x300)
        {
          *((u16 *) (((u8 *) (&D_800E0778)) + __repair_phase_var_s1)) = temp_a0 ^ 0x300;
        }
        temp_a0_2 = *((u16 *) (((u8 *) (&D_800E0778)) + __repair_phase_var_s1));
        if (inline_fn2(temp_a0_2, 0xC00) == 0xC00)
        {
          *((u16 *) (((u8 *) (&D_800E0778)) + __repair_phase_var_s1)) = temp_a0_2 ^ 0xC00;
        }
        ((OutT *) (((s8 *) (&D_8010D430)) + var_s4))->b = ((*var_s6) ^ (*((u16 *) (((u8 *) (&D_800E0778)) + __repair_phase_var_s1)))) & (*((u16 *) (((u8 *) (&D_800E0778)) + __repair_phase_var_s1)));
        *var_s6 = *((u16 *) (((u8 *) (&D_800E0778)) + __repair_phase_var_s1));
        if ((*((u16 *) (((s8 *) (&gSaveSlotValid)) + var_s1))) != 0)
        {
          temp_s0 = (void *) var_s1; temp_s0 = (void *) (((char *) temp_s0) + ((s32) (&D_800E09A6)));
          temp_v0_2 = *temp_s0;
          if (temp_v0_2 != 0)
          {
            *temp_s0 = temp_v0_2 - 1;
          }
          temp_a0_3 = (u16 *) (((s8 *) (&D_800E097E)) + var_s1);
          if ((*temp_a0_3) == 0)
          {
            if ((*((u16 *) ((u16 *) (var_s1 + (u32) var_s7)))) & 2)
            {
              func_80010690(inline_fn2(var_s5, 0xFFFF));
            }
          }
          else
          {
            temp_v1 = (void *) var_s1; temp_v1 = (void *) (((char *) temp_v1) + ((s32) (&D_800E099E))); temp_v0_3 = (*temp_v1) + 1;
            *temp_v1 = temp_v0_3;
            if (((u32) inline_fn2(temp_v0_3, 0xFFFF)) >= 0x258U)
            {
              func_800107BC(var_s5 & 0xFFFF);
              *temp_s0 = 0x3C;
            }
            else
            {
              *temp_a0_3 -= 1;
              temp_a0_4 = var_s1 + D_800E098E;
              temp_v1_2 = (*temp_a0_4) - (*((u16 *) (((s8 *) (&D_800E0996)) + var_s1)));
              *temp_a0_4 = temp_v1_2;
              if ((s16) temp_v1_2 < 0)
              {
                *temp_a0_4 = temp_v1_2 + 0x100;
                if (!inline_fn2(*((u16 *) ((u16 *) (var_s1 + (u32) var_s7))), 1))
                {
                  func_80010590(inline_fn2(var_s5, 0xFFFF));
                }
              }
              else
              {
                if ((*((u16 *) ((u16 *) (var_s1 + (u32) var_s7)))) & 1)
                {
                  stop_controller_rumble(inline_fn2(var_s5, 0xFFFF));
                }
              }
            }
          }
        }
      }
      var_s6 += 4;
      var_s4 += 8;
      var_s2 += 3;
      __repair_phase_var_s1 += 6;
      var_s5++;
      var_s1 += 2;
    }
    while (var_s5 < 4);
    switch (gSaveCmdPending)
    {
      case 1:
        osEepromLongRead(&D_8010D298, D_800E09BB, D_800E09BC, D_800E09C0);
        break;

      case 2:
        osEepromLongWrite(&D_8010D298, D_800E09BB, D_800E09BC, D_800E09C0);
        break;

      case 3:
        gSaveCmdResult = osPfsNumFiles(D_800E09B8, D_800E09BC, D_800E09C0);
        break;

      case 4:
        gSaveCmdResult = osPfsFreeBlocks(D_800E09B8, D_800E09BC);
        break;

      case 5:
        gSaveCmdResult = osPfsFileState(D_800E09B8, D_800E09BC, D_800E09C0);
        break;

      case 6:
        gSaveCmdResult = osPfsDeleteFile(D_800E09B8, D_800E09BE, D_800E09C0, D_800E09C4, D_800E09C8);
        break;

      case 7:
        gSaveCmdResult = osPfsInitPak(&D_8010D298, D_800E09B8, D_800E09BC);
        break;

      case 8:
        gSaveCmdResult = osPfsRepairId(D_800E09B8);
        break;

      case 9:
        gSaveCmdResult = osPfsReadWriteFile(D_800E09B8, D_800E09BC, D_800E09C3, D_800E09C4, D_800E09C8, D_800E09CC);
        break;

      case 10:
        gSaveCmdResult = osPfsAllocateFile(D_800E09B8, D_800E09BE, D_800E09C0, D_800E09C4, D_800E09C8, D_800E09CC, D_800E09D0);
        break;

      case 11:
        gSaveCmdResult = osPfsFindFile(D_800E09B8, D_800E09BE, D_800E09C0, D_800E09C4, D_800E09C8, D_800E09CC);
        break;

      case 12:
        gSaveCmdResult = osMotorInit(&D_8010D298, D_800E09B8, D_800E09BC);
        break;

      case 13:
        gSaveCmdResult = osContStartQuery(&D_8010D298);
        osRecvMesg(&D_8010D298, 0, 1);
        osContGetQuery(&D_800E0768);
        break;

      case 14:
        gSaveCmdResult = osGbpakInit(&D_8010D298, (gSaveSlot * 0x68) + gSaveSlotTable, gSaveSlot);
        break;

    }

    gSaveCmdPending = 0;
    osContStartReadData(&D_8010D298);
  }
}

