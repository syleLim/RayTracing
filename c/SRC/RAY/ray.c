#include "ray.h"

t_ray	*init_ray(vec origin)
{
	t_ray	*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		return (NULL);
	vcopy(ray->origin, origin);
	vzero(ray->dir);
	return (ray);
}