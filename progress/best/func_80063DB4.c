/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80016718();
s32 func_8003E6EC();
s32 func_800635B4();
extern s32 *D_800CA31C;
extern s32 D_801002E0;
extern s32 D_80102F3C;
typedef struct { u32 f0; u8 pad[8]; } Slot_80108608;
extern Slot_80108608 D_80108608[];
extern char D_8010860C[];
extern char D_80108610[];
extern char D_80109688[];
extern char D_80110B28[];
extern char D_80110B2C[];
extern char D_80110B30[];

void func_80063DB4(void *arg0) {
int __repair_literal;

    s32 temp_v0;
    unsigned int temp_v0_2;
    register void *temp_v1;
    register unsigned long var_a0;
    s32 temp_v0_3;
    s32 var_a1;
    void *temp_s1;

    temp_s1 = (*(void **)((char *)(arg0) + 0x6C));
    do { func_80016718(); } while (0);
    temp_v1 = *(s32 *)(D_80109688 + ((*(s8 *)((char *)(temp_s1) + 0x182)) * 4));
    temp_v0 = D_80102F3C * 0xC;
    (*(s32 *)((char *)(arg0) + 0x28)) = (s32) *(s32 *)(D_80110B2C + temp_v0);
    (*(s32 *)((char *)(arg0) + 0x24)) = (s32) *(s32 *)(D_80110B28 + temp_v0);
    (*(s32 *)((char *)(arg0) + 0x2C)) = (s32) *(s32 *)(D_80110B30 + temp_v0);
    (*(s32 *)((char *)(arg0) + 0x30)) = (s32) (*(s32 *)((char *)(arg0) + 0x24));
    (*(s32 *)((char *)(arg0) + 0x34)) = (s32) (*(s32 *)((char *)(arg0) + 0x28));
    (*(s32 *)((char *)(arg0) + 0x38)) = (s32) (*(s32 *)((char *)(arg0) + 0x2C));
    (*(s32 *)((char *)(temp_v1) + 0x10)) = (s32) (*(s32 *)((char *)(arg0) + 0x30));
    (*(s32 *)((char *)(temp_v1) + 0x18)) = (s32) (*(s32 *)((char *)(arg0) + 0x38));
    (*(s32 *)((char *)(temp_v1) + 0x28)) = (s32) (*(s32 *)((char *)(temp_v1) + 0x10));
    (*(s32 *)((char *)(temp_v1) + 0x2C)) = (s32) (*(s32 *)((char *)(temp_v1) + 0x14));
    (*(s32 *)((char *)(temp_v1) + 0x14)) = (s32) (*(s32 *)((char *)(arg0) + 0x34));
    var_a1 = 0;
    (*(s32 *)((char *)(temp_v1) + 0x30)) = (s32) (*(s32 *)((char *)(temp_v1) + 0x18));
__repair_literal = 0;

    if ((*(s8 *)((char *)((*(s32 **)((char *)(arg0) + 0x68))) + 0xB3)) > __repair_literal) {
        var_a0 = 0;
        do {
            *(s32 *)(var_a0 + (*(s32 *)((char *)((*(s32 **)((char *)(arg0) + 0x68))) + 0))) = (*(s32 *)((char *)(arg0) + 0x24));
            (*(s32 *)((char *)((var_a0 + (*(s32 *)((char *)((*(s32 **)((char *)(arg0) + 0x68))) + 0)))) + 4)) = (s32) (*(s32 *)((char *)(arg0) + 0x28));
            (*(s32 *)((char *)((var_a0 + (*(s32 *)((char *)((*(s32 **)((char *)(arg0) + 0x68))) + 0)))) + 8)) = (s32) (*(s32 *)((char *)(arg0) + 0x2C));
            *(s32 *)(var_a0 + (*(s32 *)((char *)((*(s32 **)((char *)(arg0) + 0x68))) + 4))) = (*(s32 *)((char *)(arg0) + 0x24));
            (*(s32 *)((char *)((var_a0 + (*(s32 *)((char *)((*(s32 **)((char *)(arg0) + 0x68))) + 4)))) + 8)) = (s32) (*(s32 *)((char *)(arg0) + 0x2C));
            (*(s32 *)((char *)((var_a0 + (*(s32 *)((char *)((*(s32 **)((char *)(arg0) + 0x68))) + 4)))) + 4)) = (s32) (*(s32 *)((char *)(arg0) + 0x28));
            ++var_a1;
            var_a0 += 0xC;
        } while (var_a1 < (*(s8 *)((char *)((*(s32 **)((char *)(arg0) + 0x68))) + 0xB3)));
    }
    temp_v0_2 = D_80102F3C * 0xC;
    (*(s32 *)((char *)(arg0) + 0x40)) = (s32) *(s32 *)(D_8010860C + temp_v0_2);
    (*(s32 *)((char *)(arg0) + 0x3C)) = D_80108608[D_80102F3C].f0;
    (*(s32 *)((char *)(arg0) + 0x48)) = (s32) (*(s32 *)((char *)(arg0) + 0x3C));
    (*(s32 *)((char *)(arg0) + 0x4C)) = (s32) (*(s32 *)((char *)(arg0) + 0x40));
    (*(s32 *)((char *)(arg0) + 0x44)) = (s32) *(s32 *)(D_80108610 + temp_v0_2);
    (*(s32 *)((char *)(arg0) + 0x50)) = (s32) (*(s32 *)((char *)(arg0) + 0x44));
    func_8003E6EC(*D_800CA31C, arg0, 0);
    temp_v0_3 = D_80102F3C + 1;
    D_80102F3C = temp_v0_3;
    if (temp_v0_3 == D_801002E0) {
        D_80102F3C = 0;
    }
    (*(s32 *)((char *)(*(s32 *)(D_80109688 + ((*(s8 *)((char *)(temp_s1) + 0x182)) * 4))) + 0xF4)) = (s32) (*(s32 *)((char *)(arg0) + 0x20));
    func_800635B4(arg0, 0);
}
