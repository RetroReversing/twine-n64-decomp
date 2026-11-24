typedef struct 
{
  s32 type;
  s32 flags;
  void *ucode_boot;
  s32 ucode_boot_size;
  void *ucode;
  s32 ucode_size;
  void *ucode_data;
  s32 ucode_data_size;
  void *dram_stack;
  s32 dram_stack_size;
  s32 output_buff;
  s32 output_buff_size;
  void *data_ptr;
  s32 data_size;
  void *yield_data_ptr;
  s32 yield_data_size;
} Task6E78;
s32 heapAlloc(s32, s32);
extern u8 D_800AC1E0[];
extern u8 func_800AC1E0[];
extern u8 D_800D1710[];
extern u8 D_800DC740[];
extern s32 gRdpFifoBuffer;
extern u8 D_800DD350[];
extern u8 D_800DD780;
extern s16 gExpansionPakPresent;
extern Task6E78 *sMatrixPoolSlots[];
extern s16 D_8010A4B0;
extern void func_800AC110(void);
/* Allocates the RDP output FIFO (larger with the Expansion Pak) and fills each gfx task slot with ucode, data, DRAM stack and FIFO pointers. */ void initGfxTasks(void)
{
  s32 fifoEntries;
  s32 fifo;
  s32 slot;
  fifoEntries = 0x800;
  if (gExpansionPakPresent != 0)
  {
    fifoEntries = 0x4000;
  }
  gRdpFifoBuffer = heapAlloc(fifoEntries * 8, 0);
  for (slot = 0; slot < 3; slot++)
  {
    if (sMatrixPoolSlots[slot] != NULL)
    {
      sMatrixPoolSlots[slot]->type = 1;
      sMatrixPoolSlots[slot]->flags = 0;
      sMatrixPoolSlots[slot]->ucode_boot = (void *) func_800AC110;
      sMatrixPoolSlots[slot]->ucode_boot_size = ((u8 *) func_800AC1E0) - ((u8 *) func_800AC110);
      sMatrixPoolSlots[slot]->ucode = (void *) D_800AC1E0;
      sMatrixPoolSlots[slot]->ucode_data = (void *) D_800D1710;
      sMatrixPoolSlots[slot]->ucode_size = 0x1000;
      sMatrixPoolSlots[slot]->ucode_data_size = 0x800;
      sMatrixPoolSlots[slot]->dram_stack = (void *) D_800DD350;
      sMatrixPoolSlots[slot]->dram_stack_size = 0x400;
      fifo = gRdpFifoBuffer;
      sMatrixPoolSlots[slot]->output_buff = fifo;
      sMatrixPoolSlots[slot]->output_buff_size = fifo + fifoEntries * 8;
      sMatrixPoolSlots[slot]->yield_data_ptr = (void *) D_800DC740;
      sMatrixPoolSlots[slot]->yield_data_size = 0xC00;
    }
  }

  D_8010A4B0 = 0;
  D_800DD780 = 0xFF;
}

