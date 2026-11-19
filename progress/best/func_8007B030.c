typedef s32 M2C_UNK;
M2C_UNK func_80002BD0(void *, M2C_UNK);
f32 func_800461D4(void *, void *);
s32 func_80077E00(void *);
s32 func_8007AEA4(void *, M2C_UNK *, M2C_UNK);
M2C_UNK func_8007AFB0(void *);
extern M2C_UNK D_800C470A;
extern M2C_UNK D_800C9C00;
extern M2C_UNK D_800C9C18;
extern M2C_UNK D_800C9C38;
extern M2C_UNK D_800C9C48;
extern M2C_UNK D_800C9C60;
extern M2C_UNK D_800C9C70;
extern M2C_UNK D_800C9C94;
extern M2C_UNK D_800C9C9C;
extern M2C_UNK D_800C9CA4;
extern M2C_UNK D_800C9CB8;
extern M2C_UNK D_800C9CC0;
extern M2C_UNK D_800C9CC8;
extern M2C_UNK D_800C9CD8;
extern M2C_UNK D_800C9CE0;
extern M2C_UNK D_800C9CE8;
extern M2C_UNK D_800C9CF8;
extern M2C_UNK D_800C9D08;
extern M2C_UNK D_800C9D18;
extern M2C_UNK D_800C9D24;

void func_8007B030(void *arg0) {
    void *var_a1;
    s32 var_a2;
    f32 var_fv1;
    void *temp_s1;
    s32 temp_a1;
    s32 var_s2;
    s32 v;

    temp_s1 = *(void **)((s8 *)arg0 + 0x6C);
    temp_a1 = *(s32 *)((s8 *)temp_s1 + 0x40);
    var_s2 = 0;
    if (temp_a1 != 0) {
        var_fv1 = func_800461D4((s8 *)arg0 + 0x24, (s8 *)temp_a1 + 0x24);
    } else {
        var_fv1 = 0.0f;
    }
    if (var_fv1 < 10.0f) {
        var_s2 = 1;
    }
    if (*(s32 *)((s8 *)temp_s1 + 0x88) & 0x04000000) {
        switch (*(s16 *)((s8 *)arg0 + 0x7C)) {
        case 3:
            if ((func_8007AEA4(arg0, &D_800C9CC0, 2) << 0x18) != 0) {
                break;
            }
            goto block_42;
        case 1:
            var_a1 = &D_800C9CB8;
            var_a2 = 2;
            goto block_47;
        case 0:
            var_a1 = &D_800C9CC8;
            var_a2 = 4;
            goto block_47;
        case 10:
            var_a1 = &D_800C9CD8;
            var_a2 = 2;
            goto block_47;
        case 2:
            var_a1 = &D_800C9CE0;
            var_a2 = 2;
            goto block_47;
        }
        return;
    }
    v = *(u8 *)((s8 *)temp_s1 + 0x82);
    if ((s32) v < 9) goto blkX;
    if ((s32) v < 0xC) goto blkY;
    if (v == 0x1E) goto blkY;
blkX:
    if (*(u8 *)((s8 *)&D_800C470A + (*(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0x68) + 0xE) * 0xE8)) == 5) {
        goto block_36;
    }
    switch (*(s16 *)((s8 *)arg0 + 0x7C)) {
    case 3:
        if (var_s2 != 0) {
            if ((func_8007AEA4(arg0, &D_800C9C38, 4) << 0x18) == 0) {
                goto block_42;
            }
        } else if ((func_8007AEA4(arg0, &D_800C9C18, 8) << 0x18) == 0) {
            goto block_42;
        }
        break;
    case 1:
        var_a1 = &D_800C9C00;
        var_a2 = 6;
        goto block_47;
    case 0:
        if (var_s2 != 0) {
            var_a1 = &D_800C9C60;
            var_a2 = 4;
        } else {
            var_a1 = &D_800C9C48;
            var_a2 = 6;
        }
        goto block_47;
    case 10:
        if (var_s2 != 0) {
            var_a1 = &D_800C9C94;
            var_a2 = 2;
        } else {
            var_a1 = &D_800C9C70;
            var_a2 = 9;
        }
        goto block_47;
    case 2:
        if (var_s2 != 0) {
            var_a1 = &D_800C9C9C;
            var_a2 = 2;
        } else {
            var_a1 = &D_800C9CA4;
            var_a2 = 5;
        }
        goto block_47;
    }
    return;
blkY:
    if (*(u8 *)((s8 *)&D_800C470A + (*(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0x68) + 0xE) * 0xE8)) == 5) {
        goto block_36;
    }
    switch (*(s16 *)((s8 *)arg0 + 0x7C)) {
    case 1:
        var_a1 = &D_800C9CF8;
        var_a2 = 4;
        goto block_47;
    case 3:
        if ((func_8007AEA4(arg0, &D_800C9CE8, 4) << 0x18) != 0) {
            return;
        }
        if ((func_80077E00(arg0) << 0x18) == 0) {
            return;
        }
        goto block_42;
    case 0:
        var_a1 = &D_800C9D08;
        var_a2 = 4;
        goto block_47;
    case 10:
        var_a1 = &D_800C9D18;
        var_a2 = 3;
        goto block_47;
    case 2:
        var_a1 = &D_800C9D24;
        var_a2 = 3;
        goto block_47;
    }
    return;
block_36:
    func_8007AFB0(arg0);
    return;
block_42:
    func_80002BD0(arg0, 0x14D);
    return;
block_47:
    func_8007AEA4(arg0, var_a1, var_a2);
    return;
}
