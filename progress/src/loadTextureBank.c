unsigned int dmaRomToRamUnaligned(u16 *, void *, u32);
unsigned short packFadedRgb5A1(u32, s32, s32);
u32 getDecompressedSize(u16 *);
s32 decompressData(u16 *, u16 *);
s32 getTopBumpAllocPtr();
s32 setTopBumpAllocPtr(s32);
u16 *heapAllocTagged(u32, s32);
s32 freeHeapBlock(u16 *, s32);
s32 memcpy(u16 *, u16 *, u32);
extern s32 D_0054D910;
extern u8 D_8010A4FC;
/* Loads a texture bank from ROM: reads entry/image tables, decompresses TLUT and pixel data, relocates pointers and nibble-swaps 4-bit images. */ void loadTextureBank(void *bank)
{
  u32 width;
  s32 savedState;
  s32 var_a0_2;
  long temp_a0;
  union 
  {
    u16 *pointer;
    s32 value;
  } __repair_phase_storage;
  s32 var_t0;
  u16 *imageTable;
  u16 *entryTable;
  u16 *pixelData;
  u16 *tlutData;
  u16 temp_s0;
  u32 temp_a2;
  u32 temp_v0;
  int temp_v1;
  u32 temp_v1_4;
  u32 var_a0;
  u32 __repair_phase_var_a0;
  u32 size;
  u32 i;
  u32 var_s1_2;
  u8 *temp_a3;
  u8 *var_a0_4;
  u8 temp_a1;
  u8 temp_v0_4;
  void *temp_a0_2;
  void *temp_v0_3;
  void *temp_v1_2;
  savedState = getTopBumpAllocPtr();
  entryTable = heapAllocTagged((*((u32 *) (((char *) bank) + 0x14))) * 8, 0x18);
  imageTable = heapAllocTagged((*((u32 *) (((char *) bank) + 0x1C))) * 0xC, 0x19);
  var_a0 = *((u32 *) (((char *) bank) + 0x2C));
  temp_v1 = *((u32 *) (((char *) bank) + 0x24));
  if (var_a0 < temp_v1)
  {
    var_a0 = temp_v1;
  }
  __repair_phase_storage.pointer = heapAllocTagged(var_a0, 0x2D);
  dmaRomToRamUnaligned(entryTable, (*((u32 *) (((char *) bank) + 0x10))) + ((u8 *) (&D_0054D910)), (*((u32 *) (((char *) bank) + 0x14))) * 8);
  dmaRomToRamUnaligned(imageTable, (*((u32 *) (((char *) bank) + 0x18))) + ((u8 *) (&D_0054D910)), (*((u32 *) (((char *) bank) + 0x1C))) * 0xC);
  dmaRomToRamUnaligned(__repair_phase_storage.pointer, (*((s32 *) (((char *) bank) + 0x28))) + ((u8 *) (&D_0054D910)), *((u32 *) (((char *) bank) + 0x2C)));
  size = getDecompressedSize(__repair_phase_storage.pointer);
  if (size != 0)
  {
    tlutData = heapAllocTagged(size, 0x1A);
    decompressData(tlutData, __repair_phase_storage.pointer);
  }
  else
  {
    tlutData = heapAllocTagged(*((u32 *) (((char *) bank) + 0x2C)), 0x1A);
    memcpy(tlutData, __repair_phase_storage.pointer, *((u32 *) (((char *) bank) + 0x2C)));
  }
  dmaRomToRamUnaligned(__repair_phase_storage.pointer, (*((s32 *) (((char *) bank) + 0x20))) + ((u8 *) (&D_0054D910)), *((u32 *) (((char *) bank) + 0x24)));
  size = getDecompressedSize(__repair_phase_storage.pointer);
  if (size != 0)
  {
    pixelData = heapAllocTagged(size, 0x1B);
    decompressData(pixelData, __repair_phase_storage.pointer);
  }
  else
  {
    size = *((u32 *) (((char *) bank) + 0x24));
    pixelData = heapAllocTagged(size, 0x1B);
    memcpy(pixelData, __repair_phase_storage.pointer, *((u32 *) (((char *) bank) + 0x24)));
  }
  if (D_8010A4FC != 0)
  {
    for (i = 0; i < (size >> 1); i += 1)
    {
        temp_s0 = pixelData[i];
        var_s1_2 = temp_s0 & 0xFFFF;
        temp_s0 &= 1;
        pixelData[i] = packFadedRgb5A1(var_s1_2 >> 0xB, (var_s1_2 >> 6) & 0x1F, (var_s1_2 >> 1) & 0x1F) + temp_s0;
    }
  }
  freeHeapBlock(__repair_phase_storage.pointer, 0x2D);
  i = 0;
  *((u16 **) (((char *) bank) + 0x10)) = entryTable;
  *((u16 **) (((char *) bank) + 0x18)) = imageTable;
  for (i = 0; i < ((u32) (*((u32 *) (((char *) bank) + 0x14)))); i += 1)
  {
      *((s32 *) (((char *) ((i * 8) + (*((u8 **) (((char *) bank) + 0x10))))) + 4)) = (s32) ((*((s32 *) (((char *) ((i * 8) + (*((u8 **) (((char *) bank) + 0x10))))) + 4))) * 2);
      var_t0 = i * 8;
      var_t0 += (s32) (*((u8 **) (((char *) bank) + 0x10)));
      *((void **) (((char *) var_t0) + 4)) = (void *) ((*((u32 *) (((char *) var_t0) + 4))) + ((u32) pixelData));
  }
  for (i = 0; i < ((u32) (*((u32 *) (((char *) bank) + 0x1C)))); i += 1)
  {
      temp_a0 = *((u8 **) (((char *) bank) + 0x18)); temp_v0_3 = i * 0xC + temp_a0;
      *((void **) (((char *) temp_v0_3) + 8)) = (void *) ((*((u32 *) (((char *) temp_v0_3) + 8))) + ((u32) tlutData));
  }
  { s32 height;
  for (i = 0; i < ((u32) (*((u32 *) (((char *) bank) + 0x1C)))); i += 1)
  {
      temp_a0_2 = (void *) (i * 0xC + (s32) (*((u8 **) (((char *) bank) + 0x18))));
      height = (*((u16 *) (((char *) temp_a0_2) + 4))) + 1;
      temp_a1 = *((u8 *) (((char *) temp_a0_2) + 6));
      temp_a3 = *((u8 **) (((char *) temp_a0_2) + 8));
      width = (*((u16 *) (((char *) temp_a0_2) + 2))) + 1;
      if (temp_a1 >= 2U)
      {
        height *= temp_a1;
      }
      temp_v1_4 = (u32) (width * height);
      if (!((*((u8 *) (((char *) temp_a0_2) + 0))) & 1))
      {
        temp_v1_4 >>= 1;
        if (((int) temp_v1_4) != 0)
        {
          var_a0_4 = temp_a3;
          do
          {
            temp_v0_4 = *var_a0_4;
            *var_a0_4 = (temp_v0_4 >> 4) | ((temp_v0_4 & 0xF) * 0x10);
            ++var_a0_4;
          }
          while (((u32) var_a0_4) < ((u32) temp_v1_4 + (u32) temp_a3));
        }
      }
  }
  }
  setTopBumpAllocPtr(savedState);
}

