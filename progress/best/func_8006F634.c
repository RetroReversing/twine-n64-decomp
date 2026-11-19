s32 func_80048F10(s32, void *, f32 *, s32 *, f32, s32 *, s32 *, s32);
s32 func_8004FF30(s32, f32 *, s32 *, s32, s32, s32, s32, s32);

void func_8006F634(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    f32 sp20;
    f32 sp24;
    f32 sp28;
    s32 sp30;
    f32 sp40;
    f32 sp44;
    f32 sp48;
    s32 sp50;
    s32 sp60;
    s32 sp70;
    f32 sp80;
    f32 sp84;
    f32 sp88;
    f32 sp90;
    f32 sp94;
    f32 sp98;
    f32 spA0;
    f32 spA4;
    f32 spA8;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 var_s1;
    u32 var_s2;
    u8 *temp_s1;
    u8 *temp_v1;
    u8 *tmp;

    temp_s1 = (u8 *) *(void **)((u8 *)arg1 + 0x6C);
    temp_fv0 = *(f32 *)(temp_s1 + 0xCC) - 0.32666668f;
    *(f32 *)(temp_s1 + 0xCC) = temp_fv0;
    temp_v1 = (u8 *) *(void **)((u8 *)arg1 + 0x68);
    *(f32 *)((u8 *)arg1 + 0x28) = *(f32 *)((u8 *)arg1 + 0x28) + (temp_fv0 * 0.033333335f);
    *(u16 *)(temp_v1 + 0xC) = *(u16 *)(temp_v1 + 0xC) & 0xFF77;
    sp80 = *(f32 *)((u8 *)arg1 + 0x24);
    sp84 = *(f32 *)((u8 *)arg1 + 0x28);
    sp88 = *(f32 *)((u8 *)arg1 + 0x2C);
    sp84 += 1.0f;
    if ((func_80048F10(arg0, (u8 *)arg1 + 0x24, &sp40, &sp50, 250.0f, &sp60, &sp70, 0) << 0x18) == 0) {
        sp40 = *(f32 *)((u8 *)arg1 + 0x24);
        sp44 = *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x68) + 8);
        sp48 = *(f32 *)((u8 *)arg1 + 0x2C);
    }
    *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x68) + 8) = sp44;
    temp_fv1 = sp44 + *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x68) + 0x38);
    if (*(f32 *)((u8 *)arg1 + 0x28) <= temp_fv1) {
        *(f32 *)((u8 *)arg1 + 0x28) = temp_fv1;
        *(f32 *)(temp_s1 + 0xCC) = 0.0f;
    }
    sp20 = 0.0f;
    sp24 = 0.0f;
    sp28 = 0.0f;
    var_s2 = 0;
    if (*(s8 *)((u8 *)*(void **)((u8 *)arg1 + 0x68) + 0xB3) > 0) {
        var_s1 = 0;
        do {
            if (var_s2 < 0xF) {
                switch (var_s2) {
                case 7:
                case 14:
                    spA0 = *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x68) + var_s1) + sp20;
                    sp90 = spA0;
                    spA4 = *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x68) + var_s1 + 4) + sp24;
                    sp94 = spA4;
                    spA8 = *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x68) + var_s1 + 8) + sp28;
                    sp98 = spA8;
                    if ((func_8004FF30(arg0, &sp90, &sp30, 0x3E4CCCCD, 0x10, arg2, arg3, 0) << 0x18) != 0) {
                        sp20 += sp90 - spA0;
                        sp24 += sp94 - spA4;
                        sp28 += sp98 - spA8;
                    }
                    break;
                default:
                    break;
                }
            }
            var_s1 += 0xC;
            var_s2 += 1;
        } while ((s32) var_s2 < *(s8 *)((u8 *)*(void **)((u8 *)arg1 + 0x68) + 0xB3));
    }
    *(f32 *)((u8 *)arg1 + 0x24) = *(f32 *)((u8 *)arg1 + 0x24) + sp20;
    *(f32 *)((u8 *)arg1 + 0x28) = *(f32 *)((u8 *)arg1 + 0x28) + sp24;
    *(f32 *)((u8 *)arg1 + 0x2C) = *(f32 *)((u8 *)arg1 + 0x2C) + sp28;
}
