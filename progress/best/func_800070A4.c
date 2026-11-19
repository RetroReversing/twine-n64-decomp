u64 osGetTime(void);
extern u64 D_80102CC8;
extern u64 D_80109DD8;
extern u64 D_80115320;

void func_800070A4(void) {
    u64 t;
    D_80109DD8 = 0;
    t = osGetTime();
    D_80102CC8 = 0;
    D_80115320 = t;
}
