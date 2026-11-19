/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80015D40();
void *func_80016410();
s32 func_8003E6EC();
s32 func_80044670();
extern s32 *D_800CA31C;
extern f64 D_800D4170;
extern char D_80109A60[];
extern s8 D_80109B1E;

void *func_8005DC2C(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    register s16 var_v0;
    void *temp_s0;
    u16 temp_v0_2;
    register u16 var_a2;
    u16 var_a1;
    u8 temp_v1;
    unsigned var_v0_2;
    void *temp_v0;

    temp_v0 = func_80016410(0x50, arg0, arg1);
    if (temp_v0 != NULL) {
        temp_s0 = (*(void **)((char *)(temp_v0) + 0x6C));
        (*(s32 *)((char *)(temp_s0) + 0x4C)) &= ~0x40;
        temp_v1 = (*(u8 *)((char *)((*(void **)((char *)(arg2) + 0x24))) + 0x1E));
        switch (temp_v1) {                          /* irregular */
        default:
            var_v0 = 0x11;
            if (temp_v1 != 0x2D) {

            } else {
block_11:
                (*(s16 *)((char *)((unsigned short)temp_v0) + 0x78)) = var_v0;
            }
            break;
        case 0x2F:
            var_v0 = 0x12;
            goto block_11;
        case 0x8E:
            D_80109B1E = 1;
            var_v0 = 0x5F;
            goto block_11;
        case 0x90:
            D_80109B1E = 1;
            var_v0 = 0x60;
            goto block_11;
        }
        (*(u16 *)((char *)(temp_s0) + 0x34)) = (u16) (*(u16 *)((char *)(arg2) + 0x2C));
        (*(u16 *)((char *)(temp_s0) + 0x40)) = (u16) (*(u16 *)((char *)(arg2) + 0x2E));
        (*(s32 *)((char *)(temp_s0) + 0x2C)) = func_80015D40((*(u16 *)((char *)(arg2) + 0x34)));
        (*(u16 *)((char *)(temp_s0) + 0x36)) = (u16) (*(u16 *)((char *)(arg2) + 0x36));
        (*(u16 *)((char *)(temp_s0) + 0x38)) = (u16) (*(u16 *)((char *)(arg2) + 0x38));
        (*(u16 *)((char *)(temp_s0) + 0x3A)) = (u16) (*(u16 *)((char *)(arg2) + 0x30));
        (*(u16 *)((char *)(temp_s0) + 0x3C)) = (u16) (*(u16 *)((char *)(arg2) + 0));
        (*(u16 *)((char *)(temp_s0) + 0x3E)) = (u16) *(*(u16 **)((char *)(arg2) + 0x28));
        (*(s16 *)((char *)(temp_s0) + 0x42)) = 0;
        if ((*(u16 *)((char *)(temp_s0) + 0x3A)) == 1) {
            var_a2 = (*(u16 *)((char *)(temp_s0) + 0x3E));
            var_a1 = (*(u16 *)((char *)(temp_s0) + 0x3C)) + *(u16 *)(D_80109A60 + (*(u16 *)((char *)(temp_s0) + 0x34)));
        
        func_80044670(temp_v0, var_a1, (s16) var_a2);} else {
            var_a1 = (*(u16 *)((char *)(arg2) + 0));
            var_a2 = (u16) (s16) *(*(u16 **)((char *)(arg2) + 0x28));
        
        func_80044670(temp_v0, var_a1, (s16) var_a2);}
        if ((*(u16 *)((char *)(arg2) + 0x40)) == 0) {
            var_v0_2 = (*(s32 *)((char *)(temp_s0) + 0x4C)) | 0x80;
        } else {
            register var_v0_2 = (*(s32 *)((char *)(temp_s0) + 0x4C)) & ~0x80;
        }
        *(D_80109A60 + (*(u16 *)((char *)(temp_s0) + 0x34))) = (s8) (*(u16 *)((char *)(arg2) + 0x32));
        (*(s32 *)((char *)(temp_s0) + 0x4C)) = var_v0_2;
        (*(void **)((char *)(temp_s0) + 4)) = arg3;
        temp_v0_2 = (*(u16 *)((char *)(arg2) + 4));
        (*(u16 *)((char *)(temp_s0) + 0x44)) = temp_v0_2;
        if (!temp_v0_2) {
            (*(u16 *)((char *)(temp_s0) + 0x44)) = 0x3CU;
        }
        (*(s8 *)((char *)(temp_s0) + 0x4B)) = 0;
        (*(s32 *)((char *)(temp_s0) + 0x4C)) = (s8) ((*(u8 *)((char *)(arg2) + 3)) - 1);
        (*(f32 *)((char *)(temp_s0) + 8)) = 1.0f;
        if (arg3 != NULL) {
            (*(s32 *)((char *)(temp_v0) + 0x24)) = (s32) (*(s32 *)((char *)(arg3) + 0));
            (*(s32 *)((char *)(temp_v0) + 0x28)) = (s32) (*(s32 *)((char *)(arg3) + 4));
            (*(s32 *)((char *)(temp_v0) + 0x2C)) = (s32) (*(s32 *)((char *)(arg3) + 8));
            (*(f32 *)((char *)(temp_v0) + 0x3C)) = (f32) ((f64) (*(f32 *)((char *)(arg3) + 0xC)) * D_800D4170);
            (*(f32 *)((char *)(temp_v0) + 0x40)) = (f32) ((f64) (*(f32 *)((char *)(arg3) + 0x10)) * D_800D4170);
            (*(f32 *)((char *)(temp_v0) + 0x44)) = (f32) ((f64) (*(f32 *)((char *)(arg3) + 0x14)) * D_800D4170);
        }
        (*(s32 *)((char *)(temp_v0) + 0x30)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x24));
        (*(s32 *)((char *)(temp_v0) + 0x34)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x28));
        (*(s32 *)((char *)(temp_v0) + 0x38)) = (s32) (*(s32 *)((char *)(temp_v0) + 0x2C));
        (*(f32 *)((char *)(temp_v0) + 0x48)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x3C));
        (*(f32 *)((char *)(temp_v0) + 0x4C)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x40));
        (*(f32 *)((char *)(temp_v0) + 0x50)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x44));
        (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
        (*(s16 *)((char *)(temp_v0) + 0x7C)) = 0;
        (*(s32 *)((char *)(temp_v0) + 0x5C)) |= 0x600;
        func_8003E6EC(*D_800CA31C, temp_v0, 1);
    }
    return temp_v0;
}
