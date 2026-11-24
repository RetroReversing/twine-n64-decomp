typedef struct {
    u16 flags; u16 pad; s32 buffer; struct Mode *mode; s32 control; u8 pad10[16];
    u32 xscale; f32 yfactor; u16 origin; u16 pad2a; u32 yscale;
} ViContext;
typedef struct Mode {
    u32 unk0, unk4, width, burst, vsync, hsync, leap, hvideo, xscale, unk24;
    struct { u32 origin, yscale, vvideo, vburst, vintr; } f[2];
} Mode;
extern ViContext *gViCurrentContext, *gViPendingContext;
extern s32 D_800CFEBC;
extern volatile u32 D_A4400000;
extern s32 osVirtualToPhysical(s32);

#define VI_CONTROL (*(volatile u32 *)0xA4400000)
#define VI_CURRENT  (*(volatile u32 *)0xA4400010)
#define VI_ORIGIN   (*(volatile u32 *)0xA4400004)
#define VI_WIDTH    (*(volatile u32 *)0xA4400008)
#define VI_V_INTR   (*(volatile u32 *)0xA440000C)
#define VI_BURST    (*(volatile u32 *)0xA4400014)
#define VI_V_SYNC   (*(volatile u32 *)0xA4400018)
#define VI_H_SYNC   (*(volatile u32 *)0xA440001C)
#define VI_LEAP     (*(volatile u32 *)0xA4400020)
#define VI_H_VIDEO  (*(volatile u32 *)0xA4400024)
#define VI_V_VIDEO  (*(volatile u32 *)0xA4400028)
#define VI_V_BURST  (*(volatile u32 *)0xA440002C)
#define VI_X_SCALE  (*(volatile u32 *)0xA4400030)
#define VI_Y_SCALE  (*(volatile u32 *)0xA4400034)

/* Programs the VI registers from the active display context and swaps the
 * active and pending contexts. Context flags: 0x02 keep the mode's xscale
 * fraction, 0x04 scale yscale by yfactor, 0x20 blank horizontal video,
 * 0x40 black frame (no yscale, buffer origin), 0x80 yscale from origin. */
void vi_apply_context(void) {
    ViContext *new_active_ctx;
    ViContext *ctx;
    Mode *mode;
    s32 field, origin, hvideo, vvideo; u32 ctrl;
    u32 scaled;
    ctx = gViCurrentContext;
    field = VI_CURRENT & 1;
    mode = ctx->mode;
    origin = osVirtualToPhysical(ctx->buffer) + mode->f[field].origin;
    if (ctx->flags & 2) ctx->xscale |= mode->xscale & ~0xFFFu;
    else ctx->xscale = mode->xscale;
    if (ctx->flags & 4) {
        scaled = (u32)(ctx->yfactor * (f32)(mode->f[field].yscale & 0xFFF));
        ctx->yscale = scaled;
        ctx->yscale = scaled | (mode->f[field].yscale & ~0xFFFu);
    } else ctx->yscale = mode->f[field].yscale;
    hvideo = mode->hvideo;
    vvideo = mode->f[field].vvideo - (D_800CFEBC << 16) + D_800CFEBC;
    hvideo &= -((ctx->flags & 0x20) == 0);
    if (ctx->flags & 0x40) { ctx->yscale = 0; origin = osVirtualToPhysical(ctx->buffer); }
    if (ctx->flags & 0x80) {
        ctx->yscale = ((u32)ctx->origin << 16) & 0x03FF0000;
        origin = osVirtualToPhysical(ctx->buffer);
    }
    VI_ORIGIN = origin;
    VI_WIDTH = mode->width;
    VI_BURST = mode->burst;
    VI_V_SYNC = mode->vsync;
    VI_H_SYNC = mode->hsync;
    VI_LEAP = mode->leap;
    VI_H_VIDEO = hvideo;
    VI_V_VIDEO = vvideo;
    VI_V_BURST = mode->f[field].vburst;
    VI_V_INTR = mode->f[field].vintr;
    VI_X_SCALE = ctx->xscale;
    VI_Y_SCALE = ctx->yscale;
    ctrl = ctx->control;
    new_active_ctx = gViPendingContext;
    gViPendingContext = ctx;
    gViCurrentContext = new_active_ctx;
    VI_CONTROL = ctrl;
    __builtin_memcpy(new_active_ctx, ctx, sizeof(ViContext));
}
