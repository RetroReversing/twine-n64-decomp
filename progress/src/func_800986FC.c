s32 compareU16Key(const u16 *left, const u16 *right) {
    return *left - *right;
}
s32 func_800986DC(const u16 *left, const u16 *right) {
    return left[2] - right[2];
}
s32 func_800986FC(const u16 *left, const u16 *right) {
    return *left - *right;
}
u32 read_sp_status(void) {
    return *(volatile u32 *)0xA4040010;
}
