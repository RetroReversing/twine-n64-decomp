/* Sets the 2-bit mode field (bits 2-3) of the flags word in obj's sub-struct to 3 if flag is nonzero, else 2. */ void setSubStructModeFlag(void *obj, s32 flag) {
 s32 *flags = (s32 *)(*(char **)((char *)obj + 0x68) + 0x14);
 unsigned int mode = -(flag != 0);
 mode = (mode & 3) | 2;
 *flags = (*flags & ~12) | (mode << 2);
}
