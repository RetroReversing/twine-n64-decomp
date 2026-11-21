void workerLockAcquire(s32, u16 *);
void workerLockRelease(void);
void func_8008C7C0(void *, s32);
extern char D_800F38E4[];
extern s32 sKeyTableCount;
extern char sKeyTableSlots[];
typedef struct 
{
  s32 w[3];
} __repair_words3;
s32 func_80097B1C(s32 arg0)
{
  s32 unused[4];
  s32 temp_v0_2;
  s32 var_a1;
  s32 var_a2;
  s32 var_s0_2;
  s32 var_s4;
  s32 var_v0;
  s32 var_v1;
  u16 **var_s2;
  u16 *temp_a1;
  char *var_s1;
  u16 temp_v0;
  u16 var_a0;
  u32 var_s3;
  void *var_a3;
  void *var_s0;
  void *var_t0;
  var_a1 = 0;
  var_s3 = 0;
  if (sKeyTableCount != 0)
  {
    s32 count;
    char *base;
    s32 wanted = (u16) arg0;
    base = D_800F38E4;
    var_s2 = (u16 **) (base + 0xC);
    loop_2:
    var_s1 = (char *) (*var_s2);

    var_a0 = *((u16 *) var_s1);
    var_s4 = 0;
    if (((u16) var_a0) != 0xFFFF)
    {
      if (sKeyTableCount)
      {
        var_s0 = var_s1 + 2;
      }
      else
      {
        var_s0 = var_s1 + 2;
      }
      do
      {
        if (var_a0 == wanted)
        {
          temp_v0 = (*((u16 *) (((char *) var_s0) + 0))) - 1;
          *((u16 *) (((char *) var_s0) + 0)) = temp_v0;
          if (temp_v0 & 0xFFFF)
          {
            var_a1 = 1;
          }
          else
          {
            func_8008C7C0(var_s1 + 0xC, *((s32 *) (((char *) var_s0) + 2)));
            var_a1 = 1;
          }
        }
        if ((*((u16 *) (((char *) var_s0) + 0))) != 0)
        {
          var_s4 = 1;
        }
        var_s1 += 0x1C;
        var_a0 = *((u16 *) var_s1);
        var_s0 += 0x1C;
      }
      while (var_a0 != 0xFFFF);
    }
    do
    {
      if (var_a1 & 0xFF)
      {
        if (var_s4 & 0xFF)
        {
          goto success;
        }
        count = sKeyTableCount; temp_a1 = *var_s2; var_s0_2 = 0;
        if (count > 0)
        {
          var_v1 = 0;
          loop_16:
          if ((*((u16 **) (sKeyTableSlots + var_v1))) != temp_a1)
          {
            var_s0_2 += 1; var_v1 += 0xC;
            if (var_s0_2 < count)
            {
              goto loop_16;
            }
          }

        }
        var_v0 = 1;
        if (var_s0_2 != sKeyTableCount)
        {
          workerLockAcquire(count, temp_a1);
          var_a2 = var_s0_2 + 1;
          if (var_a2 < sKeyTableCount)
          {
            temp_v0_2 = var_a2 * 0xC; var_t0 = (void *) (((u32) temp_v0_2) + ((u32) base)); var_a3 = temp_v0_2 + sKeyTableSlots;
            do
            {
              *((__repair_words3 *) (((char *) var_t0) + 0x0)) = *((__repair_words3 *) (((s8 *) var_a3) + 0x0)); var_t0 += 0xC; var_a2 += 1; var_a3 += 0xC;
            }
            while (var_a2 < sKeyTableCount);
          }
          sKeyTableCount -= 1;
          workerLockRelease();
        }
        success:
        return 1;

      }
      var_s3 += 1; var_s2 += 3;
      if (var_s3 >= ((u32) sKeyTableCount))
      {
        goto block_24;
      }
      goto loop_2;
    }
    while (0);
  }
  block_24:
  var_v0 = 0;

  return var_v0;
}

