extern s32 func_80002D30(void *,s32); extern s32 func_80002C74(void *,s32,s32); extern s32 func_80002BD0(void *,s32); extern s32 func_80002CAC(void *,s32,s32); extern s32 randomIntBelow(s32); extern s32 func_8007947C(void *); extern s32 func_80077960(void *,s32);
extern u8 D_800C9970[],D_800C9972[],D_800C99AC[],D_800C99AE[],D_800C99E8[],D_800C9A08[],D_800C9A0A[],D_800C9A1C[],D_800C9A1E[];
void func_80076E98(void *p){
 unsigned char *s=(unsigned char*)p; int t=*(s16*)(s+0x7A); unsigned char *q=*(unsigned char**)(s+0x6C); int x=0; unsigned int w,off;
 if(t!=0x2D && q[0x7E]==0) q[0x7E]=t;
 if(*(s32*)(q+0x64)==0x22){*(s16*)(((unsigned char*)p)+0x7C)=12;q[0x7F]=12;*(s32*)(((unsigned char*)p)+0x74)=0;func_80002D30(p,0x205);func_80077960(p,0x71);return;}
 switch(*(s16*)(((unsigned char*)p)+0x7C)){
case 0: break;

 case 5: *(s16*)(((unsigned char*)p)+0x7C)=5;q[0x7F]=5;w=*(u32*)(q+0x88);off=(w>>15)&0x3c;func_80002CAC(p,*(u16*)(D_800C9970+off),*(u16*)(D_800C9972+off));x=1;break;
 case 6: *(s16*)(((unsigned char*)p)+0x7C)=6;q[0x7F]=6;w=*(u32*)(q+0x88);off=(w>>15)&0x3c;func_80002C74(p,*(u16*)(D_800C99AC+off),*(u16*)(D_800C99AE+off));x=1;break;
 case 4: *(s16*)(((unsigned char*)p)+0x7C)=4;q[0x7F]=4;off=*(u16*)(q+0x88)&0x1e;func_80002BD0(p,*(u16*)(D_800C99E8+off));x=1;break;
 case 7: *(s16*)(((unsigned char*)p)+0x7C)=4;q[0x7F]=4;w=*(u32*)(q+0x88);off=(w>>17)&15;x=1;if(off==7||off==0||off==14){off=randomIntBelow(5)&0xffff;w=off*4;func_80002CAC(p,*(u16*)(D_800C9A08+w),*(u16*)(D_800C9A0A+w));}else{off=(w>>15)&0x3c;func_80002CAC(p,*(u16*)(D_800C9A1C+off),*(u16*)(D_800C9A1E+off));}break;
 case 8:
     break;
 }
 if(x){ struct Vec { u32 x,y,z; }; *(struct Vec *)(q+0x18)=*(struct Vec *)(q+0x50); func_8007947C(p);func_80077960(p,0x2d);}
}
