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
extern M2C_UNK D_800E1328,D_800E1368,D_800E14B0,D_800E1500,sPickupSlotTable,gValidSaveSlotCount,D_8010A4C0,D_80112F68,D_80115088; extern s32 sDistanceSoundsActive,sOptionScaleY;
/* Copies the saved state blocks into their RAM working tables, then copies four 10-byte records. */
void copyStateTablesToRam(void) {
 M2C_UNK *end,*src,*src2,*src3,*dst,*dst3; s32 idx,i; void *srcRec,*dstRec,*dst2;
 dst=&D_800E1328;src=&D_8010A4C0;end=src+0x10;do{*(Four *)dst=*(Four *)src;src+=4;dst+=4;}while(src!=end);
 {typedef struct {s32 x[2];} Two; *(Two *)&D_800E1368 = *(Two *)&sDistanceSoundsActive;}
 dst2=(void *)&D_800E1368;dst2=(void *)((char *)dst2+8);src2=&sPickupSlotTable;end=src2+0x50;
 do{*(Four *)dst2=*(Four *)src2;src2+=4;dst2+=0x10;}while(src2!=end);
 dst3=&D_800E14B0;src3=&gValidSaveSlotCount;end=src3+0x14;do{*(Four *)dst3=*(Four *)src3;src3+=4;dst3+=4;}while(src3!=end);
 {typedef struct{s32 x[8];}Eight;*(Eight *)&D_800E1500=*(Eight *)&D_80112F68;}
 i=0;do{idx=i&0xFFFF;dstRec=(idx*0xA)+((char *)&D_800E1500+0x20);srcRec=(idx*0xA0)+(char *)&D_80115088;*(Ten *)dstRec=*(Ten *)srcRec;i++;}while((u32)(i&0xFFFF)<4U);
}
