typedef struct Obj {
  char pad0[0x10];
  s32 f10;
  char pad14[0xA];
  u16 f1E;
  s16 f20;
  s16 f22;
  char pad24[2];
  s16 f26;
  s32 f28;
} Obj;
typedef struct Holder {
  char pad0[0x182];
  s8 kind;
  char pad183[0x3D4 - 0x183];
  Obj *slot[10];
} Holder;
void *allocTextNodeObject();
s32 linkNodeAfter(void *, s32);
s32 initObjectFromBankEntry(void *, s32, s32);
extern u16 D_800C7E08[];
typedef struct 
{
  s16 half[4];
} __attribute__((packed, aligned(2))) BorderPositions;
extern BorderPositions D_800D46E4;
extern BorderPositions D_800D46EC;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern s32 gVisibleSaveSlotCount;
extern s32 gTrackMarkerParents;
inline static s32 *inline_fn()
{
  return &gTrackMarkerParents;
}

#define A ((Holder *)menu)
/* Creates the four border corner objects (plus extra decorations for modes 5 and 8), sized by save-slot count. */
void setupBorderObjects(void *menu, s32 mode)
{
  struct 
  {
    BorderPositions x;
    BorderPositions y;
  } positions;
  s32 modeSaved;
  s32 kind;
  s8 *var_s3;
  u32 var_a0;
  s32 halfHeight;
  s32 halfWidth;
  s32 var_v1;
  s32 var_s1_3;
  void *var_s0_2;
  u16 *var_s4;
  s32 *marker;
  long var_s1_2;
  u32 var_s2;
  u32 var_s2_2;
  void *temp_a0;
  void *temp_a0_2;
  void *temp_s0;
  void *temp_v0;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *var_s0;
  void *var_s1;
  u32 i;
  modeSaved = mode;
  positions.x = D_800D46E4;
  positions.y = D_800D46EC;
  halfWidth = 0xA0;
  halfHeight = 0x78;
  kind = (s32) (*((s8 *) (((char *) menu) + 0x182)));
  if (gBorderSkipActive == 0)
  {
    goto full_size;
  }
  switch (gVisibleSaveSlotCount)
  {
    case 2:
      switch (gBorderFlipFlag)
    {
      case 1:
      {
        halfWidth = 0x50;
      }
        break;

      default:
      {
        do
        {
          halfHeight = 0x3C;
        }
        while (0);
      }
        break;

    }

      break;

    case 3:

    case 4:
      halfWidth = 0x50;
      halfHeight = 0x3C;
      break;

  }

  full_size:
  i = 0;
  {
    s32 *base = inline_fn();
    s32 offset = kind * 4;
    s16 width;
    s16 height;
    marker = (s32 *)(offset + (char *)base);
    var_s4 = D_800C7E08;
    var_s3 = (s8 *)&positions;
    var_s1 = menu;
    width = halfWidth;
    positions.x.half[1] = width;
    positions.x.half[3] = width;
    height = halfHeight;
    positions.y.half[2] = height;
    positions.y.half[3] = height;
  }
  for (; i < 4; i++)
  {
    if (A->slot[i] != NULL || (A->slot[i] = allocTextNodeObject()) != NULL)
    {
      Obj *p = A->slot[i];
      initObjectFromBankEntry(p, modeSaved, 0x2A);
      p->f10 = 0xFF;
      p->f28 = (p->f28 & ~0xFC) | 0x10;
      p->f20 = positions.x.half[i];
      p->f22 = positions.y.half[i];
      p->f26 = halfWidth;
      *((s8 *)p + 0x29) = halfHeight;
      linkNodeAfter(p, *marker);
      p->f1E = D_800C7E08[i];
    }
  }
  if (gBorderSkipActive == 0)
  {
    if (modeSaved == 5)
    {
      for (i = 0; i < 6; i++)
      {
        if (A->slot[4 + i] == NULL)
        {
          A->slot[4 + i] = allocTextNodeObject();
        }
        A->slot[4 + i]->f10 = 0xFF008F;
        A->slot[4 + i]->f28 = (A->slot[4 + i]->f28 & ~0xFC) | 0x10;
        linkNodeAfter(A->slot[4 + i], (&gTrackMarkerParents)[kind]);
        A->slot[4 + i]->f1E = 2;
        switch (i)
        {
          case 0:
          case 1:
            initObjectFromBankEntry(A->slot[4 + i], 0xF, 0x2A);
            if (i == 0)
            {
              A->slot[4]->f20 = 0x50;
            }
            else
            {
              A->slot[4 + i]->f20 = 0xE0;
              A->slot[4 + i]->f1E |= 0x80;
            }
            A->slot[4 + i]->f22 = 0x58;
            break;
          case 2:
          case 3:
            initObjectFromBankEntry(A->slot[4 + i], 0x10, 0x2A);
            if (i == 2)
            {
              A->slot[6]->f20 = 0x58;
            }
            else
            {
              A->slot[4 + i]->f20 = 0xD8;
              A->slot[4 + i]->f1E |= 0x80;
            }
            A->slot[4 + i]->f22 = 0x78;
            break;
          case 4:
            initObjectFromBankEntry(A->slot[4 + i], 0x11, 0x2A);
            A->slot[4 + i]->f20 = 0x80;
            A->slot[4 + i]->f22 = 0x20;
            break;
          case 5:
            initObjectFromBankEntry(A->slot[4 + i], 3, 0x2A);
            A->slot[4 + i]->f20 = 0;
            A->slot[4 + i]->f22 = 0x78;
            *((s8 *)A->slot[4 + i] + 0x29) = 8;
            A->slot[4 + i]->f26 = 0x140;
            A->slot[4 + i]->f10 = 0xFF001F;
            break;
        }
      }
    }
    if (modeSaved == 8)
    {
      for (i = 0; i < 4; i++)
      {
        s32 flags = 0;
        s32 x, y;
        if (A->slot[4 + i] == NULL)
        {
          A->slot[4 + i] = allocTextNodeObject();
        }
        A->slot[4 + i]->f10 = 0xFF7F;
        A->slot[4 + i]->f28 = (A->slot[4 + i]->f28 & ~0xFC) | 0x10;
        linkNodeAfter(A->slot[4 + i], (&gTrackMarkerParents)[kind]);
        if (i < 2)
        {
          x = 0x50;
        }
        else
        {
          x = halfWidth * 2 - 0x70;
          flags = 0x80;
        }
        if (i == 0 || i == 2)
        {
          y = 0x37;
        }
        else
        {
          y = halfHeight * 2 - 0x57;
          flags |= 0x100;
        }
        A->slot[4 + i]->f20 = x;
        A->slot[4 + i]->f22 = y;
        A->slot[4 + i]->f1E = flags | 2;
        initObjectFromBankEntry(A->slot[4 + i], 0x12, 0x2A);
      }
    }
  }
}
