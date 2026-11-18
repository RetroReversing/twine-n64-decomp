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

f32 func_800461D4();
s32 func_80077960();
s32 func_80078274();
s32 func_8007BAF8();
extern char D_80109A60[];

s32 func_8007835C(void *arg0) {
    s32 var_s3;
    u16 temp_v1;
    void *temp_s0;
    void *var_s1;

    var_s1 = *M2C_FIELD(arg0, void ***, 0x20);
    var_s3 = 0;
    if (var_s1 != NULL) {
        do {
            temp_v1 = M2C_FIELD(var_s1, u16 *, 0x78);
            if (((s32) temp_v1 < 0x61) && ((s32) temp_v1 >= 0x5E) && (*(D_80109A60 + M2C_FIELD(M2C_FIELD(var_s1, void **, 0x6C), u16 *, 0x34)) == 0)) {
                temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
                M2C_FIELD(temp_s0, s32 *, 0x88) |= 0x02000000;
                if ((func_8007BAF8(arg0, var_s1 + 0x24, 6, 0xB) << 0x18) == 0) {
                    var_s3 = 1;
                    M2C_FIELD(temp_s0, s32 *, 0x18) = (s32) M2C_FIELD(var_s1, s32 *, 0x24);
                    M2C_FIELD(temp_s0, s32 *, 0x1C) = (s32) M2C_FIELD(var_s1, s32 *, 0x28);
                    M2C_FIELD(temp_s0, s32 *, 0x20) = (s32) M2C_FIELD(var_s1, s32 *, 0x2C);
                    M2C_FIELD(temp_s0, f32 *, 0x38) = func_800461D4(arg0 + 0x24, temp_s0 + 0x18);
                    func_80077960(arg0, 0x87);
                } else {
                    func_80078274(arg0);
                    if (M2C_FIELD(arg0, s16 *, 0x7A) != 0xB) {
                        var_s3 = 1;
                    }
                }
            }
            var_s1 = M2C_FIELD(var_s1, void **, 0);
        } while (var_s1 != NULL);
    }
    return var_s3;
}
