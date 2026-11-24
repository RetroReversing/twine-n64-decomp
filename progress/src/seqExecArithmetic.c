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
s32 seqWriteIndirectVar(void *, s32, s16);
extern s16 gSeqGlobalVars[];
static __inline__ s32 readVar(Seq *seq, u8 indirect, u8 idx)
{
  s32 value;
  if (indirect)
  {
    value = seqReadIndirectVar(seq, idx & 0xFF);
  }
  else
  {
    idx &= 0x1F;
    if (idx < 16)
    {
      value = seq->regs[idx];
    }
    else
    {
      value = gSeqGlobalVars[idx];
    }
  }
  return value;
}
static __inline__ void writeVar(Seq *seq, u8 indirect, u8 idx, s16 v)
{
  if (indirect)
  {
    seqWriteIndirectVar(seq, idx & 0xFF, v);
  }
  else
  {
    idx &= 0x1F;
    if (idx < 16)
    {
      seq->regs[idx] = v;
    }
    else
    {
      gSeqGlobalVars[idx] = v;
    }
  }
}
/* Sequence VM arithmetic op (add/sub/mul/div; op 4 = add immediate): reads two operands, clamps the result to s16 and stores it in the destination variable. */
s32 seqExecArithmetic(Seq *seq, Cmd *cmd, u8 op)
{
  s32 lhs;
  s32 rhs;
  s32 result;
  lhs = readVar(seq, cmd->w0 >> 24, cmd->w1);
  if (op == 4)
  {
    rhs = cmd->w1 >> 8;
  }
  else
  {
    rhs = readVar(seq, (cmd->w1 >> 8) & 0xFF, cmd->w1 >> 16);
  }
  switch (op)
  {
    case 0:
    case 4:
      result = ((s16) lhs) + ((s16) rhs);
      break;
    case 1:
      result = ((s16) lhs) - ((s16) rhs);
      break;
    case 2:
      result = ((s16) lhs) * ((s16) rhs);
      break;
    case 3:
      if (((s16) rhs) != 0)
        result = ((s16) lhs) / ((s16) rhs);
      else
        result = 0;
      break;
  }
  {
    u32 dstIndirect = cmd->w0 >> 8;
    u32 dstIdx = cmd->w0 >> 16;
    s16 v;
  if (result >= -0x8000)
  {
    v = 0x7FFF;
    if (result <= 0x7FFF)
      v = result;
  }
  else
    v = -0x8000;
    writeVar(seq, dstIndirect, dstIdx, v);
  }
  return 0;
}
