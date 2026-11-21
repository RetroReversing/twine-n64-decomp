/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 actorLinkToSurface();
s32 effectSetAnimFrame();
s32 getTrackTriggerMask();
void *spawnEffectObject();
extern f64 D_800D4170;
extern s8 D_80109B1E;
extern s32 *gProbeObjectList;
extern s32 gTrackMarkerDone;

void *func_8005DC2C(s32 arg0, s32 arg1, void *arg2, void *arg3) {
    register u16 temp_v0_2;
    register s16 var_v0;
    
    u16 var_a2;
u16 __repair_result_var_a2;
    s32 temp_v1;
    void *temp_s0;
    void *temp_v0;

    temp_v0 = spawnEffectObject(0x50, arg0, arg1);
    if (temp_v0 != NULL) {
        temp_s0 = (*(void **)((char *)(temp_v0) + 0x6C));
        (*(s32 *)((char *)(temp_s0) + 0x4C)) = (s32) ((*(s32 *)((char *)(temp_s0) + 0x4C)) & ~0x40);
        temp_v1 = (*(u8 *)((char *)((*(void **)((char *)(arg2) + 0x24))) + 0x1E));
        switch (temp_v1) {                          /* irregular */
        case 0x2F:
            var_v0 = 0x12;
            goto block_11;
        case 0x8E:
            D_80109B1E = 1;
            var_v0 = 0x5F;
            goto block_11;
        case 0x90:
            D_80109B1E = 1;
            var_v0 = 0x60;
            goto block_11;
        default:
            var_v0 = 0x11;
            if (temp_v1 != 0x2D) {

            } else {
block_11:
                (*(s16 *)((char *)(temp_v0) + 0x78)) = var_v0;
            }
            break;
        }
        (*(u16 *)((char *)(temp_s0) + 0x34)) = (u16) (*(u16 *)((char *)(arg2) + 0x2C));
        (*(u16 *)((char *)(temp_s0) + 0x40)) = (u16) (*(u16 *)((char *)(arg2) + 0x2E));
        (*(s32 *)((char *)(temp_s0) + 0x2C)) = getTrackTriggerMask((*(u16 *)((char *)(arg2) + 0x34)));
        (*(u16 *)((char *)(temp_s0) + 0x36)) = (u16) (*(u16 *)((char *)(arg2) + 0x36));
        (*(u16 *)((char *)(temp_s0) + 0x38)) = (u16) (*(u16 *)((char *)(arg2) + 0x38));
        (*(u16 *)((char *)(temp_s0) + 0x3A)) = (u16) (*(u16 *)((char *)(arg2) + 0x30));
        (*(u16 *)((char *)(temp_s0) + 0x3C)) = (u16) (*(u16 *)((char *)(arg2) + 0));
        (*(u16 *)((char *)(temp_s0) + 0x3E)) = (u16) *(*(u16 **)((char *)(arg2) + 0x28));
        (*(s16 *)((char *)(temp_s0) + 0x42)) = 0;
        if ((*(u16 *)((char *)(temp_s0) + 0x3A)) == 1) {
            temp_v1 = (*(u16 *)((char *)(temp_s0) + 0x3C)) + *(&gTrackMarkerDone + (*(u16 *)((char *)(temp_s0) + 0x34)));
            __repair_result_var_a2 = (*(u16 *)((char *)(temp_s0) + 0x3E));
        
        effectSetAnimFrame(temp_v0, temp_v1, var_a2);} else {
            temp_v1 = (*(u16 *)((char *)(arg2) + 0));
            var_a2 = (u16) (s16) *(*(u16 **)((char *)(arg2) + 0x28));
        
        effectSetAnimFrame(temp_v0, temp_v1, (s16) var_a2);}
        if ((*(u16 *)((char *)(arg2) + 0x40)) == 0) {
            (*(s32 *)((char *)(temp_s0) + 0x4C)) = (*(s32 *)((char *)(temp_s0) + 0x4C)) | 0x80;
        } else {
            (*(s32 *)((char *)(temp_s0) + 0x4C)) = (*(s32 *)((char *)(temp_s0) + 0x4C)) & ~0x80;
        }
        *(&gTrackMarkerDone + (*(u16 *)((char *)(temp_s0) + 0x34))) = (s8) (*(u16 *)((char *)(arg2) + 0x32));
        (*(void **)((char *)(temp_s0) + 4)) = arg3;
        temp_v0_2 = (*(u16 *)((char *)(arg2) + 4));
        (*(u16 *)((char *)(temp_s0) + 0x44)) = temp_v0_2;
        if (!temp_v0_2) {
            (*(u16 *)((char *)(temp_s0) + 0x44)) = 0x3CU;
        }
        (*(s8 *)((char *)(temp_s0) + 0x4B)) = 0;
        (*(s32 *)((char *)(temp_s0) + 0x4C)) = (s8) ((*(u8 *)((char *)(arg2) + 3)) - 1);
        (*(f32 *)((char *)(temp_s0) + 8)) = 1.0f;
        if (arg3 != NULL) {
            (*(f32 *)((char *)(temp_v0) + 0x24)) = (f32) (*(f32 *)((char *)(arg3) + 0));
            (*(f32 *)((char *)(temp_v0) + 0x28)) = (f32) (*(f32 *)((char *)(arg3) + 4));
            (*(f32 *)((char *)(temp_v0) + 0x2C)) = (f32) (*(f32 *)((char *)(arg3) + 8));
            (*(f32 *)((char *)(temp_v0) + 0x3C)) = (f32) ((f64) (*(f32 *)((char *)(arg3) + 0xC)) * D_800D4170);
            (*(f32 *)((char *)(temp_v0) + 0x40)) = (f32) ((f64) (*(f32 *)((char *)(arg3) + 0x10)) * D_800D4170);
            (*(f32 *)((char *)(temp_v0) + 0x44)) = (f32) ((f64) (*(f32 *)((char *)(arg3) + 0x14)) * D_800D4170);
        }
        (*(f32 *)((char *)(temp_v0) + 0x30)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x24));
        (*(f32 *)((char *)(temp_v0) + 0x38)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x2C));
        (*(f32 *)((char *)(temp_v0) + 0x34)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x28));
        (*(f32 *)((char *)(temp_v0) + 0x48)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x3C));
        (*(f32 *)((char *)(temp_v0) + 0x50)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x44));
        (*(f32 *)((char *)(temp_v0) + 0x4C)) = (f32) (*(f32 *)((char *)(temp_v0) + 0x40));
        (*(s16 *)((char *)(temp_v0) + 0x7A)) = 0;
        (*(s16 *)((char *)(temp_v0) + 0x7C)) = 0;
        actorLinkToSurface(*gProbeObjectList, temp_v0, 1);
        (*(s32 *)((char *)(temp_v0) + 0x5C)) = (s32) ((*(s32 *)((char *)(temp_v0) + 0x5C)) | 0x600);
    }
    return temp_v0;
}
