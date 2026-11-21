f32 approxDistance();
s32 buildRotationMatrix();
s32 buildRotationMatrixS16();
s32 MatMul3x3InPlace();
s32 func_800839F0();
extern char *gObjectRecords;
typedef struct 
{
  u32 x;
  u32 y;
  u32 z;
} ObjectVectorWords;
inline static char *inline_fn(int arg0)
{
  return gObjectRecords + arg0;
}

inline static char *inline_fn2(char *arg0, s32 arg1)
{
  return arg0 + arg1;
}

void func_8000D6A0(s32 arg0)
{
  ObjectVectorWords sp10;
  char *records = gObjectRecords;
  f32 sp20[3];
  s16 sp30[3];
  f32 var_fv0;
  s32 temp_a0_2;
  s32 temp_a3;
  s32 temp_s0_2;
  s32 temp_s1;
  s32 __repair_phase_temp_s1;
  s32 __repair___repair_phase_temp_s1_1;
  s32 temp_s5;
  u32 temp_a1;
  u32 temp_v0_4;
  void *temp_a0;
  void *temp_s3;
  void *temp_v0;
  union 
  {
    void *pointer;
    s32 value;
  } __repair_phase_storage;
  void *temp_v0_3;
  void *temp_v1;
  __repair_phase_temp_s1 = (arg0 * 53) << 2; temp_a0 = __repair_phase_temp_s1 + records; __repair___repair_phase_temp_s1_1 = *((u8 *) inline_fn2((char *) temp_a0, 0x98));
  if (__repair___repair_phase_temp_s1_1 != 0xFF)
  {
    temp_s1 = (__repair___repair_phase_temp_s1_1 * 53) << 2;
    {
      typedef struct 
      {
        char pad[0x68];
        void *object;
        char pad2[0x2c];
        u8 parent;
      } ObjectRecordFields;
      ObjectRecordFields *parentRecord = (ObjectRecordFields *) inline_fn2(records, temp_s1);
      ObjectRecordFields *childRecord = (ObjectRecordFields *) temp_a0;
      temp_s3 = childRecord->object; temp_a0 = parentRecord->object;
      if (parentRecord->parent == 0xFF)
      {
        sp30[0] = (s16) ((s32) (*((f32 *) inline_fn2((char *) temp_a0, 0x3C)))); sp30[1] = (s16) ((s32) (*((f32 *) inline_fn2((char *) temp_a0, 0x40)))); sp30[2] = (s16) ((s32) (*((f32 *) inline_fn2((char *) temp_a0, 0x44))));
        buildRotationMatrixS16(sp30, ((u32) records) + ((u32) (temp_s1 + 0x9C)));
      }
    }
    sp10 = *((ObjectVectorWords *) inline_fn2(inline_fn(__repair_phase_temp_s1), 0x14));
    {
      func_800839F0((((u32) temp_s1) + ((u32) gObjectRecords)) + 0x9C, &sp10, sp20);
    }
    sp20[0] += *((f32 *) inline_fn2((char *) temp_a0, 0x24)); sp20[1] += *((f32 *) inline_fn2((char *) temp_a0, 0x28)); sp20[2] += *((f32 *) inline_fn2((char *) temp_a0, 0x2C));
    {
      typedef struct 
      {
        u32 x;
        u32 y;
        u32 z;
      } V;
      *((V *) inline_fn2((char *) temp_s3, 0x24)) = *((V *) sp20);
    }
    temp_v0_3 = *((void **) inline_fn2((char *) temp_s3, 0x70));
    if (temp_v0_3 && ((((temp_v0_4 = *((u32 *) inline_fn2((char *) temp_v0_3, 0x30)), temp_a0_2 = (temp_v0_4 >> 4) & 0xFFFF, temp_a1 = temp_v0_4 >> 20, ((temp_a1 == 0x11C) & (temp_a0_2 == 0x1A)) != 0)) || ((temp_a1 == 0x98) & (temp_a0_2 == 3))) || ((temp_a1 == 0xB1) & (temp_a0_2 == 2))))
    {
      var_fv0 = approxDistance(inline_fn2(temp_s3, 0x24), inline_fn2(temp_s3, 0x30));
      {
        f32 period = 2.7017698f;
        if (var_fv0 > period)
        {
          do
          {
            var_fv0 -= period;
          }
          while (var_fv0 > period);
        }
        temp_v1 = (void *) gObjectRecords; temp_v1 = (void *) inline_fn2((char *) temp_v1, (s32) (arg0 * 0xD4));
        *((s16 *) inline_fn2((char *) temp_v1, 0x96)) = (s16) ((s32) (((f32) (*((s16 *) inline_fn2((char *) temp_v1, 0x96)))) + ((var_fv0 / period) * 4096.0f)));
      }
    }
    sp30[0] = (s16) ((s32) (*((f32 *) inline_fn2((char *) temp_s3, 0x3C)))); temp_s1 = arg0 * 0xD4; sp30[1] = (s16) ((s32) (*((f32 *) inline_fn2((char *) temp_s3, 0x40)))); __repair_phase_storage.value = (arg0 * 0xD4) + 0x14; sp30[2] = (s16) ((s32) ((*((f32 *) inline_fn2((char *) temp_s3, 0x44))) + ((f32) (*((s16 *) inline_fn2((char *) inline_fn(arg0 * 0xD4), 0x96))))));
    buildRotationMatrix(sp30, inline_fn2(inline_fn2(gObjectRecords, __repair_phase_storage.value), 0x88));
    MatMul3x3InPlace(inline_fn2((__repair___repair_phase_temp_s1_1 * 0xD4) + gObjectRecords, 0x9C), inline_fn2(inline_fn2(gObjectRecords, __repair_phase_storage.value), 0x88));
    *((s16 *) inline_fn2((char *) temp_s3, 0x7C)) = arg0;
    *((s32 *) inline_fn2((char *) temp_s3, 0x58)) |= 0x40000;
  }
}

