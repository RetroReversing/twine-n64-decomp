typedef struct { f32 x; f32 y; f32 z; } Vert;
typedef struct { u8 pad0[0x20]; f32 base; u8 pad1[0x10]; Vert *verts; u8 pad2[0xA]; u16 count; } Mesh;
typedef struct Contact {
    u8 pad0[4];
    struct Obj *obj;
    struct Obj *other;
    f32 normal[3];
    f32 depth;
    u8 pad1[4];
    struct Contact *link;
    u8 pad2[2];
    u16 bits;
    u8 b28;
    u8 b29;
} Contact;
typedef struct { u8 pad0[0x58]; Contact *contact; } Sub;
typedef struct Obj {
    u8 pad0[0x10];
    struct Obj *next;
    u8 pad1[0xC];
    Sub *sub;
    u8 pad2[0x18];
    Mesh *mesh;
    f32 pos[3];
    f32 radius;
    u8 pad3[4];
    u8 flags54;
    u8 flags55;
    u8 pad4[2];
    union { u32 flags; u16 type; } u;
} Obj;
Contact *allocContactNode(Contact *);
s8 meshVertsInOther(Obj *, Obj *);
s8 Obj_BoundsContainPoint(f32 *, Obj *, f32);
f32 vec3DistanceBetween(f32 *, f32 *);
s8 func_8003D53C(f32, f32, f32);
void func_8003DA68(Obj *, Obj *, Obj *, f32 *, f32 *);

/* For each overlapping pair of type-0x46 objects, adds contact records for nearby
 * objects of type 0x1E, 0x84 or 0x88 and flattens ridge vertices of the third object. */
void Obj_UpdateContactPairs(Obj *list) {
    Obj *objA;
    Obj *objB;
    Obj *cand;
    Contact *contact;
    Mesh *mesh;
    Vert *vert;
    u32 i;
    u16 type;
    f32 *pos;
    f32 maxY;
    f32 minY;
    f32 vertY;
    f32 baseY;
    f32 flatY;

    for (objA = list; objA != NULL; objA = objA->next) {
        if (objA->u.type != 0x46) {
            continue;
        }
        for (objB = objA->next; objB != NULL; objB = objB->next) {
            if (objB->u.type != 0x46 || !(vec3DistanceBetween(objA->pos, objB->pos) < objA->radius + objB->radius)) {
                continue;
            }
            for (cand = list; cand != NULL; cand = cand->next) {
                type = cand->u.type;
                pos = cand->pos;
                if (((type == 0x1E) | (type == 0x84)) || type == 0x88) {
                    if (!Obj_BoundsContainPoint(pos, objA, 1.0f) || !Obj_BoundsContainPoint(pos, objB, 1.0f)
                            || !meshVertsInOther(cand, objA) || !meshVertsInOther(cand, objB)) {
                        continue;
                    }
                    objA->sub->contact = allocContactNode(objA->sub->contact);
                    objA->sub->contact->b28 = cand->flags54;
                    objA->sub->contact->b29 = cand->flags55;
                    objA->sub->contact->obj = cand;
                    objA->sub->contact->other = objB;
                    objA->sub->contact->bits = (cand->u.flags >> 2) & 0x3FFF;
                    contact = objA->sub->contact;
                    func_8003DA68(cand, objA, objB, contact->normal, &contact->depth);
                    objB->sub->contact = allocContactNode(objB->sub->contact);
                    objB->sub->contact->b28 = cand->flags54;
                    objB->sub->contact->b29 = cand->flags55;
                    objB->sub->contact->obj = cand;
                    objB->sub->contact->other = objA;
                    objB->sub->contact->bits = (cand->u.flags >> 2) & 0x3FFF;
                    objB->sub->contact->bits &= 0xF7FF;
                    objB->sub->contact->normal[0] = -objA->sub->contact->normal[0];
                    objB->sub->contact->normal[1] = -objA->sub->contact->normal[1];
                    objB->sub->contact->normal[2] = -objA->sub->contact->normal[2];
                    objB->sub->contact->depth = -objA->sub->contact->depth;
                    objA->sub->contact->link = objB->sub->contact;
                    objB->sub->contact->link = objA->sub->contact;
                    if (((objA->u.flags >> 2) & 0x200) || ((objB->u.flags >> 2) & 0x200)) {
                        mesh = cand->mesh;
                        vert = mesh->verts;
                        minY = vert->y;
                        maxY = minY;
                        for (i = 0; i < mesh->count; i++, vert++) {
                            vertY = vert->y;
                            if (maxY < vertY) {
                                maxY = vertY;
                            }
                            if (vertY < minY) {
                                minY = vertY;
                            }
                        }
                        if (maxY != minY) {
                            baseY = objA->mesh->base;
                            flatY = maxY - baseY;
                            flatY = baseY - flatY;
                            for (i = 0; i < cand->mesh->count; i++) {
                                if (func_8003D53C(cand->mesh->verts[i].y, minY, 0.1f)) {
                                    cand->mesh->verts[i].y = flatY;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
