extern s32 D_800B1D74;
extern u8 D_800CA338;
extern s64 D_80102CC8, D_80108F88, D_80109DD8, D_8010A398, D_80115320;
extern s32 D_8010A4E0;
u64 osGetTime(void);
void func_8008188C();
void func_800101D8();
void func_80016FCC();
void func_80017454();
void func_800734B8();
void func_800072B8(void) {
    u32 count;
    s64 limit;
    D_80109DD8 = osGetTime() - D_80115320;
    D_80115320 = osGetTime();
    D_80102CC8 += D_80109DD8;
    if (D_8010A4E0) limit = D_80108F88 * 8;
    else limit = D_80108F88 * 2;
    if (D_80102CC8 > limit) D_80102CC8 = limit;
    count = 0;
    D_8010A398 = osGetTime();
    while (D_80102CC8 >= D_80108F88 * 2) {
        D_80102CC8 -= D_80108F88 * 2;
        func_8008188C();
        if (D_800CA338 == 1) func_800101D8();
        func_80016FCC(count != 0);
        count++;
        if (osGetTime() - D_8010A398 > count * D_80108F88 * 2) break;
        D_800B1D74++;
    }
    func_80017454();
    func_800734B8();
}
