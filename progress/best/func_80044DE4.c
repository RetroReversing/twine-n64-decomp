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

s32 func_800422F4();
s32 func_800426B8();
s32 func_80044D28();
extern u16 D_800BD680;
extern u16 D_800C2B50;
extern u16 D_800C2B54;
extern u16 D_800C2B5C;
extern u16 D_800C2B64;
extern u16 D_800C2B68;
extern u16 D_800C2B70;
extern u16 D_800C2B80;
extern u16 D_800C2B88;
extern u16 D_800C2B94;
extern u16 D_800C2BA0;
extern u16 D_800C2BA4;
extern u16 D_800C2BB0;
extern u16 D_800C2BB8;
extern u16 D_800C2BC0;
extern u16 D_800C2BCC;
extern u16 D_800C2BF4;
extern char D_800C447A[];
extern s32 D_80102ED8;
extern void *D_80109688;
extern u8 D_80112F6C;
extern u8 D_80112F6D;

void func_80044DE4(u32 arg0) {
    u16 sp10;
    u16 sp12;
    s16 sp46;
    s16 sp48;
    s16 sp4C;
    char *var_a0_2;
    char *var_a0_3;
    s16 var_v0;
    s16 var_v0_2;
    s32 var_a0_4;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    u16 *var_a0;
    char *var_a1;
    u16 temp_v0;

    sp10 = -1U;
    func_800422F4();
    func_800426B8(M2C_FIELD(D_80109688, s32 *, 8), arg0, 1);
    switch (arg0) {
    case 2:
        var_a0 = &D_800C2B54;
        break;
    case 20:
        var_a0 = &D_800C2B5C;
        break;
    case 16:
        var_a0 = &D_800C2B64;
        break;
    case 34:
        var_a0 = &D_800C2B68;
        break;
    case 25:
        var_a0 = &D_800C2B70;
        break;
    case 38:
        var_a0 = &D_800C2B80;
        break;
    case 1:
        var_a0 = &D_800C2B88;
        break;
    case 11:
        var_a0 = &D_800C2B94;
        break;
    case 41:
        var_a0 = &D_800C2BA0;
        break;
    case 40:
        var_a0 = &D_800C2BA4;
        break;
    case 28:
        var_a0 = &D_800C2BB0;
        break;
    case 18:
        var_a0 = &D_800C2BB8;
        break;
    case 29:
        var_a0 = &D_800C2BC0;
        break;
    case 33:
        var_a0 = &D_800C2BCC;
        break;
    case 36:
        var_a0 = &D_800C2B50;
        break;
    case 0:
    case 4:
    case 7:
    case 9:
    case 12:
    case 19:
    case 21:
    case 22:
    case 23:
    case 24:
    case 26:
    case 31:
    case 32:
    case 39:
        var_v1 = 0x1B;
        var_a0_2 = &sp46;
        var_v0 = 0x1FA;
        do {
            *(s16 *)var_a0_2 = var_v0;
            var_a0_2 -= 2;
            var_v1 -= 1;
            var_v0 -= 1;
        } while (var_v1 >= 0);
        sp48 = -1;
        func_80044D28(&sp10);
        var_a0 = &D_800C2BF4;
        break;
    default:
        var_a0 = NULL;
        break;
    }
    if (var_a0 != NULL) {
        func_80044D28(var_a0);
    }
    var_v1_2 = 0x1B;
    if (D_80112F6C != 0) {
        var_a0_3 = &sp46;
        var_v0_2 = 0x1FA;
        do {
            *(s16 *)var_a0_3 = var_v0_2;
            var_a0_3 -= 2;
            var_v1_2 -= 1;
            var_v0_2 -= 1;
        } while (var_v1_2 >= 0);
        sp48 = -1;
        func_80044D28(&sp10);
    }
    var_v1_3 = 0;
    if (D_80112F6D != 0) {
        var_a1 = &sp10;
        var_a0_4 = 0;
        do {
            temp_v0 = *(u16 *)(D_800C447A + var_a0_4);
            var_a0_4 += 0x10;
            var_v1_3 += 1;
            *(u16 *)var_a1 = temp_v0;
            var_a1 += 2;
        } while (var_v1_3 < 0x1E);
        sp4C = -1;
        func_80044D28(&sp12, var_a1);
    }
    if (D_80102ED8 != 0) {
        func_80044D28(&D_800BD680);
    }
}
