typedef struct { s32 a; s16 b; s8 c; u8 d; } T;
void func_8002B2FC(T *a, T *b) {
 if ((a != 0) & (b != 0)) {
  a->b += b->b;
  while (a->b > a->d) { a->b -= a->d; a->c++; }
  a->c += b->c;
  while (a->c > 60) { a->c -= 60; a->a++; }
  a->a += b->a;
 }
}
