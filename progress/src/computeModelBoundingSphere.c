f32 sqrtf32(f32, f32 *, void *, s32);

/* Scans the model's vertices for an axis-aligned bounding box (written to outBounds as min/max pairs) and writes the box center and half-diagonal radius to outSphere. */ void computeModelBoundingSphere(void *model, f32 *outSphere, void *outBounds, s32 arg3) {
    f32 *temp_s0;
    f32 *temp_v0;
    u16 temp_v1;
    f32 x2, y2, z2, length2;
    f32 sizeZ;
    f32 sizeY;
    f32 sizeX;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxY;
    f32 maxZ;
    f32 maxX;
    u32 var_a3;
    f32 *var_a1;
    f32 *temp_v1_2;

    temp_s0 = outSphere;
    var_a1 = temp_s0;
    var_a3 = arg3;
    if (model == NULL) return;
    if (temp_s0 != NULL) {
        temp_v0 = *(f32 **)((char *)model + 0x34);
        temp_v1 = *(u16 *)((char *)model + 0x42);
        minX = temp_v0[0];
        minY = temp_v0[1];
        minZ = temp_v0[2];
        maxX = minX;
        maxY = minY;
        maxZ = minZ;
        if (temp_v1) {
            var_a3 = 0;
            var_a1 = temp_v0;
            temp_v1_2 = (f32 *)(temp_v1 * 0xC + (u32)temp_v0);
            do {
                temp_fv0 = *var_a1;
                if (temp_fv0 < minX) {
                    minX = temp_fv0;
                } else if (maxX < temp_fv0) {
                    maxX = temp_fv0;
                }
                temp_fv0_2 = *(f32 *)(var_a3 + *(u32 *)((char *)model + 0x34) + 4);
                if (minY > temp_fv0_2) {
                    minY = temp_fv0_2;
                } else if (temp_fv0_2 > maxY) {
                    maxY = temp_fv0_2;
                }
                temp_fv0_3 = *(f32 *)(var_a3 + *(u32 *)((char *)model + 0x34) + 8);
                if (minZ > temp_fv0_3) {
                    minZ = temp_fv0_3;
                } else if (maxZ < temp_fv0_3) {
                    maxZ = temp_fv0_3;
                }
                var_a3 += 0xC;
                var_a1 += 3;
            } while ((s32)var_a1 < (s32)temp_v1_2);
        }
        sizeX = maxX - minX;
        x2 = sizeX * sizeX;
        sizeY = maxY - minY;
        y2 = sizeY * sizeY;
        sizeZ = maxZ - minZ;
        z2 = sizeZ * sizeZ;
length2 = x2 + y2;
((f32 *)outBounds)[1] = maxX;
((f32 *)outBounds)[3] = maxY;
do { } while (0);
((f32 *)outBounds)[5] = maxZ;
length2 += z2;
((f32 *)outBounds)[0] = minX;
((f32 *)outBounds)[2] = minY;
((f32 *)outBounds)[4] = minZ;
        temp_s0[3] = sqrtf32(length2, var_a1, outBounds, var_a3) * 0.5f;
        temp_s0[0] = minX + (sizeX * 0.5f);
        temp_s0[1] = minY + (sizeY * 0.5f);
        temp_s0[2] = minZ + (sizeZ * 0.5f);
    }
}
