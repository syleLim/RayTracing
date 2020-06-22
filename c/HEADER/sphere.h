#ifndef SPHERE_H
# define SPHERE_H
# include "DB.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_sphere
{
	vec			pos;
	vec			color;
	double		radius;
}				t_sphere;

t_sphere	*init_sphere();
void		set_sphere_pos(t_sphere *sphere, vec pos);
void		set_sphere_radius(t_sphere *sphere, double radius);
void		set_sphere_color(t_sphere *sphere, vec color);
void		collision_sphere(t_sphere *sphere, t_ray *ray,
								 t_hitter *hitter);
#endif