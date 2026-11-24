typedef struct Worker {
    struct Worker *next;
    u8 pad4[4];
    u32 flags;
    f32 pos[3];
    f32 vel[3];
    u8 pad24[0x48 - 0x24];
    u8 data48[0x78 - 0x48];
    f32 limitHi;
    f32 limitLo;
    f32 w80;
    f32 w84;
} Worker;

typedef struct Source {
    u8 pad0[8];
    u32 flags;
    f32 pos[3];
    f32 vel[3];
    f32 radius;
    f32 f28;
    f32 f2C;
    f32 f30;
} Source;

extern Worker *gWorkerListHead;
extern void transformPointByMatrix(void *, void *, f32 *);
extern f32 normalizeVec3(f32 *);
extern f32 sqrtf(f32);

/* Walks the worker list and sums the attenuation, speed ratio and direction of each worker in range of a sound source; outputs the volume, ratio and averaged direction. */
void computeSourceAttenuation(Source *source, f32 *outVolume, f32 *outRatio, f32 *outDirX, f32 *outDirY, f32 *outDirZ) {
    f32 delta[3];
    f32 relVel[3];
    f32 dirToSource[3];
    f32 dirSum[3];
    Worker *worker;
    u32 workerCount;
    f32 dist, relSpeed, ratio, coef, frameTime;
    f32 zeroF;

    frameTime = 0.016666668f;
    *outVolume = 0.0f;
    *outRatio = 1.0f;
    worker = gWorkerListHead;
    workerCount = 0;
    zeroF = 0.0f;
    dirSum[2] = zeroF;
    dirSum[1] = zeroF;
    dirSum[0] = zeroF;
    if (worker != NULL) {
        do {
            delta[0] = source->pos[0] - worker->pos[0];
            delta[1] = source->pos[1] - worker->pos[1];
            delta[2] = source->pos[2] - worker->pos[2];
            dist = sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
            if (dist <= source->radius) {
                ratio = dist / source->radius;
                coef = source->f30;
                *outVolume += worker->w84 * (source->f2C + (source->f28 - source->f2C) * (1.0f - ((1.0f - coef) * ratio + coef * ratio * ratio)));
                if (!(source->flags & 0x80000)) {
                    if ((source->flags & 8) || (worker->flags & 1)) {
                        relVel[0] = worker->vel[0] - source->vel[0];
                        relVel[1] = worker->vel[1] - source->vel[1];
                        relVel[2] = worker->vel[2] - source->vel[2];
                        relSpeed = sqrtf(relVel[0] * relVel[0] + relVel[1] * relVel[1] + relVel[2] * relVel[2]);
                        if (relSpeed > 0.0f) {
                            delta[0] = (source->pos[0] + source->vel[0] * frameTime) - (worker->pos[0] + worker->vel[0] * frameTime);
                            delta[1] = (source->pos[1] + source->vel[1] * frameTime) - (worker->pos[1] + worker->vel[1] * frameTime);
                            delta[2] = (source->pos[2] + source->vel[2] * frameTime) - (worker->pos[2] + worker->vel[2] * frameTime);
                            if (sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]) < dist) {
                                coef = worker->w80;
                                ratio = coef - relSpeed;
                            } else {
                                coef = worker->w80;
                                ratio = coef + relSpeed;
                            }
                            *outRatio = coef / ratio;
                        }
                    }
                    if (dist != 0.0f) {
                        transformPointByMatrix(worker->data48, source->pos, dirToSource);
                        if (dirToSource[2] >= 0.0f) {
                            dirSum[2] += (dirToSource[2] < worker->limitHi) ? dirToSource[2] / worker->limitHi : 1.0;
                        } else {
                            dirSum[2] += (-worker->limitLo < dirToSource[2]) ? dirToSource[2] / worker->limitLo : -1.0;
                        }
                        if (dirToSource[0] != 0.0 || dirToSource[1] != 0.0 || dirToSource[2] != 0.0f) {
                            normalizeVec3(dirToSource);
                        }
                        dirSum[0] += dirToSource[0];
                        dirSum[1] += dirToSource[1];
                    }
                }
            }
            worker = worker->next;
            workerCount++;
        } while (worker != NULL);
    }
    if (workerCount != 0) {
        *outDirX = dirSum[0] / (f32)workerCount;
        *outDirY = dirSum[1] / (f32)workerCount;
        *outDirZ = dirSum[2] / (f32)workerCount;
    }
}
