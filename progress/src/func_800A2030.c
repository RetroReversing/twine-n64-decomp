/* identical to func_80039820 in PENNY RACERS (matched), with its names changed by decompdecomp */
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

void func_800A2030(RspTask *arg0) {
    RspTask *p;

    p = &D_800FEDF0;
    func_800A81E0(arg0, p, 0x40);
    if (p->ucode) {
        p->ucode = osVirtualToPhysical((void *)p->ucode);
    }
    if (p->data) {
        p->data = osVirtualToPhysical((void *)p->data);
    }
    if (p->stack) {
        p->stack = osVirtualToPhysical((void *)p->stack);
    }
    if (p->output) {
        p->output = osVirtualToPhysical((void *)p->output);
    }
    if (p->outputSize) {
        p->outputSize = osVirtualToPhysical((void *)p->outputSize);
    }
    if (p->input) {
        p->input = osVirtualToPhysical((void *)p->input);
    }
    if (p->yield) {
        p->yield = osVirtualToPhysical((void *)p->yield);
    }
    if (p->flags & 1) {
        p->data = p->yield;
        p->dataSize = p->yieldSize;
        arg0->flags &= ~1;
        if (p->flags & 4) {
            p->ucode = *(u32 *)((arg0->yield + 0xBFC) | 0xA0000000);
        }
    }
    func_800A0220(p, 0x40);
    func_800A9280(0x2B00);
    do {
    } while (rsp_set_pc_if_halted(0x04001000) == -1);
    do {
    } while (func_800A92C0(1, 0x04000FC0, p, 0x40) == -1);
    do {
    } while (func_800A9250() != 0);
    do {
    } while (func_800A92C0(1, 0x04001000, (void *)p->boot, p->bootSize) == -1);
}
