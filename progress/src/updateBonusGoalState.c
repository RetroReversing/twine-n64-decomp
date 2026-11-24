#define ACCUMULATE() do {     i = 0;     if (*(volatile s32 *)&gSaveTotalSlots > 0) do {         BonusObject *object = sBonusObjectTable[(u16)i];         if (object != 0) {             BonusData *data = object->state->data;             totals[data->player] += data->total - data->remaining;         }         i++;     } while ((s32)(u16)i < *(volatile s32 *)&gSaveTotalSlots); } while (0)
#define CHECK_TOTALS() do {     s32 *tp = &gBonusGoalTarget; i = 0;     if (*tp == 0) goto finish;     { s16 *totalPtr = totals; s32 *tq = tp; do { s32 index = (u16)i; i++; if (totalPtr[index] >= *tp) {             gBonusEndDelayFrames = 90;             *((volatile u8 *)tq + 4) = 1;         }     } while ((u16)i < 2); }    goto finish; } while (0)
#define COUNT_FLAGS(value) do {     s32 *np = &gSaveTotalSlots; s32 one = 1; for (i = 0; (s32)(u16)i < *np; ) { s32 index = (u16)i; BonusObject *object = sBonusObjectTable[index]; if (object != 0 && (object->state->data->flag != 0) == (value)) { count++; saved += (s32)index < np[one]; } i++; }    if (saved >= *(volatile s32 *)&gSaveSlotCount) {         selectBonusSurvivorSlot();         if (saved >= *(volatile s32 *)&gSaveSlotCount) goto set_flag;     }     if (count < gSaveTotalSlots - 1) goto finish;     goto set_flag; } while (0)
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
extern u8 gBonusGoalReached;
extern s32 gSaveTotalSlots;
extern s32 gSaveSlotCount;
extern s32 gBonusGoalTarget;
extern s32 gBonusEndDelayFrames;
extern s16 gBonusPlayerScores[];
extern u8 sProbeTimers[][8];
extern s32 timerGetTotalSeconds(void *);
extern void selectBonusSurvivorSlot(void);
inline static u16 inline_fn(short arg0)
{
  return (u16) arg0;
}

/* Evaluates the bonus-scene goal for the current scene type, sets gBonusGoalReached when met, and returns it. */
s32 updateBonusGoalState(void)
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
      if (gBonusGoalTarget == 0)
    {
      gBonusGoalReached = 0;
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
      short slots = gSaveTotalSlots;
      i = 0;
      do
      {
        if (1)
        {
        }
        while (((s32) ((u16) i)) < gSaveTotalSlots)
        {
          BonusObject *object = sBonusObjectTable[inline_fn(i)];
          if (object != 0)
          {
            BonusData *data = object->state->data;
            s32 difference = data->total - data->remaining;
            if (maximum < difference)
            {
 do { maximum = difference; } while (0);
            }
          }
          i++;
        }

      }
      while (0);
      if ((gBonusGoalTarget == 0) || (maximum < gBonusGoalTarget))
      {
        goto finish;
      }
    }

  }

  set_flag:
  gBonusEndDelayFrames = 90;

  gBonusGoalReached = 1;
  finish:
  i = 0;

  do
  {
    gBonusPlayerScores[(u16) i] = totals[(u16) i];
    i++;
  }
  while (((u16) i) < 2);
  return gBonusGoalReached;
}
