typedef struct {
    u8 state;
    u8 reserved[23];
} MenuPlayerState;

extern MenuPlayerState D_801001A2[];
extern s32 D_801002C0;
extern s16 D_8011EE4C;
extern void *D_8011F338[];
void *func_80015F74(void *);

/* For each visible save slot, creates a marker object if its state is active (1-3 or 5); otherwise clears the entry. */ void createSaveSlotMarkers(void)
{
    u16 slot;
    s32 specialState;
    s16 *slotParam;
    void **markers;
    slot = 0;
    if (D_801002C0 > 0) {
        specialState = 5;
        slotParam = &D_8011EE4C;
        markers = D_8011F338;
        do {
            s32 state = D_801001A2[slot].state;
            if (state != 0) {
                if (state < 4) {
                    goto create;
                }
                if (state != specialState) {
                    goto clear;
                }
create:
                *slotParam = slot;
                markers[slot] = func_80015F74((u8 *)slotParam - 0x20);
            } else {
clear:
                markers[slot] = NULL;
            }
            slot++;
        } while (slot < D_801002C0);
    }
}
