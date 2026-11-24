/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 initResourceCaches();
s32 setRotationInterpolationMode();
s32 buildFrameDistanceTable();
typedef struct { s32 a; s16 b; s16 c; } Rec;
extern Rec D_800C3924[];
extern s16 D_800C39B0;
extern s32 D_800D93C0;
extern s32 D_800D93C4;
extern s32 D_800D93C8;
extern s32 D_800D93CC;
extern s32 D_800D93D0;
extern s32 D_800D93D4;
extern s32 D_800D93D8;
extern s32 D_800D93DC;
extern s32 D_800D93E0;
extern s32 D_800D93E4;
extern s32 D_800D93E8;
extern s32 D_800D93EC;
extern s32 D_800D93F0;
extern s32 D_800D93F4;
extern s32 D_800D93F8;
extern s32 D_800D93FC;
extern s32 D_800D9400;
extern s32 D_800D9404;
extern s32 D_800D9408;
extern s32 D_800D940C;
extern s32 D_800D9410;
extern s32 gBootState;

/* Boot init: resets state, initialises resource caches, flags table rows whose b field differs from D_800C39B0, and stores the handle for each asset id. */ /* Resets the boot state, initialises the resource caches, flags table entries whose b field differs from D_800C39B0, and stores the handles for each asset id. */ void initAssetHandles(void) {
    s32 rec_index;
    s16 *threshold_ptr;

    gBootState = 0;
    initResourceCaches();
    setRotationInterpolationMode(0);
    for (rec_index = 0; D_800C3924[rec_index].a != 0; rec_index++) {
        threshold_ptr = &D_800C39B0;
        D_800C3924[rec_index].c = 0;
        if (D_800C3924[rec_index].b != *threshold_ptr) {
            D_800C3924[rec_index].c = 1;
        }
    }
    D_800D93C0 = buildFrameDistanceTable(0x1D0, 4, 0);
    D_800D93C4 = buildFrameDistanceTable(0x331, 4, 0);
    D_800D93C8 = buildFrameDistanceTable(0x245, 4, 0);
    D_800D93CC = buildFrameDistanceTable(0x1D1, 4, 0);
    D_800D93D0 = buildFrameDistanceTable(0x248, 4, 0);
    D_800D93D4 = buildFrameDistanceTable(0x247, 4, 0);
    D_800D93D8 = buildFrameDistanceTable(0x1DC, 4, 0);
    D_800D93E8 = buildFrameDistanceTable(0x4D, 4, 0);
    D_800D93EC = buildFrameDistanceTable(0x65, 1, 0);
    D_800D93F0 = buildFrameDistanceTable(0x6B, 1, 0);
    D_800D93DC = buildFrameDistanceTable(0x1CE, 2, 0);
    D_800D93E0 = buildFrameDistanceTable(0x1D9, 4, 1);
    D_800D93E4 = buildFrameDistanceTable(0x1DB, 4, 1);
    D_800D93F4 = buildFrameDistanceTable(0x26E, 4, 0);
    D_800D93F8 = buildFrameDistanceTable(0xB3, 4, 0);
    D_800D93FC = buildFrameDistanceTable(0x91, 1, 0);
    D_800D9400 = buildFrameDistanceTable(0x90, 1, 0);
    D_800D9404 = buildFrameDistanceTable(0x94, 4, 0);
    D_800D9408 = buildFrameDistanceTable(0xC0, 4, 0);
    D_800D940C = buildFrameDistanceTable(0x1CA, 7, 0);
    D_800D9410 = buildFrameDistanceTable(0x1CB, 7, 0);
}
