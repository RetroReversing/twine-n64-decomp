typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *gAudioVoiceTable; extern u16 sAudioVoiceCount;
void latchAudioVoiceTimes(void) { s32 i=0; E8B1C0 *e; if(i<sAudioVoiceCount) { e=gAudioVoiceTable; do {if(e->active){e->prev=e->now;e->now=e->time;} i++;e++;}while(i<sAudioVoiceCount);}}
s32 ctypeToUpper(s32);
u8 *func_800AB9B0(u8 *arg0) { u8 *p=arg0; while (*p) { *p=ctypeToUpper((s8)*p); p++; } return arg0; }
typedef union { f64 d; u32 w[2]; } Bits;
/* frexp: splits value into a mantissa in [0.5, 1) and a power-of-two exponent stored in the e out-parameter. */ f64 libmFrexp(f64 value, s32 *e) { u32 *p = (u32 *)&value; if (value==0.0) {*e=0; return 0.0;} *e=((*p>>20)&0x7ff)-0x3fe; *p=(*p&0x800fffff)|0x3fe00000; return value; }
extern u8 gDemoRecordingActive;
void setSaveSlotEntryParams(s32,s32,s32);
void setSaveSlotEntryPercent(s32 a,s32 b,s32 c) { if(!gDemoRecordingActive) setSaveSlotEntryParams(a&255,b&65535,((c*255)/100)&255); }
