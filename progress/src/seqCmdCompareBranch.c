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
s32 seqReadIndirectVar();
extern s16 gSeqGlobalVars[];
static __inline__ s32 getv(Seq *s, u8 sel, u8 idx)
{
  s32 value;
  if (sel)
  {
    value = seqReadIndirectVar(s, idx & 0xFF);
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
      value = gSeqGlobalVars[idx];
    }
  }
  return value;
}
/* Sequence command: compares two variables (op 0 equal, 1 less-than), optionally inverts, and branches the sequence pc if true. */ s32 seqCmdCompareBranch(Seq *s, register Cmd *c, u8 compareOp)
{
  s32 lhs;
  s32 rhs;
  u8 cond;
  s32 one;
  volatile u32 frame[2];
  rhs = 0;
  lhs = getv(s, (c->w0 >> 8) & 0xFF, c->w0 >> 16);
  do { rhs = getv(s, c->w0 >> 24, c->w1); } while (0);
  one = 1;
  switch (compareOp)
  {
    case 0:
      if (s || lhs)
    {
      do { do { cond = ((s16) rhs) == ((s16) lhs); } while (0); } while (0);
      break;
    }
    else
    {
      do { do { cond = ((s16) rhs) == ((s16) lhs); } while (0); } while (0);
      break;
    }

    case 1:
      cond = ((s16) lhs) < ((s16) rhs) + (one - 1);
      break;

  }

  {
    u8 invert;
    u32 dest;
    invert = ((u8 *) c)[6];
    dest = c->w1;
    if (invert)
    {
      cond = !cond;
    }
    if (cond)
    {
      do { do { do { s->pc = s->base + ((dest >> 16) * 8); } while (0); } while (0); } while (0);
    }
  }
  return 0;
}


