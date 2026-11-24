typedef struct { f32 x, y, z; } BoundVertex;
typedef struct { u8 pad0[0x34]; BoundVertex *vertices; u8 pad38[0xA]; u16 count; } BoundMesh;
typedef struct { f32 x, y, z, radius; } BoundSphere;
typedef struct { f32 minX, maxX, minY, maxY, minZ, maxZ; } BoundBox;

f32 absFloat(f32);
f32 sqrtf32(f32);

/* Computes the axis-aligned bounding box of a mesh's vertices, then a bounding sphere centred at the origin. */ void computeMeshBounds(BoundMesh *mesh, BoundSphere *sphere, BoundBox *box) {
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
        extentX = absFloat(minX);
        if (extentX < absFloat(maxX))
            extentX = maxX;
        extentY = absFloat(minY);
        if (extentY < absFloat(maxY))
            extentY = maxY;
        extentZ = absFloat(minZ);
        if (extentZ < absFloat(maxZ))
            extentZ = maxZ;
        sphere->radius = sqrtf32(extentX * extentX + extentY * extentY + extentZ * extentZ);
        sphere->x = 0.0f;
        sphere->y = 0.0f;
        sphere->z = 0.0f;
    }
}
