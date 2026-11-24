s32 evalMidiModulatorChain(s32 arg0, s32);
/* Evaluates the MIDI modulator chain at voice+196 and returns the low 16 bits. */ s32 evalVoiceModulator16(s32 arg0) {
    return evalMidiModulatorChain(arg0, arg0 + 196) & 0xFFFF;
}
