#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
s32 formatTextEntry(); s32 findEntryById(); s32 lookupDataEntry(); extern s8 gMenuNeedsRedraw; extern void *gMenuItems; extern u8 gMenuRowEnabled[]; extern s32 func_8001E5BC; extern s32 func_80022848; extern char sFmtEntryName[];

/* Builds the menu item list: formats the title text from the first item entry, then sets up the four item rows. Each row's handler and flags depend on gMenuRowEnabled. */
void initMenuItemRows(void){s32 *handler;s32 titleNode,temp_a1,rowsNode,rowIndex;u16 temp_v1,flags;titleNode=findEntryById(M2C_FIELD(gMenuItems,void **,0x10),0x4000);rowsNode=findEntryById(M2C_FIELD(gMenuItems,void **,0x10),0x39);gMenuNeedsRedraw=1;if(titleNode!=0){
void *itemList;
itemList=M2C_FIELD(gMenuItems,void **,0x10);temp_v1=M2C_FIELD(itemList,u8 *,4);{ u8 *entries=M2C_FIELD(itemList,u8 **,0); u16 id=*(u16 *)(entries+(temp_v1*5)*8); s32 name=lookupDataEntry(id); formatTextEntry(titleNode,sFmtEntryName,name); }}rowIndex=0;if(rowsNode!=0){
void *row;
row=rowsNode+0xC;__repair_rows: {
    {temp_a1=rowIndex&0xFFFF;M2C_FIELD(row,u16 *,0)&=0xFFF0;handler=&func_80022848;if(*(gMenuRowEnabled+temp_a1)!=0)handler=&func_8001E5BC;M2C_FIELD(row,s32 **,-8)=handler;{ u8 enabled=((volatile u8 *)gMenuRowEnabled)[temp_a1]; temp_v1=M2C_FIELD(row,u16 *,0); flags=enabled ? temp_v1|1 : temp_v1|5; }M2C_FIELD(row,u16 *,0)=flags;rowIndex++;row+=0x28;}
}
if ((u32)(rowIndex&0xFFFF)<4U) goto __repair_rows;
}}
