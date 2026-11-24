extern s8 gHeapActive;
extern s32 gTopBumpAllocPtr;
/* Returns the top bump-allocator pointer, or 0 while the heap is active. */ s32 getTopBumpAllocPtr(void) { s32 result = 0; if (gHeapActive) return result; result = gTopBumpAllocPtr; return result; }
