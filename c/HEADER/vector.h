#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdlib.h>
# include "DB.h"

typedef double	vec[3];

void	printv(char *name, vec src);

void	vcopy(vec dest, vec src);
void	vzero(vec v);

#endif