s32 func_800066A0(u8);
s32 func_800067C8();
s32 func_800072B8();
s32 func_80007958();
s32 func_8000A310();
s32 func_8000CA3C();
s32 func_8000D000();
s32 func_8001ED10();
s32 func_80026F84(s32);
s32 func_8002CC34(s32);
s32 func_8002D0BC(s32, s32);
s32 func_80030F88(s32);
s32 func_800450F0();
s32 func_80076168(s32);
s32 func_800761B8();
s32 func_80087C9C();
extern u8 D_800B19F0;
extern s8 D_800CA338;
extern u8 D_800CEEB0;
extern s32 D_800DC730;
extern f32 D_800DC734;
extern u8 D_800DC738;
extern u8 D_800DC739;
extern s8 D_801002AC;
extern u8 D_801002AE;
extern s32 D_801002B8;
extern s8 D_80102EB9;
extern s32 D_80102ED8;
extern u8 D_80102EDD;
extern u8 D_80102EDF;
extern s32 D_80102EEC;
extern u8 D_80103EB0;
extern void *volatile D_80109688;
#define TRACK_MARKER (*(void **)&D_80109688)
extern s32 D_8010A4E4;
extern s32 gRetraceFrameCount;
typedef struct 
{
  unsigned char pad_0[292];
  float field_124;
  unsigned char pad_128[4];
  float field_12C;
} __repair_record_D_80109688;
void func_800068B4(void)
{
  s32 var_a0_2;
  f32 temp_fv1;
  f32 temp_fv1_b;
  f32 var_fv0;
  s32 var_s0;
  s32 var_a0;
  s32 __repair_phase_var_a0;
  u32 scratch[2];
  register u8 var_v0;
  switch (D_800B19F0)
  {
    case 0:
      func_80026F84(0);
      func_800450F0();
      var_a0 = 0x12;
      *(s32 *)&((__repair_record_D_80109688 *) TRACK_MARKER)->field_12C = 0;
      goto block_63;

    default:
      return;

    case 8:
      D_800B19F0 = 9;
      D_800DC730 = gRetraceFrameCount;

    case 9:
      if ((D_801002AE == 0) && ((gRetraceFrameCount - D_800DC730) >= 0x1C3))
    {
      var_v0 = 2;
      goto block_9;
    }
      goto block_10;

    case 18:
    {
      __repair_record_D_80109688 *marker = TRACK_MARKER;
      marker->field_12C += 0.06666667f;
      marker = D_80109688;
      if (!(marker->field_12C > 1.0f))
        goto block_10;
      marker->field_12C = 1.0f;
    }
      var_v0 = 1;
      block_9:
    D_800B19F0 = var_v0;


    case 1:
      block_10:
    var_a0 = 4;

      if (D_80102EEC == 0)
    {
      func_8002CC34(4);
      if (D_800CEEB0 || (!D_80102EDD))
      {
        goto block_38;
      }
      if (D_80102ED8 == 0)
      {
        if (func_8002D0BC(0xA3, 0) & 0xFFFF)
        {
          goto block_38;
        }
        block_15:
        func_80076168(0);

        goto block_38;
      }
      else
      {
        volatile s32 *initial = &D_801002B8;
        volatile s32 *slots;
        var_s0 = 0;
        if (((*initial) <= 0) || D_801002AE)
        {
          goto block_38;
        }
        slots = initial;
        do
        {
          unsigned int result = func_8002D0BC(0xA3, var_s0 & 0xFFFF);
          var_s0++;
          if (!(result & 0xFFFF))
          {
            goto block_15;
          }
        }
        while ((var_s0 < (*slots)) && (((volatile u8 *) slots)[-10] == 0));
      }
      goto block_38;
    }
      goto block_63;

    case 2:

    case 10:
      if (D_801002AE == 0)
    {
      __repair_record_D_80109688 *marker = TRACK_MARKER;
      marker->field_12C = (f32) (marker->field_12C - 0.033333335f);
      marker = D_80109688;
      temp_fv1_b = marker->field_12C;
      D_80103EB0 = 0;
      if (temp_fv1_b < 0.0f)
      {
        marker->field_12C = 0.0f;
        func_8000A310();
        if (D_800B19F0 != 2)
        {
          var_a0_2 = 4;
          if (D_800B19F0 == 0xA)
          {
            {
              long long phantom_wide = var_a0_2;
            }
            goto block_29;
          }
        }
        else
        {
          var_a0_2 = 8;
          block_29:
          func_80030F88(var_a0_2);

        }
      }
    }
      goto block_37;

    case 3:

    case 11:
      if (!D_801002AE)
    {
      __repair_record_D_80109688 *marker = TRACK_MARKER;
      marker->field_124 = (f32) (marker->field_124 + 0.13333334f);
      marker = D_80109688;
      D_80103EB0 = 0;
      if (marker->field_124 > 1.0f)
      {
        marker->field_124 = 1.0f;
        if (D_800B19F0 != 3)
        {
          var_a0 = 0xA;
          if (D_800B19F0 == 0xB)
          {
            D_800B19F0 = (double) var_a0;
          }
        }
        else
        {
          __repair_phase_var_a0 = 2;
          D_800B19F0 = __repair_phase_var_a0;
        }
      }
    }
      block_37:
    var_a0 = 4;

      if (D_80102EEC != 0)
    {
      goto block_63;
    }
      block_38:
    func_800072B8();

      block_39:
    func_80007958();

      return;

    case 4:
      func_800067C8();
      if (D_80102EDF == 0x24)
    {
      D_80102EDD = 0;
      D_80102ED8 = 0;
      D_80102EB9 = 0xC;
    }
    else
    {
      D_801002AC = 0;
      D_80102EDD = 1;
    }
      D_800B19F0 = 0xF;
      return;

    case 15:
      func_800761B8();
      var_a0 = 0x12;
      ((__repair_record_D_80109688 *) TRACK_MARKER)->field_12C = 0.0f;
      goto block_63;

    case 5:
      func_800067C8();
      D_8010A4E4 = 1;

    case 6:
      func_8000D000();
      D_800B19F0 = 7;
      return;

    case 7:
      func_800072B8();
      func_80007958();
      var_a0 = 4;
      if (D_80102EEC != 0)
    {
      D_800CA338 = 0;
      goto block_63;
    }
      break;

    case 16:
      func_8000CA3C();
      return;

    case 12:
      D_800DC734 = -0.06666667f;
      goto block_52;

    case 13:
      D_800DC734 = 0.06666667f;
      block_52:
    D_800DC730 = 4;

      D_800B19F0 = 0xE;
      D_800DC739 = D_80103EB0;

    case 14:
    {
      __repair_record_D_80109688 *marker = TRACK_MARKER;
      marker->field_12C = (f32) (marker->field_12C + D_800DC734);
      marker = D_80109688;
      do
    {
      if (((temp_fv1 = marker->field_12C) <= 0.0f) || (temp_fv1 >= 1.0f))
      {
        if (temp_fv1 < 0.0f)
        {
          marker->field_12C = 0.0f;
        }
        else
          if (temp_fv1 > 1.0f)
        {
          marker->field_12C = 1.0f;
        }
        if ((D_800DC730--) <= 0)
        {
          D_80103EB0 = D_800DC739;
          func_800066A0(D_800DC738);
        }
      }
      goto block_39;
    }
    while (0);

    }

    case 17:
      func_80087C9C();
      return;

    case 19:
      func_8001ED10();
      func_800072B8();
      func_80007958();
      var_a0 = 4;
      if (!D_80102EEC)
    {
      break;
    }
      block_63:
    func_800066A0(var_a0);

      break;

  }

}




