typedef struct { u16 flags; u8 pad[0xE6]; } Ent;
typedef struct { u8 pad[0xE]; s8 kind; s8 mode; } Sub;
typedef struct { u8 pad[0x7A]; s16 t; } Tgt;
typedef struct { u8 pad[0xA8]; Tgt *tgt; } Own;
typedef struct { u8 pad[0x68]; Sub *sub; Own *own; } Obj;
void func_80070CA4();
extern Ent sEnemyDefTable[];
extern s32 gBorderSkipActive;

void func_80067294(Obj *o, s32 arg1) {
    Own *own = o->own;
    s32 mode;

    mode = 0x18;
    if (gBorderSkipActive != 0) {
        mode = 0x21;
    }
    switch (o->sub->kind) {
    case 4: case 5: case 18: case 19: case 28: case 29: case 30: case 31: case 32:
        o->sub->mode = mode;
        func_80070CA4(o, arg1, mode);
        break;
    case 1: case 2: case 3: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
    case 13: case 14: case 15: case 16: case 17: case 20: case 21: case 22: case 23:
    case 24: case 25: case 26: case 27:
        while (!(sEnemyDefTable[o->sub->kind].flags & 0x8000)) {
            o->sub->kind--;
        }
        o->sub->mode = mode;
        func_80070CA4(o);
        own->tgt->t = 10;
        break;
    case 0: case 33: case 34: case 35: case 36: case 37: case 38:
        break;
    }
}
