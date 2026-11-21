s32 func_8003090C(s16,s32); s32 func_80030D40(u16,void *);
extern s32 gEntryTable; extern u16 D_800E160A;
s32 func_80031548(s32 arg0,s32 arg1,s32 arg2) {
 s32 index; u16 *p; u16 value;
 if ((arg2 & 0xffff)==1) index = (s16)func_8003090C(arg0,arg1);
 else index=(s16)(arg0-1);
 if (index >= 0) {
  p=(u16 *)(index*8+gEntryTable);
  value=p[1];
  if (D_800E160A >= (value & 0xf000)) {
   p[1]=(value & 0xfff0)|arg1;
   return func_80030D40(value,p);
  }
 }
 return 3;
}
