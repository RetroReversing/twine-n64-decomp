typedef struct { u8 status; u8 data[23]; } SaveSlotInfo;
typedef struct TextNode TextNode;
typedef struct { u8 data[32]; s16 slot; } TextTemplate;
extern TextNode *spawnTextNode(TextTemplate *);
extern s16 D_8011EE4C;
extern s32 gVisibleSaveSlotCount;
extern SaveSlotInfo sSaveSlotInfo[];
extern TextNode *sSaveSlotMarkerTable[];

void create_player_state_objects(void) {
    u16 slot = 0;
    if (gVisibleSaveSlotCount > 0) {
        s16 *marker = &D_8011EE4C;
        TextNode **items = sSaveSlotMarkerTable;
        s32 index = slot & 0xFFFF;
        do {
            s32 state = sSaveSlotInfo[index].status;
            s32 clearIndex;
            TextTemplate *template;
            if (state != 0) {
                template = (TextTemplate *)((u8 *)marker - 32);
                if (state >= 4) {
                    clearIndex = slot & 0xFFFF;
                    if (state != 5) goto clear;
                    template = (TextTemplate *)((u8 *)marker - 32);
                }
                *marker = slot;
                items[index] = spawnTextNode(template);
            } else {
                clearIndex = slot & 0xFFFF;
clear:
                items[clearIndex] = 0;
            }
            state = gVisibleSaveSlotCount;
            ++slot;
            if ((slot & 0xFFFF) >= state) break;
            index = slot & 0xFFFF;
        } while (1);
    }
}
