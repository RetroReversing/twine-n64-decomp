typedef struct {
    u32 w0, w1;
} FrameCommand;

typedef struct {
    u8 pad000[0x100];
    unsigned int flags;
    u8 pad104[0x20];
    f32 overlay;
    u8 pad128[4];
    f32 opacity;
    u8 pad130[4];
    u32 alpha;
    u8 pad138[0xA];
    s8 transition;
} FrameView;

typedef struct {
    u8 pad00[0x30];
    FrameCommand *commands;
    long commandBytes;
    u8 pad38[8];
    u8 buffer[0x750];
    FrameCommand *start;
} FrameSlot;

extern u64 osGetTime(void);
extern s32 osRecvMesg(void *, void **, s32);
extern void osViSwapBuffer(void *);
extern void func_80034DD0(void);
extern void func_80034EFC(void);
extern void func_800344DC(FrameView *);
extern void func_80035060(FrameView *);
extern void func_8003C228(FrameView *, u32, s32);
extern void func_80038000(FrameView *, u32);
extern void emitScissorFromWindow(FrameView *);
extern void func_800075C4(u8, u32, u8, u8, u8);
extern void func_800389F0(FrameView *);
extern void func_80044410(s32);
extern void func_800A0220(void *, s32);
extern void func_8000B260(void);
extern void func_8000B224(FrameSlot *);
extern s32 __osDisableInt(void);
extern void __osRestoreInt(s32);
extern void vi_apply_context(void);
extern u8 D_800AE4B0, gTrackMarkerActiveMask, gSceneFlagsB, D_80113022;
extern u32 D_800B1BE0[];
extern s16 D_800B1D70, D_800B1D72, D_8010A4B0;
extern u16 D_80109B9C, sMatrixPoolSlotCount;
extern f32 D_800B1D78;
extern u64 D_800DD750[], D_800DD768[], D_8010A398;
extern u8 *sRenderState, *D_8010A928, *D_80109CB8, *D_801002FC, *D_8010A4B4;
extern void *D_80100304[];
extern u32 sGfxSyncQueue[], D_8010A2A0[];
extern s32 D_801032A0, D_8010A924, D_8010A920, D_8010A4E4;
extern s32 D_80100C04, gRetraceFrameCount, gRenderMode;
extern FrameView *sTrackMarkerTable[];
extern FrameSlot *sMatrixPoolSlots[];
extern FrameCommand *sDisplayListCursor;

static __inline__ f32 clamp_opacity(f32 value)
{
    return value < 0.0f ? 0.0f : value;
}

void func_80007958(void)
{
    FrameSlot *slot = sMatrixPoolSlots[D_8010A4B0];
    register FrameCommand *start = slot->start;
    s32 *renderMode;
    u8 *buffer, *segment1, *segment2, *segment3, *segment4;
    s32 commandBytes;
    FrameView **entry;
    FrameView *view;
    FrameSlot *submittedSlot;
    FrameView **layerEntry;
    u64 stamp;
    FrameCommand *cmd;
    u32 i, mask, alpha;
    register s32 transitioning;
    s32 layer, previous, token;
    f32 opacity;
    u8 *modeFlags;

    sRenderState = slot->buffer;
    D_8010A928 = (u8 *)slot + 0x798;
    D_80109CB8 = (u8 *)slot + 0x16A0;
    D_801002FC = (u8 *)slot + 0x1AA8;
    D_8010A4B4 = (u8 *)slot + 0x1BB0;
    D_800B1D78 += 1.0f;
    sDisplayListCursor = start;
    if (!start) {
        return;
    }

    D_8010A398 = osGetTime();
    func_80034DD0();

    renderMode = &D_8010A4E4;
    if (*renderMode == 0) {
        func_80034EFC();
    } else {
        transitioning = 0;
        modeFlags = (u8 *)renderMode - 0x21;
        i = 0;
        entry = sTrackMarkerTable;
        D_80113022 = 0;
        do {
            buffer = sRenderState;
            segment1 = D_8010A928;
            segment2 = D_80109CB8;
            segment3 = D_801002FC;
            segment4 = D_8010A4B4;
            *(u8 **)(buffer + 0x1658) = segment1;
            *(u8 **)(buffer + 0x1A60) = segment2;
            *(u8 **)(buffer + 0x1B68) = segment3;
            *(u8 **)(buffer + 0x1C70) = segment4;
            view = *entry;
            D_801032A0 = -1;
            D_8010A924 = -1;
            gRenderMode = -1;
            D_8010A920 = -1;

            if (view == NULL) {
                goto next_view;
            }
            opacity = clamp_opacity(view->opacity);
            view->alpha = (u32)(opacity * 255.0f);
            func_800344DC(view);
            if ((*entry)->flags & 0x40) {
                func_80035060(*entry);
                (*entry)->transition--;
                if ((*entry)->transition < 0) {
                    (*entry)->flags &= ~0x40;
                }
                transitioning = 1;
            } else if (!transitioning) {
                mask = 1U << i;
                if (modeFlags[0] & mask) {
                    func_80035060(*entry);
                }
                if (modeFlags[-1] & mask) {
                    cmd = sDisplayListCursor;
                    cmd->w0 = 0xDE000000;
                    cmd->w1 = D_800B1BE0;
                    view = *entry;
                    sDisplayListCursor = cmd + 1;
                    func_8003C228(view, i, 5);
                }
                if (modeFlags[-2] & mask) {
                    cmd = sDisplayListCursor;
                    cmd->w0 = 0xDE000000;
                    cmd->w1 = (u32)D_800B1BE0;
                    view = *entry;
                    sDisplayListCursor = cmd + 1;
                    func_80038000(view, i);
                }
                if (modeFlags[-1] & mask) {
                    layer = 4;
                    layerEntry = entry;
                    emitScissorFromWindow(*entry);
                    do {
                        func_8003C228(*layerEntry, i, layer);
                    } while (--layer >= 0);
                }
            }
            mask = 1U << i;
            if (!(gTrackMarkerActiveMask & mask) && !(gSceneFlagsB & mask)) {
                goto next_view;
            }

            view = *entry;
            if (view->overlay > 0.01f) {
                alpha = (u32)(view->overlay * 255.0f);
                if ((*entry)->flags & 2) {
                    func_800075C4(alpha, i, 0, 255, 0);
                } else {
                    func_800075C4(alpha, i, 255, 255, 255);
                }
                (*entry)->overlay *= 0.9f;
            } else {
                view->overlay = 0.0f;
            }
            alpha = (*entry)->alpha;
            if (alpha != 255) {
                func_800075C4(255 - alpha, i, 0, 0, 0);
            }
            func_800389F0(*entry);
        next_view:
            i += 1;
            entry += 1;
        } while (i < 6);
    }

    func_80044410(0);
    cmd = sDisplayListCursor++;
    transitioning = ((u32)cmd - 0x30) - (u32)slot;
    cmd->w0 = 0xE9000000;
    cmd->w1 = 0;
    cmd = sDisplayListCursor++;
    cmd->w0 = 0xDF000000;
    cmd->w1 = 0;
    func_800A0220(slot->buffer, transitioning);
    func_800A0220(slot->buffer, ((u32)D_8010A928 - 0x798) - (u32)slot);
    func_800A0220(slot->buffer, ((u32)D_80109CB8 - 0x16A0) - (u32)slot);
    func_800A0220(slot->buffer, ((u32)D_801002FC - 0x1AA8) - (u32)slot);
    func_800A0220(slot->buffer, ((u32)D_8010A4B4 - 0x1BB0) - (u32)slot);

    submittedSlot = slot;
    submittedSlot->commands = *(FrameCommand **)(sRenderState + 0x750);
    submittedSlot->commandBytes = ((s32)((u32)sDisplayListCursor - *(u32 *)(sRenderState + 0x750)) >> 3) << 3;
    if (D_800B1D70 != D_800B1D72) {
        func_8000B260();
        osRecvMesg(D_8010A2A0, NULL, 1);
        previous = (u32)D_8010A4B0 - 1;
        if (previous < 0) {
            previous += sMatrixPoolSlotCount;
        }
        osViSwapBuffer(D_80100304[previous]);
        D_800DD768[previous] = osGetTime() - D_800DD750[previous];

        switch (D_80109B9C) {
        default:
        case 1:
            while (gRetraceFrameCount < D_80100C04 + 2) {
                osRecvMesg(sGfxSyncQueue, NULL, 1);
            }
            token = __osDisableInt();
            vi_apply_context();
            __osRestoreInt(token);
            break;
        case 0:
            while (osRecvMesg((s32)sGfxSyncQueue, NULL, 0) == 0) {
            }
            while (gRetraceFrameCount < D_80100C04 + 1) {
                osRecvMesg(sGfxSyncQueue, NULL, 1);
            }
            osRecvMesg(sGfxSyncQueue, NULL, 1);
            break;
        case 2:
            while (gRetraceFrameCount < D_80100C04 + 2) {
                osRecvMesg(sGfxSyncQueue, NULL, 1);
            }
            break;
        }
        previous = (u16)D_800B1D72 + 1;
        D_80100C04 = (s32)gRetraceFrameCount;
        D_800B1D72 = previous;
    }
    if (!D_800AE4B0) {
        stamp = osGetTime();
        D_800DD750[D_8010A4B0] = stamp;
        func_8000B224(submittedSlot);
        D_800B1D70++;
        D_8010A4B0++;
        if (sMatrixPoolSlotCount <= D_8010A4B0) {
            D_8010A4B0 = 0;
        }
    }
}
