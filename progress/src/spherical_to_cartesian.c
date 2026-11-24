extern f32 gSinCosTable[];
#define SINS(x) gSinCosTable[(x) & 0xFFF]
#define COSS(x) gSinCosTable[((x) - 0x400) & 0xFFF]

/* Converts spherical coordinates (radians, 4096-step sine table) to an XYZ vector in out[0..2]. */
void spherical_to_cartesian(f32 *out, f32 radius, f32 yaw, f32 pitch) {
    s32 yawIdx = yaw * 651.8986206054688f;
    f32 pitchScaled = pitch * 651.8986206054688f;
    f32 x = radius * COSS(yawIdx);
    s32 pitchIdx = pitchScaled;
    f32 sinPitch = SINS(pitchIdx);
    f32 z, y;
    x *= sinPitch;
    z = radius * SINS(yawIdx);
    y = radius * COSS(pitchIdx);
    z *= sinPitch;
    out[1] = y;
    out[0] = x;
    out[2] = z;
}

u64 func_800ABAE8(u64, u64);
u64 func_800ABBE4(u64, u64);

u64 func_800ABE20(u64 dividend, u64 divisor) {
    if (divisor >> 32)
        return func_800ABAE8(dividend, divisor);
    return func_800ABBE4(dividend, divisor);
}

typedef struct {
    u8 pad[0x11DD];
    s8 state;
} StateRecord;

void advanceStreamStateToThree(StateRecord *arg0) {
    if (arg0->state == 2)
        arg0->state = 3;
}

extern u8 gInputBindingTables[];

void setGridCellFlag(s32 row, s32 col) {
    u8 *entry;
    row *= 0xA0;
    entry = gInputBindingTables + row;
    col *= 2;
    entry += col;
    *entry |= 0x80;
}
