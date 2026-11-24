s32 func_8005B5A8();
extern s32 D_800C4420,D_800C4424; extern void *gPlayerActor;
/* If the player is in state 0x11-0x12 and its trigger id matches a table entry, copies a flag to the player; otherwise calls the fallback handler. */ void applyPlayerTriggerOrFallback(u32 triggerWord, void *fallbackActor,s32 *arg2,s32 *arg3) {
 char *var_a2; char *var_a3; s32 var_t0,var_t1=0,var_v0; s32 temp_v1; u32 var_a0=triggerWord; void *var_a1=fallbackActor;
 if(gPlayerActor==0) goto fallback;
 var_a1=gPlayerActor;
 temp_v1=*(u16 *)((char *)var_a1+0x78);
 if(temp_v1>=0x13) goto fallback;
 if(temp_v1<0x11) goto fallback;
 if(*(s16 *)((char *)var_a1+0x7A)!=0) goto fallback;
 {
 register const char *base;
 u32 mask;
 var_t0=0;
 base = var_a1;
 mask = 0x08000000;
 var_a3=(char *)&D_800C4424; var_a2=(char *)&D_800C4420;
 do {
  var_a0=*(u32 *)((char *)*(void * const volatile *)(base+0x70)+0x30);

  if (((var_a0 >> 4) & 0xFFFF) != *(s32 *)var_a2) goto next;
  if ((var_a0 >> 20) != *(s32 *)var_a3) goto next;
  var_t1=1;
  if(*(s32 *)((char *)*(void **)((char *)var_a1+0x6C)+0x2C)&mask) *(s32 *)((char *)var_a1+0x60)|=mask;
next:
  var_a3+=4; var_t0++; var_a2+=4;
 } while(var_t0==0);
 }
 var_v0=var_t1;
 goto done;
fallback: var_v0=var_t1;
done: if(var_v0==0) func_8005B5A8(var_a0,var_a1);
}
