f32 approxDistance(void *, void *);
f32 readRomTableScaledValue(s32);
s32 spawnWrappedCaptions(s32, s32, s32, s32, f32, s32);
s32 lookupDataEntry(u16);
extern s32 D_800C7EE4;
extern u8 D_80100310[];
typedef struct 
{
  s8 f0;
  u8 pad[7];
} Slot_80100314;
extern Slot_80100314 D_80100314[];
extern void *gCaptionMessages;
extern int gTrackMarkerSerial;
extern void *sBonusObjectTable;
extern u8 gTrackMarkerActiveCount;
extern s16 gCaptionMessageCount;
extern s32 gTrackMarkerParents;
inline static s32 inline_fn()
{
  return (s32) gTrackMarkerActiveCount;
}

/* Registers a list of track markers (once), then spawns a caption for each and links the captions to the owner object. */ void registerTrackMarkers(void *owner, void *markers, s32 markerCount)
{
  void **__base_D_80100B20;
  f32 temp_fv0;
  f32 four;
  f32 captionHeight;
  s32 temp_v0;
  s32 off;
  s32 cnt;
  u32 end;
  s32 low;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 alreadyRegistered;
  s32 index;
  u32 var_v1;
  void **temp_s7;
  void **var_s2;
  void *captionData;
  void *marker;
  void *var_v0;
  void *entry;
  volatile s32 frame[4];
  __base_D_80100B20 = &gCaptionMessages;
  alreadyRegistered = 0;
  if (owner != NULL)
  {
    *((s32 *) (((char *) owner) + 0x60)) = (s32) ((*((s32 *) (((char *) owner) + 0x60))) | 0x10000000);
  }
  index = 0;
  if (inline_fn() > 0)
  {
    temp_v1 = inline_fn();
    var_v1 = 0;
    do
    {
      if ((*((void **) (D_80100310 + var_v1))) == markers)
      {
        alreadyRegistered = 1;
      }
      index += 1;
      var_v1 += 8;
    }
    while (index < temp_v1);
  }
  end = alreadyRegistered;
  if (end == 0)
  {
    do
    {
      off = gTrackMarkerActiveCount * 8;
      *((s8 *) ((char *) D_80100314 + off)) = markerCount;
      cnt = gTrackMarkerActiveCount;
      *((void **) (D_80100310 + off)) = markers;
      gTrackMarkerActiveCount = cnt + 1;
    }
    while (0);
  }
  gTrackMarkerSerial += 1;
  if (markerCount != 0)
  {
    marker = markers;
    end = (u32) markers;
    four = 4.0f;
    temp_s7 = __base_D_80100B20 - 1;
    do
    {
      captionHeight = 5.0f;
      if ((*((u16 *) (((char *) marker) + 6))) == 0x237)
      {
        captionHeight = 0.0f;
      }
      temp_v0 = *((s32 *) (((char *) marker) + 0));
      low = temp_v0 & 0xFFFFFF;
      if (temp_v0 & 0x80000000)
      {
        captionHeight = readRomTableScaledValue(low);
      }
      captionHeight += 0.5f;
      spawnWrappedCaptions(gTrackMarkerParents, lookupDataEntry(*((u16 *) (((char *) marker) + 6))), 0x20, 2, captionHeight, D_800C7EE4);
      if (gCaptionMessageCount)
      {
        do
        {
          index = 0;
        }
        while (0);
        if (gCaptionMessageCount > 0)
        {
          entry = marker;
          var_s2 = __base_D_80100B20;
          do
          {
            var_v0 = *var_s2;
            if (var_v0 != NULL)
            {
              captionData = *((void **) (((char *) var_v0) + 0x6C));
              if (owner != NULL)
              {
                *((void **) (((char *) captionData) - (-0x2C))) = owner;
                {
                  typedef struct 
                  {
                    s32 word[3];
                  } MarkerPosition;
                  *((MarkerPosition *) (((char *) captionData) + 8)) = *((MarkerPosition *) (((char *) owner) + 0x24));
                }
                temp_fv0 = approxDistance(captionData + 8, ((u8 *) sBonusObjectTable) + 0x24);
                *((f32 *) (((char *) captionData) + 0x28)) = temp_fv0;
                if (temp_fv0 < four)
                {
                  *((f32 *) (((char *) captionData) + 0x28)) = four;
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
              var_v0 = temp_s7[gCaptionMessageCount];
            }
            captionData = *((void **) (((char *) var_v0) + 0x6C));
            *((s32 *) (((char *) captionData) + 0x24)) = temp_v1_2;
            captionData = *((void **) (((char *) temp_s7[gCaptionMessageCount]) + 0x6C));
            *((s8 *) (((char *) captionData) + 0x32)) = (s8) (*((u16 *) (((char *) entry) + 4)));
            index += 1;
            var_s2++;
          }
          while (index < gCaptionMessageCount);
        }
      }
      marker += 8;
    }
    while (end = ((2 * (2 * ((u32) markerCount))) * 2) + (u32) markers, (u32) marker < end);
  }
}


