typedef struct Rec {
    s32 pad0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 idx;
    s32 reg;
} Rec;

extern Rec *D_800CFDA0[];

s32 func_800A7EC0(Rec *arg0, s32 arg1, s32 arg2) {
    Rec *temp_a3;
    u8 temp_t0;

    if (*(vu32 *)0xA4600010 & 3) {
        do {
        } while (*(vu32 *)0xA4600010 & 3);
    }
    temp_t0 = arg0->idx;
    temp_a3 = D_800CFDA0[temp_t0];
    if (temp_a3->f4 != arg0->f4) {
        if (temp_t0 == 0) {
            if (temp_a3->f5 != arg0->f5) {
                *(vu32 *)0xA4600014 = arg0->f5;
            }
            if (temp_a3->f6 != arg0->f6) {
                *(vu32 *)0xA460001C = arg0->f6;
            }
            if (temp_a3->f7 != arg0->f7) {
                *(vu32 *)0xA4600020 = arg0->f7;
            }
            if (temp_a3->f8 != arg0->f8) {
                *(vu32 *)0xA4600018 = arg0->f8;
            }
        } else {
            if (temp_a3->f5 != arg0->f5) {
                *(vu32 *)0xA4600024 = arg0->f5;
            }
            if (temp_a3->f6 != arg0->f6) {
                *(vu32 *)0xA460002C = arg0->f6;
            }
            if (temp_a3->f7 != arg0->f7) {
                *(vu32 *)0xA4600030 = arg0->f7;
            }
            if (temp_a3->f8 != arg0->f8) {
                *(vu32 *)0xA4600028 = arg0->f8;
            }
        }
        temp_a3->f4 = arg0->f4;
        temp_a3->f5 = arg0->f5;
        temp_a3->f6 = arg0->f6;
        temp_a3->f7 = arg0->f7;
        temp_a3->f8 = arg0->f8;
    }
    *(vu32 *)((u32)arg0->reg | arg1 | 0xA0000000) = arg2;
    return 0;
}
