#include "vector.h"

void			vzero(vec v)
{
	v[X] = 0;
	v[Y] = 0;
	v[Z] = 0;
}

void			vcopy(vec dest, vec src)
{
	dest[X] = src[X];
	dest[Y] = src[Y];
	dest[Z] = src[Z];
}

void			vcross(vec dest, vec v1, vec v2)
{
	dest[X] = v1[Y] * v2[Z] - v1[Z]	* v2[Y];
	dest[Y] = v1[Z] * v2[X] - v1[X] * v2[Z];
	dest[Z] = v1[X] * v2[Y] - v1[Y] * v2[X];
}

double			vlen(vec v)
{
	return (sqrt(v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z]));
}

void			vneg(vec dest, vec src)
{
	dest[X] = -src[X];
	dest[Y] = -src[Y];
	dest[Z] = -src[Z];
}

void			vmake(vec dest, double x, double y, double z)
{
	dest[X] = x;
	dest[Y] = y;
	dest[Z] = z;
}

void			vnormalize(vec v)
{
	double len;

	len = vlen(v);
	v[X] /= len;
	v[Y] /= len;
	v[Z] /= len;
}

void			vmultiple(vec dest, vec src, double value)
{
	dest[X] = src[X] * value;
	dest[Y] = src[Y] * value;
	dest[Z] = src[Z] * value;
}

void			vmultiply(vec dest, vec v1, vec v2)
{
	dest[X] = v1[X] * v2[X];
	dest[Y] = v1[Y] * v2[Y];
	dest[Z] = v1[Z] * v2[Z];
}

void			vsubtract(vec dest, vec v1, vec v2)
{
	dest[X] = v1[X] - v2[X];
	dest[Y] = v1[Y] - v2[Y];
	dest[Z] = v1[Z] - v2[Z];
}

void			vadd(vec dest, vec v1, vec v2)
{
	dest[X] = v1[X] + v2[X];
	dest[Y] = v1[Y] + v2[Y];
	dest[Z] = v1[Z] + v2[Z];
}

double			vdot(vec v1, vec v2)
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}

static void		get_axis(vec axis, vec v, vec ori)
{
	vcross(axis, v, ori);
	vnormalize(axis);
}

static double	get_cos(vec v1, vec v2)
{
	return (vdot(v1, v2) / (vlen(v1) * vlen(v2)));
}

double			vdiff(vec v1, vec v2)
{
	return (sqrt(pow(v1[X] - v2[X], 2)
				+ pow(v1[Y] - v2[Y], 2)
				+ pow(v1[Z] - v2[Z], 2)));
}

void			vscaling(vec dest, vec src)
{
	
}

bool			vcompare(vec v1, vec v2)
{
	if (v1[X] != v2[X] || v1[Y] != v2[Y] || v1[Z] != v2[Z])
		return (FALSE);
	return (TRUE);
}

bool			vcompare_neg(vec v1, vec v2)
{
	if (v1[X] != -v2[X] || v1[Y] != -v2[Y] || v1[Z] != -v2[Z])
		return (FALSE);
	return (TRUE);
}

void			vrotate(vec v, vec u, vec ori)
{
	vec half;
	vec cross;
	quaternion q;

	vnormalize(u);
	vnormalize(ori);
	if (vcompare(u, ori))
		return ;
	if (vcompare_neg(u, ori))
		qorthogonal(q, u);
	else
	{
		vadd(half, u, ori);
		vnormalize(half);
		vcross(cross, u, half);
		qmake(q, cross, vdot(u, half));
	}
	qrotate(v, q);
}

void	vpoint(vec dest, vec origin, vec dir, double t)
{
	dest[X] = origin[X] + t * dir[X];
	dest[Y] = origin[Y] + t * dir[Y];
	dest[Z] = origin[Z] + t * dir[Z];
}

void	printv(char *name, vec src)
{
	printf("%s : %.3f %.3f %.3f\n", name, src[X], src[Y], src[Z]);
}