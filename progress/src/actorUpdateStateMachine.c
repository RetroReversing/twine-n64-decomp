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

void *func_80016410();
s32 func_80016990();
s32 applyNearbyActorImpact(s32, f32, f32);
s32 actorLinkToSurface();
s32 func_80044670();
u16 func_80045CF8();
s32 func_8007659C();
s32 func_80085E30();
s32 updateActorTrackingState();
extern s16 D_800C2942;
extern s32 *gProbeObjectList;
extern u8 gTrackDoneFlags[];

/* Two-state actor update. State 0 waits until its spawn group's done flag is set, then starts
 * state 1, which animates, spawns a child every 8 frames, and sets the done flag near the end. */
void actorUpdateStateMachine(void *actor) {
    s16 state;
    u16 *childDataPtr;
    u16 frameCounter;
    u8 doneFlagIndex;
    void *child;
    void *record;
    void *subRecord;

    state = M2C_FIELD(actor, s16 *, 0x7A);
    record = M2C_FIELD(actor, void **, 0x6C);
    switch (state) {                              /* irregular */
    case 0:
        doneFlagIndex = M2C_FIELD(record, u8 *, 0x2E);
        if ((doneFlagIndex == 0) || (*(gTrackDoneFlags + doneFlagIndex) != 0)) {
            M2C_FIELD(actor, s16 *, 0x7A) = 1;
        }
        if (M2C_FIELD(actor, s16 *, 0x7A) == 1) {
            actorLinkToSurface(*gProbeObjectList, actor, 1);
            return;
        }
        return;
    case 1:
        if (M2C_FIELD(actor, s32 *, 0x60) & 0x7000) {
            func_80044670(actor, M2C_FIELD(record, u16 *, 0x2C), D_800C2942);
            frameCounter = M2C_FIELD(record, u16 *, 0x2C) + 1;
            M2C_FIELD(record, u16 *, 0x2C) = frameCounter;
            if ((u32) (frameCounter & 0xFFFF) >= 0x1DU) {
                M2C_FIELD(record, u16 *, 0x2C) = 0U;
            }
            if (!(M2C_FIELD(record, u16 *, 0x2C) & 7)) {
                child = func_80016410(2, actor + 0x24, actor + 0x3C);
                if (child != NULL) {
                    childDataPtr = M2C_FIELD(child, u16 **, 0x6C);
                    *childDataPtr = func_80045CF8(0x1C);
                    M2C_FIELD(child, s16 *, 0x78) = 0x5C;
                    M2C_FIELD(child, u8 *, 0x7F) = 0xFF;
                    M2C_FIELD(child, s8 *, 0x80) = 0;
                    M2C_FIELD(child, s8 *, 0x81) = 0;
                    M2C_FIELD(child, u8 *, 0x82) = 0xFF;
                    M2C_FIELD(child, f32 *, 0x54) = 0.5f;
                    func_80044670(child, *childDataPtr, D_800C2942);
                    func_80016990(child, M2C_FIELD(actor, s32 *, 0x20));
                }
            }
        }
        subRecord = record + 0x10;
        updateActorTrackingState(actor, subRecord);
        M2C_FIELD(record, f32 *, 4) += M2C_FIELD(record, f32 *, 8);
        applyNearbyActorImpact(actor, 1.0f, 5.0f);
        func_8007659C(actor, record);
        M2C_FIELD(actor, s32 *, 0x3C) = 0;
        M2C_FIELD(actor, s32 *, 0x40) = 0;
        M2C_FIELD(actor, f32 *, 0x44) = 2048.0f;
        if (M2C_FIELD(record, s16 *, 0xE) >= (M2C_FIELD(record, s16 *, 0xC) - 4)) {
            *(gTrackDoneFlags + M2C_FIELD(record, u8 *, 0x2F)) = 1;
            func_80085E30(subRecord);
            M2C_FIELD(actor, s32 *, 0x60) |= 1;
        }
        M2C_FIELD(actor, s32 *, 0x58) |= 1;
        break;
    }
}
