/* Counts polygon edges crossing the horizontal ray at height y and toggles a flag when the crossing lies right of x. */
s32 polygonRayCrossesRight(s32 vertexCount, f32 *xs, f32 *ys, f32 x, f32 y) {
    volatile s32 scratch[2];
    s32 i;
    s32 prev;
    s32 crossingFlag;
    f32 ys0;
    f32 xs0;
    f32 yCur;
    f32 *ysCursor;
    f32 *xsCursor;

    i = 0;
    prev = vertexCount - 1;
    crossingFlag = 0;
    if (vertexCount > 0) {
        ysCursor = ys;
        xsCursor = xs;
        do {
            yCur = *ysCursor;
            if (!(yCur <= y) || !(y < ys[prev])) {
                if (ys[prev] <= y) {
                    if (y < yCur) {
                        goto block_8;
                    }
                }
            } else {
block_8:
                xs0 = *ysCursor;
                yCur = xs[prev];
                ys0 = *xsCursor;
                if (x < ((((yCur - ys0) * (y - xs0)) / (ys[prev] - xs0)) + ys0)) {
                    crossingFlag = crossingFlag == 0;
                }
            }
            prev = i;
            ysCursor += 1;
            i += 1;
            xsCursor += 1;
        } while (i < vertexCount);
    }
    return crossingFlag;
}
