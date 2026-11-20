extern s32 D_800C4428;
extern char D_800C4434[];
extern u8 D_80102F28;
extern void *D_80108788;
extern void *gAimAxisTable;
extern u8 D_8010A91C;
s32 func_80073AF8();
s32 func_80087100();
s32 sprintf();

void func_8005BAB0(void) {
    char buf[0x100];
    u32 temp_a1;
    s32 temp_s0;
    s32 temp_s1;
    u32 var_s2;
    char *var_s3;
    extern char D_800D4110[];

    *(s32 *)((s8 *)gAimAxisTable + 0x100) |= 0x40;
    *(s8 *)((s8 *)gAimAxisTable + 0x142) = 2;
    if (D_80108788 != NULL) {
        var_s2 = 0;
        if (*(s32 *)((s8 *)D_80108788 + 0x78) == 0x5A0000) {
            var_s3 = (char *)&D_800C4428;
            do {
                temp_a1 = *(u32 *)(*(s8 **)((s8 *)D_80108788 + 0x70) + 0x30);
                if ((((temp_a1 >> 4) & 0xFFFF) == *(s32 *)(&D_800C4428 + var_s2)) && ((temp_a1 >> 0x14) == *(s32 *)(D_800C4434 + var_s2 * 4))) {
                    D_8010A91C += 1;
                    func_80087100(0xFA, temp_a1);
                    temp_s1 = func_80087100(0xFF);
                    temp_s0 = func_80087100(0xFE);
                    sprintf(buf, D_800D4110, temp_s1, D_8010A91C, temp_s0, (s32)D_80102F28, temp_s0);
                    *(s16 *)((s8 *)D_80108788 + 0x7A) = 1;
                    func_80073AF8(0, gAimAxisTable, buf, -1, -1, 1, 0, 0, 3, 0, 0);
                }
                var_s2 += 1;
                var_s3 += 4;
            } while (var_s2 < 3U);
        }
    }
}
