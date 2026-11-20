s32 func_8000C860();
extern s32 **gObjectTable;
extern struct CommandRef {
    s16 *id;
    char padding[8];
} D_800C3CF8[];
extern struct CommandDef {
    s16 id;
    char padding[230];
} D_800C4708[];
extern s16 D_800E0740;
extern s16 D_80100B60[];

void func_8000CD8C(void) {
    u32 *cursor;
    s16 *out;
    s32 count = 0;
    s32 active = 1;

    out = D_80100B60;
    D_800E0740 = -1;
    cursor = *gObjectTable;

    do {
        s32 id = -1;
        s32 command = *cursor;
        s32 words = 0;
        s32 args = command >> 8;
        s32 opcode = command & 0x3f;
        cursor++;
        switch (opcode) {
        case 35: active = 0; break;
        case 36: break;
        case 0:
            id = **(u16 **)cursor;
            D_800E0740 = id;
        case 9: case 10: case 14: case 22: case 23: case 28:
            words = 1; break;
        case 26: words = 2; break;
        case 1: case 2: case 4: case 5: case 6: case 8:
        case 15: case 16: case 20: case 21: case 25:
            words = 3; break;
        case 17: words = 6; break;
        case 33:
            if ((args & 255) == 0x69) {
                id = D_800C4708[func_8000C860((args >> 8) & 255)].id;
            }
            break;
        case 18: case 19:
            id = **(u16 **)cursor;
            words = 7;
            break;
        case 11: case 12: case 13:
            id = ((u8 *)cursor)[3];
            id = *D_800C3CF8[id].id;
            words = 7;
            break;
        case 3: case 7: case 24: words = 12; break;
        }
        if (id >= 0) {
            *out++ = id;
            count++;
        }
        cursor += words;
    } while (active);
    D_80100B60[count] = -1;
}
