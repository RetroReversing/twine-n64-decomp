extern s32 func_8009C8DC(s32);
extern s32 func_8009CF18(s32, s32, s32, u32);
extern s32 D_800B2568;
extern u8 D_801002F0;
extern u8 D_801002F1;
void func_8000A3AC(void) {
    u32 scaled;
    u32 quotient;
    scaled = D_801002F1 * 0x7F;
    quotient = scaled / 10;
    func_8009CF18(quotient & 0xFF, 0x3E8, 0xFD, quotient);
    scaled = D_801002F0 * 0x7F;
    quotient = scaled / 10;
    func_8009CF18(quotient & 0xFF, 0x3E8, 0xFE, quotient);
    if (D_800B2568 != -1) {
        func_8009C8DC(D_800B2568);
        D_800B2568 = -1;
    }
}
