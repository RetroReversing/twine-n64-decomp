s32 setVoiceChainPan();
s32 setSoundChainRearMix();
s32 setVoiceChainParam14();
s32 setVoiceChainParam7();
/* Starts a sound voice: converts float volume, pan, effect level and pitch to MIDI-style ranges and applies them to the voice. */ void soundVoiceStart(void *sound, f32 volume, f32 pan, s32 unused, f32 fxLevel, f32 pitch)
{
  s32 h;
  u32 v, w;
  u8 b1, b2, b3;
  u32 a4;
  u16 r;
  u32 r1;
  h = *(s32 *)((char *)sound + 0x34);
  if (*(s32 *)((char *)sound + 8) & 0x100000) {
    v = (u32)(*(f32 *)((char *)sound + 0x40) * volume * 127.0f);
    v &= 0xFF;
    b1 = v;
    if (v >= 0x80) goto cap;
  } else {
    w = (u32)(volume * 127.0f);
    w &= 0xFF;
    if (w < 0x80) b1 = w; else {
cap:
      b1 = 0x7F;
    }
  }
  setVoiceChainParam7(h, b1);
  v = (u32)((pan + 1.0f) * 64.0f);
  v &= 0xFF;
  b2 = v;
  if (v >= 0x80) b2 = 0x7F;
  setVoiceChainPan(h, b2);
  v = (u32)((1.0f - fxLevel) * 64.0f);
  v &= 0xFF;
  b3 = v;
  if (v >= 0x80) b3 = 0x7F;
  setSoundChainRearMix(h, b3);
  w = (u32)(pitch * 8192.0f);
  if (w >= 0x4000) r = w = 0x3FFF; else r = w;
  setVoiceChainParam14(h, r);
}
