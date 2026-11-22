#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))
typedef struct { f32 x, y, z; } RayVec;
typedef struct { f32 x, y, z; s32 w; } RayPlane;
typedef struct { s16 x, y, z; } RayAngles;

typedef union {
    struct {
        RayVec trans;
        u8 pad44[4];
        RayVec endLocal;
        u8 pad54[4];
        f32 rot[3][3];
        u8 pad7C[12];
        RayAngles angles;
        u8 pad8E[2];
        RayVec direction;
    } object;
    struct {
        f32 matrix[3][3];
        u8 pad5C[4];
        RayVec end;
        u8 pad6C[4];
        RayVec clippedStart;
        u8 pad7C[4];
        RayVec clippedEnd;
    } room;
} RayScratch;

f32 func_80045540(void *, void *);              /* extern */
s32 func_800455CC(void *, void *, void *, void *); /* extern */
void func_800458C0(void *, s32, s32, s32);        /* extern */
s32 func_80045CF8(s32);                         /* extern */
void func_80047E4C(void *, s32, void *);     /* extern */
s32 func_800488D4(void *, void *, void *);            /* extern */
s32 func_8004DBD8(f32 *, f32 *, s32, s32, s32, f32 *); /* extern */
s32 func_8004DEE0(void *, void *, void *);           /* extern */
u16 func_8004E418(void *, void *, void *);            /* extern */
void func_80082D24(void *, void *);            /* extern */
void func_80083A6C(void *, void *);            /* extern */
void func_80083B64(void *, void *);                /* extern */
extern void *D_80108788;
extern void **D_80108F84;

s32 func_8004E6E4(s32 (*arg0)(f32 *, f32 *, s32, s32, s32, f32 *), void **arg1, f32 *arg2, f32 *arg3, void *arg4, f32 arg5, RayPlane *arg6, u8 arg7, void *arg8) {
    RayVec end;
    RayVec nearest;
    struct {
        RayScratch scratch;
        u8 pad9C[4];
        f32 distance16;
        f32 distance8;
        union { RayVec vector; RayPlane plane; } plane;
        RayVec roomDirection;
        u8 padC4[4];
        f32 roomDistance16;
        u8 padCC[4];
        RayPlane roomPlane;
        f32 roomDistance8;
    } work;
    s32 (*spEC)(f32 *, f32 *, s32, s32, s32, f32 *);
    f32 *spF4;
    f32 *spFC;
    u8 sp107;
    void **sp10C;
    void *sp114;
    void *sp11C;
    f32 *sp124;
    f32 *sp12C;
    void *sp134;
    f32 *sp13C;
    u16 sp146;
    u16 sp14E;
    f32 *sp154;
    f32 *sp15C;
    void *sp164;
    void *sp16C;
    f32 *sp17C;
    f32 *sp184;
    f32 *sp18C;
    u16 sp19E;
    u16 sp1A6;
    f32 *sp1AC;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 var_fs0;
    f32 var_fs1;
    s32 (*var_fp)(f32 *, f32 *, s32, s32, s32, f32 *);
    s32 temp_s5;
    
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_12;
    s32 temp_v1_15;
    s32 temp_v1_4;
    s32 temp_v1_6;
    s32 temp_v1_9;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
s32 __repair_phase_var_a2;
    
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s4_3;
    s32 var_s6;
    s32 var_v0;
    u16 *var_s3_2;
    u8 *var_s3_3;
    union { u16 * pointer; s32 value; } __repair_phase_storage;
    u8 *var_s4_2;
    u16 *var_s5;
    u16 *var_s5_2;
    u16 temp_v1_11;
    u16 temp_v1_14;
    u16 temp_v1_3;
    u16 temp_v1_5;
    u16 var_v0_2;
    u16 var_v0_3;
    u32 temp_v1_10;
    u32 temp_v1_2;
    void **temp_s0;
    void **temp_s0_3;
    void **var_s7;
    void *temp_s0_2;
    void *temp_s0_4;
    void *temp_s1;
    void *temp_s2;
    void *temp_v1_13;
    void *temp_v1_16;
    void *temp_v1_17;
    void *temp_v1_7;
    void *temp_v1_8;
    void *var_s1;
    u8 *var_s1_2;
    void *var_s2;
    void *var_s2_2;
    void *var_s3;

    spEC = arg0;
    spF4 = arg2;
    spFC = arg3;
    var_fs1 = arg5;
    sp107 = arg7;
    end.x = *arg2 + (*arg3 * var_fs1);
    end.y = M2C_FIELD(spF4, f32 *, 4) + (M2C_FIELD(spFC, f32 *, 4) * var_fs1);
    var_s7 = arg1;
    end.z = M2C_FIELD(spF4, f32 *, 8) + (M2C_FIELD(spFC, f32 *, 8) * var_fs1);
    sp10C = var_s7;
    sp114 = M2C_FIELD(M2C_FIELD(var_s7, void **, 0x20), void **, 0x58);
    D_80108788 = NULL;
    D_80108F84 = NULL;
    if (var_s7 != NULL) {
        sp11C = &nearest;
        sp124 = &work.scratch.object.trans.x;
        sp12C = &work.scratch.object.endLocal.x;
        sp134 = work.scratch.object.rot;
        sp13C = &work.scratch.object.direction.x;
        do {
            var_s3 = *sp10C;
            if (var_s3 != NULL) {
                sp154 = &work.distance16;
                sp15C = &work.distance8;
                do {
                    if (((sp10C == var_s7) || (M2C_FIELD(var_s3, s32 *, 0x58) & 0x20000)) && !(M2C_FIELD(var_s3, s32 *, 0x58) & 0x400)) {
                        temp_v1 = M2C_FIELD(var_s3, s32 *, 0x5C);
                        if ((temp_v1 & 0x400) && ((var_s3 == arg8) || !(temp_v1 & 0x800) || (func_80045CF8(2) != 0) || (sp107 != 0))) {
                            temp_s1 = M2C_FIELD(var_s3, void **, 0x70);
                            if ((temp_s1 != NULL) && (M2C_FIELD(temp_s1, u8 *, 0x48) & 0x10)) {
                                var_fs0 = M2C_FIELD(var_s3, f32 *, 0x64);
                            } else {
                                var_fs0 = M2C_FIELD(var_s3, f32 *, 0x64) * M2C_FIELD(var_s3, f32 *, 0x54);
                            }
                            temp_s0 = var_s3 + 0x24;
                            func_800455CC(sp11C, spF4, &end.x, temp_s0);
                            temp_fv0 = func_80045540(temp_s0, sp11C);
                            work.distance8 = temp_fv0;
                            if (temp_fv0 < var_fs0) {
                                work.scratch.object.trans = *(RayVec *)spF4;
                                work.scratch.object.endLocal = end;
                                work.scratch.object.angles.x = (s16) (s32) -M2C_FIELD(var_s3, f32 *, 0x3C);
                                work.scratch.object.angles.y = (s16) (s32) -M2C_FIELD(var_s3, f32 *, 0x40);
                                work.scratch.object.angles.z = (s16) (s32) -M2C_FIELD(var_s3, f32 *, 0x44);
                                func_80082D24(&work.scratch.object.angles, sp134);
                                work.scratch.object.trans.x -= M2C_FIELD(var_s3, f32 *, 0x24);
                                work.scratch.object.trans.y -= M2C_FIELD(var_s3, f32 *, 0x28);
                                work.scratch.object.trans.z -= M2C_FIELD(var_s3, f32 *, 0x2C);
                                work.scratch.object.endLocal.x -= M2C_FIELD(var_s3, f32 *, 0x24);
                                work.scratch.object.endLocal.y -= M2C_FIELD(var_s3, f32 *, 0x28);
                                work.scratch.object.endLocal.z -= M2C_FIELD(var_s3, f32 *, 0x2C);
                                func_80083A6C(sp134, sp124);
                                temp_s0_2 = temp_s1 + 0x18;
                                func_80083A6C(sp134, sp12C);
                                if (((u32)func_800488D4(temp_s0_2, sp124, sp12C) << 24) != 0) {
                                    work.scratch.object.direction = *(RayVec *)spFC;
                                    temp_v0 = func_8004E418(temp_s0_2, sp124, sp12C) & 0xFFFF;
                                    var_s0 = temp_v0 & 0xFF;
    sp146 = var_s0;
                                    sp14E = temp_v0 & 0xFF00;
                                    func_80083A6C(sp134, sp13C);
                                    temp_v1_2 = M2C_FIELD(temp_s1, u8 *, 0x48) & 4;
                                    var_fp = spEC;
                                    var_s6 = -1;
                                    if (temp_v1_2 != 0) {
                                        __repair_phase_storage.pointer = M2C_FIELD(temp_s1, u16 **, 0x3C);
                                        var_s0 = 0;
                                        if (M2C_FIELD(temp_s1, u16 *, 0x40) != 0) {
                                            var_s2 = (u8 *)__repair_phase_storage.pointer + 4;
                                            do {
                                                var_s0_3 = var_s0 & 0xFFFF;
    var_s0_2 = var_s0_3;
    var_s4_3 = var_s0_2;
                                                temp_v1_3 = M2C_FIELD(temp_s1, u16 **, 0x38)[var_s4_3];
                                                if ((temp_v1_3 & sp146) && (temp_v1_3 & sp14E)) {
                                                    u32 firstVertex = *__repair_phase_storage.pointer;
                                                    temp_v1_4 = M2C_FIELD(temp_s1, s32 *, 0x34);
                                                    if ((var_fp(&work.scratch.object.trans.x, &work.scratch.object.direction.x, temp_v1_4 + (firstVertex * 0xC), temp_v1_4 + (M2C_FIELD(var_s2, u16 *, -2) * 0xC), temp_v1_4 + (M2C_FIELD(var_s2, u16 *, 0) * 0xC), sp154) & 0xFF)) {
                                                        temp_fv0 = 0.0f;
                                                        if (work.distance16 >= temp_fv0 && work.distance16 < var_fs1) {
                                                        var_s6 = var_s4_3;
                                                        var_fs1 = work.distance16;
                                                        }
                                                    }
                                                }
                                                var_s2 = (void *)((u8 *)var_s2 + 6);
                                                __repair_phase_storage.pointer = (void *)((u8 *)__repair_phase_storage.pointer + 6);
                                            } while ((u16) ++var_s0 < (u16) M2C_FIELD(temp_s1, u16 *, 0x40));
                                        }
                                    } else {
                                        var_s4_2 = M2C_FIELD(temp_s1, u8 **, 0x3C);
                                        var_s0_2 = 0;
                                        if (temp_v1_2 < (u16) M2C_FIELD(temp_s1, u16 *, 0x40)) {
                                            var_s2_2 = (u8 *)var_s4_2 + 2;
                                            do {
                                                __repair_phase_storage.value = var_s0_2 & 0xFFFF;
                                                temp_v1_5 = M2C_FIELD(temp_s1, u16 **, 0x38)[__repair_phase_storage.value];
                                                if ((temp_v1_5 & sp146) && (temp_v1_5 & sp14E)) {
                                                    u32 firstVertex = *(u8 *)var_s4_2;
                                                    temp_v1_6 = M2C_FIELD(temp_s1, s32 *, 0x34);
                                                    if ((var_fp(&work.scratch.object.trans.x, &work.scratch.object.direction.x, temp_v1_6 + (firstVertex * 0xC), temp_v1_6 + (M2C_FIELD(var_s2_2, u8 *, -1) * 0xC), temp_v1_6 + (M2C_FIELD(var_s2_2, u8 *, 0) * 0xC), sp15C) & 0xFF)) {
                                                        temp_fv0 = 0.0f;
                                                        if (work.distance8 >= temp_fv0 && work.distance8 < var_fs1) {
                                                        var_s6 = __repair_phase_storage.value;
                                                        var_fs1 = work.distance8;
                                                        }
                                                    }
                                                }
                                                var_s2_2 = (void *)((u8 *)var_s2_2 + 3);
                                                var_s4_2 = (void *)((u8 *)var_s4_2 + 3);
                                            } while ((u16) ++var_s0_2 < (u16) M2C_FIELD(temp_s1, u16 *, 0x40));
                                        }
                                    }
                                    if (var_s6 != -1) {
                                        if (M2C_FIELD(temp_s1, u8 *, 0x48) & 4) {
                                            temp_v1_7 = M2C_FIELD(temp_s1, u8 **, 0x3C) + (var_s6 * 6);
                                            var_a2 = M2C_FIELD(temp_v1_7, u16 *, 2) * 3;
                                            var_v0_2 = M2C_FIELD(temp_v1_7, u16 *, 4);
                                            var_a1 = M2C_FIELD(temp_s1, s32 *, 0x34) + (M2C_FIELD(temp_v1_7, u16 *, 0) * 0xC);
                                        
                                        func_800458C0(&work.plane.plane, var_a1, M2C_FIELD(temp_s1, s32 *, 0x34) + (var_a2 * 4), M2C_FIELD(temp_s1, s32 *, 0x34) + (var_v0_2 * 0xC));} else {
                                            temp_v1_8 = M2C_FIELD(temp_s1, u8 **, 0x3C) + (var_s6 * 3);
                                            var_a1 = M2C_FIELD(temp_s1, s32 *, 0x34) + (M2C_FIELD(temp_v1_8, u8 *, 0) * 0xC);
                                            __repair_phase_var_a2 = M2C_FIELD(temp_v1_8, u8 *, 1) * 3;
                                            var_v0_2 = (u16) M2C_FIELD(temp_v1_8, u8 *, 2);
                                        
                                        func_800458C0(&work.plane.plane, var_a1, M2C_FIELD(temp_s1, s32 *, 0x34) + (__repair_phase_var_a2 * 4), M2C_FIELD(temp_s1, s32 *, 0x34) + (var_v0_2 * 0xC));}
                                        D_80108788 = var_s3;
                                        D_80108F84 = NULL;
                                        if (arg6 != NULL) {
                                            *arg6 = work.plane.plane;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    var_s3 = M2C_FIELD(var_s3, void **, 0);
                } while (var_s3 != NULL);
            }
            if (sp114 == NULL) {
                sp10C = NULL;
            } else {
                sp10C = M2C_FIELD(sp114, void ***, 8);
                sp114 = M2C_FIELD(sp114, void **, 0);
            }
        } while (sp10C != NULL);
        if (var_s7 != NULL) {
            sp164 = &nearest;
            sp16C = &work.plane;
            sp12C = &work.scratch.room.end.x;
            sp17C = &work.scratch.room.matrix[0][0];
            sp184 = &work.scratch.room.clippedStart.x;
            sp18C = &work.scratch.room.clippedEnd.x;
            sp13C = &work.roomDirection.x;
            sp1AC = &work.roomDistance16;
            do {
                temp_s2 = M2C_FIELD(var_s7, void **, 0x3C);
                if (!(((u32) M2C_FIELD(var_s7, u32 *, 0x5C) >> 0x17) & 0x40)) {
                    temp_v1_9 = M2C_FIELD(var_s7, s32 *, 0x50);
                    if ((temp_v1_9 & 0x400) && (!(temp_v1_9 & 0x800) || (func_80045CF8(2) != 0) || (sp107 != 0))) {
                        temp_s0_3 = (void **)((u8 *)var_s7 + 0x40);
                        func_800455CC(sp164, spF4, &end.x, temp_s0_3);
                        temp_fv0_2 = func_80045540(temp_s0_3, sp164);
                        work.distance8 = temp_fv0_2;
                        if (temp_fv0_2 < M2C_FIELD(var_s7, f32 *, 0x4C)) {
                            work.plane.vector = *(RayVec *)spF4;
                            work.scratch.room.end = end;
                            if (((u32) M2C_FIELD(var_s7, u32 *, 0x5C) >> 0x17) & 1) {
                                work.plane.vector.x -= M2C_FIELD(var_s7, f32 *, 0x24);
                                work.plane.vector.y -= M2C_FIELD(var_s7, f32 *, 0x28);
                                work.plane.vector.z -= M2C_FIELD(var_s7, f32 *, 0x2C);
                                work.scratch.room.end.x -= M2C_FIELD(var_s7, f32 *, 0x24);
                                work.scratch.room.end.y -= M2C_FIELD(var_s7, f32 *, 0x28);
                                work.scratch.room.end.z -= M2C_FIELD(var_s7, f32 *, 0x2C);
                            }
                            if (((u32) M2C_FIELD(var_s7, u32 *, 0x5C) >> 0x17) & 2) {
                                func_80047E4C(var_s7, 0, sp17C);
                                func_80083B64(sp17C, sp16C);
                                func_80083B64(sp17C, sp12C);
                            }
                            temp_s0_4 = temp_s2 + 0x18;
                            if (((u32)func_800488D4(temp_s0_4, sp16C, sp12C) << 24) != 0) {
                                work.scratch.room.clippedStart = work.plane.vector;
                                work.scratch.room.clippedEnd = work.scratch.room.end;
                                var_s4_3 = -1;
                                if (((u32)func_8004DEE0(var_s7, sp184, sp18C) << 24) != 0) {
                                    work.roomDirection = *(RayVec *)spFC;
                                    temp_v0_2 = func_8004E418(temp_s0_4, sp184, sp18C);
                                    sp19E = temp_v0_2 & 0xFF;
                                    sp1A6 = temp_v0_2 & 0xFF00;
                                    if (((u32) M2C_FIELD(var_s7, u32 *, 0x5C) >> 0x17) & 2) {
                                        func_80083B64(work.scratch.room.matrix, sp13C);
                                    }
                                    var_fp = spEC;
                                    if (((u32) M2C_FIELD(var_s7, u32 *, 0x58) >> 2) & 8) {
                                        var_fp = func_8004DBD8;
                                    }
                                    temp_v1_10 = M2C_FIELD(temp_s2, u8 *, 0x48) & 4;
                                    if (temp_v1_10 != 0) {
                                        var_s3_2 = M2C_FIELD(temp_s2, u16 **, 0x3C);
                                        var_s5 = M2C_FIELD(temp_s2, u16 **, 0x38);
                                        var_s0_3 = 0;
                                        if (M2C_FIELD(temp_s2, u16 *, 0x40) != 0) {
                                            var_s1 = (u8 *)var_s3_2 + 4;
                                            do {
                                                temp_v1_11 = *var_s5;
                                                if ((temp_v1_11 & sp19E) && (temp_v1_11 & sp1A6)) {
                                                    u32 firstVertex = *var_s3_2;
                                                    temp_v1_12 = M2C_FIELD(temp_s2, s32 *, 0x34);
                                                    if ((var_fp(&work.plane.vector.x, &work.roomDirection.x, temp_v1_12 + (firstVertex * 0xC), temp_v1_12 + (M2C_FIELD(var_s1, u16 *, -2) * 0xC), temp_v1_12 + (M2C_FIELD(var_s1, u16 *, 0) * 0xC), sp1AC) & 0xFF) && (work.roomDistance16 >= 0.0f) && (work.roomDistance16 < var_fs1)) {
                                                        var_fs1 = work.roomDistance16;
                                                        var_s4_3 = var_s0_3 & 0xFFFF;
                                                    }
                                                }
                                                var_s5++;
                                                var_s1 += 6;
                                                var_s3_2 = (void *)((u8 *)var_s3_2 + 6);
                                            } while ((u16) ++var_s0_3 < (u16) M2C_FIELD(temp_s2, u16 *, 0x40));
                                        }
                                        if (var_s4_3 != -1) {
                                            D_80108788 = NULL;
                                            D_80108F84 = var_s7;
                                            if (arg6 != NULL) {
                                                if (M2C_FIELD(temp_s2, u8 *, 0x48) & 4) {
                                                    
                                                    var_a2 = M2C_FIELD((M2C_FIELD(temp_s2, u8 **, 0x3C) + (var_s4_3 * 6)), u16 *, 2) * 3;
                                                    var_v0_3 = M2C_FIELD((M2C_FIELD(temp_s2, u8 **, 0x3C) + (var_s4_3 * 6)), u16 *, 4);
                                                    var_a1_2 = M2C_FIELD(temp_s2, s32 *, 0x34) + (M2C_FIELD((M2C_FIELD(temp_s2, u8 **, 0x3C) + (var_s4_3 * 6)), u16 *, 0) * 0xC);
                                                } else {
                                                    temp_v1_17 = M2C_FIELD(temp_s2, u8 **, 0x3C) + (var_s4_3 * 3);
                                                    var_a1_2 = M2C_FIELD(temp_s2, s32 *, 0x34) + (M2C_FIELD(temp_v1_17, u8 *, 0) * 0xC);
                                                    var_a2 = M2C_FIELD(temp_v1_17, u8 *, 1) * 3;
                                                    var_v0_3 = (u16) M2C_FIELD(temp_v1_17, u8 *, 2);
                                                }
                                                func_800458C0(&work.roomPlane, var_a1_2, M2C_FIELD(temp_s2, s32 *, 0x34) + (var_a2 * 4), M2C_FIELD(temp_s2, s32 *, 0x34) + (var_v0_3 * 0xC));
                                                *arg6 = work.roomPlane;
                                            }
                                        }
                                    } else {
                                        f32 *roomDistance8 = &work.roomDistance8;
                                        var_s3_3 = M2C_FIELD(temp_s2, u8 **, 0x3C);
                                        var_s5_2 = M2C_FIELD(temp_s2, u16 **, 0x38);
                                        var_s0_4 = 0;
                                        if (temp_v1_10 < (u16) M2C_FIELD(temp_s2, u16 *, 0x40)) {
                                            var_s1_2 = (u8 *)var_s3_3 + 2;
                                            do {
                                                temp_v1_14 = *var_s5_2;
                                                if ((temp_v1_14 & sp19E) && (temp_v1_14 & sp1A6)) {
                                                    u32 firstVertex = *(u8 *)var_s3_3;
                                                    temp_v1_15 = M2C_FIELD(temp_s2, s32 *, 0x34);
                                                    if ((var_fp(&work.plane.vector.x, &work.roomDirection.x, temp_v1_15 + (firstVertex * 0xC), temp_v1_15 + (M2C_FIELD(var_s1_2, u8 *, -1) * 0xC), temp_v1_15 + (M2C_FIELD(var_s1_2, u8 *, 0) * 0xC), roomDistance8) & 0xFF) && (work.roomDistance8 >= 0.0f) && (work.roomDistance8 < var_fs1)) {
                                                        var_fs1 = work.roomDistance8;
                                                        var_s4_3 = var_s0_4 & 0xFFFF;
                                                    }
                                                }
                                                var_s1_2 += 3;
                                                var_s3_3 = (void *)((u8 *)var_s3_3 + 3);
                                                var_s5_2++;
                                            } while ((u16) ++var_s0_4 < (u16) M2C_FIELD(temp_s2, u16 *, 0x40));
                                        }
                                        if (var_s4_3 != -1) {
                                            D_80108788 = NULL;
                                            D_80108F84 = var_s7;
                                            if (arg6 != NULL) {
                                                if (M2C_FIELD(temp_s2, u8 *, 0x48) & 4) {
                                                    temp_v1_16 = M2C_FIELD(temp_s2, u8 **, 0x3C) + (var_s4_3 * 6);
                                                    var_a2 = M2C_FIELD(temp_v1_16, u16 *, 2) * 3;
                                                    var_v0_3 = M2C_FIELD(temp_v1_16, u16 *, 4);
                                                    var_a1_2 = M2C_FIELD(temp_s2, s32 *, 0x34) + (M2C_FIELD(temp_v1_16, u16 *, 0) * 0xC);
                                                } else {
                                                    temp_v1_17 = M2C_FIELD(temp_s2, u8 **, 0x3C) + (var_s4_3 * 3);
                                                    var_a1_2 = M2C_FIELD(temp_s2, s32 *, 0x34) + (M2C_FIELD(temp_v1_17, u8 *, 0) * 0xC);
                                                    var_a2 = M2C_FIELD(temp_v1_17, u8 *, 1) * 3;
                                                    var_v0_3 = (u16) M2C_FIELD(temp_v1_17, u8 *, 2);
                                                }
                                                func_800458C0(&work.roomPlane, var_a1_2, M2C_FIELD(temp_s2, s32 *, 0x34) + (var_a2 * 4), M2C_FIELD(temp_s2, s32 *, 0x34) + (var_v0_3 * 0xC));
                                                *arg6 = work.roomPlane;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                var_s7 = M2C_FIELD(var_s7, void ***, 0x14);
            } while (var_s7 != NULL);
        }
    }
    var_v0 = 0;
    if (var_fs1 < arg5) {
        var_v0 = 1;
        if (arg4 != NULL) {
            M2C_FIELD(arg4, f32 *, 0) = (f32) (M2C_FIELD(spF4, f32 *, 0) + (var_fs1 * M2C_FIELD(spFC, f32 *, 0)));
            M2C_FIELD(arg4, f32 *, 4) = (f32) (M2C_FIELD(spF4, f32 *, 4) + (var_fs1 * M2C_FIELD(spFC, f32 *, 4)));
            M2C_FIELD(arg4, f32 *, 8) = (f32) (M2C_FIELD(spF4, f32 *, 8) + (var_fs1 * M2C_FIELD(spFC, f32 *, 8)));
        }
    }
    return var_v0;
}



