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

M2C_UNK func_80016160(s32, s32 *, s32 *, s32 *);    /* extern */
M2C_UNK func_800283B0();                            /* extern */
M2C_UNK func_8002B02C(M2C_UNK *);                   /* extern */
M2C_UNK func_8002B050(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_8002B150(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002EFD8(void *, void *);              /* extern */
M2C_UNK func_8002F068(void *, void *);              /* extern */
M2C_UNK func_8002F240(void *, void *);              /* extern */
M2C_UNK func_8002F2EC(void *, void *);              /* extern */
s32 func_8002F37C(void *);                          /* extern */
s32 func_8002F560(void *);                          /* extern */
M2C_UNK func_8002F718();                            /* extern */
M2C_UNK func_8002FBD4(void *, M2C_UNK);             /* extern */
M2C_UNK func_8003099C(u8, u8);                      /* extern */
s32 func_80081730();                                /* extern */
M2C_UNK func_80087E74();                            /* extern */
extern u16 D_800BFC92;
extern M2C_UNK D_800BFD08;
extern s32 D_800BFD74;
extern s8 D_800CEEB1;
extern M2C_UNK D_800E1584;
extern u8 D_80102EDC;
extern u8 D_80102EE0;
extern u8 D_80102EE8;
extern M2C_UNK D_80102EFC;

void func_8002F868(void *arg0, void *arg1) {
    s16 temp_v1;
    s32 *var_a2;
    s32 *var_a3;
    u16 temp_v1_2;
    void *temp_t0;

    func_8002F718();
    temp_v1 = M2C_FIELD(arg1, s16 *, 0x7A);
    switch (temp_v1) {
    case 0:
        func_8002EFD8(arg0, arg1);
block_23:
        func_8002F2EC(arg0, arg1);
        return;
    case 5:
        func_8002F068(arg0, arg1);
        goto block_23;
    case 6:
        if (func_8002F37C(arg0) & 0xFF) {
            func_8002FBD4(arg1, 4);
        } else {
        default:
        }
        goto block_23;
    case 4:
        func_8002F37C(arg0);
        if (D_80102EDC != 0) {
            func_8002B050(&D_800E1584, 1);
        }
        if (func_80081730() & 0xFFFF) {
block_19:
            func_8002B150(&D_800E1584, 0, 0);
        }
        goto block_23;
    case 3:
        func_8002FBD4(arg1, 1);
        goto block_23;
    case 1:
        if (func_8002F560(arg0) & 0xFF) {
            func_8002FBD4(arg1, 2);
        }
        goto block_23;
    case 7:
        if (func_8002F560(arg0) & 0xFF) {
            var_a3 = &D_800BFD74;
            temp_v1_2 = D_800BFC92 + 1;
            var_a2 = ((temp_v1_2 & 1) * 0x24) + &D_800BFD08;
            temp_t0 = var_a2 + 0x20;
            D_800BFC92 = temp_v1_2;
            __repair_rows: {
                M2C_FIELD(var_a3, s32 *, 0) = M2C_FIELD(var_a2, s32 *, 0);
                M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
                M2C_FIELD(var_a3, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 8);
                M2C_FIELD(var_a3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0xC);
                var_a2 += 0x10;
                var_a3 += 0x10;
            }
if (var_a2 != temp_t0) goto __repair_rows;
            *var_a3 = *var_a2;
            D_800BFC92 += 1;
            func_80016160(M2C_FIELD(arg0, s32 *, 0x2C), &D_800BFD74, var_a2, var_a3);
            func_8002FBD4(arg1, 0);
        }
        goto block_23;
    case 8:
        func_8002F240(arg0, arg1);
        goto block_23;
    case 9:
        func_8002F37C(arg0);
        goto block_19;
    case 11:
        if (func_8002F560(arg0) & 0xFF) {
            func_8002B02C(&D_80102EFC);
            func_800283B0();
            D_800CEEB1 = 2;
            func_80087E74();
            func_8003099C(D_80102EE0, D_80102EE8);
            return;
        }
        goto block_23;
    }
}
