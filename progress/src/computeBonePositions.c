void MatMul3x3InPlace(void *, void *);
void multiplyMat3ByVec3(void *, void *, void *);
extern s32 (*gBuildRotationMatrixFn)(s16 *, void *);
inline static f32 inline_fn(s16 *arg0)
{
  return *((f32 *) (((char *) arg0) + 8));
}

/* Builds per-bone matrices from packed rotations, composes them with parent matrices, and writes each bone's world position to outPositions. */
void computeBonePositions(s16 *boneList, void *boneStates, void *outPositions, s32 useOffsets)
{
  f32 vec[3];
  struct 
  {
    s16 rot[3];
    s16 pad;
    u8 matrices[0x930];
  } local;
  f32 var_ft0;
  f32 var_fv0;
  f32 var_fv1;
  s16 *bone;
  s32 boneIndex;
  u32 packedRot;
  void *parentMtx;
  void *boneMtx;
  void *outPos;
  void *boneState;
  boneIndex = 0;  {
    u8 * base;
    if ((*(const s16 *) boneList) >= 0)
    { base = local.matrices;
      bone = boneList; outPos = outPositions; boneState = boneStates;
      __repair_rows:
      {
        s32 index;
 do { index = *bone; packedRot = *((u32 *) (((char *) boneState) + 0x14)); boneMtx = base + ((index * 3) * 16); local.rot[0] = (packedRot >> 22) * 4; local.rot[1] = (packedRot >> 10) & 0xffe; local.rot[2] = (packedRot * 2) & 0xffe; gBuildRotationMatrixFn(&local.rot[0], boneMtx); if (boneIndex == 0) { f32 x; f32 y; f32 z; x = *((f32 *) (((char *) boneStates) + 8)); y = *((f32 *) (((char *) boneStates) + 0xc)); z = *((f32 *) (((char *) boneStates) + 0x10)); if (useOffsets == 0) { z = 0.0f; y = 0.0f; x = 0.0f; } *((f32 *) (((char *) boneMtx) + 0x24)) = x; *((f32 *) (((char *) boneMtx) + 0x28)) = y; *((f32 *) (((char *) boneMtx) + 0x2c)) = z; } else { parentMtx = base + ((*((s16 *) (((char *) bone) + 2))) * 0x30); var_fv0 = *((f32 *) (((char *) bone) + 4)); var_fv1 = inline_fn(bone); var_ft0 = *((f32 *) (((char *) bone) + 0xc)); vec[0] = var_fv0; vec[1] = var_fv1; vec[2] = var_ft0; multiplyMat3ByVec3(parentMtx, &vec[0], boneMtx + 0x24); *((f32 *) (((char *) boneMtx) + 0x24)) += *((f32 *) (((char *) parentMtx) + 0x24)); *((f32 *) (((char *) boneMtx) + 0x28)) += *((f32 *) (((char *) parentMtx) + 0x28)); *((f32 *) (((char *) boneMtx) + 0x2c)) += *((f32 *) (((char *) parentMtx) + 0x2c)); MatMul3x3InPlace(parentMtx, boneMtx); } { s32 next; f32 x = *((f32 *) (((char *) boneMtx) + 0x24)); bone += 16; __repair_rows_: { do { do { next = *bone; } while (0); } while (0); } if (0) { goto __repair_rows_; } *((f32 *) (((char *) outPos) + 0)) = x; *((f32 *) (((char *) outPos) + 4)) = *((f32 *) (((char *) boneMtx) + 0x28)); boneState += 4; boneIndex++; *((f32 *) (((char *) outPos) + 8)) = *((f32 *) (((char *) boneMtx) + 0x2c)); outPos += 0xc; if (next >= 0) { goto __repair_rows; } } } while (0);
      }

    }
  }
}
