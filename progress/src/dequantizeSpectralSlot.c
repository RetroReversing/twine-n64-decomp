void func_8009F1D4(void *, int, int);

/* Converts eight input samples to fixed point into the current slot, runs the follow-up stage, then flips the double buffer. */
void dequantizeSpectralSlot(TwineSampleRing *ring, short *samples, int arg2, int arg3) {
    short *out = ring->slot[ring->slotIndex];
    out[0] = SAMPLE_TO_FIXED(samples[0], 0x20, 0x3333, 0x4000);
    out[1] = SAMPLE_TO_FIXED(samples[1], 0x20, 0x3333, 0x4000);
    out[2] = SAMPLE_TO_FIXED(samples[2], 0x10, 0x3333, -0x332F000);
    out[3] = SAMPLE_TO_FIXED(samples[3], 0x10, 0x3333, 0x04003C00);
    out[4] = SAMPLE_TO_FIXED(samples[4], 8, 0x4B17, -0x36E4E4);
    out[5] = SAMPLE_TO_FIXED(samples[5], 8, 0x4444, 0x03BBF800);
    out[6] = SAMPLE_TO_FIXED(samples[6], 4, 0x7ADE, 0x0147936C);
    out[7] = SAMPLE_TO_FIXED(samples[7], 4, 0x740C, 0x040D6B40);
    func_8009F1D4(ring, arg2, arg3);
    ring->slotIndex ^= 1;
}
