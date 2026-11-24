extern f32 sqrtf(f32);
/* Square root that returns 0 for non-positive inputs. */ f32 sqrtf32(f32 value) { return value <= 0.0f ? 0.0f : sqrtf(value); }
