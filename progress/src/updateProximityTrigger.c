#define FIELD(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern s32 findActionSlot(s32, s32, s32);
extern s32 getEntryKind(s16, u16);
extern f32 vec3DistanceBetween(void *, void *);
extern void registerTrackMarkers(s32, s32 *, s32);
extern s32 D_800C7EE4;
extern u8 gTriggerTable[];
extern u8 D_800C7EE9[];
extern u8 D_80115091[];
extern u8 gDemoRecordingActive;
extern s32 *gTriggerScripts[];
extern void * volatile sBonusObjectTable;
extern s8 selectActorTarget[];
/* Fires a trigger's track-marker script once when its activation condition holds (by mode) or the bonus object is within range. */ void updateProximityTrigger(void *trigger)
{
  register s32 isNear;
  s32 slot;
  s32 alwaysActive;
  s32 **scripts;
  s32 entryIndex12;
  u8 mode;
  void *player;
  void *bonusOrPos;
  s32 objectIndex;
  f32 radiusSq;
  if (gDemoRecordingActive || (!sBonusObjectTable))
  {
    return;
  }
  entryIndex12 = *((s16 *) (((u8 *) trigger) + 0x7C));
  bonusOrPos = sBonusObjectTable;
  mode = gTriggerTable[entryIndex12 * 12];
  radiusSq = 3.0f;
  player = *((void **) (((u8 *) bonusOrPos) + 0x6C));
  alwaysActive = 0;
  switch (mode)
  {
    case 0:

    case 3:
      goto joined;

    case 1:
      if ((findActionSlot((s32) player, 2, 1) << 24) == 0)
    {
      return;
    }
      if (!selectActorTarget[0x55F])
    {
      return;
    }
      alwaysActive = 1;
      goto joined;

    case 2:
      if (getEntryKind(2, 0) == 3)
    {
      return;
    }
      isNear = alwaysActive;
      goto check;

    case 4:
      if (!(*((u8 *) (((u8 *) player) + 0x23C))))
    {
      return;
    }
      alwaysActive = 1;
      goto joined;

    case 5:
      if ((*((s8 *) (((u8 *) (*((void **) (((u8 *) sBonusObjectTable) + 0x68)))) + 0xE))) != 41)
    {
      return;
    }
      alwaysActive = 1;
      goto joined;

  }

  joined:
  isNear = alwaysActive;
  check:
  bonusOrPos = ((u8 *) trigger) + 0x24;

  if ((!isNear) && (!(vec3DistanceBetween(bonusOrPos, ((u8 *) sBonusObjectTable) + 0x24) < radiusSq)))
  {
    return;
  }
  switch (D_80115091[(*((s8 *) (((u8 *) player) + 0x182))) * 160])
  {
    case 2:

    case 4:

    case 6:

    default:
      slot = 0;
      break;

    case 1:

    case 3:

    case 5:

    case 7:
      slot = 1;
      break;

  }

  entryIndex12 = (*((s16 *) (((u8 *) trigger) + 0x7C))) * 12;
  if (!((volatile u8 *) D_800C7EE9)[entryIndex12])
  {
    ((volatile u8 *) D_800C7EE9)[entryIndex12] = 1;
    scripts = gTriggerScripts;
    if ((*(*((s32 **) ((slot * 4) + (((u8 *) scripts) + ((*((s16 *) (((u8 *) trigger) + 0x7C))) * 12)))))) >= 0)
    {
      D_800C7EE4 = 1;
    }
    registerTrackMarkers(0, *((s32 **) ((slot * 4) + (((u8 *) scripts) + ((*((s16 *) (((u8 *) trigger) + 0x7C))) * 12)))), 1);
    D_800C7EE4 = 2;
  }
  *((s32 *) (((u8 *) trigger) + 0x60)) |= 1;
}



