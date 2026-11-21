typedef struct {
    u8 pad[9];
    u8 weight;
    u8 tail[2];
} Item2A9A8;

typedef struct {
    Item2A9A8 *items;
    u8 pad04[0xC];
    f32 amount;
    u8 pad14[4];
    u8 selected;
    u8 count;
    u8 pad1A[3];
    u8 progress;
} Obj2A9A8;

void func_8002A1F0(Obj2A9A8 *);

Item2A9A8 *func_8002A9A8(Obj2A9A8 *obj, s16 index) {
    u8 count;
    u8 i;
    s32 sum;

    if (obj == NULL) {
        return NULL;
    }
    if (index >= 0) {
        u8 available = obj->count;
        s16 selected;
        if (available - 1 < index) {
            selected = available - 1;
            goto store_selection;
        }
        selected = index;
store_selection:
        obj->selected = selected;
    } else {
        obj->selected = 0;
    }

    func_8002A1F0(obj);
    count = obj->count;
    sum = 0;
    if (count != 0) {
        i = 0;
        if (obj->count != count || count != 0) {
            Item2A9A8 *items = obj->items;
            do {
                sum += items[i].weight;
                i++;
            } while (i < count);
        }
        obj->amount = (1.0f / (f32)(s16)sum) * (f32)obj->progress;
    } else {
        obj->amount = 0.0f;
    }
    if (1.0f < obj->amount) {
        obj->amount = 1.0f;
    }
    return &obj->items[obj->selected];
}
