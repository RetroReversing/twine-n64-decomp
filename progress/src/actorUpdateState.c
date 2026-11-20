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

s32 func_80015D40();
s32 markObjectsNearPos();
s32 actorLinkToSurface();
void func_8007659C(void *, void *);
s32 func_80085E30();
s32 func_80085E78();
s32 func_80087380();
extern s32 *gProbeObjectList;
extern u8 gActorDoneFlags[];

typedef struct { unsigned char pad_0[32]; int field_20; unsigned char pad_24[52]; int field_58; unsigned char pad_5C[4]; int field_60; unsigned char pad_64[8]; void * field_6C; unsigned char pad_70[10]; short field_7A; unsigned short field_7C; } __repair_record_arg0;
/* Runs one frame of the actor's state machine: 0 waits for its trigger flags, 1 counts a timer, 2 advances the active motion; 3 is the finished state. */ void actorUpdateState(void *arg0) {
    s16 state;
    s16 timer;
    u8 flagIdx;
    u8 triggerFlag;
    u8 gateFlag;
    u8 endFlag;
    u8 doneFlag;
    void *cfg;

    state = ((__repair_record_arg0*)arg0)->field_7A;
    cfg = ((__repair_record_arg0*)arg0)->field_6C;
    switch (state) {                              /* irregular */
    case 0:
        triggerFlag = M2C_FIELD(cfg, u8 *, 0x44);
        if (triggerFlag != 0) {
            if (*(gActorDoneFlags + triggerFlag) == M2C_FIELD(cfg, u8 *, 0x45)) {
                gateFlag = M2C_FIELD(cfg, u8 *, 0x46);
                if ((gateFlag != 0) && (*(gActorDoneFlags + gateFlag) == M2C_FIELD(cfg, u8 *, 0x47))) {
                    ((__repair_record_arg0*)arg0)->field_7A = 1;
                    actorLinkToSurface(*gProbeObjectList, arg0, 1);
                    return;
                }
            }
            return;
        }
        actorLinkToSurface(*gProbeObjectList, arg0, 1);
        if (M2C_FIELD(cfg, s32 *, 0x1C) == 0) {
            func_80087380(arg0);
            ((__repair_record_arg0*)arg0)->field_7A = 3;
            return;
        }
        ((__repair_record_arg0*)arg0)->field_7A = 1;
        return;
    case 1:
        flagIdx = M2C_FIELD(cfg, u8 *, 0x4A);
        if (flagIdx != 0) {
            if (((__repair_record_arg0*)arg0)->field_60 & func_80015D40(flagIdx)) {
            timer = ((__repair_record_arg0*)arg0)->field_7C + 1;
            ((__repair_record_arg0*)arg0)->field_7C = (u16) timer;
            if ((f32) timer > 150.0f) {
                goto block_22;
            }
            } else { ((__repair_record_arg0*)arg0)->field_7C = 0U; }
        } else {
block_22:
            ((__repair_record_arg0*)arg0)->field_7A = 2;
            return;
        }
        break;
    case 2:
        endFlag = M2C_FIELD(cfg, u8 *, 0x4B);
        if (endFlag != 0) {
            *(gActorDoneFlags + endFlag) = 1;
        }
        M2C_FIELD(cfg, f32 *, 0x20) += 0.033333335f;
        func_80085E78(arg0, cfg);
        func_8007659C(arg0, cfg + 0x1C);
        if (M2C_FIELD(cfg, s16 *, 0x2A) == M2C_FIELD(cfg, u8 *, 0x48)) {
            doneFlag = M2C_FIELD(cfg, u8 *, 0x49);
            if (doneFlag != 0) {
                *(gActorDoneFlags + doneFlag) = 1;
            }
        }
        if (M2C_FIELD(cfg, s16 *, 0x2A) == (M2C_FIELD(cfg, s16 *, 0x28) - 4)) {
            func_80085E30(cfg);
            ((__repair_record_arg0*)arg0)->field_7A = 3;
        }
        markObjectsNearPos(((__repair_record_arg0*)arg0)->field_20, 0, 0x01200000, arg0 + 0x24, 0, 0);
        ((__repair_record_arg0*)arg0)->field_58 |= 1;
        func_80087380(arg0);
        break;
    }
}
