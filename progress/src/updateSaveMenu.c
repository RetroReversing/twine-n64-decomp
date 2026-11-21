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

s32 func_80023EC0();
u16 func_800248B4();
u16 func_8002495C();
u16 func_80024AD0();
s32 findEntryById();
s32 func_800263B8();
s32 func_80026424();
s32 updateActiveMenuState();
s32 func_80029C08();
s32 func_8002CC14();
extern u16 sSaveMenuAction;
extern u8 sSaveMenuSlot;
extern s8 sSaveMenuRefresh;
extern s32 sActiveMenu;
extern char D_80107EA8[];
extern u8 D_80107EC0;
extern void *gMenuState;

typedef struct { unsigned char pad[16]; int value; } __repair_field_10;
void updateSaveMenu(void) {
    s32 temp_a0;
    s32 temp_v1;

    sSaveMenuRefresh = 1;
    if (findEntryById(((__repair_field_10 *)gMenuState)->value, 0x54) != 0) {
        if (M2C_FIELD(gMenuState, u8 *, 0x2E) == 0) {
            M2C_FIELD(M2C_FIELD(gMenuState, void **, 0x18), s8 *, 0x24) = (s8) ((sSaveMenuSlot + func_800263B8(((__repair_field_10 *)gMenuState)->value, 0x54)) - 1);
        }
    }
    if ((M2C_FIELD(gMenuState, u8 *, 0x2C) != 0) && (M2C_FIELD(gMenuState, u8 *, 0x2E) == 0)) {
        func_80023EC0(sSaveMenuAction);
        temp_a0 = sSaveMenuAction & 0xE000;
        if (sSaveMenuAction & 0x1000) {
            updateActiveMenuState(temp_a0);
            if (func_8002CC14() & 0xFFFF) {
                func_80026424(sActiveMenu, 0x18);
            }
        } else {
            temp_v1 = sSaveMenuAction & 0xFFF;
            switch (temp_v1) {                      /* irregular */
            case 1:
                sSaveMenuAction = func_800248B4(temp_a0, D_80107EC0);
                return;
            case 2:
                sSaveMenuAction = func_8002495C(temp_a0, D_80107EC0);
                return;
            case 3:
                sSaveMenuAction = func_80024AD0(temp_a0, D_80107EC0);
                return;
            }
        }
    } else {
        updateActiveMenuState();
        func_80029C08(D_80107EA8, 2, 0);
        func_80023EC0(sSaveMenuAction);
    }
}
