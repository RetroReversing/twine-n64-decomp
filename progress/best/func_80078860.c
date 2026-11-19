s32 func_8007C094(void *, void *, f32);
void func_80077960(void *, s32, s32, s32);
void func_800779C4(void *);
void func_80077A94(void *);
void func_8008461C(void *);
extern u8 *D_8010A500;

s32 func_80078860(u8 *arg0) {
    u8 *temp_s1;
    s32 temp_a2;
    s32 temp_a3;

    temp_s1 = *(u8 **)(arg0 + 0x6C);
    if (*(s32 *)(arg0 + 0x60) & 0x3000) {
        if (func_8007C094(arg0, D_8010A500 + 0x24, 2.0f) << 0x18) {
            if ((*(s32 *)(temp_s1 + 0x88) & 0x41E00000) == 0x200000) {
                switch (temp_s1[0x82]) {
                case 3:
                case 15:
                case 35:
                case 39:
                case 40:
                    func_800779C4(arg0);
                    return 0;
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 10:
                case 11:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 43:
                case 44:
                    return 0;
                default:
                    switch (((u8 *)*(u8 **)(D_8010A500 + 0x68))[0xE]) {
                    default:
                        func_8008461C(arg0);
                        func_80077960(arg0, 0x38, 0, 0);
                        return 1;
                    case 0x0:
                    case 0x1E:
                    case 0x1F:
                    case 0x21:
                    case 0x22:
                    case 0x23:
                    case 0x24:
                    case 0x25:
                    case 0x2C:
                    case 0x2D:
                    case 0x2E:
                    case 0x2F:
                    case 0x30:
                    case 0x37:
                    case 0x38:
                        func_80077A94(arg0);
                        temp_a2 = *(s32 *)(D_8010A500 + 0x28);
                        temp_a3 = *(s32 *)(D_8010A500 + 0x2C);
                        *(s32 *)(temp_s1 + 0x18) = *(s32 *)(D_8010A500 + 0x24);
                        *(s32 *)(temp_s1 + 0x1C) = temp_a2;
                        *(s32 *)((*(u8 **)(arg0 + 0x6C)) + 0x20) = temp_a3;
                        func_80077960(arg0, 0xD, temp_a2, temp_a3);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
