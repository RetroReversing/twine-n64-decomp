#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

f32 vec3NormalizeLength(f32 *, f32 *);
s8 rayTriangleIntersect(void *, f32 *, s32, s32, s32, f32 *);
s32 sphereContainsPoint(void *, void *, f32);
extern f64 D_800D3E08;


/* Casts a ray from rayOrigin toward rayTarget against the meshes of object's node list.
 * Returns the first node hit (writing the hit point to hitPoint if non-NULL), else NULL. */
void *raycastObjectMesh(void *object, void *rayOrigin, void *rayTarget, void *hitPoint) {
    union {
        unsigned char bytes[40];
        struct { f32 value; } view_sp18;
        struct { unsigned char pad[4]; f32 value; } view_sp1C;
        struct { unsigned char pad[8]; f32 value; } view_sp20;
        struct { unsigned char pad[16]; f32 value; } view_sp28;
        struct { unsigned char pad[20]; f32 value; } view_sp2C;
        struct { unsigned char pad[24]; f32 value; } view_sp30;
        struct { unsigned char pad[32]; f32 value; } view_sp38;
    } m2c_initial_frame;
    int __repair_literal;
    f32 rayLength;
    f64 bias;
    void *out = hitPoint;
    f32 distance;
    s32 vertices;
    s32 vertices8;
    s32 triIndex;
    s32 indexOffset;
    void *mesh;
    void *tri16;
    void *tri8;
    void *node;
    void *item;

    if (object != NULL) {
        node = M2C_FIELD(M2C_FIELD(object, void **, 0x20), void **, 0x58);
        m2c_initial_frame.view_sp28.value = M2C_FIELD(rayTarget, f32 *, 0) - M2C_FIELD(rayOrigin, f32 *, 0);
        m2c_initial_frame.view_sp2C.value = M2C_FIELD(rayTarget, f32 *, 4) - M2C_FIELD(rayOrigin, f32 *, 4);
        m2c_initial_frame.view_sp30.value = M2C_FIELD(rayTarget, f32 *, 8) - M2C_FIELD(rayOrigin, f32 *, 8);
        rayLength = vec3NormalizeLength(&m2c_initial_frame.view_sp18.value, &m2c_initial_frame.view_sp28.value);
        if (node != NULL) {
            bias = D_800D3E08;
loop_3:
            item = M2C_FIELD(node, void **, 4);
            if ((sphereContainsPoint((s8 *)item + 0x40, rayOrigin, rayLength) << 24) != 0) {
              mesh = M2C_FIELD(item, void **, 0x3C);
              if (mesh != NULL) {
                if (M2C_FIELD(mesh, u8 *, 0x48) & 4) {
                    triIndex = 0;
__repair_literal = 0;

                    if ((s32) M2C_FIELD(mesh, u16 *, 0x40) > __repair_literal) {
                        indexOffset = 0;
loop_8:
                        vertices = M2C_FIELD(mesh, s32 *, 0x34);
                        tri16 = M2C_FIELD(mesh, s32 *, 0x3C) + indexOffset;
                        if (!(rayTriangleIntersect(rayOrigin, &m2c_initial_frame.view_sp18.value, vertices + (M2C_FIELD(tri16, u16 *, 0) * 0xC), vertices + (M2C_FIELD(tri16, u16 *, 2) * 0xC), vertices + (M2C_FIELD(tri16, u16 *, 4) * 0xC), &m2c_initial_frame.view_sp38.value) & 0xFF) || !((distance = m2c_initial_frame.view_sp38.value) >= 0.0f) || !(distance <= rayLength)) {
                            triIndex++;
                            indexOffset += 6;
                            if (triIndex < (s32)M2C_FIELD(mesh, u16 *, 0x40)) goto loop_8;
                            goto block_26;
                        }
                        if (out != NULL) {
                            M2C_FIELD(out, f32 *, 0) = (f32) (M2C_FIELD(rayOrigin, f32 *, 0) + (distance * m2c_initial_frame.view_sp18.value)) + (f64)m2c_initial_frame.view_sp18.value * bias;
                            M2C_FIELD(out, f32 *, 4) = (f32) (M2C_FIELD(rayOrigin, f32 *, 4) + (distance * m2c_initial_frame.view_sp1C.value)) + (f64)m2c_initial_frame.view_sp1C.value * bias;
                            M2C_FIELD(out, f32 *, 8) = (f32) (M2C_FIELD(rayOrigin, f32 *, 8) + (distance * m2c_initial_frame.view_sp20.value)) + (f64)m2c_initial_frame.view_sp20.value * bias;
                        }
                        return node;
                    }
                    goto block_26;
                }
                triIndex = 0;
                __repair_literal = 0;
                if ((s32) M2C_FIELD(mesh, u16 *, 0x40) > __repair_literal) {
                    indexOffset = 0;
loop_15:
                    vertices8 = M2C_FIELD(mesh, s32 *, 0x34);
                    tri8 = M2C_FIELD(mesh, s32 *, 0x3C) + indexOffset;
                    if ((rayTriangleIntersect(rayOrigin, &m2c_initial_frame.view_sp18.value, vertices8 + (M2C_FIELD(tri8, u8 *, 0) * 0xC), vertices8 + (M2C_FIELD(tri8, u8 *, 1) * 0xC), vertices8 + (M2C_FIELD(tri8, u8 *, 2) * 0xC), &m2c_initial_frame.view_sp38.value) & 0xFF) && ((distance = m2c_initial_frame.view_sp38.value) >= 0.0f) && (distance <= rayLength)) {
                        if (out != NULL) {
                            M2C_FIELD(out, f32 *, 0) = (f32) (M2C_FIELD(rayOrigin, f32 *, 0) + (distance * m2c_initial_frame.view_sp18.value)) + (f64)m2c_initial_frame.view_sp18.value * bias;
                            M2C_FIELD(out, f32 *, 4) = (f32) (M2C_FIELD(rayOrigin, f32 *, 4) + (distance * m2c_initial_frame.view_sp1C.value)) + (f64)m2c_initial_frame.view_sp1C.value * bias;
                            M2C_FIELD(out, f32 *, 8) = (f32) (M2C_FIELD(rayOrigin, f32 *, 8) + (distance * m2c_initial_frame.view_sp20.value)) + (f64)m2c_initial_frame.view_sp20.value * bias;
                        }
                        return node;
                    }
                    triIndex += 1;
                    indexOffset += 3;
                    if (triIndex >= (s32) M2C_FIELD(mesh, u16 *, 0x40)) {
                        goto block_26;
                    }
                    goto loop_15;
                }
                goto block_26;
            }
            }
block_26:
            node = M2C_FIELD(node, void **, 0);
            if (node == NULL) {
                goto block_27;
            }
            goto loop_3;
        }
    }
block_27:
    return NULL;
}
