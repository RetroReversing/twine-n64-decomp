/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80022DBC(s32);                             /* extern */
s32 func_80063D38(void *, u8);                      /* extern */
s32 func_8007089C(void *, s32, s32);        /* extern */
extern u8 D_800BF68A[];
typedef struct { u16 f0; u8 pad[230]; } Slot_800C469E;
extern Slot_800C469E D_800C469E[];
extern s32 D_8010019C;
extern s32 D_8011ECC0[];

void func_80119AF4(void *arg0) {
    register u8 var_s2;
    u8 *var_s1;
    u8 temp_s0;
    unsigned temp_s5;
    void *temp_s3;

    temp_s3 = (*(void **)((char *)(arg0) + 0x6C));
    var_s1 = D_8011ECC0[*(D_800BF68A + (*((s32 *)((s8 *)&D_8010019C + ((func_80022DBC((s8) (*(u8 *)((char *)(temp_s3) + 0x182)) & 0xFFFF) & 0xFFFF) * 0x18))) * 0xC))];
    var_s2 = -1U;
    temp_s5 = var_s1 + 0x3B;
loop_1:
    temp_s0 = *var_s1;
    if (((*(u8 *)((char *)((temp_s3 + (D_800C469E[temp_s0].f0 * 8))) + (unsigned short)0x1FC)) != 0) && ((func_80063D38((short)temp_s3, temp_s0) << 0x18) != 0)) {
        var_s2 = temp_s0;
    } else {
        var_s1 += 1;
        if (var_s1 < temp_s5) {
            goto loop_1;
        }
    }
    if (((u32)var_s2 != -1U) && ((*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xE)) != (short)var_s2)) {
        func_8007089C(arg0, 0, var_s2 & 0xFFFF);
    }
}
