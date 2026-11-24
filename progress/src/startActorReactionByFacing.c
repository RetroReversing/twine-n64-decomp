#ifndef M2C_DEFINES
#define M2C_DEFINES
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
s32 angleDelta12(s32, s32);
f32 approximateAtan2(f32, f32);
s32 setActorCommandState();
s32 negateMotionComponent();
s32 vec3Subtract();
void setActorAnimation();
s32 playNearestMarkerSoundFromTable();
s32 playMarkerSoundAtNearestMarker();
s32 playMarkerSoundAtNearestMarkerThird();
s32 randomIntBelow(s32);
extern u8 gActorTypeKindTable;
extern u8 D_800C9A58;
extern u8 D_800C9A5C;
extern u8 D_800C9A68;
extern u8 D_800C9A70;
extern u8 D_800C9A7C;
extern u8 D_800C9A88;
extern u8 D_800C9A94;
extern u8 D_800C9AA0;
extern u8 D_800C9AAC;
extern u8 D_800C9AB8;
extern u8 D_800C9AC4;
extern u8 D_800C9AD0;
extern u8 D_800C9ADC;
extern u8 D_800C9AE8;
extern u8 D_800C9AF4;
extern u8 D_800C9B00;
extern u8 D_800C9B0C;
extern u8 D_800C9B18;
extern u8 D_800C9B24;
extern u8 D_800C9B30;
extern u8 D_800C9B38;
extern u8 D_800C9B4C;
extern u8 D_800C9B64;
extern u8 D_800C9B6C;
extern u8 D_800C9B70;
extern u8 D_800C9B74;
extern u8 D_800C9B78;
extern u8 D_800C9B7C;
extern u8 D_800C9B80;
extern u8 D_800C9B88;
typedef struct { unsigned char pad_0[36]; float field_24; unsigned char pad_28[4]; float field_2C; unsigned char pad_30[16]; float field_40; unsigned char pad_44[28]; int field_60; unsigned char pad_64[4]; void * field_68; void * field_6C; unsigned char pad_70[8]; unsigned short field_78; unsigned char pad_7A[2]; short field_7C; } __repair_record_arg0;
/* Starts an actor's reaction to a target: faces it, then picks a random command state/animation by facing octant and target kind. */ void startActorReactionByFacing(void *actor)
{
  u8 *var_s0_2;
  f32 ox2, oz2, fa2, fb2, ox3, oz3, fa3, fb3; u32 vv2, vv3;
  s32 targetClass;
  f32 deltaZ;
  f32 deltaX;
  f32 var_fv0;
  f32 var_fv1;
  f32 var_fv1_2;
  s16 temp_v1_4;
  s32 prevState;
  f32 originX;
  void *target;
  f32 originZ;
  u32 actor_flags;
  s32 var_a0;
  s32 var_a0_2;
  u16 temp_v1;
  s32 commandId;
  u16 var_v0;
  u32 facingOctant;
  u32 var_v1;
  u32 __repair_phase_var_v1;
  u32 var_v1_2;
  u8 temp_v1_2;
  u8 temp_v1_3;
  u8 targetKind;
  void *temp_a0;
  void *temp_a0_3;
  void *targetActor;
  union 
  {
    void *pointer;
    s32 value;
  } __repair_phase_storage;
  void *temp_v0_3;
  void *temp_v0_2;
  temp_v1 = ((__repair_record_arg0*)actor)->field_78;
  if (temp_v1 == 1)
  {
    target = ((__repair_record_arg0*)actor)->field_6C;
    prevState = ((__repair_record_arg0*)actor)->field_7C;
    deltaX = (*((f32 *) (((char *) target) + 0x50))) - (((__repair_record_arg0*)actor)->field_24);
    targetKind = *((u8 *) (((char *) target) + 0x82));
    deltaZ = (*((f32 *) (((char *) target) + 0x58))) - (((__repair_record_arg0*)actor)->field_2C);
    vec3Subtract(actor + 0x24, actor + 0x30, target);
    actor_flags = *((u32 *) (((char *) target) + 0x88));
    *((s32 *) (((char *) target) + 0x48)) = 0;
    ((__repair_record_arg0*)actor)->field_78 = 0x4CU;
    ((__repair_record_arg0*)actor)->field_7C = 0xC;
    *((u8 *) (((char *) target) + 0x7F)) = 0xCU;
    targetClass = actor_flags >> 0x11;
    targetClass &= 0xF;
  }
  else
    if (temp_v1 == 2)
  {
    temp_v0_2 = ((__repair_record_arg0*)actor)->field_6C;
    ox2 = ((__repair_record_arg0*)actor)->field_24; oz2 = ((__repair_record_arg0*)actor)->field_2C; fa2 = *((f32 *) (((char *) temp_v0_2) + 0x1A0)); fb2 = *((f32 *) (((char *) temp_v0_2) + 0x1A8)); vv2 = *((u32 *) (((char *) temp_v0_2) + 0x18C)); prevState = 0; targetKind = 0; *((s32 *) (((char *) temp_v0_2) + 0xCC)) = 0;
    deltaX = fa2 - ox2;
    deltaZ = fb2 - oz2;
    ((__repair_record_arg0*)actor)->field_78 = 0x4D;
    targetClass = vv2 >> 0xC;
    targetClass &= 0xF;
    goto block_9;
  }
  else
  {
    if (temp_v1 == 3)
    {
      temp_v0_3 = ((__repair_record_arg0*)actor)->field_6C; ox3 = ((__repair_record_arg0*)actor)->field_24; oz3 = ((__repair_record_arg0*)actor)->field_2C; fa3 = *((f32 *) (((char *) temp_v0_3) + 0x1A0)); fb3 = *((f32 *) (((char *) temp_v0_3) + 0x1A8)); vv3 = *((u32 *) (((char *) temp_v0_3) + 0x18C)); prevState = 0; targetKind = 0; *((s32 *) (((char *) temp_v0_3) + 0xCC)) = 0;
      deltaX = fa3 - ox3;
      deltaZ = fb3 - oz3;
      ((__repair_record_arg0*)actor)->field_78 = 0x61;
      targetClass = vv3 >> 0xC;
      targetClass &= 0xF;
    }
    else
    {
      return;
    }
  }
  block_9:
  __repair_phase_storage.value = angleDelta12((s32) (approximateAtan2(deltaX, deltaZ) * 651.8986f), (s32) ((((__repair_record_arg0*)actor)->field_40) + 256.0f)) >> 9;

  temp_a0 = ((__repair_record_arg0*)actor)->field_68;
  *((s32 *) (((char *) temp_a0) + 0x14)) = (s32) ((*((s32 *) (((char *) temp_a0) + 0x14))) | 0x380);
  facingOctant = __repair_phase_storage.value & 7;
  switch (targetKind)
  {
    case 35:

    case 40:
      setActorCommandState(actor, 0x1F5U);
      goto block_71;

    case 22:
      setActorCommandState(actor, *((u16 *) ((&D_800C9A58) + (randomIntBelow(1) * 2))));
      setActorAnimation(actor, 0x4B);
      return;

    case 7:
      playMarkerSoundAtNearestMarkerThird(actor + 0x24);
      commandId = *((u16 *) ((&D_800C9A5C) + (randomIntBelow(6) * 2)));
      goto block_61;

    case 6:

    case 8:

    case 18:
      playNearestMarkerSoundFromTable(actor + 0x24);
      commandId = *((u16 *) ((&D_800C9A68) + (randomIntBelow(3) * 2)));
      goto block_61;

    case 4:
      playMarkerSoundAtNearestMarker(actor + 0x24);
      setActorCommandState(actor, randomIntBelow(4) + 0x2BC);
      goto block_71;

    default:
      var_v1 = prevState - 2;
      if ((((__repair_record_arg0*)actor)->field_78) == 1)
    {
      temp_v1_2 = *((u8 *) (((char *) (((__repair_record_arg0*)actor)->field_6C)) + 0x7F));
      if (temp_v1_2 != (((__repair_record_arg0*)actor)->field_7C))
      {
        switch (temp_v1_2)
        {
          case 1:
            do
          {
            case 2:
              case 3:
              case 4:
              case 5:
              case 6:
              case 7:
              case 8:
              case 9:
              case 10:
              ;









            ;
          }
          while (0);

          case 11:

          case 12:
            goto state_dispatch;

          case 0:
            ((__repair_record_arg0*)actor)->field_7C = 0;
            break;

        }

      }
      var_v1 = prevState + (-2);
    }
      state_dispatch:
    __repair_phase_var_v1 = prevState - 2;

      switch (__repair_phase_var_v1)
    {
      case 7:
        goto block_71;

      case 9:
        negateMotionComponent(actor);
        goto block_71;

      case 0:

      case 3:
        switch (facingOctant)
      {
        case 0:
          commandId = *((u16 *) ((&D_800C9A70) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 1:
          commandId = *((u16 *) ((&D_800C9A7C) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 2:
          commandId = *((u16 *) ((&D_800C9A88) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 3:
          commandId = *((u16 *) ((&D_800C9A94) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 4:
          commandId = *((u16 *) ((&D_800C9AA0) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 5:
          commandId = *((u16 *) ((&D_800C9AAC) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 6:
          commandId = *((u16 *) ((&D_800C9AB8) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 7:
          commandId = *((u16 *) ((&D_800C9AC4) + (randomIntBelow(5) * 2)));
          goto block_61;

      }

        goto block_71;

      case 4:

      case 8:
        switch (facingOctant)
      {
        case 0:
          commandId = *((u16 *) ((&D_800C9AD0) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 1:
          commandId = *((u16 *) ((&D_800C9ADC) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 2:
          commandId = *((u16 *) ((&D_800C9AE8) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 3:
          commandId = *((u16 *) ((&D_800C9AF4) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 4:
          commandId = *((u16 *) ((&D_800C9B00) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 5:
          commandId = *((u16 *) ((&D_800C9B0C) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 6:
          commandId = *((u16 *) ((&D_800C9B18) + (randomIntBelow(5) * 2)));
          goto block_61;

        case 7:
          commandId = *((u16 *) ((&D_800C9B24) + (randomIntBelow(5) * 2)));
          goto block_61;

      }

        goto block_71;

      default:
        if (targetClass == 0xE)
      {
        commandId = *((u16 *) ((&D_800C9B30) + (randomIntBelow(4) * 2)));
        goto block_61;
      }
        switch (facingOctant)
      {
        case 0:
          temp_v1_3 = *((&gActorTypeKindTable) + ((*((s8 *) (((char *) (((__repair_record_arg0*)actor)->field_68)) + 0xE))) * 0xE8));
          switch (temp_v1_3)
        {
          default:

          case 0:

          case 1:

          case 3:

          case 4:
            var_s0_2 = &D_800C9B38;
            var_a0_2 = 9;
            break;

          case 2:
            var_s0_2 = &D_800C9B4C;
            var_a0_2 = 0xB;
            break;

        }

          commandId = *((u16 *) (var_s0_2 + (randomIntBelow(var_a0_2) * 2)));
          goto block_61;

        case 1:
          commandId = *((u16 *) ((&D_800C9B64) + (randomIntBelow(3) * 2)));
          goto block_61;

        case 2:
          commandId = *((u16 *) ((&D_800C9B6C) + (randomIntBelow(1) * 2)));
          goto block_61;

        case 3:
          commandId = *((u16 *) ((&D_800C9B70) + (randomIntBelow(1) * 2)));
          goto block_61;

        case 4:
          commandId = *((u16 *) ((&D_800C9B74) + (randomIntBelow(2) * 2)));
          goto block_61;

        case 5:
          setActorCommandState(actor, *((u16 *) ((&D_800C9B78) + (randomIntBelow(1) * 2))));

        case 6:
          commandId = *((u16 *) ((&D_800C9B7C) + (randomIntBelow(1) * 2)));
          goto block_61;

        case 7:
          commandId = *((u16 *) ((&D_800C9B80) + (randomIntBelow(3) * 2)));
          block_61:
        setActorCommandState(actor, commandId);

          goto block_71;

      }

        goto block_71;

      case 6:
        temp_v1_4 = *((s16 *) (((char *) (((__repair_record_arg0*)actor)->field_68)) + 0xA2));
        switch (temp_v1_4)
      {
        case 0x2AC:
          setActorCommandState(actor, 0x2AEU);
          setActorAnimation(actor, 0x16);
          return;

        case 0x2AD:
          setActorCommandState(actor, 0x2AFU);
          setActorAnimation(actor, 0x16);
          return;

        case 0x217:
          setActorCommandState(actor, *((u16 *) ((&D_800C9B88) + (randomIntBelow(5) * 2))));
          setActorAnimation(actor, 0x16);
          return;

      }

        goto block_71;

    }

      break;

  }

  return;
  block_71:
  if ((((__repair_record_arg0*)actor)->field_78) == 0x4C)
  {
    targetActor = ((__repair_record_arg0*)actor)->field_6C;
    temp_a0_3 = *((void **) (((char *) targetActor) + 0x70));
    if (temp_a0_3 != NULL)
    {
      if ((*((u16 *) (((char *) temp_a0_3) + 0x78))) == 0x3D)
      {
        *((s16 *) (((char *) temp_a0_3) + 0x7A)) = 5;
      }
      *((void **) (((char *) targetActor) + 0x70)) = NULL;
    }
    if ((((__repair_record_arg0*)actor)->field_60) & 0x40)
    {
      setActorAnimation(actor, 0x85);
      return;
    }
    else
    {
      if ((((*((u32 *) (((char *) targetActor) + 0x88))) & 0x1E0000) == 0x1C0000) || ((*((s8 *) (((char *) (((__repair_record_arg0*)actor)->field_68)) + 0xE))) != 0))
      {
        var_fv1 = 0.0f;
      }
      else
      {
        var_fv1 = 15.0f;
      }
      if ((var_fv1 + 1) >= (2.1474836e9f + 1))
      {
        var_a0 = ((s32) (var_fv1 - 2.1474836e9f)) | 0x80000000;
      }
      else
      {
        var_a0 = (s32) var_fv1;
      }
      if (randomIntBelow((u32) var_fv1) != 5)
      {
        setActorAnimation(actor, 0x15);
        return;
      }
      else
      {
        *((s16 *) (((char *) targetActor) + 0x7C)) = 0;
        setActorAnimation(actor, 0x1A);
      }
    }
  }

}

