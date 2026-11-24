s32 lookupAnimationRemap();
s32 matchObjectCode();
void *lookupRecordByType();
extern char D_800AE72C[];
extern char D_800AE74A[];
extern char D_800AE75A[];
extern s8 D_800AE760;
extern char D_800AE761[];
extern s16 D_800C2852;
extern u8 gPauseFlag;
extern s32 gBorderSkipActive;
extern s32 gBootState;
/* Remaps an animation id (0x1DF-0x1FA) and its parameter based on input code, boot/pause state and the actor's target. */
void remapAnimationId(s32 *ioAnimId, s32 *ioAnimParam, s32 inputCode, void *actor)
{
  char *__base_D_800AE74A;
  union 
  {
    unsigned char bytes[16];
    struct 
    {
      s32 value;
    } view_sp10;
    struct 
    {
      unsigned char pad[4];
      s32 value;
    } view_sp14;
    struct 
    {
      unsigned char pad[8];
      s32 value;
    } view_sp18;
    struct 
    {
      unsigned char pad[6];
      s16 value;
    } view_unksp16;
  } m2c_initial_frame;
  register unsigned int temp_a1;
  void *target;
  s32 var_a0;
  s32 var_v0;
  void *targetInfo;
  register u16 temp_v1;
  s32 temp_v0;
  temp_v0 = *ioAnimId;
  m2c_initial_frame.view_sp14.value = temp_v0;
  m2c_initial_frame.view_sp18.value = *ioAnimParam;
  m2c_initial_frame.view_sp10.value = -1;
  if (((u32) (temp_v0 - 0x1DF)) < 0x1CU)
  {
    if (gBorderSkipActive && (gPauseFlag == 0))
    {
      m2c_initial_frame.view_sp14.value = -1;
    }
    else
      if (matchObjectCode(m2c_initial_frame.view_unksp16.value, (s8) inputCode, &m2c_initial_frame.view_sp10.value) != 0)
    {
      if ((gBootState != 0) || (((gBorderSkipActive != 0) & (m2c_initial_frame.view_sp14.value != 0x1EE)) && (((u8) gPauseFlag) < 2U)))
      {
        m2c_initial_frame.view_sp14.value = -1;
      }
      if (1)
      {
      }
      if (m2c_initial_frame.view_sp14.value >= 0)
      {
        m2c_initial_frame.view_sp14.value = (s32) D_800C2852;
      }
    }
    else
      if (gBootState)
    {
      if (((((((m2c_initial_frame.view_sp14.value == 0x1F8) | (m2c_initial_frame.view_sp14.value == 0x1EA)) & (temp_a1 = inputCode == 0x27)) || ((m2c_initial_frame.view_sp14.value == 0x1E6) & (inputCode == 0x29))) || ((m2c_initial_frame.view_sp14.value == 0x1E7) & (inputCode == 0x27))) || ((m2c_initial_frame.view_sp14.value == 0x1F0) & (inputCode == 0x27))) || ((m2c_initial_frame.view_sp14.value == 0x1EB) & (inputCode == 0x27)))
      {
        m2c_initial_frame.view_sp14.value = -1;
      }
      goto check_actor;
      found:
      m2c_initial_frame.view_sp14.value = (s32) (*((s16 *) (D_800AE75A + ((*((u16 *) (((char *) targetInfo) + 6))) & 6))));

      m2c_initial_frame.view_sp18.value = (s32) (*(D_800AE761 + var_a0));
      goto done;
    }
    else
      if ((gBorderSkipActive != 0) && (((u8) gPauseFlag) < 3U))
    {
      lookupAnimationRemap(&m2c_initial_frame.view_sp14.value, &m2c_initial_frame.view_sp18.value);
    }
    check_actor:
    target = *((void **) (((char *) actor) + 0x18));

    if (((target != NULL) && (m2c_initial_frame.view_sp14.value >= 0)) && ((*((u16 *) (((char *) target) + 0x78))) == 2))
    {
      targetInfo = lookupRecordByType(*((u8 *) (((char *) (*((void **) (((char *) target) + 0x68)))) + 0xB1)));
      if (m2c_initial_frame.view_sp10.value >= 0)
      {
        temp_v1 = *((u16 *) (((char *) targetInfo) + 6));
        if (temp_v1 & 0x38)
        {
          s32 mapped = *((s16 *) (D_800AE72C + ((((temp_v1 >> 2) & 0xE) + m2c_initial_frame.view_sp10.value) * 2)));
          volatile u16 *flag_ptr = (u16 *) (((char *) targetInfo) + 6);
          u32 flags = (*flag_ptr) >> 2;
          m2c_initial_frame.view_sp14.value = mapped;
 do { __base_D_800AE74A = D_800AE74A; } while (0);
          m2c_initial_frame.view_sp18.value = *(((flags & 0xE) + __base_D_800AE74A) + m2c_initial_frame.view_sp10.value);
        }
      }
      if ((*((u16 *) (((char *) targetInfo) + 6))) & 6)
      {
        var_a0 = 0;
        if (D_800AE760 >= 0)
        {
          __base_D_800AE74A = &D_800AE760;
          var_v0 = *__base_D_800AE74A;
          loop_31:
          __base_D_800AE74A += 2;

          if (var_v0 != inputCode)
          {
            var_v0 = *((s8 *) __base_D_800AE74A);
            var_a0 += 2;
            if (var_v0 >= 0)
            {
              goto loop_31;
            }
          }
          else
          {
            goto found;
          }
        }
      }
    }
  }
  done:
  *ioAnimId = m2c_initial_frame.view_sp14.value;

  *ioAnimParam = m2c_initial_frame.view_sp18.value;
}
