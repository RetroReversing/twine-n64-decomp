typedef s32 M2C_UNK;
M2C_UNK setActorCommandState(void *, M2C_UNK);
f32 approxDistanceXZ(void *, void *);
s32 resetActorActionState(void *);
s32 pickWeightedActorAction(void *, M2C_UNK *, M2C_UNK);
M2C_UNK setActorCommandByType(void *);
extern M2C_UNK gActorTypeKindTable;
extern M2C_UNK D_800C9C00;
extern M2C_UNK D_800C9C18;
extern M2C_UNK D_800C9C38;
extern M2C_UNK D_800C9C48;
extern M2C_UNK D_800C9C60;
extern M2C_UNK D_800C9C70;
extern M2C_UNK D_800C9C94;
extern M2C_UNK D_800C9C9C;
extern M2C_UNK D_800C9CA4;
extern M2C_UNK D_800C9CB8;
extern M2C_UNK D_800C9CC0;
extern M2C_UNK D_800C9CC8;
extern M2C_UNK D_800C9CD8;
extern M2C_UNK D_800C9CE0;
extern M2C_UNK D_800C9CE8;
extern M2C_UNK D_800C9CF8;
extern M2C_UNK D_800C9D08;
extern M2C_UNK D_800C9D18;
extern M2C_UNK D_800C9D24;

/* Picks and plays a speech/sound line for an actor based on its state, mode and distance to its target. */ /* Chooses a sound/speech line for the actor from a table keyed by its current mode and proximity to its target (0x6C state, 0x7C mode). */ void actorPlaySpeechLine(void *actor) {
    M2C_UNK *base_table;
    void *line_table;
    s32 line_count;
    f32 dist_to_target;
    void *state;
    s32 target_obj;
    s16 is_near;
    s32 state_id;

    state = *(void **)((s8 *)actor + 0x6C);
    target_obj = *(s32 *)((s8 *)state + 0x40);
    is_near = 0;
    if (target_obj != 0) {
        dist_to_target = approxDistanceXZ((s8 *)actor + 0x24, (s8 *)target_obj + 0x24);
    } else {
        dist_to_target = 0.0f;
    }
    if (dist_to_target < 10.0f) {
        is_near = 1;
    }
    if (*(s32 *)((s8 *)state + 0x88) & 0x04000000) {
        switch (*(s16 *)((s8 *)actor + 0x7C)) {
        case 3:
            if ((pickWeightedActorAction(actor, &D_800C9CC0, 2) << 0x18) == 0) {
                setActorCommandState(actor, 0x14D);
            }
            return;
        case 1:
            line_table = &D_800C9CB8;
            line_count = 2;
            {
    pickWeightedActorAction(actor, line_table, line_count);return;}
        case 0:
            pickWeightedActorAction(actor, &D_800C9CC8, 4);
            return;
        case 10:
            pickWeightedActorAction(actor, &D_800C9CD8, 2);
            return;
        case 2:
            pickWeightedActorAction(actor, &D_800C9CE0, 2);
            return;
        }
        return;
    }
    state_id = *(u8 *)((s8 *)state + 0x82);
    if ((s32) state_id < 9) goto blkX;
    if ((s32) state_id < 0xC) goto blkY;
    if (state_id == 0x1E) goto blkY;
blkX:
    if (*(u8 *)((s8 *)&gActorTypeKindTable + (*(s8 *)((s8 *)*(void **)((s8 *)actor + 0x68) + 0xE) * 0xE8)) == 5) {
        {
    setActorCommandByType(actor);return;}
    }
    switch (*(s16 *)((s8 *)actor + 0x7C)) {
    case 3:
        if (is_near != 0) {
            if ((pickWeightedActorAction(actor, &D_800C9C38, 4) << 0x18) == 0) {
                {
    setActorCommandState(actor, 0x14D);return;}
            }
        } else if ((pickWeightedActorAction(actor, &D_800C9C18, 8) << 0x18) == 0) {
            {
    setActorCommandState(actor, 0x14D);return;}
        }
        break;
    case 1:
        pickWeightedActorAction(actor, &D_800C9C00, 6);
        return;
    case 0:
        if (is_near != 0) {
            pickWeightedActorAction(actor, &D_800C9C60, 4);
        } else {
            pickWeightedActorAction(actor, &D_800C9C48, 6);
        }
        return;
    case 10:
        if (is_near != 0) {
            pickWeightedActorAction(actor, &D_800C9C94, 2);
        } else {
            pickWeightedActorAction(actor, &D_800C9C70, 9);
        }
        return;    case 2:
        if (is_near != 0) {
            pickWeightedActorAction(actor, &D_800C9C9C, 2);
        } else {
            pickWeightedActorAction(actor, &D_800C9CA4, 5);
        }
        return;

    }
    return;
blkY:
    if (*(u8 *)((s8 *)&gActorTypeKindTable + (*(s8 *)((s8 *)*(void **)((s8 *)actor + 0x68) + 0xE) * 0xE8)) == 5) {
        {
    setActorCommandByType(actor);return;}
    }
    switch (*(s16 *)((s8 *)actor + 0x7C)) {
    case 1:
        pickWeightedActorAction(actor, &D_800C9CF8, 4);
        return;
    case 3:
        if ((pickWeightedActorAction(actor, &D_800C9CE8, 4) << 0x18) == 0 && (resetActorActionState(actor) << 0x18) != 0) {
            setActorCommandState(actor, 0x14D);
        }
        return;
    case 0:
        pickWeightedActorAction(actor, &D_800C9D08, 4);
        return;
    case 10:
        line_table = &D_800C9D18;
        line_count = 3;
        {
    pickWeightedActorAction(actor, line_table, line_count);return;}
    case 2:
        pickWeightedActorAction(actor, &D_800C9D24, 3);
        return;
    }
    return;
block_42:
    setActorCommandState(actor, 0x14D);
    return;
block_47:
    pickWeightedActorAction(actor, line_table, line_count);
    return;
}
