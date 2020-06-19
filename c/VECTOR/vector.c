#include "vector.h"

void	vzero(vec v)
{
	v[X] = 0;
	v[Y] = 0;
	v[Z] = 0;
}

void	vcopy(vec dest, vec src)
{
	dest[X] = src[X];
	dest[Y] = src[Y];
	dest[Z] = src[Z];
}

void	vcross(vec dest, vec v1, vec v2)
{
	dest[X] = v1[Y] * v2[Z] - v1[Z]	* v2[Y];
	dest[Y] = v1[Z] * v2[X] - v1[X] * v2[Z];
	dest[Z] = v1[X] * v2[Y] - v1[Y] * v2[X];
}

double	vlen(vec v)
{
	return (sqrt(v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z]));
}

void	vneg(vec dest, vec src)
{
	dest[X] = -src[X];
	dest[Y] = -src[Y];
	dest[Z] = -src[Z];
}

void	vmake(vec dest, double x, double y, double z)
{
	dest[X] = x;
	dest[Y] = y;
	dest[Z] = z;
}

void	vnormalize(vec v)
{
	double len;

	len = vlen(v);
	v[X] /= len;
	v[Y] /= len;
	v[Z] /= len;
}

void	vmultiple(vec dest, vec src, double value)
{
	dest[X] = src[X] * value;
	dest[Y] = src[Y] * value;
	dest[Z] = src[Z] * value;
}

double	vsubtract(vec dest, vec v1, vec v2)
{
	dest[X] = v1[X] - v2[X];
	dest[Y] = v1[Y] - v2[Y];
	dest[Z] = v1[Z] - v2[Z];
}

double	vmultiply(vec v1, vec v2)
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}

//ZYX
void	vrotate(vec v, vec ori)
{
	double	yaw;
	double	pitch;
	vec		c;
	vec		s;
	vec		rot;
	vec		temp;

	yaw = atan2(ori[X], ori[Y]);
	pitch = atan2(ori[Z], sqrt(ori[X] * ori[X] + ori[Y] * ori[Y]));
	vmake(c, 1., cos(pitch), cos(yaw));
	vmake(s, 0., sin(pitch), sin(yaw));
	vmake(rot, c[Y] * c[Z], c[Y] * s[Z], -s[Y]);
	temp[X] = vmultiply(v, rot);
	vmake(rot, s[Z] * s[Y] * c[X] - c[Z] * s[X],
		s[Z] * s [Y] * s[X] + c[Z] * c[X], s[Z] * s[Y]);
	temp[Y] = vmultiply(v, rot);
	vmake(rot, c[Z] * s[Y] * c[X] + s[Z] * s[X],
		c[Z] * s [Y] * s[X] - s[Z] * c[X], c[Z] * s[Y]);
	temp[Z] = vmultiply(v, rot);
	vnormalize(temp);
	vcopy(v, temp);
}




void	printv(char *name, vec src)
{
	printf("%s : %.3f %.3f %.3f\n", name, src[X], src[Y], src[Z]);
}