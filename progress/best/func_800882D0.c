/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 func_8009D9D8();
s32 osRecvMesg();
s32 osSendMesg();
extern char D_800E1AC0[];
extern char D_800E2CC0[];
extern char D_800E2CD0[];
extern char D_800E2CD8[];
extern s32 D_800E3F2C;
extern char D_800E3F30[];
extern s32 (*D_80100180)(s32);

void func_800882D0(s32 arg0) {
    s32 temp_s0;
    s32 temp_v1;

    temp_s0 = arg0 * 0x1228;
    temp_v1 = *(D_800E2CC0 + temp_s0) & 0xFF;
    switch (temp_v1) {                              /* irregular */
    case 1:
        *(D_800E2CC0 + temp_s0) = 0;
        if (!(D_800E3F2C & 1)) {
            D_80100180(*(D_800E2CD0 + temp_s0));
            return;
        }
        return;
    case 2:
        osRecvMesg(D_800E3F30, 0, 1);
        func_8009D9D8(temp_s0 + D_800E1AC0);
        *(D_800E2CC0 + temp_s0) = 3;
        *(D_800E2CD8 + temp_s0) = 4;
        osSendMesg(D_800E3F30, 0, 0);
        break;
    }
}
