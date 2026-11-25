extern volatile f32 gGridZMax;
extern volatile f32 gGridZMin;
extern volatile f32 gGridXMax;
extern volatile f32 gGridXMin;
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
/* Returns a 16-bit mask of the 8x8 grid cells of a bounding box touched by the segment start->end (high byte X range, low byte Z range). */ u16 computeGridCellMask(void * bounds, void * start, void * end)
{
  f32 __repair_fzero = 0.0f;
  f32 cellD;
  f32 cellW;
  f32 minX;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 var_fv0;
  f32 startZ;
  f32 endMax;
  f32 __repair_var_fv0_1;
  cellW = (((__repair_record_arg0 *) bounds)->field_4 - ((__repair_record_arg0 *) bounds)->field_0) * 0.125f;
  minX = ((__repair_record_arg0 *) bounds)->field_0;
  cellD = (((__repair_record_arg0 *) bounds)->field_14 - ((__repair_record_arg0 *) bounds)->field_10) * 0.125f;
  if (cellW == 0.0f)
  {
    gGridXMin = 0.0f;
    gGridXMax = 0.0f;
  }
  else
  {
    f32 startX = ((*((f32 *) (((char *) start) + 0))) - minX) / cellW;
    f32 endX = (((__repair_record_arg2 *) end)->field_0 - ((volatile __repair_record_arg0 *) bounds)->field_0) / cellW;
    gGridXMin = startX;
    gGridXMax = endX;
  }
  if (cellD == 0.0f)
  {
    var_fv0 = 0.0f;
    gGridZMin = 0.0f;
  }
  else
  {
    startZ = ((*((f32 *) (((char *) start) + 8))) - ((volatile __repair_record_arg0 *) bounds)->field_10) / cellD;
    var_fv0 = (((__repair_record_arg2 *) end)->field_8 - ((volatile __repair_record_arg0 *) bounds)->field_10) / cellD;
    gGridZMin = startZ;
  }
  gGridZMax = var_fv0;
  temp_fv1 = gGridXMin;
  endMax = gGridXMax;
  if (endMax < temp_fv1)
  {
    gGridXMin = endMax;
    gGridXMax = temp_fv1;
  }
  temp_fv1_2 = gGridZMin;
  endMax = gGridZMax;
  if (endMax < temp_fv1_2)
  {
    gGridZMin = endMax;
    gGridZMax = temp_fv1_2;
  }
  if (gGridXMin < 0.0f)
  {
    gGridXMin = 0.0f;
  }
  if (gGridXMax < 0.0f)
  {
    gGridXMax = 0.0f;
  }
  if (gGridZMin < 0.0f)
  {
    gGridZMin = 0.0f;
  }
  if (gGridZMax < 0.0f)
  {
    gGridZMax = 0.0f;
  }
  if (gGridXMin > 7.0f)
  {
    gGridXMin = 7.0f;
  }
  if (gGridXMax > 7.0f)
  {
    gGridXMax = 7.0f;
  }
  if (gGridZMin > 7.0f)
  {
    gGridZMin = 7.0f;
  }
  if (gGridZMax > 7.0f)
  {
    gGridZMax = 7.0f;
  }
  {
    s32 xMask = (0xFF << ((s32) gGridXMin)) & (0xFF >> (7 - ((s32) gGridXMax)));
    s32 zMask = (0xFF << ((s32) gGridZMin)) & (0xFF >> (7 - ((s32) gGridZMax)));
    do { } while (0);
    xMask = (xMask & 0xFF) << 8;
    return xMask | (zMask & 0xFF);
  }
}
