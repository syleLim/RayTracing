#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdlib.h>
# include "DB.h"
# include "quaternion.h"

typedef double	vec[3];

void	printv(char *name, vec src);

void	vcopy(vec dest, vec src);
void	vzero(vec v);
void	vmake(vec dest, double x, double y, double z);
void	vcross(vec dest, vec v1, vec v2);
double	vlen(vec v);
void	vmultiple(vec dest, vec src, double value);
void	vmultiply(vec dest, vec v1, vec v2);
void	vnormalize(vec v);
void	vneg(vec dest, vec src);
double	vdot(vec v1, vec v2);
void	vrotate(vec v, vec u, vec ori);
double	vdiff(vec v1, vec v2);
void	vsubtract(vec dest, vec v1, vec v2);
void	vpoint(vec dest, vec origin, vec dir, double t);
void	vadd(vec dest, vec v1, vec v2);

#endif