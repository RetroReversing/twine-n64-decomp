s32 findEntryPayload(s32, s32);
s32 formatTextEntry(s32, s32 *, s8 *);
s32 isMenuButtonPressed(s32);
s32 pulseObjectValue(s32);
s32 copyString(s32 *, s8 *);
s32 findSubstring(s32 *, u8 *, s32);
s32 func_800AB9B0(s32 *);
s32 layoutTextBox(s32, void *, s32);
void *lookupDataEntry(s32);
s32 menuItemIsActive(s32);
s32 menuResolveCursorItem(void *, void *, void *);
s32 requestSound(s32);
s32 sprintf(s8 *, const s8 *, ...);
u32 strlen(const s8 *);
extern const s8 D_800D285C[];
extern u16 gNameEntryLength;
extern void *gNameEntryState;
extern u8 gPickupSavedByte;
extern void *gSaveMenuState;
extern s32 sFmtEntryName;
extern void updateActorPartnerLink(void);
/* Per-frame update of the name entry screen: handles key presses on the on-screen keyboard (append, delete, confirm), cursor movement and lays out the text box. */ void updateNameEntryScreen(void)
{
  u8 *__repair_byte_buffer;
  u8 *t2;
  u32 matcher[4];
  u8 candidateBytes[12];
  s32 temp_v0;
  s32 temp_v1;
  s32 var_a2;
  s8 *defaultName;
  s8 *nameBuffer;
  s8 *var_a1;
  s8 *candidate;
  u16 var_v0;
  u8 *temp_v1_3;
  u8 temp_v0_2;
  u8 temp_v1_2;
  u8 var_v1;
  void *keyGrid;
  void *cursorKey;
  void *temp_s0_2;
  void *var_a2_2;
  volatile u8 *slot;
  s8 *out;
  const s8 *fmt;
  if (gNameEntryState != NULL)
  {
    keyGrid = *((void **) (((char *) gNameEntryState) + 0));
    cursorKey = *((void **) (((char *) gNameEntryState) + 4));
    nameBuffer = *((s8 **) (((char *) (*((void **) (((char *) keyGrid) + 8)))) + 0x18));
    defaultName = (((s8 *) (&gPickupSavedByte)) - 0x109) + ((*((volatile u8 *) (&gPickupSavedByte))) * 0x18);
    if (cursorKey == keyGrid)
    {
      *((void **) (((char *) gNameEntryState) + 4)) = (void *) (cursorKey + 0x28);
      sprintf(nameBuffer, defaultName, gNameEntryState, cursorKey);
      gNameEntryLength = strlen(nameBuffer);
    }
    menuResolveCursorItem(gSaveMenuState + 0x2A, gSaveMenuState + 0x28, gSaveMenuState + 0x29);
    pulseObjectValue(*((s32 *) (((char *) gNameEntryState) + 8)));
    if (isMenuButtonPressed(0x24) & 0xFF)
    {
      *((s8 *) (((char *) gNameEntryState) + 0xD)) = 0;
      sprintf(nameBuffer, defaultName);
      goto block_40;
    }
    if (isMenuButtonPressed(0x2A) & 0xFF)
    {
      requestSound(0xE8);
      temp_v1 = *((s32 *) (((char *) (*((void **) (((char *) gNameEntryState) + 4)))) + 0x14));
      if (temp_v1 == 0x7D0)
      {
        sprintf(defaultName, nameBuffer);
        goto block_40;
      }
      else
      {
        if (temp_v1 == 0x3E8)
        {
          if (gNameEntryLength == 0)
          {
            requestSound(0xEA);
          }
          else
          {
            var_v0 = gNameEntryLength - 1;
            goto block_12;
          }
        }
        else
        {
          nameBuffer[gNameEntryLength] = (s8) temp_v1;
          var_v0 = gNameEntryLength + 1;
          block_12:
          gNameEntryLength = var_v0;

        }
        if (gNameEntryLength == 9)
        {
          requestSound(0xEA);
          gNameEntryLength -= 1;
        }
        nameBuffer[gNameEntryLength] = 0;
        goto block_16;
      }
    }
    else
    {
      block_16:
      if ((menuItemIsActive(0x20) & 0xFF) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
      {
        requestSound(0xED);
        *((void **) (((char *) gNameEntryState) + 4)) = (void *) ((*((void **) (((char *) gNameEntryState) + 0))) + ((*((s8 *) (((char *) (*((void **) (((char *) gNameEntryState) + 4)))) + 0x24))) * 0x28));
      }

      if ((menuItemIsActive(0x21) & 0xFF) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
      {
        requestSound(0xED);
        *((void **) (((char *) gNameEntryState) + 4)) = (void *) ((*((void **) (((char *) gNameEntryState) + 0))) + ((*((s8 *) (((char *) (*((void **) (((char *) gNameEntryState) + 4)))) + 0x25))) * 0x28));
      }
      if ((menuItemIsActive(0x1E) & 0xFF) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
      {
        requestSound(0xED);
        *((void **) (((char *) gNameEntryState) + 4)) = (void *) ((*((void **) (((char *) gNameEntryState) + 0))) + ((*((s8 *) (((char *) (*((void **) (((char *) gNameEntryState) + 4)))) + 0x26))) * 0x28));
      }
      if ((menuItemIsActive(0x1F) & 0xFF) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
      {
        requestSound(0xED);
        *((void **) (((char *) gNameEntryState) + 4)) = (void *) ((*((void **) (((char *) gNameEntryState) + 0))) + ((*((s8 *) (((char *) (*((void **) (((char *) gNameEntryState) + 4)))) + 0x27))) * 0x28));
      }
      candidate = ((s8 *) updateActorPartnerLink) + 0x6C;
      layoutTextBox(*((s32 *) (((char *) gNameEntryState) + 8)), *((void **) (((char *) gNameEntryState) + 4)), 0);
      copyString(matcher, nameBuffer);
      func_800AB9B0(matcher);
      var_v1 = (u8) (*((s8 *) (((char *) updateActorPartnerLink) + 0x6C)));
      var_a2 = 0;
      if ((*((s8 *) (((char *) updateActorPartnerLink) + 0x6C))) != 0)
      {
        slot = &gPickupSavedByte;
        loop_30:
        __repair_byte_buffer = candidateBytes;

        if (gNameEntryState)
        {
          candidateBytes[0] = var_v1;
        }
        else
        {
          candidateBytes[0] = var_v1;
        }
        if (var_v1 != 0)
        {
          var_a1 = candidate;
          do
{
do { temp_v1_3 = __repair_byte_buffer + var_a2; } while (0);
temp_v0_2 = *temp_v1_3;
var_a1 += 1;
var_a2 += 1;
do { *temp_v1_3 = temp_v0_2 - 1; } while (0);
temp_v1_2 = *var_a1;
do { do { t2 = __repair_byte_buffer; } while (0); } while (0);
if (candidate) { t2 += var_a2; } else { t2 += var_a2; }
*t2 = temp_v1_2;
}
while (temp_v1_2 != 0);
        }
        if (findSubstring(matcher, candidateBytes, var_a2) != 0)
        {
          if ((*slot) < 4U)
          {
            var_a2_2 = lookupDataEntry(0xAD);
            out = nameBuffer;
            fmt = D_800D285C;
            sprintf(out, fmt, var_a2_2, (*slot) + 1);
          }
          else
          {
            var_a2_2 = lookupDataEntry(0x158);
            out = nameBuffer;
            fmt = D_800D285C;
            sprintf(out, fmt, var_a2_2, (*slot) - 3);
          }
          gNameEntryLength = strlen(nameBuffer);
        }
        else
        {
          candidate += strlen(candidate) + 1;
          var_v1 = (u8) (*candidate);
          var_a2 = 0;
          if ((*candidate) != 0)
          {
            goto loop_30;
          }
        }
      }
      temp_s0_2 = *((void **) (((char *) (*((void **) (((char *) gNameEntryState) + 0)))) + 8));
      *((u16 *) (((char *) temp_s0_2) + 0x1C)) = strlen(nameBuffer);
    }
    return;
    block_40:
    temp_v0 = findEntryPayload(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x65);

    if (temp_v0 != 0)
    {
      formatTextEntry(temp_v0, &sFmtEntryName, nameBuffer);
    }
    *((s8 *) (((char *) gNameEntryState) + 0xF)) = 1;
    requestSound(0xE8);
  }
}


