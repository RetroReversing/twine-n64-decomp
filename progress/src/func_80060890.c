typedef struct { s32 x, y, z; } V3i;
typedef struct { s32 pad; V3i vec[3]; } Out;
typedef struct { V3i vec; u8 pad[12]; } InRec;
void func_80060890(Out *out, InRec *in, s32 count, V3i *fallback) {
    u32 start;
    u8 more;
    u32 n;
    u32 i = 0;
    V3i *fill = fallback;
    if (in != NULL) {
        out->vec[0] = in[0].vec;
        start = 1;
        n = (u16)count;
        more = start < n;
        i = 1;
        if (more) {
            do {
                out->vec[(u16)i] = in[(u16)i].vec;
                i++;
            } while (((u16)i < 3) & ((u16)i < n));
        }
    }
    {
        u32 j = i;
        u32 k = (u16)i;

        goto check;
        do {
            out->vec[k] = *fill;
            j++;
            k = (u16)j;
check:
            ;
        } while (k < 3);
    }
}
