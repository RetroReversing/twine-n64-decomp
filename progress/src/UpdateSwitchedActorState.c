static __inline__ s32 __repair_inline(s32 a) { return a; }
extern u8 gTrackMarkerDone[];
void updateActorProximityTrigger(void *arg0);
s32 func_800179E8(void *a, s32 b, s32 c, s32 d);
s32 func_800624A8(void *a, void *b, s32 c, s32 d);
s32 func_80084338(s32 a, void *b);

/* Per-frame update of a switched actor: runs its one-shot setup when flagged, then advances its
 * animation/state phase and timer while its trigger flag matches, and clears its output flag otherwise. */
void UpdateSwitchedActorState(void *actor) {
    s32 flags;
    u8 *script;
    s16 phase;
    s16 next_phase;
    s16 timer;

    flags = __repair_inline(*(s32 *)((u8 *)actor + 0x60));
    script = *(u8 **)((u8 *)actor + 0x6C);
    if (flags & 2) {
        *(s32 *)((u8 *)actor + 0x60) = flags & ~2;
        func_800624A8(actor, (u8 *)actor + 0x24, 0x3DCCCCCD, 1);
        func_800179E8((u8 *)actor + 0x24, *(s32 *)((u8 *)actor + 0x20), 0x10000, 2);
        *(s32 *)((u8 *)actor + 0x60) |= 1;
        if (script[4] != 0 && script[5] == gTrackMarkerDone[script[4]] && script[6] != 0) {
            gTrackMarkerDone[script[6]] = 1;
        }
    }
    if (script[4] == 0 || script[5] == gTrackMarkerDone[script[4]]) {
        phase = *(s16 *)((u8 *)actor + 0x7A);
        switch (phase) {
        case 0:
            if (*(u16 *)script == 0) {
                *(f32 *)((u8 *)actor + 0x40) += 9.0f;
            }
        case 1:
            if (*(u16 *)script == 0) {
                script[2]--;
            }
            if (script[2] == 0) {
                next_phase = *(s16 *)((u8 *)actor + 0x7A) + 1;
                *(s16 *)((u8 *)actor + 0x7A) = next_phase;
                if (next_phase == 1) {
                    script[2] = 0xA;
                    func_80084338(0x10F, (u8 *)actor + 0x24);
                } else {
                    script[2] = 0x50;
                }
            }
            updateActorProximityTrigger(actor);
            break;
        case 2:
            if (*(u16 *)script == 0) {
                *(f32 *)((u8 *)actor + 0x40) += -9.0f;
            }
        case 3:
            if (*(u16 *)script == 0) {
                script[2]--;
            }
            if (script[2] == 0) {
                script[2] = 0;
                next_phase = (*(s16 *)((u8 *)actor + 0x7A) + 1) & 3;
                *(s16 *)((u8 *)actor + 0x7A) = next_phase;
                if (next_phase == 3) {
                    script[2] = 0xA;
                    func_80084338(0x10F, (u8 *)actor + 0x24);
                } else {
                    script[2] = 0x50;
                }
            }
            updateActorProximityTrigger(actor);
            break;
        }
        timer = *(s16 *)((u8 *)actor + 0x7C);
        if (timer > 0) {
            if (*(u16 *)((u8 *)actor + 0x78) == 0x1B) {{ s16 __repair_value; __repair_value = timer + 1; timer = __repair_value; }
                *(s16 *)((u8 *)actor + 0x7C) = timer;
                if (timer >= 0x385) {
                    *(s16 *)((u8 *)actor + 0x7C) = 0;
                }
            }
            if (script[3] != 0) {
                gTrackMarkerDone[script[3]] = 1;
            }
            return;
        }
    }
    if (script[3] != 0) {
        gTrackMarkerDone[script[3]] = 0;
    }
}
