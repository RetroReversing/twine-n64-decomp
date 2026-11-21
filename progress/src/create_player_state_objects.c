typedef struct {
    u8 state;
    u8 reserved[23];
} MenuPlayerState;

extern MenuPlayerState sSaveSlotInfo[];
extern s32 gVisibleSaveSlots;
extern s16 D_8011EE4C;
extern void *sSaveSlotMarkers[];
void *spawnTextNode(void *);

void create_player_state_objects(void)
{
    u16 i;
    s32 special;
    s16 *paramIndex;
    void **results;
    i = 0;
    if (gVisibleSaveSlots > 0) {
        special = 5;
        paramIndex = &D_8011EE4C;
        results = sSaveSlotMarkers;
        do {
            s32 state = sSaveSlotInfo[i].state;
            if (state != 0) {
                if (state < 4) {
                    goto create;
                }
                if (state != special) {
                    goto clear;
                }
create:
                *paramIndex = i;
                results[i] = spawnTextNode((u8 *)paramIndex - 0x20);
            } else {
clear:
                results[i] = NULL;
            }
            i++;
        } while (i < gVisibleSaveSlots);
    }
}
