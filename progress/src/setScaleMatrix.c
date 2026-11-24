/* Builds a 4x4 uniform scale matrix: scale on the diagonal, zeros elsewhere, with [3][3] set to 1. */
void setScaleMatrix(f32 (*mtx)[4], f32 scale) {
    s32 row;
    s32 col;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            if (row == col) {
                mtx[row][col] = scale;
            } else {
                mtx[row][col] = 0;
            }
        }
    }
    mtx[3][3] = 1.0f;
}
