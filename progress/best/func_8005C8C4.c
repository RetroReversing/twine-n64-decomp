extern void *gPlayerActor;
extern s32 gTrackMarkers;
extern void func_8000A894(s32,s32), func_8005B5A8(void);
extern void func_80073AF8(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
extern s32 func_80087100(s32);
void func_8005C8C4(void) {
 s32 r=0; s32 v;
 if (gPlayerActor && (v=*(u16*)((u8*)gPlayerActor+0x78)) < 0x13 && v >= 0x11) {
 r=1;
 if (*(s16*)((u8*)gPlayerActor+0x7c)==0) {
 *(s16*)((u8*)gPlayerActor+0x7c)=1;
 if (*(s32*)((u8*)*(void**)((u8*)gPlayerActor+0x6c)+0x2c) & 0x08000000) {
 *(s32*)((u8*)gPlayerActor+0x60) |= 0x08000000;
 func_8000A894(0x12e,0x08000000);
 func_80073AF8(0,gTrackMarkers,func_80087100(0x160),-1,-1,1,0,0,3,0,0);
 }
 }
 }
 if (!r) func_8005B5A8();
}
