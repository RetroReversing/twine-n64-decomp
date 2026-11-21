typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} EffectVec;
s32 buildRotationMatrixS16(s16 *, f32 *);
s32 copyVec3Pair(f32 *, void *, void *);
f32 cosAngle(f32);
s32 effectSetAnimFrame(void *, s32, s32, void *);
s32 func_80047B14(f32 *, s32, f32 *, void *);
s32 objectListInsert(void *, s32);
s32 rotateVec3ByMat3(f32 *, f32 *);
f32 sinAngle(f32);
void *spawnEffectObject(s32, s32, s32);
s32 vec3Add(f32 *, f32 *, f32 *);
extern EffectVec D_800D3FE8;
extern EffectVec D_800D3FF4;
extern EffectVec D_800D4000;
extern s32 sEnemyDefTable;
extern void *sTrackMarkerTable[];
void func_800589FC(void *arg0, void *arg1)
{
  f32 matrix[12];
  f32 basis[12];
  s16 angles[3];
  volatile f32 sp78;
  volatile f32 sp7C;
  volatile f32 sp80;
  EffectVec vec88 __attribute__((aligned(8)));
  EffectVec vec98 __attribute__((aligned(8)));
  EffectVec vecA8 __attribute__((aligned(8)));
  EffectVec vecB8 __attribute__((aligned(8)));
  f32 spC8[3] __attribute__((aligned(8)));
  f32 spD8[3] __attribute__((aligned(8)));
  f32 spE8[3] __attribute__((aligned(8)));
  s32 padF4;
  volatile struct 
  {
    s32 padding;
    void *value;
  } savedOwner;
  volatile struct 
  {
    s32 padding;
    void *value;
  } savedDef;
  void *owner;
  void *enemyDef;
  s32 enemyIndex;
  volatile struct 
  {
    s32 padding;
    f32 *value;
  } savedBasis;
  f32 *basisVector;
  f32 *position;
  s32 var_a1;
  f32 *temp_s0;
  f32 temp_fs0;
  f32 temp_fs0_2;
  f32 temp_fs0_3;
  f32 temp_fs0_4;
  f32 temp_fs0_5;
  f32 temp_fs0_6;
  s32 temp_s2;
  void **temp_a1;
  void **temp_v1;
  void *temp_a0;
  void *temp_s1;
  void *temp_s7;
  void *temp_v0;
  void *temp_v0_2;
  savedOwner.value = arg0;
  temp_v0 = spawnEffectObject(0x20, 0, 0);
  if (temp_v0 != NULL)
  {
    owner = savedOwner.value;
    temp_s1 = *((void **) (((char *) owner) + 0x6C));
    temp_s7 = *((void **) (((char *) temp_v0) + 0x6C));
    temp_s2 = *((s8 *) (((char *) temp_s1) + 0x182));
    vec98 = D_800D3FE8;
    vecA8 = D_800D3FF4;
    vecB8 = D_800D4000;
    enemyIndex = *((s8 *) (((char *) (*((void **) (((char *) owner) + 0x68)))) + 0xE));
    vec88 = *((EffectVec *) arg1);
    *((void **) (((char *) temp_v0) + 0x18)) = owner;
 do { enemyIndex *= 0xE8; temp_a1 = &sTrackMarkerTable[temp_s2]; temp_a0 = *temp_a1; savedDef.value = enemyIndex + ((char *) (&sEnemyDefTable)); if (temp_a0 == NULL) { sp78 = 0.0f; sp7C = 0.0f; } else { sp78 = -((*((f32 *) (((char *) temp_a0) + 0x34))) * 651.8986f); sp7C = (*((f32 *) (((char *) (*temp_a1)) + 0x38))) * 651.8986f; } sp80 = 0.0f; matrix[0] = cosAngle(sp7C); temp_fs0 = sinAngle(sp78); matrix[1] = (-temp_fs0) * sinAngle(sp7C); temp_fs0_2 = sinAngle(sp7C); temp_fs0_3 = temp_fs0_2 * cosAngle(sp78); matrix[3] = 0; matrix[2] = temp_fs0_3; matrix[4] = cosAngle(sp78); matrix[5] = sinAngle(sp78); matrix[6] = -sinAngle(sp7C); temp_fs0_4 = cosAngle(sp7C); matrix[7] = -(temp_fs0_4 * sinAngle(sp78)); temp_fs0_5 = cosAngle(sp78); temp_fs0_6 = temp_fs0_5 * cosAngle(sp7C); vec88.y = -vec88.y; vec88.x = -vec88.x; matrix[8] = temp_fs0_6; position = &vec88.x; rotateVec3ByMat3(&matrix[0], position); temp_v1 = &sTrackMarkerTable[temp_s2]; temp_v0_2 = *temp_v1; if (temp_v0_2 != NULL) { vec88.x += *((f32 *) (((char *) temp_v0_2) + 0x10)); vec88.y += *((f32 *) (((char *) (*temp_v1)) + 0x14)); vec88.z += *((f32 *) (((char *) (*temp_v1)) + 0x18)); } *((s16 *) (((char *) temp_v0) + 0x78)) = 0x27; angles[0] = (s16) ((s32) (*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xA8)))) + 0x3C)))); angles[1] = (s16) ((s32) (*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xA8)))) + 0x40)))); angles[2] = (s16) ((s32) (*((f32 *) (((char *) (*((void **) (((char *) temp_s1) + 0xA8)))) + 0x44)))); buildRotationMatrixS16(&angles[0], basis); rotateVec3ByMat3(basis, &vec98.x); rotateVec3ByMat3(basis, &vecA8.x); savedBasis.value = &vecB8.x; rotateVec3ByMat3(basis, savedBasis.value); rotateVec3ByMat3(&matrix[0], &vec98.x); rotateVec3ByMat3(&matrix[0], &vecA8.x); rotateVec3ByMat3(&matrix[0], savedBasis.value); enemyDef = savedDef.value; func_80047B14(&vec98.x, *((s32 *) (((char *) enemyDef) + 0xC4)), spC8, enemyDef); enemyDef = savedDef.value; func_80047B14(&vecA8.x, *((s32 *) (((char *) enemyDef) + 0xC8)), spD8, enemyDef); enemyDef = savedDef.value; func_80047B14(savedBasis.value, *((s32 *) (((char *) enemyDef) + 0xCC)), spE8, enemyDef); temp_s0 = temp_s7 + 4; *((f32 *) (((char *) temp_s7) + 4)) = 0.0f; *((f32 *) (((char *) temp_s7) + 8)) = 0.0f; *((f32 *) (((char *) temp_s7) + 0xC)) = 0.0f; vec3Add(spC8, temp_s0, temp_s0); vec3Add(spD8, temp_s0, temp_s0); vec3Add(spE8, temp_s0, temp_s0); *((f32 *) (((char *) temp_s7) + 0x10)) = randomFloatScaled(64.0f); *((f32 *) (((char *) temp_s7) + 0x14)) = randomFloatScaled(64.0f); *((f32 *) (((char *) temp_s7) + 0x18)) = randomFloatScaled(64.0f); owner = savedOwner.value; *((f32 *) (((char *) temp_s7) + 4)) = (f32) ((*((f32 *) (((char *) temp_s7) + 4))) + ((*((f32 *) (((char *) owner) + 0x24))) - (*((f32 *) (((char *) owner) + 0x30))))); *((f32 *) (((char *) temp_s7) + 8)) = (f32) ((*((f32 *) (((char *) temp_s7) + 8))) + ((*((f32 *) (((char *) owner) + 0x28))) - (*((f32 *) (((char *) owner) + 0x34))))); *((f32 *) (((char *) temp_s7) + 0xC)) = (f32) ((*((f32 *) (((char *) temp_s7) + 0xC))) + ((*((f32 *) (((char *) owner) + 0x2C))) - (*((f32 *) (((char *) owner) + 0x38))))); enemyDef = savedDef.value; func_80047B14(&vec98.x, *((s32 *) (((char *) enemyDef) + 0xB8)), spC8, enemyDef); enemyDef = savedDef.value; func_80047B14(&vecA8.x, *((s32 *) (((char *) enemyDef) + 0xBC)), spD8, enemyDef); enemyDef = savedDef.value; func_80047B14(savedBasis.value, *((s32 *) (((char *) enemyDef) + 0xC0)), spE8, enemyDef); vec3Add(spC8, position, position); vec3Add(spD8, position, position); vec3Add(spE8, position, position); copyVec3Pair(position, temp_v0 + 0x24, temp_v0 + 0x30); vec3Add(position, &vec98.x, &vec98.x); vec3Add(position, &vecA8.x, &vecA8.x); basisVector = savedBasis.value; vec3Add(position, basisVector, basisVector); *((f32 *) (((char *) temp_v0) + 0x3C)) = (f32) (-sp78); *((f32 *) (((char *) temp_v0) + 0x40)) = sp7C; *((s16 *) (((char *) temp_v0) + 0x7A)) = 0; *((f32 *) (((char *) temp_v0) + 0x44)) = sp80; enemyDef = savedDef.value; if ((*((u16 *) (((char *) enemyDef) + 2))) != 0x14) { goto normalFrame; } var_a1 = 0xE; goto setFrame; } while (0);
    normalFrame:
    var_a1 = 0xD;

    setFrame:
    effectSetAnimFrame(temp_v0, var_a1, 0x1B, enemyDef);

    objectListInsert(temp_v0, *((s32 *) (((char *) savedOwner.value) + 0x20)));
    *((f32 *) (((char *) temp_v0) + 0x54)) = 0.015625f;
    owner = savedOwner.value;
    temp_fs0 = (*((f32 *) (((char *) owner) + 0x28))) - (*((f32 *) (((char *) (*((void **) (((char *) owner) + 0x68)))) + 0x38)));
    *((s16 *) (((char *) temp_s7) + 0x1C)) = 0x1E;
    *((f32 *) (((char *) temp_s7) + 0)) = temp_fs0;
    *((s16 *) (((char *) temp_v0) + 0x7A)) = 0;
  }
}
