typedef struct { u16 value, pad; } BucketField;
typedef struct { u16 value, pad[3]; } EntryField;
typedef struct { u32 first, second; } TableEntry;
void func_8008C0D4(void);
void func_8008C11C(void);
extern s32 D_800F8D5C;
extern BucketField D_800F8D60[], D_800F8D62[];
extern EntryField D_800F9564[], D_800F9566[];
extern TableEntry D_800F9560[];
s32 func_8009811C(s32 arg0)
{
    volatile s32 pad[2];
    u32 key, bucket;
    s32 i, count, start, index;
    u16 refs;
    TableEntry *src, *dst, *base;
    BucketField *p;
    s32 offset, oldStart;

    func_8008C0D4();
    key = arg0 & 0xffff;
    bucket = key >> 6;
    count = D_800F8D60[bucket].value;
    if (count != 0) {
        start = D_800F8D62[bucket].value;
        for (i = 0; i < count; i++) {
            if (D_800F9564[start+i].value == key)
                break;
        }
        if (i < D_800F8D60[bucket].value) {
            index = start+i;
            refs = D_800F9566[index].value;
            base = D_800F9560;
            refs--;
            D_800F9566[index].value = refs;
            if (refs == 0) {
                TableEntry *prev = base - 1;
                i = index+1;
                if (i < D_800F8D5C) {
                    dst = prev + i;
                    src = base + i;
                    do {
                        *dst = *src;
                        dst++;
                        i++;
                        src++;
                    } while (i < D_800F8D5C);
                }
                p = D_800F8D60;
                offset = 0;
                do {
                    oldStart = ((BucketField *)((char *)D_800F8D62 + offset))->value;
                    if (start < oldStart)
                        p->pad = oldStart - 1;
                    offset += 4;
                    p++;
                } while (offset < 0x800);
                D_800F8D60[bucket].value--;
                D_800F8D5C--;
            }
        }
    }
    func_8008C11C();
    return 0;
}
