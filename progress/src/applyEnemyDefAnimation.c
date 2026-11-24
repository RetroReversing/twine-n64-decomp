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

s32 func_8000237C();
s32 clearProbeState();
s32 func_80064318();
s32 func_800643D8();
s32 func_80067A24();
extern char sEnemyDefTable[];

/* Starts the animation named by the enemy's definition entry, or resets the animation if the entry has none. */ void applyEnemyDefAnimation(void *enemy) {
    s32 stateByte;
    u16 clearArg;
    u8 animId;
    void *enemyDef;
    void *anim;
    void *enemyState;

    enemyState = M2C_FIELD(enemy, void **, 0x6C);
    anim = M2C_FIELD(enemyState, void **, 0xA8);
    enemyDef = (M2C_FIELD(M2C_FIELD(enemy, void **, 0x68), s8 *, 0xE) * 0xE8) + sEnemyDefTable;
    animId = M2C_FIELD(enemyDef, u8 *, 0x9E);
    stateByte = M2C_FIELD(enemyState, s8 *, 0x182);
    if (animId != 0xFF) {
        func_8000237C(anim, animId, 2, 0);
        clearArg = M2C_FIELD(enemyDef, u16 *, 0x92);
        if (clearArg != 0) {
            clearProbeState(anim, clearArg);
        } else {
            M2C_FIELD(M2C_FIELD(enemyState, void **, 0xA8), s16 *, 0x7A) = 5;
            func_80067A24(anim, M2C_FIELD(enemyDef, u16 *, 0x94));
        }
        func_80064318(anim, stateByte);
        return;
    }
    func_800643D8(anim);
}
