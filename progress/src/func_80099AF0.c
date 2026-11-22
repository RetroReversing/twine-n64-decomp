extern char D_801007D9[];
extern u8 D_80100C7C[];
inline static int inline_fn(s32 arg0, u8 arg1) { return (arg0 & 0xFF) == arg1; }
s32 func_80099AF0(u8 *arg0) {
 s32 id = *((s32 *) (arg0 + 0x60)); u8 id2; u8 a; u8 b; u8 tbl;
 if (id != (-1)) { a = arg0[0x4A]; if (a != 0xFF) { b = arg0[0x4B]; id2 = id;
 if (b == 0xFF) { tbl = D_80100C7C[id2 & 0xFF]; 
if (!inline_fn(id2, tbl)) goto __repair_compare_no;
}
 else { char *base = D_801007D9; tbl = *((base + (b * 16)) + a); 
if (!inline_fn(tbl, id2)) goto __repair_compare_no;
}
return 1; __repair_compare_no:; } } return 0;
}
