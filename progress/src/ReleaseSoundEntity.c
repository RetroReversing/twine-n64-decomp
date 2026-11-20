typedef struct SndNode { struct SndNode *next; struct SndNode *prev; s32 h; } SndNode;

typedef struct {
    s32 id;            /* 0x000 */
    u8 pad4[0x10C];
    s32 w110;          /* 0x110 */
    s32 w114;          /* 0x114 */
    u8 pad118[0x410];
    u8 tbl528[0x80];   /* 0x528 */
    u8 pad5A8[0x9D0];
    struct SndNode *listF78;   /* 0xF78 */
    struct SndNode *listF7C;   /* 0xF7C */
    u8 padF80[0x40];
    u8 active;         /* 0xFC0 */
    u8 busy;           /* 0xFC1 */
    s16 hFC2;          /* 0xFC2 */
    u8 bFC4;           /* 0xFC4 */
    u8 bFC5;           /* 0xFC5 */
    u8 padFC6[0x1E];
    s32 wFE4;          /* 0xFE4 */
    s32 wFE8;          /* 0xFE8 */
    s16 hFEC;          /* 0xFEC */
    u8 flags;          /* 0xFEE */
    u8 padFEF[9];
} EntSnd;

extern EntSnd gSndEntities[];

static inline s32 find_snd(s32 id) {
    u32 i = 0;
    s32 key = id & 0x7FFFFFFF;
    s32 off = 0;

    for (; i < 8; i++, off += sizeof(EntSnd)) {
        if (*((u8 *)&gSndEntities[0].busy + off) == 0 && *(s32 *)((u8 *)&gSndEntities[0].id + off) == key) {
            return i | (id & 0x80000000);
        }
    }
    return -1;
}

extern SndNode *gFreeSndNodeList;
void sndStopNode(s32);

/* Releases a sound entity slot: deactivates it, stops its two playing lists, and moves those lists onto the free list. */ void ReleaseSoundEntity(s32 entity_id) {
    SndNode *node;
    EntSnd *ent;
    EntSnd *ent_ptr;
    SndNode *tail;

    entity_id = find_snd(entity_id);
    if (entity_id == -1) {
        return;
    }
    if (entity_id >= 0) {
        if (gSndEntities[entity_id].active != 0 && gSndEntities[entity_id].busy == 0) {
            ent = &gSndEntities[entity_id];
            gSndEntities[entity_id].active = 0;
            for (node = ent->listF78; node != NULL; node = node->next) {
                sndStopNode(node->h);
            }
            for (node = ent->listF7C; node != NULL; node = node->next) {
                sndStopNode(node->h);
            }
            ent_ptr = &gSndEntities[entity_id];
            tail = ent_ptr->listF78;
            if (tail != NULL) {
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                if (gFreeSndNodeList != NULL) {
                    tail->next = gFreeSndNodeList;
                    gFreeSndNodeList->prev = tail;
                }
                gFreeSndNodeList = ent_ptr->listF78;
                ent_ptr->listF78 = NULL;
            }
            tail = ent_ptr->listF7C;
            if (tail != NULL) {
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                if (gFreeSndNodeList != NULL) {
                    tail->next = gFreeSndNodeList;
                    gFreeSndNodeList->prev = tail;
                }
                gFreeSndNodeList = ent_ptr->listF7C;
                ent_ptr->listF7C = NULL;
            }
        }
    } else {
        entity_id &= 0x7FFFFFFF;
        if (gSndEntities[entity_id].active != 0 && gSndEntities[entity_id].busy == 0) {
            gSndEntities[entity_id].flags |= 8;
        }
    }
}
