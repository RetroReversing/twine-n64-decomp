typedef struct {
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
extern s32 D_800DD340;
extern u8 D_800DD350[];
extern u8 D_800DD780;
extern s16 gExpansionPakPresent;
extern Task6E78 *D_8010A2BC[];
extern s16 D_8010A4B0;
extern void func_800AC110(void);

void func_80006E78(void) {
    s32 size;
    s32 buf;
    s32 i;

    size = 0x800;
    if (gExpansionPakPresent != 0) {
        size = 0x4000;
    }
    size *= 8;
    D_800DD340 = heapAlloc(size, 0);
    for (i = 0; i < 3; i++) {
        if (D_8010A2BC[i] != NULL) {
            D_8010A2BC[i]->type = 1;
            D_8010A2BC[i]->flags = 0;
            D_8010A2BC[i]->ucode_boot = (void *)func_800AC110;
            D_8010A2BC[i]->ucode_boot_size = (u8 *)func_800AC1E0 - (u8 *)func_800AC110;
            D_8010A2BC[i]->ucode = (void *)D_800AC1E0;
            D_8010A2BC[i]->ucode_data = (void *)D_800D1710;
            D_8010A2BC[i]->ucode_size = 0x1000;
            D_8010A2BC[i]->ucode_data_size = 0x800;
            D_8010A2BC[i]->dram_stack = (void *)D_800DD350;
            D_8010A2BC[i]->dram_stack_size = 0x400;
            buf = D_800DD340;
            D_8010A2BC[i]->output_buff = buf;
            D_8010A2BC[i]->output_buff_size = buf + size;
            D_8010A2BC[i]->yield_data_ptr = (void *)D_800DC740;
            D_8010A2BC[i]->yield_data_size = 0xC00;
        }
    }
    D_8010A4B0 = 0;
    D_800DD780 = 0xFF;
}
