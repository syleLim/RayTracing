#ifndef HITTER_H
# define HITTER_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"

typedef struct	s_hitter
{
	vec			pos;
	vec			shadow_ray;
}				t_hitter;

t_hitter	*init_hitter();

#endif