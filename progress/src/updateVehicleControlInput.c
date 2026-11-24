inline static s8 __repair_inline(s8 a)
{
  return a;
}

s32 setActorAssetIndex();
s32 setActorCommandState();
s32 func_80002D30();
s32 func_8000A270();
s32 func_8000A894();
void *allocTextNodeObject();
s32 freeMenuItemRecord();
s32 linkNodeAfter();
s32 func_800448A4();
s32 setEffectPairAnimFrames();
s32 clearActorSubstateFields();
s32 clearActorLinkedPairFields();
s32 updateAimReticle();
s32 finishEntityAndUnlink();
s32 updateActorSpeedScale();
s32 cycleTrackMarkerMode();
s32 cycleTrackMarkerModeWithSound();
s32 func_800707B4();
s32 selectNextEnemyDef();
s32 func_80070B40();
s32 cycleSelectedEnemyKind();
s32 getBindingAxisValue();
s32 func_800819EC();
f32 getExclusiveBindingAxisNormalized();
f32 func_800828D0(f32);
typedef struct
{
  u16 flags;
  u8 pad[0xE6];
} EnemyDefRow;
extern EnemyDefRow sEnemyDefTable[];
extern char D_800C46A0[];
extern char D_800C46FC[];
extern char D_800C4738[];
extern u8 gWheelsGrounded;
extern f32 D_800E1A1C;
extern s32 D_801002C0;
extern s32 D_80102ED8;
extern char D_80109688[];
typedef struct 
{
  u8 f0;
  u8 pad[159];
} Slot_80115088;
extern Slot_80115088 gSlotTable[];
extern char D_8011508A[];
extern char D_8011508B[];
extern char D_80115090[];
typedef struct 
{
  f32 v;
} Field_f32;
typedef struct 
{
  s32 v;
} Field_s32;
typedef struct 
{
  s8 v;
} Field_s8;
typedef struct 
{
  u8 v;
} Field_u8;
typedef struct
{
  u8 b0;
  u8 count;
  s8 back;
  u8 pad;
  f32 speed;
} TrackRec;
typedef struct
{
  u8 pad[0x1FC];
  TrackRec rec[8];
} TrackOwner;
/* Per-frame player control update: toggles modes, selects enemy defs/track markers, adjusts speed scale and steering from input bindings. */ void updateVehicleControlInput(void *actor)
{
  u32 var_a0_2;
  s32 var_a1;
  f32 temp_fa0;
  f32 temp_fa0_2;
  f32 temp_fa0_3;
  f32 temp_fa0_4;
  f32 temp_fs0_3;
  f32 temp_fs1;
  f32 temp_fs1_2;
  f32 temp_fs1_3;
  f32 temp_fs3;
  f32 temp_fv0;
  f32 temp_fv0_10;
  f32 temp_fv0_11;
  f32 temp_fv0_12;
  f32 temp_fv0_13;
  f32 temp_fv0_15;
  f32 temp_fv0_17;
  f32 temp_fv0_18;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv0_4;
  f32 temp_fv0_5;
  f32 temp_fv0_6;
  f32 temp_fv0_7;
  f32 temp_fv0_8;
  f32 temp_fv0_9;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 temp_fv1_4;
  f32 temp_fv1_5;
  f32 temp_fv1_6;
  f32 temp_fv1_7;
  f32 temp_fv1_8;
  f32 temp_fv1_9;
  f32 var_fs0;
  f32 var_fs0_3;
  f32 var_fs2;
  f32 var_fv0;
  f32 var_fv0_2;
  f32 var_fv1;
  f32 var_fv1_2;
  f32 var_fv1_3;
  f32 var_fv1_4;
  f32 var_fv1_5;
  f32 var_fv1_6;
  f32 var_fv1_7;
  f32 var_fv1_8;
  f32 __repair_phase_var_fv1_8;
  f32 var_fv1_9;
  s16 temp_v0_3;
  s16 temp_v1;
  s16 temp_v1_12;
  s16 temp_v1_8;
  s16 var_a0;
  s16 var_v0;
  s32 temp_a0;
  s32 temp_a0_3;
  s32 temp_a0_4;
  s32 temp_a0_5;
  s32 temp_ft0;
  s32 var_condition_bit;
  s32 var_condition_bit_2;
  s32 var_v0_10;
  s32 var_v0_11;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_5;
  s32 var_v0_6;
  s32 var_v0_7;
  s32 var_v0_8;
  s32 var_v1;
  s32 var_v1_10;
  s32 var_v1_12;
  s32 var_v1_2;
  s32 var_v1_3;
  s32 var_v1_4;
  s32 var_v1_5;
  s32 var_v1_6;
  s32 var_v1_7;
  s32 var_v1_8;
  s32 var_v1_9;
  s32 slot;
  s32 temp_v0_2;
  s8 temp_v1_4;
  s8 temp_v1_5;
  u16 temp_a1_3;
  u16 temp_v1_3;
  u8 temp_v1_10;
  u8 temp_v1_9;
  void *temp_a0_2;
  void *temp_a1;
  void *temp_a1_4;
  void *temp_a2;
  void *temp_s0;
  void *temp_s0_2;
  void *player;
  void *temp_v0;
  void *temp_v0_4;
  void *temp_v0_5;
  void *temp_v1_11;
  void *temp_v1_2;
  void *temp_v1_6;
  void *temp_v1_7;
  player = *((void **) (((char *) actor) + 0x6C));
  temp_v1 = *((s16 *) (((char *) actor) + 0x7C));
  slot = ((Field_s8 *) (((char *) player) + 0x182))->v;
  if (temp_v1 == 2)
  {
    goto active_mode;
  }
  if (temp_v1 == 5)
  {
    active_mode:
    temp_v0 = *((void **) (((char *) actor) + 0x68));

    *((u16 *) (((char *) temp_v0) + 0xC)) |= 1;
    ((Field_f32 *) (((char *) player) + 0x40))->v = 1.0f;
  }
  else
    if ((*((u8 *) (D_8011508A + (slot * 0xA0)))) == 0)
  {
    temp_v1_2 = *((void **) (((char *) actor) + 0x68));
    *((u16 *) (((char *) temp_v1_2) + 0xC)) &= 0xFFFE;
    if (getBindingAxisValue(slot, 0x18) != 0)
    {
      var_v0 = (*((u16 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xC))) | 1;
      *((s16 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xC)) = var_v0;
    }
  }
  else
    if (func_800819EC(slot, 0x18) != 0)
  {
    var_v0 = (*((u16 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xC))) ^ 1;
    *((s16 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xC)) = var_v0;
  }
  temp_a1 = *((void **) (((char *) actor) + 0x68));
  temp_v1_3 = *((u16 *) (((char *) temp_a1) + 0xC));
  temp_a0 = temp_v1_3 & 1;
  if (temp_a0 != ((temp_v1_3 >> 1) & 1))
  {
    *((u16 *) (((char *) temp_a1) + 0xC)) = (u16) (temp_v1_3 ^ 2);
    if (temp_a0 != 0)
    {
      updateActorSpeedScale(actor);
      ((Field_s8 *) (((char *) player) + 0x17E))->v = 0;
      clearActorSubstateFields(actor);
      clearActorLinkedPairFields(actor);
      if ((*((s16 *) (((char *) actor) + 0x7C))) == 0)
      {
        setActorCommandState(actor, 0x159);
      }
    }
    else
    {
      finishEntityAndUnlink(actor);
    }
  }
  if (func_800819EC(slot, 0x10) != 0)
  {
    if ((*((s16 *) (((char *) (*((void **) (((char *) player) + 0xA8)))) + 0x7A))) == 0)
    {
      temp_a2 = *((void **) (((char *) actor) + 0x68));
      temp_v0_2 = *((s8 *) (((char *) temp_a2) + 0xE));
      temp_v1_4 = *((s8 *) (D_800C46A0 + (temp_v0_2 * 0xE8)));
      if (temp_v1_4)
      {
        *((s8 *) (((char *) temp_a2) + 0xE)) += temp_v1_4;
        temp_v1_5 = *((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE));
        var_a0 = 0;
        if (!(sEnemyDefTable[temp_v1_5].flags & 0x8000))
        {
          do
          {
            var_a0 += 1;
          }
          while (!(sEnemyDefTable[temp_v1_5 - var_a0].flags & 0x8000));
        }
        ((TrackOwner *) player)->rec[(*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) - var_a0].back = (s8) var_a0;
        setActorAssetIndex(actor, *((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE)));
        setEffectPairAnimFrames(actor);
        temp_v1_6 = *((void **) (((char *) actor) + 0x68));
        *((u8 *) (((char *) temp_v1_6) + 0xF)) = (u8) (*((s8 *) (((char *) temp_v1_6) + 0xE)));
        temp_a1_3 = *((u16 *) (D_800C4738 + ((*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) * 0xE8)));
        if (temp_a1_3 != 0)
        {
          func_80002D30(*((void **) (((char *) player) + 0xA8)), temp_a1_3);
          *((s16 *) (((char *) (*((void **) (((char *) player) + 0xA8)))) + 0x7A)) = 6;
        }
        updateActorSpeedScale(actor);
        if ((*((s32 *) (D_800C46FC + ((*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) * 0xE8)))) & 4)
        {
          func_8000A894(0x1DF);
        }
        if (((u32) (((u8) (*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE)))) - 4)) >= 2U)
        {
          func_8000A894(0x11D);
        }
      }
      else
      {
        temp_a1_4 = (temp_v0_2 * 0xE8) + ((char *) sEnemyDefTable);
        if ((*((u8 *) (((char *) temp_a1_4) + 0x2A))) != 1)
        {
          temp_v1_7 = player + (temp_v0_2 * 8);
          *((u8 *) (((char *) temp_v1_7) + 0x1FD)) += 1;
          temp_a0_2 = player + ((*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE))) * 8);
          if ((*((u8 *) (((char *) temp_a0_2) + 0x1FD))) == (*((u8 *) (((char *) temp_a1_4) + 0x2A))))
          {
            *((u8 *) (((char *) temp_a0_2) + 0x1FD)) = 0U;
          }
          func_8000A894(0x11D);
        }
      }
    }
  }
  if ((func_800707B4(player, 0x15, 1) << 0x18) != 0)
  {
    if (func_800819EC(slot, 0x11) != 0)
    {
      cycleTrackMarkerMode(player);
    }
  }
  else
    if (((func_800707B4(player, 0x1B, 1) << 0x18) != 0) && (func_800819EC(slot, 0x11) != 0))
  {
    cycleTrackMarkerModeWithSound(player);
  }
  temp_v1_8 = *((s16 *) (((char *) actor) + 0x7C));
  if (temp_v1_8 != 5)
  {
    if (temp_v1_8 != 7)
    {
      if (func_800819EC(slot, 0xF) != 0)
      {
        func_80070B40(actor);
      }
      if (func_800819EC(slot, 0x14) != 0)
      {
        selectNextEnemyDef(actor, 0);
      }
      if (func_800819EC(slot, 0x13) != 0)
      {
        cycleSelectedEnemyKind(actor);
      }
    }
  }
  temp_fs3 = ((Field_f32 *) (((char *) player) + 0x3C))->v;
  var_fs0 = 0.0f;
  if ((*((u16 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xC))) & 1)
  {
    temp_v0_3 = *((s16 *) (((char *) actor) + 0x7C));
    do
    {
    if ((temp_v0_3 != 2) & (temp_v0_3 != 5))
    {
      var_fs0 = getExclusiveBindingAxisNormalized(slot, 0x19, 0x1A);
    }
    }
    while (0);
  }
  temp_fs1 = var_fs0;
  if (temp_fs1 != 0.0f)
  {
    var_fs2 = 1.05f;
    if (temp_fs1 > 0.0f)
    {
      var_fs2 = 0.952381f;
    }
    ((Field_f32 *) (((char *) player) + 0x40))->v = (f32) (((Field_f32 *) (((char *) player) + 0x40))->v * var_fs2);
  }
  else
  {
    var_fs0 = ((Field_f32 *) (((char *) player) + 0x3C))->v - ((Field_f32 *) (((char *) player) + 0x40))->v;
    var_fs2 = 1.3f;
    if (var_fs0 > 0.0f)
    {
      var_fs2 = 0.7692308f;
    }
    temp_a0_3 = ((Field_s32 *) (((char *) player) + 0xC))->v;
    if (temp_a0_3 != (-1))
    {
      func_8000A270(temp_a0_3);
      ((Field_s32 *) (((char *) player) + 0xC))->v = -1;
    }
  }
  if (((Field_f32 *) (((char *) player) + 0x40))->v > ((Field_f32 *) (((char *) player) + 0x44))->v)
  {
    ((Field_f32 *) (((char *) player) + 0x40))->v = ((Field_f32 *) (((char *) player) + 0x44))->v;
  }
  temp_fv0 = ((Field_f32 *) (((char *) player) + 0x40))->v;
  if (temp_fv0 < 1.0f)
  {
    ((Field_f32 *) (((char *) player) + 0x40))->v = 1.0f;
  }
  else if (temp_fv0 > 10.0f)
  {
    ((Field_f32 *) (((char *) player) + 0x40))->v = 10.0f;
  }
  if (var_fs0 != 0.0f)
  {
    temp_fv1 = ((Field_f32 *) (((char *) player) + 0x3C))->v * var_fs2;
    ((Field_f32 *) (((char *) player) + 0x3C))->v = temp_fv1;
    if (var_fs0 < 0.0f)
    {
      if (((Field_f32 *) (((char *) player) + 0x40))->v < temp_fv1)
      {
        ((Field_f32 *) (((char *) player) + 0x3C))->v = ((Field_f32 *) (((char *) player) + 0x40))->v;
      }
    }
    else
    {
      if (temp_fv1 < ((Field_f32 *) (((char *) player) + 0x40))->v)
      {
        ((Field_f32 *) (((char *) player) + 0x3C))->v = ((Field_f32 *) (((char *) player) + 0x40))->v;
      }
    }
  }
  if (temp_fs1 != 0.0f)
  {
    ((Field_f32 *) (((char *) player) + 0x40))->v = (f32) ((Field_f32 *) (((char *) player) + 0x3C))->v;
    ((TrackOwner *) player)->rec[(*((s8 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xE)))].speed = (f32) ((Field_f32 *) (((char *) player) + 0x3C))->v;
    if (((Field_f32 *) (((char *) player) + 0x3C))->v != temp_fs3)
    {
      if (func_800819EC(slot, 0x19) != 0)
      {
        temp_a0_4 = ((Field_s32 *) (((char *) player) + 0xC))->v;
        if (temp_a0_4 == (-1))
        {
          var_a0_2 = 0x127;
        }
        else
        {
          func_8000A270(temp_a0_4);
          var_a0_2 = 0x127;
        }
        ((Field_s32 *) (((char *) player) + 0xC))->v = func_8000A894(var_a0_2);
      }
      else
        if (func_800819EC(slot, 0x1A) != 0)
      {
        temp_a0_5 = ((Field_s32 *) (((char *) player) + 0xC))->v;
        if (temp_a0_5 != (-1))
        {
          func_8000A270(temp_a0_5);
        }
        var_a0_2 = 0x128;
        ((Field_s32 *) (((char *) player) + 0xC))->v = func_8000A894(var_a0_2);
      }
    }
  }
  if (!((*((u16 *) (((char *) (*((void **) (((char *) actor) + 0x68)))) + 0xC))) & 1))
  {
    if ((*((u8 *) (D_80115090 + (slot * 0xA0)))) != 0)
    {
      if (((*((void **) (((char *) player) + 0x410))) != NULL) || ((temp_v0_4 = allocTextNodeObject(), *((void **) (((char *) player) + 0x410)) = temp_v0_4, linkNodeAfter(temp_v0_4, *((s32 *) (D_80109688 + (slot * 4)))), (*((void **) (((char *) player) + 0x410))) != NULL)))
      {
        temp_v1_9 = ((Field_u8 *) (((char *) player) + 0x185))->v;
        temp_s0 = *((void **) (((char *) player) + 0x410));
        if (temp_v1_9 == 1) { *((s32 *) (((char *) temp_s0) + 0x10)) = 0x3FFF3FFF; *((s32 *) (((char *) temp_s0) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_s0) + 0x28))) & (~0xFC)) | 0x10); } else if (temp_v1_9 == 2) { *((s32 *) (((char *) temp_s0) + 0x10)) = 0x3F3FFFFF; *((s32 *) (((char *) temp_s0) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_s0) + 0x28))) & (~0xFC)) | 0x10); } else { *((s32 *) (((char *) temp_s0) + 0x10)) = 0xFF0000FF; *((s32 *) (((char *) temp_s0) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_s0) + 0x28))) & (~0xFC)) | 0x10); }
        var_a1 = 0x1F;
        func_800448A4(temp_s0, var_a1, 0x1B);
        *((s16 *) (((char *) temp_s0) + 0x1E)) = 6;
      }
    }
    else
    {
      freeMenuItemRecord(*((void **) (((char *) player) + 0x410)));
      *((void **) (((char *) player) + 0x410)) = NULL;
    }
  }
  else
    if (((*((void **) (((char *) player) + 0x410))) != NULL) || ((temp_v0_5 = allocTextNodeObject(), *((void **) (((char *) player) + 0x410)) = temp_v0_5, linkNodeAfter(temp_v0_5, *((s32 *) (D_80109688 + (slot * 4)))), (*((void **) (((char *) player) + 0x410))) != NULL)))
  {
    temp_v1_10 = ((Field_u8 *) (((char *) player) + 0x185))->v;
    temp_s0_2 = *((void **) (((char *) player) + 0x410));
    if (temp_v1_10 == 1) { *((s32 *) (((char *) temp_s0_2) + 0x10)) = 0x3FFF3FFF; *((s32 *) (((char *) temp_s0_2) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_s0_2) + 0x28))) & (~0xFC)) | 0x10); } else if (temp_v1_10 == 2) { *((s32 *) (((char *) temp_s0_2) + 0x10)) = 0x3F3FFFFF; *((s32 *) (((char *) temp_s0_2) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_s0_2) + 0x28))) & (~0xFC)) | 0x10); } else { *((s32 *) (((char *) temp_s0_2) + 0x10)) = 0xFF0000FF; *((s32 *) (((char *) temp_s0_2) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_s0_2) + 0x28))) & (~0xFC)) | 0x10); }
    var_a1 = 0x18;
    if ((D_80102ED8 != 0) && (D_801002C0 >= 2))
    {
      var_a1 = 0x2A;
    }
    func_800448A4(temp_s0_2, var_a1, 0x1B);
    *((s16 *) (((char *) temp_s0_2) + 0x1E)) = 6;
  }
  temp_v1_11 = *((void **) (((char *) actor) + 0x68));
  if ((*((u16 *) (((char *) temp_v1_11) + 0xC))) & 1)
  {
    *((s32 *) (((char *) temp_v1_11) + 0x34)) = 0;
    var_fs0_3 = getExclusiveBindingAxisNormalized(slot, 6, 7);
    temp_fs1 = getExclusiveBindingAxisNormalized(slot, 8, 9);
    if (gSlotTable[slot].f0 != 0)
    {
      temp_fs1 = -temp_fs1;
    }
    var_fs0_3 = var_fs0_3 * 0.5625f;
    var_v0_2 = 1;
    temp_fs1_2 = temp_fs1 * 0.6666667f;
    if (!(var_fs0_3 <= 0.0002f))
    {
      var_v0_2 = 0;
    }
    var_v1_3 = 1;
    if (!(var_fs0_3 >= (-0.0002f)))
    {
      var_v1_3 = 0;
    }
    if (var_v0_2 & var_v1_3)
    {
      temp_fv0_3 = ((Field_f32 *) (((char *) player) + 0x1C))->v;
      temp_fa0 = (var_fs0_3 - temp_fv0_3) + temp_fv0_3;
      ((Field_f32 *) (((char *) player) + 0x1C))->v = temp_fa0;
      if (func_800828D0(temp_fa0) < 0.01f)
      {
        ((Field_f32 *) (((char *) player) + 0x1C))->v = 0.0f;
      }
    }
    else
    {
      temp_fv0_4 = ((Field_f32 *) (((char *) player) + 0x1C))->v;
      ((Field_f32 *) (((char *) player) + 0x1C))->v = (f32) (((var_fs0_3 - temp_fv0_4) * 0.5f) + temp_fv0_4);
    }
    temp_fv0_5 = ((Field_f32 *) (((char *) player) + 0x1C))->v;
    if (temp_fv0_5 < -0.5625f)
    {
      ((Field_f32 *) (((char *) player) + 0x1C))->v = -0.5625f;
    }
    else if (temp_fv0_5 > 0.5625f)
    {
      ((Field_f32 *) (((char *) player) + 0x1C))->v = 0.5625f;
    }
    if ((temp_fs1_2 <= 0.0002f) & (temp_fs1_2 >= (-0.0002f)))
    {
      temp_fv0_6 = ((Field_f32 *) (((char *) player) + 0x20))->v;
      temp_fa0_2 = (temp_fs1_2 - temp_fv0_6) + temp_fv0_6;
      ((Field_f32 *) (((char *) player) + 0x20))->v = temp_fa0_2;
      if (func_800828D0(temp_fa0_2) < 0.01f)
      {
        ((Field_f32 *) (((char *) player) + 0x20))->v = 0.0f;
      }
    }
    else
    {
      temp_fv0_7 = ((Field_f32 *) (((char *) player) + 0x20))->v;
      ((Field_f32 *) (((char *) player) + 0x20))->v = (f32) (((temp_fs1_2 - temp_fv0_7) * 0.5f) + temp_fv0_7);
    }
    temp_fv0_8 = ((Field_f32 *) (((char *) player) + 0x20))->v;
    if (temp_fv0_8 < -0.6666667f)
    {
      ((Field_f32 *) (((char *) player) + 0x20))->v = -0.6666667f;
    }
    else if (temp_fv0_8 > 0.6666667f)
    {
      ((Field_f32 *) (((char *) player) + 0x20))->v = 0.6666667f;
    }
    var_fs0_3 = 0.0f;
    temp_fv1_2 = ((Field_f32 *) (((char *) player) + 0x1C))->v;
    temp_fs1 = 0.0f;
    if (temp_fv1_2 < (-0.37f))
    {
      temp_fs1 = temp_fv1_2 + 0.37f;
    }
    else
      if (temp_fv1_2 > 0.37f)
    {
      temp_fs1 = temp_fv1_2 - 0.37f;
    }
    temp_fv1_3 = ((Field_f32 *) (((char *) player) + 0x20))->v;
    if (temp_fv1_3 < (-0.5f))
    {
      var_fs0_3 = temp_fv1_3 + 0.5f;
    }
    else
      if (temp_fv1_3 > 0.5f)
    {
      var_fs0_3 = temp_fv1_3 - 0.5f;
    }
    temp_fs1 = temp_fs1 * 0.47f;
    var_v0_4 = 1;
    var_fs0_3 = var_fs0_3 * 0.34f;
    if (!(temp_fs1 <= 0.0002f))
    {
      var_v0_4 = 0;
    }
    var_v1_5 = 1;
    if (!(temp_fs1 >= (-0.0002f)))
    {
      var_v1_5 = 0;
    }
    if (var_v0_4 & var_v1_5)
    {
      temp_fv1_4 = ((Field_f32 *) (((char *) player) + 0x2C))->v;
      temp_fa0_3 = ((temp_fs1 - temp_fv1_4) * 0.48f) + temp_fv1_4;
      ((Field_f32 *) (((char *) player) + 0x2C))->v = temp_fa0_3;
      if (func_800828D0(temp_fa0_3) < 0.01f)
      {
        ((Field_f32 *) (((char *) player) + 0x2C))->v = 0.0f;
      }
    }
    else
    {
      temp_fv0_9 = ((Field_f32 *) (((char *) player) + 0x2C))->v;
      ((Field_f32 *) (((char *) player) + 0x2C))->v = (f32) (((temp_fs1 - temp_fv0_9) * 0.08f) + temp_fv0_9);
    }
    temp_fv0_10 = ((Field_f32 *) (((char *) player) + 0x2C))->v;
    if (temp_fv0_10 < -0.47f)
    {
      ((Field_f32 *) (((char *) player) + 0x2C))->v = -0.47f;
    }
    else if (temp_fv0_10 > 0.47f)
    {
      ((Field_f32 *) (((char *) player) + 0x2C))->v = 0.47f;
    }
    temp_fs1 = ((Field_f32 *) (((char *) player) + 0x2C))->v;
    if ((var_fs0_3 <= 0.0002f) & (var_fs0_3 >= (-0.0002f)))
    {
      temp_fv1_5 = ((Field_f32 *) (((char *) player) + 0x30))->v;
      temp_fa0_4 = ((var_fs0_3 - temp_fv1_5) * 0.42000002f) + temp_fv1_5;
      ((Field_f32 *) (((char *) player) + 0x30))->v = temp_fa0_4;
      if (func_800828D0(temp_fa0_4) < 0.01f)
      {
        ((Field_f32 *) (((char *) player) + 0x30))->v = 0.0f;
      }
    }
    else
    {
      temp_fv0_11 = ((Field_f32 *) (((char *) player) + 0x30))->v;
      ((Field_f32 *) (((char *) player) + 0x30))->v = (f32) (((var_fs0_3 - temp_fv0_11) * 0.07f) + temp_fv0_11);
    }
    temp_fv0_12 = ((Field_f32 *) (((char *) player) + 0x30))->v;
    if (temp_fv0_12 < -0.34f)
    {
      ((Field_f32 *) (((char *) player) + 0x30))->v = -0.34f;
    }
    else if (temp_fv0_12 > 0.34f)
    {
      ((Field_f32 *) (((char *) player) + 0x30))->v = 0.34f;
    }
    var_fs0_3 = ((Field_f32 *) (((char *) player) + 0x30))->v;
    temp_fv0_13 = ((Field_f32 *) (((char *) player) + 0x3C))->v;
    temp_fs1_2 = temp_fs1 / temp_fv0_13;
    var_fs0_3 = var_fs0_3 / temp_fv0_13;
    if (!gWheelsGrounded)
    {
      temp_fs1_2 *= 0.4f;
      var_fs0_3 *= 0.7f;
    }
    D_800E1A1C -= temp_fs1_2 * 1024.0f;
    ((Field_f32 *) (((char *) player) + 0x34))->v += var_fs0_3;
  }
  else
  {
    var_fs0_3 = 0.0f;
    if ((*((u8 *) (D_8011508B + (slot * 0xA0)))) != 0)
    {
      var_fs0_3 = getExclusiveBindingAxisNormalized(slot, 8, 9);
      temp_fs1 = (!(var_fs0_3 <= 0.0002f) | !(var_fs0_3 >= (-0.0002f))) ? 0.1f : 0.4f;
      temp_fv1_6 = ((Field_f32 *) (((char *) player) + 0x58))->v;
      temp_fv0_15 = ((var_fs0_3 - temp_fv1_6) * temp_fs1) + temp_fv1_6;
      var_fv1_6 = -1.0f;
      ((Field_f32 *) (((char *) player) + 0x58))->v = temp_fv0_15;
      if ((temp_fv0_15 < (-1.0f)) || ((var_fv1_6 = 1.0f, temp_fv0_15 > 1.0f)))
      {
        ((Field_f32 *) (((char *) player) + 0x58))->v = var_fv1_6;
      }
      var_fs0_3 = ((Field_f32 *) (((char *) player) + 0x58))->v;
      if (!(var_fs0_3 <= 0.0002f) | !(var_fs0_3 >= (-0.0002f)))
      {
        if (gSlotTable[slot].f0 != 0)
        {
          var_fs0_3 = -var_fs0_3;
        }
        var_fs0_3 *= 0.048f;
        if (gWheelsGrounded == 0)
        {
          var_fs0_3 *= 0.6f;
        }
        ((Field_f32 *) (((char *) player) + 0x34))->v += var_fs0_3;
      }
    }
    if (((var_fs0_3 <= 0.0002f) & (var_fs0_3 >= (-0.0002f))) && (((u32) (((u16) (*((s16 *) (((char *) actor) + 0x7C)))) - 4)) >= 2U))
    {
      var_fs0_3 = getExclusiveBindingAxisNormalized(slot, 0xA, 0xB);
      temp_fs1 = (!(var_fs0_3 <= 0.0002f) | !(var_fs0_3 >= (-0.0002f))) ? 0.1f : 0.4f;
      temp_fv1_7 = ((Field_f32 *) (((char *) player) + 0x58))->v;
      temp_fv0_17 = ((var_fs0_3 - temp_fv1_7) * temp_fs1) + temp_fv1_7;
      var_fv1_7 = -1.0f;
      ((Field_f32 *) (((char *) player) + 0x58))->v = temp_fv0_17;
      if ((temp_fv0_17 < (-1.0f)) || ((var_fv1_7 = 1.0f, temp_fv0_17 > 1.0f)))
      {
        ((Field_f32 *) (((char *) player) + 0x58))->v = var_fv1_7;
      }
      var_fs0_3 = ((Field_f32 *) (((char *) player) + 0x58))->v;
      if (!(var_fs0_3 <= 0.0002f) | !(var_fs0_3 >= (-0.0002f)))
      {
        ((Field_s8 *) (((char *) player) + 0x17E))->v = 1;
        if (gSlotTable[slot].f0 != 0)
        {
          var_fs0_3 = -var_fs0_3;
        }
        var_fs0_3 *= 0.04f;
        ((Field_f32 *) (((char *) player) + 0x34))->v += var_fs0_3;
      }
    }
  }
  temp_v1_12 = *((s16 *) (((char *) actor) + 0x7C));
  switch (temp_v1_12)
  {
  default:
    if (((Field_f32 *) (((char *) player) + 0x34))->v < (-1.0f))
    {
      ((Field_f32 *) (((char *) player) + 0x34))->v = -1.0f;
    }
    else
    {
      __repair_phase_var_fv1_8 = 1.0f;
      if (__repair_phase_var_fv1_8 < ((Field_f32 *) (((char *) player) + 0x34))->v)
      {
        ((Field_f32 *) (((char *) player) + 0x34))->v = __repair_phase_var_fv1_8;
      }
    }
    break;
  case 2:
    if ((var_fs0_3 <= 0.0002f) & (var_fs0_3 >= (-0.0002f)))
    {
      temp_fv1_9 = ((Field_f32 *) (((char *) player) + 0x34))->v;
      if (temp_fv1_9 < 0.0f)
      {
        var_fv0_2 = temp_fv1_9 + 0.02f;
        ((Field_f32 *) (((char *) player) + 0x34))->v = var_fv0_2;
        if (var_fv0_2 > 0.0f)
        {
          ((Field_f32 *) (((char *) player) + 0x34))->v = 0.0f;
        }
      }
      else
      {
        var_fv0_2 = temp_fv1_9 - 0.02f;
        ((Field_f32 *) (((char *) player) + 0x34))->v = var_fv0_2;
        if (var_fv0_2 < 0.0f)
        {
          ((Field_f32 *) (((char *) player) + 0x34))->v = 0.0f;
        }
      }
    }
    if (((Field_f32 *) (((char *) player) + 0x34))->v < (-0.3f))
    {
      ((Field_f32 *) (((char *) player) + 0x34))->v = -0.3f;
    }
    else
    {
      var_fv1_8 = 0.3f;
      if (var_fv1_8 < ((Field_f32 *) (((char *) player) + 0x34))->v)
      {
        ((Field_f32 *) (((char *) player) + 0x34))->v = var_fv1_8;
      }
    }
    break;
  case 5:
    temp_ft0 = (s32) (*((f32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) player) + 0xBC)))) + 0x6C)))) + 0x10)));
    temp_fv1_8 = (f32) (((s32) ((((s32) (*((f32 *) (((char *) actor) + 0x40)))) - temp_ft0) << 0x14)) >> 0x14);
    if (temp_fv1_8 < (-358.54425f))
    {
      var_fv0 = ((f32) temp_ft0) - 358.54425f;
      goto block_243;
    }
    if (temp_fv1_8 > 358.54425f)
    {
      var_fv0 = ((f32) temp_ft0) + 358.54425f;
      block_243:
      *((f32 *) (((char *) actor) + 0x40)) = var_fv0;

    }
    temp_fv0_18 = ((Field_f32 *) (((char *) player) + 0x34))->v;
    if (temp_fv0_18 < -0.3f)
    {
      ((Field_f32 *) (((char *) player) + 0x34))->v = -0.3f;
    }
    else if (temp_fv0_18 > 0.3f)
    {
      ((Field_f32 *) (((char *) player) + 0x34))->v = 0.3f;
    }
    D_800E1A1C = 0.0f;
    break;
  }
  updateAimReticle(actor);
}


