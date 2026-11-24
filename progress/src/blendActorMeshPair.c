/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void blendMeshFrames(s32, s32, f32, s32);
void blendActorMeshPair(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4) {
    void *temp_s0;

    temp_s0 = (*(void **)((char *)(arg0) + 0x68));
    (*(f32 *)((char *)(temp_s0) + 0x28)) = arg4;
    blendMeshFrames((*(s32 *)((char *)(temp_s0) + 0x54)), arg1, arg3, (*(s32 *)((char *)(temp_s0) + 0x14)) & 1);
    blendMeshFrames((*(s32 *)((char *)(temp_s0) + 0x58)), arg2, arg3, (*(s32 *)((char *)(temp_s0) + 0x14)) & 1);
}
