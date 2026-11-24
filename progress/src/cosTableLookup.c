extern float gSinCosTable[];

/* Returns cos(radians) from a 4096-entry table (4096 / 2pi = 651.8986 steps per radian). */
float cosTableLookup(float radians) { return gSinCosTable[(int)(radians * 651.8986f) & 0xfff]; }
