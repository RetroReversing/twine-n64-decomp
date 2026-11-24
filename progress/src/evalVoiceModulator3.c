s32 evalMidiModulatorChain(s32, s32);
s32 evalVoiceModulator0(s32 a) { return evalMidiModulatorChain(a,a+268)&0xffff; }
s32 evalVoiceModulator1(s32 a) { return evalMidiModulatorChain(a,a+286)&0xffff; }
s32 evalVoiceModulator2(s32 a) { return evalMidiModulatorChain(a,a+304)&0xffff; }
/* Evaluates the voice's fourth modulator chain (offset 322, 18-byte stride) and returns the low 16 bits. */ s32 evalVoiceModulator3(s32 a) { return evalMidiModulatorChain(a,a+322)&0xffff; }
