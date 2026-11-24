s32 requestSound();
s32 isEnemyDefAvailable();
s32 playSoundAtPos();
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
/* Plays a cue, then cycles the actor's selected index (0..0x26) to the next valid enemy-def entry. */ void selectNextEnemyDef(void *actor, s8 skipType21)
{
  register s8 skippedZero = 0;
  volatile u32 pad[2];
  s32 savedIndex;
  s32 index;
  s8 temp_a1_2;
  u8 temp_v0;
  u8 *temp_a2;
  u8 *entry;
  u8 *owner;
  u8 *temp_v1_2;
  u8 *pp;
  u8 ux;
  u8 *temp_v1_3;
  u8 *temp_v1_4;
  u8 *temp_v1_5;
  owner = *((u8 **) (((u8 *) actor) + 0x6C));
  switch (*((s16 *) ((*((u8 **) (owner + 0xA8))) + 0x7A)))
  {
    default:

    case 0:

    case 2:

    case 4:

    case 8:
      if ((*((u16 *) (((u8 *) actor) + 0x78))) == 3)
    {
      if (temp_a2)
      {
        playSoundAtPos(0x118, ((u8 *) actor) + 0x24);
      }
      else
      {
        playSoundAtPos(0x118, ((u8 *) actor) + 0x24);
      }
    }
    else
    {
      requestSound(0x118);
    }
      temp_v1_2 = *((u8 **) (((u8 *) actor) + 0x68));
      temp_v1_2[0x10] = temp_v1_2[0xE];
      temp_v1_3 = *((u8 **) (((u8 *) actor) + 0x68));
      temp_v1_3[0xF] = temp_v1_3[0xE];
      temp_v1_4 = *((u8 **) (((u8 *) actor) + 0x68));
      if (((s8) temp_v1_4[0xF]) >= 0x27)
    {
      temp_v1_4[0xF] = *((u16 *) (owner + 0x134));
      return;
    }
      for (;;)
    {
      temp_v1_5 = *((u8 **) (((u8 *) actor) + 0x68));
      temp_v0 = temp_v1_5[0xF] + 1;
      temp_v1_5[0xF] = temp_v0;
      if (((s8) temp_v0) >= 0x27)
      {
        (*((u8 **) (((u8 *) actor) + 0x68)))[0xF] = 0;
      }
      temp_a2 = *((u8 **) (((u8 *) actor) + 0x68));
      index = (s8) temp_a2[0xF];
      if (!(sEnemyDefTable[index].f0 & 0x8000))
      {
        continue;
      }
      savedIndex = (s8) index;
      ux = index;
      temp_a2[0xF] = (u8) (temp_a2[0xF] + (owner + (index<<3))[0x1FE]);
      entry = owner + (((s8) savedIndex) * 8);
      if (entry[0x1FC] == 0)
      {
        continue;
      }
      if ((skipType21 != 0) && (D_800C469E[(s8) (*((u8 **) (((u8 *) actor) + 0x68)))[0xF]].f0 == 0x21))
      {
        continue;
      }
      temp_a1_2 = (s8) (*((u8 **) (((u8 *) actor) + 0x68)))[0xF];
      if (temp_a1_2 == 0)
      {
        if (skippedZero == 0)
        {
          if (skipType21 != 0)
          {
            skippedZero = 1;
            continue;
          }
        }
      }
      else
        if ((isEnemyDefAvailable(owner, temp_a1_2) << 0x18) == 0)
      {
        if ((entry[0x1FE] != 0) && ((isEnemyDefAvailable(owner, savedIndex) << 0x18) != 0))
        {
          entry[0x1FE] = 0;
          pp = *((u8 **) (((u8 *) actor) + 0x68)); do { do { pp[0xF] = ux; } while (0); } while (0);
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


