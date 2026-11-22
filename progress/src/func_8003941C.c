void func_80043FA0(void);
void func_800723C0(f32 *, f32 *, f32 *, void **, s32);
void subdivideTriangle(f32, f32 *, f32 *, f32 *, void **, s32);
void buildRotationMatrixS16(s16 *, f32 *);
void rotateVec3ByMat3(f32 *, f32 *);
void func_8003941C(void **arg0, s32 arg1, f32 *arg2, f32 *arg3, s32 arg4)
{
  f32 sp18[54];
  u8 spF0[6];
  f32 spF8[12];
  s16 sp128[3];
  unsigned long var_s2;
  unsigned offset;
  register f32 *ent;
  s32 var_s1;
  register u8 *p;
  u32 *var_s6;
  u32 *var_s7;
  u8 done;
  s32 flags;
  f32 scale;
  done = 0;
  var_s1 = 0;
  if (((*arg0) != NULL) || ((func_80043FA0(), (*arg0) != NULL)))
  {
    var_s6 = *arg0;
    {
      f32 *angles = arg3;
      if (angles != NULL)
      {
        sp128[0] = (s16) angles[0];
        sp128[1] = (s16) angles[1];
        sp128[2] = (s16) angles[2];
        buildRotationMatrixS16(sp128, spF8);
      }
    }
    scale = 0.015625f;
    flags = (s8) arg4;
    var_s7 = var_s6 + 1;
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
            ent[0] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 0)))) * scale;
            ent[1] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 2)))) * scale;
            ent[2] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 4)))) * scale;
            ent[3] = (f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 8)));
            ent[4] = (f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 0xA)));
            ent[5] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xC];
            ent[6] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xD];
            ent[7] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xE];
            ent[8] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xF];
          }
          while (0);
          if (arg3 != NULL)
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
          if (flags)
        {
          subdivideTriangle(0.0f, &sp18[27], &sp18[36], &sp18[45], arg0, arg1);
        }
        else
        {
          func_800723C0(&sp18[27], &sp18[36], &sp18[45], arg0, arg1);
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
          ent[0] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 0)))) * scale;
          ent[1] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 2)))) * scale;
          ent[2] = ((f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 4)))) * scale;
          ent[3] = (f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 8)));
          ent[4] = (f32) (*((s16 *) (((u8 *) (var_s1 + (spF0[var_s2] * 16))) + 0xA)));
          ent[5] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xC];
          ent[6] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xD];
          ent[7] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xE];
          ent[8] = (f32) ((u8 *) (var_s1 + (spF0[var_s2] * 16)))[0xF];
          if (arg3 != ((unsigned) NULL))
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
          if (flags != 0)
        {
          subdivideTriangle(0.0f, &sp18[0], &sp18[9], &sp18[18], arg0, arg1);
        }
        else
        {
          func_800723C0(&sp18[0], &sp18[9], &sp18[18], arg0, arg1);
        }
          break;

        case 0xDF000000:
          done = 1;
          break;

      }

      var_s7 += 2;
      var_s6 += 2;
    }
    while ((done & 1) == 0);
  }
}


