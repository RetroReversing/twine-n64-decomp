extern const char sFmtEntryName[];
static __inline__ u8 __repair_inline(u8 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 formatTextEntry();
s32 updateActiveMenuState();
s32 lookupDataEntry();
extern char sSaveSlotInfo[];
extern u8 gPickupSavedByte;
extern void *gSaveMenuState;

void func_8001AA98(void) {
    s32 var_a0;
    s32 temp_s0;
    u32 temp_v1;
    s32 temp_s1;

    updateActiveMenuState();
    if ((*(u8 *)((char *)(gSaveMenuState) + 0x2D)) != 0) {
        temp_s0 = (*(s32 *)((char *)(gSaveMenuState) + 0x18)) + 0x28;
        temp_s1 = __repair_inline(*(sSaveSlotInfo + (gPickupSavedByte * 0x18)));
        temp_v1 = temp_s1 & 0xFFFF;
        switch (temp_v1) {
        case 0:
            var_a0 = 0xA;
block_9:
            formatTextEntry(temp_s0, sFmtEntryName, lookupDataEntry(var_a0));
            break;
        case 1:
            var_a0 = 9;
            goto block_9;
        case 2:
            var_a0 = 0x6B;
            goto block_9;
        case 3:
            var_a0 = 0x6C;
            {
            formatTextEntry(temp_s0, sFmtEntryName, lookupDataEntry(var_a0));break;}
        case 4:
            var_a0 = 0x296;
            {
            formatTextEntry(temp_s0, sFmtEntryName, lookupDataEntry(var_a0));break;}
        case 5:
            var_a0 = 0x297;
            {
            formatTextEntry(temp_s0, sFmtEntryName, lookupDataEntry(var_a0));break;}
        }
        *(sSaveSlotInfo + (gPickupSavedByte * 0x18)) = temp_s1;
    }
}
