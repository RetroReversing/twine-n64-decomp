typedef struct { u8 pad[0x78]; s16 type; u8 pad7a[2]; u16 id; } O750;
typedef struct { u8 pad[0x2C]; u16 id; } S750;
typedef struct { u8 b0; u8 flag; u8 pad[10]; } R750;
O750 *spawnEffectObject(s32, s32, s32);
extern R750 D_800C7EE8[];
extern u8 sDifficultyLevel;

O750 *func_800750B0(s32 arg0, s32 arg1, S750 *s) {
    s32 mode = sDifficultyLevel;
    O750 *o;

    if (mode == 0) goto make;
    if (mode < 0) goto make;
    if (mode >= 3) goto make;
    if (s->id == 9) goto make;
    if (s->id != 0xD) return NULL;
make:
    {
        o = spawnEffectObject(0, arg0, 0);
        if (o != NULL) {
            o->type = 0x6A;
            {
                u16 id = s->id;
                o->id = id;
                D_800C7EE8[(s16)id].flag = 0;
            }
        }
        return o;
    }
}
