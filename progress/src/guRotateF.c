/* adapted from similar verified C in guRotateF in V-RALLY-PAL (matched), with its names changed by decompdecomp */
f32 __cosf(f32);
extern void guNormalize(float *x, float *y, float *z);
extern void guMtxIdentF(float mf[4][4]);
extern float sinApprox(float angle);
extern float __cosf(float angle);

/* Builds a 4x4 float matrix that rotates by angle (degrees) about the axis (x, y, z).
   The axis is normalised first; the result is written into mf. */
void guRotateF(float mf[4][4], float angle, float x, float y, float z)
{
	float xSine;
	float ySine;
	float zSine;
	static float	dtor = 3.1415926 / 180.0;
	float	sinAngle;
	float	cosAngle;
	float	xyT, yzT, zxT, diag;

	guNormalize(&x, &y, &z);
	angle *= dtor;
	sinAngle = sinApprox(angle);
	cosAngle = __cosf(angle);
	diag = (1 - cosAngle);
	xyT = x * y * diag;
	yzT = y * z * diag;
	zxT = z * x * diag;

	guMtxIdentF(mf);

	diag = x * x;
	xSine = x * sinAngle;
	ySine = y * sinAngle;
	zSine = z * sinAngle;
	mf[2][1] = yzT - xSine;
	mf[0][0] = diag + cosAngle * (1 - diag);
	mf[1][2] = yzT + xSine;

	diag = y * y;
	mf[1][1] = diag + cosAngle * (1 - diag);
	mf[2][0] = zxT + ySine;
	mf[0][2] = zxT - ySine;

	diag = z * z;
	mf[2][2] = diag + cosAngle * (1 - diag);
	mf[1][0] = xyT - zSine;
	mf[0][1] = xyT + zSine;
}
