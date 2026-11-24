typedef struct { u8 pad[0x78]; s16 type; u8 pad7a[2]; u16 id; } O750;
typedef struct { u8 pad[0x2C]; u16 id; } S750;
typedef struct { u8 b0; u8 flag; u8 pad[10]; } R750;
O750 *spawnEffectObject(s32, s32, s32);
extern R750 gTriggerTable[];
extern u8 sDifficultyLevel;

/* Spawns an effect object (type 0x6A) for a trigger and clears its table flag; on difficulty 1-2 only triggers 9 and 0xD spawn. */ O750 *spawnTriggerEffectObject(s32 param, s32 unused, S750 *trigger) {
    s32 difficulty = sDifficultyLevel;
    O750 *effect;

    if (difficulty == 0) goto make;
    if (difficulty < 0) goto make;
    if (difficulty >= 3) goto make;
    if (trigger->id == 9) goto make;
    if (trigger->id != 0xD) return NULL;
make:
    {
        effect = spawnEffectObject(0, param, 0);
        if (effect != NULL) {
            effect->type = 0x6A;
            {
                u16 id = trigger->id;
                effect->id = id;
                gTriggerTable[(s16)id].flag = 0;
            }
        }
        return effect;
    }
}
