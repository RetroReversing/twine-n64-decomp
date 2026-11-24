s32 evalMidiModulatorChain(s32 voice, s32);
/* Evaluates the voice's modulator chain (at +0xE8) and returns the low 16 bits. */
s32 evalVoiceModulatorLow16(s32 voice) {
    return evalMidiModulatorChain(voice, voice + 232) & 0xFFFF;
}
