/* machine draft (m2c) */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
M2C_UNK func_8000A894(u16);
M2C_UNK func_80070664(void *, s32, s32, M2C_UNK);
M2C_UNK func_80073AF8(M2C_UNK, s32, s32, s16, s32, s32, s32, s32, s32, s32, s32);
M2C_UNK func_80084338(u16, void *);
s32 func_80087100(s32);
typedef struct { s16 field0; s16 field2; M2C_UNK (*callback)(void *); u8 pad8[4]; u16 fieldC; u8 padE[2]; } EventEntry;
extern EventEntry D_800C4478[];
extern s32 D_8010302C;
extern s32 D_80109688[];
void func_8005E350(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK (*temp_v0)(void *);
    s16 var_s4, var_s7;
    s32 temp_s0, temp_s1;
    void *temp_s6;
    temp_s6=M2C_FIELD(arg0,void**,0x6C);
    func_80070664(temp_s6,arg1&0xFF,arg2&0xFF,0);
    temp_s1=arg1&0xFFFF;
    temp_s0=temp_s1*0x10;
    temp_v0=D_800C4478[temp_s1].callback;
    var_s7=-1; var_s4=-1;
    if(temp_v0!=NULL) temp_v0(arg0);
    D_8010302C+=1;
    if((temp_s1==0x1A)&((arg2&0xFFFF)==1)) {} else {
      var_s7=D_800C4478[temp_s1].field0;
      var_s4=D_800C4478[temp_s1].field2;
    }
    func_80073AF8(0,D_80109688[(s8)M2C_FIELD(temp_s6,s8*,0x182)],func_80087100((arg1|0x7000)&0xFFFF),var_s7,(s32)var_s4,1,0,0,0,0,0);
    if(M2C_FIELD(arg0,u16*,0x78)==3) {
      func_80084338(D_800C4478[temp_s1].fieldC,arg0+0x24);
      return;
    }
    func_8000A894(D_800C4478[temp_s1].fieldC);
}
