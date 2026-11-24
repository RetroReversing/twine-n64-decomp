typedef struct { s32 time; s16 pad4; s8 b6; } Rec2B180;
extern char gTimeFmtMinSecFrac[];
extern char gTimeFmtSecFrac[];
s32 func_800A1B20(char *, const char *, ...);

/* Formats a time record as "m:ss:ff" (or "s:ff" under 60) into out; empties out if record is NULL. */ void formatTimeString(Rec2B180 *record, char *out) {
    s32 seconds;

    if (out != NULL) {
        if (record != NULL) {
            seconds = record->time;
            if (seconds >= 60) {
                func_800A1B20(out, gTimeFmtMinSecFrac, (s16)(seconds / 60), (s16)((s16)seconds % 60), record->b6);
            } else {
                func_800A1B20(out, gTimeFmtSecFrac, (s16)seconds, record->b6);
            }
        } else {
            *out = 0;
        }
    }
}
