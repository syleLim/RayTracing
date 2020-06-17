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

void	normalize(vec v)
{
	double len;

	len = vlen(v);
	v[X] /= len;
	v[Y] /= len;
	v[Z] /= len;
}

void	printv(char *name, vec src)
{
	printf("%s : %3.f %3.f %3.f\n", name, src[X], src[Y], src[Z]);
}