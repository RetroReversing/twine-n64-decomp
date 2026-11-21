extern double sqrt(double);
f32 func_8009532C(f32 *v) {
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];
    f32 length = sqrt(x*x + y*y + z*z);
    v[0] = x / length;
    v[1] = v[1] / length;
    v[2] = v[2] / length;
    return length;
}

typedef struct {
    u8 pad[0x1e];
    u16 field1e, field20, field22, field24;
    u32 field28;
} Record22AD8;
extern Record22AD8 *D_800B7CF4;
extern u16 D_800E0EE0, D_800E0EE2, D_800E0EE4, D_800E0EE6;
extern s32 func_800162BC(s32);

void func_80022AD8(s32 id) {
    Record22AD8 *p;
    u16 a, b, c, d;
    u32 flags;
    if (D_800B7CF4 == NULL && (D_800B7CF4 = (Record22AD8 *)func_800162BC(id & 0xff)) == NULL)
        return;
    p = D_800B7CF4;
    a = D_800E0EE0;
    b = D_800E0EE2;
    c = D_800E0EE4;
    flags = p->field28;
    p->field20 = a;
    d = D_800E0EE6;
    p->field1e = 0x1000;
    flags = (flags & ~0xfc) | 0x1c;
    p->field22 = b;
    p->field24 = c;
    p->field28 = flags;
    *(u8 *)&p->field28 = d;
}

typedef struct {
    u8 pad[8];
    void *handle;
    u8 tail[0x1C];
} Entry2AF;

typedef struct {
    Entry2AF *entries;
    void *aux;
    void *handle;
    s8 state;
    u8 pad;
    u8 count;
} Record2AF;

void freeMenuItemRecord(void *handle);

void func_8002AF44(Record2AF *rec) {
    if (rec && rec->entries) {
        u16 i = 0;
        if (rec->count) {
            u32 index = i;
            do {
                Entry2AF *entry = &rec->entries[index];
                if (entry->handle) {
                    freeMenuItemRecord(entry->handle);
                    entry->handle = 0;
                }
                i++;
                index = i;
            } while ((u16)i < rec->count);
        }
        freeMenuItemRecord(rec->handle);
        rec->handle = 0;
        rec->aux = 0;
        rec->entries = 0;
        rec->count = 0;
        rec->state = 0;
    }
}

typedef struct {
    u8 signature[4];
    u32 first, second;
} Header148;

typedef struct {
    u32 unused;
    Header148 *header;
    u32 first, second;
    s32 format;
    u32 reserved;
    u32 flag;
    s32 error;
} Reader148;

u32 func_8001495C(void *, u32);

void parse_edl_header(Reader148 *reader) {
    Header148 *header = reader->header;
    s32 format;
    s32 error;
    if (header->signature[0] == 'E') {
        if (header->signature[1] == 'D') {
            if (header->signature[2] == 'L') goto valid;
            error = -3;
            goto fail;
        }
        error = -3;
        goto fail;
    }
    error = -3;
    goto fail;
valid:
    reader->flag = header->signature[3] >> 7;
    format = reader->header->signature[3] & 0x7F;
    reader->format = format;
    if (format < 3) {
        error = -4;
        if (format < 0) goto fail;
        reader->error = 0;
        reader->first = func_8001495C(reader, reader->header->first);
        reader->second = func_8001495C(reader, reader->header->second);
        return;
    }
    error = -4;
fail:
    reader->error = error;
}
