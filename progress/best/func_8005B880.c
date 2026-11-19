/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8005B5A8();
extern s32 D_800C4420;
extern s32 D_800C4424;
extern void *D_80108788;

void func_8005B880(u32 arg0, void *arg1, s32 *arg2, s32 *arg3) {
    char *var_a2;
    void *var_a1;
    register char *var_a3;
    long var_t1;
    s32 var_v0;
    u16 temp_v1;
    unsigned var_a0;
    unsigned long var_t0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    var_a3 = arg3;
    var_t1 = 0;
    if ((D_80108788 != NULL) && (var_a1 = D_80108788, temp_v1 = (*(u16 *)((char *)(var_a1) + 0x78)), ((0x13 > temp_v1) != 0))) {
        var_v0 = 0;
        if ((short)temp_v1 >= 0x11) {
            var_v0 = 0;
            if ((*(s16 *)((char *)(var_a1) + 0x7A)) == 0) {
                var_t0 = 0;
                var_a3 = &D_800C4424;
                var_a2 = &D_800C4420;
                __repair_rows: {
                    var_a0 = (*(u32 *)((char *)((*(void **)((char *)(var_a1) + 0x70))) + 0x30));
                    if ((((var_a0 >> 4) & 0xFFFF) == *(s32 *)var_a2) && ((var_a0 >> 0x14) == *(s32 *)var_a3)) {
                        var_t1 = 1;
                        if ((*(s32 *)((char *)((*(void **)((char *)(var_a1) + 0x6C))) + 0x2C)) & 0x08000000) {
                            (*(s32 *)((char *)(var_a1) + 0x60)) |= 0x08000000;
                        }
                    }
                    var_a3 += 4;
                    var_a2 += 4;
                    var_t0 += 1;
                }
if (var_t0 == 0) goto __repair_rows;
                goto block_10;
            }
        }
    } else {
block_10:
        var_v0 = var_t1;
    }
    if (!var_v0) {
        func_8005B5A8(var_a0, var_a1, var_a2);
    }
}
