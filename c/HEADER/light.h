#ifndef LIGHT_H
# define LIGHT_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"

typedef struct	s_light
{
	vec			pos;
	vec			light;
	vec			color;
	double		intensity;
	double		ambient;
}				t_light;

t_light		*init_light(vec pos, double intensity,
							double ambient);

#endif