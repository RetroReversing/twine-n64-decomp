s32 IsSphereVisible(void *, s32, void *, void *);
s32 func_80032630(void *);
s32 emitPrimColor(void *, void *);
s32 func_80034630(void *, void *);
s32 func_800347B0(s32 *, s32, s32, s32, f32, f32, f32);
s32 emit_projection_viewport_commands();
s32 func_80039364(void *);
s32 func_80043FA0(void *);
s32 guMtxF2L(s32 *, s32);
s32 guTranslateF(s32 *, f32, f32, f32);
extern s32 D_800B1A00;
extern s32 D_800B1B18;
extern s32 D_800B1D20;
extern s32 D_800B1D48;
extern u32 sMatrixPoolLimit;
extern u8 D_800C2B40;
extern void *D_801007BC;
extern s32 D_801032A0;
extern void *gObjectListHead;
extern u32 sMatrixPoolUsed;
extern s32 D_8010A924;
extern s32 D_8010D538;
extern s32 gRenderMode;
extern s32 D_80112F90;
extern s32 *D_80115328;
extern void *sRenderState;
typedef struct 
{
  unsigned char pad[256];
  int value;
} __repair_field_100;
typedef struct 
{
  int value;
} __repair_field_0;
typedef struct 
{
  unsigned char pad_0[20];
  void *field_14;
  unsigned char pad_18[4];
  void *field_1C;
  unsigned char pad_20[4];
  float field_24;
  float field_28;
  float field_2C;
  int field_30;
  int field_34;
  int field_38;
  void *field_3C;
  unsigned char pad_40[12];
  int field_4C;
  unsigned char pad_50[8];
  unsigned int field_58;
  unsigned int field_5C;
} __repair_record_var_s0;
void func_80036BBC(void *arg0)
{
  s32 *var_v1_2;
  s32 *temp_v1;
  s32 *temp_v1_10;
  s32 *temp_v1_11;
  s32 *temp_v1_2;
  s32 *temp_v1_3;
  union 
  {
    s32 *pointer;
    s32 value;
  } __repair_phase_storage;
  s32 *var_a0;
  s32 *var_v0;
  s32 *var_v0_2;
  s32 temp_v1_9;
  s32 var_a0_2;
  s32 var_a1;
  s32 var_v1;
  s32 sel_a;
  s32 *m1;
  s32 *m2;
  s32 v_m1;
  s32 v_m2;
  void *rsp;
  u32 temp_v1_5;
  u32 temp_v1_7;
  void *temp_a0;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v1_6;
  void *var_s0;
  void *var_s2;
  var_s2 = gObjectListHead;
  D_801007BC = NULL;
  if (gRenderMode)
  {
    gRenderMode = 0;
    emit_projection_viewport_commands();
  }
  if (D_8010A924 != 0)
  {
    D_8010A924 = 0;
    if (((__repair_field_100 *) arg0)->value & 3)
    {
      temp_v1 = D_80115328;
      D_80115328 = ((s8 *) temp_v1) + 8;
      ((__repair_field_0 *) temp_v1)->value = 0xDE000000;
      *((s32 **) (((char *) temp_v1) + 4)) = &D_800B1A00;
    }
    else
    {
      temp_v1_2 = D_80115328;
      D_80115328 = ((s8 *) temp_v1_2) + 8;
      ((__repair_field_0 *) temp_v1_2)->value = 0xDE000000;
      *((s32 **) (((char *) temp_v1_2) + 4)) = &D_800B1B18;
    }
  }
  if (D_801032A0 != 1)
  {
    D_801032A0 = 1;
    if (((__repair_field_100 *) arg0)->value & 3)
    {
      s32 *e1;
      e1 = D_80115328; D_80115328 = ((s8 *) e1) + 8;
      ((__repair_field_0 *) e1)->value = 0xFC40FE03;
      *((s32 *) (((char *) e1) + 4)) = -0xC88;
    }
    else
    {
      s32 *e2;
      e2 = D_80115328; D_80115328 = ((s8 *) e2) + 8;
      ((__repair_field_0 *) e2)->value = 0xFC40FE03;
      *((s32 *) (((char *) e2) + 4)) = 0xFF0FF37F;
    }
  }
  while (var_s2 != NULL)
  {
    var_s0 = *((void **) (((char *) var_s2) + 0x14));
    do
    {
      func_80034630(var_s2, arg0);
    }
    while (0);
    emitPrimColor(var_s2, arg0);
    if (var_s0 != NULL)
    {
      inner_loop:
      temp_v0 = ((__repair_record_var_s0 *) var_s0)->field_3C;

      if ((((temp_v0 != NULL) && ((*((u8 *) (((char *) temp_v0) + 0x45))) != 0xB)) && (!(((((u32) ((__repair_record_var_s0 *) var_s0)->field_58) >> 1) >> 1) & 1))) && ((IsSphereVisible(var_s0 + 0x40, ((__repair_record_var_s0 *) var_s0)->field_4C, var_s2, arg0) << 0x18) != 0))
      {
        do
        {
          temp_v1_5 = ((u32) ((__repair_record_var_s0 *) var_s0)->field_58) >> 2;
          if (temp_v1_5 & 0xC)
          {
            if (temp_v1_5 & 4)
            {
              temp_a0 = ((__repair_record_var_s0 *) var_s0)->field_3C;
              if ((((__repair_field_0 *) temp_a0)->value != 0) || ((func_80043FA0(temp_a0), (*((s32 *) (((char *) ((__repair_record_var_s0 *) var_s0)->field_3C) + 0))) != 0)))
              {
                temp_v1_6 = ((__repair_record_var_s0 *) var_s0)->field_3C;
                if (!((*((u8 *) (((char *) temp_v1_6) + 0x46))) & 0x80))
                {
                  *((u8 *) (((char *) temp_v1_6) + 0x46)) = (u8) D_800C2B40;
                }
                do
                {
                  func_80039364(var_s0);
                }
                while (0);
              }
              if ((!((((u32) ((__repair_record_var_s0 *) var_s0)->field_58) >> 2) & 4)) || (!(((__repair_field_100 *) arg0)->value & 4)))
              {
                goto block_26;
              }
            }
            else
            {
              block_26:
              temp_v0_2 = D_801007BC;

              D_801007BC = var_s0;
              ((__repair_record_var_s0 *) var_s0)->field_1C = temp_v0_2;
            }
            goto block_59;
          }
          if ((((u32) ((__repair_record_var_s0 *) var_s0)->field_5C) >> 0x17) & 3)
          {
            temp_v1_7 = sMatrixPoolUsed;
            if (temp_v1_7 < sMatrixPoolLimit)
            {
              sMatrixPoolUsed = ++temp_v1_7; D_8010D538 = (*((s32 *) (((char *) sRenderState) + 0x74C))) + (temp_v1_7 << 6);
              if ((((u32) ((__repair_record_var_s0 *) var_s0)->field_5C) >> 0x17) & 2)
              {
                func_800347B0(&D_80112F90, ((__repair_record_var_s0 *) var_s0)->field_30, ((__repair_record_var_s0 *) var_s0)->field_34, ((__repair_record_var_s0 *) var_s0)->field_38, ((__repair_record_var_s0 *) var_s0)->field_24 * 64.0f, ((__repair_record_var_s0 *) var_s0)->field_28 * 64.0f, ((__repair_record_var_s0 *) var_s0)->field_2C * 64.0f);
              }
              else
              {
                guTranslateF(&D_80112F90, ((__repair_record_var_s0 *) var_s0)->field_24 * 64.0f, ((__repair_record_var_s0 *) var_s0)->field_28 * 64.0f, ((__repair_record_var_s0 *) var_s0)->field_2C * 64.0f);
              }
              guMtxF2L(&D_80112F90, D_8010D538);
              m1 = D_80115328;
              D_80115328 = m1 + 2;
              v_m1 = D_8010D538 - 0x80000000;
              m1[0] = 0xDA380003;
              m1[1] = v_m1;
              goto block_34;
            }
            return;
          }
          else
          {
            m2 = D_80115328;
            rsp = (void *) sRenderState;
            m2[0] = 0xDA380003;
            v_m2 = ((u32) (*((s32 *) (((char *) rsp) + 0x74C)))) - 0x80000000;
            D_80115328 = m2 + 2;
            m2[1] = v_m2;
            block_34:
            if ((((u32) ((__repair_record_var_s0 *) var_s0)->field_58) >> 2) & 0x400)
            {
              if (D_8010A924 != 5)
              {
                D_8010A924 = 5; sel_a = ((__repair_field_100 *) arg0)->value & 7;
                if (sel_a == 1)
                {
                  goto emit_first_mode;
                }
                if (sel_a == 2)
                {
                  s32 *c2 = D_80115328;
                  D_80115328 = c2 + 2;
                  c2[0] = 0xDE000000;
                  c2[1] = (s32) &D_800B1D48;
                }
                else if (sel_a == 4)
                {
                  s32 *c1;
                  emit_first_mode:
                  c1 = D_80115328;
                  D_80115328 = c1 + 2;
                  c1[0] = 0xDE000000;
                  c1[1] = (s32) &D_800B1D20;
                }
              }
              if (D_801032A0 != 4)
              {
                D_801032A0 = 4; temp_v1_9 = ((__repair_field_100 *) arg0)->value & 7;
                if (temp_v1_9 == 1)
                {
                  var_a1 = 0xFC121824; temp_v1_3 = D_80115328; var_a0_2 = 0xFF33FFFF;
                  goto emit_combine;
                }
                if (temp_v1_9 == 2)
                {
                  goto emit_other_combine;
                }
                if (temp_v1_9 == 4)
                {
                  emit_other_combine:
                  var_a1 = 0xFC119823;

                  temp_v1_3 = D_80115328; var_a0_2 = 0xFF32FF7F;
                  emit_combine:
                  D_80115328 = temp_v1_3 + 2;

                  temp_v1_3[0] = var_a1; temp_v1_3[1] = var_a0_2;
                }
              }
              func_80032630(((__repair_record_var_s0 *) var_s0)->field_3C);
              if (D_8010A924 != 0)
              {
                D_8010A924 = 0;
                if (((__repair_field_100 *) arg0)->value & 3)
                {
                  s32 *e3 = D_80115328;
                  D_80115328 = e3 + 2;
                  e3[0] = 0xDE000000;
                  e3[1] = (s32) &D_800B1A00;
                }
                else
                {
                  s32 *e4 = D_80115328;
                  D_80115328 = e4 + 2;
                  e4[0] = 0xDE000000;
                  e4[1] = (s32) &D_800B1B18;
                }
              }
              if (D_801032A0 != 1)
              {
                D_801032A0 = 1;
                if (((__repair_field_100 *) arg0)->value & 3)
                {
                  temp_v1_10 = D_80115328; D_80115328 = ((s8 *) temp_v1_10) + 8;
                  ((__repair_field_0 *) temp_v1_10)->value = 0xFC40FE03;
                  *((s32 *) (((char *) temp_v1_10) + 4)) = -0xC88;
                }
                else
                {
                  temp_v1_11 = D_80115328; D_80115328 = ((s8 *) temp_v1_11) + 8;
                  ((__repair_field_0 *) temp_v1_11)->value = 0xFC40FE03;
                  *((s32 *) (((char *) temp_v1_11) + 4)) = 0xFF0FF37F;
                }
              }
            }
            else
            {
              func_80032630(((__repair_record_var_s0 *) var_s0)->field_3C);
            }
            goto block_59;
          }
        }
        while (0);
      }
      block_59:
      var_s0 = ((__repair_record_var_s0 *) var_s0)->field_14;

      if (var_s0 != NULL)
      {
        goto inner_loop;
      }
    }
    var_s2 = *((void **) (((char *) var_s2) + 0x1C));
  }

}
