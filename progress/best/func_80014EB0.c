typedef struct 
{
  f32 values[4];
} ClipBounds;
extern s32 func_8003F778(f32 *, void *, s32);
extern s32 func_8003F83C(f32 *, f32 *, s32);
extern void func_8003F918(f32, f32, f32, f32);
extern void func_80045514(void *, f32, f32);
extern void func_80082BD0();
extern u16 gSurfaceQueryStamp;
extern s32 D_800E09F0;
extern f32 D_800E0A00;
extern f32 D_800E0A24;
extern f32 D_800E0A48;
extern f32 D_800E0A6C;
extern f32 D_800E0B18;
extern f32 D_800E0B20;
extern s32 D_800E0C38;
extern f32 D_800E0C3C;
extern f32 D_800E09F8;
extern f32 D_80102D68;
extern f32 D_80102E68[];
extern ClipBounds D_80103F10[];
extern void *gObjectList;
extern s32 D_80109E1C;
extern void *D_8010D53C;
void func_80014EB0(void *arg0, ClipBounds *arg1)
{
  void *sp10[32];
  ClipBounds box;
  s8 spA7;
  s32 spAC;
  volatile s32 spD4;
  volatile s32 spDC;
  volatile s64 frameSpace[2];
  void *var_t0;
  f32 *scratch;
  void *var_s6;
  void *var_a1;
  void *var_a0;
  void *temp_s4;
  void *temp_a0;
  void *temp_a3;
  void *temp_v1;
  s32 temp_s3;
  s32 temp_v0;
  s32 var_s7;
  s32 i;
  s32 j;
  f32 temp_ft0;
  spAC = 0;
  D_800E0C38 += 1;
  if (D_800E09F0 == 0)
  {
    var_a1 = *((void **) arg0);
    if (var_a1 != NULL)
    {
      do
      {
        s32 flags = *((s32 *) (((u8 *) var_a1) + 0x58));
        if (!(flags & 0x20000))
        {
          goto nextHead;
        }
        if (!(flags & 0x800))
        {
          if (arg1)
          {
            temp_v1 = gObjectList;
            *((s32 *) (((u8 *) var_a1) + 0x58)) = flags | 0x800;
            gObjectList = var_a1;
            *((void **) (((u8 *) var_a1) + 0x1C)) = temp_v1;
          }
          else
          {
            temp_v1 = gObjectList;
            *((s32 *) (((u8 *) var_a1) + 0x58)) = flags | 0x800;
            gObjectList = var_a1;
            *((void **) (((u8 *) var_a1) + 0x1C)) = temp_v1;
          }
        }
        nextHead:
        var_a1 = *((void **) var_a1);

      }
      while (var_a1 != NULL);
    }
  }
  temp_v0 = D_800E09F0 + 1;
  D_800E09F0 = temp_v0;
  if (temp_v0 >= 0x40)
  {
    return;
  }
  if (arg0 != NULL)
  {
    do
    {
      var_s6 = *((void **) (((u8 *) (*((void **) (((u8 *) arg0) + 0x20)))) + 0x58));
      if (D_80109E1C != 0x40)
      {
        ((void **) (&D_80102D68))[D_80109E1C] = arg0; D_80103F10[D_80109E1C] = *arg1; D_80109E1C += 1;
        if (var_s6 != NULL)
        {
          scratch = D_80102E68; var_t0 = &D_800E09F8;
          do
          {
            var_a0 = *((void **) (*((void **) (((u8 *) var_s6) + 8))));
            if (var_a0 != NULL)
            {
              do
              {
                s32 flags = *((s32 *) (((u8 *) var_a0) + 0x58));
                if (!(flags & 0x20000))
                {
                  goto nextChild;
                }
                if (!(flags & 0x800))
                {
                  temp_v1 = gObjectList;
                  *((s32 *) (((u8 *) var_a0) + 0x58)) = flags | 0x800; gObjectList = var_a0;
                  *((void **) (((u8 *) var_a0) + 0x1C)) = temp_v1;
                }
                nextChild:
                var_a0 = *((void **) var_a0);

              }
              while (var_a0 != NULL);
            }
            temp_ft0 = ((((*((f32 *) (((u8 *) D_8010D53C) + 0x10))) * (*((f32 *) (((u8 *) var_s6) + 0xC)))) + ((*((f32 *) (((u8 *) D_8010D53C) + 0x14))) * (*((f32 *) (((u8 *) var_s6) + 0x10))))) + ((*((f32 *) (((u8 *) D_8010D53C) + 0x18))) * (*((f32 *) (((u8 *) var_s6) + 0x14))))) + (*((f32 *) (((u8 *) var_s6) + 0x18))); D_800E0C3C = temp_ft0;
            if (!(temp_ft0 > (-0.2f)))
            {
              goto nextRegion;
            }
            temp_a0 = *((void **) (((u8 *) var_s6) + 0x1C));
            if (temp_a0 != NULL)
            {
              if (!((*((s32 *) (((u8 *) temp_a0) + 0x58))) & 0x800))
              {
                temp_v1 = gObjectList;
                *((s32 *) (((u8 *) temp_a0) + 0x58)) |= 0x800; gObjectList = temp_a0;
                *((void **) (((u8 *) temp_a0) + 0x1C)) = temp_v1;
              }
              if ((*((s16 *) (((u8 *) temp_a0) + 0x7A))) == 0)
              {
                goto nextRegion;
              }
            }
            {
              box.values[0] = *((f32 *) (((u8 *) D_8010D53C) + 0x54)); box.values[1] = *((f32 *) (((u8 *) D_8010D53C) + 0x50)); box.values[2] = *((f32 *) (((u8 *) D_8010D53C) + 0x5C)); box.values[3] = *((f32 *) (((u8 *) D_8010D53C) + 0x58)); temp_s4 = *((void **) ((*((void **) (((u8 *) var_s6) + 4))) + 0x3C)); var_s7 = 0;
              if (D_800E0C3C < 0.4f)
              {
                box.values[0] = arg1->values[0]; box.values[1] = arg1->values[1]; box.values[2] = arg1->values[2]; box.values[3] = arg1->values[3];
                goto block_51;
              }
              else
              {
                spA7 = 0;
                if (((s32) (*((u16 *) (((u8 *) temp_s4) + 0x40)))) > 0)
                {
                  spD4 = 0; spDC = 0;
                  do
                  {
                    void *var_a0_2 = NULL;
                    void *var_v1 = NULL;
                    int var_a1_2;
                    u16 var_s0;
                    u16 var_s1;
                    s32 var_v0;
                    f32 *temp_v1_4;
                    if ((*((u8 *) (((u8 *) temp_s4) + 0x48))) & 4)
                    {
                      if (D_8010D53C)
                      {
                        var_v1 = ((u8 *) (*((void **) ((0, ((u8 *) temp_s4) + 0x3C))))) + spDC;
                      }
                      else
                      {
                        var_v1 = ((u8 *) (*((void **) ((0, ((u8 *) temp_s4) + 0x3C))))) + spDC;
                      }
                    }
                    else
                    {
                      var_a0_2 = ((u8 *) (*((void **) (((u8 *) temp_s4) + 0x3C)))) + spD4;
                    }
                    if (var_v1 != NULL)
                    {
                      var_a1_2 = *((u16 *) var_v1); var_s0 = *((u16 *) (((u8 *) var_v1) + 2)); var_s1 = *((u16 *) (((u8 *) var_v1) + 4)); var_v0 = var_a1_2 * 2;
                    }
                    else
                    {
                      var_a1_2 = *((u8 *) var_a0_2); var_s0 = *(((u8 *) var_a0_2) + 1); var_s1 = *(((u8 *) var_a0_2) + 2); var_v0 = var_a1_2 * 2;
                    }
                    temp_v1_4 = (f32 *) ((*((s32 *) (((u8 *) temp_s4) + 0x34))) + ((var_v0 + var_a1_2) * 4)); scratch[0] = temp_v1_4[0];
                    scratch[1] = temp_v1_4[1];
                    scratch[2] = temp_v1_4[2];
                    func_80082BD0();
                    ((f32 *) var_t0)[0] = scratch[3];
                    ((f32 *) var_t0)[1] = scratch[4];
                    ((f32 *) var_t0)[2] = scratch[5]; temp_v1_4 = (f32 *) ((*((s32 *) (((u8 *) temp_s4) + 0x34))) + (var_s0 * 0xC)); scratch[0] = temp_v1_4[0];
                    scratch[1] = temp_v1_4[1];
                    scratch[2] = temp_v1_4[2];
                    func_80082BD0();
                    ((f32 *) var_t0)[9] = scratch[3];
                    ((f32 *) var_t0)[10] = scratch[4];
                    ((f32 *) var_t0)[11] = scratch[5]; temp_v1_4 = (f32 *) ((*((s32 *) (((u8 *) temp_s4) + 0x34))) + (var_s1 * 0xC)); scratch[0] = temp_v1_4[0];
                    scratch[1] = temp_v1_4[1];
                    scratch[2] = temp_v1_4[2];
                    func_80082BD0();
                    ((f32 *) var_t0)[18] = scratch[3];
                    ((f32 *) var_t0)[19] = scratch[4];
                    ((f32 *) var_t0)[20] = scratch[5]; temp_s3 = func_8003F778(&D_800E0B18, var_t0, 3);
                    if (temp_s3 > 0)
                    {
                      s32 offset;
                      for (i = 0, offset = 0; i < temp_s3; offset += 0x24, i++)
                      {
                        f32 tmp = *((f32 *) (((u8 *) (&D_800E0B20)) + offset));
                        f32 a = (*((f32 *) (((u8 *) D_8010D53C) + 0x68))) / tmp;
                        f32 b = (*((f32 *) (((u8 *) D_8010D53C) + 0x6C))) / tmp;
                        func_80045514((&D_800E0B18) + ((i * 3) * 3), a, b);
                      }

                      func_8003F918(arg1->values[0], arg1->values[2], arg1->values[1], arg1->values[3]);
                      temp_s3 = func_8003F83C(&D_800E0B18, &D_800E0B18, temp_s3);
                      if (temp_s3 > 0)
                      {
                        for (j = 0; j < temp_s3; j++)
                        {
                          f32 *p = (&D_800E0B18) + (j * 9);
                          if (p[0] < box.values[0])
                          {
                            box.values[0] = p[0];
                          }
                          if (p[0] > box.values[1])
                          {
                            box.values[1] = p[0];
                          }
                          if (p[1] < box.values[2])
                          {
                            box.values[2] = p[1];
                          }
                          if (p[1] > box.values[3])
                          {
                            box.values[3] = p[1];
                          }
                        }

                        spA7 = 1;
                      }
                    }
                    if (D_80109E1C)
                    {
                      spD4 += 3;
                      var_s7 += 1;
                      spDC += 6;
                    }
                    else
                    {
                      spD4 += 3;
                      var_s7 += 1;
                      spDC += 6;
                    }
                  }
                  while (var_s7 < ((s32) (*((u16 *) (((u8 *) temp_s4) + 0x40)))));
                }
                if (spA7 == 1)
                {
                  goto block_51;
                }
              }
              if (0)
              {
                block_51:
                if (((box.values[1] - box.values[0]) > 0.0f) && ((box.values[3] - box.values[2]) > 0.0f))
                {
                  f32 fv = D_800E0A00;
                  temp_a3 = *((void **) (((u8 *) var_s6) + 8));
                  if (fv < D_800E0A24)
                  {
                    fv = D_800E0A24;
                  }
                  if (fv < D_800E0A48)
                  {
                    fv = D_800E0A48;
                  }
                  if (fv < D_800E0A6C)
                  {
                    fv = D_800E0A6C;
                  }
                  if ((*((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0x54))) < fv)
                  {
                    *((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0x54)) = fv;
                  }
                  temp_a0 = *((void **) (((u8 *) temp_a3) + 0x20));
                  if ((*((u16 *) (((u8 *) temp_a0) + 0x60))) != gSurfaceQueryStamp)
                  {
                    *((u16 *) (((u8 *) temp_a0) + 0x60)) = gSurfaceQueryStamp;
                    *((ClipBounds *) (*((void **) (((u8 *) temp_a3) + 0x20)))) = box;
                    *((u16 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0x62)) = (u16) D_800E0C38; sp10[spAC] = temp_a3;
                    spAC += 1;
                  }
                  else
                  {
                    s32 changed = 0;
                    if (box.values[0] < (*((f32 *) (((u8 *) temp_a0) + 0))))
                    {
                      *((f32 *) (((u8 *) temp_a0) + 0)) = box.values[0]; changed = 1;
                    }
                    if (box.values[2] < (*((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 8))))
                    {
                      *((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 8)) = box.values[2]; changed = 1;
                    }
                    if (box.values[1] > (*((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 4))))
                    {
                      *((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 4)) = box.values[1]; changed = 1;
                    }
                    if ((*((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0xC))) < box.values[3])
                    {
                      *((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0xC)) = box.values[3]; changed = 1;
                    }
                    temp_a0 = *((void **) (((u8 *) temp_a3) + 0x20));
                    if ((*((u16 *) (((u8 *) temp_a0) + 0x62))) != D_800E0C38)
                    {
                      *((u16 *) (((u8 *) temp_a0) + 0x62)) = (u16) D_800E0C38;
                      if (changed != 0)
                      {
                        sp10[spAC] = temp_a3;
                        spAC += 1;
                      }
                    }
                  }
                }

              }
            }
            nextRegion:
            var_s6 = *((void **) var_s6);

          }
          while (var_s6 != NULL);
        }
        for (i = 0; i < spAC; i++)
        {
          void *n = sp10[i];
          void *b = *((void **) (((u8 *) n) + 0x20));
          box = *((ClipBounds *) b);
          func_80014EB0(sp10[i], &box);
        }

      }
    }
    while (0);
  }
}

