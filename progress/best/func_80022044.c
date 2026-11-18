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
s32 func_80026004();
s32 func_80029068();
s32 func_8002A700();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 func_8002ACB4();
s32 func_80087100();
extern char D_80100198[];
extern u8 D_801002AD;
extern void *D_80109BB0;
extern char D_8010A488[];

void func_80022044(void) {
    s32 temp_s0;
    u8 var_s1;

    func_80029068();
    if (M2C_FIELD(D_80109BB0, u8 *, 0x2D) != 0) {
        var_s1 = *(D_80100198 + (D_801002AD * 0x18));
        temp_s0 = M2C_FIELD(D_80109BB0, s32 *, 0x18) + 0x28;
        if (var_s1 >= 8U) {
            var_s1 = 7;
        }
        func_80026004(temp_s0, "%s", func_80087100((unsigned short)(var_s1 + 0x96)));
        func_8002A700(D_8010A488);
        func_80021CA0(var_s1);
        func_8002AC04(D_8010A488, 1);
        func_8002A9A8(D_8010A488);
        func_8002ACB4(D_8010A488);
    }
}
