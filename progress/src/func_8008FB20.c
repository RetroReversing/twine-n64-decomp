s32 func_8008D49C(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80091A24(void *, s32, s32);
s32 voiceStoreParam(s32, u8, u8, s32);
extern u8 D_800EDA87;
extern u8 D_800EDA88;
typedef struct { s32 w[2]; } Pair;
typedef struct { u16 hi; u8 mid; u8 lo; u8 pad[4]; } TabEnt;
typedef struct SndNode {
    struct SndNode *next;
    struct SndNode *prev;
    s32 id;
    u32 time;
    Pair pos;
} SndNode;
typedef struct {
    Pair pos;
    u32 time;
    u8 *ptr;
    u8 pad[0x14];
    u8 chan;
    s8 sA;
    s8 sB;
    u8 key;
} Ent;
typedef struct { u8 pad[0x568]; Ent e; } EV;
typedef struct {
    u8 pad0[4];
    TabEnt *tab;
    u8 map[0x80];
    TabEnt *tab2;
    u8 map2[0x84];
    u32 mask[4];
    u32 now;
    u8 pad124[0x404];
    u8 ctab[0x40];
    Ent ents[64];
    u8 pad_f68[0x10];
    SndNode *head;
    u32 padF7C;
    s32 patch[10];
    u8 padFA8[0x20];
    u8 padFC8[0x28];
    s32 fF0;
    u8 fF4;
} SeqPlayer;
extern SeqPlayer *gSeqPlayer;
extern SndNode *gFreeSndNodeList;

s32 func_8008FB20(void)
{
    s32 any = 0;
    s32 i;
    s32 off;
    s32 k;
    SeqPlayer *p;
    EV *e;
    EV *e2;
    u32 t;
    for (i = 0; i < 64; i++) {
        off = i * 0x28;
        p = gSeqPlayer;
        if (((EV *)((char *)p + off))->e.ptr != 0) {
            any = 1;
            k = off;
            for (;;) {
                e = (EV *)((char *)p + off);
                t = *(u16 *)e->e.ptr + e->e.time;
                if (e->e.pos.w[1] + p->now >= t) {
                    s32 a, b, adv;
                    u8 chan;
                    e->e.time = t;
                    a = e->e.ptr[2];
                    chan = e->e.chan;
                    b = e->e.ptr[3];
                    if ((a == 0xFF) & (b == 0xFF)) {
                        e->e.ptr = 0;
                    } else {
                        adv = 4;
                        if ((((u32)a >> 7) & 1) & (b == 0)) {
                            u16 idx = a & 0x7F; u8 idu = idx;
                            if (chan != 9) {
                                u8 m; do { do { m = p->map[idu]; } while (0); } while (0);
                                if (m != 0xFF) {
                                    p->patch[chan] = (p->tab[m].hi << 16) | (p->tab[m].mid << 8) | p->tab[m].lo;
                                }
                            } else {
                                u8 m = p->map2[idx];
                                if (m != 0xFF) {
                                    p->patch[9] = (p->tab2[m].hi << 16) | (p->tab2[m].mid << 8) | p->tab2[m].lo;
                                }
                            }
                        } else if ((((u32)a >> 7) & 1) & (b == 1)) {
                            voiceStoreParam(0x82, chan, D_800EDA87, a & 0x7F);
                        } else if ((a & 0x80) && (b & 0x80)) {
                            s32 cmd = b & 0x7F;
                            if (cmd == 0x68) {
                                if (p->fF4 != 0) {
                                    func_80091A24((char *)p + 0xFC8, p->fF0, 1);
                                    gSeqPlayer->fF4 = 0;
                                }
                            } else {
                                voiceStoreParam(cmd, chan, D_800EDA87, a & 0x7F);
                            }
                        } else if ((a != 0) | (b != 0)) {
                            s32 key;
                            s32 pv;
                            SndNode *n;
                            e2 = (EV *)((char *)gSeqPlayer + k);
                            adv = 6;
                            key = e2->e.key;
                            if (gSeqPlayer->mask[key / 32] & (1 << (key & 31))) {
                                pv = gSeqPlayer->patch[chan];
                                if (pv != -1) {
                                                                        s32 id;
                                    SndNode *m;
                                    a = a + e2->e.sB;
                                    a = (a < 0x80) ? (a & ((~a) >> 31)) : 0x7F;
                                    b = b + ((EV *)((char *)gSeqPlayer + k))->e.sA;
                                    b = (b < 0x80) ? (b & ((~b) >> 31)) : 0x7F;
                                    n = gFreeSndNodeList;
                                    if (n) {
                                        SndNode *nx = n->next;
                                        SndNode *h;
                                        gFreeSndNodeList = nx;
                                        if (nx) nx->prev = 0;
                                        n->prev = 0;
                                        h = gSeqPlayer->head;
                                        n->next = h;
                                        if (h) gSeqPlayer->head->prev = n;
                                        gSeqPlayer->head = n;
                                    }
                                    m = n;
                                    if (m) {
                                        pv = func_8008D49C(pv, a & 0xFF, b & 0xFF, 0x40, chan, D_800EDA87, 0, key, gSeqPlayer->ctab[key], D_800EDA88 ? -1 : 0);
                                        if (pv != -1) {
                                            m->id = pv;
                                            { EV *q = (EV *)((char *)gSeqPlayer + k);
                                            m->time = t + *(u16 *)(q->e.ptr + 4);
                                            m->pos = *(Pair *)&q->e.pos; }
                                        } else {
                                            if (m->next) m->next->prev = m->prev;
                                            if (m->prev) m->prev->next = m->next;
                                            else gSeqPlayer->head = m->next;
                                            m->next = gFreeSndNodeList;
                                            if (gFreeSndNodeList) gFreeSndNodeList->prev = m;
                                            m->prev = 0;
                                            gFreeSndNodeList = m;
                                        }
                                    }
                                }
                            }
                        }
                        ((EV *)((char *)gSeqPlayer + k))->e.ptr += adv;
                    }
                    p = gSeqPlayer;
                    if (((EV *)((char *)p + off))->e.ptr != 0) continue;
                }
                break;
            }
        }
    }
    return any;
}
