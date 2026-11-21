s32 func_8001226C(s32);
u16 func_8001233C(void);
s32 func_80012F50();
extern u16 gSaveStatus;
extern s32 gSaveRequestSlot;
u16 func_80012A0C(s32 arg0) {
    s32 temp_a0;
    temp_a0 = arg0 & 0xFFFF;
    gSaveStatus = 1;
    gSaveRequestSlot = temp_a0;
    if (!(func_80012F50() & 0xFFFF)) {
        if ((func_8001226C(gSaveRequestSlot) == 0) || (gSaveRequestSlot >= 0x10)) {
            gSaveStatus = 0x82;
            return 0x82U;
        }
        if (!(func_8001233C() & 0xFFFF)) {
            gSaveStatus = 1;
            return 1U;
        }
    }
    return gSaveStatus;
}
