void sqrtf32(f32);
/* Returns the Euclidean distance between two 3D points. */
void vec3DistanceBetween(const f32 *p0, const f32 *p1) { f32 dx, dy, dz; dx = p0[0] - p1[0]; dy = p0[1] - p1[1]; dz = p0[2] - p1[2]; dx = dx * dx; dy = dy * dy; sqrtf32(dx + dy + dz * dz); }
