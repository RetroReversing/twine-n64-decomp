#define FIELD(p,t,o) (*(t *)((u8 *)(p)+(o)))
extern s32 findActionSlot(s32, s32, s32);
extern s32 func_800312F4(s16, u16);
extern f32 Vec3_DistanceSq(void *, void *);
extern void func_80074C34(s32, s32 *, s32);
extern s32 D_800C7EE4;
extern u8 D_800C7EE8[];
extern u8 D_800C7EE9[];
extern u8 D_80115091[];
extern u8 D_800CEEB0;
extern s32 *D_800C7EEC[];
extern void * volatile sBonusObjectTable;
extern s8 func_801183F4[];
void func_8007514C(void *obj)
{
  volatile unsigned short near;
  s32 slot;
  s32 force;
  s32 **scripts;
  s32 entryOffset;
  u8 mode;
  void *actor;
  void *bonus;
  void *position;
  s32 objectIndex;
  f32 limit;
  if (D_800CEEB0 || (!sBonusObjectTable))
  {
    return;
  }
  objectIndex = *((s16 *) (((u8 *) obj) + 0x7C));
  bonus = sBonusObjectTable;
  mode = D_800C7EE8[objectIndex * 12];
  limit = 3.0f;
  actor = *((void **) (((u8 *) bonus) + 0x6C));
  force = 0;
  switch (mode)
  {
    case 0:

    case 3:
      goto joined;

    case 1:
      if ((findActionSlot((s32) actor, 2, 1) << 24) == 0)
    {
      return;
    }
      if (!func_801183F4[0x55F])
    {
      return;
    }
      force = 1;
      goto joined;

    case 2:
      if (func_800312F4(2, 0) == 3)
    {
      return;
    }
      near = force;
      goto check;

    case 4:
      force = 1;
      if (!(*((u8 *) (((u8 *) actor) + 0x23C))))
    {
      return;
    }
      goto joined;

    case 5:
      force = 1;
      if ((*((s8 *) (((u8 *) (*((void **) (((u8 *) sBonusObjectTable) + 0x68)))) + 0xE))) != 41)
    {
      return;
    }
      goto joined;

  }

  joined:
  near = force;

  check:
  position = ((u8 *) obj) + 0x24;

  if ((!((s16) near)) && (!(Vec3_DistanceSq(position, ((u8 *) sBonusObjectTable) + 0x24) < limit)))
  {
    return;
  }
  switch (D_80115091[(*((s8 *) (((u8 *) actor) + 0x182))) * 160])
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

  entryOffset = (*((s16 *) (((u8 *) obj) + 0x7C))) * 12;
  if (!((volatile u8 *) D_800C7EE9)[entryOffset])
  {
    ((volatile u8 *) D_800C7EE9)[entryOffset] = 1;
    scripts = D_800C7EEC;
    if ((*(*((s32 **) ((slot * 4) + (((u8 *) scripts) + ((*((s16 *) (((u8 *) obj) + 0x7C))) * 12)))))) >= 0)
    {
      D_800C7EE4 = 1;
    }
    func_80074C34(0, *((s32 **) ((slot * 4) + (((u8 *) scripts) + ((*((s16 *) (((u8 *) obj) + 0x7C))) * 12)))), 1);
    D_800C7EE4 = 2;
  }
  *((s32 *) (((u8 *) obj) + 0x60)) |= 1;
}

