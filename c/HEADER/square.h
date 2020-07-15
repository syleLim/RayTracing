#ifndef SQUARE_H
# define SQUARE_H
# include "DB.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_square
{
	int			id;
	double		size;
	vec			pos;
	vec			normal;
	vec			color;
	vec			a;
	vec			b;
	vec			c;
	vec			d;
}				t_square;

t_square		*init_square();
void			set_square_normal(t_square *square, vec normal);
void			set_square_size(t_square *square, double size);
void			set_square_pos(t_square *square, vec pos);
void			set_square_color(t_square *square, vec color);
void			shadow_collision_square(t_square *square,
							t_ray *ray, t_hitter *hitter);
void			collision_square(t_square *square,
						t_ray *ray, t_hitter *hitter);

#endif