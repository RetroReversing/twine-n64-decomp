typedef struct { u16 used; char name[17]; char code[5]; } SaveName;
typedef struct { s32 clear; s32 magic; u16 magic2; s8 codeByte; char codeRest[3]; char name[16]; char pad[2]; } SaveRaw;
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
extern char D_80115308[];
extern char gSaveSlotCodeBuf[];
extern char gSaveSlotCodeByte[];
extern char gSaveSlotTable[];
extern SaveName gSaveSlotHeaders[];
extern SaveRaw D_80108408[];
extern u16 D_800E097C;
extern u16 gSaveStatus;
extern s16 gSaveSlot;
extern s16 gSaveFoundSlot;
extern s32 gSaveCmdResult;
u16 func_80012F50(void)
{
  s32 i;
  s32 j;
  u16 done;
  char *np;
  char *cp;
  gSaveSlot = 0;
  gSaveFoundSlot = -1;
  if (saveRefreshStatus())
  {
    return gSaveStatus;
  }
  saveSubmitCommand(7, (s32) (gSaveSlotTable + (gSaveSlot * 104)), gSaveSlot, 0, 0, 0, 0, 0);
  if (saveWaitCommand())
  {
    return func_80010B60(gSaveCmdResult);
  }
  saveSubmitCommand(3, (s32) (gSaveSlotTable + (gSaveSlot * 104)), (s32) D_800E096C, (s32) D_800E0970, 0, 0, 0, 0);
  if (saveWaitCommand())
  {
    return func_80010B60(gSaveCmdResult);
  }
  saveSubmitCommand(4, (s32) (gSaveSlotTable + (gSaveSlot * 104)), (s32) D_800E0974, 0, 0, 0, 0, 0);
  if (saveWaitCommand())
  {
    return func_80010B60(gSaveCmdResult);
  }
  i = 0;
  do
  {
    saveSubmitCommand(5, (s32) (gSaveSlotTable + (gSaveSlot * 104)), i, (s32) &D_80108408[i], 0, 0, 0, 0);
    if (saveWaitCommand() == 5)
    {
      gSaveSlotHeaders[i].used = 0;
      j = 15;
      do { gSaveSlotHeaders[i].name[j] = ' '; } while (--j >= 0);
      np = gSaveSlotHeaders[i].name;
      np[16] = 0;
      j = 3;
      do { gSaveSlotHeaders[i].code[j] = ' '; } while (--j >= 0);
      cp = gSaveSlotHeaders[i].code;
      cp[4] = 0;
      D_80108408[i].clear = 0;
      gSaveCmdResult = 0;
    }
    else
    {
      if (gSaveCmdResult)
      {
        return func_80010B60(gSaveCmdResult);
      }
      gSaveSlotHeaders[i].used = 1;
      decodeTextField(gSaveSlotHeaders[i].name, D_80108408[i].name, 16);
      decodeTextField(gSaveSlotHeaders[i].code, &D_80108408[i].codeByte, 4);
    }
    i++;
  }
  while (i < 16);
  if (D_800E097C)
  {
    gSaveSlotCodeBuf[0] = 'A';
    saveDataEncodeName(D_80115308, D_80103030, 16);
    saveDataEncodeName(gSaveSlotCodeByte, gSaveSlotCodeBuf, 4);
    do
    {
      done = 1;
      for (j = 0; j < 16; j++)
      {
        if (gSaveSlotHeaders[j].used && D_80108408[j].magic == 0x4e4f3745 && D_80108408[j].magic2 == 0x3639 && stringCompare(gSaveSlotHeaders[j].name, D_80115308))
        {
          if (D_80108408[j].codeByte == *(s8 *) gSaveSlotCodeByte)
          {
            done = 0;
            *gSaveSlotCodeByte = D_80108408[j].codeByte + 1;
            break;
          }
          gSaveFoundSlot = j;
        }
      }
    }
    while (!done);
    decodeTextField(gSaveSlotCodeBuf, gSaveSlotCodeByte, 4);
  }
  gSaveStatus = 0;
  return 0;
}
