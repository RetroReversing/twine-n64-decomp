extern s32 D_801002C0;
extern u8 D_801002A0;
extern u8 D_8010A4FD;
extern u16 D_8011ED40;
extern u16 D_8011ED42;
extern u16 D_8011ED44[];
extern u16 D_8011ED4C[];
extern u16 D_8011F0EC;
extern u16 D_8011F0EE;
extern u32 D_8011F2E8[][4];
extern u32 D_8011F3B8[];
extern u8 D_8011ED54[];
extern u32 D_8011F3C4[];
extern u32 D_8011F040[];
s32 func_80015F74(void *);
void func_8011C4D8(void);
void func_8011C958(void);
void func_8011C7B4(void);
void func_8011CC3C(void);
void func_8011C430(void);
void func_8011D3C0(void);
void func_8011E3AC(void) {
    u16 a0, v1;
    u16 i;
    u16 j;
    if (D_801002C0 == 1) D_8011ED42 = 0xCA;
    else D_8011ED42 = 0x76;
    a0 = D_8011ED42;
    D_8011ED44[0]=100; D_8011ED44[1]=130; D_8011ED44[2]=190; D_8011ED44[3]=220;
    D_8011F0EE=120;
    D_8011ED4C[0]=a0; D_8011ED4C[1]=a0; D_8011ED4C[2]=a0; D_8011ED4C[3]=a0;
    if (D_801002C0 == 1) D_8011F0EC=0x140;
    else if (D_801002C0 == 2) {
      if (D_8010A4FD == 1) {
        v1=D_8011ED40; D_8011F0EC=0xA0; D_8011F0EE=0xF0;
        D_8011ED4C[0]=a0-22; D_8011ED4C[1]=a0-11; D_8011ED4C[2]=a0+11; D_8011ED4C[3]=a0+22;
        D_8011ED44[0]=v1; D_8011ED44[1]=v1; D_8011ED44[2]=v1; D_8011ED44[3]=v1;
        goto after;
      }
      D_8011F0EC=0x140;
    } else D_8011F0EC=0xA0;
after:
    for(i=0;i<9;i++) for(j=0;j<4;j++) D_8011F2E8[i][j]=0;
    for(i=0;i<6;i++) D_8011F3B8[(unsigned short)i]=0;
    switch(D_801002A0) {
      case 2: for(i=0;i<3;i++) D_8011F3C4[i]=func_80015F74(D_8011ED54+i*36); func_8011C4D8(); break;
      case 3: func_8011C958(); break;
      case 4: func_8011C7B4(); break;
      case 5: func_8011CC3C(); break;
      case 6: break;
      case 7: break;
      case 8: break;
    }
    func_8011C430(); func_8011D3C0();
}
