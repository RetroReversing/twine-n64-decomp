#define PTR(x, off) (*(void **)((u8 *)(x) + (off)))
s16 func_8002B278();
s32 func_8011A7C8();
extern u8 gSceneType;
extern s32 D_801002A8;
extern u8 D_801002AC;
extern s32 gSaveTotalSlots;
extern s32 gSaveSlotCount;
extern void *gBonusSceneHandle[];
extern u8 sProbeTimers[];
extern u16 D_8011F15C[];
extern s32 D_8011F3A8;

u8 func_8011A2A0(s32 arg0, void *arg1, void *arg2) {
    s32 *__base_gSaveSlotCount = &gSaveSlotCount;
    s32 *__base_D_801002B4 = &gSaveTotalSlots;
    void *q;
    u16 buf[2];
    s32 j;
    u16 i;
    int s2;
    long a0;
    s32 th;
    void *p;
    register s32 s0;

    for (i = 0; (u32)i < 2; i++) {
        buf[i] = 0;
    }
    switch (gSceneType) {
    case 6:
        if (D_801002A8 == 0) {
            D_801002AC = 0;
        }
        for (i = 0; (u32)i < 2; i++) {
            buf[i] = func_8002B278(sProbeTimers + i * 8) / 10;
        }
        for (i = 0; i < (*(__base_D_801002B4 = &gSaveTotalSlots)); i++) {
            p = gBonusSceneHandle[i];
            if (p != NULL) {
                q = (*(void * *)((u8 *)((*(void * *)((u8 *)(p) + (0x6C)))) + (0xB4)));
                buf[*(u8 *)((u8 *)q + 0x12)] += *(u16 *)((u8 *)q + 0xC) - *(u16 *)((u8 *)q + 0xE);
            }
        }
        th = (s32)&D_801002A8;
        if (th != 0) {
            for (i = 0; (unsigned)i < 2; i++) {
                if ((s16)buf[i] >= th) {
                    D_8011F3A8 = 0x5A;
                    D_801002AC = 1;
                }
            }
        }
        break;
    case 7:
    case 8:
        s0 = 0;
        s2 = 0;
        for (j = 0; j < (*__base_D_801002B4); j++) {
            p = gBonusSceneHandle[j];
            if (p != NULL && ((*(u8 *)((u8 *)(*(void * *)((u8 *)((*(void * *)((u8 *)(p) + (0x6C)))) + (0xB4))) + 0x11) == 0) == 0)) {
                __base_gSaveSlotCount = &gSaveSlotCount;
                s0 += j < (*__base_gSaveSlotCount);
                s2 += 1;
            }
        }
        if (s0 >= (*__base_gSaveSlotCount)) {
            func_8011A7C8();
            if ((*__base_gSaveSlotCount) <= s0) {
                D_8011F3A8 = 0x5A;
                D_801002AC = 1;
                break;
            }
        }
        if (!(s2 < (*__base_D_801002B4) - 1)) {
            D_8011F3A8 = 0x5A;
            D_801002AC = 1;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 5:
        for (i = 0; i < (*__base_D_801002B4); i++) {
            p = gBonusSceneHandle[i];
            if (p != NULL) {
                q = (*(void * *)((u8 *)((*(void * *)((u8 *)(p) + (0x6C)))) + (0xB4)));
                buf[*(u8 *)((u8 *)q + 0x12)] += *(u16 *)((u8 *)q + 0xC) - *(u16 *)((u8 *)q + 0xE);
            }
        }
        th = D_801002A8;
        if (th != 0) {
            for (i = 0; (u32)i < 2; i++) {
                if ((s16)buf[i] >= th) {
                    D_8011F3A8 = 0x5A;
                    D_801002AC = 1;
                }
            }
        }
        break;
    default:
        a0 = 0;
        for (j = 0; j < (s32)(*__base_D_801002B4); j++) {
            p = gBonusSceneHandle[j];
            if (p != NULL) {
                q = (*(void * *)((u8 *)((*(void * *)((u8 *)(p) + (0x6C)))) + (0xB4)));
                if (a0 < *(u16 *)((u8 *)q + 0xC) - *(u16 *)((u8 *)q + 0xE)) {
                    a0 = *(u16 *)((u8 *)q + 0xC) - *(u16 *)((u8 *)q + 0xE);
                }
            }
        }
        if (D_801002A8 != 0 && !(a0 < D_801002A8)) {
            D_8011F3A8 = 0x5A;
            D_801002AC = 1;
        }
        break;
    }
    for (i = 0; (u32)i < 2; i++) {
        D_8011F15C[i] = buf[i];
    }
    return D_801002AC;
}
