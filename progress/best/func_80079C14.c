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

s32 func_80002BD0();
extern char D_800C470A[];

void func_80079C14(void *arg0) {
    s32 var_a1;
    u8 temp_v1;
    void *temp_s0;

    temp_v1 = *(D_800C470A + (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8));
    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {                              /* irregular */
    default:
        var_a1 = 0x1FC;
block_10:
        func_80002BD0(arg0, var_a1);
        break;
    case 3:
        var_a1 = 0x1FC;
        goto block_10;
    case 2:
        var_a1 = 0x1FB;
        if (M2C_FIELD(temp_s0, s32 *, 0x88) & 0x40000000) {
            var_a1 = 0x1FC;
        }
        {
        func_80002BD0(arg0, var_a1);break;}
    }
    M2C_FIELD(temp_s0, s8 *, 0x7F) = 0;
}
