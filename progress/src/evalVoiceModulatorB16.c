s32 evalMidiModulatorChain(s32 voice, s32 chain);
/* Evaluates the modulator chain at offset 214 of the voice and returns the low 16 bits. */
s32 evalVoiceModulatorB16(s32 voice) {
    return evalMidiModulatorChain(voice, voice + 214) & 0xFFFF;
}
