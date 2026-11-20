s32 func_8008CEB0(s32,s32,s32); s32 func_80096970(s32,s32);
s32 func_8008D0C0(s32 arg0,s32 arg1,s32 arg2) { s32 temp_s0=arg1&0xFF; s32 temp_s1; s32 temp_v0; s32 var_v0; if ((temp_s0==0xFF) || (temp_s1=arg2&0xFF, ((func_80096970(temp_s0,temp_s1)&0xFF)==0)) || (temp_v0=func_8008CEB0(arg0&0x7F,temp_s0,temp_s1), var_v0=temp_v0,(temp_v0==-1))) var_v0=-1; return var_v0; }
