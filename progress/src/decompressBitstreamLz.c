/* Decompresses an LZ-style bitstream: a flag bit selects a literal byte or a back-reference (length/offset); a zero length code ends the stream. */ void decompressBitstreamLz(void *stream)
{
  s32 temp_v0_2;
  s32 bitsLeft;
  s32 matchOffset;
  s32 matchLen;
  
  s32 bits;
  s32 copyCount;
  char *srcWords;
  u32 temp_a1;
  register u32 temp_a1_11;
  u32 temp_a1_13;
  u32 temp_a1_17;
  u32 __repair_phase_temp_a1_17;
  u32 temp_a1_19;
  u32 temp_a1_20;
  unsigned temp_a1_22;
  u32 temp_a1_28;
  u32 temp_a1_3;
  u32 temp_a1_5;
  u32 temp_a1_8;
  u32 temp_a1_9;
  u32 bitBuf;
  u32 nextWord;
  char *dst;
  char *copySrc;
  u8 temp_v0_3;
  u8 temp_v0_4;
  void *header;
  header = *((void **) (((char *) stream) + 4));
  bitsLeft = 0x20;
  dst = *((u8 **) (((char *) stream) + 0));
  bitBuf = *((u32 *) (((char *) header) + 0xC));
  nextWord = *((u32 *) (((char *) header) + 0x10));
  srcWords = (void *) header; srcWords = (void *) (((char *) srcWords) + ((s32) 0x14));
  loop_1:
  bitsLeft = bitsLeft - 1;

  loop_2:
  bits = bitBuf & 1;

  if (0 > bitsLeft)
  {
    bits = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bitBuf = bitBuf >> 1;
  }
  if (bits == 0)
  {
    bitsLeft = bitsLeft - 8;
    bits = bitBuf & 0xFF;
    if (bitsLeft < 0)
    {
      bits = bitBuf;
      bitBuf = nextWord;
      nextWord = *((u32 *) srcWords);
      srcWords += 4;
      bits = ((u32)bits + (bitBuf << (bitsLeft + 8))) & 0xFF;
      bitBuf >>= -bitsLeft;
      bitsLeft += 0x20;
    }
    else
    {
      bitBuf = bitBuf >> 8;
    }
    *((u8 *) dst) = bits;
    dst += 1;
    goto loop_1;
  }
  bitsLeft = bitsLeft - 1;
  bits = bitBuf & 1;
  if (bitsLeft < 0)
  {
    bits = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bitBuf = bitBuf >> 1;
  }
  bitsLeft = bitsLeft - 1;
  if (bits == 0) goto long_match;
  bits = bitBuf & 1;
  if (bitsLeft < 0)
  {
    bits = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bitBuf = bitBuf >> 1;
  }
  if (bits == 0)
  {
    bitsLeft = bitsLeft - 8;
    matchLen = 2;
    if (0 > bitsLeft)
    {
      matchOffset = bitBuf;
      bitBuf = nextWord;
      nextWord = *((u32 *) srcWords);
      srcWords += 4;
      matchOffset = ((u32)matchOffset + (bitBuf << (bitsLeft + 8))) & 0xFF;
      bitBuf >>= -bitsLeft;
      bitsLeft += 0x20;
    }
    else
    {
      matchOffset = bitBuf & 0xFF;
      bitBuf = bitBuf >> 8;
    }
    matchOffset += 1;
    goto block_68;
  }
  bitsLeft = bitsLeft - 1;
  bits = bitBuf & 1;
  if (bitsLeft < 0)
  {
    bits = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bitBuf = bitBuf >> 1;
  }
  if (bits != 0) goto read_length;
  matchLen = 3;
  goto block_37;
read_length:
  bitsLeft -= 8;
  matchLen = bitBuf & 0xFF;
  if (bitsLeft < 0)
  {
    matchLen = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    matchLen = ((u32)matchLen + (bitBuf << (bitsLeft + 8))) & 0xFF;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bitBuf = bitBuf >> 8;
  }
  if (matchLen == 0) goto done;
  matchLen += 8;
block_37:
  bitsLeft = bitsLeft - 1;

  matchOffset = 0;
  if (bitsLeft < 0)
  {
    bits = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bits = bitBuf & 1;
    bitBuf = bitBuf >> 1;
  }
  if (bits != 0)
  {
    bitsLeft = bitsLeft - 1;
    matchOffset = bitBuf & 1;
    if (0 > bitsLeft)
    {
      matchOffset = bitBuf;
      bitBuf = nextWord;
      nextWord = *((u32 *) srcWords);
      srcWords += 4;
      matchOffset = ((u32)matchOffset + (bitBuf << (bitsLeft + 1))) & 1;
      bitBuf >>= -bitsLeft;
      bitsLeft += 0x20;
    }
    else
    {
      bitBuf = bitBuf >> 1;
    }
    bitsLeft = bitsLeft - 1;
    bits = bitBuf & 1;
    if (bitsLeft < 0)
    {
      bits = bitBuf;
      bitBuf = nextWord;
      nextWord = *((u32 *) srcWords);
      srcWords += 4;
      bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
      bitBuf >>= -bitsLeft;
      bitsLeft += 0x20;
    }
    else
    {
      bitBuf = bitBuf >> 1;
    }
    if (bits)
    {
      bits = bitBuf & 1;
      bitsLeft = bitsLeft - 1;
      if (bitsLeft < 0)
      {
        bits = bitBuf;
        bitBuf = nextWord;
        nextWord = *((u32 *) srcWords);
        srcWords += 4;
        bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
        bitBuf >>= -bitsLeft;
        bitsLeft += 0x20;
      }
      else
      {
        bitBuf = bitBuf >> 1;
      }
      matchOffset = ((matchOffset * 2) + bits) + 4;
      bitsLeft = bitsLeft - 1;
      if (bitsLeft < 0)
      {
        bits = bitBuf;
        bitBuf = nextWord;
        nextWord = *((u32 *) srcWords);
        srcWords += 4;
        bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
        bitBuf >>= -bitsLeft;
        bitsLeft += 0x20;
      }
      else
        if (bitsLeft || temp_a1_13)
      {
        bits = bitBuf & 1;
        bitBuf = bitBuf >> 1;
      }
      else
      {
        bits = 1 & bitBuf;
        bitBuf = bitBuf >> 1;
      }
      if (bits == 0)
      {
        bitsLeft -= 1;
        bits = bitBuf & 1;
        if (bitsLeft < 0)
        {
          bits = bitBuf;
          bitBuf = nextWord;
          nextWord = *((u32 *) srcWords);
          srcWords += 4;
          bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
          bitBuf >>= -bitsLeft;
          bitsLeft += 0x20;
        }
        else
        {
          bitBuf = bitBuf >> 1;
        }
        matchOffset = (matchOffset * 2) + bits;
      }
    }
    else
      if (matchOffset == 0)
    {
      bitsLeft -= 1;
      bits = bitBuf & 1;
      if (0 > bitsLeft)
      {
        bits = bitBuf;
        bitBuf = nextWord;
        nextWord = *((u32 *) srcWords);
        srcWords += 4;
        bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
        bitBuf >>= -bitsLeft;
        bitsLeft += 0x20;
      }
      else
      {
        bitBuf = bitBuf >> 1;
      }
      matchOffset = bits + 2;
    }
  }
  bitsLeft = bitsLeft - 8;
  bits = bitBuf & 0xFF;
  if (bitsLeft < 0)
  {
    bits = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    bits = ((u32)bits + (bitBuf << (bitsLeft + 8))) & 0xFF;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bitBuf = bitBuf >> 8;
  }
  matchOffset = ((matchOffset << 8) + bits) + 1;
  goto block_68;

  block_68:
  copySrc = dst - matchOffset;
  if (matchLen-- != 0)
  {
    do
    {
      temp_v0_4 = *((u8 *) copySrc);
      ++copySrc;
      bits = matchLen;
      matchLen -= 1;
      *((u8 *) dst) = temp_v0_4;
      dst += 1;
    }
    while (bits);
    bitsLeft = bitsLeft - 1;
  }
  else
  {
    goto loop_1;
  }
  goto loop_2;

long_match:
  matchLen = bitBuf & 1;
  if (bitsLeft < 0)
  {
    matchLen = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    matchLen = ((u32)matchLen + (bitBuf << (bitsLeft + 1))) & 1;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bitBuf = bitBuf >> 1;
  }
  bitsLeft = bitsLeft - 1;
  matchLen += 4;
  if (bitsLeft < 0)
  {
    bits = bitBuf;
    bitBuf = nextWord;
    nextWord = *((u32 *) srcWords);
    srcWords += 4;
    bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
    bitBuf >>= -bitsLeft;
    bitsLeft += 0x20;
  }
  else
  {
    bits = bitBuf & 1;
    bitBuf = bitBuf >> 1;
  }
  if (bits != 0)
  {
    bitsLeft -= 1;
    bits = bitBuf & 1;
    if (bitsLeft < 0)
    {
      bits = bitBuf;
      bitBuf = nextWord;
      nextWord = *((u32 *) srcWords);
      srcWords += 4;
      bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
      bitBuf >>= -bitsLeft;
      bitsLeft += 0x20;
    }
    else
    {
      bitBuf = bitBuf >> 1;
    }
    matchLen = ((matchLen - 1) * 2) + bits;
  }
  if (matchLen == 9)
  {
    bitsLeft = bitsLeft - 4;
    matchLen = bitBuf & 0xF;
    if (bitsLeft < 0)
    {
      matchLen = bitBuf;
      bitBuf = nextWord;
      nextWord = *((u32 *) srcWords);
      srcWords += 4;
      matchLen = ((u32)matchLen + (bitBuf << (bitsLeft + 4))) & 0xF;
      bitBuf >>= -bitsLeft;
      bitsLeft += 0x20;
    }
    else
    {
      bitBuf = bitBuf >> 4;
    }
    temp_v0_2 = matchLen * 4;
    matchLen = temp_v0_2 + 0xB;
    if ((temp_v0_2 + 0xC) != 0)
    {
      do
      {
        bitsLeft -= 8;
        bits = bitBuf & 0xFF;
        if (bitsLeft < 0)
        {
          bits = bitBuf;
          bitBuf = nextWord;
          nextWord = *((u32 *) srcWords);
          srcWords += 4;
          bits = ((u32)bits + (bitBuf << (bitsLeft + 8))) & 0xFF;
          bitBuf >>= -bitsLeft;
          bitsLeft += 0x20;
        }
        else
        {
          bitBuf = bitBuf >> 8;
        }
        *((u8 *) dst) = bits;
        dst += 1;
      }
      while (matchLen-- != 0);
      bitsLeft = bitsLeft - 1;
    }
    else
    {
      goto loop_1;
    }
  }
  else
  {
    bitsLeft = bitsLeft - 1;
    matchOffset = 0;
    if (bitsLeft < 0)
    {
      bits = bitBuf;
      bitBuf = nextWord;
      nextWord = *((u32 *) srcWords);
      srcWords += 4;
      bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
      bitBuf >>= -bitsLeft;
      bitsLeft += 0x20;
    }
    else
    {
      bits = bitBuf & 1;
      bitBuf = bitBuf >> 1;
    }
    if (bits != 0)
    {
      bitsLeft = bitsLeft - 1;
      matchOffset = bitBuf & 1;
      if (bitsLeft < 0)
      {
        matchOffset = bitBuf;
        bitBuf = nextWord;
        nextWord = *((u32 *) srcWords);
        srcWords += 4;
        matchOffset = ((u32)matchOffset + (bitBuf << (bitsLeft + 1))) & 1;
        bitBuf >>= -bitsLeft;
        bitsLeft += 0x20;
      }
      else
      {
        bitBuf = bitBuf >> 1;
      }
      bitsLeft = ((u32) bitsLeft) - 1;
      bits = bitBuf & 1;
      if (bitsLeft < 0)
      {
        bits = bitBuf;
        bitBuf = nextWord;
        nextWord = *((u32 *) srcWords);
        srcWords += 4;
        bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
        bitBuf >>= -bitsLeft;
        bitsLeft += 0x20;
      }
      else
      {
        bitBuf = bitBuf >> 1;
      }
      if (bits != 0)
      {
        bitsLeft = bitsLeft - 1;
        bits = bitBuf & 1;
        if (bitsLeft < 0)
        {
          if (temp_a1_17)
          {
            bits = bitBuf;
            bitBuf = nextWord;
            nextWord = *((u32 *) srcWords);
            srcWords += 4;
            bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
            bitBuf >>= -bitsLeft;
            bitsLeft += 0x20;
          }
          else
          {
            bits = bitBuf;
            bitBuf = nextWord;
            nextWord = *((u32 *) srcWords);
            srcWords += 4;
            bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
            bitBuf >>= -bitsLeft;
            bitsLeft += 0x20;
          }
        }
        else
        {
          bitBuf = bitBuf >> 1;
        }
        matchOffset = ((matchOffset * 2) + bits) + 4;
        bitsLeft = bitsLeft - 1;
        if (bitsLeft < 0)
        {
          bits = bitBuf;
          bitBuf = nextWord;
          nextWord = *((u32 *) srcWords);
          srcWords += 4;
          bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
          bitBuf >>= -bitsLeft;
          bitsLeft += 0x20;
        }
        else
        {
          bits = bitBuf & 1;
          bitBuf = bitBuf >> 1;
        }
        if (!bits)
        {
          bitsLeft -= 1;
          bits = bitBuf & 1;
          if (bitsLeft < 0)
          {
            bits = bitBuf;
            bitBuf = nextWord;
            nextWord = *((u32 *) srcWords);
            srcWords += 4;
            bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
            bitBuf >>= -bitsLeft;
            bitsLeft += 0x20;
          }
          else
          {
            bitBuf = bitBuf >> 1;
          }
          matchOffset = (matchOffset * 2) + bits;
        }
      }
      else
        if (matchOffset == 0)
      {
        bitsLeft -= 1;
        bits = bitBuf & 1;
        if (bitsLeft < 0)
        {
          bits = bitBuf;
          bitBuf = nextWord;
          nextWord = *((u32 *) srcWords);
          srcWords += 4;
          bits = ((u32)bits + (bitBuf << (bitsLeft + 1))) & 1;
          bitBuf >>= -bitsLeft;
          bitsLeft += 0x20;
        }
        else
        {
          bitBuf = bitBuf >> 1;
        }
        matchOffset = bits + 2;
      }
    }
    bitsLeft = bitsLeft - 8;
    bits = bitBuf & 0xFF;
    if (bitsLeft < 0)
    {
      bits = bitBuf;
      bitBuf = nextWord;
      nextWord = *((u32 *) srcWords);
      srcWords += 4;
      bits = ((u32)bits + (bitBuf << (bitsLeft + 8))) & 0xFF;
      bitBuf >>= -bitsLeft;
      bitsLeft += 0x20;
    }
    else
    {
      bitBuf = bitBuf >> 8;
    }
    matchOffset = ((matchOffset << 8) + bits) + 1;
    copySrc = dst - matchOffset;
    if (matchLen-- != 0)
    {
      do
      {
        temp_v0_3 = *((u8 *) copySrc);
        copySrc += 1;
        copyCount = matchLen;
        matchLen -= 1;
        *((u8 *) dst) = temp_v0_3;
        dst += 1;
      }
      while (copyCount != 0);
      bitsLeft = bitsLeft - 1;
    }
    else
    {
      goto loop_1;
    }
  }
  goto loop_2;
done:
  return;
}
