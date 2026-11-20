typedef struct { s32 x, y, z; } V3i;
typedef struct { s32 pad; V3i vec[3]; } Out;
typedef struct { s32 w[6]; } InRec;
void func_80060890(Out *out, InRec *in, s32 count, V3i *fallback) {
    u32 n = (u32)count & 0xFFFF;
    u32 i = 0;
    if (in != NULL) {
        out->vec[0] = *(V3i *)in;
        i = 1;
        while (i < 3 && i < n) {
            out->vec[i] = *(V3i *)((s8 *)in + i * 0x18);
            i++;
        }
    }
    while (i < 3) {
        out->vec[i] = *fallback;
        i++;
    }
}
