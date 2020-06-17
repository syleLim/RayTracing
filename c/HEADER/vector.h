#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdlib.h>
# include "DB.h"

typedef double	vec[3];

void	printv(char *name, vec src);

void	vcopy(vec dest, vec src);
void	vzero(vec v);
void	vcross(vec dest, vec v1, vec v2);
double	vlen(vec v);
void	normalize(vec v);
void	vneg(vec dest, vec src);

#endif