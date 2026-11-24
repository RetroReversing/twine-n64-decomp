extern u16 gFrameEventFlags, gTargetSearchEnabled, D_80100786, D_80102F2A, D_80113020, gPrevFrameEventFlags;
extern u8 sDifficultyLevel;
extern f32 gMinTargetValue;
/* Resets target-search state and sets the minimum target value from the difficulty level. */ void resetTargetSearch(void) {
    f32 minTargetValue;
    u16 savedValue = gFrameEventFlags;
    gTargetSearchEnabled = 0;
    D_80100786 = 0;
    D_80102F2A = 0;
    gFrameEventFlags = 0;
    D_80113020 = 0;
    gPrevFrameEventFlags = savedValue;
    switch (sDifficultyLevel) {
    case 0:
    default:
        minTargetValue = 240.0f;
        break;
    case 1:
        minTargetValue = 120.0f;
        break;
    case 2:
        minTargetValue = 120.0f;
        break;
    }
    gMinTargetValue = minTargetValue;
}
