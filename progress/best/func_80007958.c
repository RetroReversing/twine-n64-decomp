typedef struct {
    u32 w0, w1;
} FrameCommand;

typedef struct {
    u8 pad000[0x100];
    u32 flags;
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
    s32 commandBytes;
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
extern void func_80034560(FrameView *);
extern void func_800075C4(u8, u32, u8, u8, u8);
extern void func_800389F0(FrameView *);
extern void func_80044410(s32);
extern void func_800A0220(void *, s32);
extern void func_8000B260(void);
extern void func_8000B224(FrameSlot *);
extern s32 func_8009F640(void);
extern void func_8009F6B0(s32);
extern void vi_apply_context(void);
extern u8 D_800AE4B0, D_8010A4C1, D_8010A4C2, D_80113022;
extern u32 D_800B1BE0[];
extern s16 D_800B1D70, D_800B1D72, D_8010A4B0;
extern u16 D_80109B9C, D_8010A518;
extern f32 D_800B1D78;
extern u64 D_800DD750[], D_800DD768[], D_8010A398;
extern u8 *D_80117728, *D_8010A928, *D_80109CB8, *D_801002FC, *D_8010A4B4;
extern void *D_80100304[];
extern u32 D_80109C98[], D_8010A2A0[];
extern s32 D_801032A0, D_8010A924, D_8010A920, D_8010A4E4;
extern s32 D_80100C04, D_8011740C, D_80112E40;
extern FrameView *D_80109688[];
extern FrameSlot *D_8010A2BC[];
extern FrameCommand *D_80115328;

static __inline__ f32 clamp_opacity(f32 value)
{
    return value < 0.0f ? 0.0f : value;
}

void func_80007958(void)
{
    FrameSlot *slot = D_8010A2BC[D_8010A4B0];
    FrameCommand *start = slot->start;
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
    s32 transitioning;
    s32 layer, previous, token;
    f32 opacity;
    u8 *modeFlags;

    D_80117728 = slot->buffer;
    D_8010A928 = (u8 *)slot + 0x798;
    D_80109CB8 = (u8 *)slot + 0x16A0;
    D_801002FC = (u8 *)slot + 0x1AA8;
    D_8010A4B4 = (u8 *)slot + 0x1BB0;
    D_800B1D78 += 1.0f;
    D_80115328 = start;
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
        i = 0;
        modeFlags = (u8 *)renderMode - 0x21;
        entry = D_80109688;
        D_80113022 = 0;
        do {
            buffer = D_80117728;
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
            D_80112E40 = -1;
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
                    cmd = D_80115328;
                    cmd->w0 = 0xDE000000;
                    cmd->w1 = (u32)D_800B1BE0;
                    view = *entry;
                    D_80115328 = cmd + 1;
                    func_8003C228(view, i, 5);
                }
                if (modeFlags[-2] & mask) {
                    cmd = D_80115328;
                    cmd->w0 = 0xDE000000;
                    cmd->w1 = (u32)D_800B1BE0;
                    view = *entry;
                    D_80115328 = cmd + 1;
                    func_80038000(view, i);
                }
                if (modeFlags[-1] & mask) {
                    layer = 4;
                    layerEntry = entry;
                    func_80034560(*entry);
                    __repair_rows: {
                        func_8003C228(*layerEntry, i, layer);
                    }
if (--layer >= 0) goto __repair_rows;
                }
            }
            mask = 1U << i;
            if (!(D_8010A4C1 & mask) && !(D_8010A4C2 & mask)) {
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
            i++;
            entry++;
        } while (i < 6);
    }

    func_80044410(0);
    cmd = D_80115328++;
    transitioning = ((u32)cmd - 0x30) - (u32)slot;
    cmd->w0 = 0xE9000000;
    cmd->w1 = 0;
    cmd = D_80115328++;
    cmd->w0 = 0xDF000000;
    cmd->w1 = 0;
    func_800A0220(slot->buffer, transitioning);
    func_800A0220(slot->buffer, ((u32)D_8010A928 - 0x798) - (u32)slot);
    func_800A0220(slot->buffer, ((u32)D_80109CB8 - 0x16A0) - (u32)slot);
    func_800A0220(slot->buffer, ((u32)D_801002FC - 0x1AA8) - (u32)slot);
    func_800A0220(slot->buffer, ((u32)D_8010A4B4 - 0x1BB0) - (u32)slot);

    submittedSlot = slot;
    submittedSlot->commands = *(FrameCommand **)(D_80117728 + 0x750);
    submittedSlot->commandBytes = ((s32)((u32)D_80115328 - *(u32 *)(D_80117728 + 0x750)) >> 3) << 3;
    if (D_800B1D70 != D_800B1D72) {
        func_8000B260();
        osRecvMesg(D_8010A2A0, NULL, 1);
        previous = D_8010A4B0 - 1;
        if (previous < 0) {
            previous += D_8010A518;
        }
        osViSwapBuffer(D_80100304[previous]);
        D_800DD768[previous] = osGetTime() - D_800DD750[previous];

        switch (D_80109B9C) {
        default:
        case 1:
            while (D_8011740C < D_80100C04 + 2) {
                osRecvMesg(D_80109C98, NULL, 1);
            }
            token = func_8009F640();
            vi_apply_context();
            func_8009F6B0(token);
            break;
        case 0:
            while (osRecvMesg(D_80109C98, NULL, 0) == 0) {
            }
            while (D_8011740C < D_80100C04 + 1) {
                osRecvMesg(D_80109C98, NULL, 1);
            }
            osRecvMesg(D_80109C98, NULL, 1);
            break;
        case 2:
            while (D_8011740C < D_80100C04 + 2) {
                osRecvMesg(D_80109C98, NULL, 1);
            }
            break;
        }
        previous = (u16)D_800B1D72 + 1;
        D_80100C04 = D_8011740C;
        D_800B1D72 = previous;
    }
    if (!D_800AE4B0) {
        stamp = osGetTime();
        D_800DD750[D_8010A4B0] = stamp;
        func_8000B224(submittedSlot);
        D_800B1D70++;
        D_8010A4B0++;
        if (D_8010A4B0 >= D_8010A518) {
            D_8010A4B0 = 0;
        }
    }
}
