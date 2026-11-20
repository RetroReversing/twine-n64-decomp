typedef struct { s32 x; f32 y; s32 z; } Vec3s;
s32 func_8000628C(void *,Vec3s *,s32,s32); s32 func_800828D8(s32); extern s8 D_80100900; extern Vec3s *D_80109688[];
s32 func_8007C72C(void *arg0,void *arg1,void *arg2) {
 Vec3s sp10; register s32 var_s0; u16 temp_v0; Vec3s *temp_v0_2;
 if(D_80100900!=0) goto block_6;
 {
  if(arg1!=NULL) {
   temp_v0=*(u16 *)((char *)arg1+0x78);
   if((temp_v0==2)|(temp_v0==0x4d)) {
    temp_v0_2=D_80109688[*(s8 *)((char *)(*(void **)((char *)arg1+0x6c))+0x182)];
    sp10=*(Vec3s *)((char *)temp_v0_2 + 0x10); sp10.y-=0.1f;
   } else {
    sp10=*(Vec3s *)((char *)arg1+0x24); sp10.y+=0.5f;
   } goto block_8;
  }
  if(arg2!=NULL) goto copy;
block_6: return 1;
copy: sp10=*(Vec3s *)arg2;
block_8:
  if(*(u8 *)((char *)(*(void **)((char *)arg0+0x68))+0xb1)!=0x72) var_s0=func_8000628C(arg0,&sp10,1,0x40); else var_s0=0;
  func_8000628C(arg0,&sp10,0,0xfa); D_80100900=1; return func_800828D8(var_s0)<0x1aa;
 }
done: return var_s0;
}
