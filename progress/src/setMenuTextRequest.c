/* Menu text object: a pooled display object with a text pointer and position. */
typedef struct MenuTextObj {
    u8 pad00[0x10];
    s32 param10;
    s32 param14;
    void *text;
    s16 textLength;
    u16 param1E;
    u16 x;
    u16 y;
    u8 pad24[4];
    s32 flags;
} MenuTextObj;

/* Request record filled in by menu code and consumed by setMenuTextRequest. */
typedef struct MenuTextRequest {
    u8 pad00[2];
    u16 slot02;
    u16 spriteX;
    u16 spriteY;
    s32 value08;
    s32 value0C;
    union {
        s32 word;
        s16 hi;
    } spriteArgs;
    u16 textId;
    u16 textX;
    u16 textY;
} MenuTextRequest;

/* Menu state: the active text object and a pending object applied next frame. */
typedef struct MenuState {
    MenuTextObj *activeText;
    u8 pad04[0x20];
    MenuTextObj *pendingText;
} MenuState;

void *spawnTrackMarker(u8);
void freeMenuItemRecord(void *);
s32 initObjectFromBankEntry(void *, u32, s32);
s32 lookupDataEntry(u16, void *);
s32 strlen(s8 *);
extern u8 sMenuListKind;
extern MenuState *gMenuItems;

/* Replaces the menu text request: frees the pending object, rebuilds the active text, and queues a sprite object. */
void setMenuTextRequest(MenuTextRequest *request) {
    u32 packed;
    s32 flags;
    void *text;
    MenuTextObj *temp_a0;
    MenuTextObj *temp_a1;
    MenuTextObj *temp_s0;
    MenuTextObj *temp_v0;
    MenuTextObj *temp_v0_2;
    s32 temp_a0_2;

    temp_a0 = gMenuItems->pendingText;
    if (temp_a0 != NULL) {
        freeMenuItemRecord(temp_a0);
    }
    gMenuItems->pendingText = NULL;
    if (request != NULL) {
        if ((gMenuItems->activeText != NULL) || (temp_v0 = spawnTrackMarker(sMenuListKind), (gMenuItems->activeText = temp_v0), (temp_v0 != NULL))) {
            gMenuItems->activeText->param1E = request->slot02;
            temp_a1 = gMenuItems->activeText;
            temp_a1->flags = (temp_a1->flags & ~0xFC) | 0xC;
            gMenuItems->activeText->x = request->textX;
            gMenuItems->activeText->y = request->textY;
            gMenuItems->activeText->param10 = -0x100;
            gMenuItems->activeText->text = (void *)lookupDataEntry(request->textId, temp_a1);
            gMenuItems->activeText->textLength = 0;
            temp_s0 = gMenuItems->activeText;
            temp_a0_2 = (s32)temp_s0->text;
            if (temp_a0_2) {
                temp_s0->textLength = strlen((s8 *)temp_a0_2);
            }
        }
        gMenuItems->pendingText = NULL;
        if (request->spriteArgs.hi >= 0) {
            temp_v0_2 = spawnTrackMarker(sMenuListKind);
            temp_v0_2->param10 = request->value08;
            flags = temp_v0_2->flags;
            temp_a0_2 = request->value0C;
            flags &= ~0xFC;
            flags |= 0x14;
            temp_v0_2->flags = flags;
            temp_v0_2->param14 = temp_a0_2;
            temp_v0_2->param1E = request->slot02;
            packed = (u32)request->spriteArgs.word;
            initObjectFromBankEntry(temp_v0_2, packed >> 0x10, packed & 0xFF);
            {
                u16 x = request->spriteX;
                MenuState *p = gMenuItems;
                temp_v0_2->x = x;
                temp_v0_2->y = request->spriteY;
                p->pendingText = temp_v0_2;
            }
        }
    }
}
