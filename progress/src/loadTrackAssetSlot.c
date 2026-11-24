void dmaRomToRamUnaligned();
s32 stubNoopHook();
s32 noopStubTrackModel();
s32 getDecompressedSize();
s32 decompressData();
s32 initAssetSlotFromSpawnDef();
void loadTextureBank();
s32 getTopBumpAllocPtr(void);
s32 setTopBumpAllocPtr();
s32 freeHeapBlock();
u16 *heapAllocTagged();
s32 memcpy();
s32 memset();
extern char D_54D910[];
extern char gTrackStates[];
extern char gAssetSlotHeader[];
extern char gAssetSlotEntries[];
extern char gAssetSlotEntryCount[];
extern f32 gSavedActorVelX;
extern f32 gSavedActorVelY;
extern f32 gSavedActorVelZ;
extern s8 D_80109A35;
extern s16 gExpansionPakPresent;
extern u8 gSharedItemBusy;
/* Loads a track asset slot once: reads its header and mesh table from ROM, DMAs and decompresses each mesh's data into the slot's entries, then frees the temporary buffers. */ void loadTrackAssetSlot(s32 trackId, s32 slot, u8 loadFlag)
{
  struct 
  {
    u32 mesh;
    u16 meshCount;
    u16 meshCountPadding;
    u32 index;
    u16 indexCount;
    u16 indexCountPadding;
    u32 section;
    u16 sectionCount;
    u16 sectionCountPadding;
    u32 packed;
    u16 packedSize;
    u16 packedSizePadding;
  } header;
  s32 expansionPresent;
  
  u8 sp3F;
  s32 savedAllocPtr;
  u16 *meshTable;
  u16 sp56;
  u16 *packedOut;
  u16 *meshOut;
  u16 *indexOut;
  unsigned int temp_s1;
  s32 slotOffset;
  u16 *sectionOut;
  u16 *slotHeader;
  u16 *sectionBuf;
  u16 *indexBuf;
  u16 *meshBuf;
  u16 *packedBuf;
  u16 *temp_v0;
  u32 var_s5;
  u16 *temp_v0_3;
  u16 *temp_v0_4;
  struct 
  {
    u16 id;
    u16 size;
    u32 fields[8];
    s32 rom;
    u32 tail[7];
  } *var_s0;
  u16 *var_s0_2;
  u16 *var_s2;
  long temp_s0_2;
  u16 temp_s0_3;
  s32 temp_s0_4;
  u16 temp_v1;
  u16 var_fp;
  u32 var_s1;
  u16 *temp_v0_2;
  u16 var_s7;
  u32 var_s3;
  unsigned long meshCountTotal;
  slotOffset = slot * 0x10;
  sp3F = loadFlag;
  if ((*((s32 *) (((char *) gAssetSlotHeader) + slotOffset))) == 0)
  {
    var_s5 = 0;
    savedAllocPtr = getTopBumpAllocPtr();
    temp_s1 = *((s32 *) (((char *) gTrackStates) + slotOffset));
    slotHeader = heapAllocTagged(0x30U, 0x17);
    var_fp = 0;
    var_s7 = 0;
    sp56 = 0;
    stubNoopHook();
    temp_v0 = heapAllocTagged((*((s32 *) (((char *) gAssetSlotEntryCount) + slotOffset))) * 0x4C, 0xA);
    var_s3 = 0;
    *((s32 *) (((char *) gAssetSlotEntries) + ((int) slotOffset))) = temp_v0;
    memset(temp_v0, 0, (*((s32 *) (((char *) gAssetSlotEntryCount) + slotOffset))) * 0x4C);
    dmaRomToRamUnaligned(slotHeader, temp_s1 + ((u32) (&D_54D910)), 0x30U);
    *((s32 *) (((char *) gAssetSlotHeader) + slotOffset)) = slotHeader;
    meshCountTotal = *((u32 *) (((char *) slotHeader) + 4));
    var_s1 = 0;
    meshTable = heapAllocTagged(meshCountTotal * 0x44, 0x2D);
    dmaRomToRamUnaligned(meshTable, (*((s32 *) (((char *) slotHeader) + 0))) + ((u32) (&D_54D910)), (*((u32 *) (((char *) slotHeader) + 4))) * 0x44);
    gSavedActorVelX = (gSavedActorVelY = (gSavedActorVelZ = 0.0f));
    loadTextureBank(slotHeader);
    if (var_s3 < meshCountTotal)
    {
      do
      {
        var_s0 = (void *) ((char *) meshTable + var_s3 * 0x44);
        dmaRomToRamUnaligned((u16 *) (&header), var_s0->rom + ((u32) (&D_54D910)), 0x20U);
        if (var_s5 < header.meshCount)
        {
          var_s5 = header.meshCount;
        }
        if (var_fp < header.indexCount)
        {
          var_fp = header.indexCount;
        }
        if (sp56 < header.sectionCount)
        {
          sp56 = header.sectionCount;
        }
        if (var_s1 < header.packedSize)
        {
          var_s1 = header.packedSize;
        }
        temp_v1 = var_s0->size;
        if (var_s7 < temp_v1)
        {
          var_s7 = temp_v1;
        }
        var_s3 += 1;
      }
      while (var_s3 < meshCountTotal);
    }
    packedBuf = heapAllocTagged(var_s1, 0x2D);
    packedOut = heapAllocTagged(var_s1 * 3, 0x2D);
    temp_s0_2 = var_s5 * 0xC;
    meshBuf = heapAllocTagged(temp_s0_2, 0x2D);
    meshOut = heapAllocTagged(temp_s0_2, 0x2D);
    temp_s0_2 = var_fp * 4;
    indexBuf = heapAllocTagged(temp_s0_2, 0x2D);
    indexOut = heapAllocTagged((s32) temp_s0_2, 0x2D);
    temp_s0_4 = sp56 * 4;
    sectionBuf = heapAllocTagged(temp_s0_4, 0x2D);
    sectionOut = heapAllocTagged(temp_s0_4, 0x2D);
    var_s2 = meshTable;
    if (meshCountTotal != 0)
    {
      var_s0_2 = (u16 *) (((char *) var_s2) + 0x24);
      do
      {
        var_s1 = *((s32 *) (((char *) gAssetSlotEntries) + ((*(*((s16 **) (((char *) var_s0_2) + 4)))) * 0x10)));
        expansionPresent = gExpansionPakPresent;
        *((u16 **) (((char *) (((*var_s2) * 0x4C) + var_s1)) + 4)) = (u16 *) (*((u16 **) (((char *) var_s0_2) + 0)));
        if (expansionPresent && (gSharedItemBusy == 0))
        {
          *((u8 *) (((char *) (((*var_s2) * 0x4C) + var_s1)) + 0x46)) = 0x80;
        }
        else
        {
          *((s8 *) (((char *) (((*var_s2) * 0x4C) + var_s1)) + 0x46)) = 0;
        }
        if ((*((u8 *) (((char *) (((*var_s2) * 0x4C) + var_s1)) + 0x46))) == 0)
        {
          D_80109A35 = 1;
        }
        dmaRomToRamUnaligned((u16 *) (&header), (*((u32 *) (((char *) var_s0_2) + 0))) + ((u32) (&D_54D910)), 0x20U);
        *((u16 **) (((char *) var_s0_2) + 0)) = (u16 *) (&header);
        if (!((*((u8 *) (((char *) (((*var_s2) * 0x4C) + var_s1)) + 0x45))) != 0))
        {
          dmaRomToRamUnaligned(packedBuf, header.packed + ((u32) (&D_54D910)), header.packedSize);
          temp_v0_2 = *((u16 **) (((char *) var_s0_2) + 0));
          dmaRomToRamUnaligned(indexBuf, (*((u32 *) (((char *) temp_v0_2) + 8))) + ((u32) (&D_54D910)), (*((u16 *) (((char *) temp_v0_2) + 0xC))) * 4);
          temp_v0_3 = *((u16 **) (((char *) var_s0_2) + 0));
          dmaRomToRamUnaligned(sectionBuf, (*((u32 *) (((char *) temp_v0_3) + 0x10))) + ((u32) (&D_54D910)), (*((u16 *) (((char *) temp_v0_3) + 0x14))) * 4);
          temp_v0_4 = *((u16 **) (((char *) var_s0_2) + 0));
          dmaRomToRamUnaligned(meshBuf, (*((u32 *) (((char *) temp_v0_4) + 0))) + ((u32) (&D_54D910)), (*((u16 *) (((char *) temp_v0_4) + 4))) * 0xC);
          if (getDecompressedSize(meshBuf) != 0)
          {
            decompressData(meshOut, meshBuf);
          }
          else
          {
            memcpy(meshOut, meshBuf, header.meshCount * 0xC);
          }
          if (getDecompressedSize(packedBuf) != 0)
          {
            decompressData(packedOut, packedBuf);
          }
          else
          {
            memcpy(packedOut, packedBuf, *((u16 *) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 0x1C)));
          }
          if (getDecompressedSize(indexBuf) != 0)
          {
            decompressData(indexOut, indexBuf);
          }
          else
          {
            memcpy(indexOut, indexBuf, (*((u16 *) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 0xC))) * 4);
          }
          if (getDecompressedSize(sectionBuf) != 0)
          {
            decompressData(sectionOut, sectionBuf);
          }
          else
          {
            memcpy(sectionOut, sectionBuf, (*((u16 *) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 0x14))) * 4);
          }
          *((u16 **) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 0x18)) = packedOut;
          *((u16 **) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 0)) = meshOut;
          *((u16 **) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 8)) = indexOut;
          *((u16 **) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 0x10)) = sectionOut;
        }
        else
        {
          header.packed = 0;
          *((u16 **) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 0)) = NULL;
          *((u16 **) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 8)) = NULL;
          *((u16 **) (((char *) (*((u16 **) (((char *) var_s0_2) + 0)))) + 0x10)) = NULL;
        }
        initAssetSlotFromSpawnDef(trackId, var_s2, (s8) sp3F);
        var_s0_2 = (u16 *) (((char *) var_s0_2) + 0x44);
        meshCountTotal -= 1;
        var_s2 = (u16 *) (((char *) var_s2) + 0x44);
      }
      while (meshCountTotal != 0);
    }
    freeHeapBlock(packedBuf, 0x2D);
    freeHeapBlock(packedOut, 0x2D);
    freeHeapBlock(meshBuf, 0x2D);
    freeHeapBlock(meshOut, 0x2D);
    freeHeapBlock(indexBuf, 0x2D);
    freeHeapBlock(indexOut, 0x2D);
    freeHeapBlock(sectionBuf, 0x2D);
    freeHeapBlock(sectionOut, 0x2D);
    noopStubTrackModel();
    freeHeapBlock(meshTable, 0x2D);
    setTopBumpAllocPtr(savedAllocPtr);
  }
}
