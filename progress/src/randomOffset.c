f32 randomFloatUpTo(f32);
/* Returns a random float in [0, range) shifted down by offset. */ f32 randomOffset(f32 range, f32 offset) { return randomFloatUpTo(range) - offset; }
