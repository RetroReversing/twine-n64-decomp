f32 findNearestTrackMarker(s32, s16 *);
s32 playDistanceSound(s32, f32, u8);
s32 randomIntBelow();
s32 updateSfxPanFromMarker();
extern u8 D_800CE644[];
extern u8 D_800CE64C[];
extern char D_800CE654[];
extern char D_800CE65C[];
extern char D_800CE660[];
extern char D_800CE664[];
extern char D_800CE66C[];
extern char D_800CE670[];
extern char D_800CE678[];
extern char D_800CE688[];
extern char D_800CE69C[];
extern char D_800CE6A0[];
extern char D_800CE6A4[];
extern char D_800CE6AC[];
extern char D_800CE6B4[];
extern char D_800CE6C8[];
extern char D_800CE6CC[];
extern char D_800CE6D0[];
extern char D_800CE6D8[];
extern void *gTrackMarkerParents[];
/* Plays a footstep sound for an actor, choosing a random sound from a table selected by the surface type, then pans it using the nearest track marker. */ void playFootstepSound(void *actor, s32 unused, char variant)
{
  s16 markerIndex;
  s32 result;
  f32 distance;
  u16 soundId;
  s32 surfaceType;
  distance = findNearestTrackMarker((s32) (actor + 0x24), &markerIndex);
  surfaceType = *((u8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xB1));
  switch (surfaceType)
  {
    case 0xB:

    case 0xC:

    case 0xD:

    case 0xE:

    case 0xF:

    case 0x10:

    case 0x11:

    case 0x12:
      soundId = 0x18C;
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE644 + (randomIntBelow(4) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x4:

    case 0xA:

    case 0x1E:

    case 0x1F:

    case 0x24:
      soundId = 0x158;
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE65C + (randomIntBelow(2) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x45:

    case 0x48:

    case 0x72:
      soundId = 0x188;
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE660 + (randomIntBelow(2) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x1B:

    case 0x1C:

    case 0x1D:

    case 0x23:

    case 0x3B:

    case 0x50:

    case 0x54:

    case 0x55:

    case 0x59:

    case 0x5E:

    case 0x6E:
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE664 + (randomIntBelow(4) * 2)));
    }
    else
    {
      soundId = *((u16 *) ((D_800CE69C + 4) + (randomIntBelow(2) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x30:

    case 0x31:

    case 0x71:
      soundId = 0x158;
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE678 + (randomIntBelow(3) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x0:

    case 0x5:

    case 0x6:

    case 0x8:

    case 0x14:

    case 0x22:

    case 0x27:

    case 0x39:

    case 0x5C:

    case 0x5D:

    case 0x61:
      if ((variant << 0x18) == 0)
    {
      soundId = *((u16 *) (D_800CE6A0 + (randomIntBelow(2) * 2)));
    }
    else
    {
      goto block_40;
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x13:

    case 0x2A:

    case 0x33:
      soundId = 0x146;
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE670 + (randomIntBelow(3) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x28:

    case 0x29:

    case 0x43:

    case 0x49:

    case 0x4A:

    case 0x4E:

    case 0x53:

    case 0x5A:

    case 0x60:

    case 0x64:

    case 0x6A:

    case 0x6B:

    case 0x70:
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE688 + (randomIntBelow(7) * 2)));
    }
    else
    {
      soundId = *((u16 *) (D_800CE6D8 - (-(randomIntBelow(8) * 2))));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x16:

    case 0x17:
      soundId = 0x188;
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE6CC + (randomIntBelow(2) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x19:

    case 0x1A:

    case 0x41:
      soundId = 0x158;
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE66C + (randomIntBelow(2) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x42:

    case 0x44:
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE69C + (randomIntBelow(2) * 2)));
    }
    else
    {
      soundId = *((u16 *) ((D_800CE6A4 - 4) + (randomIntBelow(2) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x51:

    case 0x52:

    case 0x5B:

    case 0x75:
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE6A4 + (randomIntBelow(4) * 2)));
    }
    else
    {
      soundId = *((u16 *) (D_800CE6AC + (randomIntBelow(2) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x9:

    case 0x38:

    case 0x78:
      soundId = 0x18C;
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE6D0 + (randomIntBelow(3) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x15:

    case 0x2C:

    case 0x2D:

    case 0x2E:

    case 0x2F:

    case 0x36:

    case 0x37:

    case 0x4B:
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE6B4 + (randomIntBelow(7) * 2)));
    }
    else
    {
      soundId = *((u16 *) ((D_800CE6D0 + 8) + (randomIntBelow(8) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    case 0x2:

    case 0x25:

    case 0x32:

    case 0x57:

    case 0x58:

    case 0x68:

    case 0x69:

    case 0x76:

    case 0x77:
      if ((variant << 0x18) != 0)
    {
      soundId = *((u16 *) (D_800CE6C8 + (randomIntBelow(2) * 2)));
    }
    else
    {
      soundId = *((u16 *) ((D_800CE6AC - 12) + (randomIntBelow(2) * 2)));
    }
      result = playDistanceSound(soundId, distance, 0xFF); break;

    default:
      if ((*((s32 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x14))) & 0x200000)
    {
      soundId = *((u16 *) (D_800CE654 + (randomIntBelow(3) * 2)));
      result = playDistanceSound(soundId, distance, 0xFF); goto play;
    }
      block_40:
    soundId = *((u16 *) (D_800CE64C + (randomIntBelow(3) * 2)));

      result = playDistanceSound(soundId, distance, 0xFF); break;

  }

  play:
  updateSfxPanFromMarker(result, gTrackMarkerParents[(u16) markerIndex], actor + 0x24, 0);

}


