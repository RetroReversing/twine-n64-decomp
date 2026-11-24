void *findEntryById(s32, s32);
void *findNthRecordById(s32, s32, s32);
s32 selectMenuItemByOffset2(void *, void *);
s32 selectPreviousItem(void *, void *);
s32 selectNextItem(void *, void *);
s32 selectItemBeforeCurrent(void *, void *);
s32 isSaveEntryFieldZero(void *);
s32 menuRangeFitsLimit(void *);
s32 menuItemIsActive(s32);
s32 requestSound(s32);
extern s32 D_80000001;
extern s32 sMenuMarkerColor;
extern f64 D_800D2CD0;
extern f64 D_800D2CD8;
extern void *gSaveMenuState;
extern s32 sSaveMenuColorActive;
extern s32 sSaveMenuColorIdle;
/* Updates the colors, sounds and scroll position of a save-menu row's arrow entries based on which directions are enabled; returns nonzero if the row's state byte changed. */ s32 updateSaveMenuRowHighlight(void *row, s32 inputMask, s32 useAltEntries)
{
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a0_3;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f64 var_ft0;
  f64 var_ft0_2;
  s32 *var_a0_4;
  void *inactiveState;
  void *inactiveEntry;
  s32 colorMask;
  s32 colorWord;
  s32 temp_s0;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_v1_3;
  s32 var_a1;
  unsigned short rightEnabled;
  s32 leftEnabled;
  s32 var_v0_2;
  s32 var_v1;
  s32 temp_sum;
  u8 oldState;
  u8 temp_v1;
  u8 var_s1_2;
  u8 var_v0_4;
  void *temp_a0;
  void *temp_a1;
  void *temp_a1_2;
  void *temp_s3;
  void *temp_s3_2;
  void *temp_v1_2;
  void *leftArrowEntry;
  void *rightArrowEntry;
  void *scrollEntry;
  if (row == NULL)
  {
    goto block_12;
  }
  {
    oldState = *((u8 *) (((char *) row) + 0x18));
    if (!(useAltEntries & 0xFF))
    {
      rightArrowEntry = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0xAC);
      leftArrowEntry = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0xAB);
      scrollEntry = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 4);
      var_a1 = inputMask & 0xFF;
    }
    else
    {
      rightArrowEntry = findNthRecordById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0xAC, 2);
      leftArrowEntry = findNthRecordById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0xAB, 2);
      scrollEntry = findNthRecordById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 4, 2);
      var_a1 = inputMask & 0xFF;
    }
    switch (var_a1)
    {
      case 0:
        leftEnabled = menuItemIsActive(0x25) & 0xFF;
        var_a0 = 0x26;
        goto block_9;

      case 1:
        leftEnabled = menuItemIsActive(0x1E) & 0xFF;
        var_a0 = 0x1F;
        block_9:
      rightEnabled = menuItemIsActive(var_a0) & 0xFF;

        break;

      default:
        rightEnabled = menuItemIsActive(0x25);
        rightEnabled |= menuItemIsActive(0x1E);
        leftEnabled = rightEnabled & 0xFF;
        rightEnabled = menuItemIsActive(0x26);
        rightEnabled |= menuItemIsActive(0x1F);
        rightEnabled &= 0xFF;
        break;

    }

    if ((leftArrowEntry != NULL) & (rightArrowEntry != NULL))
    {
      goto active_check;
    }
    block_12:
    return 0;

    active_check:
    if ((leftEnabled != 0) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
    {
      if (isSaveEntryFieldZero(row) & 0xFF)
      {
        var_a0_2 = 0xEC;
      }
      else
      {
        var_a0_2 = 0xEB;
      }
      requestSound(var_a0_2);
      temp_a1 = *((void **) (((char *) leftArrowEntry) + 8));
      *((s32 *) (((char *) temp_a1) + 0x10)) = (s32) ((sSaveMenuColorActive & (~0xFF)) | (*((u8 *) (((char *) gSaveMenuState) + 0x30))));
      if ((*((u8 *) (((char *) row) + 0x1E))) == 0)
      {
        selectPreviousItem(row, temp_a1);
      }
      else
      {
        selectItemBeforeCurrent(row, temp_a1);
      }
    }
    else
      if ((rightEnabled != 0) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
    {
      if (menuRangeFitsLimit(row) & 0xFF)
      {
        var_a0_3 = 0xEC;
      }
      else
      {
        var_a0_3 = 0xEB;
      }
      if (gSaveMenuState)
      {
        requestSound(var_a0_3);
        temp_a1_2 = *((void **) (((char *) rightArrowEntry) + 8));
        *((s32 *) (((char *) temp_a1_2) + 0x10)) = (s32) ((sSaveMenuColorActive & (~0xFF)) | (*((u8 *) (((char *) gSaveMenuState) + 0x30))));
      }
      else
      {
        requestSound(var_a0_3);
        temp_a1_2 = *((void **) (((char *) rightArrowEntry) + 8));
        *((s32 *) (((char *) temp_a1_2) + 0x10)) = (s32) ((sSaveMenuColorActive & (~0xFF)) | (*((u8 *) (((char *) gSaveMenuState) + 0x30))));
      }
      if ((*((u8 *) (((char *) row) + 0x1E))) == 0)
      {
        selectMenuItemByOffset2(row, temp_a1_2);
      }
      else
      {
        selectNextItem(row, temp_a1_2);
      }
    }
    else
    {
      if ((*((s32 *) (((char *) rightArrowEntry) + 0x20))) != 0x390024)
      {
        inactiveEntry = *((void **) (((char *) leftArrowEntry) + 8));
        inactiveState = gSaveMenuState;
        var_a0_4 = (s32 *) (((char *) (&sMenuMarkerColor)) - 0);
      }
      else
      {
        inactiveEntry = *((void **) (((char *) leftArrowEntry) + 8));
        inactiveState = gSaveMenuState;
        var_a0_4 = &sSaveMenuColorIdle;
      }
      colorMask = -0x100;
      *((s32 *) (((char *) inactiveEntry) + 0x10)) = ((*var_a0_4) & colorMask) | (*((u8 *) (((char *) inactiveState) + 0x30)));
      *((s32 *) (((char *) (*((void **) (((char *) rightArrowEntry) + 8)))) + 0x10)) = (s32) (((*var_a0_4) & colorMask) | (*((u8 *) (((char *) inactiveState) + 0x30))));
      temp_v1 = *((u8 *) (((char *) gSaveMenuState) + 0x30));
      if (temp_v1 < 0xFF)
      {
        var_s1_2 = temp_v1;
      }
      else
      {
        var_s1_2 = 0xFF;
      }
      temp_s3 = *((void **) (((char *) leftArrowEntry) + 8));
      colorMask = 0; colorWord = *((s32 *) (((char *) temp_s3) + 0x10)); temp_s0 = colorWord & (~0xFF);
      if (isSaveEntryFieldZero(row) & 0xFF)
      {
        var_v0_2 = var_s1_2 | temp_s0;
      }
      else
      {
        var_v0_2 = temp_s0 | (*((u8 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x13)));
      }
      *((s32 *) (((char *) temp_s3) + 0x10)) = var_v0_2;
      temp_s3_2 = *((void **) (((char *) rightArrowEntry) + 8));
      temp_s0 = (*((s32 *) (((char *) temp_s3_2) + 0x10))) & (~0xFF);
      *((s32 *) (((char *) temp_s3_2) + 0x10)) = (menuRangeFitsLimit(row) & 0xFF) ? ((unsigned long long) (var_s1_2 | temp_s0)) : ((unsigned long long) (temp_s0 | (*((u8 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x13)))));
    }

    if (scrollEntry != NULL)
    {
      temp_v1_2 = *((void **) (((char *) scrollEntry) + 8));
      if (temp_v1_2 != NULL)
      {
        temp_v0 = *((s32 *) (((char *) scrollEntry) + 0x14));
        var_ft0 = (f64) temp_v0;
        temp_a0 = temp_v1_2;
        if (temp_v0 < 0)
        {
          var_ft0 += D_800D2CD0;
        }
        temp_fv1 = (*((f32 *) (((char *) row) + 0xC))) * ((f32) var_ft0);
        var_v0_4 = ((u32) temp_fv1) + 1;
        *((u8 *) (((char *) temp_a0) + 0x29)) = var_v0_4;
        temp_a0 = *((void **) (((char *) scrollEntry) + 8));
        temp_v1_3 = *((s32 *) (((char *) scrollEntry) + 0x14));
        if (((u32) temp_v1_3) < ((u8) (*((u8 *) (((char *) temp_a0) + 0x29)))))
        {
          *((u8 *) (((char *) temp_a0) + 0x29)) = (u8) temp_v1_3;
        }
        temp_v0_2 = *((s32 *) (((char *) scrollEntry) + 0x14));
        temp_a0 = *((void * volatile *) (((char *) scrollEntry) + 8));
        var_ft0_2 = (f64) temp_v0_2;
        if (temp_v0_2 < 0)
        {
          var_ft0_2 += D_800D2CD8;
        }
        temp_fv1_2 = (*((f32 *) (((char *) row) + 0x10))) * ((f32) var_ft0_2);
        if (!(temp_fv1_2 >= 2147483648.0f))
        {
          var_v1 = (s32) temp_fv1_2;
        }
        else
        {
          var_v1 = ((s32) (temp_fv1_2 - 2147483648.0f)) | 0x80000000;
        }
        temp_sum = var_v1 + (*((u16 *) (((char *) scrollEntry) + 0x1A)));
        *((s16 *) (((char *) temp_a0) + 0x22)) = (s16) temp_sum;
      }
    }
    return oldState != (*((u8 *) (((char *) row) + 0x18)));
  }
}


