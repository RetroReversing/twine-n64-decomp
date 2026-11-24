#ifndef M2C_DEFINES
#define M2C_DEFINES
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
M2C_UNK setVolumeLevel(u8);
M2C_UNK setSoundVolumeTenths(u8);
M2C_UNK setExpansionMode(u8);
M2C_UNK initSlotRecord(void *, M2C_UNK);
M2C_UNK setGroupUnlockFlag(s32, s32);
M2C_UNK initBitReader(M2C_UNK *, u16 *, M2C_UNK, M2C_UNK);
s32 advanceStreamAndReadBits(void *, s32, s32);
M2C_UNK updateAllCameraProjections(f32);
M2C_UNK func_80081BC4(u32, u8);
extern u16 gSaveDataBuffer;
extern M2C_UNK gSaveBitWriter;
extern u8 D_80100198;
extern M2C_UNK D_8010019C;
extern u8 D_801001A0;
extern u8 D_801001A1;
extern u8 D_801001A2;
extern u8 gPlayerNames;
extern u8 D_801002A0;
extern u8 D_801002A1;
extern u8 D_801002A2;
extern u8 D_801002A4;
extern s32 gBonusGoalTarget;
extern u8 D_801002D4;
extern u8 D_801002D5;
extern s32 D_801002EC;
extern u8 D_801002F0;
extern u8 D_801002F1;
extern u8 D_801002F2;
extern u8 D_801002F3;
extern u8 gCurrentItemId;
extern s32 gSelectedItemId;
extern u8 D_80102EE8;
extern const u16 * volatile gMenuOptionTable;
extern u8 gExpansionModeEnabled;
extern u8 D_8010A4FC;
extern u8 D_8010A4FD;
extern u8 D_8010A4FE;
extern u8 D_8010A4FF;
extern u8 gGroupUnlockFlags;
extern u8 D_80112F7B;
extern u8 D_80112F7F;
extern u8 D_80112F82;
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
extern M2C_UNK D_80117410;
extern u8 D_80117416;
extern M2C_UNK D_80117428;
extern u8 D_8011742E;
extern u8 D_801176C8;
extern s32 gMenuOptionIndex;
extern void func_8011AA9C(void);
/* Unpacks the bit-packed save data buffer (if its header is 0xF) into player slots, settings, menu options and flags, then applies expansion mode, camera and volume. */ void deserializeSaveData(void)
{
  const u16 *var_v0;
  s32 temp_a1;
  s32 temp_s0;
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s0_4;
  s32 temp_s0_5;
  s32 temp_s1;
  s32 temp_s2;
  s32 var_s0;
  s32 var_s1;
  s32 var_s3;
  s32 var_s4;
  u32 temp_a0;
  u8 temp_v0;
  M2C_UNK *bs;
  u8 *tailBase;
  u8 *tail;
  u16 *input = &gSaveDataBuffer;
  if ((*(input++)) == 0xF)
  {
    initBitReader(&gSaveBitWriter, input, 0, 0x1FB);
    var_s4 = 0;
    bs = &gSaveBitWriter;
    tailBase = &gPlayerNames;
    do
    {
      s32 first = advanceStreamAndReadBits(bs, 1, 1);
      temp_s1 = var_s4 & 0xFFFF;
      temp_s0 = temp_s1 * 0xA0;
      *((&gSlotTable) - (-temp_s0)) = first;
      *((&gSlotMarkerActive) + temp_s0) = advanceStreamAndReadBits(bs, 1, 1);
      *((&D_8011508A) + temp_s0) = advanceStreamAndReadBits(bs, 1, 1);
      *((&D_8011508B) + temp_s0) = advanceStreamAndReadBits(bs, 1, 1);
      *((&D_8011508C) + temp_s0) = advanceStreamAndReadBits(bs, 1, 1);
      *((&D_8011508D) + (temp_s1 * 0xA0)) = advanceStreamAndReadBits(bs, 1, 1);
      *((&D_80115090) + (temp_s1 * 0xA0)) = advanceStreamAndReadBits(bs, 1, 1);
      *((&D_80115091) + (temp_s1 * 0xA0)) = advanceStreamAndReadBits(bs, 1, 4);
      *((&D_8011508E) + (temp_s1 * 0xA0)) = advanceStreamAndReadBits(bs, 1, 1);
      *((&gZoneModeEntries) + (temp_s1 * 0xA0)) = advanceStreamAndReadBits(bs, 1, 1);
      {
        s32 value = advanceStreamAndReadBits(bs, 1, 4);
        temp_s0_2 = temp_s1 * 0x18;
        *((&D_80100198) + temp_s0_2) = value;
      }
      *((s32 *) (((u8 *) (&D_8010019C)) + temp_s0_2)) = advanceStreamAndReadBits(bs, 4, 0x10);
      *((&D_801001A0) + temp_s0_2) = advanceStreamAndReadBits(bs, 1, 8);
      *((&D_801001A1) + temp_s0_2) = advanceStreamAndReadBits(bs, 1, 1);
      {
        s32 value = advanceStreamAndReadBits(bs, 1, 4);
        var_s1 = 0;
        tail = (void *) (temp_s0_2 + ((s32) tailBase));
        *((&D_801001A2) + temp_s0_2) = value;
      }
      loop_3:
      tail[var_s1 & 0xFFFF] = advanceStreamAndReadBits(&gSaveBitWriter, 1, 8);

      var_s1 += 1;
      temp_a0 = var_s4 & 0xFFFF;
      if (((u32) (var_s1 & 0xFFFF)) < 9U)
      {
        goto loop_3;
      }
      if (temp_a0 < 4U)
      {
        func_80081BC4(temp_a0, (*((volatile struct 
        {
          u8 filler[0x198];
          u8 value;
        } *) (((u8 *) 0x80100000) + (temp_a0 * 0x18)))).value);
      }
      var_s4 += 1;
    }
    while (((u32) (var_s4 & 0xFFFF)) < 0xBU);
    {
      u8 *mode = &D_801002A0;
      *mode = advanceStreamAndReadBits(&gSaveBitWriter, 1, 4);
      D_801002A1 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
      D_801002A2 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 4);
      D_801002A4 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 8);
      D_801002D4 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 4);
      D_801002D5 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
      gMenuOptionIndex = advanceStreamAndReadBits(&gSaveBitWriter, 4, 0x20);
      initSlotRecord(mode + 0x24, 0x1E);
      *((s32 *) (mode + 0x24)) = advanceStreamAndReadBits(&gSaveBitWriter, 4, 0x20);
      switch (*mode)
      {
        case 5:

        case 6:
          gMenuOptionTable = (const u16 *) (((const u8 *) func_8011AA9C) + 0x1C4);
          break;

        case 2:

        case 3:

        case 4:
          gMenuOptionTable = (const u16 *) (((const u8 *) func_8011AA9C) + 0x198);
          break;

        case 7:
          gMenuOptionTable = (const u16 *) (((const u8 *) func_8011AA9C) + 0x1F8);
          break;

        default:
          gMenuOptionTable = (const u16 *) (((const u8 *) func_8011AA9C) + 0x180);
          break;

      }

    }
    gBonusGoalTarget = (s32) (*(gMenuOptionIndex + gMenuOptionTable));
    gCurrentItemId = advanceStreamAndReadBits(&gSaveBitWriter, 1, 8);
    gSelectedItemId = advanceStreamAndReadBits(&gSaveBitWriter, 4, 0x20);
    D_80102EE8 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 4);
    gExpansionModeEnabled = advanceStreamAndReadBits(&gSaveBitWriter, 1, 2);
    D_8010A4FC = advanceStreamAndReadBits(&gSaveBitWriter, 1, 6);
    D_8010A4FD = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
    D_8010A4FE = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
    D_8010A4FF = advanceStreamAndReadBits(&gSaveBitWriter, 1, 2);
    D_801002EC = advanceStreamAndReadBits(&gSaveBitWriter, 4, 1);
    D_801002F0 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 4);
    D_801002F1 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 4);
    D_801002F2 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 2);
    D_801002F3 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
    var_s3 = 0;
    do
    {
      temp_s0_3 = (var_s3 & 0xFFFF) * 8;
      initSlotRecord(temp_s0_3 + ((u8 *) (&D_80117410)), 0x1E);
      *((s32 *) (((u8 *) (&D_80117410)) + temp_s0_3)) = advanceStreamAndReadBits(&gSaveBitWriter, 4, 0xD);
      {
        s32 value = advanceStreamAndReadBits(&gSaveBitWriter, 1, 6);
        var_s3 += 1;
        *((&D_80117416) + temp_s0_3) = value;
      }
    }
    while (((u32) (var_s3 & 0xFFFF)) < 3U);
    var_s1 = 0;
    do
    {
      var_s3 = 0;
      temp_s2 = ((var_s1 & 0xFFFF) * 3) << 3;
      loop_17:
      temp_s0_4 = (var_s3 & 0xFFFF) * 8;

      initSlotRecord(temp_s0_4 + (temp_s2 + ((u8 *) (&D_80117428))), 0x1E);
      temp_s0_5 = temp_s0_4 + temp_s2;
      *((s32 *) (((u8 *) (&D_80117428)) + temp_s0_5)) = advanceStreamAndReadBits(&gSaveBitWriter, 4, 4);
      {
        s32 value = advanceStreamAndReadBits(&gSaveBitWriter, 1, 6);
        var_s3 += 1;
        *((&D_8011742E) + temp_s0_5) = value;
      }
      if (((u32) (var_s3 & 0xFFFF)) < 3U)
      {
        goto loop_17;
      }
      *((&D_801176C8) + (var_s1 & 0xFFFF)) = advanceStreamAndReadBits(&gSaveBitWriter, 1, 2);
      var_s1 += 1;
    }
    while (((u32) (var_s1 & 0xFFFF)) < 0xEU);
    var_s1 = 0;
    do
    {
      temp_v0 = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
      *((&gGroupUnlockFlags) + (var_s1 & 0xFFFF)) = temp_v0;
      temp_a1 = temp_v0 & 0xFF;
      if (temp_a1 != 0)
      {
        setGroupUnlockFlag(var_s1 & 0xFF, temp_a1);
      }
      var_s1 += 1;
    }
    while (((u32) (var_s1 & 0xFFFF)) < 0xBU);
    var_s1 = 0;
    do
    {
      *((&D_80112F7B) + (var_s1 & 0xFFFF)) = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
      var_s1 += 1;
    }
    while (((u32) (var_s1 & 0xFFFF)) < 4U);
    var_s1 = 0;
    do
    {
      *((&D_80112F7F) + (var_s1 & 0xFFFF)) = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
      var_s1 += 1;
    }
    while (((u32) (var_s1 & 0xFFFF)) < 3U);
    var_s1 = 0;
    do
    {
      if (var_s3)
      {
        *((&D_80112F82) + (var_s1 & 0xFFFF)) = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
        var_s1 += 1;
      }
      else
      {
        *((&D_80112F82) + (var_s1 & 0xFFFF)) = advanceStreamAndReadBits(&gSaveBitWriter, 1, 1);
        var_s1 += 1;
      }
    }
    while (((u32) (var_s1 & 0xFFFF)) < 3U);
    setExpansionMode(gExpansionModeEnabled);
    updateAllCameraProjections(60.0f);
    setSoundVolumeTenths(D_801002F0);
    setVolumeLevel(D_801002F1);
  }
}

