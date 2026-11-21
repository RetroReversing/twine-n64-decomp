typedef struct { f32 x,y,z; } TwineV3;
typedef struct {
    f32 *stream;
    u8 pad04[0x1C];
    TwineV3 vector20, vector2C, vector38, vector44;
    u8 pad50[0x18];
    void *linked;
    u8 pad6C[0x14];
    s16 state, parameter;
    u8 pad84[0x50];
} StreamRecord;
extern StreamRecord *gObjectTable;
#define READ_VECTOR(field) do { \
    StreamRecord *records = gObjectTable; \
    v.x = *records->stream++; \
    v.y = *records->stream++; \
    v.z = -*records->stream++; \
    records = (StreamRecord *)((u8 *)records + index * 0xD4); \
    records->field = v; \
} while (0)
void func_8000D3AC(s32 index, u32 parameter) {
    StreamRecord *base = gObjectTable;
    StreamRecord *obj = (StreamRecord *)((s32)base + index * 0xD4);
    void *linked = obj->linked;
    TwineV3 v;
    obj->state = 0;
    obj->parameter = (s16)(parameter >> 8);
    if (linked != NULL) {
        *(TwineV3 *)((u8 *)linked + 0x24) = obj->vector2C;
    }
    READ_VECTOR(vector38);
    READ_VECTOR(vector20);
    READ_VECTOR(vector2C);
    READ_VECTOR(vector44);
}
