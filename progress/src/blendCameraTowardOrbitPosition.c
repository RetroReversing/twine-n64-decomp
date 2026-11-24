f32 sinAngle(f32); f32 cosAngle(f32);
extern f32 D_800C9D44, D_800C9D48;
/* Moves the camera's X/Z position toward a point orbiting behind the target at the given distance, by the blend factor. */ void blendCameraTowardOrbitPosition(void *targetPos, void *targetRot, void *cameraState, f32 blend, f32 extraDistance) {
 f32 temp_fs0, temp_fs1, temp_ft0, temp_fv1;
 temp_fs1 = extraDistance + D_800C9D48;
 temp_fs0 = *(f32 *)targetPos - temp_fs1 * sinAngle(*(f32 *)((char *)targetRot + 4) + D_800C9D44 * 651.8986f);
 temp_fv1 = *(volatile f32 *)((char *)cameraState + 0x18) + ((*(f32 *)((char *)targetPos + 8) - temp_fs1 * cosAngle(*(f32 *)((char *)targetRot + 4) + D_800C9D44 * 651.8986f) - *(f32 *)((char *)cameraState + 0x18)) * blend);
 temp_ft0 = *(f32 *)((char *)cameraState + 0x10);
 *(f32 *)((char *)cameraState + 0x18) = temp_fv1;
 *(f32 *)((char *)cameraState + 0x10) = temp_ft0 + ((temp_fs0 - temp_ft0) * blend);
}
