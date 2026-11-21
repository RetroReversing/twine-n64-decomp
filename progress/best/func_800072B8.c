extern s32 D_800B1D74;
extern u8 D_800CA338;
extern s64 D_80102CC8, D_80108F88, D_80109DD8, D_8010A398, D_80115320;
extern s32 D_8010A4E0;
u64 osGetTime(void);
void func_8008188C();
void updateTransitionState();
void func_80016FCC();
void func_80017454();
void func_800734B8();
void func_800072B8(void) {
    u32 count;
    s64 limit;
    s32 high;
    D_80109DD8 = osGetTime() - D_80115320;
    D_80115320 = osGetTime();
    D_80102CC8 += D_80109DD8;
    if (D_8010A4E0) {
        limit = D_80108F88 * 8;
        high = *(volatile s32 *)&D_80102CC8;
    } else {
        limit = D_80108F88 * 2;
        high = *(volatile s32 *)&D_80102CC8;
    }
    if (high > (s32)(limit >> 32) ||
        (high == (s32)(limit >> 32) && ((u32 *)&D_80102CC8)[1] > (u32)limit))
        D_80102CC8 = limit;
    count = 0;
    D_8010A398 = osGetTime();
    while (D_80102CC8 >= D_80108F88 * 2) {
        D_80102CC8 -= D_80108F88 * 2;
        func_8008188C();
        if (D_800CA338 == 1) updateTransitionState();
        func_80016FCC(count != 0);
        count++;
        if ((s64)(osGetTime() - D_8010A398) > count * D_80108F88 * 2) break;
        D_800B1D74++;
    }
    func_80017454();
    func_800734B8();
}
