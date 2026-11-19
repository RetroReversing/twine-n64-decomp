extern const char D_800D2864[];
static __inline__ u8 __repair_inline(u8 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80026004();
s32 func_80029068();
s32 func_80087100();
extern char D_801001A2[];
extern u8 D_801002AD;
extern void *D_80109BB0;

void func_8001AA98(void) {
    s32 var_a0;
    s32 temp_s0;
    u32 temp_v1;
    s32 temp_s1;

    func_80029068();
    if ((*(u8 *)((char *)(D_80109BB0) + 0x2D)) != 0) {
        temp_s0 = (*(s32 *)((char *)(D_80109BB0) + 0x18)) + 0x28;
        temp_s1 = __repair_inline(*(D_801001A2 + (D_801002AD * 0x18)));
        temp_v1 = temp_s1 & 0xFFFF;
        switch (temp_v1) {
        case 0:
            var_a0 = 0xA;
block_9:
            func_80026004(temp_s0, D_800D2864, func_80087100(var_a0));
            break;
        case 1:
            var_a0 = 9;
            goto block_9;
        case 2:
            var_a0 = 0x6B;
            goto block_9;
        case 3:
            var_a0 = 0x6C;
            {
            func_80026004(temp_s0, D_800D2864, func_80087100(var_a0));break;}
        case 4:
            var_a0 = 0x296;
            {
            func_80026004(temp_s0, D_800D2864, func_80087100(var_a0));break;}
        case 5:
            var_a0 = 0x297;
            {
            func_80026004(temp_s0, D_800D2864, func_80087100(var_a0));break;}
        }
        *(D_801001A2 + (D_801002AD * 0x18)) = temp_s1;
    }
}
