typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 pad[0x34]; Vec3f *verts; u8 pad38[0xA]; u16 vertCount; } Mesh;
typedef struct { u8 pad[0x3C]; Mesh *mesh; } MeshObject;

/* Returns 1 if every vertex of a's mesh matches some vertex of b's mesh (counted per matching pair). */
s32 meshVertsInOther(MeshObject *a, MeshObject *b) {
    Mesh *meshA = a->mesh;
    Mesh *meshB;
    s32 hits = 0;
    s32 i, j;

    meshB = b->mesh;

    for (i = 0; i < meshA->vertCount; i++) {
        for (j = 0; j < meshB->vertCount; j++) {
            if (meshA->verts[i].x == meshB->verts[j].x && meshA->verts[i].y == meshB->verts[j].y && meshA->verts[i].z == meshB->verts[j].z) {
                hits++;
                if (hits == meshA->vertCount) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
