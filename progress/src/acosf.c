f64 libmAcos(f64);
/* Single-precision arccosine: wraps libmAcos. */
f32 acosf(f32 x) { return (f32)libmAcos((f64)x); }
