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
s32 buildPlaneFromPoints(Pl *out, const V3 *p1, const V3 *p2, const V3 *p3)
{
  V3 n;
  f32 len;
  s32 ret;
  f32 dz1 = p2->z - p1->z;
  n.x = ((p2->y - p1->y) * (p3->z - p2->z)) - (dz1 * (p3->y - p2->y));
  n.y = (dz1 * (p3->x - p2->x)) - ((p2->x - p1->x) * (p3->z - p2->z));
  n.z = ((p2->x - p1->x) * (p3->y - p2->y)) - ((p2->y - p1->y) * (p3->x - p2->x));
  len = func_80082908(((n.x * n.x) + (n.y * n.y)) + (n.z * n.z));
  ret = 1;
  if (len == 0.0f)
  {
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    out->d = ((-out->x) * p1->x) - (out->y * p1->y);
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
    out->d = (((-out->x) * p1->x) - (out->y * p1->y)) - (out->z * p1->z);
  }
  return ret;
}

