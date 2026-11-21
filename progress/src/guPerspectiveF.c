#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
f32 __cosf(f32);
f32 __sinf(f32);
void guMtxIdentF(f32 *);
extern f64 D_800D2E00;
extern f64 D_800D2E08;
extern f64 D_800D2E10;
extern f64 D_800D2E18;

/* Builds a perspective projection matrix in mtx (fovy, aspect, near and far planes), scales it by 1/scale and optionally writes the perspective normalisation value to perspNorm. */
void guPerspectiveF(f32 *mtx, s16 *perspNorm, f32 fovy, f32 aspect, f32 nearPlane, f32 farPlane, f32 scale) {
f32 *row,*elem; f32 halfFovy,cosHalf,cotangent,cotX,rangeDiff; f64 nearFarSum64,normQuot; int normValue; s32 col,i; unsigned short normShort;
guMtxIdentF(mtx);
fovy=(f32)((f64)fovy*(D_800D2E00/(f64)scale));
halfFovy=0.5f*fovy;
cosHalf=__cosf(halfFovy);
halfFovy=__sinf(halfFovy);
cotangent=cosHalf/halfFovy; rangeDiff=nearPlane-farPlane; cotX=cotangent/aspect; i=0; row=mtx;
M2C_FIELD(row,s32 *,0x3C)=0; M2C_FIELD(row,f32 *,0x2C)=-1.0f; M2C_FIELD(row,f32 *,0x14)=cotangent; M2C_FIELD(row,f32 *,0x28)=(f32)((nearPlane+farPlane)/(nearPlane-farPlane)); M2C_FIELD(row,f32 *,0x38)=(f32)((2.0f*nearPlane*farPlane)/(nearPlane-farPlane)); M2C_FIELD(row,f32 *,0)=cotX;
scale=1.0f/scale;
do {col=0;elem=row;do {col+=1;*elem*=scale;elem+=1;}while(col<4);i+=1;row+=4;}while(i<4);
if(perspNorm!=NULL){nearFarSum64=(f64)(nearPlane+farPlane);normValue=0xFFFF;if(!(nearFarSum64<=D_800D2E08)){normQuot=D_800D2E10/nearFarSum64;normShort=(u32)normQuot;*perspNorm=(s16)normShort;if (!(normShort & 0xFFFF)) {normValue=1; goto block_12;}}else{block_12:*perspNorm=normValue;}}
}
