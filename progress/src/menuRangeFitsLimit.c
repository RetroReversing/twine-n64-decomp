/* Returns 1 if the menu's entry range is a single entry, or if the menu is not locked and the summed entry sizes fit within its limit. */
s32 menuRangeFitsLimit(void *menu) { s16 index, total; u8 first, last; if (!menu) __shared_return_0:
    return 0; first=*(u8 *)((char *)menu+0x18); last=*(u8 *)((char *)menu+0x19); if (first==last-1) return 1; index=first; total=0; while(index<last) { total+=*(u8 *)(*(char **)menu+index*12+9); index++; } { int result = *(u8 *)((char *)menu+0x1e); if (result == 0) result = total <= *(u8 *)((char *)menu+0x1b); else goto __shared_return_0; return result; } }
