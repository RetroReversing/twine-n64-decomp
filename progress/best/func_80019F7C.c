/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80001E28();
s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002D30();
s32 func_80019E28();
s32 formatTextEntry();
void *findEntryById();
s32 func_80027C60();
s32 func_80027CE0();
s32 updateActiveMenuState();
s32 func_8002B8AC();
s32 func_8002B930();
s32 func_8002B9CC();
s32 func_8002BA6C();
s32 getKeyEntryFlag();
s32 activateIdList();
extern void *gPickupActor;
extern u16 gSharedItemId;
extern s16 gSharedItemArg;
extern u8 D_800BF688[];
extern char D_800C3CF8[];
extern char gSaveSlotInfo[];
typedef struct { u8 f0; u8 pad[23]; } Slot_801001A3;
extern Slot_801001A3 D_801001A3[];
extern u8 gPickupSavedByte;
extern s32 gSaveSlotCount;
extern s8 gSharedItemBusy;
extern void *gMenuState;

extern char sFmtEntryName[];
extern char D_800D2858[];
void func_80019F7C(void) {
    s32 var_a1;
    u32 temp_a0;
    void **__base_D_800B5B14;
    
    long var_s1;
    u16 temp_v1;
    u16 temp_v1_3;
    u8 temp_s0_2;
    register u8 temp_v1_2;
    register void *temp_s0;
    register void *temp_s3;
    void *temp_s4;

    temp_s4 = findEntryById((*(s32 *)((char *)(gMenuState) + 0x10)), 0x400C);
    temp_s0 = (*(void **)((char *)(gMenuState) + 0x18));
    do { updateActiveMenuState(); } while (0);
    var_s1 = *(*(s32 **)((char *)(temp_s0) + 0x10));
    temp_s3 = (void *)(temp_s0); temp_s3 = (void *)((char *)temp_s3 + (s32)(0x28));
    if (((*(u8 *)((char *)(gMenuState) + 0x2D)) != 0) && ((*(u8 *)((char *)(gMenuState) + 0x2E)) == 0)) {
        D_801001A3[gPickupSavedByte].f0 = 0;
        if (func_80027CE0(0x20) & 0xFF) {
            var_s1 = func_8002B930(var_s1, -1);
        }
        if (func_80027CE0(0x21) & 0xFF) {
            var_s1 = func_8002B930(var_s1, 1);
        }
        *(*(s32 **)((char *)(temp_s0) + 0x10)) = var_s1;
        __base_D_800B5B14 = &gPickupActor;
        if ((*__base_D_800B5B14) != NULL) {
            func_8002B8AC();
            temp_v1 = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC));
            gSharedItemArg = -1;
            gSharedItemBusy = 1;
            gSharedItemId = temp_v1;
            activateIdList(&gSharedItemId);
            gSharedItemBusy = 0;
            func_8000237C((*__base_D_800B5B14), func_8002B9CC(var_s1), 0, D_801001A3[gPickupSavedByte].f0);
            func_80002BD0((*__base_D_800B5B14), 0x14D);
            (*(f32 *)((char *)((*(void **)((char *)((*__base_D_800B5B14)) + 0x68))) + 0x34)) = 0.05f;
            if (getKeyEntryFlag(*(s32 *)(gSaveSlotInfo + (gPickupSavedByte * 0x18))) & 0xFF) {
                func_80002D30((*__base_D_800B5B14), 0x327);
            } else {
                func_80002D30((*__base_D_800B5B14), 0x2A9);
            }
            goto block_11;
        }
    } else {
block_11:
        (*(u8 *)((char *)(gMenuState) + 0x2D)) = 0U;
        if (func_80027C60(0x28) & 0xFF) {
            temp_a0 = gPickupSavedByte * 0x18;
            temp_v1_2 = D_801001A3[gPickupSavedByte].f0;
            if (temp_v1_2) {
                (*(s8 *)((char *)((temp_a0 + (&gPickupSavedByte - 0x115))) + 0xB)) = (s8) (temp_v1_2 - 1);
                (*(u8 *)((char *)(gMenuState) + 0x2D)) = 1U;
            }
        }
        if (func_80027C60(0x29) & 0xFF) {
            temp_s0_2 = D_801001A3[gPickupSavedByte].f0;
            if (temp_s0_2 < func_80001E28(*(s16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC)))) {
                temp_a0 = gPickupSavedByte * 0x18;
                (*(s8 *)((char *)((temp_a0 + (&gPickupSavedByte - 0x115))) + 0xB)) = (s8) (D_801001A3[gPickupSavedByte].f0 + 1);
                (*(u8 *)((char *)(gMenuState) + 0x2D)) = 1U;
            }
        }
        if (((*(u8 *)((char *)(gMenuState) + 0x2D)) != 0) && ((*(u8 *)((char *)(gMenuState) + 0x2E)) == 0)) {
            if (gPickupActor != NULL) {
                func_8002B8AC();
                temp_v1_3 = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC));
                gSharedItemArg = -1;
                gSharedItemBusy = 1;
                gSharedItemId = temp_v1_3;
                activateIdList(&gSharedItemId);
                gSharedItemBusy = 0;
                func_8000237C((*__base_D_800B5B14), func_8002B9CC(var_s1), 0, D_801001A3[gPickupSavedByte].f0);
                func_80002BD0((*__base_D_800B5B14), 0x14D);
                (*(f32 *)((char *)((*(void **)((char *)((*__base_D_800B5B14)) + 0x68))) + 0x34)) = 0.05f;
                goto block_21;
            }
        } else {
block_21:
            if (temp_s3 != NULL) {
                formatTextEntry(temp_s3, sFmtEntryName, func_8002BA6C(var_s1));
            }
            if (temp_s4 != NULL) {
                func_80019E28(temp_s4);
            }
            if (gPickupSavedByte > gSaveSlotCount) {
                temp_s4 = findEntryById((*(s32 *)((char *)(gMenuState) + 0x10)), 0x4004);
formatTextEntry(temp_s4, D_800D2858, *(D_800BF688 + (*(s32 *)(gSaveSlotInfo + (gPickupSavedByte * 0x18)) * 0xC)) * 5);
            }
        }
    }
}
