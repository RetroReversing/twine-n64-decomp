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

M2C_UNK func_80011950();                            /* extern */
s16 osContInit(M2C_UNK *, u8 *, M2C_UNK *);         /* extern */
M2C_UNK osContStartReadData(M2C_UNK *);             /* extern */
M2C_UNK osCreateMesgQueue(M2C_UNK *, M2C_UNK *, M2C_UNK, s16 *); /* extern */
s16 osEepromProbe(M2C_UNK *);                       /* extern */
M2C_UNK osSetEventMesg(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern s16 D_800BFC30;
extern M2C_UNK D_800E0760;
extern M2C_UNK D_800E0768;
extern s16 D_800E0930;
extern s16 D_800E093E;
extern s32 D_800E0960;
extern s16 D_800E097E;
extern s16 D_800E099E;
extern s16 D_800E09A6;
extern s16 D_800E09AE;
extern s16 D_800E09B0;
extern s16 D_800E09B2;
extern s16 D_8010086A;
extern s16 D_80100908;
extern s8 D_80102D60;
extern s16 D_801083D4;
extern u8 D_80108F75;
extern s16 D_80109DC8;
extern s16 D_80109DD0;
extern s16 D_8010A3A0;
extern M2C_UNK D_8010D298;
extern u16 D_8010D430;
extern s16 D_8010D540;

u8 func_80011FA4(void) {
    s16 *var_a0;
    s16 *var_a1;
    s16 *var_a2;
    s16 *var_a3;
    s16 *var_t0;
    s16 *var_t1;
    s16 *var_v1;
    s32 var_t2;

    var_t2 = 0;
    var_t1 = &D_801083D4;
    var_t0 = &D_8010A3A0;
    var_a3 = &D_800E09A6;
    var_a2 = &D_800E099E;
    var_a1 = &D_800E097E;
    var_a0 = &D_80109DC8;
    var_v1 = &D_800E0930;
    D_80102D60 = 1;
    D_800E09AE = 0;
    D_800BFC30 = -1;
    D_800E09B0 = 0;
    D_8010086A = 0;
    D_8010D540 = 0;
    D_800E0960 = 0;
    D_800E093E = 0;
    __repair_rows: {
        *var_v1 = 0;
        *var_a0 = 0;
        *var_a1 = 0;
        *var_a2 = 0;
        *var_a3 = 0;
        *var_t0 = 2;
        *var_t1 = 0;
        var_t1 += 2;
        var_t0 += 2;
        var_a3 += 2;
        var_a2 += 2;
        var_a1 += 2;
        var_a0 += 2;
        var_t2 += 1;
        var_v1 += 2;
    }
if (var_t2 < 4) goto __repair_rows;
    osCreateMesgQueue(&D_8010D298, &D_800E0760, 1, var_a3);
    osSetEventMesg(5, &D_8010D298, 1);
    D_800E09B2 = osContInit(&D_8010D298, &D_80108F75, &D_800E0768);
    D_80100908 = osEepromProbe(&D_8010D298);
    osContStartReadData(&D_8010D298);
    D_800E09AE = 1;
    func_80011950();
    D_80109DD0 = 0;
    if (D_8010D430 & 0x1000) {
        D_80109DD0 = 1;
    }
    return D_80108F75;
}
