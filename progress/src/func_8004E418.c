extern volatile f32 D_80100160;
extern volatile f32 D_80100780;
extern volatile f32 D_80109BAC;
extern volatile f32 D_80109CBC;
typedef struct 
{
  float field_0;
  float field_4;
  unsigned char pad_8[8];
  float field_10;
  float field_14;
} __repair_record_arg0;
typedef struct 
{
  float field_0;
  unsigned char pad_4[4];
  float field_8;
} __repair_record_arg2;
s32 func_8004E418(void *arg0, void *arg1, void *arg2)
{
  f32 __repair_fzero = 0.0f;
  f32 temp_ft1;
  f32 temp_ft2;
  f32 temp_ft3;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 var_fv0;
  f32 x;
  f32 y;
  f32 __repair_var_fv0_1;
  temp_ft2 = (((__repair_record_arg0 *) arg0)->field_4 - ((__repair_record_arg0 *) arg0)->field_0) * 0.125f;
  temp_ft3 = ((__repair_record_arg0 *) arg0)->field_0;
  temp_ft1 = (((__repair_record_arg0 *) arg0)->field_14 - ((__repair_record_arg0 *) arg0)->field_10) * 0.125f;
  if (temp_ft2 == 0.0f)
  {
    D_80109CBC = 0.0f;
    D_80109BAC = 0.0f;
  }
  else
  {
    f32 x1 = ((*((f32 *) (((char *) arg1) + 0))) - temp_ft3) / temp_ft2;
    f32 y1 = (((__repair_record_arg2 *) arg2)->field_0 - ((volatile __repair_record_arg0 *) arg0)->field_0) / temp_ft2;
    D_80109CBC = x1;
    D_80109BAC = y1;
  }
  if (temp_ft1 == 0.0f)
  {
    var_fv0 = 0.0f;
    D_80100780 = 0.0f;
  }
  else
  {
    x = ((*((f32 *) (((char *) arg1) + 8))) - ((volatile __repair_record_arg0 *) arg0)->field_10) / temp_ft1;
    var_fv0 = (((__repair_record_arg2 *) arg2)->field_8 - ((volatile __repair_record_arg0 *) arg0)->field_10) / temp_ft1;
    D_80100780 = x;
  }
  D_80100160 = var_fv0;
  temp_fv1 = D_80109CBC;
  y = D_80109BAC;
  if (y < temp_fv1)
  {
    D_80109CBC = y;
    D_80109BAC = temp_fv1;
  }
  temp_fv1_2 = D_80100780;
  y = D_80100160;
  if (y < temp_fv1_2)
  {
    D_80100780 = y;
    D_80100160 = temp_fv1_2;
  }
  if (D_80109CBC < 0.0f)
  {
    D_80109CBC = 0.0f;
  }
  if (D_80109BAC < 0.0f)
  {
    D_80109BAC = 0.0f;
  }
  if (D_80100780 < 0.0f)
  {
    D_80100780 = 0.0f;
  }
  if (D_80100160 < 0.0f)
  {
    D_80100160 = 0.0f;
  }
  if (D_80109CBC > 7.0f)
  {
    D_80109CBC = 7.0f;
  }
  if (D_80109BAC > 7.0f)
  {
    D_80109BAC = 7.0f;
  }
  if (D_80100780 > 7.0f)
  {
    D_80100780 = 7.0f;
  }
  if (D_80100160 > 7.0f)
  {
    D_80100160 = 7.0f;
  }
  {
    s32 high = (0xFF << ((s32) D_80109CBC)) & (0xFF >> (7 - ((s32) D_80109BAC)));
    s32 low = (0xFF << ((s32) D_80100780)) & (0xFF >> (7 - ((s32) D_80100160)));
    do { } while (0);
    high = (high & 0xFF) << 8;
    return high | (low & 0xFF);
  }
}
