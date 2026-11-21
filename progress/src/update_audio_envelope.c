typedef struct AudioEnvelope {
    u8 pad0;
    u8 disabled;
    u8 pad2[0x20];
    u16 rate22;
    f32 peakLevel24;
    u16 steps28;
    u8 pad2A[0x1E];
    u16 stepCount48;
    f32 level4C;
    u32 timer50;
    f32 startLevel54;
    f32 targetLevel58;
    u8 state5C;
} AudioEnvelope;

extern f64 D_800D6718;
extern u32 D_800E41D4;

/* Advances an audio envelope's fade one tick: it starts a new ramp from its peak when
 * the step counter elapses, and writes the current level back to arg0. */
void update_audio_envelope(void *arg0, s32 arg1, s8 *arg2) {
    AudioEnvelope *env = (AudioEnvelope *)arg0;
    s32 __repair_store_0;
    f32 __repair_store_1;
    f32 var_ft0_2;
    f64 var_ft0;
    s32 temp_v0;
    u8 temp_v1;

    arg1 = (((u32)((u16)arg1 * 0x7D00) / D_800E41D4) << 11);
    if ((env->disabled == 0) && (env->state5C != 3)) {
        env->state5C = 3U;
        env->startLevel54 = 0.0f;
        env->timer50 = 0;
        env->targetLevel58 = (f32) env->level4C;
        env->stepCount48 = (u16) env->steps28;
        goto block_17;
    }
    if ((env->timer50 >> 16) >= (u16) env->stepCount48) {
        temp_v1 = env->state5C;
        switch (temp_v1) {                          /* irregular */
        case 0:
            env->state5C = 1U;
            env->timer50 = 0;
            env->targetLevel58 = 1.0f;
            env->startLevel54 = (f32) env->peakLevel24;
            env->stepCount48 = (u16) env->rate22;
block_17:
            goto block_18;
        case 1:
            env->state5C = 2U;
            env->targetLevel58 = (f32) env->peakLevel24;
            env->startLevel54 = (f32) env->peakLevel24;
            env->level4C = (f32) env->peakLevel24;
            return;
        case 3:
            *arg2 = 0;
            env->level4C = 0.0f;
            return;
        default:
            break;
        }
    }
    {
block_18:
        if (env->stepCount48 != 0) {
            temp_v0 = env->timer50;
            var_ft0 = (f64) temp_v0;
            if (temp_v0 < 0) {
                var_ft0 += D_800D6718;
            }
            var_ft0_2 = (f32) var_ft0 / ((f32) env->stepCount48 * 65536.0f);
        } else {
            var_ft0_2 = 1.0f;
        }
        __repair_store_0 = (s32) (env->timer50 + arg1);
        __repair_store_1 = (f32) (((env->startLevel54 - env->targetLevel58) * var_ft0_2) + env->targetLevel58);
        env->timer50 = __repair_store_0;
        env->level4C = __repair_store_1;
    }
}
