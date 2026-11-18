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

M2C_UNK func_80089850();                            /* extern */
M2C_UNK osSendMesg(M2C_UNK *, s8 *, M2C_UNK);       /* extern */
M2C_UNK osYieldThread();                            /* extern */
extern u8 D_800CF540;
extern s32 D_800E4140;
extern M2C_UNK D_800E4144;
extern s32 D_800E4170;
extern u16 D_800E41DA;
extern s32 D_800E41E0;
extern u8 D_800E4214;
extern u8 D_800E4215;
extern s32 D_800E4220;
extern s32 D_800E4224;
extern s32 D_800E422C;
extern s32 D_800E4230;
extern s32 D_800E4238;
extern s32 D_800E4240;
extern s32 D_800E4244;
extern s32 D_800E4254;
extern s32 D_800E4258;
extern u16 D_800E426A;
extern M2C_UNK (*D_80100168)();
extern M2C_UNK (*D_80100170)(M2C_UNK *);
extern M2C_UNK (*D_80100180)(s32);
extern s32 D_80103EB4;
extern M2C_UNK func_8008B25C;

void func_8008BCB0(void) {
    s8 sp10;

    if (D_800CF540 != 0) {
        D_800E426A = D_800E41DA;
        __repair_rows: {

        }
if ((D_800E426A << 0x10) > 0) goto __repair_rows;
        D_80100170(&func_8008B25C);
        if (D_800E4215 != 0) {
            D_80100168();
            osYieldThread();
            D_800E4215 = 0;
        }
        if (D_800E4230 != 0) {
            func_80089850();
            D_80100180(D_800E4230);
            D_800E4230 = 0;
        }
        if (D_800E4238 != 0) {
            D_80100180(D_800E4238);
        }
        do {

        } while (D_800E4214 != 0);
        D_80100180(D_80103EB4);
        D_80100180(D_800E4244);
        D_80100180(D_800E4240);
        D_80100180(D_800E4258);
        D_80100180(D_800E4254);
        D_80100180(D_800E4220);
        D_80100180(D_800E4224);
        D_80100180(D_800E41E0);
        D_80100180(D_800E422C);
        sp10 = 0xFF;
        osSendMesg(&D_800E4144, &sp10, 1);
        D_80100180(D_800E4170);
        D_80100180(D_800E4140);
    }
}
