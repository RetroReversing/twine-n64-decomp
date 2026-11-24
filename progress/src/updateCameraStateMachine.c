s32 postSubObjectRequest(void *, s8);
volatile int setCameraTargetMode(void *, s8);
s32 func_80002D30(void *, u16);
s32 negateMotionComponent(void *);
s32 updateActorAnimation(void *);
s32 func_8000A270(s32);
s32 func_8000A894(s32);
void *spawnEnemyDefEffect(void *, s32, s8);
s32 transferStockToItem(void *, s32);
s32 updateActorSpeedScale(void *);
s32 resetCameraTargetScale(void *);
s32 func_80067294(void *);
s32 syncCameraTargetMode(void *);
s32 fireTrackedActorShot(void *arg0, void *);
s32 resetEnemyAnimationAndEffects(void *);
s32 getBindingAxisValueAlt(int, s32);
s32 setGridCellFlag(s8, s32);
f32 func_8008292C(f32);
f32 func_80082968(f32);
extern s32 D_800C469C;
extern s32 D_800C46FC;
extern s32 gBorderSkipFlag;
extern s32 gTrackMarkerParents;
/* Runs the per-actor camera state machine, then blends the camera position and adds the given offset. */
void updateCameraStateMachine(void *actor, void *offset)
{
  s32 *__base_D_800C469C;
  struct 
  {
    f32 v[3];
  } camPos;
  f32 temp_fs0;
  f32 temp_fs1;
  f32 temp_fs2;
  f32 temp_ft1;
  f32 temp_ft2;
  f32 temp_fv0;
  f32 temp_fv1;
  s32 state;
  s32 nextState;
  void *stateDest;
  void *entryPtr;
  void *camObj;
  s32 var_v1;
  s32 temp_a0_3;
  u32 borderSkip;
  s32 playerIdx;
  s8 __repair_phase_temp_s0;
  s8 temp_v1_6;
  s8 temp_v1_7;
  u16 temp_a1;
  u16 temp_a1_2;
  u16 temp_a1_3;
  void **temp_s0_2;
  void *temp_a0;
  register void *temp_a0_4;
  void *temp_a0_5;
  void *temp_a0_6;
  void *curEntry;
  void *temp_s1_2;
  void *actorData;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  register void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v1_3;
  register void *temp_v1_4;
  void *temp_v1_5;
  void *activeEntry;
  actorData = *((void **) (((char *) actor) + 0x6C));
  __base_D_800C469C = &D_800C469C;
curEntry = (void*)(((char*)__base_D_800C469C) + (*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) * 0xE8);
  activeEntry = (void *) (((char *) __base_D_800C469C) + (*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x10))) * 0xE8);
  state = *((s16 *) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x7A));
  borderSkip = gBorderSkipFlag != 0;
  playerIdx = *((s8 *) (((char *) actorData) + 0x182));
  switch (state)
  {
    case 0:

    default:
      activeEntry = curEntry;
curEntry = activeEntry;
      if ((*((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x68)))) + 0x14))) & 0x10)
    {
      temp_a0 = *((void **) (((char *) actor) + 0x68));
      __repair_phase_temp_s0 = *((s8 *) (((char *) temp_a0) + 0xE));
      if ((*((s8 *) (((char *) temp_a0) + 0xF))) != __repair_phase_temp_s0)
      {
        *((s8 *) (((char *) temp_a0) + 0x10)) = __repair_phase_temp_s0;
        temp_v1_3 = *((void **) (((char *) actor) + 0x68));
        *((s8 *) (((char *) temp_v1_3) + 0xE)) = (s8) ((u8) (*((s8 *) (((char *) temp_v1_3) + 0xF))));
        temp_a0_3 = *((s32 *) (((char *) actorData) + 8));
        if (temp_a0_3 != (-1))
        {
          func_8000A270(temp_a0_3);
          *((s32 *) (((char *) actorData) + 8)) = -1;
        }
        syncCameraTargetMode(actor);
      }
      activeEntry = curEntry;
    }
      break;

    case 9:
      resetCameraTargetScale(actor);
      activeEntry = curEntry;
      if ((*((s16 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x68)))) + 0x94))) == 0x21)
    {
      fireTrackedActorShot(actor, activeEntry);
    }
      if ((*((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x68)))) + 0x14))) & 0x10)
    {
      if ((transferStockToItem(actor, 1) << 0x18) != 0)
      {
      camObj = *((void **) (((char *) actorData) + 0xA8));
      nextState = 3;
      goto block_48;
      }
      else {
        *((s16 *) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x7A)) = 0;
        func_80067294(actor);
      nextState = 3;
      camObj = *((void **) (((char *) actorData) + 0xA8));
      goto block_48;
      }
    }
      break;

    case 6:

    case 7:
      temp_v1_4 = *((void **) (((char *) actorData) + 0xA8));
      activeEntry = curEntry;
      if ((*((s32 *) (((char *) (*((void **) (((char *) temp_v1_4) + 0x68)))) + 0x14))) & 0x10)
    {
      *((s16 *) (((char *) temp_v1_4) + 0x7A)) = 0;
    }
      break;

    case 5:
      activeEntry = curEntry;
      if (((*((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x68)))) + 0x14))) & 0x10) && ((transferStockToItem(actor, 0), *((s16 *) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x7A)) = 0, getBindingAxisValueAlt(playerIdx, 0xE) != 0)))
    {
      setGridCellFlag(playerIdx, 0xE);
    }
    else
    {
      break;
    }
      break;

    case 1:

    case 10:
      resetCameraTargetScale(actor);
      func_80002D30(*((void **) (((char *) actorData) + 0xA8)), *((u16 *) (((char *) activeEntry) + 0x9A)));
      postSubObjectRequest(actor, *((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x10)));
      temp_a0_4 = *((void **) (((char *) actorData) + 0xA8));
      var_v1 = *((s16 *) (((char *) temp_a0_4) + 0x7A));
      if (var_v1 == 0xA)
    {
      *((s16 *) (((char *) temp_a0_4) + 0x7A)) = 0xB;
      temp_a0_4 = *((void **) (((char *) actorData) + 0xA8));
      var_v1 = *((s16 *) (((char *) temp_a0_4) + 0x7A));
    }
      if (var_v1 == 1)
    {
      *((s16 *) (((char *) temp_a0_4) + 0x7A)) = 2;
      break;
    }
      break;

    case 2:

    case 11:
      temp_v1_5 = *((void **) (((char *) actorData) + 0xA8));
      if ((*((s32 *) (((char *) (*((void **) (((char *) temp_v1_5) + 0x68)))) + 0x14))) & 0x10)
    {
      if ((*((s16 *) (((char *) temp_v1_5) + 0x7A))) == 0xB)
      {
        if (gBorderSkipFlag == 0)
        {
          temp_v0 = spawnEnemyDefEffect(actor, 0, *((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x10)));
          if (temp_v0 != NULL)
          {
            temp_s0_2 = (void **) (((char *) (&gTrackMarkerParents)) + (playerIdx * 4));
            temp_s1_2 = *((void **) (((char *) temp_v0) + 0x6C));
            temp_fs1 = func_8008292C(*((f32 *) (((char *) (*temp_s0_2)) + 0x38)));
            temp_fs2 = func_80082968(*((f32 *) (((char *) (*temp_s0_2)) + 0x38)));
            temp_fs0 = func_8008292C(*((f32 *) (((char *) (*temp_s0_2)) + 0x34)));
            *((f32 *) (((char *) temp_s1_2) + 0xC)) = (f32) (func_80082968(*((f32 *) (((char *) (*temp_s0_2)) + 0x34))) * temp_fs1);
            temp_fv0 = func_80082968(*((f32 *) (((char *) (*temp_s0_2)) + 0x34))) * temp_fs2;
            *((s32 *) (((char *) temp_s1_2) + 0x18)) = 0x96;
            *((s8 *) (((char *) temp_s1_2) + 0x2D)) = 0;
            *((s8 *) (((char *) temp_s1_2) + 0x2F)) = 0;
            *((s16 *) (((char *) temp_s1_2) + 0x30)) = 0x384;
            *((f32 *) (((char *) temp_s1_2) + 0x10)) = (f32) (-temp_fs0);
            *((f32 *) (((char *) temp_s1_2) + 0x14)) = temp_fv0;
          }
          *((s8 *) (((char *) (actorData - (-((*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x10))) * 8)))) + 0x1FC)) = 0;
        }
        else
          if ((*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x10))) == 0x1B)
        {
          *((s8 *) (((char *) actorData) + 0x2D4)) = 0;
        }
      }
      *((s16 *) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x7A)) = 3;
    }
      temp_a0_5 = *((void **) (((char *) actor) + 0x68));
      temp_v1_6 = *((s8 *) (((char *) temp_a0_5) + 0xF));
      if (temp_v1_6 != (*((s8 *) (((char *) temp_a0_5) + 0xE))))
    {
      *((s8 *) (((char *) temp_a0_5) + 0xE)) = temp_v1_6;
    }
      break;

    case 3:
      resetEnemyAnimationAndEffects(actor);
      activeEntry = curEntry;
      setCameraTargetMode(actor, *((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE)));
      do
    {
      temp_a1 = *((u16 *) (((char *) activeEntry) + 0x98));
      if (temp_a1 != 0)
      {
        do
        {
          func_80002D30(*((void **) (((char *) actorData) + 0xA8)), temp_a1);
        }
        while (0);
        camObj = *((void **) (((char *) actorData) + 0xA8));
        nextState = 4;
        goto block_48;
      }
      temp_a1_2 = *((u16 *) (((char *) activeEntry) + 0x92));
      if (temp_a1_2 != 0)
      {
        func_80002D30(*((void **) (((char *) actorData) + 0xA8)), temp_a1_2);
        nextState = 4;
        camObj = *((void **) (((char *) actorData) + 0xA8));
        goto block_48;
      }
    }
    while (0);
      *((s16 *) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x7A)) = 0;
      break;

    case 8:
      activeEntry = curEntry;
      setCameraTargetMode(actor, *((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0x10)));
      if ((*((u16 *) (((char *) activeEntry) + 0x98))) != 0)
    {
      negateMotionComponent(*((void **) (((char *) actorData) + 0xA8)));
      camObj = *((void **) (((char *) actorData) + 0xA8));
      nextState = 2;
      goto block_48;
    }
      temp_a1_3 = *((u16 *) (((char *) activeEntry) + 0x92));
      if (temp_a1_3 != 0)
    {
      func_80002D30(*((void **) (((char *) actorData) + 0xA8)), temp_a1_3);
      nextState = 2;
      camObj = *((void **) (((char *) actorData) + 0xA8));
      goto block_48;
    }
      *((s16 *) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x7A)) = 0;
      break;
      break;

    case 4:
      activeEntry = curEntry;
      if ((*((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x68)))) + 0x14))) & 0x10)
    {
      if ((*((s32 *) (((s8 *) (&D_800C46FC)) + ((*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) * 0xE8)))) & 4)
      {
        func_8000A894(0x1DF);
      }
      *((s16 *) (((char *) actorData) + 0x178)) = 0;
      *((s16 *) (((char *) (*((void **) (((char *) actorData) + 0xA8)))) + 0x7A)) = 0;
      updateActorSpeedScale(actor);
    }
      temp_a0_6 = *((void **) (((char *) actor) + 0x68));
      temp_v1_7 = *((s8 *) (((char *) temp_a0_6) + 0xE));
      if ((*((s8 *) (((char *) temp_a0_6) + 0xF))) != temp_v1_7)
    {
      *((s8 *) (((char *) temp_a0_6) + 0x10)) = temp_v1_7;
      camObj = *((void **) (((char *) actorData) + 0xA8));
      nextState = 8;
      goto block_48;
    }
      break;
      block_48:
      *((s16 *) (((char *) camObj) + 0x7A)) = nextState;
  }

  temp_v0_2 = (void *) (((borderSkip * 2 + borderSkip) * 4) + ((s32) activeEntry));
  camPos = *((typeof(camPos) *) (((char *) temp_v0_2) + 0xA0));
  if (borderSkip == 0)
  {
    temp_fv1 = *((f32 *) (((char *) (*((s32 *) (((s8 *) (&gTrackMarkerParents)) + ((*((s8 *) (((char *) actorData) + 0x182))) * 4))))) + 0x130));
    if (temp_fv1 > 0.0f)
    {
      temp_ft2 = temp_fv1 * 2.5f;
      ;
      camPos.v[0] = (camPos.v[0] * (1.0f - temp_ft2)) + ((*((f32 *) (((char *) activeEntry) + 0xAC))) * temp_ft2);
      camPos.v[1] = (camPos.v[1] * (1.0f - temp_ft2)) + ((*((f32 *) (((char *) activeEntry) + 0xB0))) * temp_ft2);
      camPos.v[2] = (camPos.v[2] * (1.0f - temp_ft2)) + ((*((f32 *) (((char *) activeEntry) + 0xB4))) * temp_ft2);
    }
  }
  temp_v0_3 = *((void **) (((char *) actorData) + 0xA8));
  *((typeof(camPos) *) (((char *) temp_v0_3) + 0x24)) = camPos;
  temp_v0_4 = *((void **) (((char *) actorData) + 0xA8));
  *((f32 *) (((char *) temp_v0_4) + 0x24)) = (f32) ((*((f32 *) (((char *) temp_v0_4) + 0x24))) + (*((f32 *) (((char *) offset) + 0))));
  temp_v0_5 = *((void **) (((char *) actorData) + 0xA8));
  *((f32 *) (((char *) temp_v0_5) + 0x28)) = (f32) ((*((f32 *) (((char *) temp_v0_5) + 0x28))) + (*((f32 *) (((char *) offset) + 4))));
  temp_v0_6 = *((void **) (((char *) actorData) + 0xA8));
  *((f32 *) (((char *) temp_v0_6) + 0x2C)) = (f32) ((*((f32 *) (((char *) temp_v0_6) + 0x2C))) + (*((f32 *) (((char *) offset) + 8))));
  updateActorAnimation(*((void **) (((char *) actorData) + 0xA8)));
}
