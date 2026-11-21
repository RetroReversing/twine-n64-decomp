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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800068B4();
s32 func_80006E30();
void func_80006E78(void);
s32 func_80006FB4();
s32 func_80008258();
s32 initGameDataBanks();
s32 func_8000B828();
s32 initControllerAndSaveState();
s32 heapInit();
s32 heapAlloc(u32, u8);
s32 func_80083C8C();
s32 func_80086DA0();
u32 osGetMemSize();
void osCreateThread(void *, s32, void (*)(void *), void *, void *, s32);
s32 osStartThread();
s32 osViBlack();
s32 osViSetMode();
s32 osViSwapBuffer();
extern char D_14977A0[];
extern char D_14A8380[];
extern char D_14BA940[];
extern char D_14CD630[];
extern s32 D_80000300;
extern s32 sDataEntryBase;
extern char D_800CFF60[];
extern s32 gViFrameRateConst;
extern char D_800D8200[];
extern char D_800D93B0[];
extern s32 D_80100304;
extern s32 D_80100308;
extern s32 D_8010030C;
extern s8 D_80100964;
extern s16 gExpansionPakPresent;
extern u32 D_80108F7C;
extern s8 D_80108F95;
extern s32 D_80109A54;
extern s16 D_80109B9C;
extern char D_80109CC8[];
extern s32 D_80109CD8;
extern s32 D_80109CF0;
extern s32 D_80109CF4;
extern s32 D_80109CF8;
extern s32 D_80109D04;
extern s32 D_80109D08;
extern s32 D_80109D0C;
extern s32 D_8010A2BC;
extern s32 D_8010A2C0;
extern s32 D_8010A2C4;
extern s16 D_8010A518;
extern s16 gSaveDataPresent;
extern char D_8011FF40[];
extern void mainThreadEntry(void *);
extern char D_014A8380[], D_014BA940[];

typedef struct { s32 w[4]; } __repair_words4;
/* Boot init: starts the main thread, sets up the heap and VI mode, then runs the idle loop. */ void initSystem(void) {
    char *dst;
    s16 hasExpansionPak;
    s32 tvType;
    s32 viModeOffset;
    s32 viScale;
    s32 viIndex;
    u32 sizeB;
    u32 heapEnd;
    u32 sizeC;
    u32 sizeA;
    void *srcEnd;
    void *src;

    osCreateThread(D_800D8200, 3, &mainThreadEntry, 0, D_800D93B0, 0x7F);
    osStartThread(D_800D8200);
    hasExpansionPak = osGetMemSize() > 0x7FFFFFU;
    gExpansionPakPresent = hasExpansionPak;
    if (hasExpansionPak != 0) {
        heapInit(D_8011FF40, 0x80800000);
        D_80109A54 = heapAlloc(0x4B000U, 1);
        D_80100304 = heapAlloc(0x4B000U, 0);
        D_80100308 = heapAlloc(0x4B000U, 0);
        D_8010030C = heapAlloc(0x4B000U, 0);
        D_8010A2BC = heapAlloc(0x1CB8U, 1);
        D_8010A2C0 = heapAlloc(0x1CB8U, 1);
        D_8010A2C4 = heapAlloc(0x1CB8U, 1);
        D_8010A518 = 3;
        D_80109B9C = 2;
    } else {
        heapInit(D_8011FF40, 0x80400000);
        D_80109A54 = heapAlloc(0x25800U, 1);
        D_80100304 = heapAlloc(0x25800U, 0);
        D_80100308 = heapAlloc(0x25800U, 0);
        D_8010A2BC = heapAlloc(0x1CB8U, 1);
        D_8010A2C0 = heapAlloc(0x1CB8U, 1);
        D_8010A2C4 = heapAlloc(0x1CB8U, 1);
        D_8010A518 = 2;
        D_80109B9C = 0;
    }
    func_80008258();
    D_80108F7C = 1;
    sizeA = D_14A8380 - D_14977A0;
    sizeB = D_14BA940 - D_014A8380;
    sizeC = D_14CD630 - D_014BA940;
    if ((sizeB < sizeA) & (sizeC < sizeA)) {
        D_80108F7C = sizeA;
    }
    if ((sizeA < sizeB) & (sizeC < sizeB)) {
        D_80108F7C = sizeB;
    }
    if ((sizeA < sizeC) & (sizeB < sizeC)) {
        D_80108F7C = sizeC;
    }
    heapEnd = D_80108F7C + 0x80;
    D_80108F7C = heapEnd;
    sDataEntryBase = heapAlloc(heapEnd, 1);
    func_80006E30();
    func_8000B828(func_80083C8C());
    heapAlloc(initGameDataBanks() + 0x400, 1);
    tvType = D_80000300;
    gViFrameRateConst = 0x3BB;
    gSaveDataPresent = (u32) (tvType - 1) < 2U;
    if (tvType == 0) goto pal;
    viIndex = 0;
    if (tvType == 2) goto mpal;
    goto scale;
pal:
    viIndex = 0xE;
    goto scale;
mpal:
    viIndex = 0x1C;
scale:
    viScale = viIndex * 4;
    viModeOffset = (viScale + viIndex) * 0x10;
    osViSetMode(viModeOffset + D_800CFF60);
    osViBlack(1);
    dst = D_80109CC8;
    src = viModeOffset + (D_800CFF60 + 0x50);
    srcEnd = src + 0x50;
    D_80100964 = viIndex + 2;
    D_80108F95 = viIndex + 6;
    do {
        M2C_FIELD(dst, __repair_words4 *, 0x0) = *(__repair_words4 *) ((s8 *) src + 0x0);
        src += 0x10;
        dst += 0x10;
    } while (src != srcEnd);
    D_80109CD8 = 0x20C;
    D_80109CF4 = 0x800;
    D_80109D08 = 0x800;
    D_80109CF0 = 0x280;
    D_80109D04 = 0x500;
    D_80109CF8 = 0x2301FD;
    D_80109D0C = 0x2501FF;
    func_80006E78();
    osViSwapBuffer(D_80100304);
    func_80086DA0(1);
    initControllerAndSaveState();
    func_80006FB4();
loop_18:
    func_800068B4();
    goto loop_18;
}

