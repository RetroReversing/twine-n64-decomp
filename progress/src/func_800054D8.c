typedef struct Inner { char pad[0x30]; float result; char pad2[0x2c]; float *values; char pad3[0x30]; s16 index; } Inner;
typedef struct Outer { char pad[0x68]; Inner *inner; } Outer;
void func_800054D8(Outer *a) {
 Inner *p = a->inner;
 s16 i = p->index;
 float *v = p->values;
 float result;
 if (i == 0) result = 0.0f;
 else result = v[i + 1];
 a->inner->result = result;
}
