extern void decodeTextField(u8 *dst, s8 *src, u8 len);
extern s32 saveFindTaggedSlot(void);
extern s32 func_8001226C(s32);
extern s32 saveDataRunSteps(void);
extern u16 func_80012F50(void);
extern u16 gSaveStatus;
extern s32 gSaveRequestSlot;
extern u8 D_80103042;
extern char D_80107B68[];
extern u8 D_80108412[];
extern u8 D_8010A3C5[];

/* Requests a save-slot operation: checks the slot header, loads the slot code and runs the save steps; returns the resulting save status. */ u16 requestSaveSlot(u16 arg0)
{
    s8 *codeByte;

    gSaveStatus = 3;
    gSaveRequestSlot = arg0;
    if (func_80012F50() == 0) {
        if (*(u16 *)(D_80107B68 + gSaveRequestSlot * 0x18) != 0) {
            if (func_8001226C(gSaveRequestSlot) == 0) {
                gSaveStatus = 0x81;
                return 0x81;
            }
            codeByte = (s8 *)&D_80103042;
            *codeByte = D_80108412[gSaveRequestSlot << 5];
            decodeTextField(D_8010A3C5, codeByte, 4);
        }
        if ((u16)saveFindTaggedSlot() != 0) {
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
