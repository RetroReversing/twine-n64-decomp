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

#define RD(dst, c, mask) \
  bits -= (c); \
  if (bits < 0) { \
    dst = word; word = nxt; nxt = *p++; \
    dst = (dst + (word << (bits + (c)))) & (mask); \
    word >>= -bits; bits += 32; \
  } else { \
    dst = word & (mask); word >>= (c); \
  }

/* Decodes a Huffman/LZ-compressed stream from the state's input buffer into its output buffer. */ void decompressHuffmanLz(void *arg0)
{
  u32 *gp;
  u32 *H;
  u32 *r_n1;
  u32 x_n31;
  s32 bits;
  u8 *out;
  u32 *in;
  u32 *q4;
  u32 word;
  u32 *q1;
  u32 *q1b;
  u16 *tab;
  u32 i;
  u32 *q3;
  u32 a;
  u32 m;
  s32 phase;
  u8 *src;
  u32 x_n3;
  u32 eb;
  u32 c;
  u32 n9;
  u32 *q2;
  u32 k;
  u32 *p;
  u32 nxt;
  u32 sp1C;
  u32 y_n29;
  u32 tb;
  u32 zz3;

  out = *(u8 **)((char *)arg0 + 0);
  sp1C = 0;
  H = D_80112EE0;
  in = *(u32 **)((char *)arg0 + 4);
  word = in[3];
  nxt = in[4];
  p = in + 5;
  bits = 0x20;
  do {
    RD(a, 1, 1);
    if (a == 0) {
      RD(c, 15, 0x7FFF);
      if (c-- > 0) {
        do {
          RD(a, 8, 0xFF);
          *out++ = a;
        } while (c-- > 0);
      }
    } else {
/*@Rs*/
      phase = 1;
      do {
        tab = D_80108970;
        tb = 8;
        if (phase-- != 0) {
          tab = D_801032B0;
          tb = 10;
        }
        RD(a, 9, 0x1FF);
        n9 = a; if (a != 0) {
          /*@R1*/
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
            { u32 hv = H[sp1C] + 1; i++; H[sp1C] = hv; }
            q1++;
          } while (i < n9);
/*@R2*/
          D_80112EE0[0] = 0;
          k = 0;
          for (i = 1; i < 16; i++) {
            y_n29 = 0;
            if (y_n29 < n9) {
              q1b = D_800B283C;
              r_n1 = D_800B3134 + k;
              do {
                if (*q1b == i) {
                  *r_n1++ = y_n29;
                  k++;
                }
                y_n29++;
                q1b++;
              } while (y_n29 < n9);
            }
          }
/*@R3*/
          k = 0;
          for (c = 1; c < 16; c++) {
            i = 1;
            if (H[c] != 0) {
              u32 *lim = H + c;
              r_n1 = D_800B283C + k;
              do {
                *r_n1++ = c;
                i++;
                k++;
              } while (*lim >= i);
            }
          }
/*@R4*/
          D_800B283C[k] = 0;
          c = D_800B283C[0];
          i = 0;
          k = 0;
          if (c != 0) {
            do {
              while (D_800B283C[k] == c) {
                y_n29 = i | (1 << c);
                i++;
                D_800B2CB8[k] = 0;
                do {
                  D_800B2CB8[k] = D_800B2CB8[k] * 2 + (y_n29 & 1);
                  y_n29 >>= 1;
                } while (y_n29 != 1);
                k++;
              }
              i *= 2;
              c++;
            } while (*(u32 *)((char *)D_800B283C + (k << 2)) != 0);
            i = 0;
          }
          {
/*@R5*/
            u8 *bz = D_80108FA0;
            g158: {
              *bz++ = 0;
              i++;
            } if ((i >> tb) == 0) goto g158;
          }
/*@R6*/
          k = 0;
          c = 1;
          if (c < tb) {
            u32 off = 4;
            q3 = H + 1;
            g169: {
              i = 1;
              if (*q3 != 0) {
                u32 t5 = 1 << c; u32 t6;
                u32 *lim; gp = D_80112EE0; lim = (u32 *)((char *)gp + off);
                do {
                  a = D_800B2CB8[k];
                  do {
                    tab[a] = (D_800B3134[k] << 7) + c;
                    a += t5;
                  } while ((a >> tb) == 0);
                  i++;
                  do { k++; t6 = *lim; } while (0);
                } while (t6 >= i);
              }
              do { off += 4; c++; q3++; } while (0);
            } if (c < tb) goto g169;
          }
/*@R7*/
          m = k;
          if (c < 16) {
            u32 mk = (1 << tb) - 1;
            u32 off = c * 4;
            do {
              i = 1;
              if (H[c] != 0) {
                u32 *lim; gp = D_80112EE0; lim = (u32 *)((char *)gp + off);
                do {
                  u32 ix;
                  a = D_800B2CB8[k];
                  ix = a & mk;
                  y_n29 = D_800B283C[k];
                  i++;
                  if (D_80108FA0[ix] < y_n29) {
                    D_80108FA0[ix] = y_n29;
                  }
                  k++;
                } while (*lim >= i);
              }
              off += 4;
              c++;
            } while (c < 16);
          }
          {
/*@R8*/
            a = 0;
            i = 0;
            do {
              u8 b = D_80108FA0[i];
              if (b != 0) {
                if ((u32)(b - tb) < 8) {
                  tab[i] = (a << 7) + ((b - tb) << 4);
                  a += 1 << (D_80108FA0[i] - tb);
                } else {
                  *(s32 *)((char *)arg0 + 0x1C) = -8;
                  return;
                }
              }
              i++;
            } while ((i >> tb) == 0);
/*@R9*/
            c = tb;
            if (a >= 0x200) {
              *(s32 *)((char *)arg0 + 0x1C) = -9;
              return;
            }
            k = m;
            if (c < 16) {
              u32 t5 = 1 << c;
              u32 mask = t5 - 1;
              u32 off = c * 4;
              do {
                i = 1;
                if (H[c] != 0) {
                  u32 *lim; gp = D_80112EE0; lim = (u32 *)((char *)gp + off);
                  do {
                    u16 ent; u32 vx, vy;
                    a = D_800B2CB8[k];
                    ent = tab[a & mask];
                    y_n29 = a >> tb;
                    do {
                      u32 o2 = y_n29 * 2;
                      u32 o1 = ((ent >> 7) + t5) * 2;
                      vx = D_800B3134[k];
                      vy = D_800B283C[k];
                      *(u16 *)(o2 + (u32)((char *)tab + o1)) = (vx << 7) + vy;
                      y_n29 += 1 << (D_800B283C[k] - tb);
                    } while ((y_n29 >> (a = ((ent >> 4) % 8))) == 0);
                    i++;
                    k++;
                  } while (*lim >= i);
                }
                do { do { do { off += 4; } while (0); } while (0); } while (0);
                c++;
              } while (c < 16);
            }
          }
        }
      } while (phase >= 0);
/*@Rd*/
      for (;;) {
        if (bits < 15) {
          x_n31 = word + (nxt << bits);
        } else {
          x_n31 = word;
        }
        c = D_801032B0[x_n31 & 0x3FF];
        zz3 = c & 0xF;
        if (zz3 == 0) {
          c = (D_801032B0 + 0x400 + (c >> 7))[(x_n31 >> 10) & ((1 << ((c >> 4) & 7)) - 1)];
          zz3 = c & 0xF;
        }
        bits -= zz3;
        word >>= zz3;
        if (bits < 0) {
          word = nxt;
          nxt = *p++;
          word >>= -bits;
          bits += 32;
        }
        c = c >> 7;
        if (c < 0x100) {
          *out++ = c;
          continue;
        }
        if (c == 0x100) {
          break;
        }
/*@Re1*/
        eb = D_800B26BF[c];
        a = 0;
        if (eb != 0) {
          RD(a, eb, (1 << eb) - 1);
        }
        c = D_800B269F[c] + a + 3;
/*@Rl2*/
        if (bits < 15) {
          x_n31 = word + (nxt << bits);
        } else {
          x_n31 = word;
        }
        y_n29 = D_80108970[x_n31 & 0xFF];
        zz3 = y_n29 & 0xF;
        if (zz3 == 0) {
          y_n29 = (D_80108970 + 0x100 + (y_n29 >> 7))[(x_n31 >> 8) & ((1 << ((y_n29 >> 4) & 7)) - 1)];
          zz3 = y_n29 & 0xF;
        }
        bits -= zz3;
        word >>= zz3;
        if (bits < 0) {
          word = nxt;
          nxt = *p++;
          word >>= -bits;
          bits += 32;
        }
        y_n29 = y_n29 >> 7;
/*@Re2*/
        eb = D_800B281C[y_n29];
        a = 0;
        if (eb != 0) {
          RD(a, eb, (1 << eb) - 1);
        }
        y_n29 = D_800B27E0[y_n29] + a;
/*@Rc*/
        src = out - y_n29 - 1;
        if (y_n29 == 0) {
          u8 cb = *src;
          do {
            *out++ = cb;
          } while (--c != 0);
        } else {
          do {
            *out++ = *src++;
          } while (--c != 0);
        }
      }
    }
/*@Rt*/
    RD(a, 1, 1);
  } while (a == 0);
}


