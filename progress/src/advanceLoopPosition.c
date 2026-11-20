/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f64 func_8008CD54();
extern f64 D_800D6720;
extern f64 D_800D6728;
extern f64 D_800D6730;
extern f64 D_800D6738;
extern f64 D_800D6740;
extern f64 D_800D6748;
extern f64 D_800D6750;
extern f64 D_800D6758;

/* Advances a looping position by speed*frames, wrapping in the loop range or clamping at the end. */ void advanceLoopPosition(void *obj, s32 frames) {
    register f64 posNext;
    f64 step;
    f64 pos;
    f64 wraps;
    s32 endRaw;
    f64 loopEnd;
    f64 loopEndF;
    f64 loopLenF;
    register f64 loopLenCF;
    f64 startF;
    f64 endF;
    f64 lastFrameF;
    s32 frameCount;
    s32 loopEndRaw;
    s32 loopEndRawB;
    s32 loopLenC;
    s32 startRaw;
    f64 newPos;
    s32 lastFrame;
    s32 loopLen;
    s32 loopLenB;

    loopLen = (*(s32 *)((char *)(obj) + 0x38));
    frameCount = frames & 0xFFFF;
    step = (f64) ((*(u16 *)((char *)(obj) + 4)) * frameCount) * D_800D6720;
    if ((loopLen) && (((*(u8 *)((char *)(obj) + 1)) != 0) || ((*(s32 *)((char *)(obj) + 0x3C)) == 0))) {
        loopEndRaw = (*(s32 *)((char *)(obj) + 0x34)) + loopLen;
        loopEnd = (f64) loopEndRaw;
        if (loopEndRaw < 0) {
            loopEnd += D_800D6728;
        }
        if (func_8008CD54(*(f64 *)((char *)obj + 8)) <= loopEnd) {
            loopLenB = (*(s32 *)((char *)(obj) + 0x38));
            loopEndRawB = (*(s32 *)((char *)(obj) + 0x34)); loopEndRawB += loopLenB;
            loopEndF = (f64) loopEndRawB;
            if (0 > loopEndRawB) {
                loopEndF += D_800D6730;
            }
            pos = (*(f64 *)((char *)(obj) + 8));
            newPos = pos + step;
            if (newPos < loopEndF) {
                (*(f64 *)((char *)(obj) + 8)) = newPos;
                return;
            } else {
                loopLenF = (f64) loopLenB;
                step = step - (loopEndF - pos);
                if (loopLenB < 0) {
                    loopLenF += D_800D6738;
                }
                wraps = func_8008CD54(step / loopLenF);
                loopLenC = (*(s32 *)((char *)(obj) + 0x38));
                loopLenCF = (f64) (s32)loopLenC;
                if (0 > loopLenC) {
                    loopLenCF += D_800D6740;
                }
                step -= wraps * loopLenCF;
                startRaw = (*(s32 *)((char *)(obj) + 0x34));
                startF = (f64) startRaw;
                if (startRaw < 0) {
                    startF += D_800D6748;
                }
                (*(f64 *)((char *)(obj) + 8)) = (f64) (startF + step);
                return;
            }
        }
        goto block_19;
    }
block_19:
    endRaw = (*(s32 *)((char *)(obj) + 0x30));
    endF = (f64) endRaw;
    posNext = (*(f64 *)((char *)(obj) + 8)) + step;
    if (0 > endRaw) {
        endF += D_800D6750;
    }
    lastFrame = endRaw - 1;
    if (posNext >= endF) {
        lastFrameF = (f64) lastFrame;
        if (0 > lastFrame) {
            lastFrameF += D_800D6758;
        }
        (*(f64 *)((char *)(obj) + 8)) = lastFrameF;
        return;
    }
    (*(f64 *)((char *)(obj) + 8)) = posNext;
}


