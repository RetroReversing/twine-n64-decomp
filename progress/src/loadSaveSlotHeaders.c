typedef struct { u16 used; char name[17]; char code[5]; } SaveName;
typedef struct { s32 clear; s32 magic; u16 magic2; s8 codeByte; char codeRest[3]; char name[16]; char pad[2]; } SaveRaw;
extern u16 saveRefreshStatus(void);
extern void saveSubmitCommand(u16, s32, s32, s32, s32, s32, s32, s32);
extern s32 saveWaitCommand(void);
extern s32 getSaveErrorStatus(s32);
extern void decodeTextField(char *, char *, s32);
extern void saveDataEncodeName(char *, char *, s32);
extern s32 stringCompare(char *, char *);
extern char D_800E096C[];
extern char D_800E0970[];
extern char gPackedValue[];
extern char gSaveFileName[];
extern char D_80115308[];
extern char gSaveSlotCodeBuf[];
extern char gSaveSlotCodeByte[];
extern char gRumblePaks[];
extern SaveName gSaveSlotHeaders[];
extern SaveRaw gSaveRawSlots[];
extern u16 gSkipSaveNameCheck;
extern u16 gSaveStatus;
extern s16 gSaveSlot;
extern s16 gSaveFoundSlot;
extern s32 gSaveCmdResult;
/* Reads all 16 save-slot headers from the save device, decodes names/codes, and picks a unique code byte for the current name. */ u16 loadSaveSlotHeaders(s32 arg0)
{
  s32 slot;
  s32 idx;
  u16 unique;
  char *np;
  char *cp;
  gSaveSlot = 0;
  gSaveFoundSlot = -1;
  if (saveRefreshStatus())
  {
    return gSaveStatus;
  }
  saveSubmitCommand(7, (s32) (gRumblePaks + (gSaveSlot * 104)), gSaveSlot, 0, 0, 0, 0, 0);
  if (saveWaitCommand())
  {
    return getSaveErrorStatus(gSaveCmdResult);
  }
  saveSubmitCommand(3, (s32) (gRumblePaks + (gSaveSlot * 104)), (s32) D_800E096C, (s32) D_800E0970, 0, 0, 0, 0);
  if (saveWaitCommand())
  {
    return getSaveErrorStatus(gSaveCmdResult);
  }
  saveSubmitCommand(4, (s32) (gRumblePaks + (gSaveSlot * 104)), (s32) gPackedValue, 0, 0, 0, 0, 0);
  if (saveWaitCommand())
  {
    return getSaveErrorStatus(gSaveCmdResult);
  }
  slot = 0;
  do
  {
    saveSubmitCommand(5, (s32) (gRumblePaks + (gSaveSlot * 104)), slot, (s32) &gSaveRawSlots[slot], 0, 0, 0, 0);
    if (saveWaitCommand() == 5)
    {
      gSaveSlotHeaders[slot].used = 0;
      idx = 15;
      do { gSaveSlotHeaders[slot].name[idx] = ' '; } while (--idx >= 0);
      np = gSaveSlotHeaders[slot].name;
      np[16] = 0;
      idx = 3;
      do { gSaveSlotHeaders[slot].code[idx] = ' '; } while (--idx >= 0);
      cp = gSaveSlotHeaders[slot].code;
      cp[4] = 0;
      gSaveRawSlots[slot].clear = 0;
      gSaveCmdResult = 0;
    }
    else
    {
      if (gSaveCmdResult)
      {
        return getSaveErrorStatus(gSaveCmdResult);
      }
      gSaveSlotHeaders[slot].used = 1;
      decodeTextField(gSaveSlotHeaders[slot].name, gSaveRawSlots[slot].name, 16);
      decodeTextField(gSaveSlotHeaders[slot].code, &gSaveRawSlots[slot].codeByte, 4);
    }
    slot++;
  }
  while (slot < 16);
  if (gSkipSaveNameCheck)
  {
    gSaveSlotCodeBuf[0] = 'A';
    saveDataEncodeName(D_80115308, gSaveFileName, 16);
    saveDataEncodeName(gSaveSlotCodeByte, gSaveSlotCodeBuf, 4);
    do
    {
      unique = 1;
      for (idx = 0; idx < 16; idx++)
      {
        if (gSaveSlotHeaders[idx].used && gSaveRawSlots[idx].magic == 0x4e4f3745 && gSaveRawSlots[idx].magic2 == 0x3639 && stringCompare(gSaveSlotHeaders[idx].name, D_80115308))
        {
          if (gSaveRawSlots[idx].codeByte == *(s8 *) gSaveSlotCodeByte)
          {
            unique = 0;
            *gSaveSlotCodeByte = gSaveRawSlots[idx].codeByte + 1;
            break;
          }
          gSaveFoundSlot = idx;
        }
      }
    }
    while (!unique);
    decodeTextField(gSaveSlotCodeBuf, gSaveSlotCodeByte, 4);
  }
  gSaveStatus = 0;
  return 0;
}
