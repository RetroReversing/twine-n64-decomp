typedef struct { u8 pad[0x10]; u8 kind; } K11;
typedef struct { u8 pad[0xB4]; K11 *k; } B11;
typedef struct { u8 pad[0x6C]; B11 *b; } A11;
void func_8011AE4C(A11 *, B11 *, s32);
extern s32 D_801002B4;
extern A11 *gBonusSceneHandle[];

void func_8011AA04(void) {
    u16 i;

    for (i = 0; i < D_801002B4; i++) {
        A11 *a = gBonusSceneHandle[i];
        if (a != NULL) {
            B11 *b = a->b;
            if (b != NULL) {
                K11 *k = b->k;
                if (k != NULL && k->kind == 7) {
                    func_8011AE4C(a, b, 0);
                    return;
                }
            }
        }
    }
}
