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

/* Updates a scrolling list window: clamps scroll/selection to the visible limit, draws each row, and eases the offset toward zero. */ void updateScrollWindow(ScrollWindow *window)
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

    if (!window || !window->draw)
        return;
    old = window->scroll;
    for (i = 0; i < window->selected; i++) before += window->rows[i].height;
    total = 0;
    for (i = 0; i < window->count; i++) total += window->rows[i].height;
    if (!window->fixed)
        window->scroll = before;
    if (before < window->scroll)
        window->scroll = before;
    do {
    if (before - window->scroll >= window->limit)
        window->scroll = before;
    } while (0);
    if (total - window->scroll < (edge = window->limit)) {
        clamped = total - edge < 0 ? 0 : total - edge >= 256 ? 255 : total - edge;
        window->scroll = clamped;
        if (!window->fixed) {
            sum = 0;
            i = 0;
            while (i <= window->selected) {
                    sum += window->rows[i].height;
                    if (clamped < sum) {
                        if (i >= 0) {
                            m = window->selected; if (i <= m) m = i; window->selected = m;
                        } else
                            window->selected = 0;
                        break;
                    }
                    ++i;
                }
            sum = 0;
            for (i = window->selected; i < window->count; i++) sum += window->rows[i].height;
            if (window->limit < sum) {
                window->selected = window->selected + 1 < 0 ? 0 : window->selected + 1 > window->count - 1 ? window->count - 1 : window->selected + 1;
            }
        }
    }
    delta = (window->scroll - old) * window->scale;
    i = 0;
    pos = 0;
    window->offset += delta;
    old = window->scroll * window->scale;
    bound = window->count;
    if (bound) {
        do {
            window->rows[i].y = window->offset + (pos + window->top) - old;
            row = (WindowRow *)((u8 *)(i * 12) + (s32)window->rows);
            scale = window->scale;
            h = scale * row->height;
            top = window->top;
            y = row->y;
            pos += h;
            if (y + (s16)h >= top - (u8)scale && y < top + (u8)scale * window->limit)
                window->draw(row, 1, window->selected == i, y);
            else
                window->draw(&window->rows[i], 0, window->selected == i, y);
            ++i;
        } while (i < window->count);
    }
    if (absFloat((f32)window->offset) > 2.0f) {
        s32 quarter = window->offset >> 2;
        s32 change = -quarter;
        s32 offset = window->offset;
        s32 result;
        if (change < -8)
            result = offset - 8;
        else if (change <= 8)
            result = offset - quarter;
        else
            result = offset + 8;
        window->offset = result;
    } else {
        window->offset = 0;
    }
}
