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

s32 func_80081CC0();
s32 memset();
extern char D_80115088[];
extern char gSlotMarkerActive[];
extern char D_8011508A[];
extern char sBonusSlots[];
extern char D_8011508C[];
extern char D_8011508D[];
extern char D_8011508E[];
extern char D_8011508F[];
extern char D_80115090[];
extern char D_80115092[];

void resetSlotState(s32 arg0) {
    s32 temp_s0;

    temp_s0 = arg0 * 0xA0;
    memset(temp_s0 + D_80115088, 0, 0xA0);
    *(D_80115088 + temp_s0) = 0;
    *(gSlotMarkerActive + temp_s0) = 1;
    *(D_8011508C + temp_s0) = 1;
    *(D_8011508A + temp_s0) = 0;
    *(sBonusSlots + temp_s0) = 0;
    *(D_8011508D + temp_s0) = 1;
    *(D_80115090 + temp_s0) = 1;
    *(D_8011508F + temp_s0) = 1;
    *(D_8011508E + temp_s0) = 1;
    *(s16 *)(D_80115092 + temp_s0) = 0;
    func_80081CC0(arg0);
}
