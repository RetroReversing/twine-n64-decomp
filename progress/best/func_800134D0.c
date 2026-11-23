extern u8 D_800B269F[];
extern u8 D_800B26BF[];
extern u16 D_800B27E0[];
extern s8 D_800B281C[];
extern u32 D_800B283C[];
extern u32 D_800B2CB8[];
extern u32 D_800B3134[];
extern u16 D_801032B0[];
extern u16 D_80108970[];
extern u8 D_80108FA0[];
extern u32 D_80112EE0[];

#define RD(dst, n, mask) \
  bits -= (n); \
  if (bits < 0) { \
    dst = word; word = nxt; nxt = *p++; \
    dst = (dst + (word << (bits + (n)))) & (mask); \
    word >>= -bits; bits += 32; \
  } else { \
    dst = word & (mask); word >>= (n); \
  }

void func_800134D0(void *arg0)
{
  u8 *out;
  u32 *p;
  u32 word;
  u32 nxt;
  s32 bits;
  u16 *tab;
  s32 phase;
  u32 a;
  s32 n;
  u32 cnt;
  u32 i;
  u32 k;
  u32 m;
  u32 c;
  u32 sp1C;
  u32 tb;
  u32 e;
  u32 v;
  u32 sym;
  u32 len;
  u32 dist;
  u32 x;
  u8 *src;
  u32 *q1;
  u32 *q2;
  u32 *q3;
  u32 *q4;
  u32 *r;
  u32 *H;

  out = *(u8 **)((char *)arg0 + 0);
  sp1C = 0;
  H = D_80112EE0;
  p = *(u32 **)((char *)arg0 + 4);
  word = ((u32 *)p)[3];
  nxt = ((u32 *)p)[4];
  p = p + 5;
  bits = 0x20;
  do {
    RD(a, 1, 1);
    if (a == 0) {
      RD(n, 15, 0x7FFF);
      if (n-- != 0) {
        do {
          RD(a, 8, 0xFF);
          *out++ = a;
        } while (n-- != 0);
      }
    } else {
      phase = 1;
      do {
        tab = D_80108970;
        tb = 8;
        if (phase-- != 0) {
          tab = D_801032B0;
          tb = 10;
        }
        RD(a, 9, 0x1FF);
        if (a != 0) {
          cnt = a;
          for (i = 1; i < 0x21; i++) {
            H[i] = 0;
          }
          i = 0;
          q1 = D_800B283C;
          do {
            RD(a, 1, 1);
            if (a == 1) {
              RD(sp1C, 4, 0xF);
            }
            *q1 = sp1C;
            H[sp1C] += 1;
            i++;
            q1++;
          } while (i < cnt);
          D_80112EE0[0] = 0;
          k = 0;
          for (c = 1; c < 16; c++) {
            if (cnt != 0) {
              u32 j;
              j = 0;
              q1 = D_800B283C;
              r = D_800B3134 + k;
              do {
                if (*q1 == c) {
                  *r++ = j;
                  k++;
                }
                j++;
                q1++;
              } while (j < cnt);
            }
          }
          k = 0;
          for (c = 1; c < 16; c++) {
            i = 1;
            if (H[c] != 0) {
              r = D_800B283C + k;
              do {
                *r++ = c;
                i++;
                k++;
              } while (H[c] >= i);
            }
          }
          D_800B283C[k] = 0;
          c = D_800B283C[0];
          i = 0;
          k = 0;
          if (c != 0) {
            u32 off = 0;
            q2 = D_800B283C;
            do {
              if (*q2 == c) {
                u32 hb = 1 << c;
                u32 *s = D_800B283C + k;
                do {
                  u32 mm = i | hb;
                  i++;
                  D_800B2CB8[k] = 0;
                  do {
                    u32 bit = mm & 1;
                    mm >>= 1;
                    D_800B2CB8[k] = D_800B2CB8[k] * 2 + bit;
                  } while (mm != 1);
                  s++;
                  off += 4;
                  q2++;
                  k++;
                } while (*s == c);
              }
              i *= 2;
              c++;
            } while (*(u32 *)((char *)D_800B283C + off) != 0);
            i = 0;
          }
          {
            u8 *bz = D_80108FA0;
            do {
              *bz++ = 0;
              i++;
            } while ((i >> tb) == 0);
          }
          k = 0;
          c = 1;
          if (c < tb) {
            u32 off = 4;
            q3 = H + 1;
            do {
              i = 1;
              if (*q3 != 0) {
                u32 t5 = 1 << c;
                u32 *lim = (u32 *)((char *)H + off);
                do {
                  u32 ix = D_800B2CB8[k];
                  do {
                    tab[ix] = (D_800B3134[k] << 7) + c;
                    ix += t5;
                  } while ((ix >> tb) == 0);
                  i++;
                  k++;
                } while (*lim >= i);
              }
              off += 4;
              c++;
              q3++;
            } while (c < tb);
          }
          m = k;
          if (c < 16) {
            u32 mk = (1 << tb) - 1;
            u32 off = c * 4;
            q3 = H + c;
            do {
              i = 1;
              if (*q3 != 0) {
                u32 *lim = (u32 *)((char *)H + off);
                do {
                  u32 ix = D_800B2CB8[k] & mk;
                  u32 sv = D_800B283C[k];
                  i++;
                  if (D_80108FA0[ix] < sv) {
                    D_80108FA0[ix] = sv;
                  }
                  k++;
                } while (*lim >= i);
              }
              off += 4;
              c++;
              q3++;
            } while (c < 16);
          }
          {
            u32 acc = 0;
            u8 *bp = D_80108FA0;
            u16 *tp = tab;
            i = 0;
            do {
              u8 b = *bp;
              if (b != 0) {
                if ((u32)(b - tb) < 8) {
                  *tp = (acc << 7) + ((b - tb) << 4);
                  acc += 1 << (*bp - tb);
                } else {
                  *(s32 *)((char *)arg0 + 0x1C) = -8;
                  return;
                }
              }
              bp++;
              i++;
              tp++;
            } while ((i >> tb) == 0);
            c = tb;
            if (acc >= 0x200) {
              *(s32 *)((char *)arg0 + 0x1C) = -9;
              return;
            }
            k = m;
            if (c < 16) {
              u32 t5 = 1 << c;
              u32 mask = t5 - 1;
              u32 off = c * 4;
              q4 = H + c;
              do {
                i = 1;
                if (*q4 != 0) {
                  u32 *lim = (u32 *)((char *)H + off);
                  do {
                    u32 cd = D_800B2CB8[k];
                    u16 ent = tab[cd & mask];
                    u32 ix = cd >> tb;
                    do {
                      (tab + (ent >> 7) + t5)[ix] = (D_800B3134[k] << 7) + D_800B283C[k];
                      ix += 1 << (D_800B283C[k] - tb);
                    } while ((ix >> ((ent >> 4) & 7)) == 0);
                    i++;
                    k++;
                  } while (*lim >= i);
                }
                off += 4;
                c++;
                q4++;
              } while (c < 16);
            }
          }
        }
      } while (phase >= 0);
      for (;;) {
        if (bits < 15) {
          v = word + (nxt << bits);
        } else {
          v = word;
        }
        e = D_801032B0[v & 0x3FF];
        n = e & 0xF;
        if (n == 0) {
          e = (D_801032B0 + 0x400)[(e >> 7) + ((v >> 10) & ((1 << ((e >> 4) & 7)) - 1))];
          n = e & 0xF;
        }
        bits -= n;
        word >>= n;
        if (bits < 0) {
          word = nxt;
          nxt = *p++;
          word >>= -bits;
          bits += 32;
        }
        sym = e >> 7;
        if (sym < 0x100) {
          *out++ = sym;
          continue;
        }
        if (sym == 0x100) {
          break;
        }
        x = D_800B26BF[sym];
        a = 0;
        if (x != 0) {
          RD(a, x, (1 << x) - 1);
        }
        len = D_800B269F[sym] + a + 3;
        if (bits < 15) {
          v = word + (nxt << bits);
        } else {
          v = word;
        }
        e = D_80108970[v & 0xFF];
        n = e & 0xF;
        if (n == 0) {
          e = (D_80108970 + 0x100)[(e >> 7) + ((v >> 8) & ((1 << ((e >> 4) & 7)) - 1))];
          n = e & 0xF;
        }
        bits -= n;
        word >>= n;
        if (bits < 0) {
          word = nxt;
          nxt = *p++;
          word >>= -bits;
          bits += 32;
        }
        sym = e >> 7;
        x = D_800B281C[sym];
        a = 0;
        if (x != 0) {
          RD(a, x, (1 << x) - 1);
        }
        dist = D_800B27E0[sym] + a;
        src = out - dist - 1;
        if (dist == 0) {
          u8 cb = *src;
          do {
            *out++ = cb;
          } while (--len != 0);
        } else {
          do {
            *out++ = *src++;
          } while (--len != 0);
        }
      }
    }
    RD(a, 1, 1);
  } while (a == 0);
}
