typedef struct { f32 x, y, z; } V3D57C;
typedef struct { u8 pad[0x34]; V3D57C *pts; u8 pad38[0xA]; u16 n; } M3D57C;
typedef struct { u8 pad[0x3C]; M3D57C *m; } O3D57C;

s32 func_8003D57C(O3D57C *arg0, O3D57C *arg1) {
    M3D57C *ma = arg0->m;
    M3D57C *mb;
    s32 hits = 0;
    s32 i, j;

    mb = arg1->m;

    for (i = 0; i < ma->n; i++) {
        for (j = 0; j < mb->n; j++) {
            if (ma->pts[i].x == mb->pts[j].x && ma->pts[i].y == mb->pts[j].y && ma->pts[i].z == mb->pts[j].z) {
                hits++;
                if (hits == ma->n) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
