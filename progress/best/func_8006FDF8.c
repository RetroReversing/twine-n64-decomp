void *func_80015F0C();
s32 func_800165E0(void *, s32);
s32 initObjectFromBankEntry(void *, s32, s32);
extern u16 D_800C7E08[];
typedef struct 
{
  s16 half[4];
} __attribute__((packed, aligned(2))) BorderPositions;
extern BorderPositions D_800D46E4;
extern BorderPositions D_800D46EC;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern s32 gVisibleSaveSlotCount;
extern s32 sTrackMarkerTable;
inline static s32 *inline_fn()
{
  return &sTrackMarkerTable;
}

void func_8006FDF8(void *arg0, s32 arg1)
{
  struct 
  {
    BorderPositions x;
    BorderPositions y;
  } positions;
  s32 sp24;
  s32 sp2C;
  s8 *var_s3;
  u32 var_a0;
  char var_s6;
  s32 var_s7;
  s32 var_v1;
  s32 var_s1_3;
  void *var_s0_2;
  u16 *var_s4;
  s32 *marker;
  long var_s1_2;
  u32 var_s2;
  u32 var_s2_2;
  void *temp_a0;
  void *temp_a0_2;
  void *temp_s0;
  void *temp_v0;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *var_s0;
  void *var_s1;
  sp24 = arg1;
  positions.x = D_800D46E4;
  positions.y = D_800D46EC;
  var_s7 = 0xA0;
  var_s6 = 0x78;
  sp2C = (s32) (*((s8 *) (((char *) arg0) + 0x182)));
  if (gBorderSkipActive == 0)
  {
    goto full_size;
  }
  switch (gVisibleSaveSlotCount)
  {
    case 2:
      switch (gBorderFlipFlag)
    {
      case 1:
      {
        var_s7 = 0x50;
      }
        break;

      default:
      {
        do
        {
          var_s6 = 0x3C;
        }
        while (0);
      }
        break;

    }

      break;

    case 3:

    case 4:
      var_s7 = 0x50;
      var_s6 = 0x3C;
      break;

  }

  full_size:
  var_s2 = 0;

  {
    s32 *base = inline_fn();
    s32 offset = sp2C * 4;
    s16 width;
    s16 height;
    marker = (s32 *)(offset + (char *)base);
    var_s4 = D_800C7E08;
    var_s3 = (s8 *)&positions;
    var_s1 = arg0;
    width = var_s7;
    positions.x.half[1] = width;
    positions.x.half[3] = width;
    height = var_s6;
    positions.y.half[2] = height;
    positions.y.half[3] = height;
  }
  do
  {
    {
      long long phantom_wide = arg1;
    }
    if (((*((void * volatile *) (((char *) var_s1) + 0x3D4))) != NULL) || ((temp_v0 = func_80015F0C(), *((void * volatile *) (((char *) var_s1) + 0x3D4)) = temp_v0, temp_v0 != NULL)))
    {
      temp_s0 = *((void * volatile *) (((char *) var_s1) - (-0x3D4)));
      initObjectFromBankEntry(temp_s0, sp24, 0x2A);
      {
        s32 flags = *((s32 *) (((char *) temp_s0) + 0x28));
        u16 y;
        *((s32 *) (((char *) temp_s0) + 0x10)) = 0xFF;
        *((s32 *) (((char *) temp_s0) + 0x28)) = (flags & (~0xFC)) | 0x10;
        *((u16 *) (((char *) temp_s0) + 0x20)) = *((u16 *) var_s3);
        y = *((u16 *) (var_s3 + 8));
        *((s16 *) (((char *) temp_s0) + 0x26)) = var_s7;
        *((s8 *) (((char *) temp_s0) + 0x29)) = var_s6;
        *((u16 *) (((char *) temp_s0) + 0x22)) = y;
      }
      func_800165E0(temp_s0, *marker);
      *((u16 *) (((char *) temp_s0) + 0x1E)) = (u16) (*var_s4);
    }
    if (temp_s0)
    {
      var_s4 += 1;
      var_s3 += 2;
      var_s2 += 1;
      var_s1 += 4;
    }
    else
    {
      var_s4 += 1;
      var_s3 += 2;
      var_s2 += 1;
      var_s1 += 4;
    }
  }
  while (var_s2 < 4U);
  if (gBorderSkipActive == 0)
  {
    if (sp24 == 5)
    {
      var_s0 = arg0;
      var_s1_2 = 0;
      do
      {
        if ((*((void * volatile *) (((char *) var_s0) + 0x3E4))) == NULL)
        {
          *((void * volatile *) (((char *) var_s0) + 0x3E4)) = func_80015F0C();
        }
        *((s32 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x10)) = 0xFF008F;
        do
        {
          temp_a0 = *((void * volatile *) (((char *) var_s0) + 0x3E4));
          *((s32 *) (((char *) temp_a0) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_a0) + 0x28))) & (~0xFC)) | 0x10);
          func_800165E0(*((void * volatile *) (((char *) var_s0) + 0x3E4)), inline_fn()[sp2C]);
          *((u16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x1E)) = 2U;
        }
        while (0);
        {
          switch (var_s1_2)
          {
            case 0:

            case 4:
              initObjectFromBankEntry(*((void * volatile *) (((char *) var_s0) + 0x3E4)), 0xF, 0x2A);
              if (var_s1_2 == 0)
            {
              *((s16 *) (((char *) (*((void * volatile *) (((char *) arg0) + 0x3E4)))) + 0x20)) = 0x50;
            }
            else
            {
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x20)) = 0xE0;
              temp_v1 = *((void * volatile *) (((char *) var_s0) - (-0x3E4)));
              *((u16 *) (((char *) temp_v1) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1) + 0x1E))) | 0x80);
            }
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x22)) = 0x58;
              break;

            case 8:

            case 12:
              initObjectFromBankEntry(*((void * volatile *) (((char *) var_s0) + 0x3E4)), 0x10, 0x2A);
              if (var_s0 == ((2 * 4) + arg0))
            {
              *((s16 *) (((char *) (*((void * volatile *) (((char *) arg0) + 0x3EC)))) + 0x20)) = 0x58;
            }
            else
            {
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x20)) = 0xD8;
              temp_v1_2 = *((void * volatile *) (((char *) var_s0) + 0x3E4));
              *((u16 *) (((char *) temp_v1_2) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1_2) + 0x1E))) | 0x80);
            }
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x22)) = 0x78;
              break;

            case 16:
              initObjectFromBankEntry(*((void * volatile *) (((char *) var_s0) + 0x3E4)), 0x11, 0x2A);
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x20)) = 0x80;
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x22)) = 0x20;
              break;

            case 23:

            case 20:
              initObjectFromBankEntry(*((void * volatile *) (((char *) var_s0) + 0x3E4)), 3, 0x2A);
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x20)) = 0;
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x22)) = 0x78;
              do
            {
              *((s8 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x29)) = 8;
              *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x26)) = 0x140;
              *((s32 *) (((char *) (*((void * volatile *) (((char *) var_s0) + 0x3E4)))) + 0x10)) = 0xFF001F;
              break;
            }
            while (0);

          }

        }
        var_s1_2 += 4;
        var_s0 += 4;
      }
      while (((u32) var_s1_2) < 0x18);
    }
    var_s2_2 = 0;
    if (sp24 == 8)
    {
      var_s0_2 = arg0;
      do
      {
        var_s1_3 = 0;
        if ((*((void * volatile *) (((char *) var_s0_2) + 0x3E4))) == NULL)
        {
          *((void * volatile *) (((char *) var_s0_2) + 0x3E4)) = func_80015F0C();
        }
        *((s32 *) (((char *) (*((void * volatile *) (((char *) var_s0_2) + 0x3E4)))) + 0x10)) = 0xFF7F;
        temp_v1_3 = *((void * volatile *) (((char *) var_s0_2) + 0x3E4));
        do
        {
          *((s32 *) (((char *) temp_v1_3) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_3) + 0x28))) & (~0xFC)) | 0x10);
          func_800165E0(*((void * volatile *) (((char *) var_s0_2) - (-0x3E4))), inline_fn()[sp2C]);
          do
          {
            var_a0 = 0x50;
          }
          while (0);
          if (var_s2_2 >= 2U)
          {
            var_a0 = (var_s7 * 2) - 0x70; var_s1_3 = 0x80;
          }
          var_v1 = 0x37;
        }
        while (0);
        if (((var_s2_2 == 0) | (var_s2_2 == 2)) == 0)
        {
          var_s2 = var_s6 * 2; var_v1 = var_s2 - 0x57;
          var_s1_3 |= 0x100;
        }
 do { *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0_2) + 0x3E4)))) + 0x20)) = var_a0; } while (0);
        *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0_2) + 0x3E4)))) + 0x22)) = var_v1;
        *((s16 *) (((char *) (*((void * volatile *) (((char *) var_s0_2) + 0x3E4)))) + 0x1E)) = (s16) (var_s1_3 | 2);
        temp_a0_2 = *((void * volatile *) (((char *) var_s0_2) + 0x3E4));
        ++var_s2_2;
        var_s0_2 += 4;
        initObjectFromBankEntry(temp_a0_2, 0x12, 0x2A);
      }
      while (var_s2_2 < 4U);
    }
  }
}


