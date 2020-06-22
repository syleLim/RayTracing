#include "ray.h"

t_ray	*init_ray()
{
	t_ray	*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		return (NULL);
	vzero(ray->origin);
	vzero(ray->dir);
	return (ray);
}

void	set_ray_origin(t_ray *ray, vec origin)
{
	vcopy(ray->origin, origin);
}

void	set_ray_dir(t_ray *ray, vec dir)
{
	vcopy(ray->dir, dir);
}

void	cal_ray_dir(t_ray *ray,
				t_screen *screen, double v, double u)
{
	ray->dir[X] = screen->origin[X]
		+ u * screen->horizontal[X] + v * screen->vertical[X];
	ray->dir[Y] = screen->origin[Y]
		+ u * screen->horizontal[Y] + v * screen->vertical[Y];
	ray->dir[Z] = screen->origin[Z]
		+ u * screen->horizontal[Z] + v * screen->vertical[Z];
}