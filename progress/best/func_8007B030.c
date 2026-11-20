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
    M2C_UNK *__base_D_800C9C00;
    void *var_a1;
    s32 var_a2;
    f32 var_fv1;
    void *temp_s1;
    s32 temp_a1;
    s16 var_s2;
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
            {
    func_8007AEA4(arg0, var_a1, var_a2);return;}
        case 0:
            func_8007AEA4(arg0, &D_800C9CC8, 4);
            return;
        case 10:
            func_8007AEA4(arg0, &D_800C9CD8, 2);
            return;
        case 2:
            func_8007AEA4(arg0, &D_800C9CE0, 2);
            return;
        }
        return;
    }
    v = *(u8 *)((s8 *)temp_s1 + 0x82);
    if ((s32) v < 9) goto blkX;
    if ((s32) v < 0xC) goto blkY;
    if (v == 0x1E) goto blkY;
blkX:
    if (*(u8 *)((s8 *)&D_800C470A + (*(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0x68) + 0xE) * 0xE8)) == 5) {
        {
    func_8007AFB0(arg0);return;}
    }
    switch (*(s16 *)((s8 *)arg0 + 0x7C)) {
    case 2:
        if (var_s2 != 0) {
            func_8007AEA4(arg0, &D_800C9C9C, 2);
        } else {
            func_8007AEA4(arg0, &D_800C9CA4, 5);
        }
        return;
    case 1:
        func_8007AEA4(arg0, &D_800C9C00, 6);
        return;
    case 3:
        if (var_s2 != 0) {
            if ((func_8007AEA4(arg0, &D_800C9C38, 4) << 0x18) == 0) {
                {
    func_80002BD0(arg0, 0x14D);return;}
            }
        } else if ((func_8007AEA4(arg0, &D_800C9C18, 8) << 0x18) == 0) {
            {
    func_80002BD0(arg0, 0x14D);return;}
        }
        break;
    case 0:
        if (var_s2 != 0) {
            func_8007AEA4(arg0, &D_800C9C60, 4);
        } else {
            func_8007AEA4(arg0, &D_800C9C48, 6);
        }
        return;
    case 10:
        if (var_s2 != 0) {
            func_8007AEA4(arg0, &D_800C9C94, 2);
        } else {
            func_8007AEA4(arg0, &D_800C9C70, 9);
        }
        return;
    }
    return;
blkY:
    if (*(u8 *)((s8 *)&D_800C470A + (*(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0x68) + 0xE) * 0xE8)) == 5) {
        {
    func_8007AFB0(arg0);return;}
    }
    switch (*(s16 *)((s8 *)arg0 + 0x7C)) {
    case 1:
        func_8007AEA4(arg0, &D_800C9CF8, 4);
        return;
    case 3:
        if ((func_8007AEA4(arg0, &D_800C9CE8, 4) << 0x18) != 0) {
            return;
        }
        if ((func_80077E00(arg0) << 0x18) == 0) {
            return;
        }
        goto block_42;
    case 0:
        func_8007AEA4(arg0, &D_800C9D08, 4);
        return;
    case 10:
        var_a1 = &D_800C9D18;
        var_a2 = 3;
        goto block_47;
    case 2:
        func_8007AEA4(arg0, &D_800C9D24, 3);
        return;
    }
    return;
block_42:
    func_80002BD0(arg0, 0x14D);
    return;
block_47:
    func_8007AEA4(arg0, var_a1, var_a2);
    return;
}
