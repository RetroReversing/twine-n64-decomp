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

s32 func_80021CA0();
s32 formatTextEntry();
s32 updateActiveMenuState();
s32 func_8002A700();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 func_8002ACB4();
s32 lookupDataEntry();
extern char D_80100198[];
extern u8 D_801002AD;
extern void *gMenuState;
extern char D_8010A488[];

extern char D_800D2AA0[];
void func_80022044(void) {
    u8 *__base_D_801002AD;
    s32 temp_s0;
    u8 var_s1;

    updateActiveMenuState();
    if (M2C_FIELD(gMenuState, u8 *, 0x2D) != 0) {
        temp_s0 = M2C_FIELD(gMenuState, s32 *, 0x18) + 0x28;
        __base_D_801002AD = &D_801002AD;
        var_s1 = *(D_80100198 + ((*__base_D_801002AD) * 0x18));
        if (var_s1 >= 8U) {
            var_s1 = 7;
        }
        formatTextEntry(temp_s0, D_800D2AA0, lookupDataEntry((unsigned short)(var_s1 + 0x96)));
        func_8002A700(D_8010A488);
        func_80021CA0(var_s1);
        func_8002AC04(D_8010A488, 1);
        func_8002A9A8(D_8010A488, (*__base_D_801002AD));
        func_8002ACB4(D_8010A488);
    }
}
