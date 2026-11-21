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

s32 effectSetAnimFrame();
s32 randomIntBelow();
extern char gTrackMarkerDone[];

/* Advances a track marker's animation state machine; sets gTrackMarkerDone for its track entry as it plays. */ void stepTrackMarkerAnim(void *marker) {
    s16 state;
    u32 packedAnim;
    u32 packedAnim1;
    u32 packedAnim2;
    u32 packedAnim3;
    u8 flagIndex;
    u8 flagIndex2;
    u8 flagIndex1;
    u8 flagIndex3;
    void *entry;

    state = M2C_FIELD(marker, s16 *, 0x7A);
    entry = M2C_FIELD(marker, void **, 0x6C);
    switch (state) {                              /* irregular */
    case 0:
        if (randomIntBelow(0x78) == 0) {
            M2C_FIELD(marker, s16 *, 0x7A) = 2;
        }
        if (randomIntBelow(0x3C) == 0) {
            flagIndex = M2C_FIELD(entry, u8 *, 4);
            if (flagIndex != 0) {
                *(gTrackMarkerDone + flagIndex) = 0;
            }
            packedAnim = M2C_FIELD(entry, u32 *, 0);
            effectSetAnimFrame(marker, ((packedAnim >> 4) & 0xFFFF) + 1, packedAnim >> 0x14);
            M2C_FIELD(marker, s16 *, 0x7A) = 1;
        }
        return;
    case 1:
        if (randomIntBelow(7) == 0) {
            flagIndex1 = M2C_FIELD(entry, u8 *, 4);
            if (flagIndex1 != 0) {
                *(gTrackMarkerDone + flagIndex1) = 1;
            }
            packedAnim1 = M2C_FIELD(entry, u32 *, 0);
            effectSetAnimFrame(marker, (packedAnim1 >> 4) & 0xFFFF, packedAnim1 >> 0x14);
            M2C_FIELD(marker, s16 *, 0x7A) = 0;
            return;
        }
        break;
    case 2:
        if (randomIntBelow(7) != 0) {
            flagIndex2 = M2C_FIELD(entry, u8 *, 4);
            if (flagIndex2 != 0) {
                *(gTrackMarkerDone + flagIndex2) = 0;
            }
            packedAnim2 = M2C_FIELD(entry, u32 *, 0);
            effectSetAnimFrame(marker, ((packedAnim2 >> 4) & 0xFFFF) + 1, packedAnim2 >> 0x14);
            M2C_FIELD(marker, s16 *, 0x7A) = 3;
        }
        if (randomIntBelow(5) == 0) {
            M2C_FIELD(marker, s16 *, 0x7A) = 0;
            return;
        }
        return;
    case 3:
        flagIndex3 = M2C_FIELD(entry, u8 *, 4);
        if (flagIndex3 != 0) {
            *(gTrackMarkerDone + flagIndex3) = 1;
        }
        packedAnim3 = M2C_FIELD(entry, u32 *, 0);
        effectSetAnimFrame(marker, (packedAnim3 >> 4) & 0xFFFF, packedAnim3 >> 0x14);
        M2C_FIELD(marker, s16 *, 0x7A) = 2;
        return;
    }
}
