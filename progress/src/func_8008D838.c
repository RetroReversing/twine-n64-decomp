s32 ReleaseSoundEntity(s32);
s32 func_8008C1B0(s32);
s32 func_8008C43C(s32);
s32 func_8008C490(s32);
s32 func_8008C4C0(s32, s32);
s32 func_8008C524(s32, s32, s32, s32, s32);
s32 func_8008C7C8();
s32 func_8008CBD0(u32);
s32 func_8008CC38(s32, s32);
s32 func_80091428(s32, s32, s32);
s16 func_80095664(s32);
s32 func_8009692C(u8, u8, s32);
s32 func_80096CFC(s32 *);
s32 func_80096D1C(s32 *);
s32 func_80096D3C(s32 *);
s32 func_80096D5C(s32 *);
s32 func_80096D7C(s32 *);
s32 func_80096D9C(s32 *);
s32 func_80096DBC(s32 *);
s32 func_80096DDC(s32 *);
s32 func_80096DFC(s32 *);
s32 func_8009AF94(s32 *);
s32 sndStopEntity(s32);
extern s32 D_80102FDC;
extern u8 D_801032AD;
extern s32 D_80107ED4;
extern s32 D_80107ED8;
extern s32 D_80107EDC;
extern s32 D_80107EE0;
extern s32 D_80107EE4;
extern s32 D_80107EE9;
extern s32 D_80107EEC;
extern s32 D_80107EF0;
extern s32 D_80107EF4;
extern s32 D_80107EF8;
extern s32 D_80109680;
extern u8 sVoiceCount;
extern s32 sVoiceTable;
void func_8008D838(void)
{
  u8 *var_a0;
  u8 *var_s0;
  u8 *var_s5;
  s32 temp_a0;
  s32 temp_a0_3;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_s2;
  s32 temp_s2_2;
  s32 temp_s3;
  s32 temp_v0_4;
  s32 temp_v0_6;
  s32 temp_v0_7;
  s32 tsh0;
  s32 temp_v0_8;
  s32 temp_v1_10;
  s32 tsh;
  s32 temp_v1_11;
  s32 temp_v1_13;
  s32 temp_v1_14;
  s32 temp_v1_4;
  s32 temp_v1_5;
  s32 temp_v1_6;
  s32 temp_v1_8;
  s32 temp_v1_9;
  s32 var_a0_2;
  s32 var_a0_3;
  s32 var_a0_4;
  s32 var_a3;
  s32 var_s0_4;
  s32 var_s0_5;
  s32 var_s2;
  s32 var_s3;
  s32 var_s6;
  s32 var_v1_2;
  s32 var_v1_3;
  u32 var_v1;
  u32 temp_a0_4;
  u32 temp_a1_3;
  u32 temp_s0;
  u32 var_s0_2;
  u32 temp_v0;
  u32 temp_v0_2;
  u32 temp_v0_5;
  u32 temp_v1;
  u32 temp_v1_2;
  u32 temp_v1_7;
  u32 var_a2;
  u32 var_s2_3;
  u8 temp_a0_2;
  u8 temp_a0_5;
  u8 temp_s4;
  u8 temp_v0_3;
  s32 temp_v1_12;
  u8 var_v0_2;
  void *temp_v1_3;
  u8 *var_s1;
  s32 var_cnt;
  s32 pad[2];
  var_s5 = (u8 *) (&sVoiceTable);
  var_s6 = 0;
  var_cnt = sVoiceCount;
  if (var_cnt > 0)
  {
    do
    {
      var_s1 = var_s5 + 0xC2;
      if ((*((s32 *) var_s5)) != 0)
      {
        func_8009AF94((s32 *) var_s5);
        goto block_5;
      }
      if (func_8008C1B0(var_s6) & 0xFF)
      {
        block_5:
        if ((*((u8 *) (((char *) var_s1) + (-5)))) == 0)
        {
          var_s2 = 0;
          do
          {
            if ((*((u32 *) (((char *) ((char *) (var_s5) + var_s2 * 0xC)) + 0x16C))) != 0)
            {
              temp_v1 = (*((u32 *) (((char *) ((char *) (var_s5) + var_s2 * 0xC)) + 0x168))) + D_80109680;
              *((u32 *) (((char *) ((char *) (var_s5) + var_s2 * 0xC)) + 0x168)) = temp_v1;
              *((s16 *) (((char *) ((char *) (var_s5) + var_s2 * 0xC)) + 0x170)) = func_80095664((((u32) ((temp_v1 % (*((u32 *) (((char *) ((char *) (var_s5) + var_s2 * 0xC)) + 0x16C)))) * 0x10)) / ((u32) ((*((u32 *) (((char *) ((char *) (var_s5) + var_s2 * 0xC)) + 0x16C))) >> 8))) & 0xFFFF);
            }
            var_s2 += 1;
          }
          while (var_s2 < 2);
          if ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0x4000)
          {
            temp_v0_2 = *((u32 *) (((char *) var_s1) + (-0x52)));
            temp_v1_2 = (*((u32 *) (((char *) var_s1) + (-0x56)))) + D_80109680;
            *((u32 *) (((char *) var_s1) + (-0x56))) = temp_v1_2;
            *((s32 *) (((char *) var_s1) + (-0x4E))) = (s32) func_80095664((((u32) ((temp_v1_2 % temp_v0_2) * 0x10)) / ((u32) (temp_v0_2 >> 8))) & 0xFFFF);
          }
          var_s2 = 0;
          do
          {
            temp_v1_3 = var_s5 + var_s2;
            if ((*((u8 *) (((char *) temp_v1_3) + 0x48))) != 0)
            {
              temp_v0_3 = (*((u8 *) (((char *) temp_v1_3) + 0xB0))) - 1;
              *((u8 *) (((char *) temp_v1_3) + 0xB0)) = temp_v0_3;
              if (!(temp_v0_3 & 0xFF))
              {
                *((u8 *) (((char *) temp_v1_3) + 0xB0)) = (u8) (*((u8 *) (((char *) temp_v1_3) + 0x48)));
                *((s32 *) (((char *) ((char *) (var_s5) + var_s2 * 4)) + 0x40)) = 0;
              }
              else
              {
                *((s32 *) (((char *) ((char *) (var_s5) + var_s2 * 4)) + 0x40)) = (s32) ((*((s32 *) (((char *) ((char *) (var_s5) + var_s2 * 4)) + 0x40))) + (*((s32 *) (((char *) ((char *) (var_s5) + var_s2 * 4)) + 0x7C))));
              }
            }
            var_s2 += 1;
          }
          while (var_s2 < 2);
          if (((*((u8 *) (((char *) var_s1) + (-0x78)))) != 0xFF) && (((u32) (func_80096DBC((s32 *) var_s5) & 0xFFFF)) >= 0x1F81U))
          {
            *((s32 *) (((char *) var_s1) + (-0x9E))) = (*((s32 *) (((char *) var_s1) + (-0x9E)))) | 0x40000000;
          }
          else
          {
            *((s32 *) (((char *) var_s1) + (-0x9E))) = (*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0xBFFFFFFF;
          }
          if (!((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0x1000))
          {
            if ((*((u8 *) (((char *) var_s1) + (-0x78)))) != 0xFF)
            {
              if (((u32) (func_80096DDC((s32 *) var_s5) & 0xFFFF)) < 0x1F81U)
              {
                *((s32 *) (((char *) var_s1) + (-0x9E))) = (s32) ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & (~0x800));
                func_8009692C(*((u8 *) (((char *) var_s1) + (-0x78))), *((u8 *) (((char *) var_s1) + (-0x77))), 0);
              }
              else
              {
                temp_a0 = *((s32 *) (((char *) var_s1) + (-0x9E)));
                if (!(temp_a0 & 0x800))
                {
                  if (!(temp_a0 & 0x80000))
                  {
                    if (((*((u8 *) (((char *) var_s1) + (-0x2A)))) == 1) && (!(temp_a0 & 0x2000)))
                    {
                      *((s32 *) (((char *) var_s1) + (-0x36))) = 0;
                    }
                    else
                    {
                      *((s32 *) (((char *) var_s1) + (-0x36))) = (s32) (*((s32 *) (((char *) var_s1) + (-0x32))));
                    }
                    *((u32 *) (((char *) var_s1) + (-0x2E))) = (u32) ((*((u8 *) (((char *) var_s1) + (-1)))) << 0x10);
                  }
                  temp_a0_2 = *((u8 *) (((char *) var_s1) + (-0x78)));
                  if (temp_a0_2 != 0xFF)
                  {
                    func_8009692C(temp_a0_2, *((u8 *) (((char *) var_s1) + (-0x77))), 1);
                  }
                }
                *((s32 *) (((char *) var_s1) + (-0x9E))) = (s32) ((*((s32 *) (((char *) var_s1) + (-0x9E)))) | 0x800);
              }
            }
            *((s32 *) (((char *) var_s1) + (-0x9E))) = (s32) ((*((s32 *) (((char *) var_s1) + (-0x9E)))) | 0x2000);
          }
          temp_v1_4 = *((s32 *) (((char *) var_s1) + (-0x9E)));
          if (temp_v1_4 & 0x20)
          {
            *((s32 *) (((char *) var_s1) + (-0x9E))) = (s32) ((temp_v1_4 & (~0x20)) | 0x10);
            func_8008C43C(var_s6);
          }
          if ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0x80)
          {
            if (!((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0x40000000))
            {
              *((s32 *) (((char *) var_s1) + (-0x9E))) = (s32) ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & (~0x90));
              func_8008C490(var_s6);
            }
          }
          temp_a0_3 = *((s32 *) (((char *) var_s1) + (-0x9A)));
          if (temp_a0_3 != 0)
          {
            temp_v0_4 = temp_a0_3 - ((*((u16 *) (((char *) var_s1) + (-0x96)))) * D_80109680);
            *((s32 *) (((char *) var_s1) + (-0x9A))) = temp_v0_4;
            if (temp_v0_4 < 0)
            {
              *((s32 *) (((char *) var_s1) + (-0x9A))) = 0;
            }
          }
          if ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0x10000)
          {
            temp_v1_5 = (*((s32 *) (((char *) var_s1) + (-0x16)))) - ((((u32) (*((u32 *) (((char *) var_s1) + (-0x1A))))) >> 8) * (*((s32 *) (((char *) var_s1) + (-0x86)))));
            *((s32 *) (((char *) var_s1) + (-0x8A))) = temp_v1_5;
            if (temp_v1_5 >= 0)
            {
              do
              {
                var_a0_2 = 0x7F0000;
              }
              while (0);
              if (((u32) temp_v1_5) <= 0x7F0000U)
              {
                var_a0_2 = temp_v1_5;
              }
            }
            else
            {
              var_a0_2 = 0;
            }
            temp_v0_5 = (*((u32 *) (((char *) var_s1) + (-0x1A)))) - D_80109680;
            *((s32 *) (((char *) var_s1) + (-0x8A))) = var_a0_2;
            *((u32 *) (((char *) var_s1) + (-0x1A))) = temp_v0_5;
            if (temp_v0_5 == 0)
            {
              *((s32 *) (((char *) var_s1) + (-0x9E))) = (s32) ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0xFFFEFFFF);
              *((s32 *) (((char *) var_s1) + (-0x8A))) = (s32) (*((s32 *) (((char *) var_s1) + (-0x16))));
            }
          }
          temp_a1 = (*((u16 *) (((char *) var_s1) + (-0x72)))) << 0x10;
          var_s0_2 = temp_a1 + (((*((s8 *) (((char *) var_s1) + (-2)))) << 0x10) / 100);
          if ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0x40010)
          {
            if ((*((u8 *) (((char *) var_s1) + (-0x78)))) != 0xFF)
            {
              var_v1 = func_80096D5C((s32 *) var_s5) & 0xFFFF;
              *((u16 *) (((char *) var_s1) + (-0xA))) = var_v1;
              goto block_56;
            }
          }
          else
          {
            var_v1 = *((u16 *) (((char *) var_s1) + (-0xA)));
            block_56:
            if (var_v1 != 0x2000)
            {
              temp_v1_6 = var_v1 - 0x2000;
              if (temp_v1_6 < 0)
              {
                var_v0_2 = *((u8 *) (((char *) var_s1) + (-0x58)));
              }
              else
              {
                var_v0_2 = *((u8 *) (((char *) var_s1) + (-0x57)));
              }
              var_s0_2 += (var_v0_2 * temp_v1_6) * 8;
            }
          }
          temp_a1_2 = *((s32 *) (((char *) var_s1) + (-0x9E)));
          if (temp_a1_2 & 0x4000)
          {
            temp_s2 = ((*((u8 *) (((char *) var_s1) + (-0x4A)))) << 8) + (((*((u8 *) (((char *) var_s1) + (-0x49)))) << 8) / 100);
            if ((temp_a1_2 & 0x8000) && ((*((u8 *) (((char *) var_s1) + (-0x78)))) != 0xFF))
            {
              var_v1_2 = ((s32) ((*((s32 *) (((char *) var_s1) + (-0x4E)))) * (((u32) (func_80096D9C((s32 *) var_s5) & 0xFFFF)) >> 7))) >> 7;
            }
            else
            {
              var_v1_2 = *((s32 *) (((char *) var_s1) + (-0x4E)));
            }
            var_s0_2 += ((s32) (temp_s2 * var_v1_2)) >> 4;
          }
          var_a2 = var_s0_2;
          if ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0x800)
          {
            temp_a0_4 = ((u32) ((*((s32 *) (((char *) var_s1) + (-0x32)))) - (*((s32 *) (((char *) var_s1) + (-0x36)))))) >> 8;
            if (((s32) temp_a0_4) > 0)
            {
              temp_a1_3 = *((u32 *) (((char *) var_s1) + (-0x2E)));
              temp_v1_7 = temp_a1_3 + (((s32) (D_80109680 * (((s32) (var_s0_2 - temp_a1_3)) >> 8))) / ((s32) temp_a0_4));
              *((u32 *) (((char *) var_s1) + (-0x2E))) = temp_v1_7;
              if (((temp_a1_3 < var_s0_2) && ((*((u32 *) (((char *) var_s1) + (-0x2E)))) < var_s0_2)) || ((var_s0_2 < temp_a1_3) && (var_s0_2 < (*((u32 *) (((char *) var_s1) + (-0x2E)))))))
              {
                var_a2 = *((u32 *) (((char *) var_s1) + (-0x2E)));
                *((s32 *) (((char *) var_s1) + (-0x36))) = (*((s32 *) (((char *) var_s1) + (-0x36)))) + D_80109680;
              }
              else
              {
                *((s32 *) (((char *) var_s1) + (-0x36))) = *((s32 *) (((char *) var_s1) + (-0x32)));
              }
            }
          }
          var_s0_2 = var_a2;
          var_s2_3 = func_8008CC38((var_s0_2 >> 0x10) & 0xFF, *((s32 *) (((char *) var_s1) + (-0x66)))) << 0x10;
          temp_s3 = var_s0_2 & 0xFFFF;
          if (temp_s3 != 0)
          {
            temp_s0 = var_s2_3 >> 0x10;
            var_s2_3 += ((func_8008CBD0(temp_s0) & 0xFFFF) - temp_s0) * temp_s3;
          }
          var_s0_2 = var_s2_3 + ((*((s32 *) (((char *) var_s1) + (-0x82)))) + (*((s32 *) (((char *) var_s1) + (-0x7E)))));
          if ((*((u8 *) (((char *) var_s1) + (-0x78)))) != 0xFF)
          {
            var_s0_2 = ((u32) ((var_s0_2 >> 0x10) * (func_80096D7C((s32 *) var_s5) & 0xFFFF))) >> 0xD;
          }
          else
          {
            var_s0_2 = var_s0_2 >> 0x10;
          }
          func_8008C4C0(var_s6, var_s0_2 & 0xFFFF);
          if ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0x20000)
          {
            temp_v1_8 = (*((s32 *) (((char *) var_s1) + (-0x3A)))) - ((((u32) (*((u32 *) (((char *) var_s1) + (-0xE))))) >> 8) * (*((s32 *) (((char *) var_s1) + (-0x3E)))));
            *((s32 *) (((char *) var_s1) + (-0x92))) = temp_v1_8;
            if (temp_v1_8 >= 0)
            {
              do
              {
                var_a0_3 = 0x7F0000;
              }
              while (0);
              if (((u32) temp_v1_8) <= 0x7F0000U)
              {
                var_a0_3 = temp_v1_8;
              }
            }
            else
            {
              var_a0_3 = 0;
            }
            temp_v0_6 = (*((u32 *) (((char *) var_s1) + (-0xE)))) - D_80109680;
            *((s32 *) (((char *) var_s1) + (-0x92))) = var_a0_3;
            *((u32 *) (((char *) var_s1) + (-0xE))) = (u32) temp_v0_6;
            if (temp_v0_6 <= 0)
            {
              *((s32 *) (((char *) var_s1) + (-0x9E))) = (s32) ((*((s32 *) (((char *) var_s1) + (-0x9E)))) & 0xFFFDFFFF);
              *((s32 *) (((char *) var_s1) + (-0x92))) = (s32) (*((s32 *) (((char *) var_s1) + (-0x3A))));
            }
          }
          temp_v1_9 = (*((u8 *) (((char *) var_s1) + (-4)))) * 0x28;
          var_s0_4 = *((s32 *) (((char *) var_s1) + (-0x92)));
          var_s0_4 = (var_s0_4 >> 7) * (*((s16 *) (((char *) (&D_80107EEC)) + temp_v1_9)));
          var_s0_4 = (var_s0_4 >> 7) * (*((s16 *) (((char *) (&D_80107ED4)) + temp_v1_9)));
          var_s2 = *((s32 *) (((char *) var_s1) + (-0x8A)));
          temp_s4 = *((u8 *) (((char *) var_s1) + (-0x78)));
          tsh0 = var_s0_4 >> 7;
          var_a0_4 = 0x348;
          if ((*((u8 *) (((char *) var_s1) + (-0x76)))) != 0)
          {
            var_a0_4 = 0x370;
          }
          temp_a0_5 = *((u8 *) (((char *) var_s1) + (-0x93)));
          var_s0_4 = tsh0 * (*((s16 *) (((char *) (&D_80107ED4)) + var_a0_4)));
          if (temp_a0_5 != 0xFF)
          {
            var_s0_4 = (var_s0_4 >> 7) * (*((u8 *) (((char *) (&D_80102FDC)) + temp_a0_5)));
          }
          if (D_801032AD == 0)
          {
            if (temp_s4 != 0xFF)
            {
              var_s0_4 = (var_s0_4 >> 7) * (((u32) (func_80096CFC((s32 *) var_s5) & 0xFFFF)) >> 7);
              if (var_s2 != 0x800000)
              {
                var_s2 = var_s2 + (((((u32) (func_80096D1C((s32 *) var_s5) & 0xFFFF)) >> 7) - 0x40) << 0x10);
                if (var_s2 >= 0)
                {
                  do
                  {
                    var_v1_3 = 0x7F0000;
                  }
                  while (0);
                  if (var_s2 <= 0x7F0000)
                  {
                    var_v1_3 = var_s2;
                  }
                }
                else
                {
                  var_v1_3 = 0;
                }
                var_s2 = var_v1_3;
              }
              var_s3 = (func_80096D3C((s32 *) var_s5) & 0xFFFF) << 9;
              if (var_s3 > 0x7F0000)
              {
                var_s3 = 0x7F0000;
              }
            }
            else
            {
              var_s3 = 0;
            }
          }
          else
          {
            if (temp_s4 != 0xFF)
            {
              var_s0_4 = (var_s0_4 >> 7) * (((u32) (func_80096CFC((s32 *) var_s5) & 0xFFFF)) >> 7);
            }
            var_s2 = 0x400000;
            var_s3 = 0;
          }
          if (temp_s4 != 0xFF)
          {
            var_a3 = ((s32) ((((u32) (func_80096DFC((s32 *) var_s5) & 0xFFFF)) >> 7) * var_s0_4)) >> 7;
            if (var_a3 > 0x7F0000)
            {
              var_a3 = 0x7F0000;
            }
            var_a3 = (var_a3 >> 7) * (*((u8 *) (((char *) var_s1) + (-0x29))));
            if (var_a3 > 0x7F0000)
            {
              var_a3 = 0x7F0000;
            }
            var_a3 = var_a3 + ((*((u8 *) (((char *) var_s1) + (-0x28)))) << 0x10);
            if (var_a3 > 0x7F0000)
            {
              var_a3 = 0x7F0000;
            }
          }
          else
          {
            var_a3 = 0;
          }
          *((s16 *) (((char *) var_s1) + 0)) = (s16) (var_s0_4 >> 8);
          func_8008C524(var_s6, var_s0_4, var_s2, var_s3, var_a3);
        }

      }
      var_s6 += 1;
      var_s5 += 0x1A0;
    }
    while (var_s6 < ((s32) sVoiceCount));
    var_s6 = 0;
  }
  var_s6 = 0;
  var_s0_5 = 0;
  do
  {
    temp_v1_10 = *((s32 *) (((char *) (&D_80107EE0)) + var_s0_5));
    if (temp_v1_10 != 0)
    {
      do
      {
        tsh = temp_v1_10 >> 8;
      }
      while (0);
      temp_v0_7 = (*((s32 *) (((char *) (&D_80107ED8)) + var_s0_5))) - (tsh * (*((s32 *) (((char *) (&D_80107EDC)) + var_s0_5))));
      *((s32 *) (((char *) (&D_80107ED4)) + var_s0_5)) = temp_v0_7;
      if (temp_v0_7 < 0)
      {
        *((s32 *) (((char *) (&D_80107ED4)) + var_s0_5)) = 0;
      }
      temp_v1_11 = (*((s32 *) (((char *) (&D_80107EE0)) + var_s0_5))) - D_80109680;
      *((s32 *) (((char *) (&D_80107EE0)) + var_s0_5)) = temp_v1_11;
      if (temp_v1_11 <= 0)
      {
        temp_v0_7 = *((s32 *) (((char *) (&D_80107ED8)) + var_s0_5));
        temp_v1_12 = *((u8 *) (((char *) (&D_80107EE9)) + var_s0_5));
        *((s32 *) (((char *) (&D_80107EE0)) + var_s0_5)) = 0;
        *((s32 *) (((char *) (&D_80107ED4)) + var_s0_5)) = temp_v0_7;
        switch (temp_v1_12)
        {
          case 1:
            sndStopEntity(*((s32 *) (((char *) (&D_80107EE4)) + var_s0_5)));
            break;

          case 2:
            ReleaseSoundEntity(*((s32 *) (((char *) (&D_80107EE4)) + var_s0_5)));
            break;

          case 3:
            func_80091428(*((s32 *) (((char *) (&D_80107EE4)) + var_s0_5)), 0, 0);
            break;

        }

      }
    }
    temp_v1_13 = *((s32 *) (((char *) (&D_80107EF8)) + var_s0_5));
    if (temp_v1_13 != 0)
    {
      temp_v0_8 = (*((s32 *) (((char *) (&D_80107EF0)) + var_s0_5))) - ((temp_v1_13 >> 8) * (*((s32 *) (((char *) (&D_80107EF4)) + var_s0_5))));
      *((s32 *) (((char *) (&D_80107EEC)) + var_s0_5)) = temp_v0_8;
      if (temp_v0_8 < 0)
      {
        *((s32 *) (((char *) (&D_80107EEC)) + var_s0_5)) = 0;
      }
      temp_v1_14 = (*((s32 *) (((char *) (&D_80107EF8)) + var_s0_5))) - D_80109680;
      *((s32 *) (((char *) (&D_80107EF8)) + var_s0_5)) = temp_v1_14;
      if (temp_v1_14 <= 0)
      {
        *((s32 *) (((char *) (&D_80107EF8)) + var_s0_5)) = 0;
        *((s32 *) (((char *) (&D_80107EEC)) + var_s0_5)) = *((s32 *) (((char *) (&D_80107EF0)) + var_s0_5));
      }
    }
    var_s6 += 1;
    var_s0_5 = var_s6 * 0x28;
  }
  while (var_s6 < 0x20);
  func_8008C7C8();
}

