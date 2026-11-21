/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *spawnEffectObject();
s32 actorLinkToSurface();
extern u16 D_800C7BE2[];
extern char D_800C7C31[];
extern char D_800C7C35[];
extern char D_800C7C39[];
extern s32 *gProbeObjectList;

typedef struct { unsigned hi:12; unsigned tbl:16; unsigned lo:4; } BF1C;
void spawnSparkEffect(u16 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u8 arg6, s32 arg7, u16 arg8) {
    s32 temp_a1;
    void *temp_a0;
    void *temp_v0;

    temp_v0 = spawnEffectObject(0x2C, arg1, arg2);
    temp_a1 = arg0;
    if (temp_v0 != NULL) {
        temp_a0 = (*(void **)((char *)(temp_v0) + 0x6C));
        (*(s32 *)((char *)(temp_a0) + 0x18)) = arg7;
        (*(u16 *)((char *)(temp_a0) + 0x20)) = (int)arg8;
        ((BF1C *)((char *)temp_a0 + 0x1C))->tbl = D_800C7BE2[arg0];
        ((BF1C *)((char *)temp_a0 + 0x1C))->hi = 0xFB;
        (*(u8 *)((char *)(temp_v0) + 0x7F)) = (u8) *(D_800C7C31 + arg0);
        (*(u8 *)((char *)(temp_v0) + 0x80)) = (u8) *(D_800C7C35 + arg0);
        (*(u8 *)((char *)(temp_v0) + 0x81)) = (u8) *(D_800C7C39 + arg0);
        (*(s16 *)((char *)(temp_v0) + 0x7C)) = (s16) (arg3 + 1);
        (*(s8 *)((char *)(temp_a0) + 0x27)) = (s8) (arg4 + 1);
        (*(s8 *)((char *)(temp_a0) + 0x28)) = (s8) (arg5 + 1);
        (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
        (*(s16 *)((char *)(temp_v0) + 0x78)) = arg0;
        (*(u8 *)((char *)(temp_a0) + 0x22)) = arg6;
        actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
    }
}
