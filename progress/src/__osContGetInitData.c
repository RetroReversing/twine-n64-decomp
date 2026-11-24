/* identical to func_80041100 in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8003A9AC (matched), with its names changed by decompdecomp */
typedef struct
{
      u8 dummy;
      u8 txsize;
      u8 rxsize;
      u8 cmd;
      u8 typeh;
      u8 typel;
      u8 status;
      u8 dummy1;
} __OSContRequesFormat;

typedef struct {
    u16 type;
    u8  status;
    u8  errno;
} OSContStatus;

extern u8 __osContPifRam[];
extern u8 __osMaxControllers;

/* Reads the PIF controller responses and fills each OSContStatus; bit i of pattern is set if controller i responded. */ void __osContGetInitData(u8 *pattern, OSContStatus *data)
{
    u8 *pifEntry;
    __OSContRequesFormat requestformat;
    int i;
    u8 presentMask = 0;

    pifEntry = __osContPifRam;

    for (i = 0; i < __osMaxControllers; i++, pifEntry += sizeof(requestformat), data++) {
        requestformat = *((__OSContRequesFormat *)pifEntry);
        data->errno = ((requestformat.rxsize & 0xC0) >> 4);

        if (data->errno != 0) {
            continue;
        }

        data->type = (requestformat.typel << 8) | requestformat.typeh;
        data->status = requestformat.status;
        presentMask |= (1 << i);
    }
    *pattern = presentMask;
}
