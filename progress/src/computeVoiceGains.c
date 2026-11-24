extern f32 gVolumeCurve[], gVolumeCurveNext[], gPanCurve[];
/* Converts volume, pan and reverb inputs into 16-bit mixer gains by interpolating
 * the volume and pan curve tables. */
void computeVoiceGains(s16 *leftGain, s16 *rightGain, u32 volume, u32 pan, u32 fade, s16 *centerGain, u32 reverb, s16 *reverbGain) {
 volatile u32 pad[4]; f32 frac,vol,fadeGain,gain,panGain; u32 i,j;
 if(volume>0x7f0000) volume=0x7f0000;
 i=volume>>16;
 frac=(f32)(volume&0xffff)*0.000015258789f;
 vol=(1.0f-frac)*gVolumeCurve[i]+frac*gVolumeCurveNext[i];
 i=fade>>22;
 frac=(f32)(fade&0x3fffff)*0.00000023841858f;
 gain=(1.0f-frac)*gPanCurve[i]+frac*gPanCurve[i+1];
 *centerGain=(s32)(vol*gain*23195.76f);
 fade=0x800000-fade;
 if(fade>0x7fffff) fade=0x7f0000;
 i=fade>>22;
 frac=(f32)(fade&0x3fffff)*0.00000023841858f;
 fadeGain=vol*((1.0f-frac)*gPanCurve[i]+frac*gPanCurve[i+1]);
 if(pan==0x800000) { *leftGain=(s32)(fadeGain*23195.76f); panGain=fadeGain*-23195.76f; *rightGain=(s32)panGain; }
 else {
 i=pan>>22; frac=(f32)(pan&0x3fffff)*0.00000023841858f;
 gain=((1.0f-frac)*gPanCurve[i]+frac*gPanCurve[i+1]); *leftGain=(s32)(fadeGain*gain*32767.0f);
 pan=0x800000-pan; if(pan>0x7fffff) pan=0x7f0000;
 i=pan>>22; frac=(f32)(pan&0x3fffff)*0.00000023841858f;
 gain=((1.0f-frac)*gPanCurve[i]+frac*gPanCurve[i+1]); *rightGain=(s32)(fadeGain*gain*32767.0f);
 }
 if(reverb>0x7f0000) reverb=0x7f0000;
 i=reverb>>16; frac=(f32)(reverb&0xffff)*0.000015258789f;
 vol=(1.0f-frac)*gVolumeCurve[i]+frac*gVolumeCurveNext[i]; *reverbGain=(s32)(vol*23195.76f);
}
