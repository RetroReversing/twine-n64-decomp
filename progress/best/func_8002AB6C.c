s32 func_8002AB6C(void *p) { s16 i,sum; u8 start,end; if (!p) __shared_return_0:
    return 0; start=*(u8 *)((char *)p+0x18); end=*(u8 *)((char *)p+0x19); if (start==end-1) return 1; i=start; sum=0; while(i<end) { sum+=*(u8 *)(*(char **)p+i*12+9); i++; } if(*(u8 *)((char *)p+0x1e) == 0) return sum <= *(u8 *)((char *)p+0x1b); goto __shared_return_0; }
