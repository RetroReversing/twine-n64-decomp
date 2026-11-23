typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
} ProbeTriple;
void actorUnlinkFromSurface(void *);
f32 approxDistance(void *, void *);
s32 func_80064370(void *, s32);
s32 func_80073AF8(s32, s32, s32 *, s32, s32, s32, s32, s32, s32, s32, s32);
void listUnlinkFree(s32);
s32 lookupDataEntry(s32);
s32 objectListInsert(void *, s32);
s32 requestSound(s32);
void setActorStatusBits(void *);
extern int sprintf(char *, const char *, ...);
s16 timerGetTotalSeconds(s32 *);
s32 unlinkNode(void *, void *, void *);
extern const s32 D_8010969C;
typedef struct { s16 a; char pad[0x22]; } TrackRec;
extern TrackRec D_8011ED10[];
extern char D_8011EFE0[];
extern char D_8011EFEC[];
extern char D_8011F170[];
extern s32 D_8011F29C;
extern s32 D_8011F2A0;
extern u8 gSceneType;
extern void *sBonusObjectTable[];
extern u8 sProbeActive[];
extern void *sProbeActors[];
extern s32 sProbeHandles[];
extern void *sProbeObjects[];
extern void *sProbeOriginTable[];
extern ProbeTriple sProbePositions[];
extern void *sProbeStates[];
extern s32 sProbeTimer;
extern s32 sProbeTimes[];
extern void *sTrackMarkerTable[];
void func_8011B5F0(void *arg0)
{
  u8 id;
  u16 n;
  void *o;
  void *o0;
  void *p;
  void *q;
  s32 gg;
  void **tab;
  s32 y1;
  s32 a1;
  s32 b1;
  s32 c1;
  s32 d1;
  s32 a2;
  s32 b2;
  s32 c2;
  s32 d2;
  s32 a3;
  s32 b3;
  s32 c3;
  s32 d3;
  id = *((u8 *) (((char *) arg0) + 0x7B));
  *((s32 *) (((char *) arg0) + 0x58)) |= 1;
  o0 = sProbeOriginTable[id];
  n = 0;
  if (o0 != NULL) {
    if (*((f32 *) (((char *) o0) + 0x74)) > 0.0f) {
      p = *((void **) (*((char **) (((char *) o0) + 0x68)) + 4));
      *((ProbeTriple *) (((char *) arg0) + 0x24)) = *((ProbeTriple *) (((char *) p) + 0x9C));
      *((ProbeTriple *) (((char *) arg0) + 0x3C)) = *((ProbeTriple *) (((char *) sProbeOriginTable[id]) + 0x3C));
      if (gSceneType != 3) {
        *((f32 *) (((char *) arg0) + 0x40)) += 1024.0f;
      }
      actorUnlinkFromSurface(arg0);
      objectListInsert(arg0, *((s32 *) (((char *) sProbeOriginTable[id]) + 0x20)));
    }
  } else {
    for (n = 0; n < 4; n++) {
      o = sBonusObjectTable[n];
      if (o == NULL) {
        continue;
      }
      if ((*((u16 *) (((char *) o) + 0x78)) == 0x4D) | (*((u16 *) (((char *) o) + 0x78)) == 0x61)) {
        continue;
      }
      if (!(approxDistance(((char *) o) + 0x24, ((char *) arg0) + 0x24) < 2.0f)) {
        continue;
      }
      q = *((void **) (((char *) sBonusObjectTable[n]) + 0x6C));
      if (q != NULL && *((u8 *) (*((char **) (((char *) q) + 0xB4)) + 0x12)) == id) {
        if (sProbeActive[id] != 0) {
          continue;
        }
        a1 = lookupDataEntry((-(id != 0) & 0x6F) | 0x6E);
        b1 = lookupDataEntry(0x28E);
        d1 = lookupDataEntry(gSceneType == 2 ? 0x28F : 0x290);
        sprintf(D_8011F170, D_8011EFE0, id == 0 ? 0xC : 5, a1, b1, d1);
        requestSound(0x219);
        func_80073AF8(0, D_8010969C, (s32 *) D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
        sProbeActive[id] = 1;
        *((ProbeTriple *) (((char *) arg0) + 0x30)) = sProbePositions[id];
        *((ProbeTriple *) (((char *) arg0) + 0x24)) = *((ProbeTriple *) (((char *) arg0) + 0x30));
        listUnlinkFree(sProbeHandles[id]);
        sProbeHandles[id] = 0;
        actorUnlinkFromSurface(arg0);
        objectListInsert(arg0, *((s32 *) (((char *) sProbeObjects[id]) + 0x20)));
        *((s32 *) (((char *) arg0) + 0x3C)) = 0;
        *((f32 *) (((char *) arg0) + 0x40)) = 0.0f;
        *((s32 *) (((char *) arg0) + 0x44)) = 0;
        setActorStatusBits(sProbeActors[id]);
        *((s32 *) (((char *) sProbeStates[id]) + 0x28)) = (*((s32 *) (((char *) sProbeStates[id]) + 0x28)) & ~0xFC) | 0x1C;
        return;
      }
      a2 = lookupDataEntry((-(id == 0) & 0x6F) | 0x6E);
      b2 = lookupDataEntry(0x28C);
      c2 = lookupDataEntry((-(id != 0) & 0x6F) | 0x6E);
      d2 = lookupDataEntry(gSceneType == 2 ? 0x28F : 0x290);
      sprintf(D_8011F170, D_8011EFEC, id == 0 ? 5 : 0xC, a2, b2, id == 0 ? 0xC : 5, c2, d2);
      func_80073AF8(0, D_8010969C, (s32 *) D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C);
      sProbeHandles[id] = requestSound(0x21E);
      sProbeActive[id] = 0;
      sProbeOriginTable[id] = sBonusObjectTable[n];
      func_80064370(arg0, n);
      *((s32 *) (((char *) sProbeStates[id]) + 0x28)) = (*((s32 *) (((char *) sProbeStates[id]) + 0x28)) & ~0xFC) | 0x10;
      tab = sTrackMarkerTable;
      y1 = *((s8 *) (((char *) q) + 0x182));
      unlinkNode(sProbeStates[id], tab[D_8011ED10[id].a], tab[y1]);
      D_8011ED10[id].a = (s16) ((s8) ((u8) (*((s8 *) (((char *) q) + 0x182)))));
      return;
    }
    if (sProbeOriginTable[id] == 0 && sProbeActive[id] == 0 && (u32) (timerGetTotalSeconds(&sProbeTimer) - sProbeTimes[id]) >= 10) {
      if (sProbeActive[id] == 0) {
        a3 = lookupDataEntry((-(id != 0) & 0x6F) | 0x6E);
        b3 = lookupDataEntry(gSceneType == 2 ? 0x28F : 0x290);
        c3 = lookupDataEntry(0x291);
        sprintf(D_8011F170, D_8011EFE0, id == 0 ? 0xC : 5, a3, b3, c3);
        { const s32 *state = &D_8010969C; func_80073AF8(0, *state, (s32 *) D_8011F170, -1, -1, 1, 0, 0, 6, 0, 0x3C); }
      }
      *((ProbeTriple *) (((char *) arg0) + 0x24)) = sProbePositions[id];
      *((ProbeTriple *) (((char *) arg0) + 0x30)) = sProbePositions[id];
      sProbeActive[id] = 1;
      sProbeOriginTable[id] = 0;
      listUnlinkFree(sProbeHandles[id]);
      sProbeHandles[id] = 0;
      actorUnlinkFromSurface(arg0);
      objectListInsert(arg0, *((s32 *) (((char *) sProbeObjects[id]) + 0x20)));
      setActorStatusBits(sProbeActors[id]);
    }
  }
}
