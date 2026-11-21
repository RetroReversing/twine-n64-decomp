void *func_80016410();
s32 func_80016990();
s32 func_80044670();
s32 randomIntBelow();
f32 randomFloatScaled(f32);
f32 randomFloatMinusOffset(f32, f32);
void func_80060D74(void *arg0) {
 struct Vec3 { f32 x,y,z; } pos;
 void *temp_s0, *temp_s3, *temp_v0;
 temp_s3 = *(void **)((char *)arg0 + 0x6C);
 if ((*(s32 *)((char *)arg0 + 0x58) & 4 || *(s32 *)((char *)arg0 + 0x60) & 0x3000) && randomIntBelow(*(s16 *)((char *)arg0 + 0x7C)) == 0) {
 pos = *(struct Vec3 *)((char *)arg0 + 0x24);
 pos.x += randomFloatMinusOffset(2.0f,1.0f) * *(f32 *)temp_s3;
 pos.z += randomFloatMinusOffset(2.0f,1.0f) * *(f32 *)temp_s3;
 temp_v0 = func_80016410(0xC, &pos, 0);
 if (temp_v0 != 0) {
 temp_s0 = *(void **)((char *)temp_v0 + 0x6C);
 func_80044670(temp_v0, 2, 0x1B);
 *(f32 *)((char *)temp_s0 + 4) = *(f32 *)((char *)temp_s3 + 4);
 *(f32 *)((char *)temp_s0 + 8) = -randomFloatScaled(0.32666668f);
 *(s16 *)((char *)temp_v0 + 0x78) = 0x65;
 *(s8 *)((char *)temp_v0 + 0x7F) = 0;
 *(s8 *)((char *)temp_v0 + 0x80) = 0;
 *(s8 *)((char *)temp_v0 + 0x81) = 0;
 *(s8 *)((char *)temp_v0 + 0x82) = 0x40;
 func_80016990(temp_v0, *(s32 *)((char *)arg0 + 0x20));
 }
 }
 *(s32 *)((char *)arg0 + 0x60) = 0;
}
