typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} V3;
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
  f32 d;
} Pl;
f32 func_80082908(f32);
s32 buildPlaneFromPoints(Pl *out, V3 *p1, V3 *p2, V3 *p3)
{
  V3 n;
  f32 len;
  s32 ret;
  f32 py = p1->y;
  f32 dz2 = p3->z - p2->z;
  f32 pz = p1->z;
  f32 dz1 = p2->z - pz;
  f32 dy1 = p2->y - py;
  f32 dy2 = p3->y - p2->y;
  f32 dx2 = p3->x - p2->x;
  f32 px = p1->x;
  f32 dx1 = p2->x - px;
  n.x = (dy1 * dz2) - (dz1 * dy2);
  n.y = (dz1 * dx2) - (dx1 * dz2);
  n.z = (dx1 * dy2) - (dy1 * dx2);
  len = func_80082908(((n.x * n.x) + (n.y * n.y)) + (n.z * n.z));
  ret = 1;
  if (len == 0.0f)
  {
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    out->d = ((-out->x) * px) - (out->y * py);
    ret = 0;
  }
  else
  {
    len = 1.0f / len;
    n.x *= len;
    n.y *= len;
    n.z *= len;
    out->x = n.x;
    out->y = n.y;
    out->z = n.z;
    out->d = (((-out->x) * px) - (out->y * py)) - (out->z * pz);
  }
  return ret;
}

