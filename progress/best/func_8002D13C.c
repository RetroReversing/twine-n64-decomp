extern u16 D_80103022[];
extern u16 D_801083D4[];
extern u16 D_80109DC8[];

u16 func_8002D13C(u16 kind) {
    u16 n = 0;
    u16 i;

    for (i = 0; i < 4; i++) {
        switch (kind) {
        case 0xA5:
            if (D_80109DC8[i] != 0) {
                n++;
            }
            break;
        case 0xA6:
            if (D_801083D4[i] != 0) {
                n++;
            }
            break;
        case 0xA3:
            if (D_80103022[i] != 0) {
                n++;
            } else {
                i = 5;
            }
            break;
        }
    }
    return n;
}
