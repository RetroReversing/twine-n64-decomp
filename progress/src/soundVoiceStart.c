s32 func_8008E4A8();
s32 func_8008E594();
s32 func_8008E680();
s32 func_8008E96C();
void soundVoiceStart(void *arg0, f32 arg1, f32 arg2, s32 arg3, f32 arg4, f32 arg5)
{
  s32 h;
  u32 v, w;
  u8 b1, b2, b3;
  u32 a4;
  u16 r;
  u32 r1;
  h = *(s32 *)((char *)arg0 + 0x34);
  if (*(s32 *)((char *)arg0 + 8) & 0x100000) {
    v = (u32)(*(f32 *)((char *)arg0 + 0x40) * arg1 * 127.0f);
    v &= 0xFF;
    b1 = v;
    if (v >= 0x80) goto cap;
  } else {
    w = (u32)(arg1 * 127.0f);
    w &= 0xFF;
    if (w < 0x80) b1 = w; else {
cap:
      b1 = 0x7F;
    }
  }
  func_8008E96C(h, b1);
  v = (u32)((arg2 + 1.0f) * 64.0f);
  v &= 0xFF;
  b2 = v;
  if (v >= 0x80) b2 = 0x7F;
  func_8008E4A8(h, b2);
  v = (u32)((1.0f - arg4) * 64.0f);
  v &= 0xFF;
  b3 = v;
  if (v >= 0x80) b3 = 0x7F;
  func_8008E594(h, b3);
  w = (u32)(arg5 * 8192.0f);
  if (w >= 0x4000) r = w = 0x3FFF; else r = w;
  func_8008E680(h, r);
}
