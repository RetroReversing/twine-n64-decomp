extern void func_800103B0(u8 *dst, s8 *src, u8 len);
extern s32 func_80010A2C(void);
extern s32 func_8001226C(s32);
extern s32 saveDataRunSteps(void);
extern u16 func_80012F50(void);
extern u16 gSaveStatus;
extern s32 D_800E0978;
extern u8 D_80103042;
extern char D_80107B68[];
extern u8 D_80108412[];
extern u8 D_8010A3C5[];

u16 func_80012AB0(u16 arg0)
{
    s8 *p;

    gSaveStatus = 3;
    D_800E0978 = arg0;
    if (func_80012F50() == 0) {
        if (*(u16 *)(D_80107B68 + D_800E0978 * 0x18) != 0) {
            if (func_8001226C(D_800E0978) == 0) {
                gSaveStatus = 0x81;
                return 0x81;
            }
            p = (s8 *)&D_80103042;
            *p = D_80108412[D_800E0978 << 5];
            func_800103B0(D_8010A3C5, p, 4);
        }
        if ((u16)func_80010A2C() != 0) {
            gSaveStatus = 0x30;
            return 0x30;
        }
        if ((u16)saveDataRunSteps() == 0 && func_80012F50() == 0) {
            gSaveStatus = 3;
            return 3;
        }
    }
    return gSaveStatus;
}
