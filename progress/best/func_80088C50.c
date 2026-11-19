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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800936A8();
s32 func_8009D510();
s32 func_800A0170();
s32 osCreateMesgQueue();
s32 osSendMesg();
extern s8 D_800CEEC0;
extern char D_800E1AC0[];
extern char D_800E2CC0[];
extern s32 D_800E3F10;
extern s32 D_800E3F1C;
extern s32 D_800E3F24;
extern s32 D_800E3F2C;
extern char D_800E3F30[];
extern char D_800E3F48[];
extern s32 (*D_8010017C)(s32, s32);
extern u8 D_8010086C;
extern s32 *D_8010D428;
extern s32 func_8008863C;

void func_80088C50(s32 arg0) {
    char *var_s0;
    char *var_s0_2;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;

    var_s1 = 0;
    var_s0 = D_800E1AC0;
    var_s2 = 0;
    D_800E3F2C = arg0;
    D_800E3F1C = 0;
    do {
        func_8009D510(var_s0, 0, 0, 0, 0);
        if (D_8010086C != 0) {
            M2C_FIELD(var_s0, u8 *, 0x11DE) = (u8) (M2C_FIELD(var_s0, u8 *, 0x11DE) * 2);
        }
        *(D_800E2CC0 + var_s2) = 0;
        var_s0 += 0x1228;/*__repair_loop_weight*/do {
        var_s1 += 1;} while (0);
        var_s2 += 0x1228;
    } while (var_s1 < 2);/*__repair_call_balance*/if(var_s1){
    osCreateMesgQueue(D_800E3F30, D_800E3F48, 1);}else{
    osCreateMesgQueue(D_800E3F30, D_800E3F48, 1);}
    osSendMesg(D_800E3F30);
    if (D_800E3F2C & 1) {
        temp_s2 = func_800936A8(0x10E0);
        var_s1_2 = 0;
        var_s0_2 = &D_800E3F24;
        do {
            var_s1_2 += 1;
            temp_v0 = D_8010017C(temp_s2, 0);
            *(s32 *)var_s0_2 = temp_v0;
            func_800A0170(temp_v0, temp_s2);
            var_s0_2 += 4;
        } while (var_s1_2 < 2);
    }
    D_8010D428 = &func_8008863C;
    D_800CEEC0 = 1;
    D_800E3F10 = 0;
}
