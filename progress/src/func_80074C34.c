f32 approxDistance(void *, void *);
f32 func_8000A4F4(s32);
s32 func_80074820(s32, s32, s32, s32, f32, s32);
s32 lookupDataEntry(u16);
extern s32 D_800C7EE4;
extern u8 D_80100310[];
typedef struct 
{
  s8 f0;
  u8 pad[7];
} Slot_80100314;
extern Slot_80100314 D_80100314[];
extern void *D_80100B20;
extern int gTrackMarkerSerial;
extern void *sBonusObjectTable;
extern u8 D_8010D294;
extern s16 D_80112EBC;
extern s32 sTrackMarkerTable;
inline static s32 inline_fn()
{
  return (s32) D_8010D294;
}

void func_80074C34(void *arg0, void *arg1, s32 arg2)
{
  void **__base_D_80100B20;
  f32 temp_fv0;
  f32 four;
  f32 var_fs0;
  s32 temp_v0;
  s32 off;
  s32 cnt;
  u32 end;
  s32 low;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 var_a0;
  s32 var_s1;
  u32 var_v1;
  void **temp_s7;
  void **var_s2;
  void *temp_s0;
  void *var_s4;
  void *var_v0;
  void *entry;
  volatile s32 frame[4];
  __base_D_80100B20 = &D_80100B20;
  var_a0 = 0;
  if (arg0 != NULL)
  {
    *((s32 *) (((char *) arg0) + 0x60)) = (s32) ((*((s32 *) (((char *) arg0) + 0x60))) | 0x10000000);
  }
  var_s1 = 0;
  if (inline_fn() > 0)
  {
    temp_v1 = inline_fn();
    var_v1 = 0;
    do
    {
      if ((*((void **) (D_80100310 + var_v1))) == arg1)
      {
        var_a0 = 1;
      }
      var_s1 += 1;
      var_v1 += 8;
    }
    while (var_s1 < temp_v1);
  }
  end = var_a0;
  if (end == 0)
  {
    do
    {
      off = D_8010D294 * 8;
      *((s8 *) ((char *) D_80100314 + off)) = arg2;
      cnt = D_8010D294;
      *((void **) (D_80100310 + off)) = arg1;
      D_8010D294 = cnt + 1;
    }
    while (0);
  }
  gTrackMarkerSerial += 1;
  if (arg2 != 0)
  {
    var_s4 = arg1;
    end = (u32) arg1;
    four = 4.0f;
    temp_s7 = __base_D_80100B20 - 1;
    do
    {
      var_fs0 = 5.0f;
      if ((*((u16 *) (((char *) var_s4) + 6))) == 0x237)
      {
        var_fs0 = 0.0f;
      }
      temp_v0 = *((s32 *) (((char *) var_s4) + 0));
      low = temp_v0 & 0xFFFFFF;
      if (temp_v0 & 0x80000000)
      {
        var_fs0 = func_8000A4F4(low);
      }
      var_fs0 += 0.5f;
      func_80074820(sTrackMarkerTable, lookupDataEntry(*((u16 *) (((char *) var_s4) + 6))), 0x20, 2, var_fs0, D_800C7EE4);
      if (D_80112EBC)
      {
        do
        {
          var_s1 = 0;
        }
        while (0);
        if (D_80112EBC > 0)
        {
          entry = var_s4;
          var_s2 = __base_D_80100B20;
          do
          {
            var_v0 = *var_s2;
            if (var_v0 != NULL)
            {
              temp_s0 = *((void **) (((char *) var_v0) + 0x6C));
              if (arg0 != NULL)
              {
                *((void **) (((char *) temp_s0) - (-0x2C))) = arg0;
                {
                  typedef struct 
                  {
                    s32 word[3];
                  } MarkerPosition;
                  *((MarkerPosition *) (((char *) temp_s0) + 8)) = *((MarkerPosition *) (((char *) arg0) + 0x24));
                }
                temp_fv0 = approxDistance(temp_s0 + 8, ((u8 *) sBonusObjectTable) + 0x24);
                *((f32 *) (((char *) temp_s0) + 0x28)) = temp_fv0;
                if (temp_fv0 < four)
                {
                  *((f32 *) (((char *) temp_s0) + 0x28)) = four;
                }
              }
            }
            temp_v1_2 = *((s32 *) (((char *) entry) + 0));
            if (0x80000000 & temp_v1_2)
            {
              var_v0 = *__base_D_80100B20;
            }
            else
            {
              var_v0 = temp_s7[D_80112EBC];
            }
            temp_s0 = *((void **) (((char *) var_v0) + 0x6C));
            *((s32 *) (((char *) temp_s0) + 0x24)) = temp_v1_2;
            temp_s0 = *((void **) (((char *) temp_s7[D_80112EBC]) + 0x6C));
            *((s8 *) (((char *) temp_s0) + 0x32)) = (s8) (*((u16 *) (((char *) entry) + 4)));
            var_s1 += 1;
            var_s2++;
          }
          while (var_s1 < D_80112EBC);
        }
      }
      var_s4 += 8;
    }
    while (end = ((2 * (2 * ((u32) arg2))) * 2) + (u32) arg1, (u32) var_s4 < end);
  }
}


