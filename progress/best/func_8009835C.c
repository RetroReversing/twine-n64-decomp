/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_800956E0();
extern s16 D_800F3894;
extern void *D_800F38B0;
extern void *D_800F38B4;
extern s32 D_800F38EC;
extern char D_800F38F0[];
extern char D_800F38F8[];
extern s32 func_800986CC;

typedef struct { unsigned char pad_0[8]; int field_8; int field_C; int field_10; int field_14; int field_18; } __repair_record_temp_v0;
s32 func_8009835C(s16 arg0, void *arg1) {
int __repair_literal;

    s32 var_s0;
    register int var_s2;
    void *temp_v0;

    D_800F3894 = arg0;
    var_s2 = 0;
__repair_literal = 0;

    if (__repair_literal < D_800F38EC) {
        var_s0 = 0;
        for (;;) {
            temp_v0 = func_800956E0(&D_800F3894, *(u16 *)(D_800F38F0 + var_s0), *(u16 *)(D_800F38F8 + var_s0), 0x1C, &func_800986CC);
            D_800F38B0 = temp_v0;/*__repair_loop_weight*/do {
            var_s2 += 1;} while (0);
            if (temp_v0 != NULL) {
                (*(s32 *)((char *)(arg1) + 0)) = (s32) ((__repair_record_temp_v0*)temp_v0)->field_C;
                (*(s32 *)((char *)(arg1) + 0x10)) = (s32) ((__repair_record_temp_v0*)temp_v0)->field_14;
                (*(s32 *)((char *)(arg1) + 8)) = 0;
                (*(s32 *)((char *)(arg1) + 4)) = (s32) ((__repair_record_temp_v0*)temp_v0)->field_8;
                (*(s32 *)((char *)(arg1) + 0xC)) = (s32) (((__repair_record_temp_v0*)temp_v0)->field_10 & 0xFFFFFF);
                D_800F38B4 = temp_v0 + 0xC;
                (*(s32 *)((char *)(arg1) + 0x14)) = (s32) ((__repair_record_temp_v0*)temp_v0)->field_18;
                (*(u8 *)((char *)(arg1) + 0x18)) = (u8) ((__repair_record_temp_v0*)temp_v0)->field_10;
                return 0;
            }
            var_s0 += 0xC;
            if (D_800F38EC <= var_s2) {
                goto block_5;
            }
            continue;
            break;
        }
    }
block_5:
    return -1;
}
