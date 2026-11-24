#define LOAD_LINK(index)     if (index != 0) {         track = D_800C46DC[index].track;         if (track != invalid && gTrackStates[track].loaded == 0)             loadTrackAssetSlot(gTrackMarkerParents[2], track, 1);     }
#define LOAD_REF(index)     if (index != 0)         loadTrackAssetSlot(gTrackMarkerParents[2], D_800C447A[index].track, 1)
typedef struct 
{
  s32 rom;
  s32 count;
} TrackHeader;
typedef struct 
{
  u8 pad[0x24];
  s32 rom;
  s16 *track;
  u16 dep1;
  u16 pad3;
  u16 dep2;
  u16 pad4;
  u16 ref1;
  u16 ref2;
  u16 ref3;
  u16 ref4;
  s32 ref5;
  s32 pad5;
} TrackRecord;
typedef struct 
{
  s32 rom;
  s32 loaded;
  s32 pad[2];
} TrackState;
typedef struct 
{
  s16 track;
  u8 pad[230];
} TrackLink;
typedef struct 
{
  s16 track;
  u8 pad[14];
} TrackRef;
typedef struct 
{
  s16 *track;
  s32 pad[2];
} TrackGroup;
extern TrackState gTrackStates[];
extern TrackLink D_800C46DC[];
extern TrackRef D_800C447A[];
extern TrackGroup gAssetSlotTable[];
extern u8 D_54D910[];
extern s32 *gTrackMarkerParents;
extern void *heapAllocTagged(s32, s32);
extern void dmaRomToRamUnaligned(void *, void *, s32);
extern void loadTrackAssetSlot(s32, s32, s32);
extern s32 getTopBumpAllocPtr(void);
extern void setTopBumpAllocPtr(s32);
extern void freeHeapBlock(void *, s32);
/* Reads the record table of a track from ROM and loads every other track it depends on or references that isn't loaded yet. */ void loadTrackDependencies(s32 trackId)
{
  u8 buffer[32];
  TrackHeader *header;
  TrackRecord *records;
  TrackRecord *record;
  s32 count;
  s32 track;
  s32 kind;
  s32 marker;
  s32 invalid;
  s32 token = getTopBumpAllocPtr();
  s32 rom = gTrackStates[trackId].rom;
  header = heapAllocTagged(0x30, 0x2D);
  dmaRomToRamUnaligned(header, D_54D910 + rom, 0x30);
  count = header->count;
  records = heapAllocTagged(count * (sizeof(TrackRecord)), 0x2D);
  dmaRomToRamUnaligned(records, D_54D910 + header->rom, header->count * (sizeof(TrackRecord)));
  if (count != 0)
  {
    invalid = -1;
    record = records;
    next_record:
    track = *record->track;

    if ((track != trackId) && (gTrackStates[track].loaded == 0))
    {
      loadTrackAssetSlot(gTrackMarkerParents[2], track, 0);
    }
    dmaRomToRamUnaligned(buffer, D_54D910 + record->rom, 0x20);
    kind = buffer[0x1E];
    switch (kind)
    {
      case 35:

      case 36:

      case 37:

      case 38:
        LOAD_LINK(record->dep1);
        LOAD_LINK(record->dep2);
        LOAD_REF(record->ref1);
        LOAD_REF(record->ref2);
        LOAD_REF(record->ref3);
        LOAD_REF(record->ref4);
        if (record->ref5 == 0)
      {
        goto advance;
      }
        marker = gTrackMarkerParents[2];
        track = D_800C447A[record->ref5].track;
        goto load;

      case 13:

      case 14:

      case 15:

      case 16:

      case 17:
        LOAD_LINK(record->ref4);
        track = *gAssetSlotTable[record->ref3].track;
        if (gTrackStates[track].loaded != 0)
      {
        goto advance;
      }
        marker = gTrackMarkerParents[2];
        break;

      default:
        goto advance;

    }

 do { load: loadTrackAssetSlot(marker, track, 1); advance: record++; if (((u32) record) < ((count * 0x44) + ((u32) records))) { goto next_record; } } while (0);
  }
  do
  {
    freeHeapBlock(records, 0x2D);
  }
  while (0);
  do
  {
    freeHeapBlock(header, 0x2D);
  }
  while (0);
  setTopBumpAllocPtr(token);
}
