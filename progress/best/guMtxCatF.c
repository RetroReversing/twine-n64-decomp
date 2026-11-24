typedef union {
    f32 cells[16];
    u32 words[16];
} MatrixWords;

void func_800A3840(volatile f32 *left, volatile f32 *right, f32 *out) {
    MatrixWords tmp;
    f32 *leftEnd = left + 16;
    f32 *rightEnd = right + 4;
    f32 *dst = tmp.cells;
    f32 result;
    do {
        volatile f32 *column = right;
        do {
            f32 l0 = left[0];
            f32 r0 = column[0];
            f32 l1, r1, l2, r2, l3, r3;
            result = l0 * r0;
            l1 = left[1];
            r1 = column[4];
            result += l1 * r1;
            l2 = left[2];
            r2 = column[8];
            result += l2 * r2;
            l3 = left[3];
            r3 = column[12];
            result += l3 * r3;
            *dst = result;
            column++;
            dst++;
        } while (column != rightEnd);
        left += 4;
    } while (left != leftEnd);
    out[15] = result;
    {
        u32 *words = (u32 *)out;
        u32 word0 = tmp.words[0];
        u32 word1 = tmp.words[1];
        u32 word2 = tmp.words[2];
        u32 word3 = tmp.words[3];
        u32 word4 = tmp.words[4];
        u32 word5 = tmp.words[5];
        u32 word6 = tmp.words[6];
        u32 word7 = tmp.words[7];
        u32 word8 = tmp.words[8];
        u32 word9 = tmp.words[9];
        u32 word10 = tmp.words[10];
        u32 word11 = tmp.words[11];
        u32 word12 = tmp.words[12];
        u32 word13 = tmp.words[13];
        u32 word14 = tmp.words[14];
        words[0] = word0;
        words[1] = word1;
        words[2] = word2;
        words[3] = word3;
        words[4] = word4;
        words[5] = word5;
        words[6] = word6;
        words[7] = word7;
        words[8] = word8;
        words[9] = word9;
        words[10] = word10;
        words[11] = word11;
        words[12] = word12;
        words[13] = word13;
        words[14] = word14;
    }
}
