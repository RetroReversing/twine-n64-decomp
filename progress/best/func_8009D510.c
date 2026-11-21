void func_8009D510(void *arg0, volatile s32 arg1, volatile s32 arg2, volatile s32 arg3, volatile s32 arg4) {
    volatile s32 pad[2];
    bzero(arg0, 0x190);
    *(s16 *)((s8 *)arg0 + 0x166) = 0x28;
    *(s32 *)((s8 *)arg0 + 0x190) = arg4;
    *(s32 *)((s8 *)arg0 + 0x198) = arg2;
    *(s32 *)((s8 *)arg0 + 0x11A8) = 0;
    *(s32 *)((s8 *)arg0 + 0x194) = arg1;
    *(s32 *)((s8 *)arg0 + 0x19C) = arg3;
    osCreateMesgQueue((s8 *)arg0 + 0x11AC, (s8 *)arg0 + 0x11C4);
    if (arg1 != 0) {
        *(s8 *)((s8 *)arg0 + 0x11DD) = 0;
        if (arg4 != 0) {
            *(s8 *)((s8 *)arg0 + 0x11DD) = 1;
        }
    } else {
        *(s8 *)((s8 *)arg0 + 0x11DD) = 0;
    }
    *(s8 *)((s8 *)arg0 + 0x11DC) = 0;
    *(s16 *)((s8 *)arg0 + 0x11A2) = 0;
    *(s32 *)((s8 *)arg0 + 0x11A4) = 0;
    *(s16 *)((s8 *)arg0 + 0x11A0) = 0;
    *(s32 *)((s8 *)arg0 + 0x11C8) = 0;
    *(s32 *)((s8 *)arg0 + 0x11D0) = 0;
    *(s32 *)((s8 *)arg0 + 0x11CC) = 0;
    *(s32 *)((s8 *)arg0 + 0x11D8) = 0;
    *(s32 *)((s8 *)arg0 + 0x11D4) = 0;
    *(s8 *)((s8 *)arg0 + 0x11DE) = 2;
}
