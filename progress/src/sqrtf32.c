extern f32 sqrtf(f32);
/* Square root that returns 0 for non-positive inputs. */ f32 sqrtf32(f32 value, f32 * arg1, void * arg2, s32 arg3) { return value <= 0.0f ? 0.0f : sqrtf(value); }
