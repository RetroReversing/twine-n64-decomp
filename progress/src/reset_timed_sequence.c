typedef struct { u32 time; s32 value; } Ev;
typedef struct {
    u8 pad[0x118];
    s32 lo;      /* 0x118 */
    u32 hi;      /* 0x11C */
    s32 half;    /* 0x120 */
    u32 cur;     /* 0x124 */
    u8 pad2[0xF68 - 0x128];
    Ev *list;    /* 0xF68 */
    Ev *next;    /* 0xF6C */
    s32 f70;     /* 0xF70 */
    s32 base;    /* 0xF74 */
    u8 pad3[0xFC2 - 0xF78];
    u16 scale;   /* 0xFC2 */
} Seq;
void func_8008CDC0(s32, u8, Seq *);
extern u8 D_800EDA87;
extern Seq *gSeqPlayer;
extern s32 D_801002D8;
extern s32 gAudioOutputRate;

/* Rewinds the sequence player to the event list, fires events already due at this base time, then recomputes the output position and half-step values from the current tempo. */ void reset_timed_sequence(s32 base) {
    Ev *event;
    u32 v;
    s32 tempoScale;
    u32 hi;
    u32 end;

    event = gSeqPlayer->list;
    if (event != NULL) {
        gSeqPlayer->next = event;
        gSeqPlayer->base = base;
        gSeqPlayer->f70 = 0;
        if (gSeqPlayer->list != NULL && gSeqPlayer->next->time != (u32)-1) {
            end = -1;
        loop:
            if ((u32)(gSeqPlayer->base + gSeqPlayer->half) >= gSeqPlayer->next->time) {
                { s32 val = gSeqPlayer->next->value;
                gSeqPlayer->cur = val;
                func_8008CDC0(val, D_800EDA87, gSeqPlayer); }
                gSeqPlayer->next = gSeqPlayer->next + 1;
                if (gSeqPlayer->next->time != end) {
                    goto loop;
                }
            }
        }
        tempoScale = (D_801002D8 << 16) / gAudioOutputRate;
        {
        u32 lowBits = (((gSeqPlayer->cur * 0xC00) / 60 * tempoScale) >> 3);
        u16 scale = gSeqPlayer->scale;
        v = lowBits * scale;
        lowBits = (v >> 8) & 0xFFFF;
        v >>= 24;
        gSeqPlayer->hi = v;
        gSeqPlayer->lo = lowBits;
        gSeqPlayer->half = (s32)v >> 1;
        }
    }
}
