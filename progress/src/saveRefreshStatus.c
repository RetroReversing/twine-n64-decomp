#define ENTB(t, i) ((i) * 104 + (t))
#define CP32(d, s) __builtin_memcpy((d), (s), 32)
extern s16 gSaveSlot;
extern u8 gRumblePaks[];
extern u8 gSaveHeaderCopy[];
extern u32 gSaveBackup[];
extern s16 gSaveStatus;
extern volatile s32 gSaveCmdResult;
extern u8 D_80102D60;
extern s16 gSaveSlotValid[];
extern s32 saveSubmitCommand(s32, void *, s32, s32, s32, s32, s32, s32);
extern s32 saveWaitCommand(void);
extern s32 getSaveErrorStatus(s32);
typedef struct 
{
  u32 v;
} __attribute__((packed)) UW;
/* Re-queries the current controller pak slot and updates gSaveStatus from the result (retrying read, repair and header backup steps); returns the new status. */ u16 saveRefreshStatus(void)
{
  s32 idx;
  u8 *b0;
  u8 *b1;
  u8 *b2;
  u8 *b3;
  s32 st;
  u16 a1;
  s32 r4;
  s32 r1;
  s32 r2;
  s32 r3;
  u8 flag;
  b0 = gRumblePaks;
  saveSubmitCommand(7, ENTB(b0, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
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
    saveSubmitCommand(0xC, ENTB(b0, 0), 0, 0, 0, 0, 0, 0);
    if (saveWaitCommand() == 0) { goto l11434; }
    saveSubmitCommand(0xE, ENTB(b0, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
    if (saveWaitCommand() == 0) { goto l113d8; }
    {
    u32 *backup = gSaveBackup;
    u8 *payload = (b0) + 12;
    s32 copyIdx = gSaveSlot;
    CP32(backup, payload + (copyIdx * 104));
    saveSubmitCommand(7, ENTB(b0, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
    if (saveWaitCommand() != 0) { goto fa4; }
    D_80102D60 = 0;
    CP32(backup, payload + (gSaveSlot * 104));
    }
    goto fa4;
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
    b1 = gRumblePaks;
    saveSubmitCommand(0xC, ENTB(b1, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
    if (saveWaitCommand() == 0) { goto l11434; }
    saveSubmitCommand(0xE, ENTB(b1, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
    if (saveWaitCommand() == 0) { goto l113d8; }
    {
    u32 *backup = gSaveBackup;
    u8 *payload = (b1) + 12;
    s32 copyIdx = gSaveSlot;
    CP32(backup, payload + (copyIdx * 104));
    saveSubmitCommand(7, ENTB(b1, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
    if (saveWaitCommand() != 0) { goto fa4; }
    D_80102D60 = 0;
    CP32(backup, payload + (gSaveSlot * 104));
    }
    goto fa4;
  }

  fa4:
  gSaveStatus = 0x12;

  return 0x12;
  fb4:
  r1 = gSaveCmdResult;

  if (r1 == 0xB)
  {
    gSaveStatus = 0x62;
    return 0x62;
  }
  if (r1 != 2)
  {
    goto d110e4;
  }
  b2 = gRumblePaks;
  saveSubmitCommand(0xE, ENTB(b2, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
  if (saveWaitCommand() == 0)
  {
    goto l113d8;
  }
  saveSubmitCommand(0xC, ENTB(b2, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
  if (saveWaitCommand() == 0)
  {
    goto l11434;
  }
  saveSubmitCommand(7, ENTB(b2, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
  saveWaitCommand();
  r2 = gSaveCmdResult;
  if (((r2 == 0) || (r2 == 0xB)) || (r2 == 0xA))
  {
    {
    s32 entryIndex = gSaveSlot;
    u8 *payloadBase = (b2) + 12;
    D_80102D60 = 0;
    CP32(gSaveBackup, (entryIndex * 104) + payloadBase);
    gSaveStatus = 0x12;
    return 0x12;
    }
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
    u8 *payload;
    s32 i16 = a1;
    payload = gSaveHeaderCopy + (gSaveSlot * 104);
    if (((u8 *) gSaveBackup)[i16] == payload[i16])
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
  while (a1 < 0x20);
  l11374:
  r3 = gSaveCmdResult;

  if (r3 != 2)
  {
    goto l11594;
  }
  b3 = gRumblePaks;
  saveSubmitCommand(0xE, ENTB(b3, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
  if (saveWaitCommand() != 0)
  {
    goto l113ec;
  }
  l113d8:
  gSaveStatus = 0x63;

  return 0x63;
  l113ec:

  saveSubmitCommand(0xC, ENTB(b3, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
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

  saveSubmitCommand(7, ENTB(b3, gSaveSlot), gSaveSlot, 0, 0, 0, 0, 0);
  saveWaitCommand();
  r4 = gSaveCmdResult;
  if (((r4 == 0) || (r4 == 0xB)) || (r4 == 0xA))
  {
    {
    s32 entryIndex = gSaveSlot;
    u8 *payloadBase = (b3) + 12;
    D_80102D60 = 0;
    CP32(gSaveBackup, (entryIndex * 104) + payloadBase);
    gSaveStatus = 0x12;
    return 0x12;
    }
  }
  goto l1159c;

  l11594:
  r4 = gSaveCmdResult;

  l1159c:
  return (u16) getSaveErrorStatus(r4);

}

