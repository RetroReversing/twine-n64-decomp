typedef struct SearchRomData {
    s32 pointsOffset;
    s16 pointsSize;
    s32 linksOffset;
    s16 linksSize;
} SearchRomData;
typedef struct SearchIndex {
    s16 id;
    s32 offset;
} SearchIndex;
typedef struct SearchPoint {
    s32 x, y, z;
} SearchPoint;
typedef struct SearchLink {
    s16 from, to, flags;
} SearchLink;
typedef struct SearchEntry {
    u8 pad[16];
    SearchPoint *point;
    struct SearchEntry *links[16];
    s32 nearest;
} SearchEntry;
extern SearchIndex func_8011EB60[];
extern SearchEntry *sSearchEntries;
extern s32 sSearchEntryCount;
extern void dmaRomToRamUnaligned(u8 *, s32, u32);
extern void *heapAllocTagged(s32, s32);
extern void func_80084048(void *, s32);
extern s32 probeFindNearestObject(SearchPoint *);

void func_80117BF4(s16 id)
{
    SearchRomData rom;
    s32 offset = 0;
    SearchIndex *record;
    SearchPoint *points;
    SearchLink *links;
    s16 pointCount, linkCount;
    s32 i, j;
    SearchEntry *entry, *base;
    s16 from, to;
    s32 cursor;

    extern s16 D_8011EB60;
    s32 first = D_8011EB60;
    sSearchEntryCount = 0;
    if (first != -1) {
        s32 wanted = id;
        s32 value;
        record = func_8011EB60;
        cursor = 0;
        value = record->id;
        do {
            record++;
            if (value == wanted) {
                offset = *(s32 *)(0x80120000U + cursor - 0x149c);
                goto read_header;
            }
            value = record->id;
            cursor += 8;
        } while (value != -1);
    }
read_header:
    dmaRomToRamUnaligned((u8 *)&rom, offset + 0x54d910, sizeof(rom));
    *(SearchEntry **)(0x80120000U - 0xf98) = heapAllocTagged(0xb000, 0x34);
    points = heapAllocTagged(rom.pointsSize, 0x34);
    links = heapAllocTagged(rom.linksSize, 0x34);
    dmaRomToRamUnaligned((u8 *)points, rom.pointsOffset + 0x54d910, rom.pointsSize);
    dmaRomToRamUnaligned((u8 *)links, rom.linksOffset + 0x54d910, rom.linksSize);
    pointCount = (u32)rom.pointsSize / 12;
    linkCount = (u32)rom.linksSize / 6;
    for (i = 0; i < pointCount; i++) {
        entry = (SearchEntry *)((u8 *)(i * sizeof(SearchEntry)) + (u32)sSearchEntries);
        entry->point = points;
        for (j = 15; j >= 0; j--)
            entry->links[j] = 0;
        points++;
        sSearchEntries[i].nearest = probeFindNearestObject(sSearchEntries[i].point);
        sSearchEntryCount++;
    }
    for (i = 0; i < linkCount; i++) {
        base = sSearchEntries;
        from = links[i].from;
        to = links[i].to;
        for (j = 0; j < 16; j++) {
            if (base[from].links[j] == 0) {
                base[from].links[j] = &base[to];
                break;
            }
        }
        for (j = 0; j < 16; j++) {
            if (base[to].links[j] == 0) {
                base[to].links[j] = &base[from];
                break;
            }
        }
    }
    func_80084048(links, 0x34);
}
