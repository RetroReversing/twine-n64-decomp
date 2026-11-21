#define F(p,t,o) (*(t*)((u8*)(p)+(o)))
void objectSetAnimFrame(void*,s32,s32);
void func_80060AA8(void *a){void*p,*q; s32 mode; u16 code;
if(a==0)return; p=F(a,void*,0x6c); if(p==0)return;
if(F(a,u16,0x78)==0x55){
 switch(F(p,u16,0x3c)){case 0: objectSetAnimFrame(a,2,0x149);break; case 2: objectSetAnimFrame(a,0,0x149);break; default: objectSetAnimFrame(a,1,0x149);}
 F(a,f32,0x54)=0.015625f;q=F(a,void*,0x70);F(a,f32,0x28)=F(p,f32,0x34)-F(q,f32,0x20);}
else {mode=F(a,s16,0x7a);F(a,f32,0x54)=1.0f;
 switch(mode){
 case 0:case 4:F(a,f32,0x28)=F(p,f32,8);
 case 1:switch(F(p,u16,0x3c)){case 0: objectSetAnimFrame(a,7,0x141);break; case 2: objectSetAnimFrame(a,3,0x141);break; default: objectSetAnimFrame(a,5,0x141);} break;
 case 2:switch(F(p,u16,0x3c)){case 0: objectSetAnimFrame(a,8,0x141);break; case 2: objectSetAnimFrame(a,4,0x141);break; default: objectSetAnimFrame(a,6,0x141);} break;
 default:
 switch(F(p,u16,0x3c)){case 0: objectSetAnimFrame(a,2,0x149);break; case 2: objectSetAnimFrame(a,0,0x149);break; default: objectSetAnimFrame(a,1,0x149);}
 F(a,f32,0x54)=0.015625f;q=F(a,void*,0x70);if(q)F(a,f32,0x28)=F(p,f32,0x34)-F(q,f32,0x20);else F(a,f32,0x28)=F(p,f32,0x34);}}}
