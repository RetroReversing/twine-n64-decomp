extern s32 D_801002B4, D_8010302C;
extern void *D_8010A500[], *gTrackMarkerTable[];
extern char D_8011F3AC[];
void func_8000A894(s32);
void func_8002B150(void *,s32,s32);
s32 func_80087100(s32);
void func_80073AF8(s32,void *,s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_8007089C(void *,s32,s32);
void func_8011B0FC(void *p) {
 void *q = D_8010A500[*(s8*)((char*)p+0x182)];
 s32 x;
 func_8000A894(0x224);
 switch(D_801002B4) {
 default: func_8002B150(D_8011F3AC,1,0); break;
 case 3: func_8002B150(D_8011F3AC,2,0); break;
 case 4: func_8002B150(D_8011F3AC,3,0); break;
 case 5: func_8002B150(D_8011F3AC,3,30); break;
 case 6: func_8002B150(D_8011F3AC,4,0); break;
 case 7: func_8002B150(D_8011F3AC,4,30); break;
 case 8: func_8002B150(D_8011F3AC,5,0); break;
 }
 *(s8*)((char*)p+0x32c)=1;
 D_8010302C++;
 x=func_80087100(0x6026);
 func_80073AF8(0,gTrackMarkerTable[*(s8*)((char*)p+0x183)],x,-1,-1,1,0,0,0,0,0);
 *(s16*)((char*)p+0x1d8)=500;
 *(s8*)((char*)p+0x32f)=5;
 func_8007089C(q,0,0x26);
}
