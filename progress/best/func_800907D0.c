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
extern Seq *D_800EDA8C;
extern s32 D_801002D8;
extern s32 D_8010A514;

void func_800907D0(s32 base) {
    Ev *p;
    u32 v;
    s32 tempo;
    u32 hi;
    u32 end;

    p = D_800EDA8C->list;
    if (p != NULL) {
        D_800EDA8C->next = p;
        D_800EDA8C->base = base;
        D_800EDA8C->f70 = 0;
        if (D_800EDA8C->list != NULL && D_800EDA8C->next->time != (u32)-1) {
            end = -1;
        loop:
            if ((u32)(D_800EDA8C->base + D_800EDA8C->half) >= D_800EDA8C->next->time) {
                { s32 val = D_800EDA8C->next->value;
                D_800EDA8C->cur = val;
                func_8008CDC0(val, D_800EDA87, D_800EDA8C); }
                D_800EDA8C->next = D_800EDA8C->next + 1;
                if (D_800EDA8C->next->time != end) {
                    goto loop;
                }
            }
        }
        tempo = (D_801002D8 << 16) / D_8010A514;
        v = (((D_800EDA8C->cur * 0xC00) / 60 * tempo) >> 3) * D_800EDA8C->scale;
        hi = v >> 24;
        D_800EDA8C->lo = (v >> 8) & 0xFFFF;
        D_800EDA8C->hi = hi;
        D_800EDA8C->half = (s32)hi >> 1;
    }
}
