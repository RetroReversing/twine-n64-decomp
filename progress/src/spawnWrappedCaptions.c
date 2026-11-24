inline static s8 __repair_inline(s8 a)
{
  return a;
}

s32 spawnCaptionMessage(s32, s32, s8 *, s32, s32, s32, s32, s32, s32, s32, s32);
s32 wrapCaptionLine(s8 *, s32);
volatile unsigned int appendString(s8 *, s8 *);
volatile unsigned int memcpy(s8 *, s8 *, s32);
extern s8 D_800D4870;
extern void *gCaptionMessages;
extern u16 gCaptionMessageCount;
extern s32 gTrackMarkerSerial;
inline static s8 inline_fn(char arg0)
{
  return (s8) arg0;
}

inline static int inline_fn2(s32 arg0, s32 arg1)
{
  return arg0 | (arg1 == '\n');
}

inline static s8 inline_fn23(u8 arg0)
{
  return inline_fn(arg0);
}

inline static int inline_fn234(s32 arg0, s32 arg1)
{
  return arg0 >= arg1;
}

/* Word-wraps text into caption lines, spawns a caption message per line, then sets each one's timing and scale. */
void spawnWrappedCaptions(s32 actorId, u8 *text, s32 maxLineLen, s32 maxLineChars, f32 totalDuration, s32 flags)
{
  char lineBuf[0x200];
  s8 wrapped[0x208];
  f32 var_fv1;
  f32 scale;
  union 
  {
    s32 *pointer;
    s32 value;
  } __repair_phase_storage;
  s32 temp_s0;
  s32 temp_v0_3;
  s32 var_a2;
  s32 var_a2_late;
  s32 var_a0_2;
  s32 var_a3;
  s32 var_t1;
  s32 temp_a1;
  s8 *line;
  s8 *dst;
  s8 temp_v0;
  s32 temp_v0_2;
  s32 var_v0;
  u8 *src;
  u8 var_a0;
  char var_v1;
  char current;
  void **var_a0_3;
  void *temp_v0_4;
  void *temp_v0_5;
  src = text;
  wrapped[0] = 0;
  var_a0 = *src;
  if (inline_fn23(*src) != 0)
  {
    do
    {
      dst = lineBuf;
      var_t1 = 0;
      var_a3 = 0;
      var_v1 = var_a0;
      if (var_a0 != 0)
      {
        for (;;)
        {
          current = var_v1;
          if (current != 0)
          {
            var_a2 = 0;
            if ((((inline_fn(var_v1) == 0x2E) | (inline_fn23(var_v1) == 0x21)) != 0) || (((s8) var_v1) == 0x3F))
            {
              var_a2 = 1;
            }
            if (var_t1 != 0)
            {
              src += 1;
              if (var_a2 != 0)
              {
                goto block_14;
              }
              else
              {
              }
            }
            else
            {
              if (var_a2 != 0)
              {
                if (var_a3 < (maxLineLen / 2))
                {
                  goto copy_next;
                }
                var_t1 = 1;
              }
              copy_next:
              src += 1;

              block_14:
              *dst = current;

              var_v1 = *src;
              dst += 1;
              var_a3 += 1;
              if (var_v1 != 0)
              {
                continue;
              }
            }
          }
          break;
        }

      }
      *dst = 0;
      wrapCaptionLine(lineBuf, maxLineLen);
      if (wrapped[0] != 0)
      {
        appendString(wrapped, &D_800D4870);
      }
      appendString(wrapped, lineBuf);
      var_a0 = (u8) (*src);
    }
    while ((*((s8 *) src)) != 0);
  }
  gCaptionMessageCount = 0;
  line = wrapped;
  if (wrapped[0] != 0)
  {
    s8 *buffer = lineBuf;
    while (*line != 0)
    {
      var_a0_2 = 0;
      var_v0 = *line;
      temp_a1 = (s32) line;
      if (inline_fn2(var_v0 == 0, var_v0) == 0)
      {
        goto scan;
      }
      goto advance;
      emit:
      temp_s0 = line - ((s8 *) temp_a1);

      memcpy(buffer, ((s8 *) temp_a1), temp_s0);
      buffer[temp_s0] = 0;
      gTrackMarkerSerial++;
      temp_v0_3 = spawnCaptionMessage(0, actorId, buffer, -1, -1, 1, 0, 0, flags & 0xFF, 0, 0x1E);
      {
        u16 index = gCaptionMessageCount;
        s32 *entries = (s32 *) (&gCaptionMessages);
        u16 next = index + 1;
        __repair_phase_storage.pointer = (s32 *) ((((s32) (index << 16)) >> 14) + ((s8 *) entries));
        gCaptionMessageCount = next;
        *__repair_phase_storage.pointer = temp_v0_3;
      }
      goto advance;
      while (line != ((s8 *) temp_a1))
      {
        ++var_a0_2;
        if (var_a2_late | inline_fn234(var_a0_2, maxLineChars))
        {
          goto emit;
        }
        scan:
        ++line;

        scan_byte:
        temp_v0_2 = *line;

        var_a2_late = temp_v0_2 == 0;
        if (inline_fn2(var_a2_late, temp_v0_2) == 0)
        {
          ++line;
          goto scan_byte;
        }
      }

      advance:
      line += (*line) != 0;

    }
  }
  var_a0_2 = (s16) gCaptionMessageCount;
  if (var_a0_2 != 0)
  {
    var_fv1 = totalDuration / ((f32) var_a0_2);
    var_fv1 = var_fv1 * 30.0f;
    var_fv1 = var_fv1 - 15.0f;
    if (var_fv1 < 1.0f)
    {
      var_fv1 = 1.0f;
    }
    __repair_phase_storage.value = 0;
    if (var_a0_2 > 0)
    {
      var_a2 = (s32) var_fv1;
      scale = 4096.0f;
      temp_a1 = var_a0_2;
      do
      {
        temp_v0_4 = ((void **) &gCaptionMessages)[__repair_phase_storage.value];
        if (temp_v0_4 != NULL)
        {
          temp_v0_5 = *((void **) (((char *) temp_v0_4) + 0x6C));
          *((s16 *) (((char *) temp_v0_5) + 0x30)) = (s16) var_a2;
          *((f32 *) (((char *) temp_v0_5) + 0x14)) = (f32) (scale / var_fv1);
        }
        __repair_phase_storage.value += 1;
      }
      while (__repair_phase_storage.value < temp_a1);
    }
  }
}
