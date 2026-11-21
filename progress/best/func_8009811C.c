typedef struct { u16 count, start; } Bucket;
typedef struct { u32 data; u16 id, refs; } Entry;
extern Bucket D_800F8D60[];
extern Entry D_800F9560[];
extern s32 D_800F8D5C;
extern void workerLockAcquire(void), workerLockRelease(void);

s32 func_8009811C(s32 arg0) {
    u32 id, bucket;
    s32 count, start;
    s32 i, j;
    Bucket *p;
    u16 r;
    s32 pad[2];
    Entry *e;

    workerLockAcquire();
    id = arg0 & 0xFFFF;
    bucket = id >> 6;
    count = D_800F8D60[bucket].count;
    if (count == 0) goto unlock;
    {
        start = D_800F8D60[bucket].start;
        for (i = 0; i < count; i++) {
            if (D_800F9560[start + i].id == id) break;
        }
        if (i < D_800F8D60[bucket].count) {
            j = start + i;
            e = D_800F9560;
            r = D_800F9560[j].refs - 1;
            D_800F9560[j].refs = r;
            if ((r & 0xFFFF) == 0) {
                j++;
                if (j < D_800F8D5C) {
                    Entry *dst = (e - 1) + j;
                    Entry *src = e + j;
                    __repair_rows: {
                        *dst = *src;
                        dst++;
                        j++;
                        src++;
                    }
if (j < D_800F8D5C) goto __repair_rows;
                }
                p = D_800F8D60;
                for (i = 0; i < 512; i++) {
                    if (start < D_800F8D60[i].start) {
                        p->start = D_800F8D60[i].start - 1;
                    }
                    p++;
                }
                D_800F8D60[bucket].count--;
                D_800F8D5C--;
            }
        }
    }
unlock:
    workerLockRelease();
    return 0;
}


