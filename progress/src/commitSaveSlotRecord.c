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

s32 cache_release_block();
s32 func_80022BB8();
s32 func_8002A700();
extern u8 D_800B7CF0;
extern s8 D_801002AD;
extern u8 D_801007C1;
extern u8 D_80102EB0;
extern u8 D_80104310;
extern u8 D_80108960;
extern u8 D_80109E20;
extern u8 D_8010A394;
extern char D_8010A488[];
extern u8 D_8010D2B1;
extern u8 D_8010D454;
extern char D_80115088[];
extern char D_80115089[];
extern char D_8011508A[];
extern char D_8011508C[];
extern char D_8011508D[];
extern char D_8011508E[];
extern char D_8011508F[];
extern char D_80115090[];

void func_80022118(void) {
    func_8002A700(D_8010A488);
    *(D_80115088 + (D_800B7CF0 * 0xA0)) = D_80109E20;
    *(D_80115089 + (D_800B7CF0 * 0xA0)) = D_8010D454;
    *(D_8011508A + (D_800B7CF0 * 0xA0)) = D_8010D2B1;
    *(D_80115090 + (D_800B7CF0 * 0xA0)) = D_80102EB0;
    *(D_8011508D + (D_800B7CF0 * 0xA0)) = D_801007C1;
    *(D_8011508C + (D_800B7CF0 * 0xA0)) = D_8010A394;
    *(D_8011508F + (D_800B7CF0 * 0xA0)) = D_80108960;
    *(D_8011508E + (D_800B7CF0 * 0xA0)) = D_80104310;
    D_801002AD = 0;
    func_80022BB8();
    cache_release_block();
}
