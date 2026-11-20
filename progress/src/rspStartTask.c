/* identical to func_80039820 in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
typedef struct RspTask {
    u32 type;
    u32 flags;
    u32 boot;
    u32 bootSize;
    u32 ucode;
    u32 ucodeSize;
    u32 data;
    u32 dataSize;
    u32 stack;
    u32 stackSize;
    u32 output;
    u32 outputSize;
    u32 input;
    u32 inputSize;
    u32 yield;
    u32 yieldSize;
} RspTask;

extern RspTask D_800FEDF0;

void func_800A81E0(void *, void *, s32);
u32 osVirtualToPhysical(void *);
void func_800A0220(void *, s32);
void func_800A9280(s32);
s32 rsp_set_pc_if_halted(u32);
s32 func_800A92C0(s32, u32, void *, u32);
s32 func_800A9250(void);

/* Copies the RSP task into the global work block, converts its pointers to physical addresses and boots the RSP. */ void rspStartTask(RspTask *arg0) {
    RspTask *task;

    task = &D_800FEDF0;
    func_800A81E0(arg0, task, 0x40);
    if (task->ucode) {
        task->ucode = osVirtualToPhysical((void *)task->ucode);
    }
    if (task->data) {
        task->data = osVirtualToPhysical((void *)task->data);
    }
    if (task->stack) {
        task->stack = osVirtualToPhysical((void *)task->stack);
    }
    if (task->output) {
        task->output = osVirtualToPhysical((void *)task->output);
    }
    if (task->outputSize) {
        task->outputSize = osVirtualToPhysical((void *)task->outputSize);
    }
    if (task->input) {
        task->input = osVirtualToPhysical((void *)task->input);
    }
    if (task->yield) {
        task->yield = osVirtualToPhysical((void *)task->yield);
    }
    if (task->flags & 1) {
        task->data = task->yield;
        task->dataSize = task->yieldSize;
        arg0->flags &= ~1;
        if (task->flags & 4) {
            task->ucode = *(u32 *)((arg0->yield + 0xBFC) | 0xA0000000);
        }
    }
    func_800A0220(task, 0x40);
    func_800A9280(0x2B00);
    do {
    } while (rsp_set_pc_if_halted(0x04001000) == -1);
    do {
    } while (func_800A92C0(1, 0x04000FC0, task, 0x40) == -1);
    do {
    } while (func_800A9250() != 0);
    do {
    } while (func_800A92C0(1, 0x04001000, (void *)task->boot, task->bootSize) == -1);
}
