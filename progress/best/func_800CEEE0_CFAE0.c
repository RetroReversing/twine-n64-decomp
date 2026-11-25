/* Hand-written asm in ROM: loop issuing `cache 0x0D, -0x10(p)` per 16-byte line from a0 to a1.
 * Not expressible in C (inline asm is rejected); this is a compiling placeholder. */
void func_800CEEE0_CFAE0(u32 start, u32 end) {
    volatile u8 *p = (volatile u8 *)start;
    do {
        p += 16;
        (void)p[-16];
    } while ((u32)p < end);
}
