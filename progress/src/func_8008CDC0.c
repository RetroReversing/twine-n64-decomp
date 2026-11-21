typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *gAudioVoiceTable; extern u16 sAudioVoiceCount;
void func_8008B1C0(void) { s32 i; E8B1C0 *e,*p; i=0; e=gAudioVoiceTable; if(i<sAudioVoiceCount) do { p=e; if(p->active) {p->prev=p->now;p->now=p->time;} i++;e++; } while(i<sAudioVoiceCount); }
extern f32 sqrtf(f32);
void func_8009532C(f32 *a){ f32 x=a[0],y=a[1],z=a[2]; f32 v=sqrtf(x*x+y*y+z*z); a[0]=x/v;a[1]=a[1]/v;a[2]=a[2]/v; }
extern s32 D_800E4290;
void func_8008CDC0(s32 a,s32 b){unsigned int n=b;if((n&255)==255)n=8; *((s32 *)((s8 *)&D_800E4290+((n&255)*4)))=(((unsigned)a<<3)*3<<9)/240;}
s32 playDistanceSound(u16,f32,s32); s32 randomIntBelow(s32); f32 findNearestTrackMarker(s32 *); extern s32 D_800CE700;
void func_80084E10(void){s32 sp10; f32 f=findNearestTrackMarker(&sp10);playDistanceSound(*((u16 *)((s8 *)&D_800CE700+randomIntBelow(2)*2)),f,255);}
