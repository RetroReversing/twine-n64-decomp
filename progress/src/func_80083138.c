f32 __cosf(f32);
f32 sinApprox(f32);

void func_80083138(const s16 *angles, f32 *matrix) {
    register f32 temp_fs0;
    register f32 temp_ft1;
    f32 temp_ft0_2;
    f32 temp_ft0;
    register f32 temp_fs0_2;
    f32 temp_fs2;
    f32 temp_fv1_2;
    f32 temp_fs0_4;
    f32 temp_fs0_3;
    f32 temp_fs4;
    f32 temp_fv0;
    f32 temp_ft2;
    f32 temp_fv0_2;
    register f32 temp_fs1;
    register f32 temp_fv1;
    register f32 temp_fs3;


    temp_fs0 = (f32) angles[0] * 0.0015339808f;
    temp_fs4 = __cosf(temp_fs0);
    temp_fs3 = sinApprox(temp_fs0);
    temp_fs0_2 = (f32) angles[1] * 0.0015339808f;
    temp_fs2 = __cosf(temp_fs0_2);
    temp_fs1 = sinApprox(temp_fs0_2);
    temp_fs0_3 = (f32) angles[2] * 0.0015339808f;
    temp_fs0_4 = __cosf(temp_fs0_3);
    temp_fv0 = sinApprox(temp_fs0_3);

    matrix[0] = (temp_fs0_4 * temp_fs2);
    matrix[1] = (temp_fs0_4 * temp_fs1) * temp_fs3 - (temp_fv0 * temp_fs4);
    matrix[2] = (temp_fs0_4 * temp_fs1) * temp_fs4 + (temp_fv0 * temp_fs3);
    matrix[3] = (temp_fv0 * temp_fs2);
    matrix[4] = (temp_fv0 * temp_fs1) * temp_fs3 + (temp_fs0_4 * temp_fs4);
    matrix[5] = (temp_fv0 * temp_fs1) * temp_fs4 - (temp_fs0_4 * temp_fs3);
    matrix[6] = -temp_fs1;
    matrix[7] = (temp_fs2 * temp_fs3);
    matrix[8] = (temp_fs2 * temp_fs4);
}
