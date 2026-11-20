typedef struct { u8 pad[0x24]; volatile f32 f24; volatile f32 f28; volatile f32 f2C; u8 pad30[0x24]; f32 f54; } ObjBCA8;
typedef struct { u8 pad[8]; void (*f8)(void); void (*fC)(void); } VtBCA8;
typedef struct { u8 pad[0x10]; VtBCA8 *vt; } SysBCA8;
typedef struct { u8 pad[8]; u8 b8; } ResBCA8;
extern ObjBCA8 *volatile gPickupActor;
extern u8 D_801002AD;
extern s32 gTrackAxisTable;
extern SysBCA8 *gMenuState;
extern u8 D_8010A488[];
void func_8002ACB4(void *);
void func_80002EF0(ObjBCA8 *);
void func_8000628C(ObjBCA8 *, s32, s32, s32);
u16 func_80029C08(void *, s32, s32);
ResBCA8 *func_8002A980(void *);

void func_8001BCA8(void) {
    ObjBCA8 *volatile *pp;
    s32 *pq;
    SysBCA8 *sys;
    ObjBCA8 *o;
    ResBCA8 *r;
    u8 saved;
    u8 *ps;

    func_8002ACB4(D_8010A488);
    pp = &gPickupActor;
    o = *pp;
    if (o != NULL) {
        func_80002EF0(o);
        gPickupActor->f24 = 1.25f;
        gPickupActor->f28 = 0.15f;
        gPickupActor->f2C = -3.0f;
        gPickupActor->f54 = 1.05f;
        pq = &gTrackAxisTable;
        func_8000628C(*pp, *pq + 0x10, 1, 0x80);
        o = *pp;
        func_8000628C(o, *pq + 0x10, 0, 0x800);
        if (func_80029C08(D_8010A488, 0, 0)) {
            ps = &D_801002AD;
            saved = *ps;
            r = func_8002A980(D_8010A488);
            if (r != NULL) {
                saved = r->b8;
            }
            gMenuState->vt->fC();
            sys = gMenuState;
            *ps = saved;
            sys->vt->f8();
        }
    }
}

