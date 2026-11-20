typedef struct {
    u32 w0, w1;
} RenderCommand;

typedef struct {
    u8 pad[0x20];
    f32 height;
} RenderDetail;

typedef struct RenderNode {
    u8 pad0[0x1C];
    struct RenderNode *next;
    u8 pad20[0x1C];
    RenderDetail *detail;
    u8 pad40[0x18];
    u32 flags;
} RenderNode;

typedef struct {
    u8 pad[0x100];
    u32 flags;
} RenderView;

typedef struct {
    u8 pad[0x74C];
    u32 matrices;
} RenderFrame;

extern void func_80014A40(RenderNode *, RenderView *);
extern void func_80032630(void *);
extern void func_8003438C(RenderNode *, RenderView *);
extern void func_80034630(RenderNode *, RenderView *);
extern void func_80038EE8(void);
extern void func_800A37C0(f32 *, u32);
extern void func_800A3940(f32 *, f32, f32, f32);
extern void guMtxIdentF(f32 *);
extern RenderCommand D_800B1A00[], D_800B1A78[], D_800B1B18[];
extern u32 D_800B1D84[3];
extern s32 D_801032A0, D_8010A924, D_80112E40;
extern RenderNode *D_80107E9C;
extern u32 D_80107EA0, D_8010D538;
extern f32 D_80112F90[16];
extern f32 D_80112FC4;
extern RenderCommand *D_80115328;
extern RenderFrame *D_80117728;

#define EMIT(a, b) { RenderCommand *cmd = D_80115328++; cmd->w0 = (a); cmd->w1 = (b); }

void func_800362B4(RenderView *view) {
    RenderNode *node = D_80107E9C;
    RenderCommand *cmd;
    f32 one = 1.0f;
    f32 scale = 64.0f;
    f32 *matrix = D_80112F90;

    if (D_801032A0 != 1) {
        D_801032A0 = 1;
        if (view->flags & 3) {
            EMIT(0xFC40FE03, 0xFFFFF378);
        } else {
            EMIT(0xFC40FE03, 0xFF0FF37F);
        }
    }
    if (D_80112E40) {
        D_80112E40 = 0;
        func_80038EE8();
    }
    if (D_8010A924 != 0) {
        D_8010A924 = 0;
        if (view->flags & 3) {
            EMIT(0xDE000000, (u32)D_800B1A00);
        } else {
            EMIT(0xDE000000, (u32)D_800B1B18);
        }
    }

    cmd = D_80115328;
    cmd->w0 = 0xDA380003;
    D_80115328++;
    cmd->w1 = D_80117728->matrices - 0x80000000;

    for (; node != NULL; node = node->next) {
        func_80014A40(node, view);
        func_8003438C(node, view);
        func_80034630(node, view);
        if (node->detail != NULL) {
            func_80032630(node->detail);
        }
    }
    if (D_8010A924 != 3) {
        D_8010A924 = 3;
        EMIT(0xDE000000, (u32)D_800B1A78);
    }

    for (node = D_80107E9C; node != NULL; node = node->next) {
        if ((node->flags >> 2) & 0x200) {
            f32 y = 2.0f * node->detail->height;
            if (D_80107EA0 >= D_800B1D84[0]) {
                break;
            }
            func_8003438C(node, view);
            func_80034630(node, view);
            D_8010D538 = D_80117728->matrices + (++D_80107EA0 << 6);
            guMtxIdentF(matrix);
            func_800A3940(matrix, one, -1.0f, one);
            D_80112FC4 = y * scale;
            func_800A37C0(matrix, D_8010D538);
            cmd = D_80115328;
            cmd->w0 = 0xDA380003;
            cmd->w1 = D_8010D538 - 0x80000000;
            D_80115328 = cmd + 1;
            func_80032630(node->detail);
        }
    }
}
