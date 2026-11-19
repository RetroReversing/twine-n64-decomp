extern u16 D_800E0986[];
extern u16 D_800E097E[];
void func_800107BC(u16);

void func_8001080C(void) {
    u16 i;

    for (i = 0; i < 4; i++) {
        D_800E0986[i] = D_800E097E[i];
        func_800107BC(i);
    }
}
