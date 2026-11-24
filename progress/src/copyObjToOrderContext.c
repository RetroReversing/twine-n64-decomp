/* identical to func_8001CA24 in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_80108040[];
void linkSourceNodesByNearestPart(int obj, int ctx);
/* Copies the object's fields into the context block held in the current order state. */
/* Links the object's source nodes into the context block held in the current order state. */ void copyObjToOrderContext(int obj) { linkSourceNodesByNearestPart(obj, *(int *)(D_80108040 + 0x23D0)); }
