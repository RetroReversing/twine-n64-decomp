f32 absFloat(f32);
/* Approximates sqrt(x*x + y*y) as 0.9604*max(|x|,|y|) + 0.3978*min(|x|,|y|). */
f32 approxHypot2D(f32 x, f32 y) {
    f32 absX, absY, larger, smaller;
    x = absFloat(x);
    absX = x;
    absY = absFloat(y);
    y = absY;
    if (absY < absX) { larger = absX; smaller = absY; }
    else { larger = y; smaller = x; }
    return larger * 0.9604f + smaller * 0.3978f;
}
