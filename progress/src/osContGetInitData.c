/* identical to func_8008CE60 in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef struct {
	u16     type;
	u8      status;
	u8	errno;
} OSContStatus;

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

typedef struct
{
      u32 ramarray[15];
      u32 pifstatus;
} OSPifRam;

extern OSPifRam gContPifRam;
extern u8 __osMaxControllers;

/* Reads the init/status response for each controller channel (__osMaxControllers
 * channels) from the PIF buffer. Each channel's type and status go into
 * data[ch]; channels with no error set their bit in *pattern. */
/* Reads each controller channel's init response from the PIF buffer into data[] and sets bits in *pattern for channels without errors. */ void osContGetInitData(u8* pattern, OSContStatus* data) {
    u8* pifPtr;
    __OSContRequesFormat requestformat;
    int channel;
    u8 channelMask = 0;

    pifPtr = (u8*)&gContPifRam;

    for (channel = 0; channel < __osMaxControllers; channel++, pifPtr += sizeof(requestformat), data++) {
        requestformat = *((__OSContRequesFormat*)pifPtr);
        data->errno = ((( requestformat ).rxsize & 0xC0 ) >> 4) ;

        if (data->errno != 0) {
            continue;
        }

        data->type = ((requestformat.typel << 8) | requestformat.typeh);
        data->status = requestformat.status;
        channelMask |= (1 << channel);
    }
    *pattern = channelMask;
}
