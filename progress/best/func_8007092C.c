s32 requestSound();
s32 func_80063D38();
s32 func_80084338();
typedef struct 
{
  u16 f0;
  u8 pad[230];
} Slot_800C469C;
extern Slot_800C469C sEnemyDefTable[];
typedef struct 
{
  u16 f0;
  u8 pad[230];
} Slot_800C469E;
extern Slot_800C469E D_800C469E[];
void func_8007092C(void *arg0, s8 arg1)
{
  register s8 var_s6 = 0;
  volatile u32 pad[4];
  s32 savedIndex;
  s32 temp_a1;
  s8 temp_a1_2;
  u8 temp_v0;
  u8 *temp_a2;
  u8 *temp_s2;
  u8 *temp_s4;
  u8 *temp_v1_2;
  u8 *temp_v1_3;
  u8 *temp_v1_4;
  u8 *temp_v1_5;
  temp_s4 = *((u8 **) (((u8 *) arg0) + 0x6C));
  switch (*((s16 *) ((*((u8 **) (temp_s4 + 0xA8))) + 0x7A)))
  {
    default:

    case 0:

    case 2:

    case 4:

    case 8:
      if ((*((u16 *) (((u8 *) arg0) + 0x78))) == 3)
    {
      if (temp_a2)
      {
        func_80084338(0x118, ((u8 *) arg0) + 0x24);
      }
      else
      {
        func_80084338(0x118, ((u8 *) arg0) + 0x24);
      }
    }
    else
    {
      requestSound(0x118);
    }
      temp_v1_2 = *((u8 **) (((u8 *) arg0) + 0x68));
      temp_v1_2[0x10] = temp_v1_2[0xE];
      temp_v1_3 = *((u8 **) (((u8 *) arg0) + 0x68));
      temp_v1_3[0xF] = temp_v1_3[0xE];
      temp_v1_4 = *((u8 **) (((u8 *) arg0) + 0x68));
      if (((s8) temp_v1_4[0xF]) >= 0x27)
    {
      temp_v1_4[0xF] = *((u16 *) (temp_s4 + 0x134));
      return;
    }
      for (;;)
    {
      temp_v1_5 = *((u8 **) (((u8 *) arg0) + 0x68));
      temp_v0 = temp_v1_5[0xF] + 1;
      temp_v1_5[0xF] = temp_v0;
      if (((s8) temp_v0) >= 0x27)
      {
        (*((u8 **) (((u8 *) arg0) + 0x68)))[0xF] = 0;
      }
      temp_a2 = *((u8 **) (((u8 *) arg0) + 0x68));
      temp_a1 = (s8) temp_a2[0xF];
      if (!(sEnemyDefTable[temp_a1].f0 & 0x8000))
      {
        continue;
      }
      savedIndex = (s8) temp_a1;
      temp_a2[0xF] = (u8) (((u8) temp_a1) + temp_s4[(temp_a1 * 8) + 0x1FE]);
      temp_s2 = temp_s4 + (((s8) savedIndex) * 8);
      if (temp_s2[0x1FC] == 0)
      {
        continue;
      }
      if ((arg1 != 0) && (D_800C469E[(s8) (*((u8 **) (((u8 *) arg0) + 0x68)))[0xF]].f0 == 0x21))
      {
        continue;
      }
      temp_a1_2 = (s8) (*((u8 **) (((u8 *) arg0) + 0x68)))[0xF];
      if (temp_a1_2 == 0)
      {
        if (var_s6 == 0)
        {
          if (arg1 != 0)
          {
            var_s6 = 1;
            continue;
          }
        }
      }
      else
        if ((func_80063D38(temp_s4, temp_a1_2) << 0x18) == 0)
      {
        if ((temp_s2[0x1FE] != 0) && ((func_80063D38(temp_s4, savedIndex) << 0x18) != 0))
        {
          temp_s2[0x1FE] = 0;
          (*((u8 **) (((u8 *) arg0) + 0x68)))[0xF] = temp_a1;
        }
        else
        {
          continue;
        }
      }
      break;
    }


    case 1:

    case 3:

    case 5:

    case 6:

    case 7:

    case 9:

    case 10:

    case 11:
      return;

  }

}

