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
s32 func_800262A8();
s32 func_800263B8();
s32 func_80026424();
s32 func_80029068();
s32 func_80029C08();
s32 func_8002CC14();
extern u16 D_800BD558;
extern u8 D_800BD559;
extern s8 D_800BD55A;
extern s32 D_80102F2C;
extern char D_80107EA8[];
extern u8 D_80107EC0;
extern void *D_80109BB0;

typedef struct { unsigned char pad[16]; int value; } __repair_field_10;
void func_80024BDC(void) {
    s32 temp_a0;
    s32 temp_v1;

    D_800BD55A = 1;
    if (func_800262A8(((__repair_field_10 *)D_80109BB0)->value, 0x54) != 0) {
        if (M2C_FIELD(D_80109BB0, u8 *, 0x2E) == 0) {
            M2C_FIELD(M2C_FIELD(D_80109BB0, void **, 0x18), s8 *, 0x24) = (s8) ((D_800BD559 + func_800263B8(((__repair_field_10 *)D_80109BB0)->value, 0x54)) - 1);
        }
    }
    if ((M2C_FIELD(D_80109BB0, u8 *, 0x2C) != 0) && (M2C_FIELD(D_80109BB0, u8 *, 0x2E) == 0)) {
        func_80023EC0(D_800BD558);
        temp_a0 = D_800BD558 & 0xE000;
        if (D_800BD558 & 0x1000) {
            func_80029068(temp_a0);
            if (func_8002CC14() & 0xFFFF) {
                func_80026424(D_80102F2C, 0x18);
            }
        } else {
            temp_v1 = D_800BD558 & 0xFFF;
            switch (temp_v1) {                      /* irregular */
            case 1:
                D_800BD558 = func_800248B4(temp_a0, D_80107EC0);
                return;
            case 2:
                D_800BD558 = func_8002495C(temp_a0, D_80107EC0);
                return;
            case 3:
                D_800BD558 = func_80024AD0(temp_a0, D_80107EC0);
                return;
            }
        }
    } else {
        func_80029068();
        func_80029C08(D_80107EA8, 2, 0);
        func_80023EC0(D_800BD558);
    }
}
