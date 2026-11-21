f32 __cosf(f32);
f32 sinApprox(f32);

/* Converts Euler angles (x, y, z; 4096 units per turn) to a quaternion (x, y, z, w). */
void eulerToQuat(const f32 *angles, f32 *quat) {
    f32 halfX = angles[0] * 0.0007669904f;
    f32 halfY = angles[1] * 0.0007669904f;
    f32 halfZ = angles[2] * 0.0007669904f;
    f32 cosX = __cosf(halfX);
    f32 sinX = sinApprox(halfX);
    f32 cosY = __cosf(halfY);
    f32 sinY = sinApprox(halfY);
    f32 cosZ = __cosf(halfZ);
    f32 sinZ = sinApprox(halfZ);
    f32 cxcz = cosX * cosZ;
    f32 cxsz = cosX * sinZ;
    f32 sxcz = sinX * cosZ;
    f32 sxsz = sinX * sinZ;
    quat[0] = cosY * sxcz - sinY * cxsz;
    quat[1] = cosY * sxsz + sinY * cxcz;
    quat[2] = cosY * cxsz - sinY * sxcz;
    quat[3] = cosY * cxcz + sinY * sxsz;
}
