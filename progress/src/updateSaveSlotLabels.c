s32 actorSteerTowardTarget(void *, void *, void *, s32);
s16 resolveEnemyDefLink(s16);
s32 initObjectFromBankEntry(void *, s32, s32);
void *lookupDataEntry(u16);
s32 sprintf(char *, const char *, ...);
s16 strlen(s8 *);
extern s32 sMenuMarkerColor;
extern s32 sSaveMenuColorActive;
extern u8 D_801001A0[];
extern u8 D_8011508D[];
extern char D_8011F01C[];
extern char D_8011F020[];
extern char D_8011F02C[];
extern char D_8011F034[];
extern f64 D_8011F038;
extern s16 gBonusPlayerScores[];
extern char D_8011F378[][12];
extern s16 gResultLabelTimers[];
extern u8 gSceneType;
extern s32 gSaveTotalSlots;
extern s32 gVisibleSaveSlotCount;

typedef struct Label {
    u8 pad0[0x10];
    u32 color;
    u8 pad14[4];
    char *text;
    s16 length;
    u8 pad1E[0xA];
    u32 flags;
} Label;
typedef struct Info {
    u8 pad0[0xC];
    u16 start;
    u16 end;
    u8 flag10;
    u8 pad11;
    u8 kind;
} Info;
typedef struct Gauge {
    u8 pad0[0x26];
    u16 value;
} Gauge;
typedef struct Ent {
    u8 pad0[0x60];
    f32 scale;
    u8 pad64[0xB4 - 0x64];
    Info *info;
    u8 padB8[0x182 - 0xB8];
    s8 kind182;
    u8 pad183[0x418 - 0x183];
    Label *label418;
    Label *label41C;
    Label *label420;
    u8 pad424[0x478 - 0x424];
    Gauge *gauge478;
    Gauge *gauge47C;
} Ent;
typedef struct Meta {
    u8 pad0[0xE];
    u8 id;
} Meta;
typedef struct Obj {
    u8 pad0[0x24];
    f32 pos[3];
    u8 pad30[0x68 - 0x30];
    Meta *meta;
    Ent *ent;
    u8 pad70[4];
    f32 life;
    u16 mode;
} Obj;

extern Obj *sBonusObjectTable[];
extern u8 sEnemyDefTable[];
extern Label *D_8011F3D0[];
extern Label *gResultLabels[];
extern Label *D_8011F2F8[][4];


/* Per-frame update of each visible save slot's text labels, health gauges and cross-slot marker labels. */ void updateSaveSlotLabels(void) {
    u8 slotLabel[2];
    u16 i;
    u16 k;
    u32 slot;
    s32 idx;
    s32 off;
    s32 t1;
    s32 t2;
    s32 t3;
    s16 enemyId;
    u8 defKind;
    f32 temp;
    f32 y0;
    f32 y1;
    s32 a1;
    s16 *cd;
    s16 *tab;
    s16 *hp;
    u8 *def;
    Obj *obj;
    Ent *ent;
    Info *info;
    Info *info2;
    Meta *meta;
    Label *scoreLabel;
    Label *lab2;
    Label **lp;
    Obj **ps;
    Obj **pk;
    Label *markerLabel;
    Obj *o2;

    for (i = 0; i < gVisibleSaveSlotCount; i++) {
        obj = sBonusObjectTable[i];
        if (obj != NULL) {
            ent = obj->ent;
            if (ent != NULL) {
                info = ent->info;
                if (info->kind == 2) {
                    sprintf(D_8011F378[i], D_8011F01C, info->start - info->end);
                } else {
                    slotLabel[0] = 12;
                    slotLabel[1] = 5;
                    info2 = ent->info;
                    sprintf(D_8011F378[i], D_8011F020, info2->start - info2->end, 5, slotLabel[info2->kind], gBonusPlayerScores[ent->info->kind]);
                }
                idx = i;
                scoreLabel = D_8011F3D0[idx];
                if (scoreLabel != NULL) {
                    scoreLabel->length = strlen(D_8011F378[idx]);
                }
                lp = &gResultLabels[idx];
                if (*lp != NULL && (tab = gResultLabelTimers, cd = tab + idx, *cd > 0)) {
                    *cd = *cd - 1;
                    if (sBonusObjectTable[idx]->life <= 0.0f) {
                        *cd = 0;
                    }
                    if (*cd < 0x20) {
                        (*lp)->color = (*lp)->color & ~0xFF;
                        (*lp)->color = (*lp)->color | (*cd * 8);
                    }
                    if (*cd == 0) {
                        (*lp)->flags = ((*lp)->flags & ~0xFC) | 0x1C;
                    }
                }
                meta = sBonusObjectTable[i]->meta;
                if (meta != NULL) {
                    enemyId = (s8) meta->id;
                } else {
                    enemyId = 0;
                }
                def = sEnemyDefTable + enemyId * 0xE8;
                defKind = def[0x80];
                if (D_8011508D[ent->kind182 * 0xA0] != 0) {
                    ent->label418->color |= 0xFF;
                    ent->label420->color |= 0xFF;
                } else {
                    ent->label418->color &= ~0xFF;
                    ent->label420->color &= ~0xFF;
                }
                temp = (f32) (D_8011F038 / (2.0 * (f64) D_801001A0[i * 0x18])) * sBonusObjectTable[i]->life;
                ent->gauge478->value = (u32) temp;
                temp = ent->scale * 0.24f;
                ent->gauge47C->value = (u32) temp;
                if (ent->gauge478->value == 0) {
                    if (sBonusObjectTable[i]->life > 0.0f) {
                        ent->gauge478->value = 1;
                    }
                }
                if (enemyId != 0) {
                    t1 = resolveEnemyDefLink(enemyId) * 8;
                    hp = (s16 *) ((char *) ent + 0x1BC);
                    sprintf(ent->label418->text, D_8011F02C, *(s8 *) ((char *) ent + t1 + 0x1FF), hp[defKind]);
                } else {
                    *ent->label418->text = 0;
                }
                lab2 = ent->label418;
                lab2->length = strlen(lab2->text);
                if (ent->label41C != NULL) {
                    sprintf(ent->label41C->text, D_8011F034, lookupDataEntry((enemyId & 0xFFFF) | 0xA000));
                    lab2 = ent->label41C;
                    lab2->length = strlen(lab2->text);
                }
                t2 = enemyId * 8;
                sprintf(ent->label420->text, D_8011F034, lookupDataEntry(*(u16 *) (def + *(u8 *) ((char *) ent + t2 + 0x1FD) * 2 + 0x2C)));
                lab2 = ent->label420;
                lab2->length = strlen(lab2->text);
                if (D_801001A0[i * 0x18 + 2] != 0) {
                    k = 0;
                    if (gSaveTotalSlots > 0) {
                        ent = (Ent *) (u32) i;
                        for (; k < gSaveTotalSlots; k++) {
                            if (sBonusObjectTable[k] != NULL && (u32) ent != k) {
                                markerLabel = D_8011F2F8[k][(u32) ent];
                                if (markerLabel != NULL) {
                                    if ((u32) (sBonusObjectTable[k]->mode - 2) < 2U) {
                                        markerLabel->flags = (markerLabel->flags & ~0xFC) | 0xC;
                                    } else {
                                        markerLabel->flags = (markerLabel->flags & ~0xFC) | 0x1C;
                                    }
                                    pk = &sBonusObjectTable[k];
                                    actorSteerTowardTarget(markerLabel, sBonusObjectTable[(u32) ent], &(*pk)->pos[0], (u32) ent);
                                    y0 = (*pk)->pos[1];
                                    y1 = sBonusObjectTable[(u32) ent]->pos[1];
                                    if (y1 < y0 - 1.0f) {
                                        initObjectFromBankEntry(markerLabel, 0x17, 0x1B);
                                    } else if ((y0 + 1.0f) < y1) {
                                        initObjectFromBankEntry(markerLabel, 0x1A, 0x1B);
                                    } else {
                                        initObjectFromBankEntry(markerLabel, 0x1B, 0x1B);
                                    }
                                    if (gSceneType == 8) {
                                        if (sBonusObjectTable[k]->ent->info->flag10 != 0) {
                                            markerLabel->color = sMenuMarkerColor;
                                        } else {
                                            markerLabel->color = sSaveMenuColorActive;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
