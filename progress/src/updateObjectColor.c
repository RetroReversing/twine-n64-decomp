f32 sinTableLookup(f32);
f32 cosTableLookup(f32);
s32 guRandom(void);
extern s32 gColorUpdateStamp;
extern f32 gAnimTime;
extern u32 gTickCount;
extern u8 gBaseColorR;
extern u8 gBaseColorB;
extern u8 gBaseColorG;
typedef struct { char pad[0x60]; u16 w60; u8 pad2[2]; u8 r; u8 g; u8 b; } Col;
typedef struct { char pad[0x20]; Col *col; char pad2[0x34]; u32 flags; } Obj;
/* Updates an object's vertex color once per stamp: pulses, flickers or static noise depending on its effect flags, else the base color. */ void updateObjectColor(Obj *obj)
{
  u32 effectBits;
  u32 pulseRed;
  u32 flicker;
  u32 yellowPulse;
  u32 staticLow;
  u32 staticHigh;
  if (obj->col->w60 != gColorUpdateStamp)
  {
    obj->col->w60 = gColorUpdateStamp;
    effectBits = obj->flags >> 2;
    if (effectBits & 0x10)
    {
      pulseRed = (u32)(sinTableLookup((f32)gTickCount * 0.1f) * 64.0f + 192.0f);
      obj->col->r = pulseRed;
      obj->col->g = 0x40;
      obj->col->b = 0x40;
      return;
    }
    else if (effectBits & 0x80)
    {
      flicker = (u32)(sinTableLookup(gAnimTime * 0.02f) * (cosTableLookup(0.07f * gAnimTime) * 64.0f) * sinTableLookup(gAnimTime * 0.04f)) + 64;
      obj->col->r = flicker;
      obj->col->g = flicker;
      obj->col->b = flicker;
      return;
    }
    if (effectBits & 0x40)
    {
      yellowPulse = (u32)(sinTableLookup(gAnimTime * 0.2f) * 128.0f + 128.0f) | 8;
      obj->col->r = yellowPulse;
      obj->col->g = yellowPulse;
      obj->col->b = 8;
    }
    else if (effectBits & 0x20)
    {
      if (obj->col->r < 0x20U)
      {
        if (guRandom() % 30 == 0)
        {
          staticLow = guRandom() % 128 - 128;
          obj->col->r = staticLow;
          obj->col->g = staticLow;
          obj->col->b = staticLow;
        }
      }
      else
      {
        if (guRandom() % 3 == 0)
        {
          staticHigh = guRandom() % 128 - 128;
          obj->col->r = staticHigh;
          obj->col->g = staticHigh;
          obj->col->b = staticHigh;
        }
      }
    }
    else
    {
      obj->col->r = gBaseColorR;
      obj->col->g = gBaseColorG;
      obj->col->b = gBaseColorB;
    }
  }
}
