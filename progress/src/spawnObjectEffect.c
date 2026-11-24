static inline u32 negate_word(u32 value) {
    return 0u - value;
}
extern s32 spawnKindActor(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
typedef struct { char pad[0x68]; char *object; char tail[0x68]; } ObjectSlot;
extern ObjectSlot *gCutscene;
/* Spawns an effect at the given object's position, passing the object's type byte and a flag set when that type is 0x33. */ void spawnObjectEffect(s32 objectIndex, s32 param1, s32 param2, s32 param3) {
    char *objPtr;
    u32 kind;
    ObjectSlot *records = gCutscene;
    ObjectSlot *record = records + objectIndex;
    objPtr = record->object;
    kind = *(u8 *)(*(char * volatile *)(objPtr + 0x68) + 0xB1);
    spawnKindActor(objPtr + 0x24, objPtr + 0x3C, 0, 0, 0, 0x64, 0x64, 0x64, param1, 0,
        *(u8 *)(*(char * volatile *)(objPtr + 0x68) + 0xB1), param2, negate_word((kind ^ 0x33u) < 1u) & 3u, 0, param3, 0);
}
