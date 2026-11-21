/* adapted from similar verified C in __osRepairPackId in V-RALLY-PAL (matched), with its names changed by decompdecomp */
typedef struct S_osPfsInitPak_arg1
{
  s32 unk_00;
  s32 unk_04;
  s32 unk_08;
  u8 unk_0C[0x40];
  s32 unk_4C;
  s32 unk_50;
  s32 unk_54;
  s32 unk_58;
  s32 unk_5C;
  s32 unk_60;
  u8 unk_64;
  u8 unk_65;
} S_osPfsInitPak_arg1;
s32 __osPfsSelectBank(void *, s32);
u32 __osGetCount(void);
s32 __osContRamRead(s32, s32, s32, u8 *);
s32 __osContRamWrite(s32, s32, u16, u8 *, s32);
static inline static u16 inline_fn(u16 *arg0)
{
  return *arg0;
}

/* Repairs a controller pak's ID block for the bank at pfs. Searches banks for a
 * free slot (0x80 marks it used, the 0x20-byte block is written inverted and
 * read back to verify), then rebuilds the block from the source record at src
 * and writes it four times to the key slots 1, 3, 4 and 6. dst receives the
 * block. Returns 0 on success or an error code. */
/* Writes a controller pak ID block for a bank: finds a free bank, rebuilds the 0x20-byte ID block from src, writes it to key slots, and verifies it */ s32 __osRepairPackId(S_osPfsInitPak_arg1 *pfs, void *src, void *dst)
{
  u8 blockA[0x20];
  u8 blockB[0x20];
  u8 *end_ptr;
  u16 src_byte;
  s32 bank;
  s32 idx;
  s32 err;
  s16 keys[4];
  *((s32 *) dst) = -1;
  *(((s32 *) dst) - -1) = __osGetCount();
  {
    s32 w0;
    s32 w1;
    w0 = ((s32 *) src)[2];
    w1 = ((s32 *) src)[3];
    ((s32 *) dst)[2] = w0;
    ((s32 *) dst)[3] = w1;
    w0 = ((s32 *) src)[4];
    w1 = ((s32 *) src)[5];
    ((s32 *) dst)[4] = w0;
    ((s32 *) dst)[5] = w1;
  }
  bank = 0;
  if (pfs->unk_65 && (err = __osPfsSelectBank(pfs, 0)))
  {
    return err;
  }
  do
  {
    if (err = __osPfsSelectBank(pfs, bank & 0xFF))
    {
      return err;
    }
    if (err = __osContRamRead(pfs->unk_04, pfs->unk_08, 0, blockA))
    {
      return err;
    }
    blockA[0] = (u8) (bank | 0x80);
    for (idx = 1; idx < 0x20; idx++)
    {
      blockA[idx] = (u8) (~blockA[idx]);
    }

    if (err = __osContRamWrite(pfs->unk_04, pfs->unk_08, 0, blockA, 0))
    {
      return err;
    }
    if (err = __osContRamRead(pfs->unk_04, pfs->unk_08, 0, blockB))
    {
      return err;
    }
    idx = 0;
    while (idx < 0x20)
    {
      if (blockB[idx] != blockA[idx])
      {
        break;
      }
      idx++;
    }

    if (idx != 0x20)
    {
      break;
    }
      if (bank > 0)
      {
        if (err = __osPfsSelectBank(pfs, 0))
        {
          return err;
        }
        if (err = __osContRamRead(pfs->unk_04, pfs->unk_08, 0, blockA))
        {
          return err;
        }
        if (blockA[0] != 0x80)
        {
          break;
        }
      }
      bank++;
    if (bank >= 0x3E)
    {
      break;
    }
  }
  while (1);
  if (pfs->unk_65 && (err = __osPfsSelectBank(pfs, 0)))
  {
    return err;
  }
  {
    u16 chk;
    u16 flags;
    u16 *srcp;
    u16 *sump;
    u16 *nsump;
    u16 *sum_end;
    u16 w;
    u16 acc;
    chk = ((u16 *) src)[0xC];
    nsump = (u16 *) (((u8 *) dst) + 0x1E);
    srcp = (u16 *) dst;
    flags = (u16) (bank > 0);
    ((u8 *) dst)[0x1A] = (u8) bank;
    chk = (u16) (chk & 0xFFFE);
    flags = (u16) (flags | chk);
    ((u16 *) dst)[0xC] = flags;
    src_byte = (u16) ((u8 *) src)[0x1B];
    chk = src_byte;
    sump = (u16 *) (((u8 *) dst) + 0x1C);
    sum_end = sump;
    *((u16 *) (((u8 *) dst) + 0x1E)) = 0;
    *sump = 0;
    ((u8 *) dst)[0x1B] = (u8) chk;
    end_ptr = (u8 *) sum_end;
    do
    {
      w = inline_fn(srcp);
      acc = inline_fn(sump);
      acc += w;
      *sump = acc;
      acc = inline_fn(nsump);
      srcp = (u16 *) (((u8 *) srcp) + 2);
      acc += (u16) (~w);
      *nsump = acc;
    }
    while (((u8 *) srcp) < end_ptr);
  }
  keys[0] = 1;
  keys[1] = 3;
  keys[2] = 4;
  keys[3] = 6;
  for (idx = 0; idx < 4; idx++)
  {
    if (err = __osContRamWrite(pfs->unk_04, pfs->unk_08, (u16) keys[idx], (u8 *) dst, 1))
    {
      return err;
    }
  }

  if (err = __osContRamRead(pfs->unk_04, pfs->unk_08, 1, blockA))
  {
    return err;
  }
  for (idx = 0; idx < 0x20; idx++)
  {
    if (blockA[idx] != ((u8 *) dst)[idx])
    {
      return 11;
    }
  }

  return 0;
}
