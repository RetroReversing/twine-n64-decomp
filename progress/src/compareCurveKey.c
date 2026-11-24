/* Comparator for curve records: orders by the u16 key at offset 4. */
s32 compareCurveKey(const u16 *curveA, const u16 *curveB) {
    return curveA[2] - curveB[2];
}
