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

double			vsubtract(vec dest, vec v1, vec v2)
{
	dest[X] = v1[X] - v2[X];
	dest[Y] = v1[Y] - v2[Y];
	dest[Z] = v1[Z] - v2[Z];
}

double	vdot(vec v1, vec v2)
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}

static void		get_axis(vec axis, vec ori)
{
	vec basic;

	vmake(basic, 0, 0, 1);
	vcross(axis, basic, ori);
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

void			vrotate(vec v, vec ori)
{
	vec		rot[3];
	vec		axis;
	vec		temp;
	double	c;
	double	s;

	get_axis(axis, ori);
	c = get_cos(axis, ori);
	s = sqrt(1 - c * c);
	vmake(rot[0], axis[X] * axis[X] * (1 - c) + c,
					axis[X] * axis[Y] * (1 - c) + axis[Z] * s,
					axis[X] * axis[Z] * (1 - c) - axis[Y] * s);
	vmake(rot[1], axis[X] * axis[Y] * (1 - c) - axis[Z] * s,
					axis[Y] * axis[Y] * (1 - c) + c,
					axis[Y] * axis[Z] * (1 - c) - axis[X] * s);
	vmake(rot[2], axis[X] * axis[Z] * (1 - c) + axis[Y] * s,
					axis[Y] * axis[Z] * (1 - c) - axis[X] * s,
					axis[Z] * axis[Z] * (1 - c) + c);
	temp[X] = vdot(v, rot[0]);
	temp[Y] = vdot(v, rot[1]);
	temp[Z] = vdot(v, rot[2]);
	vcopy(v, temp);		
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
