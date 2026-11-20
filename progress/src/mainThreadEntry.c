typedef struct {
    u32 *display;
    u32 base;
    u8 frame, frameCount, tick, delay;
    u16 stride;
} AnimationEntry;
extern u32 D_80107ED0;
extern AnimationEntry *D_80109EA0[];

void func_8003278C(void)
{
    u8 framePad[8];
    u32 count = D_80107ED0;
    register u32 i = 0;
    if (count != 0) {
        AnimationEntry **entries = D_80109EA0;
        do {
            AnimationEntry *entry = *entries;
            u8 tick = entry->tick;
            u8 delay = entry->delay;
            entry->tick = ++tick;
            if (delay < tick) {
                u8 frame = entry->frame;
                u8 frameCount = entry->frameCount;
                entry->tick = 0;
                entry->frame = ++frame;
                if (frame == frameCount)
                    entry->frame = 0;
                *entry->display = entry->base + entry->frame * entry->stride;
            }
            count = D_80107ED0;
            i++;
            entries++;
        } while (i < count);
    }
}

extern void func_800081C4(s32);
extern void func_8001087C(void);
extern void func_80011950(void);
extern void func_8009D0DC(void);
extern s32 func_800A6790(void);
extern void osCreateMesgQueue(void *, void *, s32);
extern s32 osRecvMesg(void *, void *, s32);
extern void osSetEventMesg(s32, void *, void *);
extern void osViBlack(u8);
extern void osViSetYScale(f32);
extern volatile s8 D_800AE4B0;
extern s32 D_800D93B0, D_80112E80;

void mainThreadEntry(void)
{
    osCreateMesgQueue(&D_80112E80, &D_800D93B0, 1);
    osSetEventMesg(14, &D_80112E80, 0);
    osRecvMesg(&D_80112E80, 0, 1);
    D_800AE4B0 = 1;
    func_800081C4(0);
    osViSetYScale(1.0f);
    osViBlack(1);
    func_8009D0DC();
    func_8001087C();
    do {} while (func_800A6790() != 0);
loop:
    func_80011950();
    goto loop;
}
