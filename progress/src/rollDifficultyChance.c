u32 randomIntBelow(s32);
extern u8 sDifficultyLevel;

/* Picks a percent chance by difficulty level (0 easy, 1 normal, 2 hard) and rolls it; all-zero means always succeed. */ s32 rollDifficultyChance(u32 easyChance, u32 normalChance, u32 hardChance) {
    u32 chance;
    s32 success;

    switch (sDifficultyLevel) {
    case 2:
        chance = hardChance;
        break;
    case 0:
    default:
        chance = easyChance;
        break;
    case 1:
        chance = normalChance;
        break;
    }
    if (easyChance == 0 && normalChance == 0 && hardChance == 0) {
        chance = 100;
    }
    if (chance == 100) {
        success = 1;
    } else if (chance == 0) {
        success = 0;
    } else {
        success = randomIntBelow(100) < chance;
    }
    return success;
}
