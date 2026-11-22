typedef struct 
{
  u32 w0;
  u32 w1;
} Gfx34EFC;
extern Gfx34EFC * volatile sDisplayListCursor;
extern s16 D_8010D6F8;
extern s16 D_80108F80;
extern s16 D_8010A4B0;
extern s32 gHiResScreen;
extern s32 D_8010A4EC;
extern s32 D_80100304[];
s32 osVirtualToPhysical(s32);
void func_80034EFC(void)
{
  register Gfx34EFC *base = sDisplayListCursor;
  Gfx34EFC *cmd;
  s32 width;
  s32 height;
  s32 size;
  register long cycle;
  s32 buffer;
  s32 tag;
  s32 render = 0xE200001C;
  u32 modes = 0x0F0A4000;
  cycle = 0xE3000A01;
  sDisplayListCursor = base + 1; base[0].w0 = 0xE7000000;
  sDisplayListCursor = base + 2; base[1].w1 = 0x300000;
  sDisplayListCursor = base + 3; width = D_8010D6F8 - 1; height = D_80108F80 - 1;
  base[1].w0 = cycle; ((volatile Gfx34EFC *)base)[0].w1 = 0;
  size = 2;
  ((volatile Gfx34EFC *)base)[2].w0 = render;
  ((volatile Gfx34EFC *)base)[2].w1 = modes;
  if (D_8010A4EC)
  {
    size = ((-(gHiResScreen == 0)) & 3) | 2;
  }
  size <<= 19;
  tag = (width & 0xFFF) | 0xFF000000;
  buffer = D_8010A4B0;
  base[3].w0 = size | tag;
  sDisplayListCursor = base + 4; base[3].w1 = osVirtualToPhysical(D_80100304[buffer]);
  cmd = sDisplayListCursor; sDisplayListCursor = cmd + 1; cmd[0].w0 = 0xF7000000; sDisplayListCursor = cmd + 2;
  cmd[0].w1 = 0; cmd[1].w0 = (((width & 0x3FF) << 14) | 0xF6000000u) | ((height & 0x3FF) << 2); cmd[1].w1 = 0;
}

