s32 findSaveSlotByMode();
s32 func_80022A30();
s32 func_80022AD8();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002AC04();
s32 func_8002CBD8();
s32 func_8002D09C();
s32 refreshSlotMenuLabels();
s32 selectItemAndUpdateAmount();
s32 spawnTextNode();
s32 updateSaveMenuSprites();
extern u16 D_800B81A8;
extern u8 D_800B81AB;
extern char D_800BD5D0[];
extern char D_80107EA8[];
extern char D_80109C18[];
extern char D_80109C1C[];
extern char D_8010D478[];
extern s32 func_800241F8;
extern s8 gMenuNeedsRedraw;
extern void *gSaveMenuState;
extern u8 sMenuListKind;
extern u16 sSaveMenuAction;
extern s8 sSaveMenuRefresh;
extern s32 sSaveMenuSpriteFirst;
extern s32 sSaveMenuSpriteSecond;
extern s32 updateSaveMenuEntries;
void func_8002424C(void)
{
  int __repair_constant = 3;
  char *__base_D_800BD5D0;
  s16 *temp_s3;
  s32 temp_a0;
  s32 temp_s0;
  s32 temp_v0;
  s32 var_s1;
  s32 temp_v1;
  u16 var_v0;
  void *temp_s2;
  func_8002CBD8();
  gMenuNeedsRedraw = 0;
  func_8002A644(D_80107EA8, D_8010D478, 0xC0, 6, 0x58, 0xB2, 0x3C, 0x14, 1, &updateSaveMenuEntries, &func_800241F8);
  __base_D_800BD5D0 = D_800BD5D0;
  temp_s2 = __base_D_800BD5D0 - 0x4C;
  temp_s3 = __base_D_800BD5D0 - 0x34;
  func_80022A30((var_s1 = 0, sMenuListKind), 0x20, 0x3C, 0xF8, 0x78);
  sSaveMenuSpriteSecond = spawnTextNode(__base_D_800BD5D0);
  sSaveMenuSpriteFirst = spawnTextNode(__base_D_800BD5D0 - 0x24);
  do
  {
    temp_a0 = var_s1 & 0xFFFF;
    *((s16 *) (((char *) temp_s2) + 0)) = (s16) sMenuListKind;
 do { *((s16 *) (((char *) temp_s2) + 0x24)) = (s16) sMenuListKind; temp_v0 = temp_a0 * 8; *((s32 *) (D_80109C18 + temp_v0)) = 0; *((s32 *) (D_80109C1C + temp_v0)) = 0; if (func_8002D09C(temp_a0) & 0xFFFF) { *((s32 *) (((char *) temp_s2) + (-8))) = 0xF; } else { *((s32 *) (((char *) temp_s2) + (-8))) = 0x10; } *temp_s3 = var_s1 + 0x4000; *((s32 *) (D_80109C18 + (temp_s0 = (var_s1 & 0xFFFF) * 8))) = spawnTextNode(temp_s3 - 0x14); *((s32 *) (D_80109C1C + temp_s0)) = spawnTextNode(temp_s3 - 0x38); func_8002A7CC(D_80107EA8, temp_s0 + D_80109C18, var_s1 & 0xFF, 1); var_s1 += 1; } while (0);
  }
  while (((u32) (var_s1 & 0xFFFF)) < 0x10U);
  refreshSlotMenuLabels();
  sSaveMenuRefresh = 0;
  sSaveMenuAction = 1;
  func_80022AD8(sMenuListKind);
  temp_v1 = *((u16 *) (((char *) gSaveMenuState) + 0x14));
  if (temp_v1 != 0x1A)
  {
    if (((s32) temp_v1) < 0x1B)
    {
      var_v0 = __repair_constant;
      if (temp_v1 != 0x19)
      {
        var_v0 = 1;
      }
    }
    else
    {
      var_v0 = 1;
      if (temp_v1 == 0x1B)
      {
        var_v0 = __repair_constant;
      }
    }
  }
  else
  {
    var_v0 = 2;
  }
  sSaveMenuAction = var_v0;
  do
  {
    updateSaveMenuSprites(sSaveMenuAction, D_800B81A8, D_800B81AB, 1);
  }
  while (0);
  selectItemAndUpdateAmount(D_80107EA8, 0);
  func_8002AC04(D_80107EA8, 1);
  if (((u32) ((*((u16 *) (((char *) gSaveMenuState) + 0x14))) - 0x19)) < 2U)
  {
    selectItemAndUpdateAmount(D_80107EA8, findSaveSlotByMode(sSaveMenuAction) & 0xFF);
  }
  *((s8 *) (((char *) gSaveMenuState) + 0x2C)) = 0;
}
