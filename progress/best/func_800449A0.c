extern void func_80083D04(s32);
extern void func_80083C98(void);
extern void initMatrixPools(void);
extern void func_80064250(void);
extern void func_80073400(void);
extern s32 func_8003C7C4(void);
extern void func_8007560C(void);
extern s32 gTrackMarkers[], sBonusObjectTable[], D_8010D2C0[], D_8010D380[];
extern s32 gTrackMarkerSerial, gProbeObjectList, gObjectListHead, D_80109CB4;
extern u8 D_801002E4,D_801002E5,D_80100784,D_80102F38,D_80103020,D_8010302A,D_80103041,D_801032A4,D_801032AC,D_80103EB1,D_80107B60,D_80107ECD,D_80107ECE,D_80108F74,D_80108F94,D_801093A0,D_8010957C,D_80109A35,D_80109B1E,D_8010A2B8,D_8010A3C4,D_8010A4B8,D_8010D2B0,D_8010D36C,D_8010D374,D_80110CA8,D_80110DB1,D_80112F88,D_80117734,gSharedItemBusy;
extern u8 sPrimTintR, sPrimTintG, sPrimTintB, sAltPrimTintR, sAltPrimTintG, sAltPrimTintB, sMarkerMessageCount, gAnnounceCount;
void func_800449A0(void) {
    u32 i, j;
    s32 *p, *q, *r1, *r2;
    func_80083D04(0);
    func_80083C98();
    initMatrixPools();
    func_80064250();
    func_80073400();
    for (i = 0; i < 6; i++) gTrackMarkers[i] = 0;
    for (i = 0; i < 4; i++) sBonusObjectTable[i] = 0;
    r1 = D_8010D2C0;
    r2 = D_8010D380;
    for (i = 0; i < 6; i++) {
        p = r1;
        q = r2;
        for (j = 0; j < 6; j++) {
            *q++ = 0;
            *p++ = 0;
        }
        r1 += 7;
        r2 += 7;
    }
    gTrackMarkerSerial = 0;
    gProbeObjectList = func_8003C7C4();
    func_8007560C();
    D_801032AC = 0xA0;
    D_8010D374 = 0x60;
    sPrimTintG = 0xEF;
    sPrimTintB = 0x40;
    D_8010A4B8 = 0x10;
    gObjectListHead = 0;
    D_801032A4 = 0xFF; D_80108F74 = 0xFF; D_80102F38 = 0xFF; D_80112F88 = 0xFF; D_80107B60 = 0xFF; D_80100784 = 0xFF;
    D_80103041 = 0; D_8010302A = 0; D_8010957C = 0; D_80103EB1 = 0;
    sPrimTintR = 8; D_8010A3C4 = 0; D_80110DB1 = 8; D_80107ECE = 0;
    D_80108F94 = 0xFF; D_80103020 = 0;
    sAltPrimTintR = 0; sAltPrimTintG = 0xFF; sAltPrimTintB = 0;
    D_8010D36C = 0; D_801002E4 = 0; D_80107ECD = 0x80; D_801093A0 = 0; D_801002E5 = 0;
    D_80110CA8 = 0x80;
    sMarkerMessageCount = 0; gAnnounceCount = 0;
    D_80109B1E = 0; D_80117734 = 0; D_8010A2B8 = 0; D_8010D2B0 = 0; gSharedItemBusy = 0; D_80109A35 = 0;
    D_80109CB4 = 0;
}
