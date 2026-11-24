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

s32 func_8000A894();
s32 spawnTrackMarkerCaption();
s32 spawnCaptionMessage();
s32 func_80087100();
extern s32 D_800C4450;
extern char D_800C4458[];
extern char D_800C4462[];
extern char D_800C446A[];
extern void *D_80108788;
extern s32 D_80109688;

/* If the player actor's target matches one of two table entries, shows a caption (first hit plays a sound and sets a flag, later hits just repeat the caption); otherwise falls back to spawnTrackMarkerCaption. */ s32 checkPlayerCaptionTrigger(void) {
    char *unused;
    s32 result;
    s32 handled;
    
    u32 packedId;
    u32 index;

    handled = 0;
    if (D_80108788 != NULL) {
        if (M2C_FIELD(D_80108788, void **, 0x70) != NULL) {
            index = 0;
            unused = &D_800C4450;
            do {
                packedId = M2C_FIELD(M2C_FIELD(D_80108788, void **, 0x70), u32 *, 0x30);
                if ((((packedId >> 4) & 0xFFFF) == *(s32 *)(&D_800C4450 + index)) && ((packedId >> 0x14) == *(s32 *)(D_800C4458 + index * 4)) && (M2C_FIELD(D_80108788, u16 *, 0x78) == 0x12)) {
                    if (M2C_FIELD(D_80108788, s16 *, 0x7C) == 0) {
                        M2C_FIELD(D_80108788, s16 *, 0x7C) = 1;
                        func_8000A894(0x110);
                        spawnCaptionMessage(0, D_80109688, func_80087100(*(u16 *)(D_800C4462 + index * 4)), -1, -1, 1, 0, 0, 3, 0, 0);
                        handled = 1;
                        M2C_FIELD(D_80108788, s32 *, 0x60) |= 0x08000000;
                    } else {
                        spawnCaptionMessage(0, D_80109688, func_80087100(*(u16 *)(D_800C446A + index * 4)), -1, -1, 1, 0, 0, 3, 0, 0);
                        handled = 1;
                        goto block_9;
                    }
                } else {
block_9:
                }
                unused += 4;
                index += 1;
            } while (index < 2U);
            goto block_11;
        }
    }
    {
block_11:
        result = handled;
    }
    if (result == 0) {
        result = spawnTrackMarkerCaption();
    }
    return result;
}


