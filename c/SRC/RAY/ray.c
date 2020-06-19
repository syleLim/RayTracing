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