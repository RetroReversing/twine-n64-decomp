extern f32 gSinCosTable[];

/* Cosine lookup; angle is in 4096 units per full turn. */
f32 cosAngle(f32 angle) { return gSinCosTable[(s32)angle & 0xFFF]; }
