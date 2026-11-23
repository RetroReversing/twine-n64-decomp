#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_8008C1B0(u32);
void func_800968A4(u8, u8, u8);
void func_8009876C(void *, s32);
s32 func_800988D8(void *);
void func_80099B64(void *);
extern u8 D_8010D724[];
extern u8 D_8010D734[];
extern u8 D_801176E8;
s32 func_8008CEB0(s32 arg0, u8 arg1, u8 arg2) {
u8 sp17;
u8 sp1F;
u8 *var_s1;
u8 *var_s6;
s32 var_s7;
u8 *var_s0;
s16 temp_fp;
s32 temp_a0;
s32 temp_a1_2;
s32 temp_a2;
s32 var_s4;
s32 var_s5;
u16 temp_a1;
u32 var_s3;
u8 temp_a3;
void *temp_s2;
var_s4 = -1;
var_s6 = D_8010D724;
var_s3 = 0;
sp17 = arg1;
sp1F = arg2;
if (var_s3 < D_801176E8) {
temp_fp = arg0 & 0xFF;
var_s0 = D_8010D724 + 0x24;
var_s7 = 0;
do {
            if ((M2C_FIELD(var_s0, s32 *, 0x3C) != -1) && (M2C_FIELD(var_s0, u8 *, 0x26) == sp17) && (M2C_FIELD(var_s0, u8 *, 0x27) == sp1F)) {
                temp_a0 = M2C_FIELD(var_s0, s32 *, 0x0);
                if ((temp_a0 & 0x10) && ((temp_a0 & 0x40000008) != 8) && (func_8008C1B0(var_s3) & 0xFF)) {
                    temp_a2 = M2C_FIELD(var_s0, s8 *, 0x9C) << 0x10;
                    M2C_FIELD(var_s0, s8 *, 0x9D) = (s8) M2C_FIELD(var_s0, u16 *, 0x2C);
                    temp_a3 = M2C_FIELD(var_s0, u8 *, 0x2B);
                    temp_s2 = var_s7 + D_8010D724;
                    temp_a1 = M2C_FIELD(var_s0, u16 *, 0x2C);
                    var_s1 = var_s6;
                    M2C_FIELD(var_s0, s16 *, 0x2A) = temp_fp;
                    M2C_FIELD(var_s0, s8 *, 0x9C) = 0;
                    M2C_FIELD(var_s0, s32 *, 0x68) = 0;
                    M2C_FIELD(var_s0, u16 *, 0x2C) = (u16) (temp_fp + (M2C_FIELD(var_s0, u8 *, 0x2D) - temp_a3));
                    temp_a1_2 = (temp_a1 << 0x10) + temp_a2 / 100;
                    M2C_FIELD(var_s0, s32 *, 0x0) = (s32) (M2C_FIELD(var_s0, s32 *, 0x0) | 0x80800);
                    M2C_FIELD(var_s0, s32 *, 0x70) = temp_a1_2;
                    func_8009876C(temp_s2, temp_a1_2);
                    if (var_s4 == -1) {
                        M2C_FIELD(var_s1, s32 *, 0x10) = var_s4;
                        M2C_FIELD(var_s1, s32 *, 0x14) = var_s4;
                        var_s4 = func_800988D8(temp_s2);
                    } else {
                        { s32 *q; q = (s32 *)(D_8010D734 + ((var_s5 & 0xFF) * 0x1A0)); *q = M2C_FIELD(var_s1, s32 *, 0x60); }
M2C_FIELD(var_s1, s32 *, 0x14) = var_s5;
                    }
  do { do { var_s5 = M2C_FIELD(var_s1, s32 *, 0x60); } while (0); } while (0);
                }
            }
var_s7 += 0x1A0;
var_s3 += 1;
var_s0 += 0x1A0;
var_s6 += 0x1A0;
} while (var_s3 < (u8) D_801176E8);
}
if (var_s4 != -1) {
func_80099B64(var_s1);
func_800968A4(M2C_FIELD(var_s1, u8 *, 0x4A), M2C_FIELD(var_s1, u8 *, 0x4B), M2C_FIELD(var_s1, u8 *, 0x51));
}
return var_s4;
}
