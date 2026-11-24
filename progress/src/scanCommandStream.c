/* Walks a command byte stream until opcode 12, summing the first operand of the list opcodes (0-3), counting point entries, and recording the last list opcode seen. */ void scanCommandStream(u8 *stream, s32 *outTotalA, s32 *outPointCount, s32 *outLastKind)
{
  u8 *cursor = stream;
  unsigned int pointCount;
  long entryCount;
  u8 opcode;
  *outTotalA = 0;
  *outPointCount = 0;
  opcode = *cursor;
  while (opcode != 12) {
    switch (opcode) {

        case 9: cursor += 4; break;
        case 0: *outTotalA = *outTotalA + cursor[1]; cursor++; entryCount = *cursor * 3; *outLastKind = 0; cursor += entryCount + 1; break;
        case 1: *outTotalA = *outTotalA + cursor[1]; cursor++; entryCount = *cursor * 3; *outLastKind = 1; goto double_size;
        case 3: *outTotalA = *outTotalA + cursor[1]; cursor++; entryCount = *cursor; *outLastKind = 3; cursor += entryCount + 1; break;
        case 2: *outTotalA = *outTotalA + cursor[1]; cursor++; entryCount = *cursor; *outLastKind = 2; double_size: entryCount *= 2; cursor += entryCount + 1; break;
        case 6: cursor += 2; goto extra;
        case 7: cursor += 1; goto extra;
        case 8: cursor += 3;
        case 5: extra: pointCount = cursor[1]; cursor += 2; *outPointCount += pointCount; cursor += pointCount * 3; break;
        case 4: cursor += 4; *outPointCount += 1; break;
        case 10: case 11: cursor += 2; break;
    }
    opcode = *cursor;
  }
}
