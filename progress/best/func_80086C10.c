#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
extern s32 D_80108F78;
void func_80081470();
void func_800814EC();

void func_80086C10(void *arg0, u8 arg1) {
    switch (D_80108F78) {
    case 1:
        if ((arg1 & 0xFF) == 2) {
            func_80081470(arg0, arg1);
        }
        break;
    case 20:
        switch (arg1 & 0xFF) {
        case 2:
            func_80081470(arg0);
            func_800814EC(arg0);
            break;
        case 4:
            func_80081470(arg0);
            func_800814EC(arg0);
            break;
        case 5:
            func_80081470(arg0);
            func_800814EC(arg0);
            break;
        case 6:
            func_80081470(arg0);
            func_800814EC(arg0);
            break;
        case 8:
            func_80081470(arg0);
            func_800814EC(arg0);
            break;
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
        case 8:
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
