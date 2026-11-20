/* Per-frame ground contact step: probes the floor under the object, lands or bounces it, and damps the bounce. */

f32 func_80045D2C(f32);
s32 func_8004C750(void *, f32 *, s32 *, s32 *, f32, f32 *, s32 *, s32);
s32 func_8004FF30(void *, f32 *, s32 *, f32, s32, s32, s32, void *);
s32 func_80085260(void *, u8);
extern f64 D_800D4198;
extern f64 D_800D41A0;
extern void *gPlayerActor;
extern void *D_80108F84;

void objUpdateGroundContact(void *obj) {
    union {
        unsigned char bytes[80];
        struct { f32 value; } view_sp20;
        struct { unsigned char pad[4]; f32 value; } view_sp24;
        struct { unsigned char pad[8]; f32 value; } view_sp28;
        struct { unsigned char pad[16]; s32 value; } view_sp30;
        struct { unsigned char pad[20]; f32 value; } view_sp34;
        struct { unsigned char pad[32]; s32 value; } view_sp40;
        struct { unsigned char pad[48]; f32 value; } view_sp50;
        struct { unsigned char pad[52]; f32 value; } view_sp54;
        struct { unsigned char pad[56]; f32 value; } view_sp58;
        struct { unsigned char pad[64]; s32 value; } view_sp60;
        struct { unsigned char pad[68]; s32 value; } view_sp64;
        struct { unsigned char pad[72]; s32 value; } view_sp68;
    } m2c_initial_frame;

    register f32 offset;
    register f32 temp_fs0_2;
    register f64 decayScale;
    register void *owner;
    register f32 temp_fs0;
    register u8 surfaceFlags;
    register f64 newVel;
    register f32 ownerFloor;
    register void *physics;
    register void *groundObj;

    groundObj = (*(void **)((char *)(obj) + 0x70));
    physics = (*(void **)((char *)(obj) + 0x6C));
    owner = (*(void **)((char *)(obj) + 0x20));
    if ((groundObj != NULL) && ((*(s32 *)((char *)(groundObj) + 0x38)) != 0)) {
        { f32 a = *(f32 *)((char *)obj + 0x64); f32 b = *(f32 *)((char *)obj + 0x54); offset = a * b; }
        { struct V { s32 x,y,z; }; *(struct V *)&m2c_initial_frame.view_sp20.value = *(struct V *)((char *)obj + 0x24); }
        if ((func_8004FF30((*(void **)((char *)(obj) + 0x20)), &m2c_initial_frame.view_sp20.value, &m2c_initial_frame.view_sp30.value, offset, 0, 0, 0, obj) << 0x18) != 0) {
            (*(f32 *)((char *)(obj) + 0x24)) = m2c_initial_frame.view_sp20.value;
            (*(f32 *)((char *)(obj) + 0x2C)) = m2c_initial_frame.view_sp28.value;
            if (m2c_initial_frame.view_sp24.value < (*(f32 *)((char *)(obj) + 0x28))) {
                (*(f32 *)((char *)(obj) + 0x28)) = m2c_initial_frame.view_sp24.value;
            }
        }
        { struct V { s32 x,y,z; }; *(struct V *)&m2c_initial_frame.view_sp20.value = *(struct V *)((char *)obj + 0x24); }
        ownerFloor = (*(f32 *)((char *)((*(void **)((char *)(owner) + 0x3C))) + 0x20));
        if (m2c_initial_frame.view_sp24.value < ownerFloor) {
            m2c_initial_frame.view_sp24.value = ownerFloor;
        }
        m2c_initial_frame.view_sp24.value += 0.2f;
        if ((func_8004C750((*(void **)((char *)(obj) + 0x20)), &m2c_initial_frame.view_sp20.value, &m2c_initial_frame.view_sp30.value, &m2c_initial_frame.view_sp40.value, 250.0f, &m2c_initial_frame.view_sp50.value, &m2c_initial_frame.view_sp60.value, 0) << 0x18) != 0) {
            (*(f32 *)((char *)(physics) + 0x1C)) = m2c_initial_frame.view_sp34.value;
        } else {
            m2c_initial_frame.view_sp50.value = 0.0f;
            m2c_initial_frame.view_sp54.value = 0.0f;
            m2c_initial_frame.view_sp58.value = 0.0f;
            m2c_initial_frame.view_sp60.value = 0;
            m2c_initial_frame.view_sp64.value = 0;
            m2c_initial_frame.view_sp68.value = 0;
        }
        surfaceFlags = 1;
        if (D_80108F84 != NULL) {
            surfaceFlags = (*(u8 *)((char *)((*(void **)((char *)(D_80108F84) + 0x3C))) + 0x47));
        }
        if (gPlayerActor != NULL) {
            surfaceFlags = (*(u8 *)((char *)((*(void **)((char *)(gPlayerActor) + 0x70))) + 0x47));
        }
        offset = -(*(f32 *)((char *)((*(void **)((char *)(obj) + 0x70))) + 0x20)) * (*(f32 *)((char *)(obj) + 0x54));
        if ((*(f32 *)((char *)(obj) + 0x28)) <= ((*(f32 *)((char *)(physics) + 0x1C)) + offset)) {
            (*(f32 *)((char *)(obj) + 0x24)) = (f32) ((*(f32 *)((char *)(obj) + 0x24)) + m2c_initial_frame.view_sp50.value);
            (*(f32 *)((char *)(obj) + 0x28)) = (f32) ((*(f32 *)((char *)(obj) + 0x28)) + m2c_initial_frame.view_sp54.value);
            (*(f32 *)((char *)(obj) + 0x2C)) = (f32) ((*(f32 *)((char *)(obj) + 0x2C)) + m2c_initial_frame.view_sp58.value);
            (*(f32 *)((char *)(obj) + 0x28)) = (f32) ((*(f32 *)((char *)(physics) + 0x1C)) + offset);
            if ((*(s16 *)((char *)(obj) + 0x7A)) < 2) {
                func_80085260(obj + 0x24, surfaceFlags);
                temp_fs0 = func_80045D2C((*(f32 *)((char *)(physics) + 0x10)));
                (*(f32 *)((char *)(physics) + 0xC)) = (f32) ((f64) (*(f32 *)((char *)(physics) + 0xC)) + ((f64) (temp_fs0 - func_80045D2C((*(f32 *)((char *)(physics) + 0x10)))) * (decayScale = D_800D4198)));
                temp_fs0_2 = func_80045D2C((*(f32 *)((char *)(physics) + 0x10)));
                newVel = (f64) (*(f32 *)((char *)(physics) + 0x14)) + ((f64) (temp_fs0_2 - func_80045D2C((*(f32 *)((char *)(physics) + 0x14)))) * decayScale);
                (*(f32 *)((char *)(physics) + 0x10)) = (f32) ((f64) (*(f32 *)((char *)(physics) + 0x10)) * D_800D41A0);
                (*(f32 *)((char *)(physics) + 0x14)) = (f32) newVel;
                (*(s16 *)((char *)(obj) + 0x7A)) = (s16) ((u16) (*(s16 *)((char *)(obj) + 0x7A)) + 1);
            } else {
                (*(f32 *)((char *)(physics) + 0x10)) = 0.0f;
            }
        }
        (*(s32 *)((char *)(obj) + 0x58)) = (s32) ((*(s32 *)((char *)(obj) + 0x58)) | 1);
    }
}
