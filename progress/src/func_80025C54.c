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

extern unsigned short D_800BD562;
s32 func_80026424();
s32 updateActiveMenuState();
s32 func_800294E4();
s32 func_8002CBF4();
extern char D_800BD560[];
extern s8 D_80102EDC;
extern s32 sActiveMenu;
extern void *gMenuItems;

typedef struct { unsigned char pad_0[20]; unsigned short field_14; unsigned char pad_16[22]; unsigned char field_2C; unsigned char pad_2D[1]; unsigned char field_2E; signed char field_2F; } __repair_record_D_80109BB0;
void func_80025C54(void) {
    u16 temp_a0;

    if ((((__repair_record_D_80109BB0*)gMenuItems)->field_2C == 0) || (((__repair_record_D_80109BB0*)gMenuItems)->field_2E != 0)) {
        D_800BD562 = 3U;
        D_80102EDC = ((__repair_record_D_80109BB0*)gMenuItems)->field_14 == 1;
        updateActiveMenuState();
        return;
    }
    temp_a0 = D_800BD562;
    switch (temp_a0) {                              /* irregular */
    case 3:
        D_80102EDC = 0;
        if (!(func_8002CBF4() & 0xFFFF)) {
            D_800BD562 = 4U;
            return;
        }
        D_800BD562 = 3U;
        ((__repair_record_D_80109BB0*)gMenuItems)->field_2C = 0U;
        func_80026424(sActiveMenu, 0x18);
        return;
    case 4:
        ((__repair_record_D_80109BB0*)gMenuItems)->field_2F = 1;
        D_800BD562 = 3U;
        func_800294E4();
        ((__repair_record_D_80109BB0*)gMenuItems)->field_2C = 1U;
        return;
    }
}
