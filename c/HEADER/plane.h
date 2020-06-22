#ifndef PLANE_H
# define PLANE_H
# include "DB.h"
# include "vector.h"
# include "ray.h"
# include "hitter.h"

typedef struct	s_plane
{
	vec			point;
	vec			normal;
	vec			color;
}				t_plane;

t_plane		*init_plane();
void		set_plane_point(t_plane *plane, vec point);
void		set_plane_normal(t_plane *plane, vec normal);
void		set_plane_color(t_plane *plane, vec color);
void		collision_plane(t_plane *plane,
						t_ray *ray, t_hitter *hitter);
#endif