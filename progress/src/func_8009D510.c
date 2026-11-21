extern void bzero(void *, int);
extern int osCreateMesgQueue(void *, void *, int);
typedef struct {
    char pad0[0x166];
    short s166;
    char pad1[0x190 - 0x168];
    int w190, w194, w198, w19c;
    char pad2[0x11A0 - 0x1A0];
    unsigned short h11A0, h11A2;
    int w11A4, w11A8;
    char q[0x18];
    int w11C4;
    int w11C8, w11CC, w11D0, w11D4, w11D8;
    char b11DC, b11DD, b11DE;
} S;
void func_8009D510(S *arg0, int arg1, int arg2, int arg3, int arg4) {
    bzero(arg0, 0x190);
    arg0->s166 = 0x28;
    arg0->w190 = arg4;
    arg0->w194 = arg1;
    arg0->w198 = arg2;
    arg0->w19c = arg3;
    arg0->w11A8 = 0;
    osCreateMesgQueue((char *)arg0 + 0x11AC, (char *)arg0 + 0x11C4, 1);
    if (arg1 == 0 || arg4 == 0) {
        arg0->b11DD = 0;
    } else {
        arg0->b11DD = 1;
    }
    arg0->b11DC = 0;
    arg0->h11A0 = arg0->w11A4 = arg0->h11A2 = 0;
    arg0->w11C8 = 0;
    arg0->w11D0 = 0;
    arg0->w11CC = 0;
    arg0->w11D8 = 0;
    arg0->w11D4 = 0;
    arg0->b11DE = 2;
}
