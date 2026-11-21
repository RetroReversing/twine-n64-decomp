s32 func_8008D49C(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80091A24(void *, s32, s32);
s32 voiceStoreParam(s32, u8, u8, s32);
extern u8 D_800EDA87;
extern u8 D_800EDA88;
extern void *gFreeSndNodeList;
extern void * volatile gSeqPlayer;
typedef struct 
{
  s32 w[2];
} __repair_words2;
inline static s32 inline_fn(char *arg0)
{
  return *((s32 *) (arg0 + 0x574));
}

inline static int inline_fn2(s32 arg0)
{
  return arg0 == 1;
}

inline static int inline_fn23(int arg0)
{
  return arg0;
}

typedef struct { s32 v; } Field_s32;
typedef struct { s8 v; } Field_s8;
typedef struct { u16 v; } Field_u16;
typedef struct { u32 v; } Field_u32;
typedef struct { u8 v; } Field_u8;
s32 func_8008FB20(void)
{
  s32 temp_a0;
  void *temp_v0_2;
  s32 temp_a0_4;
  s32 temp_a1_2;
  s32 temp_a3_2;
  register s32 temp_t1_2;
  s32 temp_v0_6;
  u32 temp_v1;
  s32 var_a0;
  s32 var_s2;
  s32 var_s4;
  s32 var_s6;
  s32 var_s7;
  s32 var_v0_2;
  s32 var_v1;
  unsigned temp_s1;
  u8 temp_a0_2;
  u8 temp_a0_3;
  u8 temp_a1;
  s32 temp_a3;
  s32 temp_t1;
  s32 temp_t2;
  s32 var_v0;
  void **temp_v1_4;
  void *temp_t0;
  void *temp_t0_2;
  void *temp_t0_3;
  void *temp_v0;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_5;
  void *var_a2;
  var_s7 = 0;
  var_s6 = 0;
  var_s2 = 0;
  do
  {
    temp_t0 = gSeqPlayer;
    if ((*((s32 *) (((char *) (temp_t0 - (-var_s2))) + 0x574))) != 0)
    {
      var_s7 = 1;
      var_a2 = temp_t0 + var_s2;
      for (;;)
      {
        temp_s1 = (*((u16 *) (((char *) (*((void **) (((char *) var_a2) + 0x574)))) + 0))) + ((((Field_u32 *) (((char *) var_a2) + 0x570))->v));
        if (((u32) (((((Field_s32 *) (((char *) var_a2) + 0x56C))->v)) + ((((Field_s32 *) (((char *) temp_t0) + 0x120))->v)))) >= temp_s1)
        {
          (((Field_u32 *) (((char *) var_a2) + 0x570))->v) = temp_s1;
          temp_v0 = *((void **) (((char *) var_a2) + 0x574));
          temp_a3 = (((Field_u8 *) (((char *) temp_v0) + 2))->v);
          temp_a1 = (((Field_u8 *) (((char *) var_a2) + 0x58C))->v);
          temp_t1 = (((Field_u8 *) (((char *) temp_v0) + 3))->v);
          if ((temp_a3 == 0xFF) & (temp_t1 == 0xFF))
          {
            *((void **) (((char *) var_a2) + 0x574)) = NULL;
          }
          else
          {
            temp_v1 = (temp_a3 >> 7) & 1;
            var_s4 = 4;
            if (inline_fn23(temp_v1 & (temp_t1 == 0)))
            {
              temp_a1_2 = temp_a1 & 0xFF;
              temp_a0 = temp_a3 & 0x7F;
              if (temp_a1_2 != 9)
              {
                temp_a0_2 = *((u8 *) (((char *) (temp_a0 + temp_t0)) + 8));
                if (temp_a0_2 != 0xFF)
                {
 do { temp_v0_2 = (void *) (temp_a0_2 * 8); temp_v0_2 = (void *) (((char *) temp_v0_2) + ((s32) (*((char **) (((char *) temp_t0) + 4))))); *((s32 *) (((char *) ((temp_a1_2 * 4) + temp_t0)) + 0xF80)) = (s32) (((((((Field_u16 *) (((char *) temp_v0_2) + 0))->v)) << 0x10) | (((((Field_u8 *) (((char *) temp_v0_2) + 2))->v)) << 8)) | ((((Field_u8 *) (((char *) temp_v0_2) + 3))->v))); } while (0);
                }
              }
              else
              {
                temp_a0_3 = *((u8 *) (((char *) (temp_a0 + temp_t0)) + 0x8C));
                if (temp_a0_3 != 0xFF)
                {
                  temp_v0_3 = (void *) (temp_a0_3 * 8); temp_v0_3 = (void *) (((char *) temp_v0_3) + ((s32) (*((char **) (((char *) temp_t0) + 0x88)))));
                  (((Field_s32 *) (((char *) temp_t0) + 0xFA4))->v) = (s32) (((((((Field_u16 *) (((char *) temp_v0_3) + 0))->v)) << 0x10) | (((((Field_u8 *) (((char *) temp_v0_3) + 2))->v)) << 8)) | ((((Field_u8 *) (((char *) temp_v0_3) + 3))->v)));
                }
              }
            }
            else
            {
              var_a0 = 0x82;
              if (temp_v1 & inline_fn2(temp_t1))
              {
                voiceStoreParam(var_a0, temp_a1, D_800EDA87, temp_a3 & 0x7F);
              }
              else
                if ((temp_a3 & 0x80) && ((var_a0 = temp_t1 & 0x7F, (temp_t1 & 0x80) != 0)))
              {
                if (var_a0 == 0x68)
                {
                  if (((((Field_u8 *) (((char *) temp_t0) + 0xFF4))->v)) != 0)
                  {
                    func_80091A24(temp_t0 + 0xFC8, (((Field_s32 *) (((char *) temp_t0) + 0xFF0))->v), 1);
                    (((Field_s8 *) (((char *) gSeqPlayer) + 0xFF4))->v) = 0;
                  }
                }
                else
                {
                  voiceStoreParam(var_a0, temp_a1, D_800EDA87, temp_a3 & 0x7F);
                }
              }
              else
                if (((temp_a3 != 0) | (temp_t1 != 0)) != 0)
              {
                if (temp_t2)
                {
                  temp_t0 = gSeqPlayer;
                  temp_t0_2 = temp_t0 + var_s2;
                  var_s4 = 6;
                  temp_t2 = (((Field_u8 *) (((char *) temp_t0_2) + 0x58F))->v);
                  var_v0 = temp_t2;
                }
                else
                  if (gSeqPlayer)
                {
                  temp_t0 = gSeqPlayer;
                  temp_t0_2 = temp_t0 + var_s2;
                  var_s4 = 6;
                  temp_t2 = (((Field_u8 *) (((char *) temp_t0_2) + 0x58F))->v);
                  var_v0 = temp_t2;
                }
                else
                {
                  temp_t0 = gSeqPlayer;
                  temp_t0_2 = temp_t0 + var_s2;
                  var_s4 = 6;
                  temp_t2 = (((Field_u8 *) (((char *) temp_t0_2) + 0x58F))->v);
                  var_v0 = temp_t2;
                }
                if (((s32) temp_t2) < 0)
                {
                  var_v0 = ((s32) temp_t2) + 0x1F;
                }
                if ((*((s32 *) (((char *) (((((s32) var_v0) >> 5) * 4) + temp_t0)) + 0x110))) & ((unsigned short) (1 << (temp_t2 & 0x1F))))
                {
                  temp_a0_4 = *((s32 *) (((char *) ((temp_a1 * 4) + temp_t0)) + 0xF80));
                  if (temp_a0_4 != (-1))
                  {
                    temp_a3 = temp_a3 + ((((Field_s8 *) (((char *) temp_t0_2) + 0x58E))->v));
                    if (temp_a3 < 0x80)
                    {
                      var_v1 = temp_a3 & (((s32) (~temp_a3)) >> 0x1F);
                    }
                    else
                    {
                      var_v1 = 0x7F;
                    }
                    temp_t1_2 = temp_t1 + (*((s8 *) (((char *) (gSeqPlayer + var_s2)) + 0x58D)));
                    if (temp_t1_2 < 0x80)
                    {
                      var_v0_2 = temp_t1_2 & (((s32) (~temp_t1_2)) >> 0x1F);
                    }
                    else
                    {
                      var_v0_2 = 0x7F;
                    }
                    temp_t0_3 = gFreeSndNodeList;
                    if (temp_t0_3 != NULL)
                    {
                      temp_v0_4 = *((void **) (((char *) temp_t0_3) + 0));
                      gFreeSndNodeList = temp_v0_4;
                      if (temp_v0_4 != NULL)
                      {
                        if (temp_t1)
                        {
                          (((Field_s32 *) (((char *) temp_v0_4) + 4))->v) = 0;
                        }
                        else
                        {
                          (((Field_s32 *) (((char *) temp_v0_4) + 4))->v) = 0;
                        }
                      }
                      *((void ***) (((char *) temp_t0_3) + 4)) = NULL;
                      temp_v0_5 = *((void **) (((char *) gSeqPlayer) + 0xF78));
                      *((void **) (((char *) temp_t0_3) + 0)) = temp_v0_5;
                      if (temp_v0_5 != NULL)
                      {
                        *((void **) (((char *) (*((void **) (((char *) gSeqPlayer) + 0xF78)))) + 4)) = temp_t0_3;
                      }
                      *((void **) (((char *) gSeqPlayer) + 0xF78)) = temp_t0_3;
                    }
                    if (temp_t0_3 != ((u32) NULL))
                    {
                      temp_v0_6 = func_8008D49C(temp_a0_4, var_v1 & 0xFF, var_v0_2 & 0xFF, 0x40, temp_a1, D_800EDA87, 0, temp_t2, *((u8 *) ((((char *) gSeqPlayer) + 0x528) + temp_t2)), (D_800EDA88) ? (-1) : (0));
                      if (temp_v0_6 != (-1))
                      {
                        (((Field_s32 *) (((char *) temp_t0_3) + 8))->v) = temp_v0_6;
                        temp_v1_2 = gSeqPlayer + var_s2;
                        (((Field_s32 *) (((char *) temp_t0_3) + 0xC))->v) = (s32) (temp_s1 + (*((u16 *) (((char *) (*((void **) (((char *) temp_v1_2) + 0x574)))) + 4))));
                        *((__repair_words2 *) (((char *) temp_t0_3) + 0x10)) = *((__repair_words2 *) (((s8 *) temp_v1_2) + 0x568));
                      }
                      else
                      {
                        temp_v1_3 = *((void **) (((char *) temp_t0_3) + 0));
                        if (temp_v1_3 != NULL)
                        {
                          *((void ***) (((char *) temp_v1_3) + 4)) = (void **) (*((void ***) (((char *) temp_t0_3) + 4)));
                        }
                        temp_v1_4 = *((void ***) (((char *) temp_t0_3) + 4));
                        if (temp_v1_4 != NULL)
                        {
                          *temp_v1_4 = *((void **) (((char *) temp_t0_3) + 0));
                        }
                        else
                        {
                          *((void **) (((char *) gSeqPlayer) + 0xF78)) = (void *) (*((void **) (((char *) temp_t0_3) + 0)));
                        }
                        *((void **) (((char *) temp_t0_3) + 0)) = (void *) gFreeSndNodeList;
                        if (gFreeSndNodeList != NULL)
                        {
                          *((void **) (((char *) gFreeSndNodeList) + 4)) = temp_t0_3;
                        }
                        *((void ***) (((char *) temp_t0_3) + 4)) = NULL;
                        gFreeSndNodeList = temp_t0_3;
                      }
                    }
                  }
                }
              }
            }
            temp_v1_5 = gSeqPlayer + var_s2;
            (((Field_s32 *) (((char *) temp_v1_5) + 0x574))->v) = (s32) (inline_fn((char *) temp_v1_5) + var_s4);
          }
          temp_t0 = gSeqPlayer;
          var_a2 = temp_t0 + var_s2;
          if (((((Field_s32 *) (((char *) var_a2) + 0x574))->v)) != 0)
          {
            continue;
          }
        }
        break;
      }

    }
    var_s6 += 1;
    var_s2 += 0x28;
  }
  while (var_s6 < 0x40);
  return var_s7;
}
