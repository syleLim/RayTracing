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

t_light	*init_light();
void	set_light_pos(t_light *light, vec pos);
void	set_intensity(t_light *light, double intensity);
void	set_ambient(t_light *light, double ambient);

#endif