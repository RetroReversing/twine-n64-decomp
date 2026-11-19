void func_80082908(f32);
void func_80045540(const f32 *a, const f32 *b) { f32 x, y, z; x = a[0] - b[0]; y = a[1] - b[1]; z = a[2] - b[2]; x = x * x; y = y * y; func_80082908(x + y + z * z); }
