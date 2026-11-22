#define MODEL (*(BeamModel **)(actor+0x68))
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} BeamPoint;
typedef struct 
{
  BeamPoint *points;
  char pad[4];
  f32 height;
  u8 gap[0xA6];
  u8 type;
  s8 count;
} BeamModel;
typedef struct 
{
  s8 enabled;
  s8 end;
  s16 pad;
  s32 resource;
} BeamLink;
extern BeamLink D_800B25C0[];
extern f32 D_80112F98_unused;
extern s16 D_800C392A[][4];
extern u32 *D_8010A928;
extern u32 D_80107EA0;
extern u32 D_800B1D84;
extern s32 D_8010A924;
extern s32 D_801032A0;
extern s32 D_8010D538;
extern char D_800B1D48[];
extern char D_800B1B68[];
extern char *D_80117728;
extern f32 D_800AE4D8;
extern f32 D_80112F90;
extern f32 D_80112FA0;
extern f32 D_80112FB0;
extern f32 D_80112F98;
extern f32 D_80112FA8;
extern f32 D_80112FB8;
extern u8 D_800C2B40;
extern f32 func_80082A70(f32, f32);
extern f32 func_80046140(f32, f32);
extern f32 func_8008292C(f32);
extern f32 func_80082968(f32);
extern void func_8000BB50(void *, f32, f32, f32, f32);
extern void func_800A37C0(void *, s32);
extern void func_80043FA0(void *);
extern u8 *func_80044818(s32, s32);
inline static int inline_fn(s32 arg0, s32 arg1)
{
  return arg0 < arg1;
}

void func_8000C34C(char *actor, char *viewer)
{
  BeamPoint points[49];
  volatile BeamPoint *p;
  BeamPoint *end;
  volatile BeamPoint *out;
  BeamLink *link;
  s32 pointOffset;
  s32 linkOffset;
  char *base;
  register BeamModel *model;
  f32 h;
  f32 sn;
  f32 cs;
  f32 angle;
  f32 yaw;
  f32 dx;
  f32 dz;
  f32 scale;
  f32 x;
  f32 y;
  f32 z;
  f32 m0;
  f32 m1;
  f32 m2;
  f32 m3;
  f32 m4;
  f32 m5;
  f32 *matrix;
  s32 count;
  s32 i;
  short mode;
  register u32 *cmd;
  u32 used;
  u32 address;
  u8 *resource;
  u32 *modeCmd;
  u32 *stateCmd;
  u32 *displayCmd;
  char *view = viewer;
  model = MODEL;
  if (D_800C392A[model->type][0] == 0)
  {
    count = model->count;
    mode = 15;
    if (!(((*((u32 *) ((*((char **) (actor + 0x20))) + 0x58))) >> 2) & 0x200))
    {
      mode = 14;
      if (D_8010A924 != mode)
      {
        modeCmd = D_8010A928;
        D_8010A924 = mode;
        D_8010A928 = modeCmd + 2;
        modeCmd[0] = 0xDE000000;
        modeCmd[1] = (u32) D_800B1D48;
      }
      h = MODEL->height;
    }
    else
    {
      if (D_8010A924 != ((int) mode))
      {
        modeCmd = D_8010A928;
        D_8010A924 = mode;
        D_8010A928 = modeCmd + 2;
        modeCmd[0] = 0xDE000000;
        modeCmd[1] = (u32) D_800B1B68;
      }
      h = MODEL->height + 0.01f;
    }
    if (D_801032A0 != 7)
    {
      stateCmd = D_8010A928;
      D_801032A0 = 7;
      D_8010A928 = stateCmd + 2;
      stateCmd[0] = 0xFCFF97FF;
      stateCmd[1] = 0xFFFDFE38;
    }
    if (view)
    {
      angle = func_80082A70((*((f32 *) (actor + 0x24))) - (*((f32 *) (view + 4))), (*((f32 *) (actor + 0x2C))) - (*((f32 *) (view + 0xC))));
      sn = func_8008292C(angle);
      cs = func_80082968(angle);
    }
    else
    {
      sn = 1.0f;
      cs = 0.0f;
    }
    i = 0;
    if (inline_fn(0, count))
    {
      out = points;
      pointOffset = 0;
      do
      {
        x = (*((BeamPoint *) (pointOffset + ((char *) MODEL->points)))).x;
        out->y = h;
        out->x = x;
        out->z = (*((BeamPoint *) (pointOffset + ((char *) MODEL->points)))).z;
        model = MODEL;
        out->x += sn * (((*((BeamPoint *) (pointOffset + ((char *) model->points)))).y - D_800AE4D8) - model->height);
        model = (unsigned) MODEL;
        out->z += cs * (((*((BeamPoint *) (pointOffset + ((char *) model->points)))).y - D_800AE4D8) - model->height);
        pointOffset += 12;
        ++i;
        out++;
      }
      while (inline_fn(i, count));
    }
    i = 1;
    base = (char *) points;
    if (inline_fn(i, count))
    {
      f32 unit = 64.0f;
      p = points + 1;
      matrix = &D_80112F90;
      linkOffset = 8;
      do
      {
        if ((*((s8 *) (((char *) D_800B25C0) + linkOffset))) == (-1))
        {
          goto advance;
        }
        link = (BeamLink *) (((char *) D_800B25C0) + linkOffset);
        resource = func_80044818(link->resource, 0x2A);
        end = (BeamPoint *) (base + (link->end * 12));
        dx = end->x - p->x;
        dz = end->z - p->z;
        scale = func_80046140(dx, dz);
        yaw = func_80082A70(dx, dz);
        used = D_80107EA0;
        if (used >= D_800B1D84)
        {
          goto advance;
        }
        x = p->x * unit;
        y = p->y * unit;
        z = p->z * unit;
        address = *((u32 *) (D_80117728 + 0x74C));
        D_80107EA0 = used + 1;
        D_8010D538 = address + (((used + 1) << 1) << 5);
        func_8000BB50(matrix, x, y, z, yaw);
        m0 = (*matrix) * scale;
        m1 = D_80112FA0 * scale;
        m2 = D_80112FB0 * scale;
        m3 = D_80112F98 * scale;
        m4 = D_80112FA8 * scale;
        m5 = D_80112FB8 * scale;
        *matrix = m0;
        D_80112FA0 = m1;
        D_80112FB0 = m2;
        D_80112F98 = m3;
        D_80112FA8 = m4;
        D_80112FB8 = m5;
        func_800A37C0(matrix, D_8010D538);
        cmd = D_8010A928;
        address = D_8010D538;
        D_8010A928 = cmd + 2;
        cmd[0] = 0xDA380003;
        cmd[1] = address - 0x80000000u;
        mode = (((*((u8 *) (actor + 0x82))) * 2) / 3) & 0xFF;
        cmd[2] = 0xFA000000;
        cmd[3] = mode;
        address = *((u32 *) resource);
        D_8010A928 = cmd + 4;
        if (!address)
        {
          func_80043FA0(resource);
          if ((*((u32 *) resource)) == 0)
          {
            goto advance;
          }
        }
        if (!(resource[0x46] & 0x80))
        {
          resource[0x46] = D_800C2B40;
        }
        displayCmd = D_8010A928;
        displayCmd[0] = 0xDE000000;
        address = *((u32 *) resource);
        D_8010A928 = displayCmd + 2;
        displayCmd[1] = address;
        advance:
        ++p;

        i += 1;
        linkOffset += 8;
      }
      while (inline_fn(i, count));
    }
  }
}

