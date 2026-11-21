extern u16 D_8010A91A, D_80108F72, D_80100786, D_80102F2A, D_80113020, D_80107E98;
extern u8 sDifficultyLevel;
extern f32 D_80117408;
void func_800778E0(void) {
    f32 f;
    u16 t = D_8010A91A;
    D_80108F72 = 0;
    D_80100786 = 0;
    D_80102F2A = 0;
    D_8010A91A = 0;
    D_80113020 = 0;
    D_80107E98 = t;
    switch (sDifficultyLevel) {
    case 0:
    default:
        f = 240.0f;
        break;
    case 1:
        f = 120.0f;
        break;
    case 2:
        f = 120.0f;
        break;
    }
    D_80117408 = f;
}
