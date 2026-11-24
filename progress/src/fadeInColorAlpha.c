typedef struct { u8 pad[0x10]; u32 rgba; } ColorRecord;
typedef struct {
    u8 pad[0x2C];
    ColorRecord *primary;
    u32 pad30;
    ColorRecord *secondary;
} ColorPair;

void setStateMachineState(void *arg0, s16 arg1, ...);

void fadeInColorAlpha(ColorPair *pair, void *owner) {
    s32 adjust;
    u32 rgba = pair->primary->rgba;
    if ((rgba & 255) < 255) {
        adjust = (u8)rgba + 16;
        if (adjust >= 0) {
            owner = (void *)(rgba + 16);
            if (adjust >= 256)
                owner = (void *)255;
        } else {
            owner = 0;
        }
        pair->primary->rgba = (pair->primary->rgba & ~255) | ((u32)owner & 255);
        pair->secondary->rgba = (pair->secondary->rgba & ~255) | ((u32)owner & 255);
    } else {
        setStateMachineState(owner, 5, pair);
    }
}
