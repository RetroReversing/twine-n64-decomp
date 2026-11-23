typedef struct 
{
  s32 base;
  u32 pc;
  u8 pad[0x178];
  s16 regs[16];
} Seq;
typedef struct 
{
  u32 w0;
  u32 w1;
} Cmd;
s32 func_80096E7C();
s32 func_80096F44(void *, s32, s16);
extern s16 D_80112E9E[];
static __inline__ s32 getv(Seq *s, u8 sel, u8 idx)
{
  s32 value;
  if (sel)
  {
    value = func_80096E7C(s, idx & 0xFF);
  }
  else
  {
    idx &= 0x1F;
    if (idx < 16)
    {
      value = s->regs[idx];
    }
    else
    {
      value = D_80112E9E[idx];
    }
  }
  return value;
}
static __inline__ void setv(Seq *s, u8 sel, u8 idx, s16 v)
{
  if (sel)
  {
    func_80096F44(s, idx & 0xFF, v);
  }
  else
  {
    idx &= 0x1F;
    if (idx < 16)
    {
      s->regs[idx] = v;
    }
    else
    {
      D_80112E9E[idx] = v;
    }
  }
}
s32 func_8009ABD4(Seq *s, Cmd *c, u8 op)
{
  s32 a;
  s32 b;
  s32 r;
  a = getv(s, c->w0 >> 24, c->w1);
  if (op == 4)
  {
    b = c->w1 >> 8;
  }
  else
  {
    b = getv(s, (c->w1 >> 8) & 0xFF, c->w1 >> 16);
  }
  switch (op)
  {
    case 0:
    case 4:
      r = ((s16) a) + ((s16) b);
      break;
    case 1:
      r = ((s16) a) - ((s16) b);
      break;
    case 2:
      r = ((s16) a) * ((s16) b);
      break;
    case 3:
      if (((s16) b) != 0)
        r = ((s16) a) / ((s16) b);
      else
        r = 0;
      break;
  }
  {
    u32 sel = c->w0 >> 8;
    u32 idx = c->w0 >> 16;
    s16 v;
  if (r >= -0x8000)
  {
    v = 0x7FFF;
    if (r <= 0x7FFF)
      v = r;
  }
  else
    v = -0x8000;
    setv(s, sel, idx, v);
  }
  return 0;
}
