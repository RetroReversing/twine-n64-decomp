typedef struct { u16 used; char name[0x16]; } Slot10A2C;
typedef struct { s32 code; u16 ext; u8 pad6[0x1A]; } Note10A2C;

s32 stringCompare(char *, char *);
extern s16 gSaveFoundSlot;
extern s32 D_800E0960;
extern s32 D_800E096C;
extern s32 D_800E0970;
extern s32 D_800E0974;
extern Slot10A2C gSaveSlotHeaders[];
extern Note10A2C D_8010840C[];
extern char D_80115308[];

/* Looks for a save slot tagged with the expected code and name; sets gSaveFoundSlot to it, or -1 if none. Returns 1 when no slot was found and the counters allow it. */
s32 saveFindTaggedSlot(void) {
    u16 i;

    gSaveFoundSlot = -1;
    for (i = 0; i < 16; i++) {
        if (gSaveSlotHeaders[i].used != 0 && D_8010840C[i].code == 0x4E4F3745 && D_8010840C[i].ext == 0x3639
            && stringCompare(gSaveSlotHeaders[i].name, D_80115308) != 0) {
            gSaveFoundSlot = i;
            break;
        }
    }
    if (gSaveFoundSlot == -1 && (D_800E0970 >= D_800E096C || D_800E0974 < D_800E0960)) {
        return 1;
    }
    return 0;
}
