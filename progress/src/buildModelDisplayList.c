#define FLD(p, t, o) (*(t *)((u8 *)(p) + (o)))
extern u8 D_54D910[];
extern u8 gAssetSlotHeader[];
extern s8 gTextureRegisterPending;
void func_8000B9B8(u8 *, s32, u32);
void stubNoopHook(void);
void noopStubTrackModel(void);
s32 getDecompressedSize(s32 *);
s32 getEdlFirstWord(void *);
s32 decompressData(s32 *, s32 *);
s32 setGfxAndVertexPtrs(void *, s32 *);
s32 emitModelDisplayListFromStream(s32 *, s32 *, s32 *, s32 *, s32, f32, s32, s32, s32, s32 *, s32 *);
s32 *func_80083E90(s32, s32);
s32 func_80084048(s32 *, s32);
inline static s32 inline_fn(u8 *arg0)
{
  return getEdlFirstWord(arg0);
}

/* Loads a model's data from ROM (decompressing chunks as needed), builds its display list into the model's first field, and frees the temporary buffers. */
void buildModelDisplayList(void *model)
{
  u8 header[0x20];
  u8 chunkHeader[0x20];
  s32 sp70;
  s32 sp74;
  s32 *recordEnd;
  s32 *sp7C;
  s32 *sp84;
  s32 *sp8C;
  f32 posScale;
  union 
  {
    s32 *pointer;
    s32 value;
  } __repair_phase_storage;
  s32 *t34;
  s32 *temp_s1;
  s32 *temp_s2;
  s32 *temp_s6;
  s32 *temp_t0;
  s32 *temp_v0_3;
  s32 *temp_v0_7;
  s32 *temp_v0_9;
  s32 *var_fp;
  s32 *var_s2;
  s32 *var_s3;
  s32 *var_s5;
  s32 *var_s7;
  s32 temp_s6_2;
  s32 temp_v0_2;
  s32 temp_v0;
  s32 temp_v0_4;
  s32 temp_v0_6;
  u8 *temp_v0_8;
  {
    if (model != NULL)
    {
      var_s5 = NULL;
      var_s7 = NULL; sp7C = NULL; posScale = 1.0f;
      if ((*((u8 *) (((u8 *) model) + 0x48))) & 0x10)
      {
        posScale = 64.0f;
      }
      stubNoopHook();
      func_8000B9B8(header, D_54D910 + (*((s32 *) (((u8 *) model) + 4))), 0x20);
      t34 = *((s32 **) (((u8 *) model) + 0x34));
      if (t34 == NULL)
      {
      var_s5 = func_80083E90((*((u16 *) (((u8 *) header) + 4))) * 0x18, 0x2D);
      if (var_s5 == NULL) { goto block_24; }
        recordEnd = (s32 *) (((u8 *) var_s5) + ((*((u16 *) (((u8 *) header) + 4))) * 0xC));
        func_8000B9B8(chunkHeader, D_54D910 + (*((s32 *) (((u8 *) header) + 0))), 0x20);
        temp_v0 = getEdlFirstWord(chunkHeader);
        if (temp_v0 == 0)
        {
          sp8C = var_s5;
          func_8000B9B8(var_s5, D_54D910 + (*((s32 *) (((u8 *) header) + 0))), (*((u16 *) (((u8 *) header) + 4))) * 0xC);
        }
        else
        {
          func_8000B9B8(var_s5, D_54D910 + (*((s32 *) (((u8 *) header) + 0))), temp_v0);
          sp8C = recordEnd;
          {
            getDecompressedSize(var_s5);
          }
          decompressData(recordEnd, var_s5);
        }
      }
      else
      {
        sp8C = t34;
      }
        temp_v0_3 = func_80083E90((*((u16 *) (((u8 *) header) + 0x14))) * 8 + (temp_v0_2 = (*((u16 *) (((u8 *) header) + 0x0C))) * 4) + temp_v0_2 + (*((u16 *) (((u8 *) header) + 0x1C))) + (temp_v0_2 & 3), 0x2D);

        if (temp_v0_3 != NULL)
        {
          var_s7 = temp_v0_3; sp84 = &var_s7[*((u16 *) (((u8 *) header) + 0x14))]; temp_s1 = &sp84[*((u16 *) (((u8 *) header) + 0x14))]; temp_s2 = &temp_s1[*((u16 *) (((u8 *) header) + 0x0C))]; temp_s6 = &temp_s2[*((u16 *) (((u8 *) header) + 0x0C))];
          func_8000B9B8(chunkHeader, D_54D910 + (*((s32 *) (((u8 *) header) + 8))), 0x20);
          temp_v0_4 = getEdlFirstWord(chunkHeader);
          if (temp_v0_4 == 0)
          {
            func_8000B9B8(temp_s1, D_54D910 + (*((s32 *) (((u8 *) header) + 8))), (*((u16 *) (((u8 *) header) + 0x0C))) * 4);
            var_fp = temp_s1;
          }
          else
          {

            func_8000B9B8(temp_s1, D_54D910 + (*((s32 *) (((u8 *) header) + 8))), temp_v0_4);
            getDecompressedSize(temp_s1);
            decompressData(temp_s2, temp_s1);
            var_fp = temp_s2;
          }
          func_8000B9B8(chunkHeader, D_54D910 + (*((s32 *) (((u8 *) header) + 0x10))), 0x20);
          temp_v0 = inline_fn(chunkHeader);
          if (temp_v0 == 0)
          {
            func_8000B9B8(var_s7, D_54D910 + (*((s32 *) (((u8 *) header) + 0x10))), (*((u16 *) (((u8 *) header) + 0x14))) * 4);
            var_s3 = var_s7;
          }
          else
          {
            func_8000B9B8(var_s7, D_54D910 + (*((s32 *) (((u8 *) header) + 0x10))), temp_v0);
            getDecompressedSize(var_s7);
            var_s3 = sp84;
            decompressData(var_s3, var_s7);
          }
          func_8000B9B8(chunkHeader, D_54D910 + (*((s32 *) (((u8 *) header) + 0x18))), 0x20);
          temp_v0 = inline_fn(chunkHeader);
          if (temp_v0 == 0)
          {
            func_8000B9B8(temp_s6, D_54D910 + FLD(header, s32, 0x18), FLD(header, u16, 0x1C));
            var_s2 = temp_s6;
            goto block_21;
          }
          func_8000B9B8(temp_s6, D_54D910 + (*((s32 *) (((u8 *) header) + 0x18))), temp_v0);
          temp_v0_7 = func_80083E90(getDecompressedSize(temp_s6), 0x2D); sp7C = temp_v0_7;
          if (temp_v0_7 != NULL)
          {
            decompressData(sp7C, temp_s6);
            var_s2 = sp7C;
            block_21:
            temp_v0_8 = *((u8 **) (gAssetSlotHeader + ((*((u16 *) (((u8 *) model) + 0x30))) & 0xFFF0)));

            sp70 = 0; sp74 = 0; temp_s6_2 = *((s32 *) (((u8 *) temp_v0_8) + 0x10)); __repair_phase_storage.value = *((s32 *) (((u8 *) temp_v0_8) + 0x18));
            emitModelDisplayListFromStream(var_s2, sp8C, var_fp, var_s3, *((u8 *) (((u8 *) model) + 0x45)), posScale, __repair_phase_storage.value, temp_s6_2, 0, &sp70, &sp74);
            temp_v0_9 = func_80083E90((sp70 * 0x10) + (sp74 * 8), 0x2E);
            if (temp_v0_9 != NULL)
            {
              setGfxAndVertexPtrs(((u8 *) temp_v0_9) + (sp74 * 8), temp_v0_9);
              *((s32 **) (((u8 *) model) + 0)) = temp_v0_9;
              emitModelDisplayListFromStream(var_s2, sp8C, var_fp, var_s3, *((u8 *) (((u8 *) model) + 0x45)), posScale, __repair_phase_storage.value, temp_s6_2, 1, NULL, NULL);
              if (gTextureRegisterPending != 0)
              {
                *((u8 *) (((u8 *) model) + 0x46)) |= 0x80;
              }
            }
            goto block_24;
          }
        }
        else
        {
          goto block_24;
        }
        block_24:
        if (sp7C != NULL)
        {
          func_80084048(sp7C, 0x2D);
        }

      if ((*((s32 **) (((u8 *) model) + 0x34))) == NULL)
      {
        do
        {
          func_80084048(var_s5, 0x2D);
        }
        while (0);
      }
      if (var_s7 != NULL)
      {
        func_80084048(var_s7, 0x2D);
      }
      noopStubTrackModel();
    }
  }
}
