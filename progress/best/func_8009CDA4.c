s32 func_8008C1B0(s32);
unsigned int func_8008C1DC(void);
extern u8 D_800CF540;
extern s8 D_80112DC0;
extern u8 D_801176E8;

s32 func_8009CDA4(void) {
    s32 i;
    s32 status = 0;
    s32 count;
    s32 result;
    if (D_800CF540 == 0) goto done;
    D_80112DC0 = 1;
    if ((u8)func_8008C1DC()) {
        status = 1;
        goto clear;
    }
    count = D_801176E8;
    i = 0;
    if (count <= 0) goto clear;
    do {
        result = func_8008C1B0(i);
        count = D_801176E8;
        ++i;
        status |= result;
    } while (i < count);
clear:
    D_80112DC0 = 0;
done:
    return (u8)status == 0;
}
