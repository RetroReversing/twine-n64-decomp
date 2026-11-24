extern char *lookupDataEntry(s32);
extern s32 getSaveSlotIndex(s32);
extern s32 sprintf(char *, const char *, ...);
extern char D_800D2AB4[], D_800D2ABC[];
extern s16 gPlayerScores[], D_800E107E, D_800E1080;
extern char gPlayerNames[];
extern u8 gSceneType, gSaveKeyRelaxed, gBonusGoalReached;
extern s32 gSaveTotalSlots;

typedef struct { u8 pad[0x11]; u8 active; } ResultState;
typedef struct { u8 pad[0xB4]; ResultState *state; } ResultPlayer;
extern ResultPlayer *gSaveSlots[];

/* Builds the end-of-game result text: a winner message, a tie message, or the default entry if the bonus goal wasn't reached. */ char *buildWinnerMessage(void) {
    s32 i, best, player, message, count, idx; s32 score;
    s16 *winner;
    union { ResultPlayer **players; s16 *scores; } table;
    ResultPlayer *entry;
    char *text, *name, *suffix;
    s32 scratch[4];

    if (!gBonusGoalReached)
        return lookupDataEntry(3);

    text = lookupDataEntry(0x4000);
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
        sprintf(text, D_800D2AB4, name, suffix);
        return text;
draw:
        sprintf(text, D_800D2ABC, lookupDataEntry(0xEF));
        return text;
    }
    player = 0;
    if (gSceneType == 8) {
        best = 0;
        i = 0;
        if (player < gSaveTotalSlots) {
            table.players = gSaveSlots;
            do {
                entry = *table.players;
                if (entry && entry->state->active)
                    best++;
                else
                    player = (u16)getSaveSlotIndex((u16)i);
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
        table.scores = gPlayerScores;
        do {
            idx = (u16) getSaveSlotIndex((u16)i);
            score = table.scores[idx];
            if (best < score) {
                best = score;
                player = idx;
            }
            i++;
        } while (i < gSaveTotalSlots);
    }
    best = -1;
    i = 0;
    if (gSaveTotalSlots > 0) {
        table.scores = gPlayerScores;
        winner = &table.scores[player];
        do {
            idx = (u16)getSaveSlotIndex((u16)i);
            i++;
            best += table.scores[idx] == *winner;
        } while (i < gSaveTotalSlots);
    }
decided:
    if (best > 0)
        goto draw;
    suffix = lookupDataEntry(0xEE);
    name = gPlayerNames + player * 24;
    sprintf(text, D_800D2AB4, name, suffix);
    return text;
}
