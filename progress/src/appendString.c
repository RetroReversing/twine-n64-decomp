extern void copyString(s8 *, s8 *);
#ifdef PORT
#define ALIGN_BITS(q) ((uintptr_t)(q)&3)
#else
#define ALIGN_BITS(q) ((s32)(q)&3)
#endif
/* strcat: finds the terminating NUL of dest (word-at-a-time once aligned), then copies src there. */ s8 *appendString(s8 *dest, s8 *src) {
 s8 *end = dest; s32 word;
 if(ALIGN_BITS(end)) {do {if(*end==0) goto done; end++;}while(ALIGN_BITS(end));}
 word=*(s32*)end;
 if(word&0xFF000000) {
 do {
 if(!(word&0xFF0000)){end++;goto done;}
 if(!(word&0xFF00)){end+=2;goto done;}
 if(!(word&0xFF)){end+=3;goto done;}
 end+=4; word=*(s32*)end;
 }while(word&0xFF000000);
 }
 done: copyString(end,src); return dest;
}
