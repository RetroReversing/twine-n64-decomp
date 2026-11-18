#include "common.h"

/* identical to func_8001CA24 in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_80108040[];
void func_8003D318(int obj, int ctx);
/* Copies the object's fields into the context block held in the current order state. */
void func_80015E30(int obj) { func_8003D318(obj, *(int *)(D_80108040 + 0x23D0)); }
