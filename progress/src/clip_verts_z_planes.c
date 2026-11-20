typedef struct {
    f32 x, y, z;
    s32 rest[6];
} ClipVertex;

extern f32 D_800C0740;
extern ClipVertex *clip_result_verts;
extern ClipVertex clip_buffer_a[], clip_buffer_b[];
extern ClipVertex *clip_src_verts, *clip_dst_verts, *clip_cursor, *clip_swap_tmp;
extern s16 D_800E19C8, D_800E19CA, D_800E19CC, D_800E19CE, clip_near_out_count, clip_far_out_count;

/* Clips the vertex list in clip_buffer_a against the near plane (z = 0.2) and the far plane (D_800C0740), ping-ponging between the two buffers; returns the number of surviving vertices. */
s32 clip_verts_z_planes(s32 vert_count)
{
    s32 i;
    s16 pass, remaining, in_idx, out_idx, prev_idx;
    u8 outside[8];
    u8 *flag_ptr;
    f32 plane_z;

    clip_far_out_count = 0;
    clip_near_out_count = 0;
    D_800E19CE = 0;
    D_800E19CC = 0;
    D_800E19CA = 0;
    D_800E19C8 = 0;
    for (i = 0; i < vert_count; i++) {
        f32 z = clip_buffer_a[i].z;
        if (z < 0.2f)
            clip_near_out_count++;
        else if (D_800C0740 < z)
            clip_far_out_count++;
    }
    if (clip_near_out_count + clip_far_out_count == 0) {
        clip_result_verts = clip_buffer_a;
        return vert_count;
    }
    if (clip_near_out_count == vert_count || clip_far_out_count == vert_count)
        return 0;

    clip_result_verts = clip_src_verts = clip_buffer_a;
    clip_dst_verts = clip_buffer_b;
    for (pass = 0; pass < 2; pass++) {
        switch (pass) {
        default:
        case 0:
            if (!clip_near_out_count) continue;
            plane_z = 0.2f;
            clip_cursor = clip_src_verts;
            flag_ptr = outside;
            for (remaining = vert_count; remaining > 0;) {
                u8 value = clip_cursor->z < plane_z;
                remaining--;
                *flag_ptr = value;
                clip_cursor++;
                flag_ptr++;
            }
            break;
        case 1:
            if (!clip_far_out_count) continue;
            plane_z = D_800C0740;
            clip_cursor = clip_src_verts;
            flag_ptr = outside;
            for (remaining = vert_count; remaining > 0;) {
                u8 value = plane_z < clip_cursor->z;
                remaining--;
                *flag_ptr = value;
                clip_cursor++;
                flag_ptr++;
            }
            break;
        }
        out_idx = 0;
        prev_idx = vert_count - 1;
        for (in_idx = 0; in_idx < vert_count; in_idx++) {
            if (outside[prev_idx] != outside[in_idx]) {
                if ((u16)pass < 2) {
                    s32 dstIndex = out_idx;
                    s32 dstBase = (s32)clip_dst_verts;
                    ClipVertex *new_vtx = (ClipVertex *)(dstIndex * 36 + dstBase);
                    ClipVertex *cur = (ClipVertex *)(in_idx * 36 + (s32)clip_src_verts);
                    ClipVertex *prev = (ClipVertex *)(prev_idx * 36 + (s32)clip_src_verts);
                    f32 fraction;
                    new_vtx->z = plane_z;
                    fraction = (plane_z - cur->z) / (prev->z - cur->z);
                    new_vtx->x = cur->x + (prev->x - cur->x) * fraction;
                    new_vtx->y = cur->y + (prev->y - cur->y) * fraction;
                }
                out_idx++;
            }
            if (!outside[in_idx]) {
                clip_dst_verts[out_idx] = clip_src_verts[in_idx];
                out_idx++;
            }
            prev_idx = in_idx;
        }
        { ClipVertex *tmp = clip_dst_verts;
        clip_swap_tmp = tmp;
        clip_dst_verts = clip_src_verts;
        clip_src_verts = tmp;
        }
        vert_count = out_idx;
    }
    clip_result_verts = clip_src_verts;
    return vert_count;
}
