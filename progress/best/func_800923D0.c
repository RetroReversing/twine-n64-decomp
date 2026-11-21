s32 func_8008CDC0();
s8 func_8008EF18();
s32 func_8008FB20();
s32 func_8008FF80();
s32 func_8008FFF8();
s32 func_8009010C();
s32 func_800902B4();
s32 func_80090464();
s32 func_8009CCB0();
extern void *D_800E5AC0;
extern char D_800E5AC4[];
extern u8 D_800E6A84;
extern char D_800E6A85[];
extern u8 D_800E6A88[];
extern u32 D_800EDA84;
extern u8 D_800EDA87;
extern s8 D_800EDA88;
extern void *D_800EDA8C;
extern s32 D_801002D8;
extern s32 D_8010A514;
typedef struct 
{
  void *field_0;
  unsigned char pad_4[4];
  int field_8;
} R;
typedef struct 
{
  unsigned char pad[292];
  int value;
} T;
void func_800923D0(void)
{
  s32 a;
  s32 b;
  s32 c;
  s32 d;
  register s32 e;
  s32 f;
  s32 e2;
  u32 g;
  unsigned long h;
  u32 i;
  u32 j;
  char *k;
  void **l;
  void *m;
  void *n;
  void *o;
  void *p;
  void *q;
  void *r;
  s32 rv;
  s32 t0;
  if (D_801002D8 != 0)
  {
    j = 0;
    do
    {
      if (((u8 *) &D_800E6A84)[j * 0xFF8] != 0)
      {
        D_800EDA8C = j * 0xFF8 + D_800E5AC4; D_800EDA84 = j; rv = func_8008EF18(D_800E6A88[j * 0xFF8]); n = D_800EDA8C; t0 = *((s32 *) (((char *) n) + 0xF68)); D_800EDA88 = rv;
        if (t0 != 0)
        {
          while ((*((u32 *) (((char *) (*((void **) (((char *) n) + 0xF6C)))) + 0))) != (-1U))
          {
            top: m = *((void **) (((char *) n) + 0xF6C));
            if (((u32) ((*((s32 *) (((char *) n) + 0xF74))) + (*((s32 *) (((char *) n) + 0x120))))) < ((u32) (*((u32 *) (((char *) m) + 0)))))
            {
              break;
            }
            a = *((s32 *) (((char *) m) + 4));
            ((T *) n)->value = a;
            func_8008CDC0(a, D_800EDA87);
            o = *((void **) (((char *) D_800EDA8C) + 0xF6C));
            *((void **) (((char *) D_800EDA8C) + 0xF6C)) = o + 8;
            n = D_800EDA8C;
          }
        }
        n = D_800EDA8C; rv = ((((u32) ((((T *) n)->value * 0xC00U) / 60)) * (((s32) (D_801002D8 << 16)) / ((s32) D_8010A514))) >> 3); g = rv * (*((u16 *) (((char *) n) + 0xFC2))); e = *((s32 *) (((char *) n) + 0xF68)); i = g >> 24;
        *((s32 *) (((char *) n) + 0x118)) = ((g >> 7) >> 1) & 0xFFFF;
        *((u32 *) (((char *) n) + 0x11C)) = i;
        *((s32 *) (((char *) n) + 0x120)) = ((s32) i) >> 1;
        if (((unsigned) e) != 0)
        {
          h = *((s32 *) (((char *) n) + 0xF70)) + (*((s32 *) (((char *) n) + 0x118))); a = h & 0xFFFF; *((s32 *) (((char *) n) + 0xF70)) = a; m = (*((void **) (((char *) n) + 0x11C))); *((s32 *) (((char *) n) + 0xF74)) += (h >> 16) + (u32) m;
        }
        d = func_80090464(); c = func_8008FB20();
        func_8009010C();
        func_800902B4();
        func_8008FF80();
        b = func_8008FFF8(); q = *((void **) (((char *) D_800EDA8C) + 0xF7C));
        if (q != NULL)
        {
          do
          {
            r = ((R *) q)->field_0;
            if (func_8009CCB0(((R *) q)->field_8) == (-1))
            {
              p = ((R *) q)->field_0;
              if (p != NULL)
              {
                *((void ***) (((char *) p) + 4)) = (void **) (*((void ***) (((char *) q) + 4)));
              }
              l = *((void ***) (((char *) q) + 4));
              if (l != NULL)
              {
                *l = ((R *) q)->field_0;
              }
              else
              {
                *((void **) (((char *) D_800EDA8C) + 0xF7C)) = ((R *) q)->field_0;
              }
              ((R *) q)->field_0 = (void *) D_800E5AC0;
              if (D_800E5AC0 != NULL)
              {
                *((void ***) (((char *) D_800E5AC0) + 4)) = q;
              }
              *((void ***) (((char *) q) + 4)) = NULL; D_800E5AC0 = q;
            }
            q = r;
          }
          while (q != NULL);
        }
        if (((!(d & 0xFF)) & (!(c & 0xFF))) && (!(b & 0xFF)))
        {
          ((u8 *) &D_800E6A84)[j * 0xFF8] = 0;
          D_800E6A85[j * 0xFF8] = 1;
        }
      }
      j++;
    }
    while (8U > j);
  }
}

