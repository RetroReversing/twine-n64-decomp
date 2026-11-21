s32 func_8000A3AC(void);
extern s32 D_800E1098;
extern s32 D_801002C0;
extern s32 D_801007C8;
extern s32 D_80102ED8;
extern u8 D_80102EDD;
extern u8 D_8010A4C1;
extern u8 D_8010A4C2;
void func_800265AC(s32 arg0, s32 arg1, const u8 *arg2, const s32 *arg3)
{
  s32 *var_a3;
  s32 var_a0;
  s32 var_a1;
  s32 var_a1_2;
  u8 *var_a2;
  var_a0 = arg0;
  var_a1 = arg1;
  var_a2 = arg2;
  var_a3 = arg3;
  *((u8 *) (((char *) (&D_8010A4C1)) + 0)) = 0;
  *((s8 *) (((char *) (&D_8010A4C1)) + 1)) = 0;
  if (D_80102ED8 != 0)
  {
    s32 *limit = &D_801002C0;
    s32 i = 0;
 do { if ((*limit) > 0) { u8 *flags = &D_8010A4C1; s32 one = 1; do { s32 bit = one << i; s32 end = *limit; i++; *flags |= bit; if (((u16) i) >= end) { break; } } while (1); } } while (0);
    limit = &D_801002C0;
    i = 0;
    if ((*limit) > 0)
    {
      u8 *flags = &D_8010A4C2;
      s32 one = 1;
      do
      {
        s32 bit = one << i;
        s32 end = *limit;
        i++;
        *flags |= bit;
        if (((u16) i) >= end)
        {
          break;
        }
      }
      while (1);
    }
    {
      u8 *flags = &D_8010A4C2;
      *flags |= 0x30;
    }
  }
  else
  {
    *((s8 *) (((char *) (&D_8010A4C1)) + 1)) = 1;
    *((u8 *) (((char *) (&D_8010A4C1)) + 0)) = 1;
    *((s8 *) (((char *) (&D_8010A4C1)) + 1)) = 0x21;
  }
  func_8000A3AC();
  if (D_80102EDD != 0)
  {
    typedef struct 
    {
      s32 words[4];
    } State;
    *((State *) (&D_801007C8)) = *((State *) (&D_800E1098));
  }
}
