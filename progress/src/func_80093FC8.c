extern unsigned char gWorkerActive;
int func_80093FC8(void *arg0) {
    if (gWorkerActive != 0) {
        return (*(unsigned short *)((char *)arg0 + 8)) & 1;
    }
    return 0;
}
