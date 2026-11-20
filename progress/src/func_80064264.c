extern u8 D_80115094[];
s32 func_800819EC(s32 arg0, s32 arg1) {
    s32 stride = arg0 * 160;
    u8 *base = D_80115094;
    u8 *channel = base + stride;
    u8 *slot = channel + arg1 * 2;
    u8 index = slot[1];
    if (index != 0) {
        s32 value = *(s32 *)((base + 0x70) + index * 4 + stride);
        if (!(slot[0] & 0x40)) {
            if (value > 0)
                return value;
        } else if (value < 0) {
            return value;
        }
    }
    slot = channel + arg1 * 2;
    {
        u8 flags = slot[0];
        if (!(flags & 2))
            return 0;
        if (flags & 0x80) {
            slot[0] = flags & 0x7f;
            return 0;
        }
        return ((-(s32)((flags & 0x20) != 0) << 16) | 0x10000);
    }
}

typedef struct { s32 pad[2]; s32 id; } Group44D;
extern Group44D *gTrackMarkerTable;
extern void func_800422F4(s16);
extern void func_800426B8(s32, s16, s32);
void func_80044D28(s16 *arg0) {
    s16 *entry = arg0;
    if (*arg0 >= 0) {
        do {
            s16 id;
            s32 group;
            func_800422F4(*entry);
            group = gTrackMarkerTable->id;
            id = *entry++;
            func_800426B8(group, id, 1);
        } while (*entry >= 0);
    }
}

typedef struct { s32 x, y, z; } Vec642;
extern Vec642 D_80110B28[], D_80108608[];
extern s32 D_801002E0;
extern s8 D_80100BE0[];
void func_80064264(Vec642 *arg0, Vec642 *arg1, s8 arg2) {
    D_80110B28[D_801002E0] = *arg0;
    D_80108608[D_801002E0] = *arg1;
    D_80100BE0[D_801002E0] = arg2;
    D_801002E0++;
}

typedef struct { f32 x, y, z; } Vec77;
typedef struct { f32 x, y, z; u16 flags; u8 pad[0x2a]; f32 height; } Floor77;
typedef struct { u8 pad[0x20]; s32 id; Vec77 pos; u8 pad30[0x38]; Floor77 *floor; } Obj77;
typedef struct { Vec77 pos; s32 pad; } Output77;
extern s8 func_8004C750(s32, Vec77 *, Output77 *, Output77 *, f32, s32, s32, s32);
void func_80077C00(Obj77 *arg0) {
    Vec77 pos = arg0->pos;
    Output77 hit, other;
    pos.y += 1.0f;
    if (func_8004C750(arg0->id, &pos, &hit, &other, 25.0f, 0, 0, 0)) {
        arg0->floor->flags |= 8;
        arg0->pos.y = hit.pos.y + arg0->floor->height;
        arg0->floor->z = hit.pos.y;
    }
}
