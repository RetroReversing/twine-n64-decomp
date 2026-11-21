s32 audioVoiceIsActive(u8);
s32 randomU16Next();

/* Counts down a voice's step timer (voice+0x68). On reload the period comes from the event (randomised when bit 0 of its flags is set).
 * When the timer runs out the voice may be silenced, otherwise its event pointer is advanced to the next event. */
s32 audioVoiceStepTimer(u8 *voice, u8 *event) {
    u16 stepTimer;
    u16 reloadedTimer;
    u16 decrementedTimer;

    stepTimer = *(u16 *)(voice + 0x68);
    if (stepTimer == 0) {
        if (*(u16 *)event & 1) {
            *(u16 *)(voice + 0x68) = (u16) ((u32) (randomU16Next() & 0xFFFF) % (u16) *(u16 *)(event + 4));
        } else {
            *(u16 *)(voice + 0x68) = (u16) *(u16 *)(event + 4);
        }
        reloadedTimer = *(u16 *)(voice + 0x68);
        if ((reloadedTimer & 0xFFFF) != 0xFFFF) {
            *(u16 *)(voice + 0x68) = (u16) (reloadedTimer + 1);
            goto countDown;
        }
        goto advanceEvent;
    }
    if (stepTimer != 0xFFFF) {
countDown:
        decrementedTimer = *(u16 *)(voice + 0x68) - 1;
        *(u16 *)(voice + 0x68) = decrementedTimer;
        if (decrementedTimer & 0xFFFF) {
            goto advanceEvent;
        }
    } else {
advanceEvent:
        if (((*(u32 *)event >> 8) & 1) && ((*(s32 *)(voice + 0x24) & 0x40000008) == 8)) {
            *(u16 *)(voice + 0x68) = 0U;
            return 0;
        }
        if ((*(u8 *)event & 1) && !(*(s32 *)(voice + 0x24) & 0x20)) {
            if (!(audioVoiceIsActive(*(u8 *)(voice + 0x63)) & 0xFF)) {
                *(u16 *)(voice + 0x68) = 0U;
                return 0;
            }
        }
        *(s32 *)(voice + 4) = (s32) (*(s32 *)(voice + 0) + (*(u16 *)(event + 6) * 8));
    }
    return 0;
}
