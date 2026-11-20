void func_800055CC(s32,s32,s32,s32); void func_80005F5C(void *); void func_80084180(s32,s32,s32);
extern s32 D_800D9418;
typedef struct { s32 flags; u8 pad4[0x3c]; s32 a40,a44,a48; u8 pad4c[0x32]; s16 h7e,h80; u8 pad82[0x10]; s16 h92; } Sub;
void func_80006130(void *arg0,s32 arg1,s32 arg2,s32 arg3) {
 u8 *obj=*(u8 **)((u8 *)arg0+0x68); Sub *s=(Sub *)(obj+0x14);
 if (s->flags & 0x4000) *(s16 *)(obj+0x90)=arg2; else *(s16 *)(obj+0x90)=D_800D9418;
 s->h7e=arg1; s->h80=arg2;
 func_80084180(s->a40,s->a48,s->h92);
 func_800055CC(s->a44,arg1,arg2,s->flags&1);
 func_80005F5C(arg0);
}
