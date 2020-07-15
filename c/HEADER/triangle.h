#ifndef TRIANGLE_H
# define TRIANGLE_H
# include "DB.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct  s_triangle
{
	int		id;
    vec		a;
    vec		b;
    vec		c;
	vec		normal;
	vec		color;
}				t_triangle;

t_triangle	*init_triangle();
void		set_triangle_point_a(t_triangle *triangle, vec pos);
void		set_triangle_point_b(t_triangle *triangle, vec pos);
void		set_triangle_point_c(t_triangle *triangle, vec pos);
void		set_triangle_color(t_triangle *triangle, vec color);
void		collision_triangle(t_triangle *triangle,
						t_ray *ray, t_hitter *hitter);
void		shadow_collision_triangle(t_triangle *triangle,
						t_ray *ray, t_hitter *hitter);
#endif