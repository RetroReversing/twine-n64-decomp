/* Returns -1, 0 or 1 according to the sign of value. */ s32 signOf(s32 value) { if (value==0) return 0; return (value >> 31) | 1; }
