s32 func_800645A4(u32);
extern u16 sEnemyDefTable[];
extern u8 D_800C46A1[];
extern u8 D_800C471E[];
extern u16 gStatThresholdTable[];
extern u8 D_80112F6C;
/* Fills the per-enemy status arrays in the owner's state block from the enemy definition tables, zeroed when disabled. */ void initEnemyStatusEntries(void *owner)
{
  s32 defOffset;
  s32 entryOffset;
  s32 tableOffset;
  u8 *enabledFlag;
  u32 temp_a0;
  u32 index;
  void *temp_s0;
  void *state;
  void *cursor16;
  void *cursor8;
  index = 0;
  state = *((void **) (((char *) owner) + 0x6C));
  enabledFlag = &D_80112F6C;
  tableOffset = 0;
  cursor16 = state;
  first_loop:
  {
    if ((*enabledFlag) != 0)
    {
      *((u16 *) (((char *) cursor16) + 0x1BC)) = (u16) (*((u16 *) (((u8 *) gStatThresholdTable) + tableOffset)));
    }
    else
    {
      *((u16 *) (((char *) cursor16) + 0x1BC)) = 0U;
    }
    cursor16 += 2;
    do
    {
      index += 1;
    }
    while (0);
    tableOffset += 4;
  }

  if (index < 0x20U)
  {
    goto first_loop;
  }
  do { index = 0; } while (0);
  defOffset = 0;
  do { do { entryOffset = 0; } while (0); } while (0);
  cursor8 = state;
  second_loop:
  {
    if (D_80112F6C != 0)
    {
      do
      {
        *((u8 *) (((char *) cursor8) + 0x1FC)) = (u8) D_800C46A1[defOffset];
        *((u8 *) (((char *) cursor8) + 0x1FF)) = (u8) D_800C471E[defOffset];
      }
      while (0);
    }
    else
    {
      *((u8 *) (((char *) cursor8) + 0x1FC)) = 0U;
      *((u8 *) (((char *) cursor8) + 0x1FF)) = 0U;
    }
    if (!((*((u16 *) (((u8 *) sEnemyDefTable) + defOffset))) & 0x8000))
    {
    do { do { do { *((s8 *) (((char *) (state + entryOffset)) + 0x1FC)) = 0; } while (0); } while (0); } while (0);
    }
    do { do { do { defOffset += 0xE8; } while (0); } while (0); } while (0);
    temp_s0 = (void *) (((s32) state) + entryOffset);
    entryOffset += 8;
    do { do { do { cursor8 += 8; } while (0); } while (0); } while (0);
    do { do { temp_a0 = index; index += 1; } while (0); } while (0);
    *((s8 *) (((char *) temp_s0) + 0x1FD)) = 0;
    *((s8 *) (((char *) temp_s0) + 0x1FE)) = 0;
    *((f32 *) (((char *) temp_s0) + 0x200)) = (f32) (func_800645A4(temp_a0) & 0xFF);
  }

  if (index < 0x3BU)
  {
    goto second_loop;
  }
  *((s8 *) (((char *) state) + 0x1FC)) = 1;
  *((s8 *) (((char *) state) + 0x32C)) = 0;
  *((s8 *) (((char *) state) + 0x324)) = 0;
  if (D_80112F6C != 0)
  {
    *((s8 *) (((char *) state) + 0x1FC)) = 1;
  }
}
