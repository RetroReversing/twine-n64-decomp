void clearActorTriplet(void *);
extern u8 gSkipActorSpawns;
extern f32 gSavedActorVelX;
extern f32 gSavedActorVelY;
extern f32 gSavedActorVelZ;
typedef struct 
{
  unsigned char pad[44];
  f32 value;
} __repair_field_2C;
typedef struct 
{
  unsigned char pad[60];
  int value;
} __repair_field_3C;
inline static s32 *inline_fn(void *arg0)
{
  return (s32 *) (((char *) arg0) + 0x50);
}

typedef struct 
{
  char pad[0x58];
  unsigned int mode : 16;
  unsigned int state : 14;
  unsigned int spare : 2;
  unsigned int flags : 9;
  unsigned int mid : 6;
  unsigned int low : 17;
} StateFields;
inline static s16 *inline_fn2(s16 *arg0)
{
  return arg0;
}

/* Switches on the action id and sets the actor's mode/state bits accordingly. It saves and zeroes the velocity for some actions. */ void applyActionToActorState(void *arg0, void *arg1, s32 *arg2, s8 *arg3)
{
  s16 var_v0_6;
  s16 var_v0_7;
  s32 temp_a0;
  s32 __repair_phase_temp_a0;
  unsigned int var_v0_2;
  unsigned int __repair_phase_var_v0_2;
  long var_v0_3;
  unsigned long var_v0_4;
  int var_v0_5;
  register unsigned short var_v1;
  unsigned int var_v1_2;
  unsigned var_v1_3;
  u32 temp_high_flags;
  unsigned long temp_v0_10;
  unsigned long temp_v0_11;
  u32 temp_v0_12;
  u32 temp_v0_13;
  u32 temp_v0_14;
  f32 saved_x;
  f32 __repair_phase_saved_x;
  f32 zero;
  u32 temp_v0_15;
  u32 __repair_phase_temp_v0_15;
  u32 temp_v0_17;
  u32 temp_v0_18;
  unsigned temp_v0_19;
  u32 temp_v0_20;
  u32 temp_v0_21;
  register unsigned int temp_v0_22;
  unsigned temp_v0_23;
  u32 temp_v0_24;
  s32 temp_v0_25;
  u32 temp_v0_26;
  unsigned int temp_v0_28;
  u32 temp_v0_29;
  unsigned int temp_v0_2;
  u32 temp_v0_3;
  u32 temp_v0_4;
  int temp_v0_5;
  register u32 temp_v0_6;
  register u32 temp_v0_7;
  unsigned long temp_v0_8;
  u32 temp_v0_9;
  register u32 temp_v1;
  register u32 temp_v1_2;
  unsigned int temp_v1_3;
  register u32 temp_v1_4;
  u32 temp_v1_5;
  u32 temp_v1_8;
  u32 var_a0;
  u32 temp_v0;
  s32 temp_v1_6;
  s32 __repair_phase_temp_v1_6;
  s32 temp_v1_7;
  u8 var_v0;
  void *__repair_phase_storage_pointer;
  u32 __repair_phase_storage_value;
  void *temp_a0_3;
  __repair_phase_temp_a0 = gSkipActorSpawns != 0;
  if (((__repair_field_3C *) arg0)->value & 0x400000)
  {
    *inline_fn(arg1) |= 0x100;
  }
  temp_v0 = *((u8 *) (((char *) (*((void **) (((char *) arg0) + 0x24)))) + 0x1E));
  switch ((u32) temp_v0)
  {
    case 0x3E:
    {
      s32 flags = *inline_fn(arg1);
      *((s16 *) (((char *) arg1) + 0x58)) = 0x18;
      *inline_fn(arg1) = flags & (~0x400);
      return;
    }

    case 0x40:
      ((StateFields *) arg1)->mode = 0x18;
      ((StateFields *) arg1)->state |= 4;
      ((StateFields *) arg1)->flags |= 0x20;
      *inline_fn(arg1) &= ~0x400;
      *arg2 = 1;
      return;

    case 0x4D:
      var_v0 = 0x18;
      *((s16 *) (((char *) arg1) + 0x58)) = (s16) var_v0;
      return;

    case 0x52:

    case 0xCB:
      ((StateFields *) arg1)->state |= 0x400;
      *inline_fn(arg1) &= ~0x200;
      ((StateFields *) arg1)->mode = 0x18;
      return;

    case 0x1B:
      ((StateFields *) arg1)->state |= 8;
      ((StateFields *) arg1)->mode = 0x18;
      return;

    case 0x99:
      temp_v1 = *((u32 *) (((char *) arg1) + 0x5C));
      *inline_fn2((s16 *) (((char *) arg1) + 0x58)) = 0x18;
      ;
      var_a0 = (temp_v1 & 0xFF81FFFF) | ((((temp_v1 >> 0x11) & 0x3F) | 4) << 0x11);
      *((u32 *) (((char *) arg1) + 0x5C)) = var_a0;
      *inline_fn(arg1) |= 0x02000000;
      return;

    case 0x9A:
      temp_v0_6 = *((u32 *) (((char *) arg1) + 0x5C));
      *((s16 *) (((char *) arg1) + 0x58)) = 0x18;
      var_a0 = (temp_v0_6 & 0xFF81FFFF) | ((((temp_v0_6 >> 0x11) & 0x3F) | 4) << 0x11);
      var_v0_2 = 0x04000000;
      *((u32 *) (((char *) arg1) + 0x5C)) = var_a0;
      *inline_fn(arg1) |= var_v0_2;
      return;

    case 0x9B:
      temp_v0_7 = *((u32 *) (((char *) arg1) + 0x5C));
      *((s16 *) (((char *) arg1) + 0x58)) = 0x18;
      ;
      var_a0 = (temp_v0_7 & 0xFF81FFFF) | ((((temp_v0_7 >> 0x11) & 0x3F) | 4) << 0x11);
      *((u32 *) (((char *) arg1) + 0x5C)) = var_a0;
      *inline_fn(arg1) |= 0x08000000;
      return;

    case 0x9C:
      temp_v0_8 = *((u32 *) (((char *) arg1) + 0x5C));
      *((s16 *) (((char *) arg1) + 0x58)) = 0x18;
      __repair_phase_var_v0_2 = 0x10000000;
      var_a0 = (temp_v0_8 & 0xFF81FFFF) | ((((temp_v0_8 >> 0x11) & 0x3F) | 4) << 0x11);
      *((u32 *) (((char *) arg1) + 0x5C)) = var_a0;
      *inline_fn(arg1) |= __repair_phase_var_v0_2;
      return;

    case 0x8C:
      *inline_fn(arg1) |= 0x01000000;

    case 0x18:
      var_v0 = 0x18;
      *((s16 *) (((char *) arg1) + 0x58)) = (s16) var_v0;
      return;

    case 0x9D:
      if (((u32) __repair_phase_temp_a0) == 0)
    {
      *((s16 *) (((char *) arg1) + 0x58)) = 0x18;
      return;
    }
      break;

    case 0x9E:
      temp_v0_9 = (u32) (*((s32 *) (((char *) arg1) + 0x58)));
      *((s32 *) (((char *) arg1) + 0x58)) = (s32) ((temp_v0_9 & 0xFFFF0003) | ((((temp_v0_9 >> 2) & 0x3FFF) | 8) * 4));
      if (!__repair_phase_temp_a0)
    {
      var_v0 = 0x18;
      *((s16 *) (((char *) arg1) + 0x58)) = (s16) var_v0;
      return;
    }
      break;

    case 0x19:
      ((StateFields *) arg1)->mode = 0x18;
      ((StateFields *) arg1)->mid |= 4;
      return;

    case 0x68:
      temp_v0_10 = *((u32 *) (((char *) arg1) + 0x5C));
      *((u32 *) (((char *) arg1) + 0x5C)) = (u32) ((temp_v0_10 & 0x7FFFFF) | (((temp_v0_10 >> 0x17) | 0x10) << 0x17));

    case 0xC8:
      temp_v0_11 = *((u32 *) (((char *) arg1) + 0x5C));
      *((s16 *) (((char *) arg1) + 0x58)) = 0x18;
      *((u32 *) (((char *) arg1) + 0x5C)) = (u32) ((temp_v0_11 & 0x7FFFFF) | (((temp_v0_11 >> 0x17) | 0x40) << 0x17));
      *inline_fn(arg1) &= ~0x400;
      *arg3 = 0;
      *arg2 = 0xB;
      return;

    case 0x50:
      ((StateFields *) arg1)->state |= 0x200;
      goto block_35;

    case 0x4F:
      ((StateFields *) arg1)->state |= 0x200;
      goto block_29;

    case 0x49:
      clearActorTriplet(arg1);
      ((StateFields *) arg1)->state |= 0x40;
      goto block_29;

    case 0x48:
      clearActorTriplet(arg1);
      ((StateFields *) arg1)->state |= 0x10;
      goto block_29;

    case 0x47:
      clearActorTriplet(arg1);
      __repair_phase_storage_pointer = *((void **) (((char *) arg1) + 0x20));
      ((StateFields *) arg1)->state |= 0x20;
      *((u8 *) (((char *) __repair_phase_storage_pointer) + 0x66)) = 0x80;
      *((u8 *) (((char *) __repair_phase_storage_pointer) + 0x65)) = 0x80;
      *((u8 *) (((char *) __repair_phase_storage_pointer) + 0x64)) = 0x80;
      goto block_29;

    case 0x46:
      block_29:
    temp_v0_15 = *((u32 *) (((char *) arg1) + 0x5C));

      __repair_phase_saved_x = *((f32 *) (((char *) arg1) + 0x24));
      *((u32 *) (((char *) arg1) + 0x5C)) = (u32) ((temp_v0_15 & 0xFF81FFFF) | ((((temp_v0_15 >> 0x11) & 0x3F) | 4) << 0x11));
      *((s16 *) (((char *) arg1) + 0x58)) = 0x46;
      __repair_phase_temp_v0_15 = *((u32 *) (((char *) arg1) + 0x5C));
      *((u32 *) (((char *) arg1) + 0x5C)) = (u32) ((__repair_phase_temp_v0_15 & 0x7FFFFF) | (((__repair_phase_temp_v0_15 >> 0x17) | 4) << 0x17));
      gSavedActorVelX = __repair_phase_saved_x;
      gSavedActorVelY = *((f32 *) (((char *) arg1) + 0x28));
      gSavedActorVelZ = *((f32 *) (((char *) arg1) + 0x2C));
      *((f32 *) (((char *) arg1) + 0x24)) = *((f32 *) (((char *) arg1) + 0x28)) = *((f32 *) (((char *) arg1) + 0x2C)) = 0.0f;
      if ((*((u16 *) (((char *) arg0) + 0x38))) == 1)
    {
      temp_high_flags = *((u32 *) (((char *) arg1) + 0x5C));
      *((u32 *) (((char *) arg1) + 0x5C)) = (temp_high_flags & 0x7FFFFF) | (((temp_high_flags >> 0x17) | 8) << 0x17);
    }
      return;

    case 0x45:
      ((StateFields *) arg1)->state |= 0x40;
      goto block_35;

    case 0x44:
      ((StateFields *) arg1)->state |= 0x10;
      goto block_35;

    case 0x43:
      temp_a0_3 = *((void **) (((char *) arg1) + 0x20));
      ((StateFields *) arg1)->state |= 0x20;
      *((u8 *) (((char *) temp_a0_3) + 0x66)) = 0x80;
      *((u8 *) (((char *) temp_a0_3) + 0x65)) = 0x80;
      *((u8 *) (((char *) temp_a0_3) + 0x64)) = 0x80;
      goto block_35;

    case 0x42:
      block_35:
      var_a0 = 0xFF81FFFF;
      temp_v0_13 = *((volatile u32 *) (((char *) arg1) + 0x5C));
      saved_x = *((volatile f32 *) (((char *) arg1) + 0x24));
      *((s16 *) (((char *) arg1) + 0x58)) = 0x46;
      var_a0 = temp_v0_13 & var_a0;
      var_a0 = var_a0 | ((((temp_v0_13 >> 0x11) & 0x3F) | 4) << 0x11);
      *((u32 *) (((char *) arg1) + 0x5C)) = var_a0;
      goto save_vector_zero;

    case 0x22:
      *((s16 *) (((char *) arg1) + 0x58)) = 0x46;
      *((f32 *) (((char *) (*((void **) (((char *) arg1) + 0x20)))) + 0x5C)) = 65536.0f;
      saved_x = *((f32 *) (((char *) arg1) + 0x24));
      save_vector_zero:
    gSavedActorVelX = saved_x;

      gSavedActorVelY = *((f32 *) (((char *) arg1) + 0x28));
      gSavedActorVelZ = *((f32 *) (((char *) arg1) + 0x2C));
      *((s32 *) (((char *) arg1) + 0x24)) = 0;
      *((s32 *) (((char *) arg1) + 0x28)) = 0;
      *((s32 *) (((char *) arg1) + 0x2C)) = 0;
      if ((*((u16 *) (((char *) arg0) + 0x38))) == 1)
    {
      temp_high_flags = *((u32 *) (((char *) arg1) + 0x5C));
      *((u32 *) (((char *) arg1) + 0x5C)) = (temp_high_flags & 0x7FFFFF) | (((temp_high_flags >> 0x17) | 8) << 0x17);
    }
      return;

    case 0x21:
      ((StateFields *) arg1)->mode = 0x18;
      ((StateFields *) arg1)->mid |= 1;
      return;

    case 0x3C:
      ((StateFields *) arg1)->mode = 0x18;
      ((StateFields *) arg1)->mid |= 2;
      return;

    case 0x3D:
      ((StateFields *) arg1)->mode = 0x18;
      ((StateFields *) arg1)->mid |= 8;
      return;

    case 0x1E:

    case 0x1F:

    case 0x84:

    case 0x85:

    case 0x88:

    case 0x89:
      *arg3 = 0;
      temp_v1_6 = *((u8 *) (((char *) (*((void **) (((char *) arg0) + 0x24)))) + 0x1E));
      if (temp_v1_6 == 0x84)
    {
      goto mark_84;
    }
      if (temp_v1_6 < 0x85)
    {
      if (temp_v1_6 == 0x1E)
      {
        goto mark_1e;
      }
      goto mode_1e;
    }
      if (temp_v1_6 == 0x88)
    {
      goto mark_88;
    }
      if (temp_v1_6 < 0x89)
    {
      if (temp_v1_6 == 0x85)
      {
        goto mode_84;
      }
      goto mode_1e;
    }
      if (temp_v1_6 == 0x89)
    {
      goto mode_88;
    }
      goto mode_1e;
      mark_1e:
    ((StateFields *) arg1)->state |= 0x2000;

      mode_1e:
    var_v0_6 = 0x1E;

      goto save_mode;
      mark_84:
    ((StateFields *) arg1)->state |= 0x2000;

      mode_84:
    var_v0_6 = 0x84;

      goto save_mode;
      mark_88:
    ((StateFields *) arg1)->state |= 0x2000;

      mode_88:
    var_v0_6 = 0x88;

      save_mode:
    *((volatile s16 *) (((char *) arg1) + 0x58)) = (int) var_v0_6;

      gSavedActorVelX = *((volatile f32 *) (((char *) arg1) + 0x24));
      *((f32 *) (&gSavedActorVelY)) = *((f32 *) (((char *) arg1) + 0x28));
      *((f32 *) (&gSavedActorVelZ)) = *((f32 *) (((char *) arg1) + 0x2C));
      *((f32 *) (((char *) arg1) + 0x24)) = 0;
      *((f32 *) (((char *) arg1) + 0x28)) = 0;
      *((f32 *) (((char *) arg1) + 0x2C)) = 0;
      *((s8 *) (((char *) arg1) + 0x54)) = (s8) (*((u16 *) (((char *) arg0) + 0x2C)));
      *((s8 *) (((char *) arg1) + 0x55)) = (s8) (*((u16 *) (((char *) arg0) + 0x2E)));
      return;

    case 0x27:

    case 0x86:

    case 0x8A:
      temp_v0_26 = (u32) (*((s32 *) (((char *) arg1) + 0x58)));
      *((s32 *) (((char *) arg1) + 0x58)) = (s32) ((temp_v0_26 & 0xFFFF0003) | ((((temp_v0_26 >> 2) & 0x3FFF) | 0x1000) * 4));

    case 0x53:

    case 0x87:

    case 0x8B:
      temp_v1_7 = *((u8 *) (((char *) (*((void **) (((char *) arg0) + 0x24)))) + 0x1E));
      if (temp_v1_7 < 0x86)
    {
      goto alt_mode_1e;
    }
      if (temp_v1_7 < 0x88)
    {
      goto alt_mode_84;
    }
      if (temp_v1_7 >= 0x8C)
    {
      goto alt_mode_1e;
    }
      if (temp_v1_7 >= 0x8A)
    {
      goto alt_mode_88;
    }
      alt_mode_1e:
    var_v0_7 = 0x1E;
      save_alt_mode:
    *((s16 *) (((char *) arg1) + 0x58)) = var_v0_7;

      __repair_phase_storage_value = (u32) (*((s32 *) (((char *) arg1) + 0x58)));
      *((s32 *) (((char *) arg1) + 0x58)) = (s32) ((__repair_phase_storage_value & 0xFFFF0003) | ((((__repair_phase_storage_value >> 2) & 0x3FFF) | 0x800) * 4));
      *arg2 = 1;
      gSavedActorVelX = *((f32 *) (((char *) arg1) + 0x24));
      gSavedActorVelY = *((f32 *) (((char *) arg1) + 0x28));
      gSavedActorVelZ = *((f32 *) (((char *) arg1) + 0x2C));
      *((f32 *) (((char *) arg1) + 0x24)) = 0;
      *((f32 *) (((char *) arg1) + 0x28)) = 0;
      *((f32 *) (((char *) arg1) + 0x2C)) = 0;
      *((s8 *) (((char *) *((u32 *) (((char *) arg1) + 0x3C))) + 0x47)) = (s8) (*((u16 *) (((char *) arg0) + 0x2C)));
      return;
      alt_mode_84:
    var_v0_7 = 0x84;
      goto save_alt_mode;
      alt_mode_88:
    var_v0_7 = 0x88;
      goto save_alt_mode;

    case 0x15:
      temp_v0_28 = (u32) (*((s32 *) (((char *) arg1) + 0x58)));
      *((s32 *) (((char *) arg1) + 0x58)) = (s32) ((temp_v0_28 & 0xFFFF0003) | ((((temp_v0_28 >> 2) & 0x3FFF) | 2) * 4));

    case 0x14:
      ((StateFields *) arg1)->mode = 0x18;
      ((StateFields *) arg1)->state |= 1;
      *inline_fn(arg1) &= ~0x600;
      ((StateFields *) arg1)->flags |= 0x10;
      *((s8 *) (((char *) arg1) + 0x54)) = (s8) (*((u16 *) (((char *) arg0) + 0x2C)));
      *((s8 *) (((char *) arg1) + 0x55)) = (s8) (*((u16 *) (((char *) arg0) + 0x2E)));
      *arg2 = 5;
      return;

    default:
      var_v0 = *((u8 *) (((char *) (*((void **) (((char *) arg0) + 0x24)))) + 0x1E));
      *((s16 *) (((char *) arg1) + 0x58)) = (s16) var_v0;
      return;

  }

}

