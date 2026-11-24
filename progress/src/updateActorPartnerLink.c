s32 releaseActorMarkers();
s32 findLinkedObjectByFlagMask();
s32 releaseProbeForOwner();
s32 showPlayerCaptionMessage();
extern u8 gSceneType;
extern u8 gSaveKeyRelaxed;
extern u8 D_801002D5;
extern s16 sActorPartnerSlots[];

typedef struct Stats {
    u8 pad0[0xC];
    u16 hitCount;       /* 0x0C */
    u16 partnerCount;   /* 0x0E */
    u8 f10;
    u8 linkTimer;       /* 0x11 */
    u8 f12;
} Stats;

typedef struct Ent {
    u8 pad0[4];
    struct Ent *partner;    /* 0x04 */
    u8 pad1[0xB4 - 8];
    Stats *stats;           /* 0xB4 */
    u8 pad2[0x182 - 0xB8];
    s8 slot;                /* 0x182 */
    u8 pad3[0x1B4 - 0x183];
    s32 kind;               /* 0x1B4 */
} Ent;

typedef struct Arg {
    u8 pad[0x6C];
    Ent *actor;             /* 0x6C */
} Arg;

/* Links an actor to its matching partner for the current scene and updates the partner slot table. */
void updateActorPartnerLink(Arg *arg0) {
    Ent *a;
    Ent *b;

    a = arg0->actor;
    b = (Ent *)findLinkedObjectByFlagMask(a->partner);
    switch (gSceneType) {
    case 8:
        if (a->kind == 0x26 && b->stats->f10 == 7) {
            a->stats->linkTimer = 1;
            b->stats->hitCount += 1;
        }
        releaseActorMarkers(arg0, a, b);
        break;
    case 7:
        if (a->stats->linkTimer != 0) {
            a->stats->hitCount -= 1;
            a->stats->linkTimer -= 1;
            if (a->stats->hitCount == 0) {
                showPlayerCaptionMessage(a->slot);
            }
        }
        break;
    case 2:
    case 3:
        releaseProbeForOwner(arg0);
    default:
        if (b == a || b == 0) {
            a->stats->partnerCount += 1;
        } else if (b != 0) {
            if (gSaveKeyRelaxed != 0) {
                Stats *s = b->stats;
                if (s->f12 == a->stats->f12) {
                    if (D_801002D5 != 0) {
                        s->partnerCount += 1;
                    }
                } else {
                    s->hitCount += 1;
                }
            } else {
                b->stats->hitCount += 1;
            }
        }
        break;
    }
    if (a != 0) {
        if (b != 0) {
            sActorPartnerSlots[a->slot] = b->slot;
            a->partner = 0;
            return;
        }
        sActorPartnerSlots[a->slot] = -1;
        a->partner = 0;
    }
}
