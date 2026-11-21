/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 refreshSaveSlotMenu();
s32 formatTextEntry();
void *findEntryPayload();
s32 func_8002A644();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 lookupDataEntry();
extern s8 D_800BD690;
extern char D_800BD928[];
extern char D_80100198[];
extern u8 gPickupSavedByte;
extern char D_80100408[];
extern char gPickupSearchBox[];
extern s32 func_8001AC88;
extern s32 bindMenuItemRecord;

extern char D_800D2864[];
void func_8001E23C(void) {
    u8 *__base_D_801002AD;
    u8 *__repair_offset;
    s32 temp_v1;
    u8 var_s1;
    void *temp_v0;

    D_800BD690 = 1;
    temp_v0 = findEntryPayload(D_800BD928, 0x7E);
    if (temp_v0 != NULL) {
        __base_D_801002AD = &gPickupSavedByte;
        temp_v1 = (*__base_D_801002AD) * 0x18;
        var_s1 = *(D_80100198 + temp_v1);
        if (var_s1 >= 8U) {
            var_s1 = 7;
        }
        __repair_offset = __base_D_801002AD - 0x115;
        M2C_FIELD(temp_v0, void **, -0x18) = (void *) (temp_v1 + __repair_offset);
        formatTextEntry(temp_v0, D_800D2864, lookupDataEntry((unsigned short)(var_s1 + 0x96)));
        func_8002A644(gPickupSearchBox, D_80100408, 0x1A4, 0xB, 0x1E, 0xB4, 0x34, 0xB, 1, &bindMenuItemRecord, &func_8001AC88);
        refreshSaveSlotMenu(var_s1);
        func_8002A9A8(gPickupSearchBox, (*__base_D_801002AD));
        func_8002AC04(gPickupSearchBox, 1);
    }
}
