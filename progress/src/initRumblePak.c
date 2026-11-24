typedef struct { u8 pad[0x68]; } Pfs10690;
s32 osMotorInit(void *, Pfs10690 *, s32);
s32 __osMotorAccess(Pfs10690 *, s32);
extern Pfs10690 gSaveSlotTable[];
extern u16 gSaveSlotValid[];
extern u16 D_8010A3A0[];
extern u8 gSiMesgQueue[];

/* Initializes the rumble pak on a controller channel and probes it; on failure marks the slot invalid. */ void initRumblePak(s32 channel) {
    s32 i;

    if (osMotorInit(gSiMesgQueue, &gSaveSlotTable[(u16)channel], (u16)channel) == 0) {
        for (i = 0; i < 3; i++) {
            __osMotorAccess(&gSaveSlotTable[(u16)channel], 0);
        }
        D_8010A3A0[(u16)channel] &= 0xFFFC;
    } else {
        gSaveSlotValid[(u16)channel] = 0;
    }
}
