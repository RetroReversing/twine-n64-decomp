void func_80095A80(u8, u8, u8, u8);
s32 func_800989B8(void);
extern char D_8010D734[];
extern char D_8010D748[];
extern char D_8010D784[];
extern unsigned char D_8010D76F[];
extern unsigned char D_8010D779[];
s32 func_8008E680(s32 arg0, s32 arg1)
{
  char index;
  s32 result = -1;
  s32 ret;
  s32 handle;
  u32 high;
  u32 low;
  ret = func_800989B8();
  if (ret != (-1))
  {
    high = ((u32) (arg1 & 0xffff)) >> 7;
    low = arg1 & 0x7f;
    again:
    handle = (u8) index;
    arg1 = (handle) * 0x1a0;

    index = ret;
    if ((*((s32 *) (D_8010D784 + arg1))) != ret)
    {
      goto done;
    }
    if ((*((s32 *) (D_8010D748 + arg1))) & 2)
    {
      result = (u8) index;
      func_80095A80(0x84, result, D_8010D779[arg1], high & 0xff);
      func_80095A80(0x85, result, D_8010D779[arg1], low & 0xff);
    }
    else
    {
      result = (u8) index;
      func_80095A80(0x84, result, D_8010D76F[arg1], high & 0xff);
      func_80095A80(0x85, result, D_8010D76F[arg1], low & 0xff);
    }
    ret = (u8) index;
    handle = *((s32 *) (D_8010D734 + ((ret) * 0x1a0)));
    result = 0;
    if (handle == (-1))
    {
      goto done;
    }
    goto again;
  }
  else
  {
    done:
    ret = result;

  }
  return ret;
}

