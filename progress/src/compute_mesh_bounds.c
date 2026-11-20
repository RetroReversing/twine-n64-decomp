typedef struct { f32 x, y, z; } BoundVertex;
typedef struct { u8 pad0[0x34]; BoundVertex *vertices; u8 pad38[0xA]; u16 count; } BoundMesh;
typedef struct { f32 x, y, z, radius; } BoundSphere;
typedef struct { f32 minX, maxX, minY, maxY, minZ, maxZ; } BoundBox;

f32 func_800828D0(f32);
f32 func_80082908(f32);

void compute_mesh_bounds(BoundMesh *mesh, BoundSphere *sphere, BoundBox *box) {
    BoundVertex *first, *vertex, *end;
    u16 count;
    s32 offset;
    f32 minX, minY, minZ, maxX, maxY, maxZ;
    f32 x, y, z;
    f32 extentX, extentY, extentZ;

    if (mesh == NULL)
        return;
    if (sphere == NULL)
        return;
    {
        first = mesh->vertices;
        count = mesh->count;
        maxX = first->x;
        maxY = first->y;
        maxZ = first->z;
        minX = maxX;
        minY = maxY;
        minZ = maxZ;
        if (count != 0) {
            offset = 0;
            vertex = first;
            end = (BoundVertex *)((u32)count * sizeof(BoundVertex) + (u32)vertex);
            do {
                x = vertex->x;
                if (x < minX)
                    minX = x;
                else if (maxX < x)
                    maxX = x;
                y = ((BoundVertex *)((u32)offset + (u32)((volatile BoundMesh *)mesh)->vertices))->y;
                if (y < minY)
                    minY = y;
                else if (maxY < y)
                    maxY = y;
                z = ((BoundVertex *)((u32)offset + (u32)((volatile BoundMesh *)mesh)->vertices))->z;
                if (z < minZ)
                    minZ = z;
                else if (maxZ < z)
                    maxZ = z;
                vertex++;
                offset += sizeof(BoundVertex);
            } while ((s32)vertex < (s32)end);
        }
        box->maxX = maxX;
        box->maxY = maxY;
        box->maxZ = maxZ;
        box->minX = minX;
        box->minY = minY;
        box->minZ = minZ;
        extentX = func_800828D0(minX);
        if (extentX < func_800828D0(maxX))
            extentX = maxX;
        extentY = func_800828D0(minY);
        if (extentY < func_800828D0(maxY))
            extentY = maxY;
        extentZ = func_800828D0(minZ);
        if (extentZ < func_800828D0(maxZ))
            extentZ = maxZ;
        sphere->radius = func_80082908(extentX * extentX + extentY * extentY + extentZ * extentZ);
        sphere->x = 0.0f;
        sphere->y = 0.0f;
        sphere->z = 0.0f;
    }
}
