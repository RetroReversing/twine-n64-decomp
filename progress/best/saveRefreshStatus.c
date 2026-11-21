#define ENT(i) ((i) * 104 + gSaveSlotTable)
#define CP32(d, s) __builtin_memcpy((d), (s), 32)
extern s16 gSaveSlot;
extern u8 gSaveSlotTable[];
extern u8 gSaveHeaderCopy[];
extern u32 gSaveBackup[];
extern s16 gSaveStatus;
extern s32 gSaveCmdResult;
extern u8 D_80102D60;
extern s16 gSaveSlotValid[];
extern s32 saveSubmitCommand(s32, void *, s32, s32, s32, s32, s32, s32);
extern s32 saveWaitCommand(void);
extern s32 func_80010B60(unsigned short);
typedef struct 
{
  u32 v;
} __attribute__((packed)) UW;
s32 saveRefreshStatus(void)
{
  s32 idx;
  u8 *base = gSaveSlotTable;
  s32 st;
  s32 a1;
  u8 flag;
  idx = gSaveSlot;
  saveSubmitCommand(7, ENT(idx), idx, 0, 0, 0, 0, 0);
  saveWaitCommand();
  if (gSaveSlot != 0)
  {
    return 0;
  }
  switch (gSaveStatus)
  {
    case 0x20:
      goto cec;

    case 0x21:

    case 0x25:

    case 0x62:
      goto d38;

    case 1:

    case 3:

    case 4:
      goto fb4;

    default:
      goto d110e4;

  }

  cec:
  {
    s32 mode = gSaveCmdResult;
    if ((mode == 0xB) || (mode == 2))
    {
      goto d18;
    }
    if (mode != 0)
    {
      goto l11374;
    }
    d18:
    saveSubmitCommand(0xC, ENT(0), 0, 0, 0, 0, 0, 0);

    goto after_c;
  }

  d38:
  {
    s32 mode = gSaveCmdResult;
    if ((mode == 0xA) || (mode == 2))
    {
      goto d64;
    }
    if (mode != 0)
    {
      goto l11374;
    }
    d64:
    idx = gSaveSlot;

    saveSubmitCommand(0xC, ENT(idx), idx, 0, 0, 0, 0, 0);
  }

  after_c:
  if (saveWaitCommand() == 0)
  {
    goto l11434;
  }

  idx = gSaveSlot;
  saveSubmitCommand(0xE, ENT(idx), idx, 0, 0, 0, 0, 0);
  if (saveWaitCommand() == 0)
  {
    goto l113d8;
  }
  {
    u32 *backup = gSaveBackup;
    u8 *payload = gSaveSlotTable + 12;
    s32 copyIdx = gSaveSlot;
    CP32(backup, payload + (copyIdx * 104));
    idx = *((volatile s16 *) (&gSaveSlot));
    saveSubmitCommand(7, ENT(idx), idx, 0, 0, 0, 0, 0);
    if (saveWaitCommand() != 0)
    {
      goto fa4;
    }
    idx = gSaveSlot;
    D_80102D60 = 0;
    CP32(backup, payload + (idx * 104));
  }
  fa4:
  gSaveStatus = 0x12;

  return 0x12;
  fb4:
  a1 = gSaveCmdResult;

  if (a1 == 0xB)
  {
    gSaveStatus = 0x62;
    return 0x62;
  }
  if (a1 != 2)
  {
    goto d110e4;
  }
  idx = gSaveSlot;
  saveSubmitCommand(0xE, ENT(idx), idx, 0, 0, 0, 0, 0);
  if (saveWaitCommand() == 0)
  {
    goto l113d8;
  }
  idx = gSaveSlot;
  saveSubmitCommand(0xC, ENT(idx), idx, 0, 0, 0, 0, 0);
  if (saveWaitCommand() == 0)
  {
    goto l11434;
  }
  idx = gSaveSlot;
  saveSubmitCommand(7, ENT(idx), idx, 0, 0, 0, 0, 0);
  saveWaitCommand();
  a1 = gSaveCmdResult;
  if (((a1 == 0) || (a1 == 0xB)) || (a1 == 0xA))
  {
    goto l114cc;
  }
  goto d110e4;
  d110e4:
  if (gSaveCmdResult != 0)
  {
    goto l11374;
  }

  st = gSaveStatus;
  if (((st == 0x10) || (st == 0x63)) || (st == 0xF))
  {
    idx = gSaveSlot;
    D_80102D60 = 0;
    CP32(gSaveBackup, gSaveHeaderCopy + (idx * 104));
    gSaveStatus = 0;
    return 0;
  }
  a1 = 0;
  do
  {
    u8 *payload = gSaveHeaderCopy + (gSaveSlot * 104);
    if (((u8 *) gSaveBackup)[(u16) a1] == payload[(u16) a1])
    {
      goto equal;
    }
    flag = D_80102D60;
    CP32(gSaveBackup, payload);
    if (flag != 0)
    {
      D_80102D60 = 0;
      gSaveStatus = 0;
    }
    else
    {
      gSaveStatus = 0x12;
    }
    return (u16) gSaveStatus;
    equal:
    a1++;

  }
  while (((u16) a1) < 0x20);
  l11374:
  a1 = gSaveCmdResult;

  if (a1 != 2)
  {
    goto l11594;
  }
  idx = gSaveSlot;
  saveSubmitCommand(0xE, ENT(idx), idx, 0, 0, 0, 0, 0);
  if (saveWaitCommand() != 0)
  {
    goto l113ec;
  }
  l113d8:
  gSaveStatus = 0x63;

  return 0x63;
  l113ec:
  idx = gSaveSlot;

  saveSubmitCommand(0xC, ENT(idx), idx, 0, 0, 0, 0, 0);
  if (saveWaitCommand() != 0)
  {
    goto l11464;
  }
  l11434:
  {
    s32 entryIndex = gSaveSlot;
    gSaveStatus = 0x10;
    gSaveSlotValid[entryIndex] = 1;
    return 0x10;
  }

  l11464:
  idx = gSaveSlot;

  saveSubmitCommand(7, ENT(idx), idx, 0, 0, 0, 0, 0);
  saveWaitCommand();
  a1 = gSaveCmdResult;
  if (((a1 == 0) || (a1 == 0xB)) || (a1 == 0xA))
  {
    goto l114cc;
  }
  goto l1159c;
  l114cc:
  {
    s32 entryIndex = gSaveSlot;
    u8 *payloadBase = base + 12;
    D_80102D60 = 0;
    CP32(gSaveBackup, (entryIndex * 104) + payloadBase);
    gSaveStatus = 0x12;
    return 0x12;
  }

  l11594:
  a1 = *((volatile s32 *) (&gSaveCmdResult));

  l1159c:
  return (u16) func_80010B60(a1);

}

