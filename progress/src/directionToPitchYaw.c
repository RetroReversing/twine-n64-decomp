f32 approxHypot2D(f32, f32);
f32 approximateAtan2(f32, f32);

/* Converts a direction vector (x, y, z) into pitch and yaw angles (651.9 units per radian), with roll set to 0. */ void directionToPitchYaw(f32 *outAngles, f32 x, f32 y, f32 z) {
    outAngles[0] = approximateAtan2(y, approxHypot2D(x, z)) * 651.8986f;
    outAngles[1] = approximateAtan2(x, z) * 651.8986f;
    ((s32 *)outAngles)[2] = 0;
}
