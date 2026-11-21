s32 func_800160FC(s32, void *, s32);
s32 spawnTrackMarker(s32);
s32 freeMenuItemRecord(s32);
s32 func_80022A30(u8, s32, s32, s32, s32);
s32 func_80022AD8(u8);
s32 getSaveSlotIndex(s32);
void *func_80023BD4();
s32 formatTextEntry(void *, s32 *);
void *findEntryById(s32 *, s32);
s32 func_800263B8(s32 *, s32);
s32 func_8002A644(s32 *, s32 *, s32, s32, s32, s32, s32, s32, s32, s32 *, s32 *);
s32 func_8002A7CC(s32 *, s32 *, s32, s32);
s32 selectItemAndUpdateAmount(s32 *, s32);
s32 func_8002AC04(s32 *, s32);
s16 timerGetTotalSeconds(void *);
void *lookupDataEntry(s32);
void *memset(void *, s32, u32);
s32 sprintf(char *, const char *, ...);
extern s8 D_800B60E0;
extern s8 D_800B60E1;
extern u8 sMenuListKind;
extern s32 D_800BDBF8;
extern u8 D_800BDBFC;
extern s32 D_800D2AAC;
extern const char D_800D2AB0[];
extern s32 D_800E0EF0;
extern s32 D_800E0F18;
extern s32 D_800E0FC0;
extern s32 D_800E0FC4;
extern s32 D_800E1008;
extern s32 D_800E100C;
extern s32 D_800E101C;
extern s16 D_800E1068;
extern s16 D_800E107E;
extern s16 D_800E1080;
typedef struct 
{
  u8 flag;
  u8 pad[0x17];
} SaveSlotRec;
extern SaveSlotRec D_801001A1[];
extern s32 D_801001A1_raw;
extern s32 D_801001A4;
extern s32 gSaveKeyRelaxed;
extern u8 D_801002AC;
extern s32 gSaveTotalSlots;
typedef struct 
{
  u32 word;
} __attribute__((packed)) UnalignedWord;
extern UnalignedWord D_801002E6;
extern void *gSaveMenuState;
extern void *gBonusObjects[];
extern s32 sProbeTimers;
extern s32 func_80022F10;
extern s32 func_800231F4;
void func_8002323C(void)
{
  s16 *temp_a0_2;
  s16 *temp_s0_4;
  s32 temp_a0_3;
  s32 temp_a0_5;
  s32 temp_a0_7;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_a2;
  s32 temp_s0_3;
  s32 temp_s0_5;
  s32 temp_s0_6;
  s32 temp_s0_7;
  unsigned short temp_s1;
  s32 temp_s3_2;
  s32 temp_s5;
  s32 temp_s5_2;
  s32 temp_v0_10;
  s32 temp_v0_2;
  s32 keyMode;
  s32 temp_v0_3;
  s32 temp_v0_6;
  s32 temp_v0_9;
  s32 var_s0_3;
  s32 var_s0_4;
  s32 var_s2;
  s32 var_s4;
  s32 haveEntries;
  s32 temp_v0;
  s32 var_s0_2;
  void *temp_a0;
  void *temp_v0_4;
  void *temp_a0_4;
  void *temp_a0_6;
  void *temp_s0;
  void *temp_s0_2;
  void *temp_s2;
  void *temp_s3;
  void *temp_s4;
  void *var_s0;
  void *buf3;
  s32 slotB;
  temp_s2 = findEntryById(&D_800BDBF8, 0x53);
  temp_s3 = findEntryById(&D_800BDBF8, 0xB);
  var_s0 = findEntryById(&D_800BDBF8, 0xE);
  temp_s4 = findEntryById(&D_800BDBF8, 0x4021);
  if (var_s0 == NULL)
  {
    var_s0 = findEntryById(&D_800BDBF8, 0);
  }
  haveEntries = (temp_s3 != NULL) & (temp_s2 != NULL);
  D_800B60E0 = 0;
  D_800B60E1 = 0;
  if (haveEntries && ((var_s0 != NULL) & (temp_s4 != NULL)))
  {
    if (D_801002AC == 1)
    {
      temp_v0 = func_800263B8(&D_800BDBF8, 0xB);
      *((s16 *) (((char *) var_s0) + 0)) = 0;
      *((u8 *) (((char *) temp_s2) + 0x26)) = (u8) (*((u8 *) (((char *) var_s0) + 0x26)));
      var_s0_2 = temp_v0;
      *((u8 *) (((char *) temp_s3) + 0x27)) = (u8) (*((u8 *) (((char *) var_s0) + 0x27)));
    }
    else
    {
      *((s16 *) (((char *) var_s0) + 0)) = 0xE;
      var_s0_2 = func_800263B8(&D_800BDBF8, 0xE);
      *((u8 *) (((char *) temp_s2) + 0x26)) = func_800263B8(&D_800BDBF8, 0xE);
      *((u8 *) (((char *) temp_s3) + 0x27)) = func_800263B8(&D_800BDBF8, 0xE);
    }
    D_800BDBFC = var_s0_2;
    temp_a2 = *(*((s32 **) (((char *) gSaveMenuState) + 0x10)));
    D_801002E6 = *((UnalignedWord *) (((char *) (((u8 *) temp_a2) + (((u16) var_s0_2) * 0x28))) + 0x24));
    formatTextEntry(temp_s4, &D_800D2AAC);
    {
      memset(&D_800E107E, 0, 4);
      memset(&D_800E1068, 0, 0x16);
      if (gSaveTotalSlots > 0)
      {
        var_s4 = 0;
        do
        {
          var_s0_3 = (u16) var_s4;
          temp_s1 = getSaveSlotIndex(var_s0_3);
          temp_s0 = gBonusObjects[var_s0_3];
          if (temp_s0 != NULL)
          {
            temp_s0_2 = *((void **) (((char *) temp_s0) + 0x6C));
            if (temp_s0_2 != NULL)
            {
              temp_a0 = *((void **) (((char *) temp_s0_2) + 0xB4));
              (&D_800E1068)[temp_s1 & 0xFFFF] = (*((u16 *) (((char *) temp_a0) + 0xC))) - (*((u16 *) (((char *) temp_a0) + 0xE)));
            }
          }
          temp_v0_2 = temp_s1 & 0xFFFF;
          temp_a0_2 = &(&D_800E107E)[D_801001A1[temp_v0_2].flag];
          *temp_a0_2 = ((u16) (*temp_a0_2)) + ((u16) (&D_800E1068)[temp_v0_2]);
          var_s4 += 1;
        }
        while ((var_s4 & 0xFFFF) < gSaveTotalSlots);
      }
    }
    var_s4 = 0;
    {
      volatile u8 *mode = (u8 *) (&gSaveKeyRelaxed);
      for (; ((u16) var_s4) < 2; var_s4++)
      {
        if (mode[0] == 0)
        {
          break;
        }
        if (mode[-1] == 6)
        {
          s16 bonus = timerGetTotalSeconds(((u8 *) (&sProbeTimers)) + (((u16) var_s4) * 8));
          (&D_800E107E)[(u16) var_s4] += bonus / 10;
        }
      }

    }
    func_8002A644(&D_800E0EF0, &D_800E0F18, 0xA8, 7, 0x4E, 0x64, 0x6E, 0xB, 0, &func_80022F10, &func_800231F4);
    func_80022A30(sMenuListKind, 0x4C, 0x69, 0x98, 0x5A);
    if (D_801002AC != 0)
    {
      s32 *row = &D_800E1008;
      *row = 0;
      temp_v0_3 = spawnTrackMarker(sMenuListKind);
      D_800E100C = temp_v0_3;
      D_800E101C = 0;
      if (temp_v0_3 != 0)
      {
        func_800160FC(D_800E100C, func_80023BD4(), 0x41);
        func_8002A7CC(&D_800E0EF0, row, 0xFF, 1);
      }
    }
    var_s4 = 0;
    keyMode = *((u8 *) (((char *) (&gSaveKeyRelaxed)) + 0));
    if (keyMode != 0)
    {
      var_s2 = 1;
      D_800E0FC0 = spawnTrackMarker(sMenuListKind);
      D_800E0FC4 = spawnTrackMarker(sMenuListKind);
      temp_v0_4 = lookupDataEntry(0x4001);
      sprintf(temp_v0_4, D_800D2AB0, D_800E107E);
      func_800160FC(D_800E0FC0, lookupDataEntry(0x6E), 0x40);
      func_800160FC(D_800E0FC4, temp_v0_4, 0x240);
      func_8002A7CC(&D_800E0EF0, &D_800E0FC0, 0, 1);
      if (gSaveTotalSlots > 0)
      {
        do
        {
          slotB = getSaveSlotIndex(var_s4 & 0xFFFF) & 0xFFFF;
          temp_s5 = slotB * 0x18;
          if (D_801001A1[slotB].flag == 0)
          {
            temp_v0_10 = spawnTrackMarker(sMenuListKind);
            {
              u8 channel = sMenuListKind;
              temp_a1 = var_s2 & 0xFFFF;
              temp_s0_5 = temp_a1 * 0xC;
              *((s32 *) (((char *) (&D_800E0FC0)) + temp_s0_5)) = temp_v0_10;
              temp_v0_6 = spawnTrackMarker(channel);
            }
            temp_a0_3 = *((s32 *) (((char *) (&D_800E0FC0)) + temp_s0_5));
            *((s32 *) (((char *) (&D_800E0FC4)) + temp_s0_5)) = temp_v0_6;
            if (temp_a0_3 == 0)
            {
              goto cleanup3;
            }
            if (temp_v0_6 != 0)
            {
              goto success3;
            }
            cleanup3:
            freeMenuItemRecord(temp_a0_3);

            freeMenuItemRecord(*((s32 *) (((char *) (&D_800E0FC4)) + temp_s0_5)));
            goto next3;
            success3:
            temp_v0_4 = lookupDataEntry((var_s2 + 0x4003) & 0xFFFF);

            temp_a0_4 = temp_v0_4;
            sprintf(temp_a0_4, D_800D2AB0, (&D_800E1068)[slotB]);
            var_s2 += 1;
            func_800160FC(*((s32 *) (((char *) (&D_800E0FC0)) + temp_s0_5)), temp_s5 + ((u8 *) (&D_801001A4)), 0x40);
            func_800160FC(*((s32 *) (((char *) (&D_800E0FC4)) + temp_s0_5)), temp_v0_4, 0x240);
            func_8002A7CC(&D_800E0EF0, (s32 *) (((u8 *) (&D_800E0FC0)) + temp_s0_5), 0, 1);
            next3:
            ;

            ;
          }
          var_s4 += 1;
        }
        while ((var_s4 & 0xFFFF) < gSaveTotalSlots);
      }
      var_s4 = 0;
      temp_v0_10 = spawnTrackMarker(sMenuListKind);
      {
        u8 channel = sMenuListKind;
        temp_s0_6 = (var_s2 & 0xFFFF) * 0xC;
        *((s32 *) (((char *) (&D_800E0FC0)) + temp_s0_6)) = temp_v0_10;
        var_s2++;
        temp_v0_10 = spawnTrackMarker(channel);
        *((s32 *) (((char *) (&D_800E0FC4)) + temp_s0_6)) = temp_v0_10;
      }
      temp_v0_4 = lookupDataEntry(0x4002);
      sprintf(temp_v0_4, D_800D2AB0, D_800E1080);
      func_800160FC(*((s32 *) (((char *) (&D_800E0FC0)) + temp_s0_6)), lookupDataEntry(0x6F), 0x40);
      func_800160FC(*((s32 *) (((char *) (&D_800E0FC4)) + temp_s0_6)), temp_v0_4, 0x240);
      func_8002A7CC(&D_800E0EF0, (s32 *) (((u8 *) (&D_800E0FC0)) + temp_s0_6), 1, 1);
      if (gSaveTotalSlots > 0)
      {
        do
        {
          temp_s1 = getSaveSlotIndex(var_s4 & 0xFFFF) & 0xFFFF;
          temp_s5_2 = temp_s1 * 0x18;
          if (D_801001A1[temp_s1].flag == 1)
          {
            temp_v0_10 = spawnTrackMarker(sMenuListKind);
            {
              u8 channel = sMenuListKind;
              temp_a1_2 = var_s2 & 0xFFFF;
              temp_s0_7 = temp_a1_2 * 0xC;
              *((s32 *) (((char *) (&D_800E0FC0)) + temp_s0_7)) = temp_v0_10;
              temp_v0_9 = spawnTrackMarker(channel);
            }
            temp_a0_5 = *((s32 *) (((char *) (&D_800E0FC0)) + temp_s0_7));
            *((s32 *) (((char *) (&D_800E0FC4)) + temp_s0_7)) = temp_v0_9;
            if (temp_a0_5 == 0)
            {
              goto cleanup5;
            }
            if (temp_v0_9 != 0)
            {
              goto success5;
            }
            cleanup5:
            freeMenuItemRecord(temp_a0_5);

            freeMenuItemRecord(*((s32 *) (((char *) (&D_800E0FC4)) + temp_s0_7)));
            goto next5;
            success5:
            temp_v0_4 = lookupDataEntry((var_s2 + 0x400B) & 0xFFFF);

            temp_a0_6 = temp_v0_4;
            sprintf(temp_a0_6, D_800D2AB0, (&D_800E1068)[temp_s1]);
            var_s2 += 1;
            func_800160FC(*((s32 *) (((char *) (&D_800E0FC0)) + temp_s0_7)), temp_s5_2 + ((u8 *) (&D_801001A4)), 0x40);
            func_800160FC(*((s32 *) (((char *) (&D_800E0FC4)) + temp_s0_7)), temp_v0_4, 0x240);
            func_8002A7CC(&D_800E0EF0, (s32 *) (((u8 *) (&D_800E0FC0)) + temp_s0_7), 1, 1);
            next5:
            ;

            ;
          }
          var_s4 += 1;
        }
        while ((var_s4 & 0xFFFF) < gSaveTotalSlots);
      }
    }
    else
      if (keyMode < gSaveTotalSlots)
    {
      do
      {
        var_s0_4 = (u16) var_s4;
        temp_s1 = getSaveSlotIndex(var_s0_4);
        temp_v0_10 = spawnTrackMarker(sMenuListKind);
        {
          u8 channel = sMenuListKind;
          temp_s3_2 = var_s0_4 * 0xC;
          *((s32 *) (((char *) (&D_800E0FC0)) + temp_s3_2)) = temp_v0_10;
          temp_v0_10 = spawnTrackMarker(channel);
        }
        temp_a0_7 = *((s32 *) (((char *) (&D_800E0FC0)) + temp_s3_2));
        *((s32 *) (((char *) (&D_800E0FC4)) + temp_s3_2)) = temp_v0_10;
        if (temp_a0_7 == 0)
        {
          goto cleanup7;
        }
        if (temp_v0_10 != 0)
        {
          goto success7;
        }
        cleanup7:
        freeMenuItemRecord(temp_a0_7);

        freeMenuItemRecord(*((s32 *) (((char *) (&D_800E0FC4)) + temp_s3_2)));
        goto next7;
        success7:
        buf3 = lookupDataEntry((var_s4 + 0x4003) & 0xFFFF);

        temp_s1 = temp_s1 & 0xFFFF;
        sprintf(buf3, D_800D2AB0, (&D_800E1068)[temp_s1]);
        func_800160FC(*((s32 *) (((char *) (&D_800E0FC0)) + temp_s3_2)), (temp_s1 * 0x18) + ((u8 *) (&D_801001A4)), 0x40);
        func_800160FC(*((s32 *) (((char *) (&D_800E0FC4)) + temp_s3_2)), buf3, 0x240);
        func_8002A7CC(&D_800E0EF0, (s32 *) (((u8 *) (&D_800E0FC0)) + temp_s3_2), (var_s4 + 1) & 0xFF, 1);
        next7:
        ;

        ;
        var_s4 += 1;
      }
      while ((var_s4 & 0xFFFF) < gSaveTotalSlots);
    }
    func_80022AD8(sMenuListKind);
    selectItemAndUpdateAmount(&D_800E0EF0, 0);
    func_8002AC04(&D_800E0EF0, 1);
  }
}

