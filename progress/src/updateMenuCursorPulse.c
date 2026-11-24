typedef struct 
{
  u8 pad[16];
  u32 color;
} DisplayItem;
typedef struct 
{
  u16 tick;
  u16 alpha;
} Pulse;
typedef struct 
{
  u8 pad[0x7A];
  u16 value;
} MenuData;
typedef struct 
{
  u8 pad[12];
  void *display;
} MenuObject;
DisplayItem *setMenuLabel(s32, s32, s16, u8);
void setSaveMenuPage(s32, u32, u16);
s32 func_80027CE0(s32);
void func_8002B050(void *, s32);
void initTimer(void *, s32, s8);
void setStateMachineState(void *, s16);
s32 func_80087100(s32);
extern u32 D_800BD640[];
extern u8 D_800BD8C4[];
extern u16 D_800BFC92;
extern u16 sMenuPulseTick;
extern u16 sMenuPulsePhase;
extern DisplayItem * volatile sMenuCursorItem;
extern u8 D_800E1584[];
extern u32 D_80102EBC;
extern u8 D_80102EDC;
extern u8 D_80102EDE;
extern MenuData *D_80102F2C;
extern MenuObject *D_80109BB0;
inline static int inline_fn()
{
  return !D_800BD640;
}

/* Draws the pulsing menu cursor and advances its blink animation; if a blocking state is active, resets the animation and shows the fallback screen. */ void updateMenuCursorPulse(void *unused, void *menuState)
{
  s32 cursorAsset;
  s32 altLayout;
  s32 x;
  s32 y;
  DisplayItem *cursorItem;
  u32 pulsePhase;
  u32 *color;
  u32 *menuColors;
  DisplayItem *cursorNow;
  u32 pulseValue;
  u32 baseColor;
  u32 cur;
  u16 savedTick;
  DisplayItem *cursorItemCopy;
  if (((!((u8) func_80027CE0(0x23))) && (!((u8) func_80027CE0(0x2A)))) && (!D_80102EDE))
  {
    cursorAsset = func_80087100(0x2E9);
    altLayout = D_800BFC92 & 1;
    x = (altLayout) ? (0xA0) : (0xDC);
    y = (altLayout) ? (0xB0) : (0x45);
    cursorItem = setMenuLabel(cursorAsset, 0, x, y);
    sMenuCursorItem = cursorItem;
    pulsePhase = sMenuPulseTick & 63;
    sMenuPulsePhase = pulsePhase;
    if (pulsePhase >= 32)
    {
      sMenuPulsePhase = 63 - pulsePhase;
    }
    cursorItemCopy = cursorItem;
    menuColors = D_800BD640;
    if (D_800BFC92 & 1)
    {
      color = menuColors + 1;
    }
    else
    {
      color = menuColors + 9;
    }
    cursorNow = sMenuCursorItem;
    cursorItemCopy->color = (*color) & (~255);
    baseColor = cursorNow->color & (~255);
    pulseValue = sMenuPulsePhase;
    pulsePhase = baseColor | (pulseValue << 3);
    do {
    savedTick = sMenuPulseTick;
    } while (0);
    *((volatile u32 *) (&cursorNow->color)) = pulsePhase;
    sMenuPulseTick = savedTick + 1;
    if (D_80102EDC)
    {
      func_8002B050(D_800E1584, 1);
    }
  }
  else
  {
    sMenuPulseTick = 0;
    D_80109BB0->display = D_800BD8C4;
    setSaveMenuPage(1, D_80102EBC & (~255), D_80102F2C->value);
    setMenuLabel(func_80087100(3), 0x40, 0xA0, 0xCC);
    initTimer(D_800E1584, 0, 0);
    setStateMachineState(menuState, 4);
  }
}


