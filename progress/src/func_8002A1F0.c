typedef struct {
    char pad0[6];
    u16 y;
    u8 pad8, height;
    char padA[2];
} WindowRow;
typedef struct {
    WindowRow *rows;
    void (*draw)(WindowRow *, s32, s32, u16);
    char pad8[12];
    s16 offset;
    char pad16[2];
    u8 selected, count, pad1A, limit, pad1C, scroll, fixed, pad1F, top, scale;
} ScrollWindow;
extern f32 absFloat(f32);

void func_8002A1F0(ScrollWindow *w)
{
    s16 i, before = 0, total, sum, pos = 0, old;
    s32 bound;
    s32 delta;
    s32 proposed;
    s32 h;
    s32 top;
    s32 scale;
    s32 t;
    u8 selected, m;
    u8 edge;
    u8 clamped;
    s32 y;
    WindowRow *row;

    if (!w || !w->draw)
        return;
    old = w->scroll;
    for (i = 0; i < w->selected; i++) before += w->rows[i].height;
    total = 0;
    for (i = 0; i < w->count; i++) total += w->rows[i].height;
    if (!w->fixed)
        w->scroll = before;
    if (before < w->scroll)
        w->scroll = before;
    do {
    if (before - w->scroll >= w->limit)
        w->scroll = before;
    } while (0);
    if (total - w->scroll < (edge = w->limit)) {
        clamped = total - edge < 0 ? 0 : total - edge >= 256 ? 255 : total - edge;
        w->scroll = clamped;
        if (!w->fixed) {
            sum = 0;
            i = 0;
            while (i <= w->selected) {
                    sum += w->rows[i].height;
                    if (clamped < sum) {
                        if (i >= 0) {
                            m = w->selected; if (i <= m) m = i; w->selected = m;
                        } else
                            w->selected = 0;
                        break;
                    }
                    ++i;
                }
            sum = 0;
            for (i = w->selected; i < w->count; i++) sum += w->rows[i].height;
            if (w->limit < sum) {
                w->selected = w->selected + 1 < 0 ? 0 : w->selected + 1 > w->count - 1 ? w->count - 1 : w->selected + 1;
            }
        }
    }
    delta = (w->scroll - old) * w->scale;
    i = 0;
    pos = 0;
    w->offset += delta;
    old = w->scroll * w->scale;
    bound = w->count;
    if (bound) {
        do {
            w->rows[i].y = w->offset + (pos + w->top) - old;
            row = (WindowRow *)((u8 *)(i * 12) + (s32)w->rows);
            scale = w->scale;
            h = scale * row->height;
            top = w->top;
            y = row->y;
            pos += h;
            if (y + (s16)h >= top - (u8)scale && y < top + (u8)scale * w->limit)
                w->draw(row, 1, w->selected == i, y);
            else
                w->draw(&w->rows[i], 0, w->selected == i, y);
            ++i;
        } while (i < w->count);
    }
    if (absFloat((f32)w->offset) > 2.0f) {
        s32 quarter = w->offset >> 2;
        s32 change = -quarter;
        s32 offset = w->offset;
        s32 result;
        if (change < -8)
            result = offset - 8;
        else if (change <= 8)
            result = offset - quarter;
        else
            result = offset + 8;
        w->offset = result;
    } else {
        w->offset = 0;
    }
}
