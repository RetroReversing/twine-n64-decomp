s32 bitStreamInit(s32 *, s32 *, s32, s32);
s32 writeBitsAdvance(s32 *, s32, s32, s32);
s32 noopStubSaveData(s32 *);
extern s32 gSaveBitBuffer;
extern s32 gSaveBitWriter;
extern s32 D_80100198;
extern s32 gSaveSlotInfo;
extern s32 D_801001A0;
extern s32 D_801001A1;
extern s32 D_801001A2;
extern s32 gPlayerNames;
extern u8 gSceneType;
extern u8 gSaveKeyRelaxed;
extern u8 D_801002A2;
extern u8 D_801002A4;
extern s32 gMenuTimerSetting;
extern u8 gPauseFlag;
extern u8 D_801002D5;
extern s32 D_801002EC;
extern u8 D_801002F0;
extern u8 D_801002F1;
extern u8 gOptionChoice;
extern u8 gOptionFlag;
extern u8 gCurrentItemId;
extern s32 gSelectedItemId;
extern u8 sDifficultyLevel;
extern u8 gExpansionModeEnabled;
extern u8 gColorFadeLevel;
extern u8 gBorderFlipFlag;
extern u8 gOptionFlagA;
extern u8 D_8010A4FF;
extern s8 gGroupUnlockFlags;
extern s8 D_80112F7B;
extern s8 D_80112F7F;
extern s8 D_80112F82;
extern u8 gSlotTable;
extern u8 gSlotMarkerActive;
extern u8 D_8011508A;
extern u8 D_8011508B;
extern u8 D_8011508C;
extern u8 D_8011508D;
extern u8 D_8011508E;
extern u8 gZoneModeEntries;
extern u8 D_80115090;
extern u8 D_80115091;
extern s8 D_80117410;
extern s8 D_80117416;
extern s8 D_80117428;
extern s8 D_8011742E;
extern s8 D_801176C8;
extern s32 gMenuOptionIndex;
inline static u8 *inline_fn(s8 *arg0)
{
  return (u8 *) arg0;
}

/* Serializes save slots, settings and records into the save bitstream (gSaveBitWriter), then finalizes it. */ void packSaveDataToBitstream(void)
{
  u16 j;
  u16 i;
  s32 temp_a1_2;
  s32 temp_a1_3;
  s32 slotOffsetA0;
  unsigned int slotOffset24;
  s32 temp_s0_3;
  register s32 temp_s0_4;
  s32 temp_s1;
  s32 var_s1_4;
  s32 slotIdxMasked;
  
  unsigned long slotIdx;
  s8 temp_a1;
  u8 temp_a1_4;
  u8 temp_a1_5;
  u8 temp_a1_6;
  u8 temp_a1_7;
  register u8 temp_a1_8;
  bitStreamInit(&gSaveBitWriter, &gSaveBitBuffer, 0, 0x1FB);
  slotIdx = 0;
  do
  {
    slotIdxMasked = slotIdx & 0xFFFF;
    slotOffsetA0 = slotIdxMasked * 0xA0;
    writeBitsAdvance(&gSaveBitWriter, *((&gSlotTable) + slotOffsetA0), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *((&gSlotMarkerActive) + slotOffsetA0), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *((&D_8011508A) + slotOffsetA0), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *((&D_8011508B) + slotOffsetA0), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *((&D_8011508C) + slotOffsetA0), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *((&D_8011508D) + slotOffsetA0), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *((&D_80115090) + slotOffsetA0), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *((&D_80115091) + slotOffsetA0), 1, 4);
    writeBitsAdvance(&gSaveBitWriter, *((&D_8011508E) + slotOffsetA0), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *((&gZoneModeEntries) + slotOffsetA0), 1, 1);
    slotOffset24 = slotIdxMasked * 24;
    writeBitsAdvance(&gSaveBitWriter, *((u8 *) (((s8 *) (&D_80100198)) + slotOffset24)), 1, 4);
    writeBitsAdvance(&gSaveBitWriter, *((s32 *) (((s8 *) (&gSaveSlotInfo)) + slotOffset24)), 4, 0x10);
    writeBitsAdvance(&gSaveBitWriter, *inline_fn(((s8 *) (&D_801001A0)) + slotOffset24), 1, 8);
    writeBitsAdvance(&gSaveBitWriter, *inline_fn(((s8 *) (&D_801001A1)) + slotOffset24), 1, 1);
    writeBitsAdvance(&gSaveBitWriter, *inline_fn(((s8 *) (&D_801001A2)) + slotOffset24), 1, 4);
    {
      u16 slotByte;
      for (slotByte = 0; slotByte < 9; slotByte++)
      {
        temp_a1 = *((inline_fn(&gPlayerNames) + slotOffset24) + slotByte);
        writeBitsAdvance(&gSaveBitWriter, temp_a1, 1, 8);
      }

    }
    slotIdx += 1;
  }
  while (((u32) (slotIdx & 0xFFFF)) < 0xBU);
  {
    writeBitsAdvance(&gSaveBitWriter, gSceneType, 1, 4);
  }
  {
    writeBitsAdvance(&gSaveBitWriter, gSaveKeyRelaxed, 1, 1);
  }
  {
    writeBitsAdvance(&gSaveBitWriter, D_801002A2, 1, 4);
  }
  writeBitsAdvance(&gSaveBitWriter, D_801002A4, 1, 8);
  writeBitsAdvance(&gSaveBitWriter, gPauseFlag, 1, 4);
  writeBitsAdvance(&gSaveBitWriter, D_801002D5, 1, 1);
  writeBitsAdvance(&gSaveBitWriter, gMenuOptionIndex, 4, 0x20);
  writeBitsAdvance(&gSaveBitWriter, gMenuTimerSetting, 4, 0x20);
  writeBitsAdvance(&gSaveBitWriter, gCurrentItemId, 1, 8);
  writeBitsAdvance(&gSaveBitWriter, gSelectedItemId, 4, 0x20);
  writeBitsAdvance(&gSaveBitWriter, sDifficultyLevel, 1, 4);
  writeBitsAdvance(&gSaveBitWriter, gExpansionModeEnabled, 1, 2);
  writeBitsAdvance(&gSaveBitWriter, gColorFadeLevel, 1, 6);
  writeBitsAdvance(&gSaveBitWriter, gBorderFlipFlag, 1, 1);
  writeBitsAdvance(&gSaveBitWriter, gOptionFlagA, 1, 1);
  writeBitsAdvance(&gSaveBitWriter, D_8010A4FF, 1, 2);
  writeBitsAdvance(&gSaveBitWriter, D_801002EC, 4, 1);
  writeBitsAdvance(&gSaveBitWriter, D_801002F0, 1, 4);
  writeBitsAdvance(&gSaveBitWriter, D_801002F1, 1, 4);
  writeBitsAdvance(&gSaveBitWriter, gOptionChoice, 1, 2);
  writeBitsAdvance(&gSaveBitWriter, gOptionFlag, 1, 1);
  {
    
    for (j = 0; j < 3; j++)
    {
      temp_s0_3 = j * 8;
      temp_a1_2 = *((s32 *) ((&D_80117410) + temp_s0_3));
      writeBitsAdvance(&gSaveBitWriter, temp_a1_2, 4, 0xD);
      writeBitsAdvance(&gSaveBitWriter, *((&D_80117416) + temp_s0_3), 1, 6);
    }

  }
  {
    
    for (i = 0; i < 0xE; i++)
    {
      {
        
        for (j = 0; j < 3; j++)
        {
          temp_s0_4 = (j * 8) + (i * 0x18);
          temp_a1_3 = *((s32 *) ((&D_80117428) + temp_s0_4));
          writeBitsAdvance(&gSaveBitWriter, temp_a1_3, 4, 4);
          writeBitsAdvance(&gSaveBitWriter, *((&D_8011742E) + temp_s0_4), 1, 6);
        }

      }
      temp_a1_4 = *((&D_801176C8) + ((u32) i));
      writeBitsAdvance(&gSaveBitWriter, temp_a1_4, 1, 2);
    }

  }
  {
    
    for (i = 0; i < 0xB; i++)
    {
      temp_a1_5 = *((&gGroupUnlockFlags) + i);
      writeBitsAdvance(&gSaveBitWriter, temp_a1_5, 1, 1);
    }

  }
  {
    
    for (i = 0; i < 4; i++)
    {
      var_s1_4 = (u32) i;
      temp_a1_6 = *((&D_80112F7B) + var_s1_4);
      writeBitsAdvance(&gSaveBitWriter, temp_a1_6, 1, 1);
    }

  }
  var_s1_4 = 0;
  {
    
    for (i = 0; i < 3; i++)
    {
      temp_a1_7 = *((&D_80112F7F) + i);
      writeBitsAdvance(&gSaveBitWriter, temp_a1_7, 1, 1);
    }

  }
  i = 0;
  do
  {
    temp_a1_8 = *((&D_80112F82) + (((s32) i) & 0xFFFF));
    writeBitsAdvance(&gSaveBitWriter, temp_a1_8, 1, 1);
    ++i;
  }
  while (((u32) (i & 0xFFFF)) < 3U);
  noopStubSaveData(&gSaveBitWriter);
}


