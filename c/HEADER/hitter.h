#ifndef HITTER_H
# define HITTER_H
# include <stdlib.h>
# include "DB.h"
# include "vector.h"

typedef struct	s_hitter
{
	bool		is_hit;
	vec			pos;
	vec			normal;
	vec			color;
	vec			shadow;
}				t_hitter;

t_hitter	*init_hitter();
void		set_hitter_pos(t_hitter *hitter, vec pos);
void		set_hitter_shadow_ray(t_hitter *hitter, vec shadow);
void		set_hitter_color(t_hitter *hitter, vec color);
bool		check_hitter(t_hitter *hitter, vec pos,
							vec origin, vec normal);

#endif