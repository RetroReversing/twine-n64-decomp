/* context.h for TWINE: shared by every function. Agents grow it with edit_context:
 * add a prototype or struct the moment you work one out, so the next function benefits. */

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile s32 vs32;
typedef int s32_bool;

#define NULL ((void *)0)
#define TRUE 1
#define FALSE 0
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

/* Observed in the exact-matched slot update at 0x8011B460. */
typedef struct { u8 pad0[0x10]; u8 flags; } TwineSlotEventState;
typedef struct {
    u8 pad0[0xB4];
    TwineSlotEventState *event;
    u8 padB8[0xCA];
    s8 index;
} TwineSlotEventActor;

/* Field offsets verified in func_800969B4. */
typedef struct {
    s8 active;
    u8 pad;
    u8 code;
    u8 bank;
    u16 volume;
    u8 rest[12];
} TwineAudioChannel;

typedef struct {
    u8 pad[0xC2];
    TwineAudioChannel channel[10];
} TwineAudioChannelBank;

/* Fields used by the type-0x46 object query at 0x8003D848. */
typedef struct { f32 x, y, z; } TwineProbeVector;
typedef struct {
    u8 pad0[0x18];
    f32 minX, maxX, minY, maxY, minZ, maxZ;
} TwineProbeBounds;
typedef struct TwineProbeObject {
    u8 pad0[0x10];
    struct TwineProbeObject *next;
    struct TwineProbeObject *attachedNext;
    struct TwineProbeObject *attachedTo;
    u8 pad1C[4];
    u8 *hostData;
    u8 pad24[4];
    f32 groundY;
    u8 pad2C[0x10];
    TwineProbeBounds *bounds;
    f32 center[3];
    f32 distance;
    u8 pad50[8];
    u16 type;
} TwineProbeObject;

s32 create_centered_sprite(s32 assetId, s32 frameIndex);

void spherical_to_cartesian(f32 *out, f32 radius, f32 yaw, f32 pitch);

s32 soundQueueInsert(void *object, f32 sortKey, f32 value0, f32 value1, f32 value2, f32 value3);

void updateMenuState(void);

void func_80087A80(void);

void func_8008C3D8(s32 index, u16 *data);

void func_800081C4(s32 fill);

f32 randomFloatScaled(f32 scale);
f32 randomFloatMinusOffset(f32 scale, f32 offset);

s32 func_800819EC(s32 bank, s32 index);
s32 func_80096E7C(void *arg0, s32 arg1);

extern char D_800D2D44[];

typedef s32 (*TwineDisplayUpdateCallback)(u32, u32, u32, u32, void *);

void mat3_mul(const f32 a[3][3], const f32 b[3][3], f32 out[3][3]);

void func_80085160(f32 *);

s32 func_80047998(void *, void *, void *, void *, void *, void *, f32, f32);

extern f64 D_800D66C0;
extern f32 D_800CEE98[6];
extern s32 D_800CEE50[18];

/* Bounds face rejection for a segment, with a separate Y margin. */
s32 segmentPassesBoundsRejection(void *bounds, void *start, void *end, f32 yMargin);

void cameraUpdateProjection(void *arg0, f32 arg1);

/* Sprite rectangle setup; verified from exact-matched func_8004844C. */
void func_8004844C(void *sprite, f32 x, f32 y, f32 width, f32 height, f32 scaleX, f32 scaleY);

extern void *jtbl_8011EF48[11];

/* RSP task message posted to the SP event queue: type 1 = start task, 2 = yield, 0x81 = RSP done. */
typedef struct {
    u8 type;
    u8 pad[3];
    s32 task;
} RspMsg;

extern void *jtbl_8011EF48[11];

/* Probe actor layout. */
typedef struct ProbeActor {
    u8 pad0[0x24];
    f32 pos[3];
    f32 pos2[3];
    u8 pad1[0x58 - 0x3C];
    s32 flags;
    u8 pad2[0x7B - 0x5C];
    u8 probeIndex;
} ProbeActor;

/* Double-buffered table of eight fixed-point samples per slot; idx selects the slot being written. */
typedef struct {
    u8 pad0[0x168];
    s16 slot[2][8];
    s16 slotIndex;
} TwineSampleRing;

/* Converts a sample to a 16-bit fixed-point value: offset by origin, scaled by 1024, multiplied by scale, biased, shifted by 15, then stored as a halfword count. */
#define SAMPLE_TO_FIXED(sample, origin, scale, bias) (((((sample) - (origin)) << 10) * (scale) + (bias)) >> 15) * 2

/* Track marker object (updateTrackMarkerTrigger): pos at 0x24, trigger data pointer at 0x6C, mode at 0x78. */
typedef struct TrackMarkerTrigger {
    f32 scale;        /* 0x00 */
    s16 timer;        /* 0x04 */
    u16 sfxId;        /* 0x06 */
    u8 trackIndex;    /* 0x08 index into gTrackMarkerDone */
    u8 expectedState; /* 0x09 */
    u8 soundParam;    /* 0x0A */
    u8 doneFlagIndex; /* 0x0B */
    u8 notifyFlag;    /* 0x0C */
    u8 useAltSpawn;   /* 0x0D */
} TrackMarkerTrigger;

typedef struct TrackMarker {
    u8 pad0[0x24];
    f32 pos[3];       /* 0x24 */
    u8 pad1[0x60 - 0x30];
    s32 flags;        /* 0x60 */
    u8 pad2[0x6C - 0x64];
    TrackMarkerTrigger *trigger; /* 0x6C */
    u8 pad3[0x78 - 0x70];
    u16 mode;         /* 0x78 */
} TrackMarker;
