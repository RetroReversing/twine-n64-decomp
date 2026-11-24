typedef struct {
    u32 w0, w1;
} DisplayCommand;

extern s32 gFrameBufferIndex;
extern DisplayCommand *volatile sDisplayListCursor;
extern u8 *sRenderState;

/* Appends projection/modelview matrix and light/viewport display list commands for the current frame buffer. */ void appendMatrixAndLightCommands(void) {
    u32 projectionCmd = 0xDA380007;
    u32 modelviewCmd = 0xDA380005;
    DisplayCommand *cmd = sDisplayListCursor;
    s32 bufferIndex = gFrameBufferIndex;
    s32 matrixOffsetInState = (bufferIndex << 6) + 0x560;
    u8 *renderState = sRenderState;
    u32 segmentBias = 0x80000040;
    u32 baseAddr;
    u16 viewportValue;

    cmd[0].w0 = projectionCmd;
    cmd[0].w1 = (u32)(renderState + matrixOffsetInState) - 0x80000000;
    cmd[1].w0 = modelviewCmd;
    baseAddr = *(u32 *)(renderState + 0x74C);
    cmd[2].w0 = 0xDC080008;
    cmd[2].w1 = (u32)(renderState + ((bufferIndex << 4) + 0x6E0));
    cmd[3].w0 = 0xDB0E0000;
    cmd[1].w1 = baseAddr + segmentBias;
    viewportValue = ((u16 *)(renderState + 0x740))[bufferIndex];
    sDisplayListCursor = cmd + 1;
    sDisplayListCursor = cmd + 2;
    sDisplayListCursor = cmd + 3;
    sDisplayListCursor = cmd + 4;
    cmd[3].w1 = viewportValue;
}
