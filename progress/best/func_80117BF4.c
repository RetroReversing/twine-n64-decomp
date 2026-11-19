typedef struct TabEnt { s16 id; s16 pad; s32 val; } TabEnt;
typedef struct Rec16 { s32 a; s16 b; s16 c; s32 d; s16 e; s16 f; } Rec16;
typedef struct Rec6 { s16 a; s16 b; s16 c; } Rec6;
typedef struct Ent { u8 pad0[0x10]; void *p10; struct Ent *arr[16]; s32 r54; } Ent;

void func_8000B9B8();
s32 func_8003D848(void *);
void *func_80083E90(s32, s32);
void func_80084048(void *, s32);
extern TabEnt func_8011EB60[];
extern Ent *D_8011F068;
extern s32 D_8011F06C;

void func_80117BF4(s16 arg0, s32 unused1, s32 unused2, s32 arg3) {
int __repair_literal;

    Rec16 rec;
    unsigned int a3v;
    s32 val;
    u8 *s1;
    Rec6 *s3;
    s16 n4;
    s32 n1;
    s32 i, j, k;
    Ent *ea, *eb;
    Ent *t2;
    Rec6 *r;
    s32 t0;

    a3v = arg3;
    D_8011F06C = 0;
    val = 0;
    if (func_8011EB60[0].id != -1) {
        a3v = -1;
        for (k = 0; ; k++) {
            if (func_8011EB60[k].id == arg0) {
                val = func_8011EB60[k].val;
                break;
            }
            if (func_8011EB60[k + 1].id == -1) {
                break;
            }
        }
    }
    func_8000B9B8(&rec, val + 0x54D910, 0x10, a3v);
    D_8011F068 = func_80083E90(0xB000, 0x34);
    s3 = func_80083E90(rec.e, 0x34);
    s1 = func_80083E90(rec.b, 0x34);
    func_8000B9B8(s3, rec.d + 0x54D910, rec.e);
    func_8000B9B8(s1, rec.a + 0x54D910, rec.b);
    n1 = (u32)rec.b / 12;
    n4 = (u32)rec.e / 6;
    if (0 < n1) {
        for (i = 0; i < n1; i++) {
            Ent *e = &D_8011F068[i];
            e->p10 = s1;
            for (j = 15; j >= 0; j--) {
                e->arr[j] = NULL;
            }
            s1 += 0xC;
            e->r54 = func_8003D848(e->p10);
            D_8011F06C += 1;
        }
    }
    t0 = 0;
__repair_literal = 0;

    if (n4 > __repair_literal) {
        t2 = D_8011F068;
        r = s3;
        do {
            ea = &t2[r->a];
            eb = &t2[r->b];
            for (i = 0; i < 16; i++) {
                if (ea->arr[i] == NULL) {
                    ea->arr[i] = eb;
                    break;
                }
            }
            for (i = 0; i < 16; i++) {
                if (eb->arr[i] == NULL) {
                    eb->arr[i] = ea;
                    break;
                }
            }
            r += 1;/*(u32)__repair_loop_weight*/do {do {do {
            t0++;} while (0);} while (0);} while (0);
        } while (n4 > t0);
    }
    func_80084048(s3, 0x34);
}
