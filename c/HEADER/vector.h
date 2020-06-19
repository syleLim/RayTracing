#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdlib.h>
# include "DB.h"

typedef double	vec[3];

void	printv(char *name, vec src);

void	vcopy(vec dest, vec src);
void	vzero(vec v);
void	vmake(vec dest, double x, double y, double z);
void	vcross(vec dest, vec v1, vec v2);
double	vlen(vec v);
void	vmultiple(vec dest, vec src, double value);
void	vnormalize(vec v);
void	vneg(vec dest, vec src);
double	vmultiply(vec v1, vec v2);
void	vrotate(vec v, vec cos);

#endif