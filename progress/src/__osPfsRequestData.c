/* identical to __osPfsRequestData in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern u8 D_801083DC;
extern OSPifRam D_80112FE0;
extern u8 D_80109E90;
extern u8 D_801083DC;

/* Fills the PIF buffer with one controller-pak request block per channel, then writes the end-of-list byte. */ void __osPfsRequestData(u8 cmd) {
    u8* cursor = (u8*)&D_80112FE0;
    __OSContRequesFormat req;
    int i;

    D_80109E90 = cmd;
    D_80112FE0.pifstatus = 1 ;
    req.dummy = 0xff ;
    req.txsize = 1 ;
    req.rxsize = 3 ;
    req.cmd = cmd;
    req.typeh = 0xff ;
    req.typel = 0xff ;
    req.status = 0xff ;
    req.dummy1 = 0xff ;

    for (i = 0; i < D_801083DC; i++) {
        *((__OSContRequesFormat*)cursor) = req;
        cursor += sizeof(__OSContRequesFormat);
    }

    *cursor = 0xfe ;
}
