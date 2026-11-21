typedef struct { u8 pad[8]; u32 flags; u8 pad2[20]; u16 textId; u16 pad3; } TextSetup;
typedef struct { s32 unk0; void *left; void *middle; void *right; void *options[4]; void *extra[2]; } MenuText;
typedef struct { u8 pad[0x6C]; MenuText *text; u8 pad2[8]; s16 kind; s16 state; } MenuObject;
extern void *spawnEffectObject(s32,s32,s32); extern void func_80064318(void *,u32); extern void *func_80015F74();
extern TextSetup D_800BFE28[]; extern TextSetup D_800BFEB8[]; extern u16 D_800BFE48[]; extern u16 D_800BFED8[]; extern u16 D_800BFE24,D_800BFE00; extern u32 D_800BFE0C,D_800BFDE8; extern s32 gBorderSkipFlag;
void *createTextMenu(u16 textId) {
 MenuObject *obj; MenuText *text; s32 i; s32 index; s32 offset; struct Mode { unsigned mode:3; unsigned rest:29; } *flags; void *entry; volatile s32 *state; s32 variant;
    s32 __repair_variant_1;
 obj=spawnEffectObject(0x28,0,0); if(obj==NULL) return NULL;
 obj->kind=0x37; obj->state=0; func_80064318(obj,textId); text=obj->text; i=0;
 text->left=NULL; text->middle=NULL; text->right=NULL;
 do { index=(u16)i; offset=index*36; index*=4; index+=(u32)text; ((MenuText*)index)->options[0]=NULL; *(u16*)((char*)D_800BFE48+offset)=textId; entry=((void *(*)(void *))func_80015F74)((char*)D_800BFE28+offset); ++i; ((MenuText*)index)->options[0]=entry; } while((u16)i<4U);
 i=0;
 do { index=(u16)i; offset=index*36; index*=4; index+=(u32)text; ((MenuText*)index)->extra[0]=NULL; *(u16*)((char*)D_800BFED8+offset)=textId; entry=((void *(*)(void *))func_80015F74)((char*)D_800BFEB8+offset); ++i; ((MenuText*)index)->extra[0]=entry; } while((u16)i<2U);
 flags=(struct Mode*)&D_800BFE0C; state=&gBorderSkipFlag; variant=*state; entry=(u32*)flags-2; D_800BFE24=textId; flags->mode=variant==0?5:4; text->right=((void *(*)(void *))func_80015F74)(entry);
 flags=(struct Mode*)&D_800BFDE8; __repair_variant_1=*state; entry=(u32*)flags-2; D_800BFE00=textId; flags->mode=__repair_variant_1==0?5:4; text->left=((void *(*)(void *))func_80015F74)(entry);
 return obj;
}
