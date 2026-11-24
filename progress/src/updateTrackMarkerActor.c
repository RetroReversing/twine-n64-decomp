s32 actorLinkToSurface(s32, void *, s32);
s32 actorUnlinkFromSurface(void *);
s32 advanceActorMotion(void *, u32);
s32 advanceMotionPath(void *, s32, s32, s8);
s32 loadObjectKeyframeVectors(s8, void *);
s32 spawnCaptionMessage(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 playSoundAtPos(volatile unsigned int, void *);
s32 allocSpriteEntry(u16, f32, f32);
s32 getTrackTriggerMask(u16);
s32 listUnlinkFree(s32);
s32 lookupDataEntry(u16);
s32 markObjectsNearPos(s32, s32, s32, void *, f32, s32);
s32 randomIntBelow(s32);
s32 updateActorTrackingState(void *, s32);
extern s8 gSineTable[];
extern u8 D_800CA338;
extern void *gChasedObject;
extern s32 *gDefaultOrderObj;
extern u8 gTrackMarkerDone[];
extern s32 gTrackMarkerParents;
inline static u16 *inline_fn(void *arg0, int arg1)
{
  return (u16 *) (((char *) arg0) + arg1);
}

#define AF(T, o) (*(T *)((char *)a + (o)))
#define TF(T, o) (*(T *)((char *)t + (o)))
#define SETD(o, v) if (TF(u16, o)) gTrackMarkerDone[TF(u16, o)] = (v)
#define PLAY(o) if (TF(u16, o)) TF(s32, 0x28) = playSoundAtPos(TF(u16, o), (char *)a + 0x24)
#define MARKNEAR() markObjectsNearPos(AF(s32, 0x20), 0, 0x01000000, (char *)a + 0x24, *(f32 *)((char *)AF(void *, 0x70) + 0x14) + 1.0f, 0)
#define CAPTION(id) do { var_a2 = lookupDataEntry(id); spawnCaptionMessage(0, gTrackMarkerParents, var_a2, -1, -1, 1, 0, 0, 5, 0, 0x3C); playSoundAtPos(9, (char *)a + 0x24); } while (0)
#define ACTIVATE() do { SETD(0x36, 0); SETD(0x34, 1); SETD(0x3A, 2); AF(s16, 0x7A) = 2; TF(f32, 8) = 0.0f; } while (0)
#define DEACTIVATE() do { SETD(0x38, 0); SETD(0x34, 0); SETD(0x3A, 2); AF(s16, 0x7A) = 7; TF(f32, 8) = 0.0f; } while (0)

/* Per-frame state machine for a track marker actor (doors, platforms, switches, sprites, bobbing objects), driven by its track data type and its state field. */ void updateTrackMarkerActor(void *a)
{
  void *t;
  struct { f32 x, y, z; } d;
  s32 var_a2;
  t = AF(void *, 0x6C);
  if (D_800CA338 == 1)
  {
    if (TF(s32, 0x4C) & 0x40)
      AF(u8, 0x7E) = 0xB;
  }
  else if (TF(s32, 0x4C) & 0x40)
    AF(u8, 0x7E) = TF(u8, 0x4E);
  switch (TF(u8, 0x4A))
  {
    case 0:
      switch (AF(s16, 0x7A))
      {
        case 0:
          if (advanceActorMotion(a, 1) << 0x18) { TF(f32, 8) = 0.0f; AF(s16, 0x7A) = 1; }
          break;
        case 1:
          if (advanceActorMotion(a, -1) << 0x18) { TF(f32, 8) = 0.0f; AF(s16, 0x7A) = 0; }
          break;
      }
      break;
    case 1:
      switch (AF(s16, 0x7A))
      {
        case 0:
          if (advanceMotionPath(a, 1, TF(u16, 0x44), 0)) { TF(f32, 8) = 0.0f; AF(s16, 0x7A) = 1; }
          break;
        case 1:
          if (advanceMotionPath(a, -1, TF(u16, 0x44), 0)) { TF(f32, 8) = 0.0f; AF(s16, 0x7A) = 0; }
          break;
      }
      break;
    case 19:
      switch (AF(s16, 0x7A))
      {
        case 0:
          actorUnlinkFromSurface(a);
          AF(s16, 0x7A) = 1;
          break;
        case 1:
          if (TF(u16, 0x34) == 0 || gTrackMarkerDone[TF(u16, 0x34)] == 0)
            break;
          {
            s32 *probe = gDefaultOrderObj;
            AF(s16, 0x7A) = 2;
            actorLinkToSurface(*probe, a, 0);
          }
        case 2:
          gChasedObject = a;
          if (advanceActorMotion(a, 1) << 0x18)
          {
            s32 m = TF(u16, 0x36);
            gChasedObject = NULL;
            if (m)
              gTrackMarkerDone[m] = 1;
            AF(s16, 0x7A) = 3;
          }
          AF(s32, 0x58) |= 1;
          break;
      }
      break;
    case 18:
      if (AF(s16, 0x7A) == 0 && (AF(s32, 0x60) & 0x100010) == 0x10 && TF(s8, 0x4C) > 0)
      {
        MARKNEAR();
        if (advanceActorMotion(a, 1) << 0x18)
        {
          SETD(0x34, 1);
          AF(s16, 0x7A) = 1;
        }
        AF(s32, 0x58) |= 1;
      }
      break;
    case 6:
      switch (AF(s16, 0x7A))
      {
        case 0:
          TF(s32, 0) = allocSpriteEntry(TF(u16, 0x34), (f32) TF(u16, 0x36), (f32) TF(u16, 0x38));
          AF(s16, 0x7A) = 1;
          break;
        case 1:
          TF(u16, 0x3C) = randomIntBelow(0x1E) * TF(u16, 0x3A);
          AF(s16, 0x7A) = 2;
          break;
        case 2:
          if (TF(u16, 0x3C) == 0)
            AF(s16, 0x7A) = 3;
          TF(u16, 0x3C) = TF(u16, 0x3C) - 1;
          break;
        case 3:
          d.x = AF(f32, 0x24) - AF(f32, 0x30);
          d.y = AF(f32, 0x28) - AF(f32, 0x34);
          d.z = AF(f32, 0x2C) - AF(f32, 0x38);
          if (advanceActorMotion(a, 1) << 0x18)
          {
            TF(s8, 0x4B) = 0;
            TF(f32, 8) = 0.0f;
            loadObjectKeyframeVectors(0, a);
            AF(f32, 0x30) = AF(f32, 0x24) + d.x;
            AF(f32, 0x34) = AF(f32, 0x28) + d.y;
            AF(f32, 0x38) = AF(f32, 0x2C) + d.z;
            if (TF(u16, 0x3A))
              AF(s16, 0x7A) = 1;
          }
          updateActorTrackingState(a, TF(s32, 0));
          AF(s32, 0x58) |= 1;
          break;
      }
      break;
    case 7:
      switch (AF(s16, 0x7A))
      {
        case 0:
          AF(s16, 0x7A) = 1;
          TF(s8, 0x4B) = 0;
          TF(f32, 8) = 0.0f;
          loadObjectKeyframeVectors(TF(s8, 0x4B), a);
        case 1:
          if (advanceMotionPath(a, 1, TF(u16, 0x44), 0))
            AF(s16, 0x7A) = 0;
          break;
      }
      AF(s32, 0x58) |= 1;
      break;
    case 20:
      if ((AF(s32, 0x60) & 0x100800) == 0x800)
      {
        s32 *pp = (s32 *) &gTrackMarkerParents;
        var_a2 = lookupDataEntry(TF(u16, 0x48));
        spawnCaptionMessage(0, *pp, var_a2, -1, -1, 1, 0, 0, 5, 0, 0x3C);
        playSoundAtPos(9, (char *)a + 0x24);
      }
      break;
    case 4:
    case 5:
    case 10:
    case 11:
    case 12:
    case 13:
    case 16:
    case 17:
      switch (AF(s16, 0x7A))
      {
        case 0:
          if (!(TF(u16, 0x42) == 0 || gTrackMarkerDone[TF(u16, 0x42)] == 0))
            break;
          if (TF(u16, 0x34))
          {
            if (gTrackMarkerDone[TF(u16, 0x34)] == TF(u16, 0x36))
            {
              TF(u16, 0x46) = TF(u16, 0x44);
              PLAY(0x3A);
              AF(s16, 0x7A) = 1;
              TF(f32, 8) = 0.0f;
            }
            else if ((AF(s32, 0x60) & 0x100800) == 0x800)
            {
              s16 cid = TF(s16, 0x48);
              if (cid != -1)
                CAPTION(cid);
            }
          }
          else if (AF(s32, 0x60) & 0x100800)
          {
            if (TF(u8, 0x4A) - 10 < 2U || TF(u8, 0x4A) - 12 < 2U)
            {
              if (AF(s32, 0x60) & 8)
                TF(s8, 0x4D) = 0;
              else
                TF(s8, 0x4D) = 1;
            }
            TF(u16, 0x46) = 0x14;
            PLAY(0x3A);
            AF(s16, 0x7A) = 1;
            TF(f32, 8) = 0.0f;
          }
          break;
        case 1:
        {
          f32 r = (f32) TF(s16, 0x46);
          MARKNEAR();
          if (advanceMotionPath(a, 1, (s32) r, TF(s8, 0x4D)))
            AF(s16, 0x7A) = 2;
        }
          break;
        case 2:
          AF(s16, 0x7A) = 3;
          TF(f32, 8) = 900.0f;
          if (TF(u16, 0x3A))
            listUnlinkFree(TF(s32, 0x28));
          PLAY(0x3C);
          break;
        case 3:
          SETD(0x38, 1);
          AF(s16, 0x7A) = 4;
          break;
        case 4:
          if (TF(u16, 0x42) == 0 || gTrackMarkerDone[TF(u16, 0x42)] == 0)
          {
            if (TF(u16, 0x34))
            {
              if (gTrackMarkerDone[TF(u16, 0x34)] != TF(u16, 0x36))
              {
                TF(u16, 0x46) = TF(u16, 0x44);
                PLAY(0x3E);
                AF(s16, 0x7A) = 5;
                TF(f32, 8) = 0.0f;
              }
            }
            else if (AF(s32, 0x60) & 0x800)
            {
              TF(u16, 0x46) = 0x14;
              PLAY(0x3E);
              AF(s16, 0x7A) = 5;
              TF(f32, 8) = 0.0f;
            }
            else
            {
              TF(f32, 8) = TF(f32, 8) - 1.0f;
              if (TF(f32, 8) <= 0.0f)
              {
                TF(u16, 0x46) = 0x14;
                PLAY(0x3E);
                AF(s16, 0x7A) = 5;
                TF(f32, 8) = 0.0f;
              }
            }
          }
          break;
        case 5:
        {
          f32 r = (f32) TF(s16, 0x46);
          MARKNEAR();
          if (advanceMotionPath(a, -1, (s32) r, 0))
            AF(s16, 0x7A) = 6;
        }
          break;
        case 6:
          AF(s16, 0x7A) = 7;
          if (TF(u16, 0x3E))
            listUnlinkFree(TF(s32, 0x28));
          PLAY(0x40);
          break;
        case 7:
          if (TF(u16, 0x38))
            gTrackMarkerDone[TF(u16, 0x38)] = 0;
          AF(s16, 0x7A) = 0;
          break;
      }
      break;
    case 2:
    case 14:
      switch (AF(s16, 0x7A))
      {
        case 0:
          SETD(0x3A, 0);
          SETD(0x36, 1);
          if (TF(u16, 0x34) && gTrackMarkerDone[TF(u16, 0x34)] == 1)
            goto act2;
          if (!(AF(s32, 0x60) & getTrackTriggerMask(TF(u16, 0x40))))
            AF(s16, 0x7A) = 1;
          break;
        case 1:
          if ((TF(u16, 0x34) && gTrackMarkerDone[TF(u16, 0x34)] == 1) || (AF(s32, 0x60) & getTrackTriggerMask(TF(u16, 0x40))))
          {
            act2:
            ACTIVATE();
          }
          break;
        case 2:
          if (TF(u16, 0x3C) == 0 || gTrackMarkerDone[TF(u16, 0x3C)] == 0)
          {
            AF(s16, 0x7A) = 3;
            PLAY(0x3E);
          }
          break;
        case 3:
          MARKNEAR();
          if (advanceActorMotion(a, 1) << 0x18)
            AF(s16, 0x7A) = 4;
          break;
        case 4:
          AF(s16, 0x7A) = 5;
          SETD(0x38, 1);
          TF(f32, 8) = 300.0f;
          if (TF(u16, 0x3E))
            listUnlinkFree(TF(s32, 0x28));
          break;
        case 5:
          SETD(0x3A, 1);
          SETD(0x38, 1);
          if (TF(u16, 0x34) && gTrackMarkerDone[TF(u16, 0x34)] == 0)
            goto deact3;
          if (TF(u8, 0x4A) == 0xE)
          {
            TF(f32, 8) = TF(f32, 8) - 1.0f;
            if (TF(f32, 8) <= 0.0f)
              goto set6;
          }
          if (!(AF(s32, 0x60) & getTrackTriggerMask(TF(u16, 0x40))))
            AF(s16, 0x7A) = 6;
          break;
        case 6:
          if (TF(u16, 0x34) && gTrackMarkerDone[TF(u16, 0x34)] == 0)
            goto deact3;
          if (TF(u8, 0x4A) == 0xE)
          {
            TF(f32, 8) = TF(f32, 8) - 1.0f;
            if (TF(f32, 8) <= 0.0f)
              goto deact2;
          }
          if (AF(s32, 0x60) & getTrackTriggerMask(TF(u16, 0x40)))
          {
            deact2:
            DEACTIVATE();
          }
          break;
        case 7:
          if (TF(u16, 0x3C) == 0 || gTrackMarkerDone[TF(u16, 0x3C)] == 0)
          {
            AF(s16, 0x7A) = 8;
            PLAY(0x3E);
          }
          break;
        case 8:
          MARKNEAR();
          if (advanceActorMotion(a, -1) << 0x18)
            AF(s16, 0x7A) = 9;
          break;
        case 9:
          AF(s16, 0x7A) = 0;
          SETD(0x36, 1);
          if (TF(u16, 0x3E))
            listUnlinkFree(TF(s32, 0x28));
          break;
      }
      break;
    case 3:
    case 15:
      switch (AF(s16, 0x7A))
      {
        case 0:
          SETD(0x3A, 0);
          SETD(0x36, 1);
          if (TF(u16, 0x34) && gTrackMarkerDone[TF(u16, 0x34)] == 1)
            goto act3;
          if (!(AF(s32, 0x60) & getTrackTriggerMask(TF(u16, 0x40))) || (AF(s32, 0x60) & 0x200000))
            AF(s16, 0x7A) = 1;
          break;
        case 1:
          if ((TF(u16, 0x34) && gTrackMarkerDone[TF(u16, 0x34)] == 1) || (AF(s32, 0x60) & (getTrackTriggerMask(TF(u16, 0x40)) | 0x200000)))
          {
            act3:
            ACTIVATE();
          }
          break;
        case 2:
          if (TF(u16, 0x3C) == 0 || gTrackMarkerDone[TF(u16, 0x3C)] == 0)
          {
            AF(s16, 0x7A) = 3;
            PLAY(0x3E);
          }
          break;
        case 3:
          MARKNEAR();
          if (advanceMotionPath(a, 1, TF(u16, 0x44), 0))
            AF(s16, 0x7A) = 4;
          break;
        case 4:
          AF(s16, 0x7A) = 5;
          SETD(0x38, 1);
          TF(f32, 8) = 300.0f;
          if (TF(u16, 0x3E))
            listUnlinkFree(TF(s32, 0x28));
          break;
        case 5:
          SETD(0x3A, 1);
          SETD(0x38, 1);
          if (TF(u16, 0x34) && gTrackMarkerDone[TF(u16, 0x34)] == 0)
            goto deact3;
          if (TF(u8, 0x4A) == 0xF)
          {
            TF(f32, 8) = TF(f32, 8) - 1.0f;
            if (TF(f32, 8) <= 0.0f)
            {
              set6:
              AF(s16, 0x7A) = 6;
              goto deact3;
            }
          }
          if (!(AF(s32, 0x60) & getTrackTriggerMask(TF(u16, 0x40))))
            AF(s16, 0x7A) = 6;
          break;
        case 6:
          if (TF(u16, 0x34) && gTrackMarkerDone[TF(u16, 0x34)] == 0)
            goto deact3;
          if (TF(u8, 0x4A) == 0xF)
          {
            TF(f32, 8) = TF(f32, 8) - 1.0f;
            if (TF(f32, 8) <= 0.0f)
              goto deact3;
          }
          if (AF(s32, 0x60) & getTrackTriggerMask(TF(u16, 0x40)))
          {
            deact3:
            DEACTIVATE();
          }
          break;
        case 7:
          if (TF(u16, 0x3C) == 0 || gTrackMarkerDone[TF(u16, 0x3C)] == 0)
          {
            AF(s16, 0x7A) = 8;
            PLAY(0x3E);
          }
          break;
        case 8:
          MARKNEAR();
          if (advanceMotionPath(a, -1, TF(u16, 0x44), 0))
            AF(s16, 0x7A) = 9;
          break;
        case 9:
          AF(s16, 0x7A) = 0;
          SETD(0x36, 1);
          if (TF(u16, 0x3E))
            listUnlinkFree(TF(s32, 0x28));
          break;
      }
      break;
    case 9:
    {
      u32 idx;
      f32 pv;
      AF(u16, 0x7C) = AF(u16, 0x7C) + 1;
      idx = (u32) ((f32) AF(u16, 0x7C) + AF(f32, 0x24) + AF(f32, 0x2C));
      pv = (f32) gSineTable[(idx / 3) & 0x7F] * 0.0000078125f; AF(f32, 0x28) = AF(f32, 0x28) + pv;
      idx = (u32) ((f32) AF(u16, 0x7C) + AF(f32, 0x24) + AF(f32, 0x2C));
      pv = (f32) gSineTable[(idx >> 2) & 0x7F] * 0.0015625f; AF(f32, 0x44) = AF(f32, 0x44) + pv;
      idx = (u32) ((f32) AF(u16, 0x7C) + AF(f32, 0x24) + AF(f32, 0x2C));
      pv = (f32) gSineTable[(idx >> 1) & 0x7F] * 0.0015625f; AF(f32, 0x3C) = AF(f32, 0x3C) + pv;
      if (AF(s16, 0x7A) == 0 && TF(s32, 4) != 0 && (TF(u16, 0x34) == 0 || gTrackMarkerDone[TF(u16, 0x34)] != 0))
      {
        AF(s32, 0x58) |= 1;
        if (advanceActorMotion(a, 1) << 0x18)
        {
          TF(f32, 8) = 0.0f;
          AF(s16, 0x7A) = 1;
        }
      }
    }
      break;
  }
  AF(s32, 0x60) = AF(s32, 0x60) & 1;
}
