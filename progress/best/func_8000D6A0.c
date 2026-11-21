extern void MatMul3x3InPlace(f32 (*)[3],f32 (*)[3]); extern f32 approxDistance(void*,void*); extern void buildRotationMatrix(const s16*,f32*); extern void buildRotationMatrixS16(const s16*,f32*); extern void func_800839F0(void*,void*,void*,s32); extern u8 *gObjectRecords;
void func_8000D6A0(s32 arg0) {
 s32 id=arg0, input[3]; f32 pos[3]; s16 a[3],rot[3]; u8 other; u8 *obj,*otherObj; void *out,*base,*data; u32 word,type,sub; f32 d; s16 *angle;
 obj=gObjectRecords+id*0xd4; other=obj[0x98];
 if(other!=0xff){otherObj=gObjectRecords+other*0xd4;out=obj+0x68;base=otherObj+0x68;
 if(otherObj[0x98]==0xff){a[0]=(s16)*(f32*)((u8*)base+0x3c);a[1]=(s16)*(f32*)((u8*)base+0x40);a[2]=(s16)*(f32*)((u8*)base+0x44);buildRotationMatrixS16(a,(f32*)(otherObj+0x9c));}
 input[0]=*(s32*)(obj+0x14);input[1]=*(s32*)(obj+0x18);input[2]=*(s32*)(obj+0x1c);do { func_800839F0(otherObj+0x9c,input,pos,input[2]); } while (0);
 pos[0]+=*(f32*)((u8*)base+0x24);pos[1]+=*(f32*)((u8*)base+0x28);pos[2]+=*(f32*)((u8*)base+0x2c);*(f32*)((u8*)out+0x24)=pos[0];*(f32*)((u8*)out+0x28)=pos[1];*(f32*)((u8*)out+0x2c)=pos[2];
 data=*(void**)((u8*)out+0x70);if(data){word=*(u32*)((u8*)data+0x30);type=word>>20;sub=(word>>4)&0xffff;if((type==0x11c&&sub==0x1a)||(type==0x98&&sub==3)||(type==0xb1&&sub==2)){d=approxDistance((u8*)out+0x24,(u8*)out+0x30);while(d>2.7017698f)d-=2.7017698f;angle=(s16*)(obj+0x96);*angle=(s16)(*angle+(d/2.7017698f)*4096.0f);}}
 rot[0]=(s16)*(f32*)((u8*)out+0x3c);rot[1]=(s16)*(f32*)((u8*)out+0x40);rot[2]=(s16)(*(f32*)((u8*)out+0x44)+*(s16*)(obj+0x96));buildRotationMatrix(rot,(f32*)(obj+0x9c));MatMul3x3InPlace((f32 (*)[3])(otherObj+0x9c),(f32 (*)[3])(obj+0x9c));*(s16*)((u8*)out+0x7c)=arg0;*(s32*)((u8*)out+0x58)|=0x40000;
 }
}
