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

void	printv(char *name, vec src)
{
	printf("%s : %3.f %3.f %3.f\n", name, src[X], src[Y], src[Z]);
}