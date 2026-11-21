typedef struct { u32 words[8]; } SetupWords;
typedef struct { s8 bytes[10]; } SetupRecord;
extern u32 D_800E1328[16], D_8010A4C0[16];
typedef struct { u32 first, second; } SetupPair;
extern struct { SetupPair header; u32 rest[80]; } D_800E1368;
extern u32 sPickupSlotTable[80];
extern u32 D_800E14B0[20], gValidSaveSlotCount[20];
extern SetupPair D_801002EC;
extern struct { SetupWords header; SetupRecord records[4]; } D_800E1500;
extern SetupWords D_80112F68;
extern u8 D_80115088[];
extern u8 D_80115091[];
extern u16 D_80115092[];
extern void updateVideoMode(void);

void initSetupTables(void)
{
    u16 i;
    __builtin_memcpy(D_8010A4C0, D_800E1328, 0x40);
    D_801002EC = D_800E1368.header;
    __builtin_memcpy(sPickupSlotTable, D_800E1368.rest, 0x140);
    __builtin_memcpy(gValidSaveSlotCount, D_800E14B0, 0x50);
    D_80112F68 = D_800E1500.header;
    i = 0;
    do {
        u32 offset = i * 0xA0;
        *(SetupRecord *)(D_80115088 + offset) = D_800E1500.records[i];
        *(u16 *)((u8 *)D_80115092 + offset) = D_80115091[offset];
        i++;
    } while (i < 4);
    updateVideoMode();
}
