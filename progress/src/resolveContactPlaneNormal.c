#define FLIP_VECTOR() {     f32 x = -arg3->x, y = -arg3->y, z = -arg3->z;     arg3->x = x; arg3->y = y; arg3->z = z; }
#define FLIP_RETURN() { FLIP_VECTOR(); *arg4 = -*arg4; return 1; }
#define CELLVAL(p) ((((u32)*(u32 *)((u8 *)*(void **)((u8 *)(p) + 0x3C) + 0x30)) >> 4) & 0xFFFF)
#define F8(o, a, b) (castRayAgainstObjectsAndRooms(&rayTriangleIntersect, (o), (a), (b), &out, 256.0f, 0, 1, 0) << 24)
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} Vec3;
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} Vec4;
extern Vec3 gProbeDirDown;
extern Vec3 gProbeDirAlt;
extern void *gSweepHitObject;
extern s32 rayTriangleIntersect;
s32 castRayAgainstObjectsAndRooms(void *, void *, Vec3 *, Vec3 *, Vec3 *, f32, s32, s32, s32);
void buildPlaneFromPoints(Vec4 *, void *, void *, void *);
s8 boundsContainPoint(Vec3 *, void *);
inline static f32 inline_fn(f32 arg0)
{
  return arg0;
}

/* Builds the plane of a surface triangle (arg0) and picks the normal direction (flipping if needed) that separates arg1 from arg2; returns 0 if no side is found. */ s32 resolveContactPlaneNormal(void *arg0, void *arg1, void *arg2, Vec3 *arg3, f32 *arg4)
{
  Vec3 pos;
  Vec3 sum;
  Vec4 r;
  Vec3 out;
  Vec3 neg;
  Vec3 p1;
  Vec3 p2;
  u16 t0;
  void *b;
  void *pa;
  void *pb;
  u16 t1;
  u16 t2;
  long vbase;
  void *s1;
  s32 cellA;
  s32 __repair_result_cellA;
  s32 cellB;
  s32 __repair_result_cellB;
  f32 d1;
  f32 d2;
  s8 c1;
  s8 c2;
  b = *((void **) (((u8 *) arg0) + 0x3C));
  pos.x = *((f32 *) (0x40 + ((u8 *) arg0)));
  pos.y = *((f32 *) (((u8 *) arg0) + 0x44));
  pos.z = *((f32 *) (((u8 *) arg0) + 0x48));
  pa = NULL;
  pb = NULL;
  if ((*(((u8 *) b) + 0x48)) & 4)
  {
    pa = *((void **) (((u8 *) b) + 0x3C));
  }
  else
  {
    pb = *((void **) (((u8 *) b) + 0x3C));
  }
  if (pa != NULL)
  {
    t0 = *((u16 *) (((u8 *) pa) + 0));
    t1 = *((u16 *) (((u8 *) pa) + 2));
    t2 = *((u16 *) (((u8 *) pa) + 4));
  }
  else
  {
    t0 = *((u8 *) (((u8 *) pb) + 0));
    t1 = *((u8 *) (((u8 *) pb) + 1));
    t2 = *((u8 *) (((u8 *) pb) + 2));
  }
  vbase = *((s32 *) (((u8 *) b) + 0x34));
  buildPlaneFromPoints(&r, (void *) ((*((s32 *) (((u8 *) b) + 0x34))) + (t0 * 12)), (void *) ((*((s32 *) (((u8 *) b) + 0x34))) + (t1 * 12)), (void *) ((*((s32 *) (((u8 *) b) + 0x34))) + (t2 * 12)));
  arg3->x = r.x;
  arg3->y = r.y;
  arg3->z = r.z;
  *arg4 = r.w;
  sum.x = pos.x + arg3->x;
  sum.y = pos.y + arg3->y;
  sum.z = pos.z + arg3->z;
  neg.x = -arg3->x;
  neg.y = -arg3->y;
  neg.z = -arg3->z;
  if ((*((u16 *) (((u8 *) arg0) + 0x58))) == 0x84)
  {
    __repair_result_cellA = CELLVAL(arg1);
    __repair_result_cellB = CELLVAL(arg2);
    if (__repair_result_cellB < __repair_result_cellA)
    {
      FLIP_RETURN();
    }
    goto E364;
  }
  if ((*((u16 *) (((u8 *) arg0) + 0x58))) == 0x88)
  {
    cellA = CELLVAL(arg1);
    cellB = CELLVAL(arg2);
    if (cellA < cellB)
    {
      if (1)
      {
        do { FLIP_RETURN(); } while (0);
      }
    }
    goto E364;
  }
  p1 = gProbeDirDown;
  p2 = gProbeDirAlt;
  arg3->x = r.x;
  arg3->y = r.y;
  arg3->z = r.z;
  *arg4 = r.w;
  if (F8(arg1, &sum, &p1) != 0)
  {
    d1 = sum.y - out.y;
    if (F8(arg2, &sum, &p1) != 0)
    {
      d2 = sum.y - out.y;
      if (d1 < d2)
      {
        do { FLIP_RETURN(); } while (0);
      }
      goto E364;
    }
  }
  if (F8(arg1, &sum, &p2) != 0)
  {
    d1 = sum.y - out.y;
    if (F8(arg2, &sum, &p2) != 0)
    {
      d2 = sum.y - out.y;
      if (d1 < d2)
      {
        FLIP_RETURN();
      }
      goto E364;
    }
  }
  if (F8(arg1, &sum, &p1) != 0)
  {
    s1 = gSweepHitObject;
    if ((F8(arg1, &sum, &p2) != 0) && ((float) (s1 == gSweepHitObject)))
    {
      if (s1 != arg1)
      {
        FLIP_VECTOR();
        *arg4 = -(*arg4);
      }
      return 1;
    }
  }
  arg3->x = -r.x;
  arg3->y = -r.y;
  arg3->z = -r.z;
  *arg4 = -r.w;
  if (F8(arg2, &sum, &p1) != 0)
  {
    s1 = gSweepHitObject;
    if ((F8(arg2, &sum, &p2) != 0) && (s1 == gSweepHitObject))
    {
      if (s1 != arg2)
      {
        FLIP_VECTOR();
        *arg4 = -(*arg4);
      }
      return 1;
    }
  }
  arg3->x = r.x;
  arg3->y = r.y;
  arg3->z = r.z;
  *arg4 = r.w;
  c1 = boundsContainPoint(&sum, arg1);
  c2 = boundsContainPoint(&sum, arg2);
  if ((c1 == 0) & (c2 == 0))
  {
    arg3->x = 0.0f;
    arg3->y = 0.0f;
    arg3->z = 0.0f;
    *arg4 = 0.0f;
  }
  if ((c1 != 0) & (c2 == 0))
  {
    return 1;
  }
  if ((c1 == 0) & (c2 != 0))
  {
    FLIP_RETURN();
  }
  if (((unsigned) (c1 != 0)) & (c2 != 0))
  {
    FLIP_VECTOR();
    *arg4 = -(*arg4);
    sum.x = pos.x + arg3->x;
    sum.y = pos.y + arg3->y;
    sum.z = pos.z + arg3->z;
    c1 = boundsContainPoint(&sum, arg1);
    c2 = boundsContainPoint(&sum, arg2);
    if ((c1 == 0) & (c2 == 0))
    {
    }
    if ((c1 != 0) & (c2 == 0))
    {
      return 1;
    }
    if ((c1 == 0) & (c2 != 0))
    {
      FLIP_RETURN();
    }
  }
  if (F8(arg1, &pos, arg3) != 0)
  {
    goto E364;
  }
  if (F8(arg2, &pos, arg3) != 0)
  {
    FLIP_RETURN();
  }
  if (F8(arg1, &pos, &neg) != 0)
  {
    FLIP_RETURN();
  }
  if (F8(arg2, &pos, &neg) == 0)
  {
    return 0;
  }
  goto E364;
  E364:
  arg3->x = r.x;

  arg3->y = r.y;
  arg3->z = r.z;
  *arg4 = r.w;
  return 1;
}

