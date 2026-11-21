s32 findEntryPayload(s32, s32);
s32 formatTextEntry(s32, s32 *, s8 *);
s32 func_80027C60(s32);
s32 func_80029000(s32);
s32 func_800AB880(s32 *, s8 *);
s32 func_800AB950(s32 *, u8 *, s32);
s32 func_800AB9B0(s32 *);
s32 layoutTextBox(s32, void *, s32);
void *lookupDataEntry(s32);
s32 menuItemIsActive(s32);
s32 menuResolveCursorItem(void *, void *, void *);
s32 requestSound(s32);
s32 sprintf(s8 *, const s8 *, ...);
u32 strlen(const s8 *);
extern const s8 D_800D285C[];
extern u16 D_800B60A4;
extern void *D_800BF5A0;
extern u8 gPickupSavedByte;
extern void *gSaveMenuState;
extern s32 sFmtEntryName;
extern void updateActorPartnerLink(void);
void func_80018E38(void)
{
  u8 *__repair_byte_buffer;
  u32 sp10[4];
  u8 sp20[12];
  s32 temp_v0;
  s32 temp_v1;
  s32 var_a2;
  s8 *temp_s0;
  s8 *temp_s1;
  s8 *var_a1;
  s8 *var_s0;
  u16 var_v0;
  u8 *temp_v1_3;
  u8 temp_v0_2;
  u8 temp_v1_2;
  u8 var_v1;
  void *temp_a1;
  void *temp_a3;
  void *temp_s0_2;
  void *var_a2_2;
  volatile u8 *slot;
  s8 *out;
  const s8 *fmt;
  if (D_800BF5A0 != NULL)
  {
    temp_a1 = *((void **) (((char *) D_800BF5A0) + 0));
    temp_a3 = *((void **) (((char *) D_800BF5A0) + 4));
    temp_s1 = *((s8 **) (((char *) (*((void **) (((char *) temp_a1) + 8)))) + 0x18));
    temp_s0 = (((s8 *) (&gPickupSavedByte)) - 0x109) + ((*((volatile u8 *) (&gPickupSavedByte))) * 0x18);
    if (temp_a3 == temp_a1)
    {
      *((void **) (((char *) D_800BF5A0) + 4)) = (void *) (temp_a3 + 0x28);
      sprintf(temp_s1, temp_s0, D_800BF5A0, temp_a3);
      D_800B60A4 = strlen(temp_s1);
    }
    menuResolveCursorItem(gSaveMenuState + 0x2A, gSaveMenuState + 0x28, gSaveMenuState + 0x29);
    func_80029000(*((s32 *) (((char *) D_800BF5A0) + 8)));
    if (func_80027C60(0x24) & 0xFF)
    {
      *((s8 *) (((char *) D_800BF5A0) + 0xD)) = 0;
      sprintf(temp_s1, temp_s0);
      goto block_40;
    }
    if (func_80027C60(0x2A) & 0xFF)
    {
      requestSound(0xE8);
      temp_v1 = *((s32 *) (((char *) (*((void **) (((char *) D_800BF5A0) + 4)))) + 0x14));
      if (temp_v1 == 0x7D0)
      {
        sprintf(temp_s0, temp_s1);
        goto block_40;
      }
      else
      {
        if (temp_v1 == 0x3E8)
        {
          var_v0 = D_800B60A4 - 1;
          if (D_800B60A4 == 0)
          {
            requestSound(0xEA);
          }
          else
          {
            goto block_12;
          }
        }
        else
        {
          temp_s1[D_800B60A4] = (s8) temp_v1;
          var_v0 = D_800B60A4 + 1;
          block_12:
          D_800B60A4 = var_v0;

        }
        if (D_800B60A4 == 9)
        {
          requestSound(0xEA);
          D_800B60A4 -= 1;
        }
        temp_s1[D_800B60A4] = 0;
        goto block_16;
      }
    }
    else
    {
      block_16:
      if ((menuItemIsActive(0x20) & 0xFF) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
      {
        requestSound(0xED);
        *((void **) (((char *) D_800BF5A0) + 4)) = (void *) ((*((void **) (((char *) D_800BF5A0) + 0))) + ((*((s8 *) (((char *) (*((void **) (((char *) D_800BF5A0) + 4)))) + 0x24))) * 0x28));
      }

      if ((menuItemIsActive(0x21) & 0xFF) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
      {
        requestSound(0xED);
        *((void **) (((char *) D_800BF5A0) + 4)) = (void *) ((*((void **) (((char *) D_800BF5A0) + 0))) + ((*((s8 *) (((char *) (*((void **) (((char *) D_800BF5A0) + 4)))) + 0x25))) * 0x28));
      }
      if ((menuItemIsActive(0x1E) & 0xFF) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
      {
        requestSound(0xED);
        *((void **) (((char *) D_800BF5A0) + 4)) = (void *) ((*((void **) (((char *) D_800BF5A0) + 0))) + ((*((s8 *) (((char *) (*((void **) (((char *) D_800BF5A0) + 4)))) + 0x26))) * 0x28));
      }
      if ((menuItemIsActive(0x1F) & 0xFF) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
      {
        requestSound(0xED);
        *((void **) (((char *) D_800BF5A0) + 4)) = (void *) ((*((void **) (((char *) D_800BF5A0) + 0))) + ((*((s8 *) (((char *) (*((void **) (((char *) D_800BF5A0) + 4)))) + 0x27))) * 0x28));
      }
      var_s0 = ((s8 *) updateActorPartnerLink) + 0x6C;
      layoutTextBox(*((s32 *) (((char *) D_800BF5A0) + 8)), *((void **) (((char *) D_800BF5A0) + 4)), 0);
      func_800AB880(sp10, temp_s1);
      func_800AB9B0(sp10);
      var_v1 = (u8) (*((s8 *) (((char *) updateActorPartnerLink) + 0x6C)));
      var_a2 = 0;
      if ((*((s8 *) (((char *) updateActorPartnerLink) + 0x6C))) != 0)
      {
        slot = &gPickupSavedByte;
        loop_30:
        __repair_byte_buffer = sp20;

        sp20[0] = var_v1;
        if (var_v1 != 0)
        {
          var_a1 = var_s0;
          do
          {
            temp_v1_3 = __repair_byte_buffer + var_a2;
            temp_v0_2 = *temp_v1_3;
            var_a1 += 1;
            var_a2 += 1;
 do { *temp_v1_3 = temp_v0_2 - 1; temp_v1_2 = *var_a1; } while (0);
            __repair_byte_buffer[var_a2] = temp_v1_2;
          }
          while (temp_v1_2 != 0);
        }
        if (func_800AB950(sp10, sp20, var_a2) != 0)
        {
          if ((*slot) < 4U)
          {
            var_a2_2 = lookupDataEntry(0xAD);
            out = temp_s1;
            fmt = D_800D285C;
            sprintf(out, fmt, var_a2_2, (*slot) + 1);
          }
          else
          {
            var_a2_2 = lookupDataEntry(0x158);
            out = temp_s1;
            fmt = D_800D285C;
            sprintf(out, fmt, var_a2_2, (*slot) - 3);
          }
          D_800B60A4 = strlen(temp_s1);
        }
        else
        {
          var_s0 += strlen(var_s0) + 1;
          var_v1 = (u8) (*var_s0);
          var_a2 = 0;
          if ((*var_s0) != 0)
          {
            goto loop_30;
          }
        }
      }
      temp_s0_2 = *((void **) (((char *) (*((void **) (((char *) D_800BF5A0) + 0)))) + 8));
      *((u16 *) (((char *) temp_s0_2) + 0x1C)) = strlen(temp_s1);
    }
    return;
    block_40:
    temp_v0 = findEntryPayload(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x65);

    if (temp_v0 != 0)
    {
      formatTextEntry(temp_v0, &sFmtEntryName, temp_s1);
    }
    *((s8 *) (((char *) D_800BF5A0) + 0xF)) = 1;
    requestSound(0xE8);
  }
}
