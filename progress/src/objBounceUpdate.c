typedef struct {
    u8 pad0[0xC];
    f32 velX;
    f32 velY;
    f32 velZ;
    s32 timer;
    u8 pad1C[0xA];
    u16 hitFlags;
    u16 soundId;
    u8 pad2A[3];
    u8 bounceEnabled;
    u8 active;
    u8 soundPending;
    s16 bounceCount;
} SubEBF4;

typedef struct {
    u8 pad0[0x24];
    f32 posX;
    f32 posY;
    f32 posZ;
    u8 pad30[0xC];
    f32 squashX;
    f32 squashZ;
    u8 pad44[0x1C];
    s32 flags;
    u8 pad64[8];
    SubEBF4 *sub;
    u8 pad70[0xA];
    s16 state;
    u8 pad7C[2];
    s8 hideTimer;
    u8 pad7F[3];
    u8 expireTimer;
} ObjEBF4;

s32 angleDelta12(s32, s32);
s32 addRandomJitterVec3(void *, f32, f32);
s8 checkBonusObjectPickup(void *);
s32 objUpdateGroundContact(void *);
s32 playRandomBounceSoundAtNearestMarker(void *);
extern u8 gSceneType;
extern u8 gBonusMarkerActive;
extern s32 gBorderSkipActive;

/* Per-frame update for a bouncing object: decays squash and recoil, runs the bounce/fall state logic, and counts down the timers that flag the object for removal. */
void objBounceUpdate(ObjEBF4 *obj) {
    SubEBF4 *sub = obj->sub;

    if (sub->active != 0) {
        obj->squashX -= angleDelta12(0x400, (s32)obj->squashX) * 0.1f;
        obj->squashZ -= angleDelta12(0, (s32)obj->squashZ) * 0.1f;
        if (obj->flags & 2) {
            obj->flags &= ~2;
            addRandomJitterVec3(&obj->squashX, 512.0f, 256.0f);
            addRandomJitterVec3(&sub->velX, 0.4f, 0.2f);
            sub->velY = 2.0f;
            playRandomBounceSoundAtNearestMarker(&obj->posX);
            obj->state = 0;
        }
    }
    switch (obj->state) {
    case 0:
    case 1:
        sub->velY -= 0.32666668f;
        obj->posY += sub->velY * 0.033333335f;
        obj->posX += sub->velX;
        obj->posZ += sub->velZ;
        sub->velX *= 0.75f;
        sub->velZ *= 0.75f;
        objUpdateGroundContact(obj);
        break;
    case 2:
        if (sub->soundPending == 0 && (obj->flags & 0x01000000)) {
            obj->flags &= ~0x01000000;
            sub->velY -= 0.32666668f;
            obj->posY += sub->velY * 0.033333335f;
            objUpdateGroundContact(obj);
        }
        break;
    }
    if (checkBonusObjectPickup(obj) != 0) {
        if (sub->bounceEnabled == 0) {
            obj->flags |= 1;
        } else {
            sub->bounceCount = 0;
        }
    }
    if (sub->active != 0 && (sub->hitFlags == 0 || gBorderSkipActive != 0)) {
        if (sub->timer > 0) {
            if (--sub->timer == 0) {
                obj->hideTimer = 0x10;
                obj->expireTimer = 0xFF;
            }
        } else if (obj->expireTimer != 0) {
            obj->expireTimer--;
        } else {
            if (gSceneType == 8) {
                switch (sub->soundId) {
                case 25:
                    gBonusMarkerActive &= 0xFB;
                    break;
                case 24:
                    gBonusMarkerActive &= 0xFD;
                    break;
                case 23:
                    gBonusMarkerActive &= 0xFE;
                    break;
                }
            }
            obj->flags |= 1;
        }
    }
}
