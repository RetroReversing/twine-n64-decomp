#undef sp34
s32 actorLinkToSurface(s32, void *, s32);
s32 findEntryById(s32, s32);
s32 formatTextEntry(void *, char *, void *);
s32 func_8000237C();
s32 func_80002BD0();
s32 clearProbeState(void *, s32);
s32 func_800160FC();
s32 spawnTrackMarker(u8);
s32 func_80018318();
s32 func_80019E28();
s32 func_80022A30();
s32 func_80022AD8();
s32 getSaveSlotIndex(s32);
s16 func_80022DE8();
s32 func_80022E18();
s32 func_80025F78();
void *findEntryPayload(s32, s32);
s32 func_8002A644();
s32 func_8002A7CC();
s32 selectItemAndUpdateAmount(s32 *, s16);
s32 func_8002AC04();
s32 func_8002ACB4();
s32 func_8002B8AC();
s32 func_8002B9CC();
void *func_8002BA6C();
s32 activateIdList(u16 *);
void *lookupDataEntry(s32);
s32 getKeyEntryFlag(s32);
s32 layoutTextBox(s32, void *, s32);
void *spawnEffectObject(s32, s32, s32);
s32 sprintf(void *, char *, void *, s32);
extern s32 sMenuItemParamTable[];
extern s8 gMenuNeedsRedraw;
extern u8 D_800BF688;
extern s32 D_800C3CF8;
extern u8 D_801001A0;
extern u8 sSaveSlotInfo;
extern u8 D_801001A3;
extern u8 gPickupSavedByte;
extern s32 gSaveTotalSlots;
extern s8 D_801002E6;
extern s8 D_801002E7;
extern s8 D_801002E8;
extern s8 D_801002E9;
extern s32 D_80100408;
extern s32 D_80102EBC;
extern s32 D_80102EC0;
extern s32 D_80102EC4;
extern s32 D_80102F48[];
extern s8 D_80104311;
extern s32 gPickupSearchBox;
extern s32 func_8001AC88;
extern s32 bindMenuItemRecord;
extern u8 sMenuListKind;
extern void *gSaveMenuState;
extern void * volatile gPickupActor;
extern volatile long *gProbeObjectList;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo;
extern s16 gSharedItemArg;
extern s8 gSharedItemBusy;
extern u16 gSharedItemId;
extern char D_800D2858[];
extern char D_800D285C[];
extern char sFmtEntryName[];
inline static int inline_fn(volatile u8 *arg0)
{
  return (*arg0) * 0x18;
}

void func_8001ADE8(void)
{
  s32 sp34;
  char *temp_s0_3;
  volatile u8 *savedByte;
  volatile u8 *savedByteLate;
  void *menuState;
  void *actor;
  s32 entry;
  volatile u8 *slotField;
  s32 menuRoot;
  void * volatile *actorSlot;
  s32 model;
  s32 var_a1;
  s32 *temp_s0_2;
  s32 *markers;
  s32 markerFlags;
  u32 temp_a0;
  u8 temp_a0_2;
  s32 temp_s3;
  s32 temp_v0;
  register s32 temp_v0_4;
  s32 temp_v1;
  s32 var_a0;
  s32 var_a3;
  s32 var_s0_1;
  s32 var_s0_2;
  s32 var_s0_3;
  s32 var_s0_4;
  s32 var_s2;
  s32 off111;
  s32 off10b;
  s32 var_v0;
  s32 var_v0_2;
  register u16 temp_v0_2;
  u16 temp_v1_4;
  u32 temp_s0;
  volatile u8 *temp_s0_4;
  u8 temp_v1_2;
  s32 var_a0_3;
  void *temp_a0_3;
  void *temp_a1;
  void *temp_fp;
  void *temp_s1;
  void *temp_s5;
  register void *temp_s6;
  void *temp_s7;
  void *temp_v0_3;
  void *temp_v0_5;
  void *temp_v1_3;
  register void *var_a2;
  menuRoot = *((s32 *) (((char *) gSaveMenuState) + 0x10));
  gMenuNeedsRedraw = 1;
  temp_fp = findEntryPayload(menuRoot, 0x70);
  temp_s7 = findEntryPayload(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x65);
  temp_s6 = findEntryPayload(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x64);
  temp_s5 = findEntryPayload(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x6A);
  sp34 = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x400C);
  if ((((temp_fp != NULL) & (temp_s7 != NULL)) && ((temp_s6 != NULL) & (temp_s5 != NULL))) && sp34)
  {
    func_8002A644(&gPickupSearchBox, &D_80100408, 0x1A4, 0xB, 0x2C, 0xB4, 0x32, 0xE, 1, &bindMenuItemRecord, &func_8001AC88);
    func_80022A30(sMenuListKind, 0x27, 0x2E, 0x3C, 0x98);
    var_s2 = 0;
    if (gSaveTotalSlots > 0)
    {
      markers = D_80102F48;
      do
      {
        var_s0_1 = (u16) var_s2;
        temp_s3 = getSaveSlotIndex(var_s0_1);
        temp_v0 = spawnTrackMarker(sMenuListKind);
        var_s0_2 = (var_s0_1 * 4) + (s32) markers;
        *((s32 *) var_s0_2) = temp_v0;
        if (temp_v0 != 0)
        {
          temp_s1 = lookupDataEntry((var_s2 + 0x4008) & 0xFFFF);
          temp_s0 = temp_s3 & 0xFFFF;
          if (4U > temp_s0)
          {
            sprintf(temp_s1, D_800D285C, lookupDataEntry(0xAD), temp_s0 + 1);
          }
          else
          {
            sprintf(temp_s1, D_800D285C, lookupDataEntry(0x158), temp_s0 - 3);
          }
          func_800160FC(*((var_s2 & 0xFFFF) + markers), temp_s1, 0x40);
        }
        var_s0_3 = (u16) var_s2;
        temp_s0_2 = (s32 *) ((var_s0_3 * 4) + (s32) markers);
        var_s2 += 1;
        temp_a0 = *temp_s0_2;
        markerFlags = func_80018318(temp_a0);
        func_8002A7CC(&gPickupSearchBox, *temp_s0_2, temp_s3 & 0xFF, markerFlags & 0xFF);
        var_s0_4 = var_s2 & 0xFFFF;
      }
      while (((s32) ((u16) var_s2)) < gSaveTotalSlots);
    }
    func_80022E18(sMenuListKind);
    func_80022AD8(sMenuListKind);
    savedByte = &gPickupSavedByte;
    selectItemAndUpdateAmount(&gPickupSearchBox, func_80022DE8(*savedByte));
    func_8002AC04(&gPickupSearchBox, 1);
    func_8002ACB4(&gPickupSearchBox);
    temp_s0_3 = sFmtEntryName;
    formatTextEntry(temp_fp, temp_s0_3, func_8002BA6C(*((s32 *) (((u8 *) (&gSaveSlotInfo)) + inline_fn(savedByte)))));
    entry = sp34;
    *((void **) (((char *) temp_fp) + (-0x18))) = inline_fn(savedByte) + (off111 = savedByte - 0x111);
    func_80019E28(entry);
    temp_s0_4 = savedByte - 0x109;
    formatTextEntry(temp_s7, temp_s0_3, inline_fn(savedByte) + temp_s0_4);
    *((void **) (((char *) temp_s7) + (-0x18))) = (void *) (inline_fn(savedByte) + temp_s0_4);
    temp_v1 = inline_fn(savedByte);
    D_80104311 = (*((&D_801001A0) + temp_v1)) / 10U;
    formatTextEntry(temp_s6, D_800D2858, (void *) (*((&D_801001A0) + temp_v1)));
    *((void **) (((char *) temp_s5) + (-0x18))) = (void *) (inline_fn(savedByte) + (off10b = savedByte - 0x10B));
    temp_v1_2 = *((&sSaveSlotInfo) + inline_fn(savedByte));
    switch (temp_v1_2)
    {
      case 0:
        var_a0 = 0xA;
        goto block_19;

      case 1:
        var_a0 = 9;
        goto block_19;

      case 2:
        var_a0 = 0x6B;
        goto block_19;

      case 3:
        var_a0 = 0x6C;
        goto block_19;

      case 4:
        var_a0 = 0x296;
        goto block_19;

      case 5:
        var_a0 = 0x297;
        block_19:
      formatTextEntry(temp_s5, sFmtEntryName, lookupDataEntry(var_a0));

        break;

    }

    if ((*((u8 *) (((char *) gSaveMenuState) + 8))) != 1)
    {
      void *sound;
      temp_v1_3 = *((void **) (((char *) gSaveMenuState) + 0x18));
      temp_v0_2 = *((u16 *) (((char *) temp_v1_3) + 0xC));
      temp_a0_2 = temp_v0_2 & 0xF;
      if (temp_a0_2 != 0)
      {
        sound = *((void **) (((char *) temp_v1_3) + 8));
        var_v0 = sMenuItemParamTable[temp_a0_2];
        var_a0 = *((u8 *) (((char *) gSaveMenuState) + 0x30));
      }
      else
      {
        if (temp_v0_2 & 0x80)
        {
          sound = *((void **) (((char *) temp_v1_3) + 8));
          var_v0 = D_80102EBC;
        }
        else
        {
          sound = *((void **) (((char *) temp_v1_3) + 8));
          var_v0 = D_80102EC4;
        }
        var_a0 = *((u8 *) (((char *) sound) + 0x13));
      }
      *((s32 *) (((char *) sound) + 0x10)) = (var_v0 & (~0xFF)) | var_a0;
      menuState = gSaveMenuState;
      *((u8 *) (((char *) gSaveMenuState) + 8)) = 1U;

      {
        *((void **) (((char *) gSaveMenuState) + 0x18)) = (void *) (temp_s7 - 0x28); temp_v0_3 = *((void * volatile *) (((char *) menuState) + 0x18)); temp_a1 = *((void **) (((char *) temp_v0_3) + 8));
        if (temp_a1 != NULL)
        {
          temp_v0_4 = (*((u16 *) (((char *) temp_v0_3) + 0xC))) & 0xF;
          if (temp_v0_4 != 0)
          {
            var_v0_2 = sMenuItemParamTable[temp_v0_4]; var_a0_3 = *((u8 *) (((char *) menuState) + 0x30));
          }
          else
          {
            var_v0_2 = D_80102EC0; var_a0_3 = *((u8 *) (((char *) temp_a1) + 0x13));
          }
          if (D_800D285C)
          {
            *((s32 *) (((char *) temp_a1) + 0x10)) = (s32) ((var_v0_2 & (~0xFF)) | var_a0_3);
          }
          else
          {
            *((s32 *) (((char *) temp_a1) + 0x10)) = (s32) ((var_v0_2 & (~0xFF)) | var_a0_3);
          }
        }
        layoutTextBox(*((s32 *) (((char *) gSaveMenuState) + 0x1C)), *((void **) (((char *) gSaveMenuState) + 0x18)), 0);
      }

    }
    savedByteLate = &gPickupSavedByte;
    temp_a0_3 = temp_s6 - 0x28;
    if (gSaveSlotCount < ((s32) (*savedByteLate)))
    {
      *((s8 *) (((char *) temp_s7) + (-1))) = 7;
      *((s8 *) (((char *) temp_fp) + (-2))) = 1;
      D_801002E8 = 7;
      D_801002E9 = 7;
      D_801002E6 = 1;
      D_801002E7 = 1;
      func_80025F78(temp_a0_3, 0xD);
      do { func_80025F78(temp_s6, 0xD); } while (0);
      func_80025F78(temp_s5 - 0x28, 0xD);
      func_80025F78(temp_s5, 0xD);
      formatTextEntry(temp_s6, D_800D2858, (void *) ((*((&D_800BF688) + ((*((s32 *) (((u8 *) (&gSaveSlotInfo)) + inline_fn(savedByteLate)))) * 0xC))) * 5));
      formatTextEntry(temp_s5, sFmtEntryName, lookupDataEntry(0x13));
    }
    else
    {

      {
        *((s8 *) (((char *) temp_s7) + (-1))) = 3;
        *((s8 *) (((char *) temp_fp) + (-2))) = 5; D_801002E8 = 7; D_801002E9 = 3; D_801002E6 = 1;
        D_801002E7 = 1;
        func_80025F78(temp_a0_3, 0);
        func_80025F78(temp_s6, 0);
        func_80025F78(temp_s5 - 0x28, 0);
      }

      func_80025F78(temp_s5, 0);
    }
    actorSlot = &gPickupActor;
    if ((*((s32 *) actorSlot)) == NULL)
    {
      actor = spawnEffectObject(0, 0, 0);
      *((s32 *) actorSlot) = actor;
      if (actor == NULL)
      {
        return;
      }
    }
    {
      *((s16 *) (((char *) gPickupActor) + 0x78)) = 0x1F;
      *((s32 *) (((char *) gPickupActor) + 0x58)) |= 0x400;
      *((s8 *) (((char *) gPickupActor) + 0x7E)) = 1;
      *((s16 *) (((char *) gPickupActor) + 0x7A)) = 0;
      *((f32 *) (((char *) gPickupActor) + 0x54)) = 1.05f;
      *((u8 *) (((char *) gPickupActor) + 0x7F)) = 0xFF;
      *((u8 *) (((char *) gPickupActor) + 0x80)) = 0xFF;
      *((u8 *) (((char *) gPickupActor) + 0x81)) = 0xFF;
      *((f32 *) (((char *) gPickupActor) + 0x24)) = 1.25f;
      *((f32 *) (((char *) gPickupActor) + 0x28)) = 0.15f;
 do { *((f32 *) (((char *) gPickupActor) + 0x2C)) = -3.0f; func_8002B8AC(); actorLinkToSurface(*gProbeObjectList, *((s32 *) actorSlot), 1); } while (0);
      savedByteLate = &gPickupSavedByte;
      temp_v1_4 = *((u16 *) (*((u16 **) (((u8 *) (&D_800C3CF8)) + (func_8002B9CC(*((s32 *) (((u8 *) (&gSaveSlotInfo)) + inline_fn(savedByteLate)))) * 0xC)))));
      gSharedItemArg = -1;
      gSharedItemBusy = 1;
      {
        u16 *itemId = &gSharedItemId;
        *itemId = temp_v1_4;
        activateIdList(itemId);
      }
      model = *((s32 *) (((u8 *) (&gSaveSlotInfo)) + inline_fn(savedByteLate)));
      gSharedItemBusy = 0;
      model = func_8002B9CC(model);
      func_8000237C(*((s32 *) actorSlot), model, 0, *((&D_801001A3) + inline_fn(savedByteLate)));
      func_80002BD0(*((s32 *) actorSlot), 0x14D);
      *((f32 *) (((char *) (*((void **) (((char *) gPickupActor) + 0x68)))) + 0x34)) = 0.05f;
      if (!(getKeyEntryFlag(*((s32 *) (((u8 *) (&gSaveSlotInfo)) + inline_fn(savedByteLate)))) & 0xFF))
      {
        clearProbeState(*((s32 *) actorSlot), 0x2A9);
      }
      else
      {
        clearProbeState(*((s32 *) actorSlot), 0x327);
      }
    }
  }
}

