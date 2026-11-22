extern u16 saveRefreshStatus(void);
extern void saveSubmitCommand(u16, s32, s32, s32, s32, s32, s32, s32);
extern s32 saveWaitCommand(void);
extern s32 func_80010B60(s32);
extern void decodeTextField(char *, char *, s32);
extern void saveDataEncodeName(char *, char *, s32);
extern s32 stringCompare(char *, char *);
extern char D_800E096C[];
extern char D_800E0970[];
extern char D_800E0974[];
extern char D_80103030[];
extern char D_80107B6A[];
extern char D_80108408[];
extern char D_8010840C[];
extern char D_80108410[];
extern char D_80115308[];
extern char gSaveSlotCodeBuf[];
extern char gSaveSlotCodeByte[];
extern char gSaveSlotCodes[];
extern char gSaveSlotHeaders[];
extern char gSaveSlotTable[];
extern u16 D_800E097C;
extern u16 gSaveStatus;
extern s16 gSaveSlot;
extern s16 gSaveFoundSlot;
extern s32 gSaveCmdResult;
u16 func_80012F50(void)
{
  char frame[8];
  char *table;
  char *name;
  char *code;
  char *raw;
  char *rawCode;
  char *p;
  char *baseName;
  char *encoded;
  char *buf;
  u16 *used;
  s32 slot;
  s32 i;
  s32 rawOffset;
  s32 headerOffset;
  s32 j;
  s32 value;
  s32 result;
  u16 done;
  s32 scan;
  s32 scanOffset;
  char *scanName;
  gSaveSlot = 0;
  gSaveFoundSlot = -1;
  if (saveRefreshStatus())
  {
    return gSaveStatus;
  }
  table = gSaveSlotTable;
  slot = gSaveSlot;
  saveSubmitCommand(7, (s32) (table + (slot * 104)), slot, 0, 0, 0, 0, 0);
  if (saveWaitCommand())
  {
    goto commandError;
  }
  saveSubmitCommand(3, (s32) (table + (gSaveSlot * 104)), (s32) D_800E096C, (s32) D_800E0970, 0, 0, 0, 0);
  if (saveWaitCommand())
  {
    goto commandError;
  }
  saveSubmitCommand(4, (s32) (table + (gSaveSlot * 104)), (s32) D_800E0974, 0, 0, 0, 0, 0);
  if (saveWaitCommand() == 0)
  {
    do
    {
      goto readSlots;
    }
    while (0);
  }
  commandError:
  result = gSaveCmdResult;

  mapError:
  return func_80010B60(result);

  readSlots:
  raw = D_80108408;

  rawCode = raw + 10;
  name = (u32) D_80107B6A;
  code = name + 17;
  used = (u16 *) (name - 2);
  i = 0;
  rawOffset = 0;
  do
  {
    saveSubmitCommand(5, (s32) (gSaveSlotTable + (gSaveSlot * 104)), i, (s32) raw, 0, 0, 0, 0);
    if (saveWaitCommand() == 5)
    {
      j = 15;
      *used = 0;
      p = name + 15;
      do
      {
        *p = ' ';
        --j;
        --p;
      }
      while (j >= 0);
      {
        name[16] = 0; j = 3; p = code + 3;
        do
        {
          *p = ' ';
          --j;
          --p;
        }
        while (j >= 0);
        code[4] = 0;
        *((s32 *) (D_80108408 + rawOffset)) = 0;
      }
      gSaveCmdResult = 0;
    }
    else
    {
      result = gSaveCmdResult;
      if (result)
      {
        goto mapError;
      }
      *used = 1;
      decodeTextField(name, ((char *) (((s32) D_80108408) + 14)) + rawOffset, 16);
      do
      {
        decodeTextField(code, rawCode, 4);
      }
      while (0);
    }
    rawCode += 32;
    name += 24;
    code += 24;
    used += 12;
    rawOffset += 32;
    raw += 32;
    do
    {/*__repair_loop_weight*/do {
      ++i;} while (0);
    }
    while (0);
  }
  while (i < 16);
  if (D_800E097C)
  {
    buf = gSaveSlotCodeBuf;
    *buf = 'A';
    saveDataEncodeName(D_80115308, D_80103030, 16);
    encoded = gSaveSlotCodeByte;
    saveDataEncodeName(gSaveSlotCodeByte, buf, 4);
    baseName = D_80107B6A;
    do
    {
      done = 1;
      scanOffset = 0;
      scanName = baseName;
      scan = 0;
      headerOffset = 0;
      do
      {
        if ((((*((u16 *) (gSaveSlotHeaders + headerOffset))) && ((*((u32 *) (D_8010840C + scanOffset))) == 0x4e4f3745)) && ((*((u16 *) (D_80108410 + scanOffset))) == 0x3639)) && stringCompare(scanName, D_80115308))
        {
          value = *((s8 *) (gSaveSlotCodes + scanOffset));
          do
          {
 do { if (value == (*((s8 *) gSaveSlotCodeByte))) { done = 0; *gSaveSlotCodeByte = value + 1; break; } gSaveFoundSlot = scan; } while (0);
          }
          while (0);
        }
        scanName += 24;
        scanOffset += 32;
        ++scan;
        headerOffset += 24;
      }
      while (scan < 16);
    }
    while (!done);
    decodeTextField(gSaveSlotCodeBuf, gSaveSlotCodeByte, 4);
  }
  gSaveStatus = 0;
  return 0;
}
