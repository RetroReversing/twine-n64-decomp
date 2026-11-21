typedef struct { u8 pad[8]; u8 b8; } SearchRes;
typedef struct { u8 p0[8]; void (*f8)(void); void (*fC)(void); } MenuVt;
typedef struct { u8 p0[0x10]; MenuVt *vt; } MenuItems;
typedef struct { u8 p0[0x24]; f32 f24, f28, f2C; u8 p30[0x24]; f32 f54; } PickupActor;
extern void func_80002EF0(void *);
extern void func_8000628C(void *, s32, s32, s32);
extern s32 func_80029C08(void *, s32, s32);
extern SearchRes *func_8002A980(void *);
extern void func_8002ACB4(void *);
extern MenuItems *gMenuItems;
extern PickupActor *gPickupActor;
extern u8 gPickupSavedByte;
extern u8 gPickupSearchBox[];
extern s32 gTrackMarkers;

void resetPickupActorState(void) {
    u8 v;
    SearchRes *r;
    func_8002ACB4(gPickupSearchBox);
    if (gPickupActor != 0) {
        func_80002EF0(gPickupActor);
        gPickupActor->f24 = 1.25f;
        gPickupActor->f28 = 0.15f;
        gPickupActor->f2C = -3.0f;
        gPickupActor->f54 = 1.05f;
        func_8000628C(gPickupActor, gTrackMarkers + 0x10, 1, 0x80);
        func_8000628C(gPickupActor, gTrackMarkers + 0x10, 0, 0x800);
        if (func_80029C08(gPickupSearchBox, 0, 0) & 0xFFFF) {
            v = gPickupSavedByte;
            r = func_8002A980(gPickupSearchBox);
            if (r != 0) v = r->b8;
            gMenuItems->vt->fC();
            gPickupSavedByte = v;
            gMenuItems->vt->f8();
        }
    }
}
