f32 distanceXZ(void *, void *);
f32 randomFloatScaled(f32);
s32 buildRotationMatrixS16(void *, s16 *);
void multiplyMat3ByVec3(void *, void *, void *);
extern f64 D_800D66C0;
typedef struct 
{
  unsigned char pad_0[60];
  float field_3C;
  float field_40;
  float field_44;
  unsigned char pad_48[36];
  void *field_6C;
} __repair_record_arg0;
/* Spawns six burst particles around the effect position, rotating a fixed offset table by the effect's angles and giving each a spread velocity. */ void initBurstParticles(void *effect)
{
  u8 rotMatrix[0x30];
  s16 angles[3];
  struct 
  {
    s32 f48;
    f32 f4C;
    s32 f50;
  } __repair_frame;
  typeof(__repair_frame) *frame;
  f32 loop_zero;
  register s32 *offsetTable;
  f32 *yawOffsets;
  f32 temp_fv0;
  f32 speedSpread;
  f32 randomScale;
  s32 temp_a0;
  s32 particlePos;
  u32 i;
  register void *particle;
  register void *particleList;
  register void *listCursor;
  particleList = ((__repair_record_arg0 *) effect)->field_6C;
  angles[0] = (s16) ((s32) ((__repair_record_arg0 *) effect)->field_3C);
  angles[1] = (s16) ((s32) ((__repair_record_arg0 *) effect)->field_40);
  angles[2] = (s16) ((s32) ((__repair_record_arg0 *) effect)->field_44);
  buildRotationMatrixS16(angles, rotMatrix);
  temp_fv0 = distanceXZ(effect + 0x24, effect + 0x30);
  speedSpread = 3.6442475f;
  if (0.0f != temp_fv0)
  {
    f32 quotient = temp_fv0 / speedSpread;
    randomScale = (f32) (((f64) temp_fv0) * D_800D66C0);
    speedSpread = quotient * 4096.0f;
  }
  else
    if (D_800D66C0)
  {
    randomScale = (speedSpread = 0.0f);
  }
  else
  {
    randomScale = (speedSpread = 0.0f);
  }
  i = 0;
  frame = &__repair_frame;
  loop_zero = 0.0f;
  yawOffsets = D_800CEE98;
  offsetTable = gBurstParticleOffsets;
  listCursor = particleList;
  do
  {
    particle = *((void **) (((char *) listCursor) + 0x2C));
    __repair_frame = *((typeof(__repair_frame) *) offsetTable);
    temp_a0 = __repair_frame.f50;
    particlePos = particle + 0x24;
    __repair_frame.f4C -= randomFloatScaled(randomScale);
    multiplyMat3ByVec3(rotMatrix, frame, (void *) particlePos);
    do
    {
      vec3Add(effect + 0x24, particlePos, particlePos);
    }
    while (0);
    *((s32 *) (((char *) particle) + 0x30)) = (s32) (*((s32 *) (((char *) particle) + 0x24)));
    *((s32 *) (((char *) particle) + 0x34)) = (s32) (*((s32 *) (((char *) particle) + 0x28)));
    *((s32 *) (((char *) particle) + 0x38)) = (s32) (*((s32 *) (((char *) particle) + 0x2C)));
    *((f32 *) (((char *) particle) + 0x40)) = (f32) (((__repair_record_arg0 *) effect)->field_40 + (*yawOffsets));
    if ((*yawOffsets) == loop_zero)
    {
      *((f32 *) (((char *) particle) + 0x3C)) = (*((f32 *) (((char *) particle) + 0x3C))) - speedSpread;
    }
    else
    {
      *((f32 *) (((char *) particle) + 0x3C)) = (*((f32 *) (((char *) particle) + 0x3C))) + speedSpread;
    }
    yawOffsets += 1;
    offsetTable += 3;
    listCursor += 4;
    ++i;
    *((f32 *) (((char *) particle) + 0x44)) = (f32) ((__repair_record_arg0 *) effect)->field_44;
  }
  while (i < 6U);
}
