typedef struct PA { u8 pad0[0x24]; f32 a, b, c; u8 pad1[0x54-0x30]; f32 d; } PA;
typedef struct VT { u8 pad[8]; void (*f8)(void); void (*fC)(void); } VT;
typedef struct MI { u8 pad[0x10]; VT *vt; } MI;
extern s32 func_80002EF0(void *);
extern s32 func_8000628C(void *, s32, s32, s32);
extern s32 func_80029C08(void *, s32, s32);
extern void *func_8002A980(void *);
extern s32 func_8002ACB4(void *);
extern MI *gMenuItems;
extern PA *gPickupActor;
extern u8 gPickupSavedByte;
extern s32 gPickupSearchBox;
extern s32 gTrackMarkers;
void resetPickupActorState(void) {
    PA **p = &gPickupActor;
    u8 *sv;
    u8 var_s0;
    void *t;
    func_8002ACB4(&gPickupSearchBox);
    if (*p != NULL) {
        func_80002EF0(*p);
        gPickupActor->a = 1.25f;
        gPickupActor->b = 0.15f;
        gPickupActor->c = -3.0f;
        gPickupActor->d = 1.05f;
        func_8000628C(*p, gTrackMarkers + 0x10, 1, 0x80);
        func_8000628C(*p, gTrackMarkers + 0x10, 0, 0x800);
        if (func_80029C08(&gPickupSearchBox, 0, 0) & 0xFFFF) {
            sv = &gPickupSavedByte;
            var_s0 = *sv;
            t = func_8002A980(&gPickupSearchBox);
            if (t != NULL) var_s0 = ((u8 *)t)[8];
            gMenuItems->vt->fC();
            *sv = var_s0;
            gMenuItems->vt->f8();
        }
    }
}
