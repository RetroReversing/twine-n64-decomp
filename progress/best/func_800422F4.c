typedef struct { s32 rom, count; } TrackHeader;
typedef struct {
    u8 pad[0x24];
    s32 rom;
    s16 *track;
    u16 dep1, pad3, dep2, pad4, ref1, ref2, ref3, ref4;
    s32 ref5;
    s32 pad5;
} TrackRecord;
typedef struct { s32 rom, loaded; s32 pad[2]; } TrackState;
typedef struct { s16 track; u8 pad[230]; } TrackLink;
typedef struct { s16 track; u8 pad[14]; } TrackRef;
typedef struct { s16 *track; s32 pad[2]; } TrackGroup;
extern TrackState D_800C0780[];
extern TrackLink D_800C46DC[];
extern TrackRef D_800C447A[];
extern TrackGroup D_800C3CF8[];
extern u8 D_54D910[];
extern s32 *sTrackMarkerTable;
extern void *heapAllocTagged(s32, s32);
extern void dmaRomToRamUnaligned(void *, void *, s32);
extern void func_800426B8(s32, s32, s32);
extern s32 func_80083E24(void);
extern void func_80083E44(s32);
extern void func_80084048(void *, s32);

#define LOAD_LINK(index) \
    if (index != 0) { \
        track = D_800C46DC[index].track; \
        if (track != invalid && D_800C0780[track].loaded == 0) \
            func_800426B8(sTrackMarkerTable[2], track, 1); \
    }
#define LOAD_REF(index) \
    if (index != 0) \
        func_800426B8(sTrackMarkerTable[2], D_800C447A[index].track, 1)

void func_800422F4(s32 arg0) {
    u8 buffer[32];
    TrackHeader *header;
    TrackRecord *records, *record;
    s32 count, track, kind, marker;
    s32 invalid = -1;
    s32 token = func_80083E24();
    s32 rom = D_800C0780[arg0].rom;
    header = heapAllocTagged(0x30, 0x2D);
    dmaRomToRamUnaligned(header, D_54D910 + rom, 0x30);
    count = header->count;
    records = heapAllocTagged(count * sizeof(TrackRecord), 0x2D);
    dmaRomToRamUnaligned(records, D_54D910 + header->rom, header->count * sizeof(TrackRecord));
    if (count != 0) {
        record = records;
    next_record:
            track = *record->track;
            if (track != arg0 && D_800C0780[track].loaded == 0)
                func_800426B8(sTrackMarkerTable[2], track, 0);
            dmaRomToRamUnaligned(buffer, D_54D910 + record->rom, 0x20);
            kind = buffer[0x1E];
            switch (kind) {
            case 35: case 36: case 37: case 38:
                LOAD_LINK(record->dep1);
                LOAD_LINK(record->dep2);
                LOAD_REF(record->ref1);
                LOAD_REF(record->ref2);
                LOAD_REF(record->ref3);
                LOAD_REF(record->ref4);
                if (record->ref5 == 0)
                    goto advance;
                marker = sTrackMarkerTable[2];
                track = D_800C447A[record->ref5].track;
                goto load;
            case 13: case 14: case 15: case 16: case 17:

                LOAD_LINK(record->ref4);
                track = *D_800C3CF8[record->ref3].track;
                if (D_800C0780[track].loaded != 0)
                    goto advance;
                marker = sTrackMarkerTable[2];
                break;
            default:
                goto advance;
            }
        load:
            func_800426B8(marker, track, 1);
    advance:
        record++;
        if (record < records + count)
            goto next_record;
    }
    func_80084048(records, 0x2D);
    func_80084048(header, 0x2D);
    func_80083E44(token);
}
