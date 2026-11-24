s32 setTransitionStateIfAllowed(u8);
s32 func_800067C8();
s32 runFixedTimestepUpdates();
s32 finishFrameAndSubmitDisplayList();
s32 stopAllAudio();
s32 func_8000CA3C();
s32 initSceneObjects();
s32 enterBonusMenuState();
s32 initSaveMenuForSlot(s32);
s32 getSaveSlotUsableMask(s32);
s32 getSaveSlotField(s32, s32);
s32 commitEntryAndCloseSaveMenu(s32);
s32 loadTrackSceneAssets();
s32 requestSaveMenu(s32);
s32 func_800761B8();
s32 resetDemoAndCommitEntry();
extern u8 gTransitionState;
extern s8 gSkipActorSpawns;
extern u8 gDemoRecordingActive;
extern s32 gFadeCountdown;
extern f32 gFadeStep;
extern u8 gTransitionParam;
extern u8 D_800DC739;
extern s8 gBonusGoalReached;
extern u8 D_801002AE;
extern s32 D_801002B8;
extern s8 gMenuStateIndex;
extern s32 D_80102ED8;
extern u8 D_80102EDD;
extern u8 gNextSceneId;
extern s32 gSceneChangePending;
extern u8 gBonusSequenceReady;
extern void *volatile D_80109688;
#define TRACK_MARKER (*(void **)&D_80109688)
extern s32 D_8010A4E4;
extern s32 gRetraceFrameCount;
typedef struct 
{
  unsigned char pad_0[292];
  float field_124;
  unsigned char pad_128[4];
  float field_12C;
} __repair_record_D_80109688;
/* Per-frame scene transition state machine: fades the screen in/out and advances to the next scene state. */
void updateSceneTransitionState(void)
{
  s32 nextSoundState;
  f32 fade;
  f32 temp_fv1_b;
  f32 var_fv0;
  s32 slotIdx;
  s32 nextState;
  s32 __repair_phase_var_a0;
  u32 scratch[2];
  register u8 var_v0;
  switch (gTransitionState)
  {
    case 0:
      initSaveMenuForSlot(0);
      loadTrackSceneAssets();
      nextState = 0x12;
      *(s32 *)&((__repair_record_D_80109688 *) TRACK_MARKER)->field_12C = 0;
      goto block_63;

    default:
      return;

    case 8:
      gTransitionState = 9;
      gFadeCountdown = gRetraceFrameCount;

    case 9:
      if ((D_801002AE == 0) && ((gRetraceFrameCount - gFadeCountdown) >= 0x1C3))
    {
      var_v0 = 2;
      goto block_9;
    }
      goto block_10;

    case 18:
    {
      __repair_record_D_80109688 *marker = TRACK_MARKER;
      marker->field_12C += 0.06666667f;
      marker = D_80109688;
      if (!(marker->field_12C > 1.0f))
        goto block_10;
      marker->field_12C = 1.0f;
    }
      var_v0 = 1;
      block_9:
    gTransitionState = var_v0;


    case 1:
      block_10:
    nextState = 4;

      if (gSceneChangePending == 0)
    {
      getSaveSlotUsableMask(4);
      if (gDemoRecordingActive || (!D_80102EDD))
      {
        goto block_38;
      }
      if (D_80102ED8 == 0)
      {
        if (getSaveSlotField(0xA3, 0) & 0xFFFF)
        {
          goto block_38;
        }
        block_15:
        requestSaveMenu(0);

        goto block_38;
      }
      else
      {
        volatile s32 *initial = &D_801002B8;
        volatile s32 *slots;
        slotIdx = 0;
        if (((*initial) <= 0) || D_801002AE)
        {
          goto block_38;
        }
        slots = initial;
        do
        {
          unsigned int result = getSaveSlotField(0xA3, slotIdx & 0xFFFF);
          slotIdx++;
          if (!(result & 0xFFFF))
          {
            goto block_15;
          }
        }
        while ((slotIdx < (*slots)) && (((volatile u8 *) slots)[-10] == 0));
      }
      goto block_38;
    }
      goto block_63;

    case 2:

    case 10:
      if (D_801002AE == 0)
    {
      __repair_record_D_80109688 *marker = TRACK_MARKER;
      marker->field_12C = (f32) (marker->field_12C - 0.033333335f);
      marker = D_80109688;
      temp_fv1_b = marker->field_12C;
      gBonusSequenceReady = 0;
      if (temp_fv1_b < 0.0f)
      {
        marker->field_12C = 0.0f;
        stopAllAudio();
        if (gTransitionState != 2)
        {
          nextSoundState = 4;
          if (gTransitionState == 0xA)
          {
            {
              long long phantom_wide = nextSoundState;
            }
            goto block_29;
          }
        }
        else
        {
          nextSoundState = 8;
          block_29:
          commitEntryAndCloseSaveMenu(nextSoundState);

        }
      }
    }
      goto block_37;

    case 3:

    case 11:
      if (!D_801002AE)
    {
      __repair_record_D_80109688 *marker = TRACK_MARKER;
      marker->field_124 = (f32) (marker->field_124 + 0.13333334f);
      marker = D_80109688;
      gBonusSequenceReady = 0;
      if (marker->field_124 > 1.0f)
      {
        marker->field_124 = 1.0f;
        if (gTransitionState != 3)
        {
          nextState = 0xA;
          if (gTransitionState == 0xB)
          {
            gTransitionState = (double) nextState;
          }
        }
        else
        {
          __repair_phase_var_a0 = 2;
          gTransitionState = __repair_phase_var_a0;
        }
      }
    }
      block_37:
    nextState = 4;

      if (gSceneChangePending != 0)
    {
      goto block_63;
    }
      block_38:
    runFixedTimestepUpdates();

      block_39:
    finishFrameAndSubmitDisplayList();

      return;

    case 4:
      func_800067C8();
      if (gNextSceneId == 0x24)
    {
      D_80102EDD = 0;
      D_80102ED8 = 0;
      gMenuStateIndex = 0xC;
    }
    else
    {
      gBonusGoalReached = 0;
      D_80102EDD = 1;
    }
      gTransitionState = 0xF;
      return;

    case 15:
      func_800761B8();
      nextState = 0x12;
      ((__repair_record_D_80109688 *) TRACK_MARKER)->field_12C = 0.0f;
      goto block_63;

    case 5:
      func_800067C8();
      D_8010A4E4 = 1;

    case 6:
      initSceneObjects();
      gTransitionState = 7;
      return;

    case 7:
      runFixedTimestepUpdates();
      finishFrameAndSubmitDisplayList();
      nextState = 4;
      if (gSceneChangePending != 0)
    {
      gSkipActorSpawns = 0;
      goto block_63;
    }
      break;

    case 16:
      func_8000CA3C();
      return;

    case 12:
      gFadeStep = -0.06666667f;
      goto block_52;

    case 13:
      gFadeStep = 0.06666667f;
      block_52:
    gFadeCountdown = 4;

      gTransitionState = 0xE;
      D_800DC739 = gBonusSequenceReady;

    case 14:
    {
      __repair_record_D_80109688 *marker = TRACK_MARKER;
      marker->field_12C = (f32) (marker->field_12C + gFadeStep);
      marker = D_80109688;
      do
    {
      if (((fade = marker->field_12C) <= 0.0f) || (fade >= 1.0f))
      {
        if (fade < 0.0f)
        {
          marker->field_12C = 0.0f;
        }
        else
          if (fade > 1.0f)
        {
          marker->field_12C = 1.0f;
        }
        if ((gFadeCountdown--) <= 0)
        {
          gBonusSequenceReady = D_800DC739;
          setTransitionStateIfAllowed(gTransitionParam);
        }
      }
      goto block_39;
    }
    while (0);

    }

    case 17:
      resetDemoAndCommitEntry();
      return;

    case 19:
      enterBonusMenuState();
      runFixedTimestepUpdates();
      finishFrameAndSubmitDisplayList();
      nextState = 4;
      if (!gSceneChangePending)
    {
      break;
    }
      block_63:
    setTransitionStateIfAllowed(nextState);

      break;

  }

}
