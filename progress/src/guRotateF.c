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
	float __repair_x_sine;
	float __repair_y_sine;
	float __repair_z_sine;
	static float	dtor = 3.1415926 / 180.0;
	float	sine;
	float	cosine;
	float	ab, bc, ca, t;

	guNormalize(&x, &y, &z);
	angle *= dtor;
	sine = sinApprox(angle);
	cosine = __cosf(angle);
	t = (1 - cosine);
	ab = x * y * t;
	bc = y * z * t;
	ca = z * x * t;

	guMtxIdentF(mf);

	t = x * x;
	__repair_x_sine = x * sine;
	__repair_y_sine = y * sine;
	__repair_z_sine = z * sine;
	mf[2][1] = bc - __repair_x_sine;
	mf[0][0] = t + cosine * (1 - t);
	mf[1][2] = bc + __repair_x_sine;

	t = y * y;
	mf[1][1] = t + cosine * (1 - t);
	mf[2][0] = ca + __repair_y_sine;
	mf[0][2] = ca - __repair_y_sine;

	t = z * z;
	mf[2][2] = t + cosine * (1 - t);
	mf[1][0] = ab - __repair_z_sine;
	mf[0][1] = ab + __repair_z_sine;
}
