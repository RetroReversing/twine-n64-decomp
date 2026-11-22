void func_80043FA0(void);
void func_800723C0(f32 *, f32 *, f32 *, void **, s32);
void subdivideTriangle(f32, f32 *, f32 *, f32 *, void **, s32);
void buildRotationMatrixS16(s16 *, f32 *);
void rotateVec3ByMat3(f32 *, f32 *);
void func_8003941C(void **arg0, s32 arg1, f32 *arg2, f32 *arg3, s32 arg4)
{
  f32 sp18[54];
  volatile u8 spF0[6];
  f32 spF8[12];
  s16 sp128[3];
  unsigned long var_s2;
  unsigned offset;
  register s32 flags;
  register f32 *ent;
  s32 var_s1;
  register u8 *p;
  u32 *var_s6;
  u32 *var_s7;
  struct 
  {
    u32 pad0;
    volatile s32 mode;
    u32 pad8;
    f32 * volatile rotation;
    u8 pad10[7];
    volatile u8 done;
    u32 pad18;
    volatile s32 flags;
  } state;
  state.mode = arg1;
  state.rotation = arg3;
  state.done = 0;
  var_s1 = 0;
  flags = *(volatile s32 *)&arg4;
  if (((*arg0) != NULL) || ((func_80043FA0(), (*arg0) != NULL)))
  {
    var_s6 = *arg0;
    {
      f32 *angles = state.rotation;
      if (angles != NULL)
      {
        sp128[0] = (s16) angles[0];
        sp128[1] = (s16) angles[1];
        sp128[2] = (s16) angles[2];
        buildRotationMatrixS16(sp128, spF8);
      }
    }
    var_s7 = var_s6 + 1;
    state.flags = (s8) flags;
    do
    {
      switch (var_s6[0] & 0xFF000000)
      {
        case 0x1000000:
          var_s1 = var_s7[0] - 0x80000000;
          break;

        case 0x6000000:
          spF0[3] = (u8) ((var_s7[0] >> 17) & 0x7F);
          spF0[4] = (u8) ((var_s7[0] & 0xFF00) >> 9);
          spF0[5] = (u8) ((*(((u8 *) var_s7) + 3)) >> 1);
          var_s2 = 3;
          offset = 0x6C;
          do
        {
          do
          {
            ent = (f32 *) (((u8 *) sp18) + offset);
            ent[0] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 0)))) * 0.015625f;
            ent[1] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 2)))) * 0.015625f;
            ent[2] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 4)))) * 0.015625f;
            ent[3] = (f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 8)));
            ent[4] = (f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 0xA)));
            ent[5] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xC];
            ent[6] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xD];
            ent[7] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xE];
            ent[8] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xF];
          }
          while (0);
          if (state.rotation != NULL)
          {
            rotateVec3ByMat3(spF8, ent);
          }
          var_s2 += 1;
          if (arg2 != NULL)
          {
            ent[0] = ent[0] + arg2[0];
            ent[1] = ent[1] + arg2[1];
            ent[2] = ent[2] + arg2[2];
          }
          offset += 36;
        }
        while (6U > var_s2);
          if (state.flags)
        {
          subdivideTriangle(0.0f, &sp18[27], &sp18[36], &sp18[45], arg0, state.mode);
        }
        else
          if (arg4 || var_s2)
        {
          func_800723C0(&sp18[27], &sp18[36], &sp18[45], arg0, state.mode);
        }
        else
        {
          func_800723C0(&sp18[27], &sp18[36], &sp18[45], arg0, state.mode);
        }

        case 0x5:
          spF0[0] = (u8) ((var_s6[0] >> 17) & 0x7F);
          spF0[1] = (u8) ((var_s6[0] & 0xFF00) >> 9);
          spF0[2] = (u8) ((*(((u8 *) var_s6) + 3)) >> 1);
          var_s2 = 0;
          offset = 0;
          do
        {
          ent = (f32 *) (((u8 *) sp18) + offset);
          ent[0] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 0)))) * 0.015625f;
          ent[1] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 2)))) * 0.015625f;
          ent[2] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 4)))) * 0.015625f;
          ent[3] = (f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 8)));
          ent[4] = (f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 0xA)));
          ent[5] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xC];
          ent[6] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xD];
          ent[7] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xE];
          ent[8] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xF];
          if (state.rotation != ((unsigned) NULL))
          {
            rotateVec3ByMat3(spF8, ent);
          }
          var_s2 += 1;
          if (arg2 != NULL)
          {
            ent[0] = ent[0] + arg2[0];
            ent[1] = ent[1] + arg2[1];
            ent[2] = ent[2] + arg2[2];
          }
          offset += 36;
        }
        while (3U > var_s2);
          if (state.flags != 0)
        {
          subdivideTriangle(0.0f, &sp18[0], &sp18[9], &sp18[18], arg0, state.mode);
        }
        else
        {
          func_800723C0(&sp18[0], &sp18[9], &sp18[18], arg0, state.mode);
        }
          break;

        case 0xDF000000:
          state.done = 1;
          break;

      }

      var_s7 += 2;
      var_s6 += 2;
    }
    while (!state.done);
  }
}


