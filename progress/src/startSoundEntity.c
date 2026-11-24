/* Partial candidate from function #296352744009 in project #69; rechecked locally. */
s32 audio_slot_reset(s32, s32);
s32 setAudioChannelScaledValue(s32, s32);
s32 setSoundChannelRamp(u8, u16, u8, s32, s32);
void setSoundEntityStatus(s32, s8);
void voiceStoreParam(u8, unsigned char, u8, u8);
extern u8 D_800E6A85;
extern s32 gSoundEntityIdCounter;
extern u8 D_80102FDC;
extern s32 gSoundEntities;
typedef struct 
{
  unsigned char pad[4];
  int value;
} __repair_field_4;
/* Finds a free sound entity slot (8 max), initialises its instrument maps, channels and sequence pointers, and returns a unique entity id (or -1 if none free). */ s32 startSoundEntity(void *bankData, void *instrumentTable, void *channelInit, void *seqData, void *options)
{
  int __repair_literal;
  u32 scratch[2];
  s32 *var_a1_3;
  unsigned temp_a0;
  s32 temp_a0_2;
  s32 temp_a1_2;
  s32 temp_a1_3;
  s32 temp_s0;
  s32 slotId;
  s32 temp_v0_4;
  s32 var_a0;
  s32 var_a0_7;
  s32 var_a3;
  s32 i;
  s32 var_v0;
  s32 var_v1;
  u32 var_v1_4;
  u8 var_a0_3;
  
  u32 var_a2_4;
  u32 slotIndex;
  u8 *var_a2_3;
  u8 *var_v1_3;
  s32 temp_a0_3;
  u8 idx1;
  u8 idx2;
  u8 temp_a3_3;
  u8 temp_v0_6;
  u8 temp_v1_2;
  u8 temp_v1_4;
  u8 var_a1;
  u8 var_a1_2;
  void *temp_a1;
  union 
  {
    u8 *pointer;
    s32 value;
  } __repair_phase_storage;
  u8 *temp_a3_2;
  void *entity;
  void *temp_t0;
  void *temp_v0;
  void *temp_v0_3;
  void *temp_v0_5;
  void *temp_v1;
  void *temp_v1_3;
  void *temp_v1_5;
  void *var_a0_6;
  void *var_a2;
  void *var_a2_2;
  void *var_t1;
  void *var_v0_3;
  void *var_v1_2;
  u8 *rec;
  u8 *temp_p;
  s32 neg1;
  s32 tbl;
  slotIndex = 0;
  var_v1 = 0;
  for (;;)
  {
    if ((*((&D_800E6A85) + var_v1)) == 0)
    {
      slotIndex += 1;
      var_v1 += 0xFF8;
      if (8U <= slotIndex)
      {
      }
      else
      {
        continue;
      }
    }
    break;
  }

  if (slotIndex != 8)
  {
    entity = (slotIndex * 0xFF8) + ((u8 *) (&gSoundEntities));
    __repair_phase_storage.pointer = (void *) (8 + ((s32) entity));
    ((__repair_field_4 *) entity)->value = bankData;
    var_a2 = *(void * volatile *) (((char *) entity) + 4);
    *((s8 *) (((char *) entity) + 0xFF4)) = 0;
    *((void **) (((char *) entity) + 0x88)) = instrumentTable;
    *((void **) (((char *) entity) + 0x10C)) = seqData;
    {
      for (var_a0_3 = 0; var_a0_3 < 0x80; var_a0_3++)
      {
        *(__repair_phase_storage.pointer + var_a0_3) = 0xFF;
      }

    }
    var_a1 = *((u8 *) (((char *) var_a2) + 5));
    var_a0_3 = 0;
    if ((var_a1 & 0xFF) != 0xFF)
    {
      do
      {
        var_a2 += 8;
        *(var_a1 + __repair_phase_storage.pointer) = var_a0_3;
        var_a1 = *((u8 *) (((char *) var_a2) + 5));
        var_a0_3 += 1;
      }
      while (var_a1 != 0xFF);
    }
    temp_a3_2 = (void *) (0x8C + ((s32) entity));
    do { var_a2_2 = *((void **) (((char *) entity) + 0x88)); } while (0);
    for (var_a0_3 = 0; var_a0_3 < 0x80; var_a0_3++)
    {
      *(temp_a3_2 + var_a0_3) = 0xFF;
    }

    var_a1_2 = *((u8 *) (((char *) var_a2_2) + 5));
    var_a0_3 = 0;
    if ((var_a1_2 & 0xFF) != 0xFF)
    {
      do
      {
        do { do { do { var_a2_2 += 8; } while (0); } while (0); } while (0);
        *(var_a1_2 + temp_a3_2) = (unsigned) var_a0_3;
        var_a1_2 = *((u8 *) (((char *) var_a2_2) + 5));
        do { var_a0_3 += 1; } while (0);
      }
      while (var_a1_2 != 0xFF);
    }
    *((u8 *) (((char *) entity) + 0xFC4)) = (u8) (slotIndex + 0x17);
    i = 0;
    do
    {
      temp_v0 = (void *) (((char *) entity) + i);
      i += 1;
      *((u8 *) (((char *) temp_v0) + 0x528)) = (u8) (*((u8 *) (((char *) entity) + 0xFC4)));
    }
    while (i < 0x40);
    if (options == NULL)
    {
      *((s32 *) (((char *) entity) + 0x110)) = -1;
      *((s32 *) (((char *) entity) + 0x114)) = -1;
      *((u16 *) (((char *) entity) + 0xFC2)) = 0x100U;
    }
    else
    {
      if ((*((s32 *) (((char *) options) + 0))) & 1)
      {
        *((s32 *) (((char *) entity) + 0x110)) = (s32) ((__repair_field_4 *) options)->value;
        *((s32 *) (((char *) entity) + 0x114)) = (s32) (*((s32 *) (((char *) options) + 8)));
      }
      else
      {
        *((s32 *) (((char *) entity) + 0x110)) = -1;
        *((s32 *) (((char *) entity) + 0x114)) = -1;
      }
      if ((*((s32 *) (((char *) options) + 0))) & 2)
      {
        *((u16 *) (((char *) entity) + 0xFC2)) = (u16) (*((u16 *) (((char *) options) + 0xC)));
      }
      else
      {
        *((u16 *) (((char *) entity) + 0xFC2)) = 0x100U;
      }
      if ((*((s32 *) (((char *) options) + 0))) & 8)
      {
        i = 0;
        __repair_literal = 0;
        if (((s32) (*((u8 *) (((char *) options) + 0x12)))) > __repair_literal)
        {
          do
          {
            *((u8 *) (((char *) (entity + (*((u8 *) (((char *) ((i * 2) + (*((u8 **) (((char *) options) + 0x14))))) + 0))))) + 0x528)) = (u8) (*((u8 *) (((char *) ((i * 2) + (*((u8 **) (((char *) options) + 0x14))))) + 1)));
            setSoundEntityStatus(*((u8 *) (((char *) ((i * 2) + (*((u8 **) (((char *) options) + 0x14))))) + 1)), 0);
            i += 1;
          }
          while (i < ((s32) (*((u8 *) (((char *) options) + 0x12)))));
        }
      }
      if ((*((s32 *) (((char *) options) + 0))) & 4)
      {
        setSoundChannelRamp(*((u8 *) (((char *) options) + 0x10)), *((u16 *) (((char *) options) + 0xE)), *((u8 *) (((char *) entity) + 0xFC4)), 0, 0);
        if ((i = 0) < ((s32) (*((u8 *) (((char *) options) + 0x18)))))
        {
          do
          {
            setSoundChannelRamp(*((u8 *) (((char *) options) + 0x10)), *((u16 *) (((char *) options) + 0xE)), (*((u8 **) (((char *) options) + 0x1C)))[i], 0, 0);
            i += 1;
          }
          while (i < ((s32) (*((u8 *) (((char *) options) + 0x18)))));
        }
      }
    }
    var_a0 = *((s32 *) (((char *) seqData) + 0x10));
    *((s32 *) (((char *) entity) + 0x124)) = var_a0;
    setAudioChannelScaledValue(var_a0, slotIndex & 0xFF);
    tbl = *((s32 *) (((char *) seqData) + 0xC));
    if (tbl != 0)
    {
      temp_v0_3 = (void *) (tbl + ((s32) seqData));
      *((void **) (((char *) entity) + 0xF68)) = temp_v0_3;
      *((void **) (((char *) entity) + 0xF6C)) = temp_v0_3;
      *((s32 *) (((char *) entity) + 0xF70)) = 0;
      *((s32 *) (((char *) entity) + 0xF74)) = 0;
    }
    else
    {
      *((void **) (((char *) entity) + 0xF68)) = NULL;
    }
    i = 0;
    *((s8 *) (((char *) entity) + 0xFC5)) = 0;
    var_a1_3 = (void *) ((*((s32 *) (((char *) seqData) + 0))) + ((s32) seqData));
    do
    {
      *((&D_80102FDC) + i) = 0x7F;
      *((s32 *) (((char *)entity + i * 0x10) + 0x130)) = 0;
      *((s32 *) (((char *)entity + i * 0x10) + 0x134)) = 0;
      *((s32 *) (((char *)entity + i * 0x28) + 0x574)) = 0;
      *((s32 *) (((char *)entity + i * 0x28) + 0x578)) = 0;
      *((s32 *) (((char *)entity + i * 0x28) + 0x57C)) = 0;
      temp_v0_4 = var_a1_3[i];
      if (temp_v0_4 != 0)
      {
        temp_v0_5 = (void *) (temp_v0_4 + ((s32) seqData));
        *((void **) (((char *)entity + i * 0x10) + 0x128)) = temp_v0_5;
        *((void **) (((char *)entity + i * 0x10) + 0x12C)) = temp_v0_5;
      }
      else
      {
 do { *((void **) (((char *)entity + i * 0x10) + 0x128)) = NULL; *((void **) (((char *)entity + i * 0x10) + 0x12C)) = NULL; } while (0);
      }
      i += 1;
    }
    while (i < 0x40);
    i = 0;
    *((s32 *) (((char *) entity) + 0xF78)) = 0;
    *((s32 *) (((char *) entity) + 0xF7C)) = 0;
    do
    {
      audio_slot_reset(i & 0xFF, slotIndex & 0xFF);
      i += 1;
    }
    while (i < 0x10);
    neg1 = -1;
    i = 0xF;
    var_v0_3 = (void *) (0x3C + ((s32) entity));
    do
    {
      *((s32 *) (((char *) var_v0_3) + 0xF80)) = neg1;
      i -= 1;
      var_v0_3 -= 4;
    }
    while (i >= 0);
    var_t1 = ((__repair_field_4 *) entity)->value;
    var_v1_3 = (void *) (8 + ((s32) entity));
    var_a3 = 0;
    do
    {
      var_a2_3 = var_v1_3;
      temp_t0 = (void *) (0x80 + ((s32) var_a2_3));
      do
      {
        temp_v0_6 = *var_a2_3;
        if (temp_v0_6 != 0xFF)
        {
          temp_a1 = (void *) ((temp_v0_6 * 8) + ((s32) var_t1));
          temp_a0_3 = *((u8 *) (((char *) temp_a1) + 4));
          if (temp_a0_3 != 0xFF)
          {
            *((s32 *) (((char *) ((temp_a0_3 * 4) + entity)) + 0xF80)) = (s32) ((((*((u16 *) (((char *) temp_a1) + 0))) << 0x10) | ((*((u8 *) (((char *) temp_a1) + 2))) << 8)) | (*((u8 *) (((char *) temp_a1) + 3))));
          }
        }
        var_a2_3 += 1;
      }
      while (((s32) var_a2_3) < ((s32) temp_t0));
      var_t1 = *((void **) (((char *) entity) + 0x88));
      var_a3 += 1;
      var_v1_3 = (void *) (0x8C + ((s32) entity));
    }
    while (var_a3 < 2);
    if (channelInit != NULL)
    {
      i = 0;
      var_v1_4 = slotIndex & 0xFF;
      slotId = var_v1_4;
      do
      {
        rec = (u8 *) channelInit + i * 8;
        temp_a0_3 = *((u8 *) (((char *) rec) + 4));
        idx1 = temp_a0_3;
        temp_a1_2 = i & 0xFF;
        if (temp_a1_2 != 9)
        {
          temp_v1_2 = *((u8 *) (((char *) (idx1 + entity)) + 8));
          if (temp_v1_2 != 0xFF)
          {
            temp_p = (u8 *) ((s32) (temp_a1_2 * 4) + (s32) entity);
            temp_v1_3 = (void *) ((temp_v1_2 * 8) + ((__repair_field_4 *) entity)->value);
            *((s32 *) (temp_p + 0xF80)) = (s32) ((((*((u16 *) (((char *) temp_v1_3) + 0))) << 0x10) | ((*((u8 *) (((char *) temp_v1_3) + 2))) << 8)) | (*((u8 *) (((char *) temp_v1_3) + 3))));
          }
        }
        else
        {
          temp_v1_4 = *((u8 *) (((char *) ((s32) temp_a0_3 + (s32) entity)) + 0x8C));
          if (temp_v1_4 != 0xFF)
          {
            temp_a0_2 = *((void **) (((char *) entity) + 0x88)); temp_v1_5 = (temp_v1_4 * 8) + temp_a0_2;
            *((s32 *) (((char *) entity) + 0xFA4)) = (s32) ((((*((u16 *) (((char *) temp_v1_5) + 0))) << 0x10) | ((*((u8 *) (((char *) temp_v1_5) + 2))) << 8)) | (*((u8 *) (((char *) temp_v1_5) + 3))));
          }
        }
        temp_s0 = i & 0xFF;
        voiceStoreParam(7, temp_s0, slotId, *((u8 *) (((char *) rec) + 5)));
        {
          voiceStoreParam(0xA, temp_s0, slotId, *((u8 *) (((char *) rec) + 6)));
        }
        voiceStoreParam(0x5B, temp_s0, slotId, *((u8 *) (((char *) rec) + 7)));
        voiceStoreParam(0x5D, temp_s0, slotId, *((u8 *) (((char *) rec) + 8)));
        i += 1;
      }
      while (i < 0x10);
    }
    *((s16 *) (((char *) entity) + 0xFC6)) = 0;
    if ((options == NULL) || (!((*((s32 *) (((char *) options) + 0))) & 0x10)))
    {
      *((s8 *) (((char *) entity) + 0xFC0)) = 1;
    }
    temp_a1_3 = slotIndex;
    do
    {
      var_a2_4 = 0;
      var_v1_4 = 0;
      temp_v0_4 = gSoundEntityIdCounter;
      gSoundEntityIdCounter = (temp_v0_4 + 1) & 0x7FFFFFFF;
      var_a0 = temp_v0_4;
      for (;;) {
          if ((*((&D_800E6A85) + var_v1_4)) != 0)
          {
            var_a2_4 += 1;
            goto block_70;
          }

          if ((*((s32 *) (((u8 *) (&gSoundEntities)) + var_v1_4))) == var_a0)
          {
            var_a0 = -1;
          }
          else
          {
            var_a2_4 += 1;
block_70:
            var_v1_4 += 0xFF8;

            if (var_a2_4 < 8U)
            {
              continue;
            }
          }
          break;
      }
    }
    while (var_a0 == (-1));
    *((s32 *) (((u8 *) (&gSoundEntities)) + (temp_a1_3 * 0xFF8))) = var_a0;
    *((s8 *) (((char *) entity) + 0xFC1)) = 0;
    return var_a0;
  }
  return -1;
}

