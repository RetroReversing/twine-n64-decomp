s32 func_800645A4(u32);
extern u16 sEnemyDefTable[];
extern u8 D_800C46A1[];
extern u8 D_800C471E[];
extern u16 D_800C7C16[];
extern u8 D_80112F6C;
void func_80064630(void *arg0)
{
  s32 value;
  s32 first_offset;
  s32 off1;
  u8 *p1;
  u32 temp_a0;
  u32 var_s2;
  void *temp_s0;
  void *temp_s5;
  void *var_v1;
  void *var_v1_2;
  var_s2 = 0;
  temp_s5 = *((void **) (((char *) arg0) + 0x6C));
  p1 = &D_80112F6C;
  off1 = 0;
  var_v1 = temp_s5;
  first_loop:
  {
    if ((*p1) != 0)
    {
      *((u16 *) (((char *) var_v1) + 0x1BC)) = (u16) (*((u16 *) (((u8 *) D_800C7C16) + off1)));
    }
    else
    {
      *((u16 *) (((char *) var_v1) + 0x1BC)) = 0U;
    }
    var_v1 += 2;
    do
    {
      var_s2 += 1;
    }
    while (0);
    off1 += 4;
  }

  if (var_s2 < 0x20U)
  {
    goto first_loop;
  }
  do { var_s2 = 0; } while (0);
  value = 0;
  do { do { first_offset = 0; } while (0); } while (0);
  var_v1_2 = temp_s5;
  second_loop:
  {
    if (D_80112F6C != 0)
    {
      do
      {
        *((u8 *) (((char *) var_v1_2) + 0x1FC)) = (u8) D_800C46A1[value];
        *((u8 *) (((char *) var_v1_2) + 0x1FF)) = (u8) D_800C471E[value];
      }
      while (0);
    }
    else
    {
      *((u8 *) (((char *) var_v1_2) + 0x1FC)) = 0U;
      *((u8 *) (((char *) var_v1_2) + 0x1FF)) = 0U;
    }
    if (!((*((u16 *) (((u8 *) sEnemyDefTable) + value))) & 0x8000))
    {
    do { do { do { *((s8 *) (((char *) (temp_s5 + first_offset)) + 0x1FC)) = 0; } while (0); } while (0); } while (0);
    }
    do { do { do { value += 0xE8; } while (0); } while (0); } while (0);
    temp_s0 = (void *) (((s32) temp_s5) + first_offset);
    first_offset += 8;
    do { do { do { var_v1_2 += 8; } while (0); } while (0); } while (0);
    do { do { temp_a0 = var_s2; var_s2 += 1; } while (0); } while (0);
    *((s8 *) (((char *) temp_s0) + 0x1FD)) = 0;
    *((s8 *) (((char *) temp_s0) + 0x1FE)) = 0;
    *((f32 *) (((char *) temp_s0) + 0x200)) = (f32) (func_800645A4(temp_a0) & 0xFF);
  }

  if (var_s2 < 0x3BU)
  {
    goto second_loop;
  }
  *((s8 *) (((char *) temp_s5) + 0x1FC)) = 1;
  *((s8 *) (((char *) temp_s5) + 0x32C)) = 0;
  *((s8 *) (((char *) temp_s5) + 0x324)) = 0;
  if (D_80112F6C != 0)
  {
    *((s8 *) (((char *) temp_s5) + 0x1FC)) = 1;
  }
}
