extern void (*gAnimPoseExtraLerpCallback)(), (*gBuildRotationMatrixFn)(), (*gTransformVertexFn)();
extern void vecSlerp(),buildRotationMatrixS16(),eulerToQuaternion(),quatSlerp(),eulerAnglesToMatrix(),eulerToQuat();
/* Selects rotation helpers: mode 1 uses quaternion slerp and Euler-to-quaternion; otherwise the vector/matrix variants. */ void setRotationInterpolationMode(s32 mode) {
  switch(mode) {
  default:
  case 0:
    gAnimPoseExtraLerpCallback=vecSlerp;
    gBuildRotationMatrixFn=buildRotationMatrixS16;
    gTransformVertexFn=eulerToQuaternion;
    break;
  case 1:
    gAnimPoseExtraLerpCallback=quatSlerp;
    gBuildRotationMatrixFn=eulerAnglesToMatrix;
    gTransformVertexFn=eulerToQuat;
    break;
  }
}
