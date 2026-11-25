typedef struct { u8 pad0[0xE]; s8 bE; s8 bF; } BonusCtl;
typedef struct { u8 pad0[0xA8]; s32 wA8; u8 padAC[0x88]; s16 h134; } BonusSub;
typedef struct { u8 pad0[0x68]; BonusCtl *ctl; BonusSub *sub; u8 pad70[0xC]; s16 state; } BonusObject;
typedef struct { u8 flag; u8 pad[0x9F]; } BonusSlotEntry;

s32 func_800643D8(s32);
extern s32 gSaveSlotCount;
extern u8 gExpansionModeEnabled[];
extern BonusObject *sBonusObjectTable[];
extern BonusSlotEntry sBonusSlots[];

/* Updates each active bonus object: state 5 marks its slot entry, and state 7 runs the bonus handler and clears the object's control bytes. */
void updateBonusObjects(u8 arg0) {
    s32 i;
    BonusObject *p;
    BonusSub *s;

    for (i = 0; i < gSaveSlotCount; i++) {
        p = sBonusObjectTable[i];
        if (p != NULL) {
            s = p->sub;
            if (p->state == 5) {
                sBonusSlots[i].flag = 1;
            }
            if (p->state == 7) {
                func_800643D8(s->wA8);
                s->h134 = p->ctl->bE;
                p->ctl->bF = 0;
                gExpansionModeEnabled[2] &= 0xDE;
            }
        }
    }
}
