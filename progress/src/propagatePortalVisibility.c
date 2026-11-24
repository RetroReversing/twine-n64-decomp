typedef struct 
{
  f32 values[4];
} ClipBounds;
extern s32 clipPolygonZPlanes(f32 *, void *, s32);
extern s32 clipVerticesInvertDepth(f32 *, f32 *, s32);
extern void setClipParams(f32, f32, f32, f32);
extern void scaleVec2(void *, f32, f32);
extern void transformGlobalVec3();
extern u16 gSurfaceQueryStamp;
extern s32 D_800E09F0;
extern f32 D_800E0A00;
extern f32 D_800E0A24;
extern f32 D_800E0A48;
extern f32 D_800E0A6C;
extern f32 D_800E0B18;
extern f32 D_800E0B20;
extern s32 D_800E0C38;
extern f32 D_800E0C3C;
extern f32 D_800E09F8;
extern f32 gPendingEntries;
extern f32 D_80102E68[];
extern ClipBounds gPendingEntryBounds[];
extern void *gObjectList;
extern s32 gPendingEntryCount;
extern void *gSurfaceQueryContext;
inline static s32 inline_fn(void *arg0)
{
  return (s32) (*((u16 *) (((u8 *) arg0) + 0x40)));
}

/* Recursively walks a room's portals, projecting each visible portal to a screen-space box clipped against the parent's rect, and marking reached rooms/objects visible. */
void propagatePortalVisibility(void *room, ClipBounds *clipRect)
{
  void *visibleRooms[32];
  ClipBounds box;
  s8 spA7;
  s32 visibleCount;
      void *var_t0;
  f32 *scratch;
  void *portal;
  void *var_a1;
  void *var_c1;
  void *portalMesh;
  void *temp_a0;
  void *temp_a3;
  void *temp_v1_1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4_;
  s32 temp_s3;
  s32 temp_v0;
  s32 var_s7;
  s32 i;
  s32 j;
  f32 temp_ft0;
  visibleCount = 0;
  D_800E0C38 += 1;
  if (D_800E09F0 == 0)
  {
    var_a1 = *((void **) room);
    if (var_a1 != NULL)
    {
      do
      {
        s32 flags = *((s32 *) (((u8 *) var_a1) + 0x58));
        if (!(flags & 0x20000))
        {
          goto nextHead;
        }
        if (!(flags & 0x800))
        {
          if (clipRect)
          {
            temp_v1_1 = gObjectList;
            *((s32 *) (((u8 *) var_a1) + 0x58)) = flags | 0x800;
            gObjectList = var_a1;
            *((void **) (((u8 *) var_a1) + 0x1C)) = temp_v1_1;
          }
          else
          {
            temp_v1_2 = gObjectList;
            *((s32 *) (((u8 *) var_a1) + 0x58)) = flags | 0x800;
            gObjectList = var_a1;
            *((void **) (((u8 *) var_a1) + 0x1C)) = temp_v1_2;
          }
        }
        nextHead:
        var_a1 = *((void **) var_a1);

      }
      while (var_a1 != NULL);
    }
  }
  temp_v0 = D_800E09F0 + 1;
  D_800E09F0 = temp_v0;
  if (temp_v0 >= 0x40)
  {
    return;
  }
  if (room != NULL)
  {
    {
      portal = *((void **) (((u8 *) (*((void **) (((u8 *) room) + 0x20)))) + 0x58));
      if (gPendingEntryCount != 0x40)
      {
        ((void **) (&gPendingEntries))[gPendingEntryCount] = room;
        do
        {
          gPendingEntryBounds[gPendingEntryCount] = *clipRect; gPendingEntryCount += 1;
          if (portal != NULL)
          {
            scratch = D_80102E68; var_t0 = &D_800E09F8;
            do
            {
              var_c1 = *((void **) (*((void **) (((u8 *) portal) + 8))));
              if (var_c1 != NULL)
              {
                do
                {
                  s32 flags = *((s32 *) (((u8 *) var_c1) + 0x58));
                  if (!(flags & 0x20000))
                  {
                    goto nextChild;
                  }
                  if (!(flags & 0x800))
                  {
                    temp_v1_3 = gObjectList;
                    *((s32 *) (((u8 *) var_c1) + 0x58)) = flags | 0x800; gObjectList = var_c1;
                    *((void **) (((u8 *) var_c1) + 0x1C)) = temp_v1_3;
                  }
                  nextChild:
                  var_c1 = *((void **) var_c1);

                }
                while (var_c1 != NULL);
              }
              do {
              temp_ft0 = ((((*((f32 *) (((u8 *) gSurfaceQueryContext) + 0x10))) * (*((f32 *) (((u8 *) portal) + 0xC)))) + ((*((f32 *) (((u8 *) gSurfaceQueryContext) + 0x14))) * (*((f32 *) (((u8 *) portal) + 0x10))))) + ((*((f32 *) (((u8 *) gSurfaceQueryContext) + 0x18))) * (*((f32 *) (((u8 *) portal) + 0x14))))) + (*((f32 *) (((u8 *) portal) + 0x18))); D_800E0C3C = temp_ft0;
              if (!(temp_ft0 > (-0.2f)))
              {
                goto nextRegion;
              }
              } while (0);
              temp_a0 = *((void **) (((u8 *) portal) + 0x1C));
              if (temp_a0 != NULL)
              {
                if (!((*((s32 *) (((u8 *) temp_a0) + 0x58))) & 0x800))
                {
                  temp_v1_4_ = gObjectList;
                  *((s32 *) (((u8 *) temp_a0) + 0x58)) |= 0x800; gObjectList = temp_a0;
                  *((void **) (((u8 *) temp_a0) + 0x1C)) = temp_v1_4_;
                }
                if ((*((s16 *) (((u8 *) temp_a0) + 0x7A))) == 0)
                {
                  goto nextRegion;
                }
              }
              {
                box.values[0] = *((f32 *) (((u8 *) gSurfaceQueryContext) + 0x54)); box.values[1] = *((f32 *) (((u8 *) gSurfaceQueryContext) + ((unsigned short) 0x50))); box.values[2] = *((f32 *) (((u8 *) gSurfaceQueryContext) + 0x5C)); box.values[3] = *((f32 *) (((u8 *) gSurfaceQueryContext) + 0x58)); portalMesh = *((void **) ((*((void **) (((u8 *) portal) + 4))) + 0x3C));
                if (D_800E0C3C < 0.4f)
                {
                  box.values[0] = clipRect->values[0]; box.values[1] = clipRect->values[1]; box.values[2] = clipRect->values[2]; box.values[3] = clipRect->values[3];
                  goto block_51;
                }
                else
                {
                  spA7 = 0;
                  {
                    for (var_s7 = 0; var_s7 < ((s32) (*((u16 *) (((u8 *) portalMesh) + 0x40)))); var_s7++)
                    {
                      void *var_v1 = NULL;
                      void *var_a0_2 = NULL;
                      int var_a1_2;
                      u16 var_s0;
                      u16 var_s1;
                      s32 var_v0;
                      f32 *temp_v1_4;
                      if ((*((u8 *) (((u8 *) portalMesh) + 0x48))) & 4)
                      {
                        var_v1 = *((void **) (((u8 *) portalMesh) + 0x3C)); var_v1 = ((u8 *) var_v1) + var_s7 * 6;
                      }
                      else
                      {
                        var_a0_2 = *((void **) (((u8 *) portalMesh) + 0x3C)); var_a0_2 = ((u8 *) var_a0_2) + var_s7 * 3;
                      }
                      if (var_v1 != NULL)
                      {
                        var_a1_2 = *((u16 *) var_v1); var_s0 = *((u16 *) (((u8 *) var_v1) + 2)); var_s1 = *((u16 *) (((u8 *) var_v1) + 4)); var_v0 = var_a1_2 * 2;
                      }
                      else
                      {
                        var_a1_2 = *((u8 *) var_a0_2); var_s0 = *(((u8 *) var_a0_2) + 1); var_s1 = *(((u8 *) var_a0_2) + 2); var_v0 = var_a1_2 * 2;
                      }
                      temp_v1_4 = (f32 *) ((*((s32 *) (((u8 *) portalMesh) + 0x34))) + ((var_v0 + var_a1_2) * 4)); scratch[0] = temp_v1_4[0];
                      scratch[1] = temp_v1_4[1];
                      scratch[2] = temp_v1_4[2];
                      transformGlobalVec3();
                      ((f32 *) var_t0)[0] = scratch[3];
                      ((f32 *) var_t0)[1] = scratch[4];
                      ((f32 *) var_t0)[2] = scratch[5]; temp_v1_4 = (f32 *) ((*((s32 *) (((u8 *) portalMesh) + 0x34))) + (var_s0 * 0xC)); scratch[0] = temp_v1_4[0];
                      scratch[1] = temp_v1_4[1];
                      scratch[2] = temp_v1_4[2];
                      transformGlobalVec3();
                      ((f32 *) var_t0)[9] = scratch[3];
                      ((f32 *) var_t0)[10] = scratch[4];
                      ((f32 *) var_t0)[11] = scratch[5]; temp_v1_4 = (f32 *) ((*((s32 *) (((u8 *) portalMesh) + 0x34))) + (var_s1 * 0xC)); scratch[0] = temp_v1_4[0];
                      scratch[1] = temp_v1_4[1];
                      scratch[2] = temp_v1_4[2];
                      transformGlobalVec3();
                      ((f32 *) var_t0)[18] = scratch[3];
                      ((f32 *) var_t0)[19] = scratch[4];
                      ((f32 *) var_t0)[20] = scratch[5]; temp_s3 = clipPolygonZPlanes(&D_800E0B18, var_t0, 3);
                      if (temp_s3 > 0)
                      {
                        for (i = 0; i < temp_s3; i++)
                        {
                          s32 off = i * 0x24; f32 tmp = *((f32 *) (((u8 *) (&D_800E0B20)) + off));
                          f32 a = (*((f32 *) (((u8 *) gSurfaceQueryContext) + 0x68))) / tmp;
                          f32 b = (*((f32 *) (((u8 *) gSurfaceQueryContext) + 0x6C))) / tmp;
                          scaleVec2((&D_800E0B18) + ((i * 3) * 3), a, b);
                        }

                        setClipParams(clipRect->values[0], clipRect->values[2], clipRect->values[1], clipRect->values[3]);
                        temp_s3 = clipVerticesInvertDepth(&D_800E0B18, &D_800E0B18, temp_s3);
                        if (temp_s3 > 0)
                        {
                          f32 *y;
                          f32 *x;
                          i = 0;
                          if (i < temp_s3)
                          {
                          y = (f32 *)((u8 *)&D_800E0B18 + 4);
                          x = &D_800E0B18;
                          do
                          {
                            if (*x < box.values[0])
                            {
                              if (i)
                              {
                                box.values[0] = *x;
                              }
                              else
                              {
                                box.values[0] = *x;
                              }
                            }
                            if (*x > box.values[1])
                            {
                              box.values[1] = *x;
                            }
                            if (*y < box.values[2])
                            {
                              box.values[2] = *y;
                            }
                            if (*y > box.values[3])
                            {
                              box.values[3] = *y;
                            }
                            y += 9; i++; x += 9;
                          } while (i < temp_s3);
                          }

                          spA7 = 1;
                        }
                      }
                    }
                  }
                  if (spA7 == 1)
                  {
                    goto block_51;
                  }
                }
                if (0)
                {
                  block_51:
                  if (((box.values[1] - box.values[0]) > 0.0f) && ((box.values[3] - box.values[2]) > 0.0f))
                  {
                    f32 fv = D_800E0A00;
                    temp_a3 = *((void **) (((u8 *) portal) + 8));
                    if (fv < D_800E0A24)
                    {
                      fv = D_800E0A24;
                    }
                    if (fv < D_800E0A48)
                    {
                      fv = D_800E0A48;
                    }
                    if (fv < D_800E0A6C)
                    {
                      fv = D_800E0A6C;
                    }
                    if ((*((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0x54))) < fv)
                    {
                      *((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0x54)) = fv;
                    }
                    temp_a0 = *((void **) (((u8 *) temp_a3) + 0x20));
                    if ((*((u16 *) (((u8 *) temp_a0) + 0x60))) != gSurfaceQueryStamp)
                    {
                      *((u16 *) (((u8 *) temp_a0) + 0x60)) = gSurfaceQueryStamp;
                      *((ClipBounds *) (*((void **) (((u8 *) temp_a3) + 0x20)))) = box;
                      *((u16 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0x62)) = (u16) D_800E0C38; visibleRooms[visibleCount] = temp_a3;
                      visibleCount += 1;
                    }
                    else
                    {
                      char changed = 0;
                      if (box.values[0] < (*((f32 *) (((u8 *) temp_a0) + 0))))
                      {
                        *((f32 *) (((u8 *) temp_a0) + 0)) = box.values[0]; changed = 1;
                      }
                      if (box.values[2] < (*((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 8))))
                      {
                        *((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 8)) = box.values[2]; changed = 1;
                      }
                      if (box.values[1] > (*((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 4))))
                      {
                        *((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 4)) = box.values[1]; changed = 1;
                      }
                      if ((*((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0xC))) < box.values[3])
                      {
                        *((f32 *) (((u8 *) (*((void **) (((u8 *) temp_a3) + 0x20)))) + 0xC)) = box.values[3]; changed = 1;
                      }
                      temp_a0 = *((void **) (((u8 *) temp_a3) + 0x20));
                      if ((*((u16 *) (((u8 *) temp_a0) + 0x62))) != D_800E0C38)
                      {
                        *((u16 *) (((u8 *) temp_a0) + 0x62)) = (u16) D_800E0C38;
                        if (changed != 0)
                        {
                          visibleRooms[visibleCount] = temp_a3;
                          visibleCount += 1;
                        }
                      }
                    }
                  }

                }
              }
              nextRegion:
              portal = *((void **) portal);

            }
            while (portal != NULL);
          }
          for (i = 0; i < visibleCount; i++)
          {
            void *n = visibleRooms[i];
            void *b = *((void **) (((u8 *) n) + 0x20));
            box = *((ClipBounds *) b);
            propagatePortalVisibility(visibleRooms[i], &box);
          }

        }
        while (0);
      }
    }
  }
}
