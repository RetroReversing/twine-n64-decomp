extern s32 D_80108F78;
void func_80081470(void *);
void func_800814EC(void *);

void func_80086C10(void *arg0, s32 arg1) {
    switch (D_80108F78) {
    case 1:
        if ((arg1 & 0xFF) == 2) {
            func_80081470(arg0);
        }
        break;
    case 20:
        switch (arg1 & 0xFF) {
        case 2:
        case 4:
        case 5:
        case 6:
        case 8:
        case 11:
            func_80081470(arg0);
            func_800814EC(arg0);
            break;
        case 13:
            func_80081470(arg0);
            break;
        }
        break;
    case 33:
        if ((arg1 & 0xFF) == 1) {
            *(s32 *)((u8 *)arg0 + 0x60) &= 0xFBFFFE39;
        }
        break;
    case 16:
        if ((arg1 & 0xFF) == 3) {
            *(s32 *)((u8 *)arg0 + 0x60) &= -0xC1;
        }
        break;
    case 18:
        if ((arg1 & 0xFF) == 3) {
            func_80081470(arg0);
            func_800814EC(arg0);
        }
        break;
    case 11:
        switch (arg1 & 0xFF) {
        case 3:
        case 7:
            func_80081470(arg0);
            func_800814EC(arg0);
            break;
        }
        /* fallthrough */
    case 41:
        if ((arg1 & 0xFF) == 3) {
            func_80081470(arg0);
        }
        break;
    case 40:
        if ((arg1 & 0xFF) == 2) {
            func_80081470(arg0);
        }
        break;
    }
}
