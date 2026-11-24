extern void shiftLeft8InPlace(u32 *);
extern u8 D_80107EE8;
extern s32 D_80107EEC;
extern s32 D_80107EF0;
extern s32 D_80107EF4;
extern s32 D_80107EF8;

/* Sets a ramp toward (level << 16) over duration ticks for one channel (0x28-byte entries),
   or for a group of channels selected by codes 0xFA-0xFF. */
void setChannelRamp(u8 level, u16 duration, u8 channelSel) {
    u32 startTick;
    s32 *targetPtr;
    s32 *targetPtr2;
    s32 *targetPtr3;
    s32 selector;
    s32 durationWide;
    s32 entryOffset;
    s32 offset;
    s32 offset2;
    s32 offset3;
    u16 safeDuration;
    s32 groupType;
    u32 groupSel;
    u32 i;
    u32 i2;
    u32 i3;

    safeDuration = duration;
    if (!(safeDuration & 0xFFFF)) {
        safeDuration = duration + 1;
    }
    durationWide = safeDuration & 0xFFFF;
    startTick = durationWide;
    shiftLeft8InPlace(&startTick);
    selector = channelSel & 0xFF;
    switch (selector) {
    case 0xFF: {
        s32 value, divisor, previous, current;
        u32 tick;
        i = 0;
        value = (level & 0xFF) << 0x10;
        tick = startTick;
        divisor = (u16)safeDuration;
        targetPtr = &D_80107EF0;
        offset = 0;
        do {
            if ((u8) *(&D_80107EE8 + offset) < 2U) {
                *targetPtr = value;
                *((s32 *)((u8 *)&D_80107EF8 + offset)) = tick;
                current = *targetPtr;
                previous = *((s32 *)((u8 *)&D_80107EEC + offset));
                *((s32 *)((u8 *)&D_80107EF4 + offset)) = (current - previous) / divisor;
            }
            targetPtr += 0xA;
            i += 1;
            offset += 0x28;
        } while (i < 0x20U);
        return;
    }
    case 0xFC: {
        s32 value, divisor, previous, current;
        u32 tick;
        i2 = 0;
        value = (level & 0xFF) << 0x10;
        tick = startTick;
        divisor = (u16)safeDuration;
        targetPtr2 = &D_80107EF0;
        offset2 = 0;
        do {
            if ((u32) (*(&D_80107EE8 + offset2) - 2) < 2U) {
                *targetPtr2 = value;
                *((s32 *)((u8 *)&D_80107EF8 + offset2)) = tick;
                current = *targetPtr2;
                previous = *((s32 *)((u8 *)&D_80107EEC + offset2));
                *((s32 *)((u8 *)&D_80107EF4 + offset2)) = (current - previous) / divisor;
            }
            targetPtr2 += 0xA;
            i2 += 1;
            offset2 += 0x28;
        } while (i2 < 0x20U);
        return;
    }
    case 0xFA:
        groupType = 2;
        goto block_18;
    case 0xFB:
        groupType = 3;
        goto block_18;
    case 0xFD:
        groupType = 0;
        goto block_18;
    case 0xFE:
        groupType = 1;
block_18: {
        s32 value, divisor, previous, current;
        u32 tick;
        i3 = 0;
        groupSel = (u8)groupType;
        value = (level & 0xFF) << 0x10;
        tick = startTick;
        divisor = (u16)safeDuration;
        targetPtr3 = &D_80107EF0;
        offset3 = 0;
        do {
            if (*(&D_80107EE8 + offset3) == groupSel) {
                *targetPtr3 = value;
                *((s32 *)((u8 *)&D_80107EF8 + offset3)) = tick;
                current = *targetPtr3;
                previous = *((s32 *)((u8 *)&D_80107EEC + offset3));
                *((s32 *)((u8 *)&D_80107EF4 + offset3)) = (current - previous) / divisor;
            }
            targetPtr3 += 0xA;
            i3 += 1;
            offset3 += 0x28;
        } while (i3 < 0x20U);
        return;
    }
    default: {
        s32 previous, current, quotient;
        entryOffset = selector * 0x28;
        *((volatile s32 *)((u8 *)&D_80107EF0 + entryOffset)) = (level & 0xFF) << 0x10;
        current = *((volatile s32 *)((u8 *)&D_80107EF0 + entryOffset));
        previous = *((s32 *)((u8 *)&D_80107EEC + entryOffset));
        quotient = (current - previous) / durationWide;
        *((s32 *)((u8 *)&D_80107EF8 + entryOffset)) = startTick;
        *((s32 *)((u8 *)&D_80107EF4 + entryOffset)) = quotient;
        return;
    }
    }
}
