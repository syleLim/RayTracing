#include "plane.h"

t_plane		*init_plane()
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		return (NULL);
	vzero(plane->point);
	vmake(plane->normal, 0, 0, 1);
	vmake(plane->color, 1, 1, 1);
	return (plane);
}

void		set_plane_point(t_plane *plane, vec point)
{
	vcopy(plane->point, point);
}

void		set_plane_normal(t_plane *plane, vec normal)
{
	vcopy(plane->normal, normal);
}

void		set_plane_color(t_plane *plane, vec color)
{
	vcopy(plane->color, color);
}

static double	equation(t_plane *plane, vec origin, vec dir)
{
	double t;

	if (vdot(plane->normal, dir) == 0)
		return (-1.);
	t = (vdot(plane->normal, plane->point)
		- vdot(plane->normal, origin))
		/ vdot(plane->normal, dir);
	return (t);
}

static bool	collision(vec pos, t_plane *plane,
								vec origin, vec dir)
{
	double t;

	t = equation(plane, origin, dir);
	if (t < 0)
		return (FALSE);
	vpoint(pos, origin, dir, t);
	return (TRUE);
}

void		collision_plane(t_plane *plane,
						t_ray *ray, t_hitter *hitter)
{
	vec pos;

	if (collision(pos, plane, ray->origin, ray->dir))
		if (check_hitter(hitter, pos, ray->origin, plane->normal))
			set_hitter_color(hitter, plane->color);
}

