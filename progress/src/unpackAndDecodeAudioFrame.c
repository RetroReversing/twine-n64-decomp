s32 decodeAudioSubframes();

/* Unpacks a bit-packed audio frame into header and four subframes of fields, then decodes it. */ s32 unpackAndDecodeAudioFrame(s32 decoder, u8 *packed, s32 output) {
    s16 header[8];
    s16 gain[4];
    s16 grid[4];
    s16 shift[4];
    s16 amplitude[4];
    s16 pulses[52];
    s32 sub;

    header[0] = ((packed[0] & 0xF) << 2) | ((packed[1] >> 6) & 3);
    header[1] = packed[1] & 0x3F;
    header[2] = (packed[2] >> 3) & 0x1F;
    header[3] = ((packed[2] & 7) << 2) | ((packed[3] >> 6) & 3);
    header[4] = (packed[3] >> 2) & 0xF;
    header[5] = ((packed[3] & 3) << 2) | ((packed[4] >> 6) & 3);
    header[6] = (packed[4] >> 3) & 7;
    header[7] = packed[4] & 7;
    for (sub = 0; sub < 4; sub++) {
        gain[sub] = (packed[sub*7+5] >> 1) & 0x7F;
        shift[sub] = ((packed[sub*7+5] & 1) << 1) | ((packed[sub*7+6] >> 7) & 1);
        grid[sub] = (packed[sub*7+6] >> 5) & 3;
        amplitude[sub] = ((packed[sub*7+6] & 0x1F) << 1) | ((packed[sub*7+7] >> 7) & 1);
        pulses[sub*13+0] = (packed[sub*7+7] >> 4) & 7;
        pulses[sub*13+1] = (packed[sub*7+7] >> 1) & 7;
        pulses[sub*13+2] = ((packed[sub*7+7] & 1) << 2) | ((packed[sub*7+8] >> 6) & 3);
        pulses[sub*13+3] = (packed[sub*7+8] >> 3) & 7;
        pulses[sub*13+4] = packed[sub*7+8] & 7;
        pulses[sub*13+5] = (packed[sub*7+9] >> 5) & 7;
        pulses[sub*13+6] = (packed[sub*7+9] >> 2) & 7;
        pulses[sub*13+7] = ((packed[sub*7+9] & 3) << 1) | ((packed[sub*7+10] >> 7) & 1);
        pulses[sub*13+8] = (packed[sub*7+10] >> 4) & 7;
        pulses[sub*13+9] = (packed[sub*7+10] >> 1) & 7;
        pulses[sub*13+10] = ((packed[sub*7+10] & 1) << 2) | ((packed[sub*7+11] >> 6) & 3);
        pulses[sub*13+11] = (packed[sub*7+11] >> 3) & 7;
        pulses[sub*13+12] = packed[sub*7+11] & 7;
    }
    decodeAudioSubframes(decoder, header, gain, shift, grid, amplitude, pulses, output);
    return 0;
}
