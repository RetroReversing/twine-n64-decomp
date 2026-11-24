s8 sphereContainsPoint(void *, void *, f32);
s32 buildPlaneFromPoints(f32 *, void *, void *, void *);
s32 buildRotationMatrix(s16 *, f32 *);
s32 buildRotationMatrixCopy(s16 *, f32 *);
s32 buildRotationMatrixS16(s16 *, f32 *);
s32 buildRotationMatrixS16Copy(s16 *, f32 *);
f32 func_80047AB0(f32 *, f32 *);
s8 isPointOutsideActorSphere(void *, void *, f32);
s32 computeGridCellMask(void *, f32 *, f32 *);
f32 sqrtf32(f32);
s32 rotateVec3InPlaceByMat3(f32 *, f32 *);
s32 rotateVec3ByMat3(f32 *, f32 *);
f32 segmentClosestPoint(f32 *, void *, void *, f32 *);
s8 triangleContainsPoint(void *, void *, void *, void *, f32 *);
extern f64 D_800D3E70;
extern f64 D_800D3E78;
extern f64 D_800D3E80;
extern f64 D_800D3E88;
extern u16 gSurfaceQueryStamp;

typedef struct { f32 x; f32 y; f32 z; } SurfaceVec3;

typedef struct SurfaceMesh {
    u8 pad0[0x18];
    f32 minX, maxX, minY, maxY, minZ, maxZ;
    u8 pad30[4];
    SurfaceVec3 *verts;
    u16 *cellMasks;
    void *tris;
    u16 count;
    u8 pad42[6];
    u8 flags;
} SurfaceMesh;

typedef struct SurfaceActor {
    struct SurfaceActor *next;
    u8 pad4[0x20];
    f32 pos[3];
    u8 pad30[0xC];
    f32 rot[3];
    u8 pad48[0x10];
    s32 flags;
    s32 flags2;
    s32 hitMask;
    u8 pad64[0xC];
    SurfaceMesh *mesh;
} SurfaceActor;

typedef struct SurfaceCell {
    u8 pad0[0x58];
    struct SurfaceNode *list;
    u8 pad5C[4];
    u16 stamp;
} SurfaceCell;

typedef struct SurfaceObj {
    SurfaceActor *actors;
    u8 pad4[0x10];
    struct SurfaceObj *next;
    u8 pad18[8];
    SurfaceCell *cell;
    f32 pos[3];
    f32 rot[3];
    SurfaceMesh *mesh;
    u8 sphere[0x10];
    s32 flags;
    u8 pad54[8];
    u32 flags2;
} SurfaceObj;

typedef struct SurfaceNode {
    struct SurfaceNode *next;
    SurfaceObj *obj;
    SurfaceObj *owner;
} SurfaceNode;

#define POS scratch.vsp18
#define MAT scratch.vsp28.values
#define MAT2 scratch.vsp58.values
#define ANG scratch.vsp88.values
#define PLANE scratch.vsp90.values
#define CLOSE scratch.vspA0.values
#define E0 scratch.vspB0.values
#define E1 scratch.vspC0.values
#define E2 scratch.vspD0.values
#define CORR scratch.correction.values
#define CORR8 scratch.vspF0.values
#define POS2 scratch.vsp28.values
#define VMAX scratch.vsp38.values
#define CLOSE2 scratch.chosenPoint.values
#define MATA scratch.vspA0.values
#define PLANE2 scratch.vspC8.values
#define VMIN scratch.boundsMin.values
#define MATB scratch.vsp100.values
#define F0 scratch.vsp128.values
#define F1 scratch.vsp138.values
#define F2 scratch.vsp148.values
#define CORRB scratch.vsp158.values
#define CORRB8 scratch.vsp168.values

/* Pushes a sphere (pos, radius) out of nearby actor and object collision meshes, accumulating the correction into pos; returns 1 if any surface was hit. */
s8 pushSphereOutOfSurfaces(SurfaceObj *startObj, SurfaceVec3 *pos, SurfaceVec3 *out, f32 radius, s32 hitFlags, s32 *outKind, SurfaceObj **outObj, SurfaceActor *ignore)
{
  union 
  {
    f32 vsp18[3];
    struct 
    {
      u8 pad[0x10];
      f32 values[9];
    } vsp28;
    struct 
    {
      u8 pad[0x20];
      f32 values[3];
    } vsp38;
    struct 
    {
      u8 pad[0x40];
      f32 values[9];
    } vsp58;
    struct 
    {
      u8 pad[0x70];
      s16 values[3];
    } vsp88;
    struct 
    {
      u8 pad[0x78];
      f32 values[4];
    } vsp90;
    struct 
    {
      u8 pad[0x88];
      f32 values[9];
    } vspA0;
    struct 
    {
      u8 pad[0x98];
      f32 values[3];
    } vspB0;
    struct 
    {
      u8 pad[0xa8];
      f32 values[3];
    } vspC0;
    struct 
    {
      u8 pad[0xb0];
      f32 values[4];
    } vspC8;
    struct 
    {
      u8 pad[0xb8];
      f32 values[3];
    } vspD0;
    struct 
    {
      u8 pad[0xc0];
      f32 values[3];
    } boundsMin;
    struct 
    {
      u8 pad[0xc8];
      f32 values[3];
    } correction;
    struct 
    {
      u8 pad[0xd8];
      f32 values[3];
    } vspF0;
    struct 
    {
      u8 pad[0xe8];
      f32 values[9];
    } vsp100;
    struct 
    {
      u8 pad[0x110];
      f32 values[3];
    } vsp128;
    struct 
    {
      u8 pad[0x120];
      f32 values[3];
    } vsp138;
    struct 
    {
      u8 pad[0x130];
      f32 values[3];
    } vsp148;
    struct 
    {
      u8 pad[0x140];
      f32 values[3];
    } vsp158;
    struct 
    {
      u8 pad[0x150];
      f32 values[3];
    } vsp168;
    struct 
    {
      u8 pad[0x30];
      f32 values[3];
    } chosenPoint;
  } scratch;
  SurfaceObj *self;
  u8 hit;
  SurfaceNode *node;
  u16 i;
  f32 radiusSq;
  SurfaceObj *obj;
  SurfaceActor *actor;
  SurfaceMesh *mesh;
  SurfaceMesh *omesh;
  u16 *tri16;
  u8 *tri8;
  u16 *q16;
  u8 *q8;
  u32 skip;
  u32 kindBits;
  s32 mask;
  u16 j;
  f32 *mtx;

  self = startObj;
  hit = 0;
  radiusSq = radius * radius;
  if (self == NULL)
  {
    return 0;
  }
  gSurfaceQueryStamp++;
  node = self->cell->list;
  do
  {
    self->cell->stamp = gSurfaceQueryStamp;
    obj = self;
    if (self != NULL)
    {
      for (actor = self->actors; actor != NULL; actor = actor->next)
      {
        if (actor == ignore) continue;
        if (actor->mesh == NULL) continue;
        skip = actor->flags & 0x400;
        if (skip) continue;
        if (!(actor->flags2 & 0x200)) continue;
        mesh = actor->mesh;
        if (!isPointOutsideActorSphere(actor, pos, radius)) continue;
        *((SurfaceVec3 *) POS) = *pos;
        ANG[0] = -actor->rot[0];
        ANG[1] = -actor->rot[1];
        ANG[2] = -actor->rot[2];
        buildRotationMatrix(ANG, MAT);
        POS[0] -= actor->pos[0];
        POS[1] -= actor->pos[1];
        POS[2] -= actor->pos[2];
        rotateVec3ByMat3(MAT, POS);
        ANG[0] = actor->rot[0];
        ANG[1] = actor->rot[1];
        ANG[2] = actor->rot[2];
        buildRotationMatrixS16(ANG, MAT2);
        if (mesh->flags & 4)
        {
          tri16 = mesh->tris;
          for (i = 0; i < mesh->count; tri16 += 3, i++)
          {
            void *a;
            void *b;
            void *c;
            f32 d;
            f32 d0;
            f32 d1;
            f32 d2;
            f32 best;
            f32 cx;
            f32 cz;
            f32 cy;
            f32 py;
            f32 px;
            f32 pz;
            u32 bits;
            f32 f;
            buildPlaneFromPoints(PLANE, &mesh->verts[tri16[0]], &mesh->verts[tri16[1]], &mesh->verts[tri16[2]]);
            d = PLANE[0] * POS[0] + PLANE[1] * POS[1] + PLANE[2] * POS[2] + PLANE[3];
            if ((d > 0.0f) & (d < radius))
            {
              out->x = POS[0] - d * PLANE[0];
              out->y = POS[1] - d * PLANE[1];
              out->z = POS[2] - d * PLANE[2];
              a = &mesh->verts[tri16[0]];
              b = &mesh->verts[tri16[1]];
              c = &mesh->verts[tri16[2]];
              if (!triangleContainsPoint(out, a, b, c, PLANE))
              {
                segmentClosestPoint(E0, a, b, POS);
                d0 = func_80047AB0(E0, POS);
                segmentClosestPoint(E1, b, c, POS);
                d1 = func_80047AB0(E1, POS);
                segmentClosestPoint(E2, c, a, POS);
                d2 = func_80047AB0(E2, POS);
                best = d0;
                *((SurfaceVec3 *) CLOSE) = *((SurfaceVec3 *) E0);
                if ((d1 < best) & (d1 < d2))
                {
                  *((SurfaceVec3 *) CLOSE) = *((SurfaceVec3 *) E1);
                  best = d1;
                }
                else if ((d2 < best) & (d2 < d1))
                {
                  *((SurfaceVec3 *) CLOSE) = *((SurfaceVec3 *) E2);
                  best = d2;
                }
                if (!(best < radiusSq)) continue;
                f = D_800D3E70 - sqrtf32(best) / radius;
                cx = f * (POS[0] - CLOSE[0]);
                cz = f * (POS[2] - CLOSE[2]);
                cy = f * (POS[1] - CLOSE[1]);
                CORR[0] = cx;
                CORR[2] = cz;
                POS[0] += cx;
                CORR[1] = cy;
                POS[1] += cy;
                POS[2] += cz;
                rotateVec3ByMat3(MAT2, CORR);
                pos->x += CORR[0];
                pos->y += CORR[1];
                pos->z += CORR[2];
                hit = 1;
                actor->hitMask |= hitFlags;
              }
              else
              {
                f = radius - d;
                px = f * PLANE[0];
                py = f * PLANE[1];
                pz = f * PLANE[2];
                CORR[0] = px;
                CORR[1] = py;
                CORR[2] = pz;
                POS[0] += px;
                POS[1] += py;
                POS[2] += pz;
                rotateVec3ByMat3(MAT2, CORR);
                pos->x += CORR[0];
                pos->y += CORR[1];
                pos->z += CORR[2];
                hit = 1;
                actor->hitMask |= hitFlags;
              }
            }
          }
        }
        else
        {
          tri8 = mesh->tris;
          for (i = 0; i < mesh->count; tri8 += 3, i++)
          {
            void *a;
            void *b;
            void *c;
            f32 d;
            f32 d0;
            f32 d1;
            f32 d2;
            f32 best;
            f32 cx;
            f32 cz;
            f32 cy;
            f32 py;
            f32 px;
            f32 pz;
            u32 bits;
            f32 f;
            buildPlaneFromPoints(PLANE, &mesh->verts[tri8[0]], &mesh->verts[tri8[1]], &mesh->verts[tri8[2]]);
            d = PLANE[0] * POS[0] + PLANE[1] * POS[1] + PLANE[2] * POS[2] + PLANE[3];
            if ((d > 0.0f) & (d < radius))
            {
              out->x = POS[0] - d * PLANE[0];
              out->y = POS[1] - d * PLANE[1];
              out->z = POS[2] - d * PLANE[2];
              a = &mesh->verts[tri8[0]];
              b = &mesh->verts[tri8[1]];
              c = &mesh->verts[tri8[2]];
              if (!triangleContainsPoint(out, a, b, c, PLANE))
              {
                segmentClosestPoint(E0, a, b, POS);
                d0 = func_80047AB0(E0, POS);
                segmentClosestPoint(E1, b, c, POS);
                d1 = func_80047AB0(E1, POS);
                segmentClosestPoint(E2, c, a, POS);
                d2 = func_80047AB0(E2, POS);
                best = d0;
                *((SurfaceVec3 *) CLOSE) = *((SurfaceVec3 *) E0);
                if ((d1 < best) & (d1 < d2))
                {
                  *((SurfaceVec3 *) CLOSE) = *((SurfaceVec3 *) E1);
                  best = d1;
                }
                else if ((d2 < best) & (d2 < d1))
                {
                  *((SurfaceVec3 *) CLOSE) = *((SurfaceVec3 *) E2);
                  best = d2;
                }
                if (!(best < radiusSq)) continue;
                f = D_800D3E78 - sqrtf32(best) / radius;
                cx = f * (POS[0] - CLOSE[0]);
                cz = f * (POS[2] - CLOSE[2]);
                cy = f * (POS[1] - CLOSE[1]);
                CORR8[0] = cx;
                CORR8[2] = cz;
                POS[0] += cx;
                CORR8[1] = cy;
                POS[1] += cy;
                POS[2] += cz;
                rotateVec3ByMat3(MAT2, CORR8);
                pos->x += CORR8[0];
                pos->y += CORR8[1];
                pos->z += CORR8[2];
                hit = 1;
                actor->hitMask |= hitFlags;
              }
              else
              {
                f = radius - d;
                px = f * PLANE[0];
                py = f * PLANE[1];
                pz = f * PLANE[2];
                CORR8[0] = px;
                CORR8[1] = py;
                CORR8[2] = pz;
                POS[0] += px;
                POS[1] += py;
                POS[2] += pz;
                rotateVec3ByMat3(MAT2, CORR8);
                pos->x += CORR8[0];
                pos->y += CORR8[1];
                pos->z += CORR8[2];
                hit = 1;
                actor->hitMask |= hitFlags;
              }
            }
          }
        }
      }
      if (obj != NULL)
      {
      do
      {
        omesh = obj->mesh;
        if (!(obj->flags & 0x200)) goto next_obj;
        kindBits = (obj->flags2 >> 23) & 0x20;
        if (kindBits) goto next_obj;
        if (!sphereContainsPoint(obj->sphere, pos, radius)) goto next_obj;
        *((SurfaceVec3 *) POS2) = *pos;
        POS2[0] -= obj->pos[0];
        POS2[1] -= obj->pos[1];
        POS2[2] -= obj->pos[2];
        ANG[0] = -(obj->rot[0] * 651.8986f);
        ANG[1] = -(obj->rot[1] * 651.8986f);
        ANG[2] = -(obj->rot[2] * 651.8986f);
        buildRotationMatrixCopy(ANG, MATA);
        ANG[0] = obj->rot[0] * 651.8986f;
        ANG[1] = obj->rot[1] * 651.8986f;
        ANG[2] = obj->rot[2] * 651.8986f;
        buildRotationMatrixS16Copy(ANG, MATB);
        rotateVec3InPlaceByMat3(MATA, POS2);
        mtx = MATB;
        if ((obj->mesh->minX < POS2[0] + radius) && (POS2[0] - radius < obj->mesh->maxX)
            && (obj->mesh->minZ < POS2[2] + radius) && (POS2[2] - radius < obj->mesh->maxZ)
            && (obj->mesh->minY < POS2[1] + radius) && (POS2[1] - radius < obj->mesh->maxY))
        {
          u16 lo;
          u16 hi;
          *((SurfaceVec3 *) VMAX) = *((SurfaceVec3 *) POS2);
          *((SurfaceVec3 *) VMIN) = *((SurfaceVec3 *) VMAX);
          VMIN[0] -= radius;
          VMIN[2] -= radius;
          VMAX[0] += radius;
          VMAX[2] += radius;
          mask = computeGridCellMask(&obj->mesh->minX, VMIN, VMAX);
          lo = mask & 0xFF;
          hi = mask & 0xFF00;
          if (omesh->flags & 4)
          {
            for (j = 0; j < omesh->count; j++)
            {
              q16 = omesh->tris;
              q16 += j * 3;
              if ((omesh->cellMasks[j] & lo) && (omesh->cellMasks[j] & hi))
              {
                void *a;
                void *b;
                void *c;
                f32 d;
                f32 d0;
                f32 d1;
                f32 d2;
                f32 best;
                f32 cx;
                f32 cz;
                f32 cy;
                f32 py;
                f32 px;
                f32 pz;
                u32 bits;
                f32 f;
                buildPlaneFromPoints(PLANE2, &omesh->verts[q16[0]], &omesh->verts[q16[1]], &omesh->verts[q16[2]]);
                d = PLANE2[0] * POS2[0] + PLANE2[1] * POS2[1] + PLANE2[2] * POS2[2] + PLANE2[3];
                if ((d > 0.0f) & (d < radius))
                {
                  out->x = POS2[0] - d * PLANE2[0];
                  out->y = POS2[1] - d * PLANE2[1];
                  out->z = POS2[2] - d * PLANE2[2];
                  a = &omesh->verts[q16[0]];
                  b = &omesh->verts[q16[1]];
                  c = &omesh->verts[q16[2]];
                  if (!triangleContainsPoint(out, a, b, c, PLANE2))
                  {
                    segmentClosestPoint(F0, a, b, POS2);
                    d0 = func_80047AB0(F0, POS2);
                    segmentClosestPoint(F1, b, c, POS2);
                    d1 = func_80047AB0(F1, POS2);
                    segmentClosestPoint(F2, c, a, POS2);
                    d2 = func_80047AB0(F2, POS2);
                    best = d0;
                    *((SurfaceVec3 *) CLOSE2) = *((SurfaceVec3 *) F0);
                    if ((d1 < best) & (d1 < d2))
                    {
                      *((SurfaceVec3 *) CLOSE2) = *((SurfaceVec3 *) F1);
                      best = d1;
                    }
                    else if ((d2 < best) & (d2 < d1))
                    {
                      *((SurfaceVec3 *) CLOSE2) = *((SurfaceVec3 *) F2);
                      best = d2;
                    }
                    if (!(best < radiusSq)) continue;
                    f = D_800D3E80 - sqrtf32(best) / radius;
                    cx = f * (POS2[0] - CLOSE2[0]);
                    cz = f * (POS2[2] - CLOSE2[2]);
                    cy = f * (POS2[1] - CLOSE2[1]);
                    CORRB[0] = cx;
                    CORRB[2] = cz;
                    POS2[0] += cx;
                    CORRB[1] = cy;
                    POS2[1] += cy;
                    POS2[2] += cz;
                    rotateVec3InPlaceByMat3(mtx, CORRB);
                    pos->x += CORRB[0];
                    pos->y += CORRB[1];
                    pos->z += CORRB[2];
                    bits = obj->flags2;
                    if (bits & 0x7E0000)
                    {
                      if (outKind != NULL)
                      {
                        *outKind = (bits >> 17) & 0x3F;
                      }
                      if (outObj != NULL)
                      {
                        *outObj = obj;
                      }
                    }
                    hit = 1;
                  }
                  else
                  {
                    f = radius - d;
                    px = f * PLANE2[0];
                    py = f * PLANE2[1];
                    pz = f * PLANE2[2];
                    CORRB[0] = px;
                    CORRB[1] = py;
                    CORRB[2] = pz;
                    POS2[0] += px;
                    POS2[1] += py;
                    POS2[2] += pz;
                    rotateVec3InPlaceByMat3(mtx, CORRB);
                    pos->x += CORRB[0];
                    pos->y += CORRB[1];
                    pos->z += CORRB[2];
                    bits = obj->flags2;
                    if (bits & 0x7E0000)
                    {
                      if (outKind != NULL)
                      {
                        *outKind = (bits >> 17) & 0x3F;
                      }
                      if (outObj != NULL)
                      {
                        *outObj = obj;
                      }
                    }
                    hit = 1;
                  }
                }
              }
            }
          }
          else
          {
            for (j = 0; j < omesh->count; j++)
            {
              q8 = omesh->tris;
              q8 += j * 3;
              if ((omesh->cellMasks[j] & lo) && (omesh->cellMasks[j] & hi))
              {
                void *a;
                void *b;
                void *c;
                f32 d;
                f32 d0;
                f32 d1;
                f32 d2;
                f32 best;
                f32 cx;
                f32 cz;
                f32 cy;
                f32 py;
                f32 px;
                f32 pz;
                u32 bits;
                f32 f;
                buildPlaneFromPoints(PLANE2, &omesh->verts[q8[0]], &omesh->verts[q8[1]], &omesh->verts[q8[2]]);
                d = PLANE2[0] * POS2[0] + PLANE2[1] * POS2[1] + PLANE2[2] * POS2[2] + PLANE2[3];
                if ((d > 0.0f) & (d < radius))
                {
                  out->x = POS2[0] - d * PLANE2[0];
                  out->y = POS2[1] - d * PLANE2[1];
                  out->z = POS2[2] - d * PLANE2[2];
                  a = &omesh->verts[q8[0]];
                  b = &omesh->verts[q8[1]];
                  c = &omesh->verts[q8[2]];
                  if (!triangleContainsPoint(out, a, b, c, PLANE2))
                  {
                    segmentClosestPoint(F0, a, b, POS2);
                    d0 = func_80047AB0(F0, POS2);
                    segmentClosestPoint(F1, b, c, POS2);
                    d1 = func_80047AB0(F1, POS2);
                    segmentClosestPoint(F2, c, a, POS2);
                    d2 = func_80047AB0(F2, POS2);
                    best = d0;
                    *((SurfaceVec3 *) CLOSE2) = *((SurfaceVec3 *) F0);
                    if ((d1 < best) & (d1 < d2))
                    {
                      *((SurfaceVec3 *) CLOSE2) = *((SurfaceVec3 *) F1);
                      best = d1;
                    }
                    else if ((d2 < best) & (d2 < d1))
                    {
                      *((SurfaceVec3 *) CLOSE2) = *((SurfaceVec3 *) F2);
                      best = d2;
                    }
                    if (!(best < radiusSq)) continue;
                    f = D_800D3E88 - sqrtf32(best) / radius;
                    cx = f * (POS2[0] - CLOSE2[0]);
                    cz = f * (POS2[2] - CLOSE2[2]);
                    cy = f * (POS2[1] - CLOSE2[1]);
                    CORRB8[0] = cx;
                    CORRB8[2] = cz;
                    POS2[0] += cx;
                    CORRB8[1] = cy;
                    POS2[1] += cy;
                    POS2[2] += cz;
                    rotateVec3InPlaceByMat3(mtx, CORRB8);
                    pos->x += CORRB8[0];
                    pos->y += CORRB8[1];
                    pos->z += CORRB8[2];
                    bits = obj->flags2;
                    if (bits & 0x7E0000)
                    {
                      if (outKind != NULL)
                      {
                        *outKind = (bits >> 17) & 0x3F;
                      }
                      if (outObj != NULL)
                      {
                        *outObj = obj;
                      }
                    }
                    hit = 1;
                  }
                  else
                  {
                    f = radius - d;
                    px = f * PLANE2[0];
                    py = f * PLANE2[1];
                    pz = f * PLANE2[2];
                    CORRB8[0] = px;
                    CORRB8[1] = py;
                    CORRB8[2] = pz;
                    POS2[0] += px;
                    POS2[1] += py;
                    POS2[2] += pz;
                    rotateVec3InPlaceByMat3(mtx, CORRB8);
                    pos->x += CORRB8[0];
                    pos->y += CORRB8[1];
                    pos->z += CORRB8[2];
                    bits = obj->flags2;
                    if (bits & 0x7E0000)
                    {
                      if (outKind != NULL)
                      {
                        *outKind = (bits >> 17) & 0x3F;
                      }
                      if (outObj != NULL)
                      {
                        *outObj = obj;
                      }
                    }
                    hit = 1;
                  }
                }
              }
            }
          }
        }
      next_obj:
        obj = obj->next;
      }
      while (obj != NULL);
      }
    }
    if (node == NULL)
    {
      break;
    }
    goto loop_153;
  next_node:
    node = node->next;
    if (node == NULL) continue;
  loop_153:
    for (;;)
    {
      self = node->owner;
      if (self->cell->stamp != gSurfaceQueryStamp)
      {
        if (node != NULL)
        {
          if (sphereContainsPoint(node->obj->sphere, pos, radius) != 0)
          {
            node = node->next;
            break;
          }
          goto next_node;
        }
        return (s8) hit;
      }
      node = node->next;
      if (node == NULL) break;
    }
  }
  while (self != NULL);
  return hit;
}
