s32 func_80076168(s32);
s32 func_8011A2A0();
s32 func_8011C580();
s32 func_8011C674(s32);
s32 func_8011C890();
s32 func_8011CAE4();
s32 func_8011CEA0();
s32 func_8011DC18();
s32 func_8011E894();
extern u8 D_801002A0;
extern u8 D_801002AC;
extern u8 D_801002AE;
extern s32 D_801002B4;
extern s32 D_801002C0;
extern s32 D_80102ED8;
extern u8 D_8010A4FD;
extern s16 D_8011F0EC;
extern s16 D_8011F0EE;
extern s32 D_8011F3A8;

void func_8011E634(void) {
    s32 s1;
    s32 i;
    u8 *p;
    s32 t;

    D_8011F0EE = 0x78;
    if (D_801002C0 >= 3) {
        D_8011F0EC = 0xA0;
    } else if (D_8010A4FD == 1) {
        D_8011F0EC = 0xA0;
        D_8011F0EE = 0xF0;
    } else {
        D_8011F0EC = 0x140;
    }
    if (*(u8 *)&D_801002AE == 0) {
        func_8011C674(-1);
        if (*(u8 *)&D_801002AE == 0) {
            func_8011C580();
        }
    }
    t = D_801002A0;
    if (t < 6) {
        if (t >= 4) {
            func_8011C890();
            t = D_801002A0;
        }
    }
    if (t >= 2) {
        if (t < 4) {
            func_8011CEA0();
        } else if (t == 6) {
            func_8011CAE4();
        }
    }
    func_8011DC18();
    if ((D_80102ED8 != 0 && D_801002AC != 0) || (func_8011A2A0() & 0xFFFF)) {
        s1 = D_8011F3A8 - 1;
        D_8011F3A8 = s1;
        if (s1 <= 0) {
            if (s1 == 0) {
                func_8011E894();
                i = 0;
                if (s1 < D_801002B4) {
                    p = (u8 *)&D_801002B4 - 6;
                    do {
                        *p = 1;
                        func_80076168(i & 0xFF);
                        i++;
                    } while ((i & 0xFFFF) < D_801002B4);
                }
            } else {
                D_8011F3A8 = -1;
            }
        }
    }
}
