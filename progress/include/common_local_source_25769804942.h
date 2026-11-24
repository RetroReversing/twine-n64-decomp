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

typedef struct EntityState {
    /* 0x000 */ u8 pad0[0x8C];
    /* 0x08C */ f32 scale;
    /* 0x090 */ u8 pad90[0x11C - 0x90];
    /* 0x11C */ s32 unk11C;
    /* 0x120 */ s32 unk120;
    /* 0x124 */ s32 unk124;
    /* 0x128 */ u8 pad128[0x195 - 0x128];
    /* 0x195 */ s8 unk195;
} EntityState;

typedef struct Entity {
    /* 0x00 */ u8 pad0[0x6C];
    /* 0x6C */ EntityState *state;
} Entity;
