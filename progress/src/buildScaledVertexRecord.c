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

typedef struct { short field_0; short field_2; short field_4; unsigned char pad_6[2]; int field_8; int field_C; } __repair_record_arg0;
/* Fills a vertex record: scaled position (x64 fixed point) from a Vec3 array, plus two words looked up from index tables. */ void buildScaledVertexRecord(void *vtx, s32 positions, s32 colorTable, s32 texCoordTable, s32 posIndex, s32 texIndex, s32 colorIndex, f32 scale) {
char *__repair_addr;

    void *pos;

    pos = positions + (posIndex * 0xC);
    ((__repair_record_arg0*)vtx)->field_0 = (s16) (s32) (M2C_FIELD(pos, f32 *, 0) * scale * 64.0f);
    ((__repair_record_arg0*)vtx)->field_2 = (s16) (s32) (M2C_FIELD(pos, f32 *, 4) * scale * 64.0f);
    ((__repair_record_arg0*)vtx)->field_4 = (s16) (s32) (M2C_FIELD(pos, f32 *, 8) * scale * 64.0f);
    ((__repair_record_arg0*)vtx)->field_8 = (s32) *(s32 *)((texIndex * 4) + texCoordTable);
__repair_addr = (char *)(colorTable + (colorIndex * 4));

    ((__repair_record_arg0*)vtx)->field_C = (s32) *(s32 *)(__repair_addr);
}
