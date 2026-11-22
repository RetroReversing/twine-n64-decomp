s32 applyEnemyKindMode(void *);
f32 approxDistance(void *, void *);
f32 func_80045590(void *, void *);
s32 func_800643EC(void *);
s32 func_80064860(void *, u8, u8);
s32 func_800648FC(void *, s32);
s32 func_80067A24(void *, u16);
s32 func_80067A7C(void *, void *, u16);
void func_8006832C(void *, void *);
s32 func_8007A9CC(void *, void *, s32 *, f32);
volatile short func_800818AC(int, s32);
s32 func_8008194C(int, s32);
s32 func_80081AA4(s32, s32);
s32 func_80082834(s8, s32, u8);
s32 func_80084338(u16, void *);
s32 listUnlinkFree(s32);
s32 markObjectsNearPos(s32, s32, s32, void *, s32, s32);
s32 requestSound(u16);
extern s32 D_800E1A28;
extern s32 D_800E1A2C;
extern u8 gWheelsGrounded;
extern s32 sEnemyDefTable;
extern void *sTrackMarkerTable[];
inline static int inline_fn(s32 arg0)
{
  return arg0 > 0;
}

inline static char *inline_fn2(char *arg0, int arg1)
{
  return arg0 + arg1;
}

inline static char *inline_fn23(char *arg0, int arg1)
{
  return arg0 + arg1;
}

inline static int inline_fn234(void *arg0)
{
  return (*((u16 *) inline_fn2((char *) arg0, 0x34))) == 0;
}

void func_8006899C(void *arg0, u8 arg1)
{
  s16 __repair_store_0;
  s16 __repair_store_1;
  s32 sp28;
  s32 sp2C;
  u8 sp37;
  s16 temp_v0_10;
  s16 temp_v0_3;
  s16 temp_v0_4;
  s16 temp_v0_8;
  s16 temp_v0_9;
  s16 temp_v1_4;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a0_3;
  s32 temp_a0_4;
  s32 temp_v0_6;
  s32 temp_v0_7;
  s32 var_a0;
  s32 var_s6;
  s32 temp_fp;
  u16 temp_a0_5;
  u16 temp_v0_11;
  s32 temp_v1;
  u16 var_a0_2;
  u8 temp_a1_2;
  u8 temp_a1_3;
  u8 temp_v0_2;
  u8 temp_v0_5;
  void **temp_v0;
  volatile f32 cameraAngles[3];
  void **var_a3;
  void *temp_a1;
  void *temp_s0;
  void *temp_s0_2;
  void *temp_s2;
  void *temp_s4;
  void *temp_s7;
  void *temp_v1_2;
  void *temp_v1_3;
  void *var_s1;
  void *var_s5;
  temp_s2 = *((void **) (((char *) arg0) + 0x6C));
  temp_fp = *((s8 *) inline_fn2((char *) temp_s2, 0x182));
  temp_v0 = &sTrackMarkerTable[temp_fp];
  {
    void *marker = *temp_v0;
    void *actor = *(void **)((char *)arg0 + 0x68);
    f32 yaw = *(f32 *)((char *)marker + 0x34);
    s32 kind = *(s8 *)((char *)actor + 0xE);
    cameraAngles[0] = yaw;
    marker = *temp_v0;
    var_s6 = 1;
    sp37 = arg1;
    cameraAngles[1] = *(f32 *)((char *)marker + 0x38);
    temp_s4 = (char *)&sEnemyDefTable + kind * 0xE8;
  }
  cameraAngles[2] = 0.0f;
  if (func_80081AA4(temp_fp, 0x12) != 0)
  {
    var_a3 = *((void ***) inline_fn2((char *) arg0, 0x20));
    var_s5 = *((void **) inline_fn2((char *) (*((void **) inline_fn2((char *) var_a3, 0x20))), 0x58));
    if (var_a3 != NULL)
    {
      temp_s7 = inline_fn23(arg0, 0x24);
      do
      {
        var_s1 = *var_a3;
        if (var_s1 != NULL)
        {
          do
          {
            temp_v1 = *((u16 *) inline_fn23((char *) var_s1, 0x78));
            if (((s32) temp_v1) < 0x13)
            {
              if (((s32) temp_v1) >= 0x10)
              {
                goto block_10;
              }
              if (temp_v1 == 0xB)
              {
                goto special;
              }
              goto next_object;
            }
            if (((s32) temp_v1) >= 0x61)
            {
              goto next_object;
            }
            if (((s32) temp_v1) < 0x5E)
            {
              goto next_object;
            }
            block_10:
            if (((*((s32 *) inline_fn2((char *) var_s1, 0x20))) == (*((void ***) inline_fn2((char *) arg0, 0x20)))) && ((*((s32 *) inline_fn23((char *) (*((void **) inline_fn2((char *) var_s1, 0x6C))), 0x2C))) & 0x800))
            {
              temp_s0_2 = inline_fn2(var_s1, 0x24);
              if (((func_8007A9CC(arg0, temp_s0_2, &sp28, 1024.0f) << 0x18) != 0) && (approxDistance(temp_s0_2, inline_fn2(arg0, 0x24)) < 1.5f))
              {
                var_s6 = 0;
                *((s32 *) inline_fn2((char *) var_s1, 0x60)) = (s32) ((*((s32 *) inline_fn2((char *) var_s1, 0x60))) | 0x800);
              }
            }

            goto next_object;
            special:
            temp_a1 = *((void **) inline_fn23((char *) var_s1, 0x6C));

            temp_v0_2 = *((u8 *) (((char *) temp_a1) + 0x4A));
            var_a0 = 1;
            switch (temp_v0_2)
            {
              case 4:
              case 5:
              case 16:
              case 17:
                var_a0 &= -inline_fn234(temp_a1);
                break;

              case 18:

              case 19:

              case 20:

              default:
                var_a0 = 0;
                break;

            }

            if ((var_a0 << 0x18) != 0)
            {
              temp_s0 = inline_fn23(var_s1, 0x24);
              if ((((func_8007A9CC(arg0, temp_s0, &sp2C, 1024.0f) << 0x18) != 0) && (approxDistance(temp_s0, temp_s7) < 3.0f)) && (func_80045590(temp_s0, temp_s7) < 2.0f))
              {
                temp_v0_3 = *((s16 *) inline_fn23((char *) var_s1, 0x7A));
                if (((temp_v0_3 == 0) | (temp_v0_3 == 4)) != 0)
                {
                  if ((*((void ***) inline_fn2((char *) arg0, 0x20))) == (*((s32 *) (((char *) var_s1) + 0x20))))
                  {
                    *((s32 *) inline_fn2((char *) var_s1, 0x60)) = (*((s32 *) inline_fn2((char *) var_s1, 0x60))) | 8;
                  }
                  else
                  {
                    *((s32 *) inline_fn23((char *) var_s1, 0x60)) = (*((s32 *) inline_fn23((char *) var_s1, 0x60))) & (~8);
                  }
                  markObjectsNearPos(*((s32 *) inline_fn2((char *) var_s1, 0x20)), 2, 0x20000, var_s1 + 0x24, 0, 1);
                  var_s6 = 0;
                  *((s32 *) inline_fn2((char *) var_s1, 0x60)) = (s32) ((*((s32 *) inline_fn2((char *) var_s1, 0x60))) | 0x800);
                }
              }
            }
            next_object:
            var_s1 = *((void **) inline_fn2((char *) var_s1, 0));

          }
          while (var_s1 != NULL);
        }
        var_a3 = NULL;
        if (var_s5 != NULL)
        {
          var_a3 = *((void ***) (((char *) var_s5) + 8));
          var_s5 = *((void **) inline_fn2((char *) var_s5, 0));
        }
      }
      while (var_a3 != NULL);
    }
  }
  temp_v0_4 = *((s16 *) inline_fn2((char *) temp_s2, 0x176));
  if (temp_v0_4 >= 0)
  {
    *((s16 *) inline_fn2((char *) temp_s2, 0x176)) = (s16) (temp_v0_4 - 1);
    return;
  }
  if (var_s6 != 0)
  {
    if ((func_80081AA4(temp_fp, 0x12) != 0) && ((*((s16 *) (((char *) (*((void **) inline_fn2((char *) temp_s2, 0xA8)))) + 0x7A))) == 0))
    {
      if ((func_800648FC(arg0, 1) << 0x18) != 0)
      {
        temp_a0 = *((s32 *) inline_fn2((char *) temp_s2, 8));
        *((s16 *) inline_fn23((char *) temp_s2, 0x176)) = (s16) (*((u8 *) inline_fn2((char *) temp_s4, 0x36)));
        if (temp_a0 != (-1))
        {
          listUnlinkFree(temp_a0);
          *((s32 *) inline_fn2((char *) temp_s2, 8)) = -1;
        }
        temp_v1_2 = *((void **) (((char *) temp_s2) + 0xA8));
        *((u16 *) inline_fn2((char *) temp_s2, 0x17A)) = (u16) (*((u16 *) (((char *) (((*((u8 *) inline_fn2((char *) (temp_s2 - (-((*((s8 *) inline_fn2((char *) (*((void **) (((char *) arg0) + 0x68))), 0xE))) * 8))), 0x1FD))) * 2) + temp_s4)) + 0x24)));
        if (temp_v1_2 != NULL)
        {
          *((s16 *) inline_fn23((char *) temp_v1_2, 0x7A)) = 5;
          func_80067A24(*((void **) (((char *) temp_s2) + 0xA8)), *((u16 *) inline_fn23((char *) temp_s4, 0x94)));
        }
        else
          if ((*((u16 *) inline_fn2((char *) arg0, 0x78))) == 3)
        {
          func_80084338(*((u16 *) inline_fn23((char *) temp_s4, 0x54)), arg0 + 0x24);
        }
        else
        {
          requestSound(*((u16 *) inline_fn23((char *) temp_s4, 0x54)));
        }
      }
    }
  }
  if (func_8008194C(temp_fp, 0xE) == 0)
  {
    if (var_s1 || temp_s4)
    {
      *((u16 *) inline_fn2((char *) temp_s2, 0x17A)) = 0U;
      goto block_61;
    }
    else
    {
      *((u16 *) inline_fn2((char *) temp_s2, 0x17A)) = 0U;
      goto block_61;
    }
  }
  if ((func_80064860(arg0, *((u8 *) inline_fn2((char *) temp_s4, 0x81)), 0U) << 0x18) == 0)
  {
    if (((*((s8 *) inline_fn2((char *) (*((void **) inline_fn2((char *) arg0, 0x68))), 0xE))) != 0x1C) || (func_800818AC(temp_fp, 0x18) == 0))
    {
      temp_v0_5 = (*((u8 *) inline_fn2((char *) temp_s2, 0x19A))) - 1;
      *((u8 *) inline_fn23((char *) temp_s2, 0x19A)) = temp_v0_5;
      if (temp_v0_5 & 0x80)
      {
        *((u8 *) inline_fn23((char *) temp_s2, 0x19A)) = 0xFU;
        if ((*((u16 *) (((char *) arg0) + 0x78))) == 3)
        {
          func_80084338(*((u16 *) inline_fn23((char *) temp_s4, 0x56)), arg0 + 0x24);
        }
        else
        {
          requestSound(*((u16 *) (((char *) temp_s4) + 0x56)));
        }
      }
    }
    goto block_62;
  }
  temp_v0_6 = *((s32 *) inline_fn23((char *) temp_s2, 0x10));
  temp_v0_7 = temp_v0_6 - 1;
  if (inline_fn(temp_v0_6))
  {
    *((s32 *) inline_fn2((char *) temp_s2, 0x10)) = temp_v0_7;
    if (temp_v0_7 == 0)
    {
      if (inline_fn(*((s16 *) inline_fn23((char *) temp_s4, 0x34))))
      {
        if ((*((s16 *) inline_fn2((char *) (*((void **) inline_fn2((char *) temp_s2, 0xA8))), 0x7A))) != 0)
        {
          return;
        }
        goto block_76;
      }
      goto block_62;
    }
  }
  block_61:
  block_62:
  if ((func_8008194C(temp_fp, 0xE) == 0) && ((func_80064860(arg0, *((u8 *) inline_fn2((char *) temp_s4, 0x81)), 0U) << 0x18) == 0))
  {
    if (((*((s16 *) inline_fn2((char *) (*((void **) (((char *) temp_s2) + 0xA8))), 0x7A))) == 0) && (((*((s8 *) inline_fn2((char *) (*((void **) inline_fn2((char *) arg0, 0x68))), 0xE))) != 0x1C) || (func_800818AC(temp_fp, 0x18) == 0)))
    {
      temp_a0_2 = *((s32 *) inline_fn2((char *) temp_s2, 8));
      if (temp_a0_2 != (-1))
      {
        listUnlinkFree(temp_a0_2);
        *((s32 *) inline_fn2((char *) temp_s2, 8)) = -1;
      }
      if ((func_800648FC(arg0, 1) << 0x18) != 0)
      {
        __repair_store_0 = (s16) (*((u8 *) (((char *) temp_s4) + 0x36)));
        __repair_store_1 = (s16) (*((u8 *) inline_fn23((char *) temp_s4, 0x36)));
        *((s16 *) (((char *) temp_s2) + 0x176)) = __repair_store_0;
        *((s16 *) (((char *) temp_s2) + 0x176)) = __repair_store_1;
        temp_v1_3 = *((void **) (((char *) temp_s2) + 0xA8));
        *((s16 *) inline_fn2((char *) temp_s2, 0x178)) = 0;
        *((u16 *) (((char *) temp_s2) - (-0x17A))) = (u16) (*((u16 *) inline_fn2((char *) (((*((u8 *) (((char *) inline_fn23(temp_s2, (*((s8 *) (((char *) (*((void **) inline_fn2((char *) arg0, 0x68)))) + 0xE))) * 8)) + 0x1FD))) * 2) + temp_s4), 0x24)));
        if (temp_v1_3 != NULL)
        {
          *((s16 *) (((char *) temp_v1_3) + 0x7A)) = 5;
          func_80067A24(*((void **) inline_fn23((char *) temp_s2, 0xA8)), *((u16 *) (((char *) temp_s4) + 0x94)));
          return;
        }
        var_a0_2 = *((u16 *) inline_fn2((char *) temp_s4, 0x54));
        func_80084338(var_a0_2, inline_fn2(arg0, 0x24));
        return;
      }
      applyEnemyKindMode(arg0);
    }
  }
  else
  {
    if ((func_80081AA4(temp_fp, 0xE) != 0) || (((s8) sp37) == 1))
    {
      block_76:
      if (((*((s16 *) (((char *) temp_s2) + 0x176))) == (-1)) && (((s32) (*((s16 *) inline_fn2((char *) temp_s2, 0x178)))) == 0))
      {
        temp_v0_8 = *((s16 *) (((char *) temp_s4) + 0x34));
        if (inline_fn(temp_v0_8))
        {
          *((s32 *) (((char *) temp_s2) + 0x10)) = (s32) temp_v0_8;
        }
        temp_v0_9 = *((s16 *) inline_fn2((char *) (*((void **) inline_fn2((char *) temp_s2, 0xA8))), 0x7A));
        if (((temp_v0_9 == 0) | (temp_v0_9 == 7)) != 0)
        {
          temp_a1_2 = *((u8 *) (((char *) temp_s4) + 0x81));
          if ((func_80064860(arg0, temp_a1_2, temp_a1_2) << 0x18) != 0)
          {
            *((u16 *) inline_fn2((char *) temp_s2, 0x17A)) = (u16) (*((u16 *) inline_fn2((char *) (((*((u8 *) inline_fn2((char *) inline_fn2(temp_s2, (*((s8 *) inline_fn23((char *) (*((void **) inline_fn2((char *) arg0, 0x68))), 0xE))) * 8), 0x1FD))) * 2) + temp_s4), 0x24)));
            *((s16 *) inline_fn2((char *) temp_s2, 0x178)) = (s16) (*((s32 *) inline_fn2((char *) temp_s4, 0x30)));
            goto block_100;
          }
        }
        goto block_83;
      }

      goto block_83;
    }
    block_83:
    temp_v0_10 = *((s16 *) (((char *) temp_s2) + 0x178));

    if (inline_fn(temp_v0_10))
    {
      *((s16 *) inline_fn23((char *) temp_s2, 0x178)) = (s16) (temp_v0_10 - 1);
      temp_v1_4 = *((s16 *) inline_fn2((char *) (*((void **) inline_fn2((char *) temp_s2, 0xA8))), 0x7A));
      if (temp_v1_4 != 7)
      {
        if (!(temp_v1_4 >= 8))
        {
          if (temp_v1_4 != 0)
          {
            return;
          }
          goto block_91;
        }
        else
          if (temp_v1_4 == 9)
        {
          goto block_91;
        }
      }
      else
      {
        block_91:
        if ((*((s16 *) inline_fn2((char *) temp_s2, 0x178))) == 0)
        {
          temp_v0_11 = (*((u16 *) inline_fn2((char *) temp_s2, 0x17A))) - 1;
          *((u16 *) inline_fn2((char *) temp_s2, 0x17A)) = temp_v0_11;
          if ((temp_v0_11 << 0x10) <= 0)
          {
            temp_a0_3 = *((s32 *) inline_fn2((char *) temp_s2, 8));
            if (temp_a0_3 == (-1))
            {
              *((s16 *) inline_fn23((char *) temp_s2, 0x178)) = 0;
              return;
            }
            listUnlinkFree(temp_a0_3);
            *((s32 *) inline_fn2((char *) temp_s2, 8)) = -1;
            *((s16 *) inline_fn2((char *) temp_s2, 0x178)) = 0;
            return;
          }
          temp_a1_3 = *((u8 *) inline_fn23((char *) temp_s4, 0x81));
          if ((func_80064860(arg0, temp_a1_3, temp_a1_3) << 0x18) == 0)
          {
            temp_a0_4 = *((s32 *) inline_fn2((char *) temp_s2, 8));
            *((u16 *) inline_fn2((char *) temp_s2, 0x17A)) = (u16) ((*((u16 *) (((char *) temp_s2) + 0x17A))) + 1);
            *((s16 *) inline_fn2((char *) temp_s2, 0x178)) = (s16) (*((s32 *) (((char *) temp_s4) + 0x30)));
            if (temp_a0_4 != (-1))
            {
              listUnlinkFree(temp_a0_4);
              *((s32 *) (((char *) temp_s2) + 8)) = -1;
            }
          }
          else
          {
            block_100:
            if ((gWheelsGrounded == 0) && (!((*((s32 *) inline_fn2((char *) temp_s4, 0x60))) & 0x80)))
            {
              if ((*((u16 *) inline_fn2((char *) arg0, 0x78))) == 3)
              {
                var_a0_2 = *((u16 *) inline_fn23((char *) temp_s4, 0x56));
                func_80084338(var_a0_2, inline_fn2(arg0, 0x24));
                return;
              }
              requestSound(*((u16 *) inline_fn23((char *) temp_s4, 0x56)));
              return;
            }

            D_800E1A28 |= 0x10000;
            D_800E1A2C = (s32) (*((u8 *) inline_fn2((char *) temp_s4, 0x5E)));
            temp_a0_5 = *((u16 *) inline_fn2((char *) (((*((u8 *) (((char *) inline_fn2(temp_s2, (*((s8 *) inline_fn2((char *) (*((void **) inline_fn2((char *) arg0, 0x68))), 0xE))) * 8)) + 0x1FD))) * 2) + temp_s4), 0x4E));
            if ((temp_a0_5 != 0) && ((*((s32 *) inline_fn2((char *) temp_s2, 8))) == (-1)))
            {
              if ((*((u16 *) inline_fn2((char *) arg0, 0x78))) == 3)
              {
                *((s32 *) (((char *) temp_s2) + 8)) = func_80084338(*((u16 *) inline_fn2((char *) temp_s4, 0x58)), inline_fn23(arg0, 0x24));
              }
              else
              {
                *((s32 *) inline_fn2((char *) temp_s2, 8)) = requestSound(temp_a0_5);
              }
            }
            if ((*((u16 *) inline_fn2((char *) arg0, 0x78))) == 2)
            {
              func_80082834(temp_fp, 5, *((u8 *) inline_fn2((char *) temp_s4, 0x84)));
            }
            *((s16 *) inline_fn2((char *) temp_s2, 0x178)) = (s16) (*((s32 *) inline_fn2((char *) temp_s4, 0x30)));
            func_80067A7C(temp_s2, *((void **) inline_fn23((char *) temp_s2, 0xA8)), *((u16 *) inline_fn2((char *) temp_s4, 0x96)));
            if ((*((s32 *) (((char *) temp_s4) + 0x60))) & 0x4000)
            {
              *((s16 *) inline_fn2((char *) (*((void **) (((char *) temp_s2) + 0xA8))), 0x7A)) = 9;
              return;
            }
            func_8006832C(arg0, temp_s4);
          }
        }

      }
    }
    else
      if ((*((s16 *) inline_fn2((char *) temp_s2, 0x176))) <= 0)
    {
      func_800643EC(arg0);
    }
  }


}


