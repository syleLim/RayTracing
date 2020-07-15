#ifndef LIGHT_H
# define LIGHT_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"
# include "hitter.h"

typedef struct	s_light
{
	vec			pos;
	vec			color;
	vec			ambient;
}				t_light;

t_light	*init_light();
void	set_light_pos(t_light *light, vec pos);
void	set_light_color(t_light *light, vec color);
void	set_light_ambient(t_light *light, vec ambient);
void	set_color(vec color, t_light *light,
					t_hitter *hitter, vec origin);

#endif