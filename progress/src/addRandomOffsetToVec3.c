f32 randomOffset(f32, f32);
/* Adds an independent random offset to each of the three components of vec. */ void addRandomOffsetToVec3(f32 *vec, f32 range, f32 bias) {
 vec[0] += randomOffset(range, bias);
 vec[1] += randomOffset(range, bias);
 vec[2] += randomOffset(range, bias);
}
