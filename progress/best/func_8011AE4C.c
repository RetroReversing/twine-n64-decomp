typedef struct { f32 x, y, z; } Vec3f;
extern void relinkTrackMarker(void *, s32);
extern void startBonusSceneActor(void *);
extern s32 func_8002B150(void *, s32, s32);
extern s32 func_8007089C(void *, s32, u16);
extern u8 D_801002A3;
extern s32 gSaveTotalSlots;
extern u8 *sBonusObjectTable[];
extern u8 sMenuCountdown;
extern u8 *sBonusMarkerNodes;
extern u8 *sMarkerTextNode2;
extern u8 *sMarkerTextNode3;

void func_8011AE4C(u8 *arg0, u8 *arg1, u8 *arg2) {
    Vec3f pos = *(Vec3f *)(arg0 + 0x24);
    u32 i;
    s32 s0;
    if (*(arg1 + 0) , *(*(u8 **)(arg1 + 0xB4) + 0x10) == 7) {
        func_8002B150(&sMenuCountdown, 0, 0);
        if (*(s8 *)(*(u8 **)(arg0 + 0x68) + 0xE) == 0x26) {
            func_8007089C(arg0, 0, *(u16 *)(arg1 + 0x134));
        }
        *(s8 *)(arg1 + 0x32C) = 0;
        *(s16 *)(arg1 + 0x1D8) = 0;
        D_801002A3 = 0;
        *(*(u8 **)(arg1 + 0xB4) + 0x10) = 0;
        *(s32 *)(sBonusMarkerNodes + 0x28) = (*(s32 *)(sBonusMarkerNodes + 0x28) & ~0xFC) | 0x1C;
        *(s32 *)(sMarkerTextNode2 + 0x28) = (*(s32 *)(sMarkerTextNode2 + 0x28) & ~0xFC) | 0x1C;
        *(s32 *)(sMarkerTextNode3 + 0x28) = (*(s32 *)(sMarkerTextNode3 + 0x28) & ~0xFC) | 0x1C;
        if (gSaveTotalSlots > 0) {
            u16 n = 0;
            do {
                u8 *o = sBonusObjectTable[n];
                if (o != NULL) {
                    u8 *t = *(u8 **)(o + 0x6C);
                    if (t != NULL) {
                        *(*(u8 **)(t + 0xB4) + 0x11) = 0;
                    }
                }
                n++;
            } while (n < *(s32 *)(&D_801002A3 + 0x11));
        }
    } else {
        s0 = 0;
        if (arg2 != NULL && arg2 != arg1 && *(f32 *)(sBonusObjectTable[*(s8 *)(arg2 + 0x182)] + 0x74) > 0.0f) {
            s0 = *(*(u8 **)(arg2 + 0xB4) + 0x10) != 7;
        }
        if (*(*(u8 **)(arg1 + 0xB4) + 0x10) & 1) {
            *(s32 *)(sBonusMarkerNodes + 0x28) = (*(s32 *)(sBonusMarkerNodes + 0x28) & ~0xFC) | 0x1C;
            if (s0 & 0xFF) relinkTrackMarker(arg2, 1);
        }
        if (*(*(u8 **)(arg1 + 0xB4) + 0x10) & 2) {
            *(s32 *)(sMarkerTextNode2 + 0x28) = (*(s32 *)(sMarkerTextNode2 + 0x28) & ~0xFC) | 0x1C;
            if (s0 & 0xFF) relinkTrackMarker(arg2, 2);
        }
        if (*(*(u8 **)(arg1 + 0xB4) + 0x10) & 4) {
            *(s32 *)(sMarkerTextNode3 + 0x28) = (*(s32 *)(sMarkerTextNode3 + 0x28) & ~0xFC) | 0x1C;
            if (s0 & 0xFF) {
                relinkTrackMarker(arg2, 4);
                goto blk;
            }
        } else {
blk:
            if ((s0 & 0xFF) && *(*(u8 **)(arg2 + 0xB4) + 0x10) == 7) startBonusSceneActor(arg2);
        }
        *(*(u8 **)(arg1 + 0xB4) + 0x10) = 0;
    }
}
