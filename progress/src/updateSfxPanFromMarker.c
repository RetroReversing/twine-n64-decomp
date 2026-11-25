s32 angleDelta12(s32,s32); void getAngleToMarker(void*,void*,s32*); s32 setSfxRearMix(s32,s32); s32 setSfxPitch(s32,s32); s32 setSfxPan(s32,s32); extern s32 sDistanceSoundsActive; extern u8 gOptionChoice[];
/* Pans and pitches a playing sound from the angle between listener and marker, honouring the audio-mode option. */
void updateSfxPanFromMarker(s32 sfxHandle, s32 marker, void * listener, f32 pitchScale) {
s32 angle,panRaw,pan,pan2,rearAmount,pitchValue; f32 pitchFloat,clampedPitch;
clampedPitch=pitchScale;
if(sDistanceSoundsActive!=0) if(sfxHandle!=-1) {
do { getAngleToMarker(marker,listener,&angle); } while (0);
pan2=angleDelta12(angle,(s32)(*(f32*)((s8*)marker+0x38)*651.8986f))*0x7F;
if(pan2<0)pan2+=0x7FF;
pan=pan2>>11; panRaw=pan;
if(pan>=0x40)pan=0x7F-pan;
if(pan< -0x3F)pan=-0x7F-pan;
pan+=0x40; if(panRaw>0){rearAmount=panRaw;} else {rearAmount=-panRaw;}

if(gOptionChoice[0]!=0){
    do { setSfxPan(sfxHandle,pan&0xFF); } while (0);
    if(gOptionChoice[0]>=2U) {
        setSfxRearMix(sfxHandle,rearAmount&0xFF);
        goto done;
    }
} else {
    setSfxPan(sfxHandle,0x40);
}
setSfxRearMix(sfxHandle,0);
done:;
if(clampedPitch>16.0f)clampedPitch=16.0f;
pitchFloat=(clampedPitch*512.0f)+8192.0f;
pitchValue=(u32)pitchFloat;
setSfxPitch(sfxHandle,pitchValue&0xFFFF);
}
}
