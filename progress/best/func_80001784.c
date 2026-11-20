extern s16 D_800D9428, D_800D942A, D_800D942C[6];
extern s16 D_800D94F8, D_800D94FA, D_800D9500[8];
extern s16 D_800DC710, D_800DC712;
extern s32 D_800DC718[6];

static __inline__ void fill_s16(u32 i, s16 value, s16 *out, u32 count, s16 *read, s16 *write) {
    *read = 0;
    *write = 0;
    do {
        *out++ = value;
        ++i;
    } while (i < count);
}

static __inline__ void fill_s32(u32 i, s32 value, s32 *out, u32 count, s16 *read, s16 *write) {
    *read = 0;
    *write = 0;
    do {
        *out++ = value;
        ++i;
    } while (i < count);
}

void func_80001784(void) {
    fill_s16(0, 0x7fff, D_800D942C, 6, &D_800D942A, &D_800D9428);
    fill_s16(0, 0x7fff, D_800D9500, 8, &D_800D94FA, &D_800D94F8);
    fill_s32(0, 0x7fffffff, D_800DC718, 6, &D_800DC712, &D_800DC710);
}
