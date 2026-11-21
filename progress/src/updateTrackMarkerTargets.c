/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 func_800461D4();
s32 func_80077960();
s32 func_80078274();
s32 func_8007BAF8();
extern u8 gTrackMarkerDone[];

s32 updateTrackMarkerTargets(void *arg0) {
    int var_s3;
    s32 temp_v1;
    void *temp_s0;
    void *var_s1;

    var_s1 = *(*(void ***)((char *)(arg0) + 0x20));
    var_s3 = 0;
    if (var_s1 != NULL) {
        do {
            if (((temp_v1 = (*(u16 *)((char *)(var_s1) + 0x78))) < 0x61) && ((s32) temp_v1 >= 0x5E) && (*(gTrackMarkerDone + (*(u16 *)((char *)((*(void **)((char *)(var_s1) + 0x6C))) + 0x34))) == 0)) {
                temp_s0 = (*(void **)((char *)(arg0) + 0x6C));
                (*(s32 *)((char *)(temp_s0) + 0x88)) |= 0x02000000;
                if ((func_8007BAF8(arg0, var_s1 + 0x24, 6, 0xB) << 0x18) != 0) {
                    func_80078274(arg0);
                    if ((*(s16 *)((char *)(arg0) + 0x7A)) != 0xB) {
                        var_s3 = 1;
                    }
                } else {
                    var_s3 = 1;
                    { struct Vec3 { s32 x, y, z; }; *(struct Vec3 *)((char *)temp_s0 + 0x18) = *(struct Vec3 *)((char *)var_s1 + 0x24); }
                    (*(f32 *)((char *)(temp_s0) + 0x38)) = func_800461D4(arg0 + 0x24, temp_s0 + 0x18);
                    func_80077960(arg0, 0x87);
                }
            }
            var_s1 = (*(void **)((char *)(var_s1) + 0));
        } while (var_s1 != NULL);
    }
    return var_s3;
}
