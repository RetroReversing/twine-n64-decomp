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

s32 func_8004478C();
f32 func_80045540();
s32 func_80045CF8();
s32 func_800462C4(void *, f32, f32, f32);
void *func_800617D8(s32, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);
f32 func_800829A0(f32);
f32 func_800829C8(f32);
s32 func_80083A6C();
extern char D_800C469C[];
extern u8 D_801002D4;
extern s32 D_80102ED8;
extern char D_80109688[];

typedef struct { f32 x, y, z; } Vec3;
void func_80067F40(void *arg0, void *arg1) {
s32 __repair_operand;

    f32 m[3][3];
    f32 pad[3];
    f32 ang[2];
    f32 v[3];
    f32 d[3];
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    f32 temp_ft0;
    f32 temp_ft1;
    f32 temp_fv1;
    s32 temp_s0;
    void **temp_s0_2;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_s2;
    void *temp_v0;
    void *var_s0;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    temp_s0 = M2C_FIELD(temp_s1, s8 *, 0x182);
    temp_s2 = (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8) + D_800C469C;
    if ((D_80102ED8 == 0) || (D_801002D4 != 0)) {
        if (M2C_FIELD(temp_s2, u8 *, 0x9E) != 0xFF) {
            M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xA8), void **, 0x68), s32 *, 0x78) = func_8004478C(M2C_FIELD(temp_s2, s16 *, 0x48), M2C_FIELD(temp_s2, s16 *, 0x40));
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0x74) = func_8004478C(M2C_FIELD(temp_s2, s16 *, 0x4A), M2C_FIELD(temp_s2, s16 *, 0x40));
        if (((M2C_FIELD(temp_s2, s32 *, 0x60) & 0xC00) != 0) & (arg1 != NULL)) {
            temp_s0_2 = (temp_s0 * 4) + D_80109688;
            temp_s1_2 = M2C_FIELD(temp_s1, void **, 0xA8);
            ang[0] = -(M2C_FIELD(*temp_s0_2, f32 *, 0x34) * 651.8986f);
            ang[1] = M2C_FIELD(*temp_s0_2, f32 *, 0x38) * 651.8986f;
            m[0][0] = func_800829C8(ang[1]);
            temp_fs0 = func_800829A0(ang[0]);
            m[0][1] = -temp_fs0 * func_800829A0(ang[1]);
            temp_fs0_2 = func_800829A0(ang[1]);
            temp_fs0_3 = temp_fs0_2 * func_800829C8(ang[0]);
            m[1][0] = 0.0f;
            m[0][2] = temp_fs0_3;
            m[1][1] = func_800829C8(ang[0]);
            m[1][2] = func_800829A0(ang[0]);
            m[2][0] = -func_800829A0(ang[1]);
            temp_fs0_4 = func_800829C8(ang[1]);
            m[2][1] = -(temp_fs0_4 * func_800829A0(ang[0]));
            temp_fs0_5 = func_800829C8(ang[0]);
            m[2][2] = temp_fs0_5 * func_800829C8(ang[1]);
            __repair_operand = M2C_FIELD(M2C_FIELD(temp_s1_2, void **, 0x68), s32 *, 4);
            temp_v0 = (M2C_FIELD(temp_s2, u16 *, 0x90) * 0xC) + __repair_operand;
            *(Vec3 *) v = *(Vec3 *) temp_v0;
            v[1] = -v[1];
            v[0] = -v[0];
            func_80083A6C(m, v);
            v[0] += M2C_FIELD(*temp_s0_2, f32 *, 0x10);
            v[1] += M2C_FIELD(*temp_s0_2, f32 *, 0x14);
            v[2] += M2C_FIELD(*temp_s0_2, f32 *, 0x18);
            var_s0 = NULL;
            temp_fs0_6 = func_80045540(v, arg1);
            if (M2C_FIELD(temp_s2, s32 *, 0x60) & 0x800) {
                var_s0 = func_800617D8(M2C_FIELD(arg0, s32 *, 0x20), v, 0, 0, 1.0f, 1.0f, 0x16, 0x1B, 0x22, 0x8020, 0x80808021);
                M2C_FIELD(var_s0, s32 *, 0x58) |= 0x100000;
            }
            if (M2C_FIELD(temp_s2, s32 *, 0x60) & 0x400) {
                var_s0 = func_800617D8(M2C_FIELD(arg0, s32 *, 0x20), v, 0, 0, 1.0f, 1.0f, func_80045CF8(4) + 0x17, 0x1B, 0x22, 0x8080, 0x80808081);
                M2C_FIELD(var_s0, s32 *, 0x58) |= 0x100000;
            }
            if (var_s0 != NULL) {
                M2C_FIELD(var_s0, f32 *, 0x54) = temp_fs0_6;
                M2C_FIELD(var_s0, s32 *, 0x58) |= 0x8000;
                temp_ft1 = v[0] - M2C_FIELD(arg1, f32 *, 0);
                d[0] = temp_ft1;
                temp_ft0 = v[1] - M2C_FIELD(arg1, f32 *, 4);
                d[1] = temp_ft0;
                temp_fv1 = v[2] - M2C_FIELD(arg1, f32 *, 8);
                d[2] = temp_fv1;
                func_800462C4(var_s0 + 0x3C, temp_ft1, temp_ft0, temp_fv1);
                M2C_FIELD(var_s0, s32 *, 0x44) = 0;
                M2C_FIELD(var_s0, f32 *, 0x3C) = (f32) -M2C_FIELD(var_s0, f32 *, 0x3C);
            }
        }
    }
}
