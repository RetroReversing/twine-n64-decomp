s32 func_80002BD0();
s32 randomIntBelow();
s32 func_80077960();
s32 func_80077ED8();
extern char sEnemyDefTable[];
extern u16 D_800C9BD0[];
extern u16 D_800C9BE0[];
extern u16 D_800C9BE4[];
extern u16 D_800C9BF0[];
extern u16 D_800C9BF4[];

/* Enemy state handler: plays a random sound cue for the enemy's current state and returns 1 if it handled the state, 0 otherwise */
s32 enemyStateSound(void *actor) {
    u16 *cueTable;
    s32 cueCount;
    u8 *enemyDef;
    u8 *enemyData;
    s32 variant;

    enemyData = *(u8 **)((u8 *)actor + 0x6C);
    enemyDef = (u8 *)sEnemyDefTable + *(s8 *)(*(u8 **)((u8 *)actor + 0x68) + 0xE) * 0xE8;
    switch (*(s16 *)((u8 *)actor + 0x7C)) {
    case 0:
    case 3:
        if (*(s32 *)(enemyData + 0x88) & 0x40000000) {
            switch (enemyDef[0x6E]) {
            case 0:
                func_80002BD0(actor, D_800C9BE0[randomIntBelow(1)]);
                func_80077960(actor, 0x81);
                return 1;
            case 1:
                func_80002BD0(actor, D_800C9BF0[randomIntBelow(1)]);
                func_80077960(actor, 0x81);
                return 1;
            case 2:
                func_80002BD0(actor, D_800C9BF4[randomIntBelow(5)]);
                func_80077960(actor, 0x81);
                return 1;
            default:
                func_80002BD0(actor, 0x129);
                func_80077960(actor, 4);
                return 1;
            }
        }
        func_80077ED8(actor);
        return 1;
    case 1:
        if (*(s32 *)((u8 *)actor + 0x58) & 4) {
            switch (enemyDef[0x6E]) {
            case 0:
                func_80002BD0(actor, D_800C9BE0[randomIntBelow(1)]);
                func_80077960(actor, 4);
                return 1;
            case 1:
                return 0;
            case 2:
                variant = enemyData[0x81];
                if (variant == 0 || (u8)variant != 1) {
                    cueTable = D_800C9BD0;
                    cueCount = 8;
                } else {
                    cueTable = D_800C9BE4;
                    cueCount = 5;
                }
                func_80002BD0(actor, cueTable[randomIntBelow(cueCount)]);
                func_80077960(actor, 4);
                return 1;
            default:
                return 0;
            }
        }
        return 0;
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    default:
        return 0;
    }
}
