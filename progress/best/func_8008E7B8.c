extern int func_80095A80(int, int, unsigned char, int);
extern int func_800989B8(void);
extern int D_8010D734, D_8010D748, D_8010D76F, D_8010D779, D_8010D784;
int func_8008E7B8(int arg1) {
 int ret=-1;
 int v=func_800989B8();
 if(v!=-1) {
  unsigned int s4=((unsigned int)(arg1&0xffff))>>7;
  do {
   unsigned int idx=(unsigned char)v;
   unsigned int off=idx*0x1a0;
   if (*(int *)((char *)&D_8010D784+off)==v) {
    unsigned char a2;
    if (*(unsigned char *)((char *)&D_8010D748+off)&2) {
     func_80095A80(0x80,idx,*(unsigned char *)((char *)&D_8010D779+off),s4&0xff);
     a2=*(unsigned char *)((char *)&D_8010D779+off);
    } else {
     func_80095A80(0x80,idx,*(unsigned char *)((char *)&D_8010D76F+off),s4&0xff);
     a2=*(unsigned char *)((char *)&D_8010D76F+off);
    }
    func_80095A80(0x81,idx,a2,arg1&0x7f);
    v=*(int *)((char *)&D_8010D734+off);
    ret=0;
   } else break;
  } while(v!=-1);
 }
 return ret;
}
