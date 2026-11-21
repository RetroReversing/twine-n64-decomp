void func_8009F1D4(void *, int, int);
typedef struct { char pad[0x168]; short rec[2][8]; short idx; } S;
#define F(v, off, k, add) (((((v) - (off)) << 10) * (k) + (add)) >> 15) * 2
void func_8009D9F0(S *arg0, short *arg1, int arg2, int arg3) {
    short *out = arg0->rec[arg0->idx];
    out[0] = F(arg1[0], 0x20, 0x3333, 0x4000);
    out[1] = F(arg1[1], 0x20, 0x3333, 0x4000);
    out[2] = F(arg1[2], 0x10, 0x3333, -0x332F000);
    out[3] = F(arg1[3], 0x10, 0x3333, 0x04003C00);
    out[4] = F(arg1[4], 8, 0x4B17, -0x36E4E4);
    out[5] = F(arg1[5], 8, 0x4444, 0x03BBF800);
    out[6] = F(arg1[6], 4, 0x7ADE, 0x0147936C);
    out[7] = F(arg1[7], 4, 0x740C, 0x040D6B40);
    func_8009F1D4(arg0, arg2, arg3);
    arg0->idx ^= 1;
}
