s32 actorLinkToSurface(s32, void *, s32);
s32 effectSetAnimFrame(void *, int, int);
u8 rollDifficultyChance(u16, u16, u16);
s32 pickRandomTableEntry(s32, u8, void *, s32);
void *spawnEffectObject(s32, void *, s32);
extern s16 D_800C4478;
extern short D_800C447A;
extern s16 D_800C4706;
extern s16 D_800C4708;
extern s32 *gDefaultOrderObj;
typedef struct 
{
  s32 w[3];
} __repair_words3;
typedef struct 
{
  unsigned char pad_0[12];
  int field_C;
  int field_10;
  int field_14;
  unsigned char pad_18[4];
  float field_1C;
  unsigned char pad_20[4];
  unsigned short field_24;
  unsigned short field_26;
  unsigned short field_28;
  unsigned short field_2A;
  unsigned char pad_2C[1];
  signed char field_2D;
  signed char field_2E;
  signed char field_2F;
  short field_30;
} __repair_record_temp_s0;
/* Spawns an effect object at pos, initializes its data record, picks its animation frame from a lookup table or direct values, and links it to the surface. */ void *spawnSurfaceDecalEffect(void *pos, s32 room, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8, u16 arg9, short flags, u16 effectId, s32 arg12, u8 arg13)
{
  u16 sp16;
  u16 sp26;
  int var_a1;
  void *var_a0;
  unsigned int var_a2;
  s32 temp_v0_2;
  s32 temp_v0_3;
  void *effectData;
  void *effect;
  sp16 = arg2;
  sp26 = arg6;
  pickRandomTableEntry(arg12, arg13, pos, room);
  if ((rollDifficultyChance(arg7, arg8, arg9) << 0x18) != 0)
  {
    effect = spawnEffectObject(0x34, pos, room);
    if (effect != NULL)
    {
      effectData = *((void **) (((char *) effect) + 0x6C));
      *((s16 *) (((char *) effect) + 0x78)) = 0x24;
      *((s16 *) (((char *) effect) + 0x7A)) = 0;
      *((__repair_words3 *) (((char *) effectData) + 0x0)) = *((__repair_words3 *) (((s8 *) pos) + 0x0));
      ((__repair_record_temp_s0 *) effectData)->field_C = 0;
      ((__repair_record_temp_s0 *) effectData)->field_10 = 0;
      ((__repair_record_temp_s0 *) effectData)->field_14 = 0;
      ((__repair_record_temp_s0 *) effectData)->field_24 = effectId;
      ((__repair_record_temp_s0 *) effectData)->field_2F = 1;
      if (flags & 2)
      {
        ((__repair_record_temp_s0 *) effectData)->field_2D = 1;
      }
      else
      {
        ((__repair_record_temp_s0 *) effectData)->field_2D = 0;
      }
      if (flags & 1)
      {
        switch (arg4)
        {
          do
          {
            case 0:
              temp_v0_2 = (arg5 & 0xFFFF) * 0xE8;

            var_a0 = effect;
            var_a1 = *((s16 *) (((u8 *) (&D_800C4706)) + temp_v0_2)); var_a2 = *((s16 *) (((u8 *) (&D_800C4708)) + temp_v0_2));
            goto block_17;
          }
          while (0);
          case 1:
            temp_v0_3 = arg5 * 0x10;
            var_a0 = effect;
            var_a1 = *((s16 *) (((u8 *) (&D_800C4478)) + temp_v0_3));
            var_a2 = *((s16 *) (((u8 *) (&D_800C447A)) + temp_v0_3));
            goto block_17;

          case 2:
            goto direct;

        }

      }
      else
      {
        direct:
        var_a0 = effect;
        var_a1 = arg2;

        do { var_a2 = arg3 & 0xFFFF; } while (0);
        block_17:
        effectSetAnimFrame(var_a0, var_a1, var_a2);

      }
      ((__repair_record_temp_s0 *) effectData)->field_26 = arg4;
      ((__repair_record_temp_s0 *) effectData)->field_28 = arg5;
      ((__repair_record_temp_s0 *) effectData)->field_2A = arg6;
      ((__repair_record_temp_s0 *) effectData)->field_30 = 0;
      actorLinkToSurface(*gDefaultOrderObj, effect, 1);
 *((s32 *) (((char *) effect) - (-0x5C))) = (s32) ((*((s32 *) (((char *) effect) + 0x5C))) | 0x400); *((f32 *) (((char *) effect) + 0x54)) = 0.015625f; ((__repair_record_temp_s0 *) effectData)->field_1C = (f32) ((*((f32 *) (((char *) effect) + 0x28))) - 1.0f);        if (((((u32) ((short) (arg5 - 0x18))) < 2U) | (arg5 == 0x17)) != 0)
      {
        ((__repair_record_temp_s0 *) effectData)->field_2E = 1;
      }
      else
      {
        ((__repair_record_temp_s0 *) effectData)->field_2E = 0;
      }
      *((s16 *) (((char *) effect) + 0x7A)) = 2;
    }
    return effect;
  }
  return NULL;
}

