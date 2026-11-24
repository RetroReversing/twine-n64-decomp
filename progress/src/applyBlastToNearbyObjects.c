/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 approxDistance(void *, void *);                 /* extern */
s32 propagateFlagsToLinkedObjects(void *, void **, s32, u8); /* extern */
s32 setProximityQuery(void *, void *, f32);     /* extern */
s32 playRandomNearestMarkerSoundOfThree(void *);                      /* extern */
s32 startSubdivision(s32, void **, void *, s32, f32, f32, s32, s32); /* extern */
s32 updateNearbyEntries(f32, void *, void *);   /* extern */
extern s32 gBorderSkipActive;

typedef struct { s32 w[3]; } __repair_words3;
/* Applies a blast at origin to every object in the area's cells within radius: flags them, sets damage/impulse data by object type with distance falloff, and triggers subdivision on breakable ones. */ void applyBlastToNearbyObjects(void *source, f32 strength, f32 radius, void *area, void *origin, s32 stateFlags, s32 param) {
    f32 distance;
    f32 scaledStrength;
    s32 temp_v1;
    void **cell;
    void *temp_a2;
    
    void *temp_s0;
    void *object;
    void *nextCell;

    cell = (*(void ***)((char *)(area) + 0x20));
    if (cell != NULL) {
        object = (*(void **)((char *)(cell) + 0));
        nextCell = (*(void **)((char *)((*(void **)((char *)(cell) + 0x20))) + 0x58));
        if (source != NULL) {
            propagateFlagsToLinkedObjects(origin, cell, 0x10000, (*(u8 *)((char *)(source) + 0x5E)));
        }
        updateNearbyEntries(radius * 4.0f, area, origin);
loop_4:
        if (object != NULL) {
            do {
                temp_v1 = (*(s32 *)((char *)(object) + 0x60)) | 0x10000;
                (*(s32 *)((char *)(object) + 0x60)) = temp_v1;
                if ((*(u16 *)((char *)(object) + 0x78)) == 0x4B) {
                    (*(s32 *)((char *)(object) + 0x60)) = (s32) (temp_v1 | 1);
                }
                if ((*(s32 *)((char *)(object) + 0x58)) & 0x400) {
                    distance = approxDistance(origin, object + 0x24);
                    if (distance < radius) {
                        f32 falloff;
                        distance /= radius;
                        falloff = 1.0f - distance;
                        if ((u32) ((*(u16 *)((char *)(object) + 0x78)) - 2) < 2U) {
                            temp_a2 = (*(void **)((char *)(object) + 0x6C));
                            if (gBorderSkipActive == 0) {
                                scaledStrength = strength * 0.25f;
                            } else {
                                scaledStrength = strength;
                            }
                            (*(s32 *)((char *)(object) + 0x60)) = stateFlags;
                            (*(s32 *)((char *)(temp_a2) + 0x18C)) = (s32) (((*(s32 *)((char *)(temp_a2) + 0x18C)) & 0xFFFF0FFF) | 0x7000);
                            (*(__repair_words3 *)((char *)(temp_a2) + 0x1A0)) = *(__repair_words3 *) ((s8 *) origin + 0x0);
                            (*(f32 *)((char *)(temp_a2) + 0x1B0)) = (f32) ((*(f32 *)((char *)(temp_a2) + 0x1B0)) + (falloff * scaledStrength));
                            (*(s32 *)((char *)(temp_a2) + 0x1B4)) = 0;
                            (*(s32 *)((char *)(temp_a2) + 0x1B8)) = param;
                            if (source != NULL) {
                                (*(s32 *)((char *)(temp_a2) + 0x1B4)) = (s32) (*(u8 *)((char *)(source) + 1));
                            }
                            if ((u32) ((*(u16 *)((char *)(area) + 0x78)) - 6) < 2U) {
                                (*(s32 *)((char *)(temp_a2) + 4)) = (s32) (*(s32 *)((char *)((*(void **)((char *)(area) + 0x6C))) + 0x24));
                            }
                        }
                        if (((*(u16 *)((char *)(object) + 0x78)) == 1) && ((*(s16 *)((char *)(object) + 0x7A)) != 0x27)) {
                            temp_a2 = (*(void **)((char *)(object) + 0x6C));
                            (*(s32 *)((char *)(object) + 0x60)) = stateFlags;
                            (*(s32 *)((char *)(temp_a2) + 0x88)) = (s32) (((*(s32 *)((char *)(temp_a2) + 0x88)) & 0xFFE1FFFF) | 0xE0000);
                            (*(__repair_words3 *)((char *)(temp_a2) + 0x50)) = *(__repair_words3 *) ((s8 *) origin + 0x0);
                            (*(s32 *)((char *)(temp_a2) + 0x64)) = 0;
                            (*(s32 *)((char *)(temp_a2) + 0x68)) = param;
                            (*(f32 *)((char *)(temp_a2) + 0x60)) = (f32) ((*(f32 *)((char *)(temp_a2) + 0x60)) + strength);
                            if (source != NULL) {
                                (*(s32 *)((char *)(temp_a2) + 0x64)) = (s32) (*(u8 *)((char *)(source) + 1));
                            }
                        }
                        if ((*(s32 *)((char *)(object) + 0x5C)) & 2) {
                            (*(s32 *)((char *)(object) + 0x60)) = (s32) ((*(s32 *)((char *)(object) + 0x60)) | 1);
                            if ((*(s32 *)((char *)(object) + 0x70)) != 0) {
                                temp_s0 = object + 0x24;
                                setProximityQuery(temp_s0, origin, 5.0f);
                                startSubdivision((*(s32 *)((char *)(object) + 0x70)), cell, temp_s0, (*(s32 *)((char *)(object) + 0x3C)), (*(f32 *)((char *)(object) + 0x40)), (*(f32 *)((char *)(object) + 0x44)), 1, 1);
                                playRandomNearestMarkerSoundOfThree(origin);
                            }
                        }
                    }
                }
                object = (*(void **)((char *)(object) + 0));
            } while (object != NULL);
        }
        if (nextCell != NULL) {
            cell = (*(void ***)((char *)(nextCell) + 8));
            nextCell = (*(void **)((char *)(nextCell) + 0));
            object = *cell;
            goto loop_4;
        }
    }
}
