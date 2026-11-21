s32 spawnTextNode(s16 *);
extern s16 D_8011EE4C;
extern s32 gVisibleSaveSlotCount;
extern s8 sSaveSlotInfo;
extern s32 sSaveSlotMarkerTable[];
void create_player_state_objects(void) {
    s16 *__base_D_8011EE4C;
    s16 *var_a0;
    u16 var_s1;
    s32 var_s0;
    s32 var_v0;
    s32 *markers;
    s32 temp_v1;
    var_s1 = 0;
    if (gVisibleSaveSlotCount > 0) {
        markers = sSaveSlotMarkerTable;
        var_s0 = 0 & 0xFFFF;
        do {
            temp_v1 = *((u8 *)&sSaveSlotInfo + (var_s0 * 0x18));
            if (temp_v1 != 0) {
                __base_D_8011EE4C = &D_8011EE4C;
                var_a0 = (s16 *)((u8 *)__base_D_8011EE4C - 0x20);
                if ((s32) temp_v1 >= 4) {
                    var_v0 = var_s1 & 0xFFFF;
                    if (temp_v1 == 5) {
                        var_a0 = (s16 *)((u8 *)__base_D_8011EE4C - 0x20);
                        goto block_6;
                    }
                    goto block_8;
                }
block_6:
                (*__base_D_8011EE4C) = var_s1;
                markers[var_s0] = spawnTextNode(var_a0);
            } else {
                var_v0 = var_s1 & 0xFFFF;
block_8:
                markers[var_v0] = 0;
            }
            var_s1 += 1;
            var_s0 = var_s1 & 0xFFFF;
        } while ((var_s1 & 0xFFFF) < gVisibleSaveSlotCount);
    }
}
