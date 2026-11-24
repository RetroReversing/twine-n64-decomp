extern f32 gSinCosTable[];
extern void (*gDataBankHandler)(void *, int);
f32 cosAngle(f32 x) { return gSinCosTable[(s32)x & 0xFFF]; }
s32 isIdNonNegativeOrUnset(u32 *p) { u32 x = *p; if (x == -1U) return 1; return (x >> 31) ^ 1; }
/* Calls the data bank handler on a block with mode 0 (apparently release). */ void dataBankFree(void *p) { gDataBankHandler(p, 0); }
f32 sinAngle(f32 x) { return gSinCosTable[((s32)x - 0x400) & 0xFFF]; }
