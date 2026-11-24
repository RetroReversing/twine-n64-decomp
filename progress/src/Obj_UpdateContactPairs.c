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
Contact *Contact_PushFront(Contact *);
s8 meshVertsInOther(Obj *, Obj *);
s8 Obj_BoundsContainPoint(f32 *, Obj *, f32);
f32 Vec3_DistanceSq(f32 *, f32 *);
s8 func_8003D53C(f32, f32, f32);
void func_8003DA68(Obj *, Obj *, Obj *, f32 *, f32 *);

/* For each overlapping pair of type-0x46 objects, adds contact records for nearby
 * objects of type 0x1E, 0x84 or 0x88 and flattens ridge vertices of the third object. */
void Obj_UpdateContactPairs(Obj *list) {
    Obj *a;
    Obj *b;
    Obj *c;
    Contact *k;
    Mesh *m;
    Vert *v;
    u32 i;
    u16 t;
    f32 *p;
    f32 hi;
    f32 lo;
    f32 f;
    f32 base;
    f32 level;

    for (a = list; a != NULL; a = a->next) {
        if (a->u.type != 0x46) {
            continue;
        }
        for (b = a->next; b != NULL; b = b->next) {
            if (b->u.type != 0x46 || !(Vec3_DistanceSq(a->pos, b->pos) < a->radius + b->radius)) {
                continue;
            }
            for (c = list; c != NULL; c = c->next) {
                t = c->u.type;
                p = c->pos;
                if (((t == 0x1E) | (t == 0x84)) || t == 0x88) {
                    if (!Obj_BoundsContainPoint(p, a, 1.0f) || !Obj_BoundsContainPoint(p, b, 1.0f)
                            || !meshVertsInOther(c, a) || !meshVertsInOther(c, b)) {
                        continue;
                    }
                    a->sub->contact = Contact_PushFront(a->sub->contact);
                    a->sub->contact->b28 = c->flags54;
                    a->sub->contact->b29 = c->flags55;
                    a->sub->contact->obj = c;
                    a->sub->contact->other = b;
                    a->sub->contact->bits = (c->u.flags >> 2) & 0x3FFF;
                    k = a->sub->contact;
                    func_8003DA68(c, a, b, k->normal, &k->depth);
                    b->sub->contact = Contact_PushFront(b->sub->contact);
                    b->sub->contact->b28 = c->flags54;
                    b->sub->contact->b29 = c->flags55;
                    b->sub->contact->obj = c;
                    b->sub->contact->other = a;
                    b->sub->contact->bits = (c->u.flags >> 2) & 0x3FFF;
                    b->sub->contact->bits &= 0xF7FF;
                    b->sub->contact->normal[0] = -a->sub->contact->normal[0];
                    b->sub->contact->normal[1] = -a->sub->contact->normal[1];
                    b->sub->contact->normal[2] = -a->sub->contact->normal[2];
                    b->sub->contact->depth = -a->sub->contact->depth;
                    a->sub->contact->link = b->sub->contact;
                    b->sub->contact->link = a->sub->contact;
                    if (((a->u.flags >> 2) & 0x200) || ((b->u.flags >> 2) & 0x200)) {
                        m = c->mesh;
                        v = m->verts;
                        lo = v->y;
                        hi = lo;
                        for (i = 0; i < m->count; i++, v++) {
                            f = v->y;
                            if (hi < f) {
                                hi = f;
                            }
                            if (f < lo) {
                                lo = f;
                            }
                        }
                        if (hi != lo) {
                            base = a->mesh->base;
                            level = hi - base;
                            level = base - level;
                            for (i = 0; i < c->mesh->count; i++) {
                                if (func_8003D53C(c->mesh->verts[i].y, lo, 0.1f)) {
                                    c->mesh->verts[i].y = level;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
