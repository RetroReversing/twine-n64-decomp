s32 buildTriangleGridMasks();
s32 computeMeshBounds();
s32 computeVertexBounds();
s32 func_800328B8();
s32 func_800336FC(s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32);
void *func_8003C860();
s32 func_8003C94C();
s32 func_8003FCF4();
s32 func_8003FDE0();
s32 buildCollisionPlanesFromCommands();
s32 func_800404F0();
s32 func_800410E8();
s32 func_80041114();
s32 func_80045278();
s32 func_80045290();
s32 heapAllocTagged();
s32 vec3Add();

typedef struct { s32 w[4]; } SlotBounds;

typedef struct {
    f32 x, y, z;
} SpawnVec3;

typedef struct {
    /* 0x00 */ s32 dl;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ SlotBounds bounds;
    /* 0x18 */ s32 sphere[6];
    /* 0x30 */ u32 packed;
    /* 0x34 */ SpawnVec3 *verts;
    /* 0x38 */ s32 planes;
    /* 0x3C */ s32 tris;
    /* 0x40 */ u16 len;
    /* 0x42 */ u16 count;
    /* 0x44 */ u8 unk44;
    /* 0x45 */ u8 loaded;
    /* 0x46 */ u8 flags46;
    /* 0x47 */ u8 unk47;
    /* 0x48 */ u8 flags48;
    /* 0x49 */ u8 pad49[3];
} AssetSlotEntry;

typedef struct {
    /* 0x00 */ SpawnVec3 *verts;
    /* 0x04 */ u16 count;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 commands;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u8 type;
} SpawnModel;

typedef struct {
    /* 0x00 */ u16 id;
    /* 0x04 */ s32 unk04[2];
    /* 0x0C */ SpawnVec3 pos;
    /* 0x18 */ SpawnVec3 rot;
    /* 0x24 */ SpawnModel *model;
    /* 0x28 */ s16 *slotIndex;
    /* 0x2C */ s32 unk2C[3];
    /* 0x38 */ u16 unk38;
    /* 0x3A */ u16 unk3A;
    /* 0x3C */ s32 flags;
} SpawnDef;

typedef struct {
    /* 0x00 */ u8 pad00[0x24];
    /* 0x24 */ SpawnVec3 pos;
    /* 0x30 */ SpawnVec3 rot;
    /* 0x3C */ AssetSlotEntry *slot;
    /* 0x40 */ SlotBounds bounds;
    /* 0x50 */ s32 input;
    /* 0x54 */ f32 lift;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ struct { u32 hi : 9; u32 lo : 23; } bits;
} SpawnObject;

typedef struct {
    s32 *header;
    AssetSlotEntry *entries;
    s32 pad[2];
} AssetSlotTable;

extern AssetSlotTable D_800C0784[];
extern f32 D_800E19E0;
extern f32 D_800E19E4;
extern f32 D_800E19E8;
extern s8 D_80109A94;

/* Fills an asset slot entry from a spawn definition (allocating vertices, triangles, collision planes, bounds and display list on first load) and, if requested, creates or updates the world object bound to the slot. */ void initAssetSlotFromSpawnDef(SpawnObject **objp, SpawnDef *sp, s32 load)
{
    s32 mode;
    s8 visible;
    s32 scanA;
    s32 scanLen;
    s32 scanKind;
    s32 vertexCount;
    s32 commandCount;
    s32 vertexCount2;
    s32 commandCount2;
    AssetSlotEntry *slots;
    AssetSlotEntry *rec;
    AssetSlotEntry *slot;
    SpawnObject *obj;
    s32 planes;
    s32 commands;
    s32 i;
    s32 off;
    s8 kind;
    f32 scale;
    u32 bits;

    mode = 1;
    visible = 1;
    slots = D_800C0784[*sp->slotIndex].entries;
    slots[sp->id].packed = (slots[sp->id].packed & 0xFFF0000F) | (sp->id << 4);
    slots[sp->id].packed = (slots[sp->id].packed & 0xFFFFF) | (*sp->slotIndex << 20);
    slots[sp->id].unk47 = sp->unk3A;
    scale = 1.0f;
    switch (sp->model->type) {
        case 0x14: case 0x15: case 0x18: case 0x19: case 0x1A: case 0x1B: case 0x1E: case 0x1F:
        case 0x21: case 0x22: case 0x27: case 0x3C: case 0x3D: case 0x3E: case 0x40: case 0x42:
        case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49: case 0x4D:
        case 0x4F: case 0x50: case 0x52: case 0x53: case 0x68: case 0x84: case 0x85: case 0x86:
        case 0x87: case 0x88: case 0x89: case 0x8A: case 0x8B: case 0x8C: case 0x99: case 0x9A:
        case 0x9B: case 0x9C: case 0x9D: case 0x9E: case 0xC8:
            if ((load << 24) != 0) {
                switch (sp->model->type) {
                    case 0x22: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47:
                    case 0x48: case 0x49: case 0x4F: case 0x50:
                        {
                            SpawnObject *made = func_8003C860(*objp, 1);
                            *objp = made;
                            made->slot = &slots[sp->id];
                        }
                        (*objp)->pos.x = sp->pos.x;
                        (*objp)->pos.y = sp->pos.y;
                        (*objp)->pos.z = sp->pos.z;
                        D_800E19E0 = (*objp)->pos.x;
                        D_800E19E4 = (*objp)->pos.y;
                        D_800E19E8 = (*objp)->pos.z;
                        break;
                    default:
                        {
                            SpawnObject *made = func_8003C860(*objp, 0);
                            *objp = made;
                            made->slot = &slots[sp->id];
                        }
                        break;
                }
                rec = (*objp)->slot;
                mode = 1;
                func_80045278(&D_800E19E0);
                (*objp)->pos.x = sp->pos.x;
                (*objp)->pos.y = sp->pos.y;
                (*objp)->pos.z = sp->pos.z;
                (*objp)->rot.x = sp->rot.x * 4.261058e-06f;
                (*objp)->rot.y = sp->rot.y * 4.261058e-06f;
                (*objp)->rot.z = sp->rot.z * 4.261058e-06f;
                (*objp)->input = func_8003FCF4(sp);
                (*objp)->lift = 0.0f;
                scale = 1.0f;
                if (sp->flags & 0x10000) {
                    (*objp)->lift += 5.0f;
                }
                if (sp->flags & 0x20000) {
                    (*objp)->lift += 10.0f;
                }
                func_800404F0(sp, *objp, &mode, &visible);
                if (sp->flags & 0x2000) {
                    (*objp)->bits.hi |= 0x10;
                }
                if (slots[sp->id].loaded == 0) {
                    func_8003FDE0(sp->model->commands, &scanA, &scanLen, &scanKind);
                    rec->count = sp->model->count;
                    rec->len = scanLen;
                    slots[sp->id].loaded = 1;
                    rec->verts = heapAllocTagged(sp->model->count * 12, 2);
                    if ((u32)(scanKind - 1) < 2) {
                        rec->flags48 |= 4;
                        rec->tris = heapAllocTagged(rec->len * 6, 4);
                    } else {
                        rec->flags48 |= 8;
                        rec->tris = heapAllocTagged(rec->len * 3, 3);
                    }
                    do {
                    rec->planes = heapAllocTagged(rec->len * 2, 5);
                    do {
                    commands = sp->model->commands;
                    planes = rec->planes;
                    i = 0;
                    for (; i < sp->model->count; i++) {
                        vec3Add(&D_800E19E0, &sp->model->verts[i], &rec->verts[i]);
                    }
                    } while (0);
                    buildCollisionPlanesFromCommands(rec, commands, planes);
                    (*objp)->slot = &slots[sp->id];
                    } while (0);
                    (*objp)->slot->count = sp->model->count;
                    obj = *objp;
                    func_8003C94C(obj->slot, &obj->bounds, &obj->slot->sphere);
                    slots[sp->id].bounds = (*objp)->bounds;
                    buildTriangleGridMasks((*objp)->slot);
                    func_80041114(*objp);
                    if (scale != 1.0f) {
                        slots[sp->id].flags48 |= 0x10;
                    }
                    slots[sp->id].loaded = mode;
                    if ((slots[sp->id].flags46 & 0x80) && visible) {
                        s32 *header = D_800C0784[*sp->slotIndex].header;
                        if (header != NULL) {
                            s32 headerA, headerB, dl;
                            headerA = header[4];
                            headerB = header[6];
                            vertexCount = 0;
                            commandCount = 0;
                            func_800336FC(sp->model->commands, slots[sp->id].verts, sp->model->unk08, sp->model->unk10, mode, scale, headerB, headerA, 0, &vertexCount, &commandCount);
                            dl = heapAllocTagged(vertexCount * 16 + commandCount * 8, 0x2E);
                            slots[sp->id].dl = dl;
                            func_800328B8(dl + commandCount * 8, dl);
                            rec->dl = dl;
                            func_800336FC(sp->model->commands, slots[sp->id].verts, sp->model->unk08, sp->model->unk10, mode, scale, headerB, headerA, 1, NULL, NULL);
                            if (D_80109A94) {
                                slots[sp->id].flags46 |= 0x80;
                            }
                        }
                    }
                    func_800410E8(*objp);
                    slots[sp->id] = *rec;
                    return;
                }
                (*objp)->bounds = slots[sp->id].bounds;
                (*objp)->slot = &slots[sp->id];
                (*objp)->pos.x = sp->pos.x;
                (*objp)->pos.y = sp->pos.y;
                (*objp)->pos.z = sp->pos.z;
                (*objp)->rot.x = sp->rot.x * 4.261058e-06f;
                (*objp)->rot.y = sp->rot.y * 4.261058e-06f;
                (*objp)->rot.z = sp->rot.z * 4.261058e-06f;
                func_80041114(*objp);
                func_800410E8(*objp);
            }
            return;
        default:
            if (slots[sp->id].loaded == 0) {
                kind = 0;
                func_8003FDE0(sp->model->commands, &scanA, &scanLen, &scanKind);
                slots[sp->id].loaded = 1;
                mode = 1;
                switch (sp->model->type) {
                    case 0x73:
                        sp->flags |= 0x1000;
                        goto set_kind;
                    case 0x74:
                        sp->flags |= 0x1000;
                    case 0x31:
                        mode = 1;
                        break;
                    case 0x34: case 0x51: case 0x7A: case 0x7D:
                    set5:
                        mode = 5;
                        kind = 1;
                        break;
                    case 0x29: case 0x2A: case 0x2B:
                        mode = 1;
                        kind = 1;
                        break;
                    case 0x79:
                        mode = 3;
                        kind = 1;
                        break;
                    case 0x75:
                        sp->flags |= 0x1000;
                    case 0x32:
                        mode = 0xC;
                        kind = 1;
                        break;
                    case 0x97:
                        mode = 0xA;
                        kind = 1;
                        break;
                    case 0x76:
                        sp->flags |= 0x1000;
                    case 0x33:
                        mode = 4;
                        kind = 1;
                        break;
                    case 0x77:
                        sp->flags |= 0x1000;
                        goto set5;
                    case 0xC7:
                        mode = 0xF;
                        kind = 1;
                        break;
                    case 0x80:
                        mode = 5;
                        break;
                    case 0x78:
                        sp->flags |= 0x1000;
                    case 0x35:
                        mode = 6;
                        kind = 1;
                        break;
                    case 0x55:
                        mode = 9;
                        kind = 1;
                        break;
                    case 0x5D:
                        sp->flags |= 0x1000;
                        break;
                    case 0x30: case 0x54: case 0x56: case 0xC9:
                    set_kind:
                        kind = 1;
                        break;
                }
                if (sp->flags & 0x1000) {
                    scale = 64.0f;
                }
                slots[sp->id].count = sp->model->count;
                slots[sp->id].len = scanLen;
                rec = &slots[sp->id];
                if (kind == 0) {
                    rec->verts = heapAllocTagged(sp->model->count * 12, 2);
                    if ((u32)(scanKind - 1) < 2) {
                        rec->flags48 |= 4;
                        rec->tris = heapAllocTagged(rec->len * 6, 4);
                    } else {
                        rec->flags48 |= 8;
                        rec->tris = heapAllocTagged(rec->len * 3, 3);
                    }
                    rec->planes = heapAllocTagged(rec->len * 2, 5);
                    for (i = 0; i < sp->model->count; i++) {
                        func_80045290(&sp->model->verts[i], &rec->verts[i]);
                    }
                    buildCollisionPlanesFromCommands(rec, sp->model->commands, rec->planes);
                    computeMeshBounds(rec, &rec->bounds, rec->sphere);
                    buildTriangleGridMasks(rec);
                } else {
                    computeVertexBounds(sp->model->count, sp->model->verts, &rec->bounds, rec->sphere);
                }
                if (scale != 1.0f) {
                    slots[sp->id].flags48 |= 0x10;
                }
                slots[sp->id].loaded = mode;
                if (slots[sp->id].flags46 & 0x80) {
                    s32 *header = D_800C0784[*sp->slotIndex].header;
                    if (header != NULL) {
                        s32 headerA, headerB, dl;
                        headerA = header[4];
                        headerB = header[6];
                        vertexCount2 = 0;
                        commandCount2 = 0;
                        func_800336FC(sp->model->commands, sp->model->verts, sp->model->unk08, sp->model->unk10, mode, scale, headerB, headerA, 0, &vertexCount2, &commandCount2);
                        dl = heapAllocTagged(vertexCount2 * 16 + commandCount2 * 8, 0x2E);
                        func_800328B8(dl + commandCount2 * 8, dl);
                        slots[sp->id].dl = dl;
                        func_800336FC(sp->model->commands, sp->model->verts, sp->model->unk08, sp->model->unk10, mode, scale, headerB, headerA, 1, NULL, NULL);
                        if (D_80109A94) {
                            slots[sp->id].flags46 |= 0x80;
                        }
                    }
                }
            }
            break;
    }
}
