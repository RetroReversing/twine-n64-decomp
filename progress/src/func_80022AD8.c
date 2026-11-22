typedef struct {
    u8 pad[0x1e];
    s16 scale;
    u16 x, y, z;
    u8 pad26[2];
    u32 color:8; u32 mid:16; u32 kind:6; u32 low:2;
} Obj;
Obj *spawnTrackMarker(s32);
extern Obj *D_800B7CF4;
extern u16 D_800E0EE0, D_800E0EE2, D_800E0EE4, D_800E0EE6;
void func_80022AD8(s32 id) {
    Obj *obj;
    if (!D_800B7CF4) {
        D_800B7CF4 = spawnTrackMarker(id & 0xff);
        if (!D_800B7CF4) return;
    }
    obj = D_800B7CF4;
    obj->scale = 0x1000;
    obj->x = D_800E0EE0;
    obj->y = D_800E0EE2;
    obj->z = D_800E0EE4;
    obj->kind = 7;
    obj->color = D_800E0EE6;
}
