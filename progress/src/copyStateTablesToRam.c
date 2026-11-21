#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
typedef struct {char b[10];} Ten; typedef struct{s32 x[4];} Four;
extern M2C_UNK D_800E1328,D_800E1368,D_800E14B0,D_800E1500,D_80100198,D_80102EB8,D_8010A4C0,D_80112F68,D_80115088; extern s32 D_801002EC,D_801002F0;
void copyStateTablesToRam(void) {
 M2C_UNK *end,*var_a2,*var_a2_2,*var_a2_3,*var_a3,*var_a3_3; s32 temp_v1,var_t0; void *temp_v0,*temp_v1_2,*var_a3_2;
 var_a3=&D_800E1328;var_a2=&D_8010A4C0;end=var_a2+0x10;do{*(Four *)var_a3=*(Four *)var_a2;var_a2+=4;var_a3+=4;}while(var_a2!=end);
 {typedef struct {s32 x[2];} Two; *(Two *)&D_800E1368 = *(Two *)&D_801002EC;}
 var_a3_2=(void *)&D_800E1368;var_a3_2=(void *)((char *)var_a3_2+8);var_a2_2=&D_80100198;end=var_a2_2+0x50;
 do{*(Four *)var_a3_2=*(Four *)var_a2_2;var_a2_2+=4;var_a3_2+=0x10;}while(var_a2_2!=end);
 var_a3_3=&D_800E14B0;var_a2_3=&D_80102EB8;end=var_a2_3+0x14;do{*(Four *)var_a3_3=*(Four *)var_a2_3;var_a2_3+=4;var_a3_3+=4;}while(var_a2_3!=end);
 {typedef struct{s32 x[8];}Eight;*(Eight *)&D_800E1500=*(Eight *)&D_80112F68;}
 var_t0=0;do{temp_v1=var_t0&0xFFFF;temp_v1_2=(temp_v1*0xA)+((char *)&D_800E1500+0x20);temp_v0=(temp_v1*0xA0)+(char *)&D_80115088;*(Ten *)temp_v1_2=*(Ten *)temp_v0;var_t0++;}while((u32)(var_t0&0xFFFF)<4U);
}
