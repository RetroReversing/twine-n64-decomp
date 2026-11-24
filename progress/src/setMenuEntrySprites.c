#define SET_COLOR(member, value) sprites->member->color = ((value) & ~0xFF) | ((u8 *)gSaveMenuState)[0x30]
typedef struct MenuSprite22F
{
  char pad[0x10];
  u32 color;
  char pad14[0xC];
  u16 x;
  u16 y;
  u32 unk24;
  u32 highFlags : 24;
  u32 mode : 6;
  u32 lowFlags : 2;
} MenuSprite22F;
typedef struct MenuPair22F
{
  MenuSprite22F *first;
  MenuSprite22F *second;
} MenuPair22F;
typedef struct MenuEntry22F
{
  MenuPair22F *pair;
  u16 x;
  u16 y;
  u8 slot;
} MenuEntry22F;
extern void setMenuMarkersPalette(s32);
extern s32 D_800BD650;
extern s32 D_800BD65C;
extern s32 sMenuItemParamTable;
extern s32 sSaveMenuColorActive;
extern s32 sSaveMenuColorIdle;
extern s32 sSaveSlotTable;
extern u8 gSaveKeyRelaxed[1];
extern void *gSaveMenuState;
/* Positions and colors a menu entry's sprite pair by slot state, then refreshes the menu. */
void setMenuEntrySprites(MenuEntry22F *entry, u8 enabled)
{
  MenuPair22F *sprites;
  s32 *colorSrc;
  if (!entry)
  {
    return;
  }
  sprites = entry->pair;
  if (!sprites)
  {
    return;
  }
  if (sprites->first)
  {
    sprites->first->mode = 1 | ((-(enabled == 0)) & 7); sprites->first->x = entry->x; sprites->first->y = entry->y;
    if (gSaveKeyRelaxed[0])
    {
      switch (entry->slot)
      {
        case 0:
          SET_COLOR(first, D_800BD65C);
          break;

        case 1:
          SET_COLOR(first, D_800BD650);
          break;

        case 255:
          SET_COLOR(first, sSaveMenuColorActive);
          break;

        default:
        {
          s32 index = entry->slot - 1;
          u8 slotUsed = ((u8 *) (&sSaveSlotTable))[index * 24];
          s32 *colorTable = &sMenuItemParamTable;
          MenuSprite22F *sprite = sprites->first;
          colorSrc = (slotUsed) ? (colorTable + 4) : (colorTable + 7);
          sprite->color = ((*colorSrc) & (~0xFF)) | ((u8 *) gSaveMenuState)[0x30];
        }
          break;

      }

    }
    else
    {
      SET_COLOR(first, sSaveMenuColorIdle);
    }
  }
  if (sprites->second)
  {
    sprites->second->mode = 1 | ((-(enabled == 0)) & 7);
    if (gSaveKeyRelaxed[0])
    {
      switch (entry->slot)
      {
        case 0:
          SET_COLOR(second, D_800BD65C);
          break;

        case 1:
          SET_COLOR(second, D_800BD650);
          break;

        case 255:
          SET_COLOR(second, sSaveMenuColorActive);
          break;

        default:
        {
          s32 index = entry->slot - 1;
          u8 slotUsed = ((u8 *) (&sSaveSlotTable))[index * 24];
          s32 *colorTable = &sMenuItemParamTable;
          MenuSprite22F *sprite = sprites->second;
          colorSrc = (slotUsed) ? (colorTable + 4) : (colorTable + 7);
          sprite->color = ((*colorSrc) & (~0xFF)) | ((u8 *) gSaveMenuState)[0x30];
        }
          break;

      }

    }
    else
    {
      SET_COLOR(second, sSaveMenuColorIdle);
    }
    if (entry->slot == 255)
    {
      sprites->second->x = 160;
    }
    else
    {
      sprites->second->x = entry->x + 144;
    }
    sprites->second->y = entry->y;
  }
  setMenuMarkersPalette(1);
}
