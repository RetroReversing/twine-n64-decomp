#define F(p,t,o) (*(t*)((u8*)(p)+(o)))
void func_80044670(void*,s32,s32);
void func_80060AA8(void *a){void*p,*q; s32 mode; u16 code;
if(a==0)return; p=F(a,void*,0x6c); if(p==0)return;
if(F(a,u16,0x78)==0x55){code=F(p,u16,0x3c); mode=code==0?2:(code==2?0:1);func_80044670(a,mode,0x149);F(a,f32,0x54)=0.015625f;q=F(a,void*,0x70);F(a,f32,0x28)=F(p,f32,0x34)-F(q,f32,0x20);}
else {mode=F(a,s16,0x7a);F(a,f32,0x54)=1.0f;switch(mode){case 0:case 4:F(a,f32,0x28)=F(p,f32,8);case 1:code=F(p,u16,0x3c);if(code==0){func_80044670(a,7,0x141);return;}if(code==2){func_80044670(a,3,0x141);return;}func_80044670(a,5,0x141);return;case 2:code=F(p,u16,0x3c);if(code==0){func_80044670(a,8,0x141);return;}if(code==2){func_80044670(a,4,0x141);return;}func_80044670(a,6,0x141);return;default:code=F(p,u16,0x3c);if(code==0){func_80044670(a,2,0x149);}else if(code != 2){func_80044670(a,1,0x149);}else{func_80044670(a,0,0x149);}F(a,f32,0x54)=0.015625f;q=F(a,void*,0x70);if(q)F(a,f32,0x28)=F(p,f32,0x34)-F(q,f32,0x20);else F(a,f32,0x28)=F(p,f32,0x34);}}}
