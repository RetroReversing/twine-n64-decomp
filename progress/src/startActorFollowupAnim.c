s32 setActorCommandState(void *, u16);
s32 clearProbeAndSetCommandValue(void *, u16, u16);
s32 trySetActorCommandValue(void *, u16, u16);
s32 clearProbeState(void *, s32);
s32 setActorAnimation(void *, s32);
s32 freeActorAnimListNode(void *);
s32 randomIntBelow(s32);
extern s32 D_800C9970;
extern s32 D_800C9972;
extern s32 D_800C99AC;
extern s32 D_800C99AE;
extern s32 D_800C99E8;
extern s32 D_800C9A08;
extern s32 D_800C9A0A;
extern s32 D_800C9A1C;
extern s32 D_800C9A1E;
typedef struct 
{
  s32 w[2];
} __repair_words2;
/* Picks and starts a follow-up animation for the actor from its current state and its target's flags; if the target is in mode 0x22 it switches to state 0xC instead. */ void startActorFollowupAnim(void *actor)
{
  volatile s32 frame_pad[8];
  s32 var_a1;
  s16 prevState;
  s16 state;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_v0_3;
  s32 temp_v0_4;
  s32 variant;
  char started;
  s32 var_v0;
  u16 animA;
  u16 animB;
  void *target;
  prevState = *((s16 *) (((char *) actor) + 0x7A));
  target = *((void **) (((char *) actor) + 0x6C));
  if ((prevState != 0x2D) && ((*((u8 *) (((char *) target) + 0x7E))) == 0))
  {
    *((u8 *) (((char *) target) + 0x7E)) = (u8) prevState;
  }
  if ((*((s32 *) (((char *) target) + 0x64))) == 0x22)
  {
    *((s16 *) (((char *) actor) + 0x7C)) = 0xC;
    *((s8 *) (((char *) target) + 0x7F)) = 0xC;
    *((s32 *) (((char *) actor) + 0x74)) = 0;
    clearProbeState(actor, 0x205);
    setActorAnimation(actor, 0x71);
    return;
  }
  state = *((s16 *) (((char *) actor) + 0x7C));
  started = 0;
  switch (state)
  {
    case 2:

    case 5:
      *((s16 *) (((char *) actor) + 0x7C)) = 5;
      *((s8 *) (((char *) target) + 0x7F)) = 5;
      temp_v0 = (((u32) (*((u32 *) (((char *) target) + 0x88)))) >> 0xF) & 0x3C;
      animA = *((u16 *) (((u8 *) (&D_800C9970)) + temp_v0));
      animB = *((u16 *) (((u8 *) (&D_800C9972)) + temp_v0));
      started = 1;
      trySetActorCommandValue(actor, animA, animB);
      break;

    case 6:

    case 10:
      *((s16 *) (((char *) actor) + 0x7C)) = 6;
      *((s8 *) (((char *) target) + 0x7F)) = 6;
      temp_v0_2 = (((u32) (*((u32 *) (((char *) target) + 0x88)))) >> 0xF) & 0x3C;
      started = 1;
      clearProbeAndSetCommandValue(actor, *((u16 *) (((u8 *) (&D_800C99AC)) + temp_v0_2)), *((u16 *) (((u8 *) (&D_800C99AE)) + temp_v0_2)));
      break;

    case 1:
      *((s16 *) (((char *) actor) + 0x7C)) = 4;
      *((s8 *) (((char *) target) + 0x7F)) = 4;
      animA = *((u16 *) (((u8 *) (&D_800C99E8)) + ((*((u16 *) (((char *) target) + 0x88))) & 0x1E)));
      started = 1;
      setActorCommandState(actor, animA);
      break;

    case 0:

    case 3:

    case 4:

    case 7:
      *((s16 *) (((char *) actor) + 0x7C)) = 4;
      *((s8 *) (((char *) target) + 0x7F)) = 4;
      variant = (((u32) (*((u32 *) (((char *) target) + 0x88)))) >> 0x11) & 0xF;
      started = 1;
      switch (variant)
    {
      case 7:

      case 0:

      case 14:
        temp_v0_4 = (randomIntBelow(5) & 0xFFFF) * 4;
        animA = *((u16 *) (((u8 *) (&D_800C9A08)) + temp_v0_4));
        animB = *((u16 *) (((u8 *) (&D_800C9A0A)) + temp_v0_4));
        break;

      default:
        temp_v0_3 = (((u32) (*((u32 *) (((char *) target) + 0x88)))) >> 0xF) & 0x3C;
        animA = *((u16 *) (((u8 *) (&D_800C9A1C)) + temp_v0_3));
        animB = *((u16 *) (((u8 *) (&D_800C9A1E)) + temp_v0_3));
        break;

    }

      trySetActorCommandValue(actor, animA, animB);
      break;

    case 11:

    default:
      break;

  }

  if (started != 0)
  {
    typedef struct 
    {
      s32 w[3];
    } Position;
    *((Position *) (((char *) target) + 0x18)) = *((Position *) (((char *) target) + 0x50));
    freeActorAnimListNode(actor);
    var_a1 = 0x2D;
    block_23:
    setActorAnimation(actor, var_a1);

  }
}

