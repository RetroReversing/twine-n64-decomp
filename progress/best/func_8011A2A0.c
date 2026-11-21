#define ACCUMULATE() do {     i = 0;     if (*(volatile s32 *)&gSaveTotalSlots > 0) do {         BonusObject *object = sBonusObjectTable[(u16)i];         if (object != 0) {             BonusData *data = object->state->data;             totals[data->player] += data->total - data->remaining;         }         i++;     } while ((s32)(u16)i < *(volatile s32 *)&gSaveTotalSlots); } while (0)
#define CHECK_TOTALS() do {     s32 *tp = &D_801002A8; i = 0;     if (*tp == 0) goto finish;     { s32 *tq = tp; do {         s32 index = (u16)i;         i++;         if (totals[index] >= *tp) {             D_8011F3A8 = 90;             *((volatile u8 *)tq + 4) = 1;         }     } while ((u16)i < 2); }    goto finish; } while (0)
#define COUNT_FLAGS(value) do {     s32 *np = &gSaveTotalSlots; s32 one = 1; for (i = 0; (s32)(u16)i < *np; ) { s32 index = (u16)i; BonusObject *object = sBonusObjectTable[index]; i++; if (object != 0 && (object->state->data->flag != 0) == (value)) { count++; saved += (s32)index < np[one]; } }    if (saved >= *(volatile s32 *)&gSaveSlotCount) {         func_8011A7C8();         if (saved >= *(volatile s32 *)&gSaveSlotCount) goto set_flag;     }     if (count < gSaveTotalSlots - 1) goto finish;     goto set_flag; } while (0)
typedef struct 
{
  u8 pad[12];
  u16 total;
  u16 remaining;
  u8 unused;
  u8 flag;
  u8 player;
} BonusData;
typedef struct 
{
  u8 pad[0xB4];
  BonusData *data;
} BonusState;
typedef struct 
{
  u8 pad[0x6C];
  BonusState *state;
} BonusObject;
extern BonusObject *sBonusObjectTable[];
extern u8 gSceneType;
extern u8 D_801002AC;
extern s32 gSaveTotalSlots;
extern s32 gSaveSlotCount;
extern s32 D_801002A8;
extern s32 D_8011F3A8;
extern s16 D_8011F15C[];
extern u8 sProbeTimers[][8];
extern s32 timerGetTotalSeconds(void *);
extern void func_8011A7C8(void);
s32 func_8011A2A0(void)
{
  s16 totals[2];
  s32 maximum = 0;
  s32 count = 0;
  s32 saved = 0;
  short i = 0;
  volatile s32 *slotPtr;
  volatile s32 *thresholdPtr;
  volatile s32 *countPtr;
  s32 slots;
  s32 threshold;
  do
  {
    totals[(u16) i] = 0;
    i++;
  }
  while (((u16) i) < 2);
  switch (gSceneType)
  {
    case 6:
      if (D_801002A8 == 0)
    {
      D_801002AC = 0;
    }
      i = 0;
      do
    {
      u16 index = (u16) i;
      totals[index] = ((s16) timerGetTotalSeconds(sProbeTimers[index])) / 10;
      i++;
    }
    while (((u16) i) < 2);
      do
    {
      ACCUMULATE();
    }
    while (0);
      CHECK_TOTALS();

    case 7:
      COUNT_FLAGS(0);

    case 1:
      do
    {
      case 2:
        case 3:
        case 5:
        ACCUMULATE();



      CHECK_TOTALS();
    }
    while (0);

    case 8:
      COUNT_FLAGS(1);

    default:
    {
      s32 slots = gSaveTotalSlots;
      i = 0;
      do
      {
        if (1)
        {
        }
        while (((s32) ((u16) i)) < slots)
        {
          BonusObject *object = sBonusObjectTable[(u16) i];
          if (object != 0)
          {
            BonusData *data = object->state->data;
            s32 difference = data->total - data->remaining;
            if (maximum < difference)
            {
              maximum = difference;
            }
          }
          i++;
        }

      }
      while (0);
      if ((D_801002A8 == 0) || (maximum < D_801002A8))
      {
        goto finish;
      }
    }

  }

  set_flag:
  D_8011F3A8 = 90;

  D_801002AC = 1;
  finish:
  i = 0;

  do
  {
    D_8011F15C[(u16) i] = totals[(u16) i];
    i++;
  }
  while (((u16) i) < 2);
  return D_801002AC;
}


