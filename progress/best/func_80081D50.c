#define E(n) arg0[(u16)(n)]
typedef struct 
{
  s8 idx;
  u8 flags;
  u16 mask;
  u16 val;
  u8 type;
  u8 pad;
} SlotEnt;
typedef struct 
{
  u8 a;
  u8 b;
} SlotOut;
typedef struct 
{
  u8 first;
  u8 pad[0x9F];
} BonusEnt;
u16 func_8002D0BC(s32, s32);
extern u16 D_800C9D40;
extern u8 D_800CEEB0;
extern s32 D_80112E98[];
extern BonusEnt sBonusSlots[];
inline static u8 inline_fn(SlotOut *arg0, s32 arg1)
{
  return arg0[arg1].a;
}

inline static SlotEnt *inline_fn2(u16 arg0, int arg1, u32 arg2)
{
  return (SlotEnt *) ((arg0 * arg1) + arg2);
}

inline static int inline_fn23(int arg0)
{
  return arg0;
}

inline static u8 inline_fn234(SlotOut *arg0, s32 arg1)
{
  return arg0[arg1].a;
}

void func_80081D50(SlotEnt *arg0, u8 arg1, s32 arg2, SlotOut *arg3)
{
  s32 i = 0;
  s32 idx;
  u8 bonus;
  u16 a2;
  u8 v;
  u8 v_web;
  u16 ii;
  SlotOut *o;
  SlotEnt *e;
  s32 t1;
  s32 t1_web;
  s32 t2;
  s32 s1;
  s32 s1_web;
  s32 t3;
  s32 one;
  if (arg0[0].idx == (-1))
  {
    return;
  }
  {
    do
    {
      {
        ii = i;
        e = (SlotEnt *) ((ii * sizeof(*arg0)) + (u32) arg0);
        idx = e->idx;
        s1 = 0;
        if ((D_800CEEB0 == 2) || ((u16) func_8002D0BC(0xA3, arg1 & 0xFF)))
        {
          a2 = 0;
          if (((volatile SlotEnt *) e)->flags & 0x10)
          {
            a2 = sBonusSlots[arg1 & 0xFF].first;
          }
          {
            {
              t3 = (E(i).mask != 0); t1 = t3 | inline_fn23(a2 != 0);
            }
          }
          if (t1)
          {
            t2 = (arg2 & E(i).mask) != 0;
            t2 ^= E(i).flags & 1;
            if ((t2 == 0) & (a2 == 0))
            {
              goto update;
            }
          }
          {
            if ((E(i).val != 0) || (E(i).type != 0))
            {
              if (E(i).type != 0)
              {
                s1 = D_80112E98[E(i).type];
              }
              else
              {
                t1_web = (u16) a2;
    s1 = (arg2 & E(i).val) | t1_web;
              }
              if (E(i).flags & 8)
              {
                if (s1 == E(i).val)
                {
                  s1 = 1;
                }
                else
                {
                  s1 = 0;
                }
              }
              if (E(i).flags & 2)
              {
                arg3[idx].a |= 0x20;
              }
              else
              {
                arg3[idx].a &= 0xDF;
              }
            }
            else
            {
              o = (SlotOut *) ((((unsigned int) idx) * ((unsigned int) (sizeof(*arg3)))) + ((unsigned int) arg3)); o->b = (E(i).flags & 4) ? (2) : (1);
              do
              {
                o->a = (E(i).flags & 2) ? (o->a | 0x40) : (o->a & 0xBF);
              }
              while (0);
            }
          }
        }
        update:
        s1 = s1 != 0;

        D_800C9D40 |= s1; v = inline_fn(arg3, idx);
        arg3[idx].a = (((v & 1) ^ s1) & s1) ? (v | 2) : (v & 0xFD);
        if (s1)
        {
          arg3[idx].a |= 1;
        }
        else
        {
          arg3[idx].a &= 0xFE;
        }
        arg3[idx].a |= s1 ? 8 : 0;
        if (s1) one = 1; else if (!s1) one = 1; else one = 0;
        if (!one) goto advance;
        v = ((volatile SlotOut *) arg3)[idx].a;
        s1_web = (v >> 2) & 1; t2 = s1_web ^ ((v >> 3) & 1);
        if ((v & 8) && (t2 & 1))
        {
          arg3[idx].a = v | 0x10;
        }
        else
        {
          arg3[idx].a &= 0xEF;
        }
        v_web = inline_fn234(arg3, idx);
        arg3[idx].a = (v_web & 8) ? (v_web | 4) : (v_web & 0xFB);
        arg3[idx].a &= 0xF7;
        advance: ;
      }
      i++;
    }
    while (E(i).idx != (-1));
  }
}



