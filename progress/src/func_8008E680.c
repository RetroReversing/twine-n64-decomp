void func_80095A80(u8, u8, u8, u8);
s32 func_800989B8(void);
extern char D_8010D734[];
extern char D_8010D748[];
extern char D_8010D784[];
extern unsigned char D_8010D76F[];
extern unsigned char D_8010D779[];
s32 func_8008E680(s32 arg0, s32 arg1)
{
  s32 result = -1;
  s32 handle;
  s32 idx;
  s32 t;
  handle = func_800989B8();
  if (handle != -1)
  {
    while (handle != -1) {
    idx = handle & 0xff;
    arg0 = idx * 0x1a0;
    if ((*((s32 *) (D_8010D784 + arg0))) != handle)
    {
      return result;
    }
    if ((*((s32 *) (D_8010D748 + arg0))) & 2)
    {
      func_80095A80(0x84, idx, D_8010D779[arg0], ((u32)(arg1 & 0xffff)) >> 7);
      func_80095A80(0x85, idx, D_8010D779[arg0], arg1 & 0x7f);
    }
    else
    {
      func_80095A80(0x84, idx, D_8010D76F[arg0], ((u32)(arg1 & 0xffff)) >> 7);
      func_80095A80(0x85, idx, D_8010D76F[arg0], arg1 & 0x7f);
    }
    t = idx * 0x1a0;
    handle = *((s32 *) (D_8010D734 + t));
    result = 0;
    }
  }
  return result;
}
