typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
  s32 rest[6];
} ClipVertex;
extern f32 D_800C0750;
extern f32 D_800C0754;
extern f32 D_800C0758;
extern f32 D_800C075C;
extern ClipVertex *clip_result_verts;
extern ClipVertex clip_buffer_a[];
extern ClipVertex clip_buffer_b[];
extern ClipVertex *clip_src_verts;
extern ClipVertex *clip_dst_verts;
extern ClipVertex *clip_cursor;
extern ClipVertex *clip_swap_tmp;
extern s16 D_800E19C8;
extern s16 D_800E19CA;
extern s16 D_800E19CC;
extern s16 D_800E19CE;
extern f32 D_800E177C;
s32 func_8003EC70(s32 vert_count)
{
  int __repair_literal;
  s32 i;
  s32 offset;
  s16 pass;
  s16 remaining;
  s16 in_idx;
  s16 out_idx;
  s16 prev_idx;
  u8 outside[8];
  u8 *flag_ptr;
  f32 plane;
  D_800E19CE = 0;
  D_800E19CC = 0;
  D_800E19CA = 0;
  D_800E19C8 = 0;
  i = 0;
  __repair_literal = 0;
  if (vert_count > __repair_literal)
  {
    offset = 0;
    do
    {
      f32 x = *((f32 *) (((u8 *) clip_buffer_a) + offset));
      f32 y;
      if (x < D_800C0754)
      {
        D_800E19CE++;
      }
      else
        if (D_800C0750 < x)
      {
        D_800E19CA++;
      }
      y = *((f32 *) (((u8 *) (&D_800E177C)) + offset));
      if (y < D_800C075C)
      {
        D_800E19C8++;
        if (1)
        {
        }
        i++;
      }
      else
      {
        i++;
        if (D_800C0758 < y)
        {
          D_800E19CC++;
        }
      }
      offset += 36;
    }
    while (i < vert_count);
  }
  if ((((D_800E19C8 + D_800E19CA) + D_800E19CC) + D_800E19CE) == 0)
  {
    clip_result_verts = clip_buffer_a;
    return vert_count;
  }
  if ((((D_800E19C8 == vert_count) || (D_800E19CA == vert_count)) || (D_800E19CC == vert_count)) || (D_800E19CE == vert_count))
  {
    return 0;
  }
  clip_result_verts = (clip_src_verts = clip_buffer_a);
  clip_dst_verts = clip_buffer_b;
  for (pass = 2; pass < 6; pass++)
  {
    switch (pass)
    {
      default:

      case 2:
        if (!D_800E19C8)
      {
        continue;
      }
        plane = D_800C075C;
        clip_cursor = clip_src_verts;
        flag_ptr = outside;
        for (remaining = vert_count; remaining > 0;)
      {
        u8 value = clip_cursor->y < plane;
        remaining--;
        *flag_ptr = value;
        clip_cursor++;
        flag_ptr++;
      }

        break;

      case 3:
        if (!D_800E19CA)
      {
        continue;
      }
        plane = D_800C0750;
        clip_cursor = clip_src_verts;
        flag_ptr = outside;
        for (remaining = vert_count; remaining > 0;)
      {
        u8 value = plane < clip_cursor->x;
        remaining--;
        *flag_ptr = value;
        clip_cursor++;
        flag_ptr++;
      }

        break;

      case 4:
        if (!D_800E19CC)
      {
        continue;
      }
        plane = D_800C0758;
        clip_cursor = clip_src_verts;
        flag_ptr = outside;
        for (remaining = vert_count; remaining > 0;)
      {
        u8 value = plane < clip_cursor->y;
        remaining--;
        *flag_ptr = value;
        clip_cursor++;
        flag_ptr++;
      }

        break;

      case 5:
        if (!D_800E19CE)
      {
        continue;
      }
        plane = D_800C0754;
        clip_cursor = clip_src_verts;
        flag_ptr = outside;
        for (remaining = vert_count; remaining > 0;)
      {
        u8 value = clip_cursor->x < plane;
        remaining--;
        *flag_ptr = value;
        clip_cursor++;
        flag_ptr++;
      }

        break;

    }

    out_idx = 0;
    prev_idx = vert_count - 1;
    for (in_idx = 0; in_idx < vert_count; in_idx++)
    {
      if (outside[prev_idx] != outside[in_idx])
      {
        if ((pass == 2) | (pass == 4))
        {
          s32 dstIndex = out_idx;
          s32 dstBase = (s32) clip_dst_verts;
          ClipVertex *new_vtx = (ClipVertex *) ((dstIndex * 36) + dstBase);
          ClipVertex *cur = (ClipVertex *) ((in_idx * 36) + ((s32) clip_src_verts));
          ClipVertex *prev = (ClipVertex *) ((prev_idx * 36) + ((s32) clip_src_verts));
          f32 fraction;
          f32 base;
          f32 numerator;
          f32 others;
          f32 value;
          new_vtx->y = plane;
          base = cur->y;
          do
          {
            numerator = plane - base; fraction = numerator / (prev->y - base);
          }
          while (0);
          others = prev->x;
          value = cur->x;
          new_vtx->x = value + ((others - value) * fraction);
          new_vtx->z = cur->z + ((prev->z - cur->z) * fraction);
        }
        if ((pass == 3) | (pass == 5))
        {
          s32 dstIndex = out_idx;
          s32 dstBase = (s32) clip_dst_verts;
          ClipVertex *new_vtx = (ClipVertex *) ((dstIndex * 36) + dstBase);
          ClipVertex *cur = (ClipVertex *) ((in_idx * 36) + ((s32) clip_src_verts));
          ClipVertex *prev = (ClipVertex *) ((prev_idx * 36) + ((s32) clip_src_verts));
          f32 fraction;
          f32 base;
          f32 numerator;
          f32 others;
          f32 value;
          new_vtx->x = plane;
          base = cur->x;
          numerator = plane - base;
          fraction = numerator / (prev->x - base);
 do { others = prev->y; value = cur->y; new_vtx->y = value + ((others - value) * fraction); } while (0);
          new_vtx->z = cur->z + ((prev->z - cur->z) * fraction);
        }
        out_idx++;
      }
      if (!outside[in_idx])
      {
        clip_dst_verts[out_idx] = clip_src_verts[in_idx];
        out_idx++;
      }
      prev_idx = in_idx;
    }

    {
      ClipVertex *tmp = clip_dst_verts;
      clip_swap_tmp = tmp;
      clip_dst_verts = clip_src_verts;
      clip_src_verts = tmp;
    }
    vert_count = out_idx;
  }

  clip_result_verts = clip_src_verts;
  return vert_count;
}
