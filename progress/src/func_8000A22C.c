void func_8009CF18(s32, s32, s32);
void func_8000A22C(s32 arg0) {
    u32 value = (u32)(arg0 * 127);
    func_8009CF18((value / 10) & 0xFF, 0, 0);
}
