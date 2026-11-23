s32 func_800083DC(f32 *, f32, f32, f32, f32);
s8 IsSphereVisible(f32 *, s32, void *, void *);
s8 func_800158A4(void *, f32 *, s32, s32 *, s32, s32, s32, s32, s32);
s32 func_80032630(s32);
s32 func_80034928(void *, s32);
f32 func_800357C8(f32);
s32 func_80039068();
s32 func_80043FA0(void *);
s32 *func_8004478C(s32, s32);
s32 vec3Add(f32 *, f32 *, f32 *);
s32 func_800452E0(f32 *, f32 *, f32 *);
f32 approxDistance(void *, void *);
f32 approximate_hypot2(f32, f32);
s32 func_80047B14(f32 *, s32, f32 *);
s32 rotateVec3ByMat3(void *, f32 *);
s32 guMtxF2L(f32 *, s32);
s32 func_800A3840(f32 *, f32 *, f32 *);
s32 func_800A3940(f32 *, f32, f32, f32);
s32 guTranslateF(f32 *, f32, f32, f32);
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct RS { u8 p0[0x74C]; s32 s74c; } RS;
extern s32 D_800B1CA8;
extern u32 sMatrixPoolLimit;
extern s32 D_800C0670[];
extern f32 D_800C0698[];
extern u8 D_800C06C4[];
extern u8 D_800C06D0[];
extern u8 D_800C06DC[];
extern u8 D_800C06E8[];
extern u8 D_800C2B40;
extern s32 D_801032A0;
typedef struct Ent {
  u8 p0[0x14];
  struct Ent *next;
  u8 p18[0xC];
  f32 pos[3];
  u8 p30[0xC];
  s32 s3C;
  u8 p40[0xC];
  s32 s4C;
  u8 p50[4];
  u8 b54;
  u8 b55;
  u8 p56[2];
  u32 flags;
} Ent;
typedef struct Obj {
  u8 p0[0x14];
  Ent *first;
  u8 p18[4];
  struct Obj *next;
} Obj;
typedef struct Cam {
  u8 p0[0x10];
  f32 pos[3];
  f32 p1C[3];
  u8 p28[0x90];
  f32 mB8[3];
  u8 pC4[0x30];
  s32 sF4;
  u8 pF8[8];
  u32 flags;
  u8 p104[0x20];
  f32 fade;
} Cam;
extern Obj *gObjectListHead;
extern u32 sMatrixPoolUsed;
extern u8 gTrackMarkerDone[];
extern f32 sParentMatrixF[];
extern Gfx *D_80109CB8;
extern s32 D_8010A4D8;
extern u32 D_8010A924;
extern s32 sCurrentMatrixSlot;
extern s32 gRenderMode;
extern f32 sObjectMatrixF[];
extern Gfx *sDisplayListCursor;
extern RS *sRenderState;

void func_800358D4(Cam *arg0)
{
  f32 v28[4];
  s32 *tbl[5];
  s32 buf50[4];
  f32 v60[4];
  f32 v70[4];
  f32 v80[4];
  f32 scale;
  u8 r, g, b;
  Obj *obj;
  Ent *e;
  f32 zero;
  f32 dist, t, d, ratio;
  s32 i;
  u32 rs;

  obj = gObjectListHead;
  if (gRenderMode != 2) {
    gRenderMode = 2;
    func_80039068();
  }
  if (D_8010A924 != 7) {
    Gfx *gp;
    D_8010A924 = 7;
    gp = sDisplayListCursor;
    sDisplayListCursor = gp + 1;
    gp->w0 = 0xDE000000;
    gp->w1 = (u32)&D_800B1CA8;
  }
  if (D_801032A0 != 2) {
    Gfx *gp;
    D_801032A0 = 2;
    gp = sDisplayListCursor;
    sDisplayListCursor = gp + 1;
    gp->w0 = 0xFC419883;
    gp->w1 = 0xFF32FF7F;
  }
  if (arg0->flags & 1) {
    b = 0xFF;
    scale = func_800357C8(0.05f) + 1.0f;
    g = 0xFF;
    r = 0xFF;
  } else if (!(arg0->flags & 4)) {
    b = 0;
    scale = func_800357C8(0.1f) + 3.0f;
    r = 0;
    g = 0xFF;
  } else {
    return;
  }
  for (; obj != NULL; obj = obj->next) {
    for (e = obj->first; e != NULL; e = e->next) {
      if (!((e->flags >> 2) & 1)) continue;
      if (e->b54 != 0 && gTrackMarkerDone[e->b54] == e->b55) continue;
      if (!IsSphereVisible(e->pos, e->s4C, obj, arg0)) continue;
      func_80034928(arg0, 2);
      func_800452E0(e->pos, arg0->p1C, v28);
      rotateVec3ByMat3(arg0->mB8, v28);
      if (!(v28[2] > 0.0f)) continue;
      if (sMatrixPoolUsed >= sMatrixPoolLimit) return;
      sMatrixPoolUsed++;
      sCurrentMatrixSlot = sRenderState->s74c + (sMatrixPoolUsed << 6);
      func_800083DC(sObjectMatrixF, v28[0] * 64.0f, v28[1] * 64.0f, v28[2] * 64.0f, scale);
      guMtxF2L(sObjectMatrixF, sCurrentMatrixSlot);
      sDisplayListCursor->w0 = 0xDA380003;
      sDisplayListCursor->w1 = sCurrentMatrixSlot - 0x80000000;
      sDisplayListCursor++;
      sDisplayListCursor->w0 = 0xFA000000;
      sDisplayListCursor->w1 = (r << 24) | (g << 16) | (b << 8) | 0xFF;
      sDisplayListCursor++;
      func_80032630(e->s3C);
      if (!((e->flags >> 2) & 2)) continue;
      tbl[0] = func_8004478C(1, 0x18A);
      tbl[1] = func_8004478C(2, 0x18A);
      tbl[2] = func_8004478C(3, 0x18A);
      tbl[3] = func_8004478C(4, 0x18A);
      tbl[4] = func_8004478C(5, 0x18A);
      if (!func_800158A4(arg0->pos, e->pos, arg0->sF4, buf50, 0, 0, 0, 1, 0)) continue;
      dist = approximate_hypot2(v28[0], v28[1]);
      if (!(dist < 127.0f)) continue;
      ratio = 25.0f / v28[2];
      zero = 0.0f;
      v60[0] = zero;
      v60[1] = zero;
      v60[2] = 25.0f;
      v28[0] *= ratio;
      v28[1] *= ratio;
      v28[2] *= ratio;
      func_800452E0(v60, v28, v70);
      for (i = 0; i < 10; i++) {
        func_80047B14(v70, D_800C0670[i], v80);
        vec3Add(v28, v80, v80);
        if (i == 0) {
          dist = approximate_hypot2(v80[0], v80[1]);
          t = (16.0f - dist) * 0.03125f;
          if (arg0->flags & 2) {
            d = approxDistance(arg0->pos, e->pos) * 0.125f;
            if (d > 1.0f) t /= d;
          }
          if (arg0->fade < t) arg0->fade = t;
          if (arg0->fade > 1.0f) arg0->fade = 1.0f;
          if (arg0->fade < 0.0f) arg0->fade = 0.0f;
          if (arg0->flags & 2) goto next_entity;
        }
        if (dist < 127.0f) {
          f32 sc;
          s32 *ta;
          sc = D_800C0698[i];
          if (sMatrixPoolUsed >= sMatrixPoolLimit) return;
          sMatrixPoolUsed++;
          sCurrentMatrixSlot = sRenderState->s74c + (sMatrixPoolUsed << 6);
          guTranslateF(sObjectMatrixF, v80[0] * 64.0f, v80[1] * 64.0f, v80[2] * 64.0f);
          func_800A3940(sParentMatrixF, sc, sc, sc);
          func_800A3840(sParentMatrixF, sObjectMatrixF, sObjectMatrixF);
          guMtxF2L(sObjectMatrixF, sCurrentMatrixSlot);
          {
          Gfx *p1;
          Gfx *p2;
          p1 = D_80109CB8++;
          p1->w0 = 0xDA380003;
          p1->w1 = sCurrentMatrixSlot - 0x80000000;
          p2 = D_80109CB8++;
          p2->w0 = 0xFA000000;
          p2->w1 = (D_800C06D0[i] << 24) | (D_800C06DC[i] << 16) | (D_800C06E8[i] << 8) | ((u32)zero & 0xFF);
          }
          ta = tbl[D_800C06C4[i]];
          if (*ta != 0 || (func_80043FA0(ta), *tbl[D_800C06C4[i]] != 0)) {
            u8 *q = (u8 *)tbl[D_800C06C4[i]];
            Gfx *gp;
            if (!(q[0x46] & 0x80)) q[0x46] = D_800C2B40;
            gp = D_80109CB8;
            D_80109CB8 = gp + 1;
            gp->w0 = 0xDE000000;
            gp->w1 = *tbl[D_800C06C4[i]];
          }
        }
      }
      {
      Gfx *gp = D_80109CB8;
      D_80109CB8 = gp + 1;
      gp->w0 = 0xFA000000;
      gp->w1 = -1;
      }
    next_entity: ;
    }
  }
  func_80034928(arg0, D_8010A4D8);
}
