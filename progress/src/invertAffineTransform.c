/* Inverts a 3x4 affine transform (3x3 matrix plus translation) from src into dst. */
void invertAffineTransform(void *arg0, void *arg1) {
    f32 *dst = arg0;
    f32 *src = arg1;
    f32 p00, p01, p10, p11, p20, p21;
    f32 cof0, cof1, cof2;
    f32 invDet;
    f32 negInvDet;
    f32 src4, src8, src7, src5, src3, src6;

    src4 = src[4];
    src8 = src[8];
    p00 = src4 * src8;
    src7 = src[7];
    src5 = src[5];
    p01 = src7 * src5;
    src3 = src[3];
    p11 = src3 * src8;
    src6 = src[6];
    p10 = src6 * src5;
    p20 = src3 * src7;
    p21 = src6 * src4;
    cof0 = p00 - p01;
    cof1 = p10 - p11;
    cof2 = p20 - p21;
    invDet = 1.0f / ((src[0] * cof0) + (src[1] * cof1) + (src[2] * cof2));
    dst[0] = invDet * cof0;
    dst[3] = invDet * cof1;
    dst[6] = invDet * cof2;
    negInvDet = -invDet;
    dst[1] = negInvDet * ((src[1] * src[8]) - (src[7] * src[2]));
    dst[4] = invDet * ((src[0] * src[8]) - (src[6] * src[2]));
    dst[7] = negInvDet * ((src[0] * src[7]) - (src[6] * src[1]));
    dst[2] = invDet * ((src[1] * src[5]) - (src[4] * src[2]));
    dst[5] = negInvDet * ((src[0] * src[5]) - (src[3] * src[2]));
    dst[8] = invDet * ((src[0] * src[4]) - (src[3] * src[1]));
    dst[9] = ((-src[9] * dst[0]) - (src[10] * dst[1])) - (src[11] * dst[2]);
    dst[10] = ((-src[9] * dst[3]) - (src[10] * dst[4])) - (src[11] * dst[5]);
    dst[11] = ((-src[9] * dst[6]) - (src[10] * dst[7])) - (src[11] * dst[8]);
}
