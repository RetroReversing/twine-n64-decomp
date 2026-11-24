extern f32 gSinCosTable[];
extern void (*gDataBankHandler)(void *, int);
f32 cosAngle(f32 angle) { return gSinCosTable[(s32)angle & 0xFFF]; }
s32 isIdNonNegativeOrUnset(u32 *p) { u32 x = *p; if (x == -1U) return 1; return (x >> 31) ^ 1; }
void dataBankFree(void *p) { gDataBankHandler(p, 0); }
/* Sine of a 12-bit angle (4096 units per turn): cosine table lookup shifted by a quarter turn. */
f32 sinAngle(f32 angle) { return gSinCosTable[((s32)angle - 0x400) & 0xFFF]; }
