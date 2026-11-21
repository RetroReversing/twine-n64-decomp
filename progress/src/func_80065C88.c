typedef struct { u8 pad0[0xE]; s8 bE; s8 bF; } Ctl65C88;
typedef struct { u8 pad0[0xA8]; s32 wA8; u8 padAC[0x88]; s16 h134; } Sub65C88;
typedef struct { u8 pad0[0x68]; Ctl65C88 *ctl; Sub65C88 *sub; u8 pad70[0xC]; s16 h7C; } Obj65C88;
typedef struct { u8 flag; u8 pad[0x9F]; } Ent65C88;

s32 func_800643D8(s32);
extern s32 gSaveSlotCount;
extern u8 D_8010A4C0[];
extern Obj65C88 *gBonusObjectTable[];
extern Ent65C88 sBonusSlotEntries[];

void func_80065C88(void) {
    s32 i;
    Obj65C88 *p;
    Sub65C88 *s;

    for (i = 0; i < gSaveSlotCount; i++) {
        p = gBonusObjectTable[i];
        if (p != NULL) {
            s = p->sub;
            if (p->h7C == 5) {
                sBonusSlotEntries[i].flag = 1;
            }
            if (p->h7C == 7) {
                func_800643D8(s->wA8);
                s->h134 = p->ctl->bE;
                p->ctl->bF = 0;
                D_8010A4C0[2] &= 0xDE;
            }
        }
    }
}
