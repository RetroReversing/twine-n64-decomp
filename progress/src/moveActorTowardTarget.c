extern u8 gSaveSlotInfo[];
extern u8 D_800BF688[];
extern u8 D_8011EE68[];
extern u8 D_8011EE70[];
f32 approxDistanceXZ(void *, f32 *);
s32 getSaveSlotIndex(s32);
s32 setActorCommandState(void *, s32);
f32 approximateAtan2(f32, f32);
f32 sinAngle(f32);
f32 cosAngle(f32);
f32 absFloat(f32);
void easeActorAngle(void *, s32, f32);
/* Walks an actor toward targetPos at a speed set by its save slot; stops and faces the target once the remaining distance is used up. Returns the speed magnitude. */ f32 moveActorTowardTarget(u8 *actor, f32 *targetPos, f32 *remaining)
{
  u8 *player;
  f32 speed;
  f32 stepSpeed;
  f32 heading;
  f32 baseSpeed;
  f32 t;
  f32 dx;
  f32 dz;
  f32 distance;
  s32 walkAnim;
  s32 speedClass;
  s32 k;
  s32 yaw;
  u16 x;
  u16 t16;
  player = *((u8 **) (actor + 0x6C));
  distance = approxDistanceXZ(actor + 0x24, targetPos);
  if (distance < remaining[0])
  {
    remaining[0] = distance;
  }
  x = getSaveSlotIndex((u16) ((s8) player[0x182])) & 0xFFFF;
  k = *((u32 *) (gSaveSlotInfo + (x * 24)));
  t16 = *((u16 *) (D_800BF688 + (k * 12)));
  speedClass = (t16 >> 2) & 7;
  switch (speedClass)
  {
    case 1:

    default:
      speed = 0.074f;
      walkAnim = 0x15F;
      break;

    case 2:
      speed = 0.149f;
      walkAnim = 0x165;
      break;

    case 3:
      speed = 0.16000001f;
      walkAnim = 0x171;
      break;

    case 4:
      speed = 0.2f;
      walkAnim = 0x171;
      break;

    case 5:
      speed = 0.23f;
      walkAnim = 0x171;
      break;

  }

  *((f32 *) (player + 0x80)) = speed;
  baseSpeed = *((volatile f32 *) (player + 0x80));
  t = remaining[0] - baseSpeed;
  remaining[0] = t;
  if ((t < baseSpeed) || ((*((s16 *) (actor + 0x7A))) == 7))
  {
    remaining[0] = 0.0f;
    setActorCommandState(actor, 0x14D);
    dx = targetPos[0] - (*((f32 *) (actor + 0x24)));
    dz = targetPos[2] - (*((f32 *) (actor + 0x2C)));
    if ((dx == 0.0f) & (dz == 0.0f))
    {
      yaw = (s32) (*((f32 *) (actor + 0x40)));
    }
    else
    {
      yaw = (s32) (approximateAtan2(dx, dz) * 651.8986f);
    }
    easeActorAngle(actor, yaw, (f32) 0.2);
    return 0.0f;
  }
  dz = targetPos[2] - (*((f32 *) (actor + 0x2C)));
  dx = targetPos[0] - (*((f32 *) (actor + 0x24)));
  if ((dx == 0.0f) & (dz == 0.0f))
  {
    yaw = (s32) (*((f32 *) (actor + 0x40)));
  }
  else
  {
    yaw = (s32) (approximateAtan2(dx, dz) * 651.8986f);
  }
  easeActorAngle(actor, yaw, 0.2f);
  if (remaining[0] != 0.0f)
  {
    f32 curSpeed = *((f32 *) (player + 0x80));
 do { *((f32 *) (player + 0x80)) = curSpeed + ((baseSpeed - curSpeed) * 0.1f); } while (0);
  }
  stepSpeed = *((f32 *) (player + 0x80));
  heading = *((f32 *) (actor + 0x40));
  if ((*((s16 *) (actor + 0x7A))) == 9)
  {
    stepSpeed = (f32) (((f64) stepSpeed) * (*((f64 *) D_8011EE68)));
    heading = heading + 1024.0f;
    setActorCommandState(actor, 0x1A2);
  }
  else
    if ((*((s16 *) (actor + 0x7A))) == 10)
  {
    stepSpeed = (f32) (((f64) stepSpeed) * (*((f64 *) D_8011EE70)));
    heading = heading - 1024.0f;
    setActorCommandState(actor, 0x1A8);
  }
  else
  {
    setActorCommandState(actor, walkAnim);
  }
  *((f32 *) (actor + 0x24)) += stepSpeed * sinAngle(heading);
  *((f32 *) (actor + 0x2C)) += stepSpeed * cosAngle(heading);
  *((f32 *) ((*((u8 **) (actor + 0x68))) + 0x34)) = stepSpeed;
  return absFloat(baseSpeed);
}
