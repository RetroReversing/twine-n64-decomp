typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
} __V3;
void *allocObject();
void func_800169EC(void *, void *);
s32 setObjectAsset(void *, s32, s32);
f32 approximate_hypot2(f32, f32);
f32 approximateAtan2(f32, f32);
/* Spawns an effect object at position, orients it (pitch/yaw) along the direction vector, and attaches it to parent. */ void spawnDirectedEffect(void *parent, s32 *position, const f32 *direction, s32 param)
{
  volatile f32 dirX;
  volatile f32 dirY;
  volatile f32 dirZ;
  void *effect;
  effect = allocObject();
  if (effect != NULL)
  {
    *((s32 *) (((char *) effect) + 0x1C)) = param;
    *((__V3 *) (((s8 *) effect) + 0x20)) = *((__V3 *) position);
    setObjectAsset(effect, 4, 0x1B);
    dirX = *((const f32 *) (((char *) direction) + 0));
    do
    {
 do { dirY = *((const f32 *) (((char *) direction) + 4)); } while (0);
      dirZ = *((const f32 *) (((char *) direction) + 8));
    }
    while (0);
    *((f32 *) (((char *) effect) + 0x2C)) = (f32) (-(approximateAtan2(dirY, approximate_hypot2(direction[0], direction[2])) * 651.8986f));
    *((f32 *) (((char *) effect) + 0x30)) = approximateAtan2(dirX, dirZ) * 651.8986f;
    *((s32 *) (((char *) effect) + 0x34)) = 0;
    func_800169EC(effect, parent);
    func_80085160(position);
  }
}
