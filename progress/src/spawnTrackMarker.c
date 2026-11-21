extern s32 func_80015F0C();
extern s32 func_800165E0(s32, s32);
extern s32 sTrackMarkerTable[];
s32 spawnTrackMarker(s32 arg0) {
 s32 v = func_80015F0C();
 if (v == 0) return 0;
 func_800165E0(v, sTrackMarkerTable[arg0]);
 return v;
}
