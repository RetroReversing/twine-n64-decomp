s32 evalMidiModulatorChain(s32, s32);
/* Evaluates the voice's modulator chain at +304 and returns the low 16 bits. */
s32 evalVoiceModulator2(s32 voice) {
    return evalMidiModulatorChain(voice, voice + 304) & 0xFFFF;
}
