#ifndef RAY_H
# define RAY_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"

typedef	struct	s_ray
{
	vec			origin;
	vec			dir;
}				t_ray;

t_ray	*init_ray(vec origin);

#endif