s32 freeHeapBlock(s32, s32);
extern s32 D_800C0784;
extern s32 D_800C0788;
extern s32 D_800C078C;
extern u32 D_80100914;
extern u8 D_80109A35;
typedef struct 
{
  s32 handle;
  u8 gap[0x42];
  u8 timer;
  u8 tail[5];
} TimerObject;
void tickPooledObjectTimers(s8 arg0)
{
  volatile s32 padding[3];
  s32 var_s2;
  u32 temp_v0_2;
  u32 var_s1;
  u32 var_s3;
  u8 temp_v0;
  u8 temp_v1;
  TimerObject *var_s0;
  u32 count;
  TimerObject *objects;
  s32 innerOffset;
  if (D_80109A35 != 0)
  {
    u32 __block_var_s3;
    __block_var_s3 = 0;
    if (D_80100914 != 0)
    {
      s32 mode = arg0;
      do
      {
        {
          var_s2 = __block_var_s3 << 4;
          if ((*((s32 *) (((s8 *) (&D_800C0784)) + var_s2))) != 0)
          {
            count = *((volatile u32 *) (var_s2 + ((u32) (&D_800C078C))));
            objects = *((TimerObject * volatile *) (var_s2 + ((u32) (&D_800C0788))));
            do
            {
              var_s1 = 0;
            }
            while (0);
            if (count != 0)
            {
              innerOffset = var_s2;
              var_s0 = objects;
              do
              {
                {
                  temp_v1 = *((volatile u8 *) (&var_s0->timer));
                  if (!(temp_v1 & 0x80))
                  {
                    temp_v0 = temp_v1 - 1;
                    if (temp_v1 != 0)
                    {
                      if (__block_var_s3)
                      {
                        *((volatile u8 *) (&var_s0->timer)) = temp_v0;
                        temp_v0_2 = temp_v0;
                      }
                      else
                      {
                        *((volatile u8 *) (&var_s0->timer)) = temp_v0;
                        temp_v0_2 = temp_v0;
                      }
                      if (temp_v0_2 == 0)
                      {
                        freeHeapBlock(var_s0->handle, 0x2E);
                        var_s0->handle = 0;
                      }
                      else
                        if (mode != 0)
                      {
                        if (temp_v0_2 >= 5U)
                        {
                          *((volatile u8 *) (&var_s0->timer)) = 0U;
                        }
                      }
                    }
                  }
                  var_s1 += 1;
                  var_s0++;
                }
              }
              while (var_s1 < (*((volatile u32 *) (innerOffset + ((u32) (&D_800C078C))))));
            }
          }
          __block_var_s3 += 1;
        }
      }
      while (__block_var_s3 < ((u32) D_80100914));
    }
  }
}

