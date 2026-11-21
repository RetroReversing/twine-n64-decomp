typedef struct {u8 pad[0x1e];s16 field_1e;u8 pad20[8];u32 hi:16;u32 b:4;u32 c:4;u32 lo:8;} Obj15F0C;
Obj15F0C *func_80015F0C(void); void func_800165E0(s32 *,s32 *);
extern s32 gTrackMarkers;
s32 spawnTrackMarker(s32 arg0) { Obj15F0C *obj=func_80015F0C(); if(obj==0) return 0; {func_800165E0((s32 *)obj,*(s32 *)((u8 *)&gTrackMarkers+arg0*4)); return (s32)obj;} return 0;}
