s32 lookupMenuItemIndex(u32);
s32 lookupItemSlotIndex(s32);
s32 initSlotRecord(void *, s32);
s16 timerGetTotalSeconds(void *);
s32 isRecordBetter(void *, void *);
unsigned short addPlayTime(void *, void *);
s32 copyItemRecordHeader(void *, s32 *);
s32 setGroupUnlockFlag(s32, s32);
s32 getTextRefType();
s32 getEntryStatus();
u16 getEntryLevelLimitTopNibble();
extern s16 D_80102CBC;
extern s16 D_80102CBE;
extern s16 D_80102CC0;
extern u8 gCurrentItemId;
extern s32 gSelectedItemId;
extern s32 D_80102EFC;
extern s8 sMenuRowEnabled;
extern s8 gMenuFlagItem20;
extern s8 gMenuFlagItem22;
extern s8 gMenuFlagItem27;
extern s8 D_80112F7F;
extern s8 D_80112F80;
extern s8 D_80112F81;
extern s8 sOptionReady7;
extern s8 sOptionReady8;
extern s8 D_80112F84;
extern u8 D_80117410;
extern u8 D_80117428;
extern u8 D_80117578;
extern u8 D_801176C8;
inline static unsigned short inline_fn(u16 arg0)
{
  return arg0 & 0xFFFF;
}

inline static u8 *inline_fn2(u8 *arg0)
{
  return arg0;
}

inline static u8 *inline_fn23(s32 arg0, u8 *arg1)
{
  return arg0 + arg1;
}

inline static int inline_fn234(s32 arg0)
{
  return inline_fn(arg0) * 0x18;
}

inline static u8 *inline_fn2345(int arg0, u16 arg1, u8 *arg2)
{
  return inline_fn23(inline_fn23(arg2 + 0x18, arg1 * 8), arg0);
}

/* Advances item slot progress, records best values, and sets unlock flags/messages for newly earned items. */ void updateItemRecordsAndUnlocks(void)
 {
  s16 currentSeconds;
  s16 var_v0;
  s32 slotOffset;
  s32 __repair_phase_temp_s0;
  u16 temp_s2;
  s32 off2;
  s32 slotIndex;
  s32 var_a0;
  s32 __repair_phase_var_s1;
  s32 nextSlot;
  s32 temp_v0;
  void *temp_s0_2;
  {
    D_80102CBC = 0;
    D_80102CBE = 0;
    D_80102CC0 = 0;
    if (getEntryStatus() == 5)  {
      u8 *itemIdPtr = &gCurrentItemId;
      nextSlot = lookupItemSlotIndex(*itemIdPtr) + 1;
      if (((u32) (nextSlot & 0xFFFF)) >= 0xEU)  {
        nextSlot = 0xD;
      }
      *itemIdPtr = lookupMenuItemIndex(nextSlot & 0xFFFF);
      slotIndex = lookupItemSlotIndex(getTextRefType());
      nextSlot = slotIndex;
      temp_v0 = getEntryLevelLimitTopNibble();
      slotOffset = (slotIndex & 0xFFFF) * 0x18;
      if (((timerGetTotalSeconds(inline_fn23((temp_v0 * 8) + (&D_80117428), slotOffset)) << 0x10) == 0) || ((itemIdPtr += 0x1C, isRecordBetter(inline_fn23(inline_fn23(((u16) getEntryLevelLimitTopNibble()) * 8, &D_80117428), slotOffset), itemIdPtr) & 0xFF)))  {
        copyItemRecordHeader(inline_fn23(inline_fn23(((u16) getEntryLevelLimitTopNibble()) * 8, inline_fn2(&D_80117428)), slotOffset), &D_80102EFC);
      }
      do  {
      __repair_phase_temp_s0 = 0;
      initSlotRecord(inline_fn23(((u16) getEntryLevelLimitTopNibble()) * 8, &D_80117410), 0x1E);
      itemIdPtr = &D_80117410;
      do  {
        temp_s0_2 = inline_fn23(itemIdPtr, (getEntryLevelLimitTopNibble() & 0xFFFF) * 8);
        addPlayTime(temp_s0_2, inline_fn2345((__repair_phase_temp_s0 & 0xFFFF) * 0x18, (u16) getEntryLevelLimitTopNibble(), itemIdPtr));
        __repair_phase_temp_s0 += 1;
      }
      while (((u32) (__repair_phase_temp_s0 & 0xFFFF)) < 0xEU);
      slotOffset = nextSlot & 0xFFFF;
      if (((u32) inline_fn(getEntryLevelLimitTopNibble())) > ((u8) (*((&D_801176C8) + slotOffset))))  {
        *((&D_801176C8) + slotOffset) = getEntryLevelLimitTopNibble();
      }
      {
        s32 *selectedItemPtr = &gSelectedItemId;
        do  {
        }
        while (0);
        if (slotOffset >= ((u32) ((u16) lookupItemSlotIndex(*selectedItemPtr))))  {
          nextSlot = nextSlot + 1;
          if (((u32) ((u16) nextSlot)) >= 0xEU)  {
            nextSlot = 0xD;
          }
          var_a0 = nextSlot & 0xFFFF;
        }
        else  {
          var_a0 = (u16) lookupItemSlotIndex(*selectedItemPtr);
        }
        *selectedItemPtr = (u16) lookupMenuItemIndex(var_a0);
      }
      if (getTextRefType() == 0x21)  {
        if (!((u16) getEntryLevelLimitTopNibble()))  {
          setGroupUnlockFlag(0xA, 1);
          D_80102CBC = 0x2C4;
        }
        if (((u16) getEntryLevelLimitTopNibble()) == 1)  {
          setGroupUnlockFlag(4, 1);
          D_80102CBE = 0x2B3;
        }
        if ((getEntryLevelLimitTopNibble() & 0xFFFF) == 2)  {
          D_80112F81 = 1;
          D_80102CC0 = 0x2BC;
        }
      }
      currentSeconds = timerGetTotalSeconds(&D_80102EFC);
      temp_s2 = getEntryLevelLimitTopNibble();
      off2 = (slotIndex & 0xFFFF) * 0x18;
      if (currentSeconds <= timerGetTotalSeconds(inline_fn23(inline_fn23(temp_s2 * 8, &D_80117578), off2)))  {
        var_a0 = getTextRefType();
        switch (var_a0)  {
          case 2: if ((getEntryLevelLimitTopNibble() & 0xFFFF) == 1)  {
            setGroupUnlockFlag(5, 1);
            var_v0 = 0x2AF;
            goto block_59;
          }
          break;
          case 20: if (!(getEntryLevelLimitTopNibble() & 0xFFFF))  {
            D_80112F7F = 1;
            D_80102CBC = 0x2BA;
          }
          if ((getEntryLevelLimitTopNibble() & 0xFFFF) == 1)  {
            setGroupUnlockFlag(8, 1);
            D_80102CBE = 0x2B0;
            return;
          }
          break;
          case 16: if (((u16) getEntryLevelLimitTopNibble()) == 2)  {
            sOptionReady7 = 1;
            var_v0 = 0x2B7;
            goto block_59;
          }
          break;
          case 34: if (!((u16) getEntryLevelLimitTopNibble()))  {
            gMenuFlagItem27 = 1;
            var_v0 = 0x2C0;
            goto block_59;
          }
          break;
          case 25: if ((getEntryLevelLimitTopNibble() & 0xFFFF) == 2)  {
            setGroupUnlockFlag(1, 1);
            D_80102CBC = 0x2B4;
          }
          if ((getEntryLevelLimitTopNibble() & 0xFFFF) == 1)  {
            gMenuFlagItem20 = 1;
            var_v0 = 0x2BE;
            goto block_59;
          }
          break;
          case 38: if ((getEntryLevelLimitTopNibble() & 0xFFFF) == 2)  {
            sMenuRowEnabled = 1;
            var_v0 = 0x2BD;
            goto block_59;
          }
          break;
          case 1: if (!((u16) getEntryLevelLimitTopNibble()))  {
            setGroupUnlockFlag(9, 1);
            var_v0 = 0x2AE;
            goto block_59;
          }
          break;
          case 11: if (!(getEntryLevelLimitTopNibble() & 0xFFFF))  {
            gMenuFlagItem22 = 1;
            D_80102CBC = 0x2BF;
          }
          if ((getEntryLevelLimitTopNibble() & 0xFFFF) == 2)  {
            setGroupUnlockFlag(2, 1);
            D_80102CC0 = 0x2B2;
            return;
          }
          break;
          case 41: if (!((u16) getEntryLevelLimitTopNibble()))  {
            setGroupUnlockFlag(6, 1);
            D_80102CBC = 0x2B6;
          }
          if ((getEntryLevelLimitTopNibble() & 0xFFFF) == 1)  {
            setGroupUnlockFlag(3, 1);
            D_80102CBE = 0x2B1;
            return;
          }
          break;
          case 40: if (!((u16) getEntryLevelLimitTopNibble()))  {
            sOptionReady8 = 1;
            var_v0 = 0x2B8;
            goto block_59;
          }
          break;
          case 28: if (((u16) getEntryLevelLimitTopNibble()) == 1)  {
            D_80112F80 = 1;
            var_v0 = 0x2BB;
            goto block_59;
          }
          break;
          case 18: if (((u16) getEntryLevelLimitTopNibble()) == 1)  {
            D_80112F84 = 1;
            D_80102CBE = 0x2B9;
            return;
          }
          break;
          case 29: if (((u16) getEntryLevelLimitTopNibble()) == 2)  {
            setGroupUnlockFlag(7, 1);
            var_v0 = 0x2B5;
            goto block_59;
          }
          break;
        }
      }
      } while (0);
    }
    return;
    block_59: D_80102CBC = var_v0;
    }
}
