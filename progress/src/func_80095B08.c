extern u8 D_800EE420[][16][0x86];
extern u8 D_800F2720[][0x86];
inline static void St(u8 i, u8 r, u8 b, u8 v) {
    if (b != 0xFF) { D_800EE420[b][r][i] = v & 0x7F; } else { D_800F2720[r][i] = v & 0x7F; }
}

void func_80095B08(u8 arg0, u8 arg1, u8 arg2, u16 arg3) {
    if (arg0 < 0x40) {
        St(arg0 & 0x1F, arg1, arg2, arg3 >> 7);
        St((arg0 & 0x1F) | 0x20, arg1, arg2, arg3 & 0x7F);
    } else if ((u8)(arg0 + 128) < 2) {
        St(arg0 & 0xFE, arg1, arg2, arg3 >> 7);
        St(arg0 | 1, arg1, arg2, arg3 & 0x7F);
    } else if ((u8)(arg0 + 124) < 2) {
        St(arg0 & 0xFE, arg1, arg2, arg3 >> 7);
        St(arg0 | 1, arg1, arg2, arg3 & 0x7F);
    } else {
        St(arg0, arg1, arg2, arg3 >> 7);
    }
}
