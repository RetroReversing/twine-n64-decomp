f32 sinTableLookup(f32);
f32 cosTableLookup(f32);
s32 guRandom(void);
extern s32 D_800B1D74;
extern f32 D_800B1D78;
extern u32 D_801007B8;
extern u8 D_80102F38;
extern u8 D_801032A4;
extern u8 D_80108F74;
typedef struct { char pad[0x60]; u16 w60; u8 pad2[2]; u8 r; u8 g; u8 b; } Col;
typedef struct { char pad[0x20]; Col *col; char pad2[0x34]; u32 flags; } Obj;
void updateObjectColor(Obj *o)
{
  u32 f;
  u32 v;
  u32 w;
  u32 x;
  u32 y;
  u32 z;
  if (o->col->w60 != D_800B1D74)
  {
    o->col->w60 = D_800B1D74;
    f = o->flags >> 2;
    if (f & 0x10)
    {
      v = (u32)(sinTableLookup((f32)D_801007B8 * 0.1f) * 64.0f + 192.0f);
      o->col->r = v;
      o->col->g = 0x40;
      o->col->b = 0x40;
      return;
    }
    else if (f & 0x80)
    {
      w = (u32)(sinTableLookup(D_800B1D78 * 0.02f) * (cosTableLookup(0.07f * D_800B1D78) * 64.0f) * sinTableLookup(D_800B1D78 * 0.04f)) + 64;
      o->col->r = w;
      o->col->g = w;
      o->col->b = w;
      return;
    }
    if (f & 0x40)
    {
      x = (u32)(sinTableLookup(D_800B1D78 * 0.2f) * 128.0f + 128.0f) | 8;
      o->col->r = x;
      o->col->g = x;
      o->col->b = 8;
    }
    else if (f & 0x20)
    {
      if (o->col->r < 0x20U)
      {
        if (guRandom() % 30 == 0)
        {
          y = guRandom() % 128 - 128;
          o->col->r = y;
          o->col->g = y;
          o->col->b = y;
        }
      }
      else
      {
        if (guRandom() % 3 == 0)
        {
          z = guRandom() % 128 - 128;
          o->col->r = z;
          o->col->g = z;
          o->col->b = z;
        }
      }
    }
    else
    {
      o->col->r = D_80102F38;
      o->col->g = D_80108F74;
      o->col->b = D_801032A4;
    }
  }
}
