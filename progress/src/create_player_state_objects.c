typedef struct {
    u8 state;
    u8 reserved[23];
} MenuPlayerState;

extern MenuPlayerState D_801001A2[];
extern s32 gVisibleSaveSlots;
extern s16 D_8011EE4C;
extern void *D_8011F338[];
void *func_80015F74(void *);

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
        results = D_8011F338;
        do {
            s32 state = D_801001A2[i].state;
            if (state != 0) {
                if (state < 4) {
                    goto create;
                }
                if (state != special) {
                    goto clear;
                }
create:
                *paramIndex = i;
                results[i] = func_80015F74((u8 *)paramIndex - 0x20);
            } else {
clear:
                results[i] = NULL;
            }
            i++;
        } while (i < gVisibleSaveSlots);
    }
}
