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
f32 func_80045E34();
extern s32 D_8011F068;
extern u32 D_8011F06C;

u32 func_80117AFC(void *arg0) {
    struct {
        s32 f10;
        f32 f14;
        s32 f18;
    } __repair_frame;
    f32 temp_fv0;
    f32 var_fs0;
    s32 var_s1;
    u32 var_s0;
    u32 var_s3;

    var_fs0 = 65536.0f;
    var_s0 = 0;
    var_s3 = 0;
    if (D_8011F06C != 0) {
        var_s1 = 0;
        do {
            __repair_frame.f10 = *(s32 *)((u8 *)arg0 + 0x24);
            __repair_frame.f14 = *(f32 *)((u8 *)arg0 + 0x28);
            __repair_frame.f18 = *(s32 *)((u8 *)arg0 + 0x2C);
            if ((u32)(*(u16 *)((u8 *)arg0 + 0x78) - 2) < 2U) {
                __repair_frame.f14 -= *(f32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0x38);
            }
            temp_fv0 = func_80045E34(&__repair_frame, *(s32 *)(var_s1 + D_8011F068 + 0x10));
            if (temp_fv0 < var_fs0) {
                var_fs0 = temp_fv0;
                var_s3 = var_s0;
            }
            var_s0 += 1;
            var_s1 += 0x58;
        } while (var_s0 < D_8011F06C);
    }
    return var_s3;
}
