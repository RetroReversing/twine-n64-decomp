#define FLD(p, t, o) (*(t *)((u8 *)(p) + (o)))
#define BE16(p) ((u16)(((p)[0] << 8) | (p)[1]))
void buildPlaneFromPoints(void *, s32, s32, s32);
inline static int inline_fn(u8 *arg0, u8 arg1)
{
  return arg0[arg1] & 0xFF;
}

inline static int inline_fn2()
{
  return -1;
}

inline static u8 *inline_fn23(u8 *arg0)
{
  return arg0 + 2;
}

/* Interprets a mesh command stream (vertex tables in several index formats, triangle and quad lists), copying triangle indices out and building a plane per triangle. */
void buildCollisionPlanesFromCommands(void *mesh, u8 *cmdStream, s16 *planeFlags)
{
  register u8 *cmd = cmdStream;
  register s16 *flagOut = planeFlags;
  register unsigned long indexFormat = 3;
  u8 *vertexData = NULL;
  s16 *indexOut16 = NULL;
  u8 *indexOut8 = NULL;
  s16 *var_s4;
  u8 op;
  register u8 triCount;
  u32 triIndex;
  u8 *var_s3;
  s32 a3_2;
  s32 v1_2;
  s32 a2;
  s32 a2_c;
  s32 __repair_result_a2;
  s32 __repair_phase_v1;
  s32 __repair_phase___repair_phase_v1;
  unsigned int base;
  unsigned int __repair_phase_base;
  u32 plane[3];
  u32 unused[2];
  register unsigned long tmp8;
  u16 t16_2;
  u16 t16_default;
  long t16_arm;
  u16 __repair_result_t16;
  u16 t16b_2;
  u16 t16b_default;
  u16 t16b_arm;
  u16 __repair_result_t16b;
  u16 t16c;
  if ((*((u8 *) (((u8 *) mesh) + 0x48))) & 4)
  {
    indexOut16 = *((s16 **) (((u8 *) mesh) + 0x3C));
  }
  else
  {
    indexOut8 = *((u8 **) (((u8 *) mesh) + 0x3C));
  }
  goto loop_48;
  dispatch:
  switch (op)
  {
    do
    {
      case 9:
        cmd += 4;

      goto loop_48;
      case 0:
        vertexData = inline_fn23(cmd);

      ++cmd;
      indexFormat = 0; cmd += 1 + (cmd[0] * 3);
      goto loop_48;
      do
      {
        case 1:
          vertexData = cmd + 2;

        ++cmd;
        indexFormat = 1; cmd += 1 + (cmd[0] * 6);
        goto loop_48;
        case 3:
          vertexData = inline_fn23(cmd);

        ++cmd;
        indexFormat = 3; cmd += 1 + (cmd[0] * 1);
        goto loop_48;
        case 2:
          if (vertexData)
        {
          vertexData = cmd + 2;
          ++cmd;
          indexFormat = 2;
          cmd += 1 + (cmd[0] * 2);
          goto loop_48;
        }
        else
        {
          vertexData = cmd + 2;
          ++cmd;
          indexFormat = 2;
          cmd += 1 + (cmd[0] * 2);
          goto loop_48;
        }

        case 6:
        {
          u8 value = cmd[1];
          if ((cmd || vertexData) != 0.0f)
          {
            cmd += 2;
            *((u8 *) (((u8 *) mesh) + 0x44)) = value;
          }
          else
          {
            cmd += 2;
            *((u8 *) (((u8 *) mesh) + 0x44)) = value;
          }
        }

        goto block_15;
        case 7:
        {
          u8 value = cmd[1];
          ++cmd;
          *((u8 *) (((u8 *) mesh) + 0x44)) = value;
          goto block_15;
        }

        case 8:
          cmd += 3;

        case 5:
          block_15:
        triCount = cmd[1];


        cmd += 2; triIndex = 0;
        if (triCount)
        {
                    do
          {
            if (1)
            {
              switch (indexFormat)
              {
                case 3:
                {
                  u8 first = vertexData[cmd[0]];
                  u8 second;
                  *indexOut8 = first; second = vertexData[cmd[1]];
                  indexOut8[1] = second;
                  tmp8 = vertexData[cmd[2]]; a2 = first & 0xFF;
                  a2_c = second & 0xFF;
                  v1_2 = tmp8 & 0xFF;
                  indexOut8[2] = tmp8; indexOut8 += 3;
                  goto after;
                }

                case 2:
                  t16_2 = BE16(vertexData + (cmd[0] * 2));
                  *indexOut16 = t16_2;
                  t16b_2 = BE16(vertexData + (cmd[1] * 2));
                  indexOut16[1] = t16b_2;
                  a2 = t16_2 & 0xFFFF;
                  tmp8 = cmd[2];
                  t16c = BE16(vertexData + (tmp8 * 2));
                  v1_2 = t16c & 0xFFFF;
                  a2_c = t16b_2 & 0xFFFF;
                  indexOut16[2] = t16c; indexOut16 += 3;
                  break;

                case 0:
                {
                  u8 first = vertexData[cmd[0] * 3];
                  u8 second;
                  *indexOut8 = first; second = vertexData[cmd[1] * 3];
                  indexOut8[1] = second;
                  tmp8 = vertexData[cmd[2] * 3]; a2 = first & 0xFF;
                  a2_c = second & 0xFF;
                  v1_2 = tmp8 & 0xFF;
                  indexOut8[2] = tmp8; indexOut8 += 3;
                  goto after;
                }

                default:
                  t16_default = BE16(vertexData + (cmd[0] * 6));
                  *indexOut16 = t16_default;
                  t16b_default = BE16(vertexData + (cmd[1] * 6));
                  indexOut16[1] = t16b_default;
                  a2 = t16_default & 0xFFFF;
                  tmp8 = cmd[2] * 3;
                  t16c = BE16(vertexData + (tmp8 * 2));
                  a2_c = t16b_default & 0xFFFF;
                  v1_2 = t16c & 0xFFFF;
                  indexOut16[2] = t16c; indexOut16 += 3;
                  break;

              }

              after:
              buildPlaneFromPoints(&plane, *((s32 *) (((u8 *) mesh) + 0x34)) + (a2 * 12), *((s32 *) (((u8 *) mesh) + 0x34)) + (a2_c * 12), *((s32 *) (((u8 *) mesh) + 0x34)) + (v1_2 * 12));
              cmd += 3; triIndex += 1;
              *flagOut = 0;
              flagOut++;
            }
          }
          while (triIndex < triCount);
        }
        goto loop_48;
        case 4:
          do
        {
          switch (indexFormat)
          {
            case 3:
            {
              u8 first = vertexData[cmd[1]];
              u8 second;
              indexOut8[0] = first; second = vertexData[cmd[2]];
              indexOut8[1] = second;
              tmp8 = vertexData[cmd[3]]; a2 = first & 0xFF;
              a2_c = second & 0xFF;
              v1_2 = tmp8 & 0xFF;
              indexOut8[2] = tmp8;
              indexOut8 += 3;
            }
              break;

            case 2:
              __repair_phase_v1 = (u16) BE16(vertexData + (cmd[1] * 2));
              indexOut16[0] = __repair_phase_v1;
              __repair_result_t16b = BE16(vertexData + (cmd[2] * 2));
              indexOut16[1] = __repair_result_t16b;
              tmp8 = cmd[3];
              a2 = __repair_phase_v1 & 0xFFFF;
              t16c = BE16(vertexData + (tmp8 * 2));
              a2_c = __repair_result_t16b & 0xFFFF;
              v1_2 = t16c & 0xFFFF;
              indexOut16[2] = t16c;
              indexOut16 += 3;
              break;

            case 0:
            {
              u8 first = vertexData[cmd[1] * 3];
              indexOut8[0] = first; a2 = first;
            }
              __repair_phase___repair_phase_v1 = vertexData[cmd[2] * 3];
              indexOut8[1] = (u8) __repair_phase___repair_phase_v1;
              tmp8 = vertexData[cmd[3] * 3];
              __repair_result_a2 = inline_fn(vertexData, cmd[1] * 3);
              a2_c = __repair_phase___repair_phase_v1 & 0xFF;
              v1_2 = tmp8 & 0xFF;
              indexOut8[2] = tmp8;
              indexOut8 += 3;
              break;

            default:
            {
              t16_arm = BE16(vertexData + (cmd[1] * 6)); indexOut16[0] = t16_arm; t16b_arm = BE16(vertexData + (cmd[2] * 6)); indexOut16[1] = t16b_arm; tmp8 = cmd[3] * 3; a2 = t16_arm & 0xFFFF; t16c = BE16(vertexData + (tmp8 * 2)); v1_2 = t16c & 0xFFFF; a2_c = t16b_arm & 0xFFFF; indexOut16[2] = t16c; indexOut16 += 3;
            }
              break;

          }

          buildPlaneFromPoints(&plane, *((s32 *) (((u8 *) mesh) + 0x34)) + (a2 * 12), *((s32 *) (((u8 *) mesh) + 0x34)) + (a2_c * 12), *((s32 *) (((u8 *) mesh) + 0x34)) + (v1_2 * 12));
          cmd += 4;
          *flagOut = 0;
        flagOut++;
        }
        while (0);

        goto loop_48;
        case 10:
          *((u8 *) (((u8 *) mesh) + 0x44)) = cmd[1];

        cmd += 2;
        goto loop_48;
        case 11:
          cmd += 2;

        goto loop_48;
        default:
          goto loop_48;

      }
      while (0);
    }
    while (0);
  }


  loop_48:
  op = cmd[0];
  if (op != 12)
  {
    {
      long long phantom_wide = indexFormat;
    }
    goto dispatch;
  }

}
