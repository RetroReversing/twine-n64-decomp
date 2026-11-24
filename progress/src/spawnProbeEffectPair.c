void *func_80016410(s32, s32, s32);
s32 initSlotRecord(s32 *, s32);
s32 func_8003E6EC(s32, void *, s32);
s32 func_80044670(void *, s32, s32);
s32 func_80119E60(s32, s32, void *);
extern s32 *D_800CA31C;
extern u8 D_801002A0;
extern s32 D_8011F118;
extern s32 D_8011F11C;
extern s32 D_8011F120;
extern u8 D_8011F140[];
extern s32 sProbeEffectObjects[];
typedef struct 
{
  unsigned char pad[92];
  int value;
} __repair_field_5C;
typedef struct 
{
  unsigned char pad_0[84];
  float field_54;
  unsigned char pad_58[20];
  void *field_6C;
  unsigned char pad_70[8];
  short field_78;
  short field_7A;
  short field_7C;
} __repair_record_temp_v0;
typedef struct 
{
  unsigned char pad_0[84];
  float field_54;
  unsigned char pad_58[32];
  short field_78;
  short field_7A;
  short field_7C;
} __repair_record_temp_v0_2;
/* Spawns a linked pair of probe effect objects at pos for the given slot (scene type 6 only); returns the primary or NULL. */ void *spawnProbeEffectPair(void *pos, s32 effectParam, s32 slotPlusOne)
{
  int slot;
  void *secondary;
  unsigned int slotIndex;
  register s32 offset;
  unsigned int slotKey;
  register void *primary;
  if (D_801002A0 == 6)
  {
    initSlotRecord((s32 *) D_8011F140, 0x1E);
    initSlotRecord((s32 *) (D_8011F140 + 8), 0x1E);
    slot = slotPlusOne - 1; primary = func_80016410(0, (s32) pos, effectParam);
    if (primary != NULL)
    {
      slotKey = slot & 0xFFFF; sProbeEffectObjects[slotKey] = (s32) primary;
      switch (slotKey)
      {
        case 0:
          func_80044670(primary, 3, 0xF4);
          break;

        case 1:
          func_80044670(primary, 4, 0xF4);
          break;

        default:
          func_80044670(primary, 5, 0xF4);
          break;

      }

      ((__repair_record_temp_v0 *) primary)->field_7A = slot;
      ((__repair_record_temp_v0 *) primary)->field_7C = 2;
      ((__repair_record_temp_v0 *) primary)->field_78 = 0x41;
      ((__repair_record_temp_v0 *) primary)->field_54 = 1.0f;
      ((__repair_field_5C *) primary)->value &= ~0x200;
      func_8003E6EC(*D_800CA31C, primary, 1);
      secondary = func_80016410(0, (s32) pos, effectParam);
      if (secondary != NULL)
      {
        func_80044670(secondary, 2, 0xF4);
        ((__repair_record_temp_v0_2 *) secondary)->field_7A = slot; slotIndex = slot & 0xFFFF;
        ((__repair_record_temp_v0_2 *) secondary)->field_7C = 2;
        ((__repair_field_5C *) secondary)->value &= ~0x200;
        func_80119E60(slotIndex, 2, primary);
        do
        {
          do
          {
            do
            {
              offset = slotIndex * 12;
            }
            while (0);
          }
          while (0);
        }
        while (0);
        {
          s32 x;
          s32 y;
          s32 z;
          x = *((s32 *) (((char *) pos) + 0)); y = *((s32 *) (((char *) pos) + 4)); z = *((s32 *) (((char *) pos) + 8));
 do { *((s32 *) (((char *) (&D_8011F118)) + offset)) = x; } while (0);
          *((s32 *) (((char *) (&D_8011F11C)) + offset)) = y;
          *((s32 *) (((char *) (&D_8011F120)) + offset)) = z;
        }
        ((__repair_record_temp_v0 *) primary)->field_6C = secondary;
        ((__repair_record_temp_v0_2 *) secondary)->field_78 = 0x1F;
        ((__repair_record_temp_v0_2 *) secondary)->field_54 = 1.0f;
        {
          void *linked = secondary;
          s32 obj = *D_800CA31C;
          func_8003E6EC(obj, linked, 1);
        }
      }
      return primary;
    }
  }
  return NULL;
}
