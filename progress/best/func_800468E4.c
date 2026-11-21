typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} RotationQuat;
void func_800468E4(const RotationQuat *q, f32 m[3][3])
{
  volatile f64 scratch[1];
  f32 y = q->y;
  register f32 y2 = y + y;
  f32 x = q->x;
  f32 z = q->z;
  f32 xy = y2 * x;
  f32 z2 = z + z;
  f32 xz = z2 * x;
  f32 yy = y2 * y;
  f32 zz = z2 * z;
  f32 w = q->w;
  f32 yw = y2 * w;
  f32 zw = z2 * w;
  f32 x2 = x + x;
  f32 xx;
  f32 a = (y2 * y) + zz;
  f32 b = xy - zw;
  f32 yz = y * z2;
  f32 c = xz + yw;
  f32 d = xy + zw;
  f32 xw = w * x2;
  f32 e = (x2 * x) + zz;
  f32 f = yz - xw;
  f32 g = xz - yw;
  f32 h;
  f32 i = (x2 * x) + yy;
  m[0][0] = 1.0f - a;
  m[0][1] = b;
  m[1][0] = d;
  m[0][2] = c;
  m[1][1] = 1.0f - e;
  m[1][2] = f;
  m[2][1] = yz + xw;
  m[2][0] = g;
  m[2][2] = 1.0f - i;
}

