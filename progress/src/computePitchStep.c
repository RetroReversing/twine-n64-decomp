/* Converts a voice's current pitch toward a target note into a 16.16 output step, scaled by the audio output rate. */
extern s32 gPitchUpRatios;
extern s32 gPitchRatioDown;
extern f64 gTwoPow32F64;
extern f64 gTwoPow32F64Eq;
extern s32 gAudioOutputRate;

s32 computePitchStep(s32 targetNote, u32 pitch) {
    f32 fractionF32;
    f32 fractionF32Scaled;
    f32 pitchScaled;
    f64 fractionF64;
    f64 fractionF64Eq;
    s32 fraction;
    s32 fractionEq;
    s32 stepValue;
    u32 noteIndex;
    u32 pitchNote;
    u32 pitchValue;
    f32 stepF32;

    pitchValue = pitch;
    noteIndex = targetNote & 0xFF;
    if (pitchValue == -1U) {
        pitchValue = 0x40005622;
    }
    pitchNote = pitchValue >> 0x18;
    if (noteIndex != pitchNote) {
        fraction = pitchValue & 0xFFFFFF;
        fractionF64 = (f64) fraction;
        if (fraction < 0) {
            fractionF64 += gTwoPow32F64;
        }
        fractionF32 = (f32) fractionF64;
        if (pitchNote < noteIndex) {
            fractionF32Scaled = fractionF32 * *((f32 *)((s8 *)&gPitchUpRatios + ((noteIndex - pitchNote) * 4)));
        } else {
            fractionF32Scaled = fractionF32 * *((f32 *)((s8 *)&gPitchRatioDown + ((pitchNote - noteIndex) * 4)));
        }
    } else {
        fractionEq = pitchValue & 0xFFFFFF;
        fractionF64Eq = (f64) fractionEq;
        if (fractionEq < 0) {
            fractionF64Eq += gTwoPow32F64Eq;
        }
        fractionF32Scaled = (f32) fractionF64Eq;
    }
    stepF32 = (fractionF32Scaled * 4096.0f) / (f32) gAudioOutputRate;
    stepValue = (u32) stepF32;
    return stepValue;
}
