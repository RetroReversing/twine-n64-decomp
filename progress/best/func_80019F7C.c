/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80001E28();
s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002D30();
s32 func_80019E28();
s32 func_80026004();
void *func_800262A8();
s32 func_80027C60();
s32 func_80027CE0();
s32 func_80029068();
s32 func_8002B8AC();
s32 func_8002B930();
s32 func_8002B9CC();
s32 func_8002BA6C();
s32 func_8002BC28();
s32 func_80044D28();
extern void *D_800B5B14;
extern u16 D_800BD680;
extern s16 D_800BD682;
extern u8 D_800BF688[];
extern char D_800C3CF8[];
extern char D_8010019C[];
typedef struct { u8 f0; u8 pad[23]; } Slot_801001A3;
extern Slot_801001A3 D_801001A3[];
extern u8 D_801002AD;
extern s32 D_801002B8;
extern s8 D_80107ECC;
extern void *D_80109BB0;

extern char D_800D2864[];
extern char D_800D2858[];
void func_80019F7C(void) {
    void **__base_D_800B5B14;
    u32 temp_a0;
    s32 var_a1;
    
    long var_s1;
    u16 temp_v1;
    u16 temp_v1_3;
    u8 temp_s0_2;
    register u8 temp_v1_2;
    register void *temp_s0;
    register void *temp_s3;
    void *temp_s4;

    temp_s4 = func_800262A8((*(s32 *)((char *)(D_80109BB0) + 0x10)), 0x400C);
    temp_s0 = (*(void **)((char *)(D_80109BB0) + 0x18));
    do { func_80029068(); } while (0);
    var_s1 = *(*(s32 **)((char *)(temp_s0) + 0x10));
    temp_s3 = temp_s0 + 0x28;
    if (((*(u8 *)((char *)(D_80109BB0) + 0x2D)) != 0) && ((*(u8 *)((char *)(D_80109BB0) + 0x2E)) == 0)) {
        D_801001A3[D_801002AD].f0 = 0;
        if (func_80027CE0(0x20) & 0xFF) {
            var_s1 = func_8002B930(var_s1, -1);
        }
        if (func_80027CE0(0x21) & 0xFF) {
            var_s1 = func_8002B930(var_s1, 1);
        }
        *(*(s32 **)((char *)(temp_s0) + 0x10)) = var_s1;
        __base_D_800B5B14 = &D_800B5B14;
        if ((*__base_D_800B5B14) != NULL) {
            func_8002B8AC();
            temp_v1 = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC));
            D_800BD682 = -1;
            D_80107ECC = 1;
            D_800BD680 = temp_v1;
            func_80044D28(&D_800BD680);
            D_80107ECC = 0;
            func_8000237C((*__base_D_800B5B14), func_8002B9CC(var_s1), 0, D_801001A3[D_801002AD].f0);
            func_80002BD0((*__base_D_800B5B14), 0x14D);
            (*(f32 *)((char *)((*(void **)((char *)((*__base_D_800B5B14)) + 0x68))) + 0x34)) = 0.05f;
            if (func_8002BC28(*(s32 *)(D_8010019C + (D_801002AD * 0x18))) & 0xFF) {
                func_80002D30((*__base_D_800B5B14), 0x327);
            } else {
                func_80002D30((*__base_D_800B5B14), 0x2A9);
            }
            goto block_11;
        }
    } else {
block_11:
        (*(u8 *)((char *)(D_80109BB0) + 0x2D)) = 0U;
        if (func_80027C60(0x28) & 0xFF) {
            temp_a0 = D_801002AD * 0x18;
            temp_v1_2 = D_801001A3[D_801002AD].f0;
            if (temp_v1_2) {
                (*(s8 *)((char *)((temp_a0 + (&D_801002AD - 0x115))) + 0xB)) = (s8) (temp_v1_2 - 1);
                (*(u8 *)((char *)(D_80109BB0) + 0x2D)) = 1U;
            }
        }
        if (func_80027C60(0x29) & 0xFF) {
            temp_s0_2 = D_801001A3[D_801002AD].f0;
            if (temp_s0_2 < func_80001E28(*(s16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC)))) {
                (*(s8 *)((char *)((temp_a0 + (&D_801002AD - 0x115))) + 0xB)) = (s8) (D_801001A3[D_801002AD].f0 + 1);
                temp_a0 = D_801002AD * 0x18;
                (*(u8 *)((char *)(D_80109BB0) + 0x2D)) = 1U;
            }
        }
        if (((*(u8 *)((char *)(D_80109BB0) + 0x2D)) != 0) && ((*(u8 *)((char *)(D_80109BB0) + 0x2E)) == 0)) {
            if ((*__base_D_800B5B14) != NULL) {
                func_8002B8AC();
                temp_v1_3 = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(var_s1) * 0xC));
                D_800BD682 = -1;
                D_80107ECC = 1;
                D_800BD680 = temp_v1_3;
                func_80044D28(&D_800BD680);
                D_80107ECC = 0;
                func_8000237C((*__base_D_800B5B14), func_8002B9CC(var_s1), 0, D_801001A3[D_801002AD].f0);
                func_80002BD0((*__base_D_800B5B14), 0x14D);
                (*(f32 *)((char *)((*(void **)((char *)((*__base_D_800B5B14)) + 0x68))) + 0x34)) = 0.05f;
                goto block_21;
            }
        } else {
block_21:
            if (temp_s3 != NULL) {
                func_80026004(temp_s3, D_800D2864, func_8002BA6C(var_s1));
            }
            if (temp_s4 != NULL) {
                func_80019E28(temp_s4);
            }
            if (D_801002AD > D_801002B8) {
                temp_s4 = func_800262A8((*(s32 *)((char *)(D_80109BB0) + 0x10)), 0x4004);
func_80026004(temp_s4, D_800D2858, *(D_800BF688 + (*(s32 *)(D_8010019C + (D_801002AD * 0x18)) * 0xC)) * 5);
            }
        }
    }
}
