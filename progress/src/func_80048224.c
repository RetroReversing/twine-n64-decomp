f32 sinAngle(f32); f32 cosAngle(f32);
extern f32 D_800C9D44, D_800C9D48;
void func_80048224(void *arg0, void *arg1, void *arg2, f32 arg3, f32 arg4) {
 f32 temp_fs0, temp_fs1, temp_ft0, temp_fv1;
 temp_fs1 = arg4 + D_800C9D48;
 temp_fs0 = *(f32 *)arg0 - temp_fs1 * sinAngle(*(f32 *)((char *)arg1 + 4) + D_800C9D44 * 651.8986f);
 temp_fv1 = *(volatile f32 *)((char *)arg2 + 0x18) + ((*(f32 *)((char *)arg0 + 8) - temp_fs1 * cosAngle(*(f32 *)((char *)arg1 + 4) + D_800C9D44 * 651.8986f) - *(f32 *)((char *)arg2 + 0x18)) * arg3);
 temp_ft0 = *(f32 *)((char *)arg2 + 0x10);
 *(f32 *)((char *)arg2 + 0x18) = temp_fv1;
 *(f32 *)((char *)arg2 + 0x10) = temp_ft0 + ((temp_fs0 - temp_ft0) * arg3);
}
