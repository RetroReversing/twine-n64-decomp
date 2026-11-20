#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_800422F4(); s32 func_800426B8(); s32 func_80044D28();
extern u16 gSharedItemId,D_800C2B50,D_800C2B54,D_800C2B5C,D_800C2B64,D_800C2B68,D_800C2B70,D_800C2B80,D_800C2B88,D_800C2B94,D_800C2BA0,D_800C2BA4,D_800C2BB0,D_800C2BB8,D_800C2BC0,D_800C2BCC,D_800C2BF4;
extern char D_800C447A[]; extern s32 gBorderSkipFlag; extern void *gAimAxisTable; extern u8 D_80112F6C,D_80112F6D;
void func_80044DE4(u32 arg0) {
    s16 sp10[0x100]; s16 sp12,sp46,sp48,sp4C; char *var_a0_2; s16 var_v0,var_v0_2; s32 var_a0_4,var_v1,var_v1_2,var_v1_3; u16 *var_a0; u16 temp_v0;
    sp10[0]=-1; func_800422F4(); func_800426B8(M2C_FIELD(gAimAxisTable,s32*,8),arg0,1);
    switch(arg0) {
    case 2: var_a0=&D_800C2B54; break; case 20: var_a0=&D_800C2B5C; break; case 16: var_a0=&D_800C2B64; break;
    case 34: var_a0=&D_800C2B68; break; case 25: var_a0=&D_800C2B70; break; case 38: var_a0=&D_800C2B80; break;
    case 1: var_a0=&D_800C2B88; break; case 11: var_a0=&D_800C2B94; break; case 41: var_a0=&D_800C2BA0; break;
    case 40: var_a0=&D_800C2BA4; break; case 28: var_a0=&D_800C2BB0; break; case 18: var_a0=&D_800C2BB8; break;
    case 29: var_a0=&D_800C2BC0; break; case 33: var_a0=&D_800C2BCC; break; case 36: var_a0=&D_800C2B50; break;
    case 0: case 4: case 7: case 9: case 12: case 19: case 21: case 22: case 23: case 24: case 26: case 31: case 32: case 39:
        var_v1=0x1B; var_a0_2=(char *)&sp10[0x1B]; var_v0=0x1FA;
        do { *(s16*)var_a0_2=var_v0; var_a0_2-=2; var_v1--; var_v0--; } while(var_v1>=0);
        sp10[0x1C]=-1; func_80044D28(&sp10[0]); var_a0=&D_800C2BF4; break;
    default: var_a0=NULL; break;
    }
    if(var_a0!=NULL) func_80044D28(var_a0);
    var_v1_2=0x1B;
    if(D_80112F6C!=0) {
        var_a0_2=(char *)&sp10[0x1B]; var_v0_2=0x1FA;
        do { *(s16*)var_a0_2=var_v0_2; var_a0_2-=2; var_v1_2--; var_v0_2--; } while(var_v1_2>=0);
        sp10[0x1C]=-1; func_80044D28(&sp10[0]);
    }
    var_v1_3=0;
    if(D_80112F6D!=0) {
        var_a0_2=(char *)&sp10[0]; var_a0_4=0;
        do { temp_v0=*(u16*)(D_800C447A+var_a0_4); var_a0_4+=0x10; var_v1_3++; *(u16*)var_a0_2=temp_v0; var_a0_2+=2; } while(var_v1_3<0x1E);
        sp10[0x1E]=-1; func_80044D28(&sp10[1],var_a0_2);
    }
    if(gBorderSkipFlag!=0) func_80044D28(&gSharedItemId);
}
