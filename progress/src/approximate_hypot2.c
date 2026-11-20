f32 absFloat(f32);
f32 approximate_hypot2(f32 a, f32 b) {
    f32 first, second, high, low;
    a = absFloat(a);
    first = a;
    second = absFloat(b);
    b = second;
    if (second < first) { high = first; low = second; }
    else { high = b; low = a; }
    return high * 0.9604f + low * 0.3978f;
}
