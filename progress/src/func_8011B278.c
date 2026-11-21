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

s32 getSaveSlotIndex();
s32 func_8002B000();
void *heapAllocTagged();
extern char D_801001A1[];
extern u8 gSceneType;
extern u8 gSaveKeyRelaxed;
extern s32 D_801002A8;
extern s8 D_801002AE;

void func_8011B278(void *arg0, u8 arg1) {
    void *temp_v0;

    temp_v0 = heapAllocTagged(0x14, 0x2C);
    M2C_FIELD(arg0, void **, 0xB4) = temp_v0;
    M2C_FIELD(temp_v0, s16 *, 0xC) = 0;
    func_8002B000(M2C_FIELD(arg0, void **, 0xB4), 0x1E);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), s16 *, 0xE) = 0;
    D_801002AE = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), s8 *, 0x10) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), s32 *, 8) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), s8 *, 0x11) = 0;
    if (gSceneType == 7) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), s8 *, 0x11) = (s8) D_801002A8;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), s16 *, 0xC) = (s16) D_801002A8;
    }
    if (gSaveKeyRelaxed != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), u8 *, 0x12) = (u8) *(D_801001A1 + ((getSaveSlotIndex(arg1 & 0xFF) & 0xFFFF) * 0x18));
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), u8 *, 0x12) = 2U;
}
