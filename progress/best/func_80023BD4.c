extern char *lookupDataEntry(s32);
extern s32 func_80022DBC(s32);
extern s32 sprintf(char *, const char *, ...);
extern char D_800D2AB4[], D_800D2ABC[];
extern s16 D_800E1068[], D_800E107E, D_800E1080;
extern char D_801001A4[];
extern u8 gSceneType, gSaveKeyRelaxed, D_801002AC;
extern s32 gSaveTotalSlots;

typedef struct { u8 pad[0x11]; u8 active; } ResultState;
typedef struct { u8 pad[0xB4]; ResultState *state; } ResultPlayer;
extern ResultPlayer *D_80102CD0[];

char *func_80023BD4(void) {
    s32 i, best, player, message, score, count, idx;
    s16 *winner;
    union { ResultPlayer **players; s16 *scores; } table;
    ResultPlayer *entry;
    char *buffer, *name, *suffix;
    s32 scratch[4];

    if (!D_801002AC)
        return lookupDataEntry(3);

    buffer = lookupDataEntry(0x4000);
    best = -9999;
    if (gSaveKeyRelaxed) {
        if (D_800E107E > D_800E1080)
            message = 0x6E;
        else if (D_800E107E < D_800E1080)
            message = 0x6F;
        else
            goto draw;
        name = lookupDataEntry(message);
        suffix = lookupDataEntry(0xEE);
        sprintf(buffer, D_800D2AB4, name, suffix);
        return buffer;
draw:
        sprintf(buffer, D_800D2ABC, lookupDataEntry(0xEF));
        return buffer;
    }
    player = 0;
    if (gSceneType == 8) {
        best = 0;
        i = 0;
        if (player < gSaveTotalSlots) {
            table.players = D_80102CD0;
            do {
                entry = *table.players;
                if (entry && entry->state->active)
                    best++;
                else
                    player = (u16)func_80022DBC((u16)i);
                i++;
                table.players++;
            } while (i < gSaveTotalSlots);
        }
        count = gSaveTotalSlots - 1;
        if (best == count) {
            best = 0;
            goto decided;
        }
        best = -99;
        player = 0;
    }
    i = 0;
    if (gSaveTotalSlots > 0) {
        table.scores = D_800E1068;
        do {
            u16 slot = func_80022DBC((u16)i);
            score = table.scores[slot];
            if (best < score) {
                best = score;
                player = slot;
            }
            i++;
        } while (i < gSaveTotalSlots);
    }
    best = -1;
    i = 0;
    if (gSaveTotalSlots > 0) {
        table.scores = D_800E1068;
        winner = &table.scores[player];
        do {
            idx = (u16)func_80022DBC((u16)i);
            score = table.scores[idx];
            i++;
            best += *winner == score;
        } while (i < gSaveTotalSlots);
    }
decided:
    if (best > 0)
        goto draw;
    suffix = lookupDataEntry(0xEE);
    name = D_801001A4 + player * 24;
    sprintf(buffer, D_800D2AB4, name, suffix);
    return buffer;
}
