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
extern f32 D_800C2E64[];
extern s16 D_80117386;
s8 func_8007C094(Ent7C120 *, s32, f32);
s8 func_8007C120(Ent7C120 *arg0, s32 arg1, f32 arg2)
{
  Obj7C120 *obj = arg0->obj;
  f32 scale;
  if (((obj->state == 9) || (obj->state == 10)) || (obj->state == 11))
  {
    scale = D_800C2E64[D_80117386];
    scale *= arg2;
  }
  else
  {
    s32 idx;
    f32 f;
    if (obj->flags & 0x40000000)
    {
      idx = D_80117386;
      f = 0.95f;
    }
    else
      if (obj->flags & 0x20000000)
    {
      idx = D_80117386;
      f = 0.75f;
    }
    else
    {
 do { idx = D_80117386; f = 0.25f; } while (0);
    }
    scale = D_800C2E64[idx];
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
