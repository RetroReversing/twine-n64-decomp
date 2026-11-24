typedef struct Inner { char pad[0x30]; float result; char pad2[0x2c]; float *values; char pad3[0x30]; s16 index; } Inner;
typedef struct Outer { char pad[0x68]; Inner *inner; } Outer;
/* Stores table[slot + 1] into state->result, or 0.0 when slot is 0. */ void storeIndexedValueResult(Outer *owner) {
 Inner *state = owner->inner;
 s16 slot = state->index;
 float *table = state->values;
 float result;
 if (slot == 0) result = 0.0f;
 else result = table[slot + 1];
 owner->inner->result = result;
}
