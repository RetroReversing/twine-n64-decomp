extern s32 func_8008C0D4(), func_8008C11C(), func_800989B8(s32), func_80095A80(s32,s32,u8,s32);
extern u8 D_800CF540, D_8010D76F, D_8010D779;
extern s32 D_8010D734, D_8010D748, D_8010D784;
s32 func_8009CB24(s32 arg0, s32 arg1) {
 s32 index, off, result;
 u8 value;
 result=-1;
 if (D_800CF540) {
  func_8008C0D4();
  arg0=func_800989B8(arg0);
  if (arg0 != -1) {
loop:
   index=arg0 & 255; off=index * 104;
   if (*(&D_8010D784+off)==arg0) {
    if (*(&D_8010D748+off)&2) {
     value=*(&D_8010D779+off*4);
     func_80095A80(0x40,index,value,arg1&255);
    } else {
     value=*(&D_8010D76F+off*4);
     func_80095A80(0x40,index,value,arg1&255);
    }
    arg0=*(&D_8010D734+index*104);
    result=0;
    if(arg0!=-1) goto loop;
   }
  }
  func_8008C11C();
 }
 return result;
}
