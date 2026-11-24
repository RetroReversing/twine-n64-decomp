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
f32 sqrtf32(f32);
/* Builds a normalized plane (normal + d) through three points; returns 0 if the points are degenerate. */ s32 buildPlaneFromPoints(Pl *plane, const V3 *a, const V3 *b, const V3 *c)
{
  V3 normal;
  f32 invLen;
  s32 valid;
  f32 abDz = b->z - a->z;
  normal.x = ((b->y - a->y) * (c->z - b->z)) - (abDz * (c->y - b->y));
  normal.y = (abDz * (c->x - b->x)) - ((b->x - a->x) * (c->z - b->z));
  normal.z = ((b->x - a->x) * (c->y - b->y)) - ((b->y - a->y) * (c->x - b->x));
  invLen = sqrtf32(((normal.x * normal.x) + (normal.y * normal.y)) + (normal.z * normal.z));
  valid = 1;
  if (invLen == 0.0f)
  {
    plane->x = 0.0f;
    plane->y = 0.0f;
    plane->z = 0.0f;
    plane->d = ((-plane->x) * a->x) - (plane->y * a->y);
    valid = 0;
  }
  else
  {
    invLen = 1.0f / invLen;
    normal.x *= invLen;
    normal.y *= invLen;
    normal.z *= invLen;
    plane->x = normal.x;
    plane->y = normal.y;
    plane->z = normal.z;
    plane->d = (((-plane->x) * a->x) - (plane->y * a->y)) - (plane->z * a->z);
  }
  return valid;
}

