s32 activateIdList(u16 *);
s32 clearProbeState(void *, s32);
void *findEntryById(s32, s32);
s32 formatTextEntry(void *, const void *, s32);
s32 func_80001E28(s16);
s32 func_8000237C(void *, s32, s32, u8);
s32 func_80002BD0(void *, s32);
s32 func_80019E28(void *);
s32 func_80027C60(s32);
s32 func_8002B8AC();
s32 func_8002B930(s32, s32);
s32 func_8002B9CC(s32);
s32 func_8002BA6C(s32);
s32 getKeyEntryFlag(s32);
s32 menuItemIsActive(s32);
s32 updateActiveMenuState();
extern u8 D_800BF688;
extern char D_800D2858[];
extern s16 *D_800C3CF8;
extern u8 D_801001A3;
extern void *gPickupActor;
extern u8 gPickupSavedByte;
extern void *gSaveMenuState;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo;
extern s16 gSharedItemArg;
extern s8 gSharedItemBusy;
extern u16 gSharedItemId;
extern s32 sFmtEntryName;
inline static s8 inline_fn(u8 arg0)
{
  return (s8) (arg0 - 1);
}

inline static u8 *inline_fn2(u8 *arg0, int arg1)
{
  return arg0 - arg1;
}

void func_80019F7C(void)
{
  char *__repair_addr;
  u8 *slot;
  u8 *__repair_offset;
  u16 *list;
  void **actor;
  s32 id;
  s32 temp_v0;
  s32 var_s1;
  u16 temp_v1;
  u16 temp_v1_3;
  u8 temp_s0_2;
  u8 temp_v1_2;
  void *temp_s0;
  void *temp_s3;
  void *temp_s4;
  temp_s4 = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x400C);
  temp_s0 = *((void **) (((char *) gSaveMenuState) + 0x18));
  do
  {
    updateActiveMenuState();
  }
  while (0);
  if (slot)
  {
    var_s1 = *(*((s32 **) (((char *) temp_s0) + 0x10)));
    temp_s3 = temp_s0 + 0x28;
  }
  else
  {
    var_s1 = *(*((s32 **) (((char *) temp_s0) + 0x10)));
    temp_s3 = temp_s0 + 0x28;
  }
  if (((*((u8 *) (((char *) gSaveMenuState) + 0x2D))) != 0) && ((*((u8 *) (((char *) gSaveMenuState) + 0x2E))) == 0))
  {
    slot = &gPickupSavedByte;
    {
      extern char D_8010019C[];
      *((u8 *) ((((char *) D_8010019C) + ((*slot) * 0x18)) + 7)) = 0;
    }
    if (menuItemIsActive(0x20) & 0xFF)
    {
      var_s1 = func_8002B930(var_s1, -1);
    }
    if (menuItemIsActive(0x21) & 0xFF)
    {
      var_s1 = func_8002B930(var_s1, 1);
    }
    *(*((s32 **) (((char *) temp_s0) + 0x10))) = var_s1;
    actor = &gPickupActor;
    if ((*actor) != NULL)
    {
      func_8002B8AC();
      temp_v1 = *(*((s16 **) (((u8 *) (&D_800C3CF8)) + (func_8002B9CC(var_s1) * 0xC))));
      gSharedItemArg = -1;
      gSharedItemBusy = 1;
      list = &gSharedItemId;
      *list = temp_v1;
      activateIdList(list);
      gSharedItemBusy = 0;
      id = func_8002B9CC(var_s1);
      func_8000237C(*actor, id, 0, *((&D_801001A3) + ((*slot) * 0x18)));
      func_80002BD0(*actor, 0x14D);
      *((f32 *) (((char *) (*((void **) (((char *) gPickupActor) + 0x68)))) + 0x34)) = 0.05f;
      if (!(getKeyEntryFlag(*((s32 *) (((char *) (&gSaveSlotInfo)) + ((*slot) * 0x18)))) & 0xFF))
      {
        clearProbeState(*actor, 0x2A9);
      }
      else
      {
        clearProbeState(*actor, 0x327);
      }
      goto block_11;
    }
  }
  else
  {
    block_11:
    *((u8 *) (((char *) gSaveMenuState) + 0x2D)) = 0U;

    if (func_80027C60(0x28) & 0xFF)
    {
      u8 *decrementSlot = &gPickupSavedByte;
      if (temp_s3 || gSaveMenuState)
      {
        id = (*decrementSlot) * 0x18;
        temp_v1_2 = *((&D_801001A3) + id);
      }
      else
      {
        id = (*decrementSlot) * 0x18;
        do
        {
          temp_v1_2 = *((&D_801001A3) + id);
        }
        while (0);
      }
      if (temp_v1_2 != 0)
      {
        if (1)
        {
          __repair_addr = (char *) ((unsigned) id + (unsigned) inline_fn2(decrementSlot, 0x115));
        }
        *((s8 *) (((char *) __repair_addr) + 0xB)) = inline_fn(temp_v1_2);
        *((u8 *) (((char *) gSaveMenuState) + 0x2D)) = 1U;
      }
    }
    if (func_80027C60(0x29) & 0xFF)
    {
      slot = &gPickupSavedByte;
      temp_s0_2 = *((&D_801001A3) + ((*slot) * 0x18));
      if (((s32) temp_s0_2) < func_80001E28(*(*((s16 **) (((u8 *) (&D_800C3CF8)) + (func_8002B9CC(var_s1) * 0xC))))))
      {
        temp_v0 = (*slot) * 0x18;
        __repair_offset = slot - 0x115;
        *((s8 *) (((char *) (temp_v0 + __repair_offset)) + 0xB)) = (s8) ((*((&D_801001A3) + temp_v0)) + 1);
        *((u8 *) (((char *) gSaveMenuState) + 0x2D)) = 1U;
      }
    }
    if (((*((u8 *) (((char *) gSaveMenuState) + 0x2D))) != 0) && ((*((u8 *) (((char *) gSaveMenuState) + 0x2E))) == 0))
    {
      actor = &gPickupActor;
      if ((*actor) != NULL)
      {
        func_8002B8AC();
        temp_v1_3 = *(*((s16 **) (((u8 *) (&D_800C3CF8)) + (0xC * func_8002B9CC(var_s1)))));
        gSharedItemArg = -1;
        gSharedItemBusy = 1;
        list = &gSharedItemId;
        *list = temp_v1_3;
        activateIdList(list);
        gSharedItemBusy = 0;
        id = func_8002B9CC(var_s1);
        func_8000237C(*actor, id, 0, *((&D_801001A3) + (gPickupSavedByte * 0x18)));
        func_80002BD0(*actor, 0x14D);
        *((f32 *) (((char *) (*((void **) (((char *) gPickupActor) + 0x68)))) + 0x34)) = 0.05f;
        goto block_21;
      }
    }
    else
    {
      block_21:
      if (temp_s3 != NULL)
      {
        if (slot)
        {
          formatTextEntry(temp_s3, &sFmtEntryName, func_8002BA6C(var_s1));
        }
        else
        {
          formatTextEntry(temp_s3, &sFmtEntryName, func_8002BA6C(var_s1));
        }
      }

      if (temp_s4 != NULL)
      {
        func_80019E28(temp_s4);
      }
      {
      u8 *tailSlot = &gPickupSavedByte;
      if (gSaveSlotCount < ((s32) (*tailSlot)))
      {
        if (1)
        {
          formatTextEntry(findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x4004), D_800D2858, (*((u8 *) (((char *) (&D_800BF688)) + ((*((s32 *) (((char *) (&gSaveSlotInfo)) + ((*tailSlot) * 0x18)))) * 0xC)))) * 5);
        }
      }
      }
    }
  }
}


