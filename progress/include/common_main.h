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
    u8 pad14[0x28];
    TwineProbeBounds *bounds;
    u8 pad40[0xC];
    f32 distance;
    u8 pad50[8];
    u16 type;
} TwineProbeObject;

s32 create_centered_sprite(s32 assetId, s32 frameIndex);

void spherical_to_cartesian(f32 *out, f32 radius, f32 yaw, f32 pitch);

s32 func_80094B48(void *object, f32 sortKey, f32 value0, f32 value1, f32 value2, f32 value3);

void func_80027FF4(void);

void func_80087A80(void);

void func_8008C3D8(s32 index, u16 *data);
