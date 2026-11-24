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
/* Zeroes an audio stream state block, stores its parameters, creates its message queue and resets playback fields. */ void initAudioStreamState(S *stream, int source, int param2, int param3, int bufferSize) {
    bzero(stream, 0x190);
    stream->s166 = 0x28;
    stream->w190 = bufferSize;
    stream->w194 = source;
    stream->w198 = param2;
    stream->w19c = param3;
    stream->w11A8 = 0;
    osCreateMesgQueue((char *)stream + 0x11AC, (char *)stream + 0x11C4, 1);
    if (source == 0 || bufferSize == 0) {
        stream->b11DD = 0;
    } else {
        stream->b11DD = 1;
    }
    stream->b11DC = 0;
    stream->h11A0 = stream->w11A4 = stream->h11A2 = 0;
    stream->w11C8 = 0;
    stream->w11D0 = 0;
    stream->w11CC = 0;
    stream->w11D8 = 0;
    stream->w11D4 = 0;
    stream->b11DE = 2;
}
