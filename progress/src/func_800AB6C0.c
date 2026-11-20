extern void func_800AB880(s8 *, s8 *);
#ifdef PORT
#define ALIGN_BITS(q) ((uintptr_t)(q)&3)
#else
#define ALIGN_BITS(q) ((s32)(q)&3)
#endif
s8 *func_800AB6C0(s8 *dst, s8 *src) {
 s8 *p = dst; s32 w;
 if(ALIGN_BITS(p)) {do {if(*p==0) goto done; p++;}while(ALIGN_BITS(p));}
 w=*(s32*)p;
 if(w&0xFF000000) {
 do {
 if(!(w&0xFF0000)){p++;goto done;}
 if(!(w&0xFF00)){p+=2;goto done;}
 if(!(w&0xFF)){p+=3;goto done;}
 p+=4; w=*(s32*)p;
 }while(w&0xFF000000);
 }
 done: func_800AB880(p,src); return dst;
}
