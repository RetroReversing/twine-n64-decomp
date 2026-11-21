typedef struct {
    u8 pad[0x18];
    f32 xmin, xmax;
    u8 pad20[8];
    f32 zmin, zmax;
    s32 unk30;
    f32 (*verts)[3];
    u16 *masks;
    void *indices;
    u16 count;
    u8 pad42[6];
    u8 flags;
} GridMesh;

extern s32 triangleOverlapsBounds(f32 *, f32 *, f32 *, f32, f32, f32, f32);

void func_80040E5C(GridMesh *mesh) {
    f32 xstep = (mesh->xmax - mesh->xmin) * 0.125f;
    f32 zstep = (mesh->zmax - mesh->zmin) * 0.125f;
    s32 i;
    for (i = 0; i < mesh->count; i++) {
        f32 *a, *b, *c;
        s32 x, z;
        if (mesh->flags & 4) {
            u16 *tri = (u16 *)mesh->indices + i * 3;
            a = mesh->verts[tri[0]];
            b = mesh->verts[tri[1]];
            c = mesh->verts[tri[2]];
        } else {
            u8 *tri = (u8 *)mesh->indices + i * 3;
            a = mesh->verts[tri[0]];
            b = mesh->verts[tri[1]];
            c = mesh->verts[tri[2]];
        }
        for (x = 0; x < 8; x++) {
            f32 xoff = xstep * x;
            f32 xnext = xstep * (x + 1);
            for (z = 0; z < 8; z++) {
                f32 xmin = mesh->xmin;
                f32 zmin = mesh->zmin;
                if ((triangleOverlapsBounds(a, b, c,
                        xmin + xoff, zmin + zstep * z,
                        xmin + xnext, zmin + zstep * (z + 1)) << 24) != 0) {
                    mesh->masks[i] |= ((1 << x) << 8) | (1 << z);
                }
            }
        }
        if (!mesh->masks[i])
            mesh->masks[i] = 0xFFFF;
    }
}
