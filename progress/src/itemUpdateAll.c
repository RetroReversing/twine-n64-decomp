/* identical to itemUpdateAll in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_800DA320[];
void func_8002A700(char *a);

/* Runs the item list handlers for the item system state block at D_800DA320 + 0x6BD0. */
void itemUpdateAll(void) { func_8002A700(D_800DA320 + 0x6BD0); }
