typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *gAudioVoiceTable;
extern u16 sAudioVoiceCount;
void latchAudioVoiceTimes(void) {
 s32 i; E8B1C0 *e; E8B1C0 *p;
 i=0; e=gAudioVoiceTable;
 if(i<sAudioVoiceCount) do { p=e; if(p->active) {p->prev=p->now; p->now=p->time;} i++; e++; } while(i<sAudioVoiceCount);
}
extern s32 sCurrentDistanceSoundId;
void startDistanceSound(void);
void restartDistanceSound(void) { sCurrentDistanceSoundId=-1; startDistanceSound(); }
extern s8 D_80102EDF, D_800CA310;
extern s32 D_80102EEC, gSceneLoaded;
void resetSlotsAndRefreshAll(void);
void requestSceneChange(s8 arg0) { resetSlotsAndRefreshAll(); D_80102EDF=arg0; D_80102EEC=1; gSceneLoaded=0; D_800CA310=0; }
extern char D_80115092[];
void setBonusSlotState(s32,s32,s32);
void clearBonusSlotValue(s32 arg0) { s16 *p=(s16 *)(D_80115092+arg0*0xa0); s32 old=*p; *p=-1; setBonusSlotState(arg0,old, -1); }
