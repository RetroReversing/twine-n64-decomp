s32 setAudioChannelScaledValue();
s8 getSequencePlayerFlagBit();
s32 stepSequenceTracks();
s32 advanceSeqVoicePositions();
s32 func_8008FFF8();
s32 func_8009010C();
s32 func_800902B4();
s32 advanceSequenceTracks();
s32 validateSoundHandle();
extern void *D_800E5AC0;
extern char D_800E5AC4[];
extern u8 gSndChannelStates;
extern char D_800E6A85[];
extern u8 D_800E6A88[];
extern u32 D_800EDA84;
extern u8 gSeqVoiceBank;
extern s8 D_800EDA88;
extern void *D_800EDA8C;
extern s32 gAudioUpdateRate;
extern s32 D_8010A514;
typedef struct 
{
  void *field_0;
  unsigned char pad_4[4];
  int field_8;
} R;
typedef struct 
{
  unsigned char pad[292];
  int value;
} T;
/* Advances each active audio sequence player by one frame: processes tempo events, steps tracks, frees finished nodes, and marks the player stopped when idle. */ void updateSequencePlayers(void)
{
  s32 a;
  s32 fxDone;
  s32 stepDone;
  s32 advanceDone;
  register s32 e;
  s32 f;
  s32 n3;
  s32 n2;
  s32 n1;
  s32 t3;
  s32 t2;
  s32 t1;
  s32 l74;
  s32 e2;
  u32 tickFixed;
  unsigned long h;
  u32 tickWhole;
  u32 playerIdx;
  char *k;
  void **l;
  void *event;
  void *player;
  void *o;
  void *p;
  void *node;
  void *nextNode;
  s32 rv;
  s32 t0;
  if (gAudioUpdateRate != 0)
  {
    playerIdx = 0;
    do
    {
      if (((u8 *) &gSndChannelStates)[playerIdx * 0xFF8] != 0)
      {
        D_800EDA8C = playerIdx * 0xFF8 + D_800E5AC4; D_800EDA84 = playerIdx; rv = getSequencePlayerFlagBit(D_800E6A88[playerIdx * 0xFF8]); player = D_800EDA8C; t0 = *((s32 *) (((char *) player) + 0xF68)); D_800EDA88 = rv;
        if (t0 != 0)
        {
          while ((*((u32 *) (((char *) (*((void **) (((char *) player) + 0xF6C)))) + 0))) != (-1U))
          {
            top: event = *((void **) (((char *) player) + 0xF6C));
            if (((u32) ((*((s32 *) (((char *) player) + 0xF74))) + (*((s32 *) (((char *) player) + 0x120))))) < ((u32) (*((u32 *) (((char *) event) + 0)))))
            {
              break;
            }
            a = *((s32 *) (((char *) event) + 4));
            ((T *) player)->value = a;
            setAudioChannelScaledValue(a, gSeqVoiceBank);
            o = *((void **) (((char *) D_800EDA8C) + 0xF6C));
            *((void **) (((char *) D_800EDA8C) + 0xF6C)) = o + 8;
            player = D_800EDA8C;
          }
        }
        player = D_800EDA8C; rv = ((((u32) ((((T *) player)->value * 0xC00U) / 60)) * (((s32) (gAudioUpdateRate << 16)) / ((s32) D_8010A514))) >> 3); tickFixed = rv * (*((u16 *) (((char *) player) + 0xFC2))); e = *((s32 *) (((char *) player) + 0xF68)); tickWhole = tickFixed >> 24;
        *((s32 *) (((char *) player) + 0x118)) = ((tickFixed >> 7) >> 1) & 0xFFFF;
        *((u32 *) (((char *) player) + 0x11C)) = tickWhole;
        *((s32 *) (((char *) player) + 0x120)) = ((s32) tickWhole) >> 1;
        if (((unsigned) e) != 0)
        {
          event = (*((void **) (((char *) player) + 0x11C)));  h = *((s32 *) (((char *) player) + 0xF70)); t1 = (*((s32 *) (((char *) player) + 0x118))); h += t1; a = (u16) h; t1 = *((s32 *) (((char *) player) + 0xF74)); t1 += (h >> 16) + (u32) event; *((s32 *) (((char *) player) + 0xF74)) = t1; *((s32 *) (((char *) player) + 0xF70)) = a;
        }
        advanceDone = advanceSequenceTracks(); stepDone = stepSequenceTracks();
        func_8009010C();
        func_800902B4();
        advanceSeqVoicePositions();
        fxDone = func_8008FFF8(); node = *((void **) (((char *) D_800EDA8C) + 0xF7C));
        if (node != NULL)
        {
          do
          {
            nextNode = ((R *) node)->field_0;
            if (validateSoundHandle(((R *) node)->field_8) == (-1))
            {
              p = ((R *) node)->field_0;
              if (p != NULL)
              {
                *((void ***) (((char *) p) + 4)) = (void **) (*((void ***) (((char *) node) + 4)));
              }
              l = *((void ***) (((char *) node) + 4));
              if (l != NULL)
              {
                *l = ((R *) node)->field_0;
              }
              else
              {
                *((void **) (((char *) D_800EDA8C) + 0xF7C)) = ((R *) node)->field_0;
              }
              ((R *) node)->field_0 = (void *) D_800E5AC0;
              if (D_800E5AC0 != NULL)
              {
                *((void ***) (((char *) D_800E5AC0) + 4)) = node;
              }
              *((void ***) (((char *) node) + 4)) = NULL; D_800E5AC0 = node;
            }
            node = nextNode;
          }
          while (node != NULL);
        }
        if (((!(advanceDone & 0xFF)) & (!(stepDone & 0xFF))) && (!(fxDone & 0xFF)))
        {
          ((u8 *) &gSndChannelStates)[playerIdx * 0xFF8] = 0;
          D_800E6A85[playerIdx * 0xFF8] = 1;
        }
      }
      playerIdx++;
    }
    while (8U > playerIdx);
  }
}

