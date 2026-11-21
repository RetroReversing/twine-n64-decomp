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

s32 requestSound();
s32 func_8002B050();
s32 func_8002B180();
s16 func_8002B278();
s16 strlen();
extern s32 D_800BD65C;
extern s32 D_800BD66C;
extern u8 D_801002AC;
extern char D_801002CC[];
extern s16 D_801002D0;
extern u8 D_80102EDD;
extern char D_8011F0D4[];
extern s32 D_8011F3A8;
extern void *D_8011F3B8;

void func_8011C674(s16 arg0) {
    s32 var_v0;
    u8 temp_v0;
    void *temp_s1;

    if (D_80102EDD != 0) {
        func_8002B050(D_801002CC, arg0);
        if ((func_8002B278(D_801002CC - 8) << 0x10) != 0) {
            if (D_801002AC == 0) {
                temp_v0 = (func_8002B278(D_801002CC) << 0x10) < 1;
                D_801002AC = temp_v0;
                if (temp_v0 & 0xFF) {
                    D_8011F3A8 = 0x1E;
                }
            }
            if ((func_8002B278(D_801002CC) < 0xB) && (D_801002D0 == 0)) {
                requestSound(0x123);
            }
            temp_s1 = D_8011F3B8;
            if (temp_s1 != NULL) {
                if (func_8002B278(D_801002CC) < 0x3C) {
                    var_v0 = D_800BD65C;
                } else {
                    var_v0 = D_800BD66C;
                }
                M2C_FIELD(temp_s1, s32 *, 0x10) = var_v0;
                func_8002B180(D_801002CC, D_8011F0D4);
                M2C_FIELD(temp_s1, s16 *, 0x1C) = strlen(D_8011F0D4);
            }
        }
    }
}
