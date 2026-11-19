extern u8 D_801096E8;
extern u32 D_801096EC;
extern u32 D_801096F0;
extern u32 D_801096F4;
extern u32 D_801096F8;
extern u32 D_801096FC;
extern u8 D_801176E8;
u32 func_8008C6CC(s32);
void func_8008C6F4(s32, s32);

#define AT(T, sym, off) (*(T *)((u8 *)&(sym) + (off)))

void func_80093268(void) {
    register u32 *__base_D_801096FC;
    u32 *__base_D_801096F0;
int __repair_literal;

    register s32 var_s3;
    long var_s0;
    register u32 *var_s2;
    register u32 temp_v0;
    u32 temp_t0;
    register u32 temp_v1;
    register unsigned long temp_a2;
    unsigned int var_a0;
    register unsigned long var_a1;

    var_s3 = 0;
__repair_literal = 0;

    if ((s32) D_801176E8 > __repair_literal) {
        var_s2 = &D_801096F8;
        var_s0 = 0;
        do {
            if (AT(u8, (*(u8 *)0x801096f8), var_s0) == 1) {
                temp_v0 = func_8008C6CC(var_s3);
                temp_t0 = *var_s2;
                if (temp_t0 != temp_v0) {
                    if (temp_t0 < temp_v0) {
                        __base_D_801096F0 = &D_801096F0;
                        __base_D_801096FC = &D_801096FC;
                        if (((s32 (*)(s32, s32, s32, s32, s32)) AT(u32, (*(u32 *)0x801096f8), var_s0))(AT(u32, (*__base_D_801096F0), var_s0) + (temp_t0 * 2), temp_v0 - temp_t0, 0, 0, AT(u32, (*__base_D_801096FC), var_s0)) & 0xFF) {
                            var_a0 = AT(u32, (*__base_D_801096F0), var_s0) + (*var_s2 * 2);
                            var_a1 = (s32)temp_v0 - *var_s2;
                            func_8008C6F4(var_a0, var_a1);
                        }
                    } else {
                        temp_a2 = AT(u32, (*__base_D_801096F0), var_s0);
                        if (((s32 (*)(s32, s32, s32, s32, s32)) AT(u32, D_801096EC, var_s0))(temp_a2 + (temp_t0 * 2), AT(u32, D_801096F4, var_s0) - temp_t0, temp_a2, temp_v0, AT(u32, (*__base_D_801096FC), var_s0)) & 0xFF) {
                            temp_v1 = *var_s2;
                            func_8008C6F4(AT(u32, (*__base_D_801096F0), var_s0) + (temp_v1 * 2), AT(u32, D_801096F4, var_s0) - temp_v1);
                            func_8008C6F4(AT(u32, (*__base_D_801096F0), var_s0), temp_v0);
                        }
                    }
                }
                *var_s2 = temp_v0;
            }
            var_s0 += 0x18;
            var_s2 += 0x18 / 4;
            var_s3 += 1;
        } while (var_s3 < (s32) D_801176E8);
    }
}
