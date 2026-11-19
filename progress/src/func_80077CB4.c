s32 func_80077CB4(u8 *arg0) {
    u8 *p;
    u8 *q;

    if (*(u8 **)(arg0 + 0x1C) != NULL) {
        p = *(u8 **)(arg0 + 0x1C);
        if (*(u16 *)(p + 0x78) != 0xB) {
            return 1;
        }
        q = *(u8 **)(p + 0x6C);
        switch (q[0x4A]) {
        case 4:
        case 5:
            if (*(u16 *)(q + 0x34) != 0 && *(s16 *)(p + 0x7A) != 4) {
                return 0;
            }
            break;
        case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
            break;
        case 16:
        case 17:
            if (*(u16 *)(q + 0x34) != 0 && *(s16 *)(p + 0x7A) != 0) {
                return 0;
            }
            break;
        }
    }
    return 1;
}
