typedef struct 
{
  u8 pad0[0x82];
  u8 state;
  u8 pad83[5];
  s32 flags;
} Obj7C120;
typedef struct 
{
  u8 pad0[0x6C];
  Obj7C120 *obj;
} Ent7C120;
extern f32 gSightRangeTable[];
extern s16 gSightRangeIndex;
s8 func_8007C094(Ent7C120 *, s32, f32);
s8 checkSightWithRangeScale(Ent7C120 *arg0, s32 arg1, f32 arg2)
{
  Obj7C120 *obj = arg0->obj;
  f32 scale;
  if (((obj->state == 9) || (obj->state == 10)) || (obj->state == 11))
  {
    scale = gSightRangeTable[gSightRangeIndex];
    scale *= arg2;
  }
  else
  {
    s32 idx;
    f32 f;
    if (obj->flags & 0x40000000)
    {
      idx = gSightRangeIndex;
      f = 0.95f;
    }
    else
      if (obj->flags & 0x20000000)
    {
      idx = gSightRangeIndex;
      f = 0.75f;
    }
    else
    {
 do { idx = gSightRangeIndex; f = 0.25f; } while (0);
    }
    scale = gSightRangeTable[idx];
    scale *= f;
    scale *= arg2;
  }
  if (scale)
  {
    return func_8007C094(arg0, arg1, scale);
  }
  else
  {
    return func_8007C094(arg0, arg1, scale);
  }
}
