typedef struct { s32 w0; s32 w1; } Gfx;
typedef struct { s32 x; } W;
s32 emitScissorFromWindow();
void emit_projection_viewport_commands(void);
void func_80034928(s32, s32);
s32 func_80038FA4(void *);
extern s32 D_800B1AC8;
extern void *D_801002FC;
extern s32 D_801032A0;
extern void *D_8010A4B4;
extern W D_8010A4D8;
extern s32 D_8010A924;
extern s32 gRenderMode;
extern void * volatile sDisplayListCursor;
extern void *sRenderState;
void func_80037DC0(void *arg0)
{
  register s32 temp_a1;
  void *state;
  unsigned int var_a1;
  register s32 var_a3;
  s32 blue;
  int listAddress;
  void *tail;
  s32 temp_v1_3;
  void *temp_a0;
  void *temp_a2;
  register void *end;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_4;
  emitScissorFromWindow();
  if (gRenderMode != 1)
  {
    gRenderMode = 1;
    func_80038FA4(arg0);
  }
  if (D_8010A924 != 8)
  {
    temp_v1 = sDisplayListCursor;
    D_8010A924 = 8;
    sDisplayListCursor = temp_v1 + 8;
    *((s32 *) (((char *) temp_v1) + 0)) = 0xDE000000;
    *((s32 **) (((char *) temp_v1) + 4)) = &D_800B1AC8;
  }
  if (D_801032A0 != 2)
  {
    temp_v1_2 = sDisplayListCursor;
    D_801032A0 = 2;
    sDisplayListCursor = temp_v1_2 + 8;
    *((s32 *) (((char *) temp_v1_2) + 0)) = 0xFC419883;
    *((s32 *) (((char *) temp_v1_2) + 4)) = 0xFF32FF7F;
  }
  func_80034928((s32) arg0, 2);
  end = D_801002FC;
  *((s32 *) (((char *) end) + 0)) = 0xDF000000;
  *((s32 *) (((char *) end) + 4)) = 0;
  temp_v1_3 = *((s32 *) (((char *) arg0) + 0x100));
  D_801002FC = end + 8;
  if (temp_v1_3 & 2)
  {
    var_a3 = 0;
    var_a1 = 0;
    blue = 0xFF;
  }
  else
  {
    if (temp_v1_3 & 4)
        return;
    temp_v1_4 = sDisplayListCursor;
    sDisplayListCursor = temp_v1_4 + 8;
    *((s32 *) (((char *) temp_v1_4) + 0)) = 0xFB000000;
    *((s32 *) (((char *) temp_v1_4) + 4)) = 0xFF;
    var_a3 = 0xFF;
    blue = 0xFF;
    var_a1 = 0xFF;
  }
  {
    temp_a0 = sDisplayListCursor;

    *((s32 *) (((char *) temp_a0) + 0)) = 0xFA000000;
    {
      u32 packed = (var_a1 << 24) | (blue << 16);
      u32 green = var_a3 << 8;
      state = sRenderState;
      *((s32 *) (((char *) temp_a0) + 4)) = packed | green | 0xFF;
    }
    *((s32 *) (((char *) temp_a0) + 8)) = 0xFB000000;
    *((s32 *) (((char *) temp_a0) + 0xC)) = 0xFF;
    *((s32 *) (((char *) temp_a0) + 0x10)) = 0xDE000000;
    listAddress = *((s32 *) (((char *) state) + 0x1B68));
    temp_a1 = gRenderMode;
    sDisplayListCursor = temp_a0 + 8;
    sDisplayListCursor = temp_a0 + 0x10;
    sDisplayListCursor = temp_a0 + 0x18;
    *((s32 *) (((char *) temp_a0) + 0x14)) = listAddress;
    if (temp_a1 != 0)
    {
      gRenderMode = 0;
      emit_projection_viewport_commands();
    }
    {
    void *tailState;
    tail = D_8010A4B4;
    temp_a2 = sDisplayListCursor;
    tailState = sRenderState;
    *((s32 *) (((char *) tail) + 0)) = 0xDF000000;
    *((s32 *) (((char *) tail) + 4)) = 0;
    *((s32 *) (((char *) temp_a2) + 0)) = 0xDE000000;
    ((Gfx *)temp_a2)->w1 = *((s32 *) (((char *) tailState) + 0x1C70));
    D_8010A4B4 = tail + 8;
    sDisplayListCursor = temp_a2 + 8;
    temp_a1 = D_8010A4D8.x;
    temp_a2 += 8;
    func_80034928((s32) arg0, temp_a1);
    }
  }
}


