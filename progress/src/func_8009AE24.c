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
s32 func_8009AE24(Seq *s, register Cmd *c, u8 op)
{
  s32 a;
  s32 b;
  u8 r;
  s32 one;
  volatile u32 frame[2];
  b = 0;
  a = getv(s, (c->w0 >> 8) & 0xFF, c->w0 >> 16);
  do { b = getv(s, c->w0 >> 24, c->w1); } while (0);
  one = 1;
  switch (op)
  {
    case 0:
      if (s || a)
    {
      do { do { r = ((s16) b) == ((s16) a); } while (0); } while (0);
      break;
    }
    else
    {
      do { do { r = ((s16) b) == ((s16) a); } while (0); } while (0);
      break;
    }

    case 1:
      r = ((s16) a) < ((s16) b) + (one - 1);
      break;

  }

  {
    u8 invert;
    u32 dest;
    invert = ((u8 *) c)[6];
    dest = c->w1;
    if (invert)
    {
      r = !r;
    }
    if (r)
    {
      do { do { do { s->pc = s->base + ((dest >> 16) * 8); } while (0); } while (0); } while (0);
    }
  }
  return 0;
}


