void func_80095A80(u8,u8,u8,u8); s32 func_800989B8();
extern char D_8010D734[],D_8010D748[],D_8010D784[]; extern unsigned char D_8010D76F[],D_8010D779[];
s32 func_8008E7B8(s32 arg0,s32 arg1) {
 s32 temp_s2,var_s0=-1,var_v0,var_v1; u32 temp_s4,low;
 var_v1=func_800989B8(arg0);
 if(var_v1!=-1) { temp_s4=(u32)(arg1&0xffff)>>7; low=arg1&0x7f;
 loop_2: temp_s2=var_v1&0xff; arg1=temp_s2*0x1a0; var_s0=temp_s2&0xff;
 if(*(s32*)(D_8010D784+arg1)!=var_v1) goto block_7;
 if(*(s32*)(D_8010D748+arg1)&2) { var_s0=temp_s2&0xff; func_80095A80(0x80,var_s0,*(D_8010D779+arg1),temp_s4&0xff); func_80095A80(0x81,var_s0,*(D_8010D779+arg1),low&0xff); }
 else { var_s0=temp_s2&0xff; func_80095A80(0x80,var_s0,*(D_8010D76F+arg1),temp_s4&0xff); func_80095A80(0x81,var_s0,*(D_8010D76F+arg1),low&0xff); }
 var_v1=*(s32*)(D_8010D734+(temp_s2*0x1a0)); var_s0=0; if(var_v1==-1) goto block_7; goto loop_2;
 } else { block_7: var_v0=var_s0; } return var_v0;
}
