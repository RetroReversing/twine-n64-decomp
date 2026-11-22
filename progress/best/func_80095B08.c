typedef u8 ControlRow[134];
extern ControlRow D_800EE420[][16];
extern ControlRow D_800F2720[];
inline static int inline_fn(u32 arg0, u32 arg1)
{
  return arg0 + arg1;
}

inline static ControlRow *inline_fn2(ControlRow (*arg0)[16], s32 arg1)
{
  return arg0[arg1];
}

inline static ControlRow *inline_fn23(u32 arg0, ControlRow *arg1)
{
  return arg0 + arg1;
}

inline static unsigned char inline_fn234(ControlRow (*arg0)[16], s32 arg1)
{
  return (u32) arg0[arg1];
}

inline static ControlRow *inline_fn2345(ControlRow (*arg0)[16], s32 arg1)
{
  return arg0[arg1];
}

void func_80095B08(u8 arg0, u8 arg1, u8 arg2, u16 arg3)
{
  s32 temp_a0;
  s32 temp_a2;
  s32 temp_t0_2;
  s32 temp_a3;
  s32 var_a3;
  u32 temp_t0;
  u32 temp_v0;
  u32 var_v0;
  u32 index;
  int groupBase;
  u32 upper;
  u32 rowOffset;
  temp_t0 = arg0 & 0xFF;
  if (temp_t0 < 0x40U)
  {
    index = arg0 & 0x1F;
    upper = ((u16) arg3) >> 7;
    temp_a0 = arg2 & 0xFF;
    if (temp_a0 != 0xFF)
    {
      groupBase = (u32) inline_fn2(D_800EE420, temp_a0);
      var_v0 = arg1 & 0xFF; rowOffset = var_v0 * 134;
      var_v0 = inline_fn(groupBase, rowOffset);
    }
    else
    {
      rowOffset = (arg1 & 0xFF) * 134;
      do
      {
        var_v0 = inline_fn(rowOffset, (u32) D_800F2720);
      }
      while (0);
    }
    if (D_800F2720)
    {
      *((u8 *) inline_fn(index, var_v0)) = upper & 0x7F;
      temp_a0 = (arg0 & 0x1F) | 0x20;
      temp_a2 = arg2 & 0xFF;
      temp_a3 = arg3 & 0x7F;
    }
    else
    {
      *((u8 *) inline_fn(index, var_v0)) = upper & 0x7F;
      temp_a0 = (arg0 & 0x1F) | 0x20;
      temp_a2 = arg2 & 0xFF;
      temp_a3 = arg3 & 0x7F;
    }
    if (temp_a2 != 0xFF)
    {
      *((u8 *) (temp_a0 + inline_fn2(D_800EE420, temp_a2)[arg1 & 0xFF])) = temp_a3;
      return;
    }
    *((u8 *) inline_fn(temp_a0, (u32) D_800F2720[arg1 & 0xFF])) = temp_a3;
    return;
  }
  if ((arg0 == 0x80) || (arg0 == 0x81))
  {
    index = arg0 & 0xFE;
    if (1)
    {
      upper = ((u16) arg3) >> 7;
      temp_a0 = arg2 & 0xFF;
      if (temp_a0 != 0xFF)
      {
        groupBase = (u32) inline_fn2(D_800EE420, temp_a0);
        temp_a0 = arg1 & 0xFF;
        rowOffset = temp_a0 * 134;
        var_v0 = inline_fn(groupBase, rowOffset);
      }
      else
      {
        temp_a0 = arg1 & 0xFF;
        rowOffset = temp_a0 * 134;
        var_v0 = inline_fn(rowOffset, (u32) D_800F2720);
      }
      *((u8 *) inline_fn(index, var_v0)) = upper & 0x7F;
      temp_a2 = arg2 & 0xFF;
      var_a3 = arg3 & 0x7F;
    }
    if (arg1)
    {
      index = arg0 | 1;
    }
    else
    {
      index = arg0 | 1;
    }
    if (temp_a2 != 0xFF)
    {
      u32 __repair_branch_groupBase_2;
      if (groupBase)
      {
        __repair_branch_groupBase_2 = inline_fn234(D_800EE420, temp_a2);
        var_v0 = inline_fn(__repair_branch_groupBase_2, rowOffset);
        rowOffset = (arg1 & 0xFF) * 134;
      }
      else
      {
        __repair_branch_groupBase_2 = (u32) inline_fn2345(D_800EE420, temp_a2);
        var_v0 = inline_fn(__repair_branch_groupBase_2, rowOffset);
        rowOffset = (arg1 & 0xFF) * 134;
      }
    }
    else
    {
      goto block_19;
    }
    goto block_20;
  }
  index = arg3 & 0xFFFF;
  if ((arg0 == 0x84) || (arg0 == 0x85))
  {
    temp_a0 = arg2 & 0xFF;
    if (temp_a0 != 0xFF)
    {
      groupBase = (unsigned char) ((u32) inline_fn2(D_800EE420, temp_a0));
      rowOffset = (arg1 & 0xFF) * 134;
      var_v0 = inline_fn(groupBase, rowOffset);
    }
    else
    {
      temp_a0 = arg1 & 0xFF;
      rowOffset = temp_a0 * 134;
      var_v0 = rowOffset + ((u32) D_800F2720);
    }
    if (arg1)
    {
      *((u8 *) inline_fn(arg0 & 0xFE, var_v0)) = (index >> 7) & 0x7F;
      index = arg0 | 1;
      temp_a2 = arg2 & 0xFF;
      var_a3 = arg3 & 0x7F;
    }
    else
    {
      *((u8 *) inline_fn(arg0 & 0xFE, var_v0)) = (index >> 7) & 0x7F;
      index = arg0 | 1;
      temp_a2 = arg2 & 0xFF;
      var_a3 = arg3 & 0x7F;
    }
    if (temp_a2 != 0xFF)
    {
      if (D_800F2720)
      {
        groupBase = inline_fn2(D_800EE420, temp_a2);
        rowOffset = (arg1 & 0xFF) * 134;
        var_v0 = inline_fn(groupBase, rowOffset);
      }
      else
      {
        groupBase = inline_fn2(D_800EE420, temp_a2);
        rowOffset = (arg1 & 0xFF) * 134;
        var_v0 = inline_fn(groupBase, rowOffset);
      }
    }
    else
    {
      block_19:
      rowOffset = (arg1 & 0xFF) * 134;

      do
      {
        var_v0 = inline_fn(rowOffset, (u32) D_800F2720);
      }
      while (0);
    }
    block_20:
    *((u8 *) ((index & 0xFF) + var_v0)) = var_a3;

    return;
  }
  temp_a2 = ((u32) arg2) & 0xFF;
  if (temp_a2 != 0xFF)
  {
    groupBase = inline_fn2345(D_800EE420, temp_a2);
    rowOffset = (arg1 & 0xFF) * 134;
    var_v0 = inline_fn(groupBase, rowOffset);
  }
  else
  {
    var_v0 = inline_fn23(rowOffset, D_800F2720);
    rowOffset = (arg1 & 0xFF) * 134;
  }
  *((u8 *) (var_v0 + temp_t0)) = (index >> 7) & 0x7F;
}

