extern u32 D_800C2EB0;
extern u32 D_800C2EB4;

void func_80045CC4(void) {
    u32 carryState = D_800C2EB0;
    u32 seed = D_800C2EB4;
    carryState += seed;
    seed += (carryState) + ((carryState >> 31));
    D_800C2EB0 = carryState;
    D_800C2EB4 = seed;
}
