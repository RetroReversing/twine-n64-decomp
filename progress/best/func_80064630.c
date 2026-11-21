s32 func_800645A4(u32);
extern u16 sEnemyDefTable[];
extern u8 D_800C46A1[];
extern u8 D_800C471E[];
extern u16 D_800C7C16[];
extern u8 D_80112F6C;
void func_80064630(void *arg0)
{
  union 
  {
    u8 *pointer;
    s32 value;
  } __repair_phase_storage;
  s32 first_offset;
  u32 temp_a0;
  u32 var_s2;
  void *temp_s0;
  void *temp_s5;
  void *var_v1;
void *__repair_phase_var_v1;
  var_s2 = 0;
  temp_s5 = *((void **) (((char *) arg0) + 0x6C));
  __repair_phase_storage.pointer = &D_80112F6C;
  first_offset = 0;
  var_v1 = temp_s5;
  first_loop:
  {
    if ((*__repair_phase_storage.pointer) != 0)
    {
      *((u16 *) (((char *) var_v1) + 0x1BC)) = (u16) (*((u16 *) (((u8 *) D_800C7C16) + first_offset)));
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
    first_offset += 4;
  }

  if (var_s2 < 0x20U)
  {
    goto first_loop;
  }
  var_s2 = 0;
  __repair_phase_storage.value = 0;
  first_offset = 0;
  __repair_phase_var_v1 = temp_s5;
  second_loop:
  {
    if (D_80112F6C != 0)
    {
      do
      {
        *((u8 *) (((char *) __repair_phase_var_v1) + 0x1FC)) = (u8) D_800C46A1[__repair_phase_storage.value];
        *((u8 *) (((char *) __repair_phase_var_v1) + 0x1FF)) = (u8) D_800C471E[__repair_phase_storage.value];
      }
      while (0);
    }
    else
    {
      *((u8 *) (((char *) __repair_phase_var_v1) + 0x1FC)) = 0U;
      *((u8 *) (((char *) __repair_phase_var_v1) + 0x1FF)) = 0U;
    }
    if (!((*((u16 *) (((u8 *) sEnemyDefTable) + __repair_phase_storage.value))) & 0x8000))
    {
      *((s8 *) (((char *) (temp_s5 + first_offset)) + 0x1FC)) = 0;
    }
    __repair_phase_storage.value += 0xE8;
    temp_s0 = (void *) (((s32) temp_s5) + first_offset);
    first_offset += 8;
    __repair_phase_var_v1 += 8;
    temp_a0 = var_s2;
    var_s2 += 1;
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

