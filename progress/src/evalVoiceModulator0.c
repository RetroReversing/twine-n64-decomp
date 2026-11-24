s32 evalMidiModulatorChain(s32, s32);
/* Evaluates the first MIDI modulator chain of a voice (offset 268); returns the low 16 bits. */
s32 evalVoiceModulator0(s32 voice) { return evalMidiModulatorChain(voice, voice + 268) & 0xffff; }
/* Same for the chain at offset 286. */
s32 evalVoiceModulator1(s32 voice) { return evalMidiModulatorChain(voice, voice + 286) & 0xffff; }
/* Same for the chain at offset 304. */
s32 evalVoiceModulator2(s32 voice) { return evalMidiModulatorChain(voice, voice + 304) & 0xffff; }
/* Same for the chain at offset 322. */
s32 evalVoiceModulator3(s32 voice) { return evalMidiModulatorChain(voice, voice + 322) & 0xffff; }
