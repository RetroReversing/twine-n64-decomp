f32 absFloat(f32);

/* Approximates the distance between two 3D points: sorts the absolute axis deltas and returns a weighted sum of them. */
f32 approxDistance(void *posA, void *posB) {
    f32 swapTemp;
    f32 swapTemp2;
    f32 swapTemp3;
    f32 largestDelta;
    f32 middleDelta;
    f32 smallestDelta;

    largestDelta = absFloat(*(f32 *)((s8 *)posA + 0) - *(f32 *)((s8 *)posB + 0));
    middleDelta = absFloat(*(f32 *)((s8 *)posA + 4) - *(f32 *)((s8 *)posB + 4));
    smallestDelta = absFloat(*(f32 *)((s8 *)posA + 8) - *(f32 *)((s8 *)posB + 8));
    if (largestDelta < middleDelta) {
        swapTemp = largestDelta;
        largestDelta = middleDelta;
        middleDelta = swapTemp;
    }
    swapTemp2 = smallestDelta;
    if (largestDelta < smallestDelta) {
        smallestDelta = largestDelta;
        largestDelta = swapTemp2;
    }
    swapTemp3 = middleDelta;
    if (middleDelta < smallestDelta) {
        middleDelta = smallestDelta;
        smallestDelta = swapTemp3;
    }
    return (largestDelta * 0.9398f) + (middleDelta * 0.3893f) + (smallestDelta * 0.2987f);
}
